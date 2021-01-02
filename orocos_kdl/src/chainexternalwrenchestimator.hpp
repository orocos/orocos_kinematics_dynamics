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

#ifndef KDL_EXTERNAL_WRENCH_ESTIMATOR_HPP
#define KDL_EXTERNAL_WRENCH_ESTIMATOR_HPP

#include <Eigen/Core>
#include <Eigen/SVD> 
#include "chaindynparam.hpp"
#include "chainjnttojacsolver.hpp"
#include "chainfksolverpos_recursive.hpp"
#include <iostream>

namespace KDL {

    /**
     * \brief First-order momentum observer for the estimation of external wrenches applied on the robot's end-effector. 
     *
     * Implementation based on:
     * S. Haddadin, A. De Luca and A. Albu-Schäffer,
     * "Robot Collisions: A Survey on Detection, Isolation, and Identification,"
     * in IEEE Transactions on Robotics, vol. 33(6), pp. 1292-1312, 2017.
     */
    class ChainExternalWrenchEstimator : public SolverI
    {
    public:
        /**
         * Constructor for the estimator, it will allocate all the necessary memory
         * \param chain The kinematic chain of the robot, an internal copy will be made.
         * \param gravity The gravity-acceleration vector to use during the calculation.
         * \param sample_frequency Frequency at which users updates it estimation loop (in Hz).
         * \param filter_constant Parameter defining how much the estimated signal should be filtered by the low-pass filter.
         *                        This input value should be between 0 and 1. Higher the number means more noise needs to be filtered-out.
         *                        The filter can be turned off by setting this value to 0.
         */
        ChainExternalWrenchEstimator(const Chain &chain, const Vector &gravity, const double sample_frequency, const double estimation_gain, const double filter_constant);
        ~ChainExternalWrenchEstimator(){};

        /**
         * Calculates robot's initial momentum in the joint space. 
         * Bassically, sets the offset for future estimation (momentum calculation).
         * If this method is not called by the user, zero values will be taken for the initial momentum.
         */
        int setInitialMomentum(const JntArray &joint_position, const JntArray &joint_velocity);

        /**
         * This method calculates the external wrench that is applied on the robot's end-effector.
         * Input parameters:
         * \param joint_position The current (measured) joint positions.
         * \param joint_velocity The current (measured) joint velocities.
         * \param joint_torque The joint space torques. 
         *                     Depending on the user's choice, this array can represent commanded or measured joint torques.
         *                     A particular choice depends on the available sensors in robot's joint. 
         *                     For more details see the above-referenced article.
         *
         * Output parameters:
         * \param external_wrench The estimated external wrench applied on the robot's end-effector.
         *                        The wrench will be expressed w.r.t. end-effector's frame.
         *
         * @return error/success code
         */
        int JntToExtWrench(const JntArray &joint_position, const JntArray &joint_velocity, const JntArray &joint_torque, Wrench &external_wrench);

        /// @copydoc KDL::SolverI::updateInternalDataStructures()
        virtual void updateInternalDataStructures();

    private:
        const Chain &CHAIN;
        const double DT_SEC, FILTER_CONST;
        unsigned int nj, ns;
        JntSpaceInertiaMatrix jnt_mass_matrix, previous_jnt_mass_matrix;
        JntArray initial_jnt_momentum, estimated_momentum_integral, filtered_estimated_ext_torque;
        Eigen::VectorXd ESTIMATION_GAIN;
        ChainDynParam dynparam_solver;
        ChainJntToJacSolver jacobian_solver;
        ChainFkSolverPos_recursive fk_pos_solver;
    };
}

#endif
