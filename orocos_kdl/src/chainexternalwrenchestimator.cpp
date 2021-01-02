// Copyright  (C)  2021 Djordje Vukcevic <djordje dot vukcevic at h-brs dot de>

// Version: 1.0
// Author: Djordje Vukcevic <djordje dot vukcevic at h-brs dot de>
// URL: http://www.orocos.org/kdl

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include "chainexternalwrenchestimator.hpp"
namespace KDL {

ChainExternalWrenchEstimator::ChainExternalWrenchEstimator(const Chain &chain, const Vector &gravity, const double sample_frequency, const double estimation_gain, const double filter_constant) :
    CHAIN(chain),
    DT_SEC(1.0 / sample_frequency), FILTER_CONST(filter_constant),
    nj(CHAIN.getNrOfJoints()), ns(CHAIN.getNrOfSegments()),
    jnt_mass_matrix(nj), previous_jnt_mass_matrix(nj),
    initial_jnt_momentum(nj), estimated_momentum_integral(nj), filtered_estimated_ext_torque(nj),
    ESTIMATION_GAIN(Eigen::VectorXd::Constant(nj, estimation_gain)),
    dynparam_solver(CHAIN, gravity),
    jacobian_solver(CHAIN),
    fk_pos_solver(CHAIN)
{
}

void ChainExternalWrenchEstimator::updateInternalDataStructures()
{
    nj = CHAIN.getNrOfJoints();
    ns = CHAIN.getNrOfSegments();
    jnt_mass_matrix.resize(nj);
    previous_jnt_mass_matrix.resize(nj);
    initial_jnt_momentum.resize(nj);
    estimated_momentum_integral.resize(nj);
    filtered_estimated_ext_torque.resize(nj);
    ESTIMATION_GAIN.conservativeResizeLike(Eigen::VectorXd::Constant(nj, ESTIMATION_GAIN(0)));
    dynparam_solver.updateInternalDataStructures();
    jacobian_solver.updateInternalDataStructures();
    fk_pos_solver.updateInternalDataStructures();
}

// Calculates robot's initial momentum in the joint space. If this method is not called by the user, zero values will be taken for the initial momentum.
int ChainExternalWrenchEstimator::setInitialMomentum(const JntArray &joint_position, const JntArray &joint_velocity)
{
    // Check sizes first
    if (joint_position.rows() != nj || joint_velocity.rows() != nj) return (error = E_SIZE_MISMATCH);

    // Calculate robot's inertia and momentum in the joint space
    dynparam_solver.JntToMass(joint_position, jnt_mass_matrix);
    initial_jnt_momentum.data = jnt_mass_matrix.data * joint_velocity.data;

    // Reset data because of the new momentum offset
    SetToZero(estimated_momentum_integral);
    SetToZero(filtered_estimated_ext_torque);

    return (error = E_NOERROR);
}

// This method calculates the external wrench that is applied on the robot's end-effector.
int ChainExternalWrenchEstimator::JntToExtWrench(const JntArray &joint_position, const JntArray &joint_velocity, const JntArray &joint_torque, Wrench &external_wrench)
{
    /**
     * ==========================================================================
     * First-order momentum observer, an implementation based on:
     * S. Haddadin, A. De Luca and A. Albu-Schäffer,
     * "Robot Collisions: A Survey on Detection, Isolation, and Identification,"
     * in IEEE Transactions on Robotics, vol. 33(6), pp. 1292-1312, 2017.
     * ==========================================================================
     */

    // Check sizes first
    if (nj != CHAIN.getNrOfJoints() || ns != CHAIN.getNrOfSegments()) return (error = E_NOT_UP_TO_DATE);
    if (joint_position.rows() != nj || joint_velocity.rows() != nj || joint_torque.rows() != nj) return (error = E_SIZE_MISMATCH);

    /**
     * =======================================================================================================================
     * Part I: Estimation of the torques that are felt in joints as a result of the external wrench being applied on the robot
     * =======================================================================================================================
     */

    // Calculate decomposed robot's dynamics
    JntArray gravity_torque(nj), coriolis_torque(nj);
    int solver_result = dynparam_solver.JntToMass(joint_position, jnt_mass_matrix);
    if (solver_result != 0) return solver_result;
    solver_result = dynparam_solver.JntToCoriolis(joint_position, joint_velocity, coriolis_torque);
    if (solver_result != 0) return solver_result;
    solver_result = dynparam_solver.JntToGravity(joint_position, gravity_torque);
    if (solver_result != 0) return solver_result;

    // Calculate the change of robot's inertia in the joint space
    JntSpaceInertiaMatrix jnt_mass_matrix_dot(nj);
    jnt_mass_matrix_dot.data = (jnt_mass_matrix.data - previous_jnt_mass_matrix.data) / DT_SEC;

    // Save data for the next iteration
    previous_jnt_mass_matrix.data = jnt_mass_matrix.data;

    // Calculate total torque exerted on the joint
    JntArray total_torque(nj);
    total_torque.data = joint_torque.data - gravity_torque.data - coriolis_torque.data + jnt_mass_matrix_dot.data * joint_velocity.data;

    // Accumulate main integral
    estimated_momentum_integral.data += (total_torque.data + filtered_estimated_ext_torque.data) * DT_SEC;

    // Estimate external joint torque
    JntArray estimated_ext_torque(nj);
    estimated_ext_torque.data = ESTIMATION_GAIN.asDiagonal() * (jnt_mass_matrix.data * joint_velocity.data - estimated_momentum_integral.data - initial_jnt_momentum.data);

    // First order low-pass filter: filter out the noise from the estimated signal
    // This filter can be turned off by setting FILTER_CONST value to 0
    filtered_estimated_ext_torque.data = FILTER_CONST * filtered_estimated_ext_torque.data + (1.0 - FILTER_CONST) * estimated_ext_torque.data;

    /**
     * ==================================================================================================================
     * Part II: Propagate above-estimated joint torques to Cartesian wrench using a pseudo-inverse of Jacobian-Transpose
     * ==================================================================================================================
     */
    
    // Compute robot's end-effector frame, expressed in the base frame
    Frame end_eff_frame;
    solver_result = fk_pos_solver.JntToCart(joint_position, end_eff_frame);
    if (solver_result != 0) return solver_result;

    // Compute robot's jacobian for the end-effector frame, expressed in the base frame
    Jacobian jacobian_end_eff(nj);
    solver_result = jacobian_solver.JntToJac(joint_position, jacobian_end_eff);
    if (solver_result != 0) return solver_result;

    // Transform the jacobian from the base frame to the end-effector frame. 
    // This part can be commented out if the user wants its estimated wrench to be expressed w.r.t. base frame 
    jacobian_end_eff.changeBase(end_eff_frame.M.Inverse()); // Jacobian is now expressed w.r.t. end-effector frame

    // Compute SVD of the jacobian using Eigen functions
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(jacobian_end_eff.data.transpose(), Eigen::ComputeThinU | Eigen::ComputeThinV);

    // Invert singular values
    Eigen::VectorXd singular_inv(svd.singularValues());
    for (int j = 0; j < singular_inv.size(); ++j)
        singular_inv(j) = (singular_inv(j) < 1e-8) ? 0.0 : 1.0 / singular_inv(j);

    // Compose SVD
    Eigen::MatrixXd jacobian_end_eff_inv;
    jacobian_end_eff_inv.noalias() = svd.matrixV() * singular_inv.matrix().asDiagonal() * svd.matrixU().adjoint();

    // Compute end-effector's Cartesian wrench from the estimated joint torques
    Eigen::VectorXd estimated_wrench = jacobian_end_eff_inv * filtered_estimated_ext_torque.data;
    for (int i = 0; i < 6; i++) 
        external_wrench(i) = estimated_wrench(i);

    return (error = E_NOERROR);
}

} // namespace
