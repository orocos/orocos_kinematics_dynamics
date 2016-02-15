/*
    Computes the Jacobian time derivative
    Copyright (C) 2015  Antoine Hoarau <hoarau [at] isir.upmc.fr>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include "chainjnttojacdotsolver.hpp"

namespace KDL
{

ChainJntToJacDotSolver::ChainJntToJacDotSolver(const Chain& _chain):
    chain(_chain),
    locked_joints_(chain.getNrOfJoints(),false),
    nr_of_unlocked_joints_(chain.getNrOfJoints()),
    jac_solver_(chain),
    jac_(chain.getNrOfJoints()),
    jac_dot_(chain.getNrOfJoints()),
    representation_(HYBRID),
    fk_solver_(chain)
{
}

int ChainJntToJacDotSolver::JntToJacDot(const JntArrayVel& q_in, Twist& jac_dot_q_dot, int seg_nr)
{
    JntToJacDot(q_in,jac_dot_,seg_nr);
    MultiplyJacobian(jac_dot_,q_in.qdot,jac_dot_q_dot);
    return (error = E_NOERROR);
}

int ChainJntToJacDotSolver::JntToJacDot(const JntArrayVel& q_in, Jacobian& jdot, int seg_nr)
{
    unsigned int segmentNr;
    if(seg_nr<0)
        segmentNr=chain.getNrOfSegments();
    else
        segmentNr = seg_nr;

    //Initialize Jacobian to zero since only segmentNr columns are computed
    SetToZero(jdot) ;

    if(q_in.q.rows()!=chain.getNrOfJoints()||nr_of_unlocked_joints_!=jdot.columns())
        return (error = E_JAC_DOT_FAILED);
    else if(segmentNr>chain.getNrOfSegments())
        return (error = E_JAC_DOT_FAILED);

    // First compute the jacobian in the Hybrid representation
    jac_solver_.JntToJac(q_in.q,jac_,segmentNr);

    // Change the reference frame and/or the reference point
    switch(representation_)
    {
        case HYBRID:
            // Do Nothing as it is the default in KDL;
            break;
        case BODYFIXED:
            // Ref Frame {ee}, Ref Point {ee}
            fk_solver_.JntToCart(q_in.q,F_bs_ee_,segmentNr);
            jac_.changeBase(F_bs_ee_.M.Inverse());
            break;
        case INTERTIAL:
            // Ref Frame {bs}, Ref Point {bs}
            fk_solver_.JntToCart(q_in.q,F_bs_ee_,segmentNr);
            jac_.changeRefPoint(-F_bs_ee_.p);
            break;
        default:
            return (error = E_JAC_DOT_FAILED);
    }

    // Let's compute Jdot in the corresponding representation
    int k=0;
    for(unsigned int i=0;i<segmentNr;++i)
    {
        //Only increase joint nr if the segment has a joint
        if(chain.getSegment(i).getJoint().getType()!=Joint::None){

            for(unsigned int j=0;j<chain.getNrOfJoints();++j)
            {
                // Column J is the sum of all partial derivatives  ref (41)
                if(!locked_joints_[j])
                    jac_dot_k_ += getPartialDerivative(jac_,j,k,representation_) * q_in.qdot(j);
            }
            jdot.setColumn(k++,jac_dot_k_);
            SetToZero(jac_dot_k_);
        }
    }

    return (error = E_NOERROR);
}

const Twist& ChainJntToJacDotSolver::getPartialDerivative(const KDL::Jacobian& J, 
                                                          const unsigned int& joint_idx, 
                                                          const unsigned int& column_idx, 
                                                          const int& representation)
{
    switch(representation)
    {
        case HYBRID:
            return getPartialDerivativeHybrid(J,joint_idx,column_idx);
        case BODYFIXED:
            return getPartialDerivativeBodyFixed(J,joint_idx,column_idx);
        case INTERTIAL:
            return getPartialDerivativeInertial(J,joint_idx,column_idx);
        default:
            SetToZero(this->t_djdq_);
            return t_djdq_;
    }
}

const Twist& ChainJntToJacDotSolver::getPartialDerivativeHybrid(const KDL::Jacobian& bs_J_ee, 
                                                                const unsigned int& joint_idx, 
                                                                const unsigned int& column_idx)
{
    int j=joint_idx;
    int i=column_idx;

    jac_j_ = bs_J_ee.getColumn(j);
    jac_i_ = bs_J_ee.getColumn(i);

    SetToZero(t_djdq_);

    if(j < i)
    {
        // P_{\Delta}({}_{bs}J^{j})  ref (20)
        t_djdq_.vel = jac_j_.rot * jac_i_.vel;
        t_djdq_.rot = jac_j_.rot * jac_i_.rot;
    }else if(j > i)
    {
        // M_{\Delta}({}_{bs}J^{j})  ref (23)
        SetToZero(t_djdq_.rot);
        t_djdq_.vel = -jac_j_.vel * jac_i_.rot;
    }else if(j == i)
    {
         // ref (40)
         SetToZero(t_djdq_.rot);
         t_djdq_.vel = jac_i_.rot * jac_i_.vel;
    }
    return t_djdq_;
}

const Twist& ChainJntToJacDotSolver::getPartialDerivativeBodyFixed(const Jacobian& ee_J_ee, 
                                                            const unsigned int& joint_idx, 
                                                            const unsigned int& column_idx)
{
    int j=joint_idx;
    int i=column_idx;

    SetToZero(t_djdq_);

    if(j > i)
    {
        jac_j_ = ee_J_ee.getColumn(j);
        jac_i_ = ee_J_ee.getColumn(i);

        // - S_d_(ee_J^j) * ee_J^ee  ref (23)
        t_djdq_.vel = jac_j_.rot * jac_i_.vel + jac_j_.vel * jac_i_.rot;
        t_djdq_.rot = jac_j_.rot * jac_i_.rot;
        t_djdq_ = -t_djdq_;
    }

    return t_djdq_;
}
const Twist& ChainJntToJacDotSolver::getPartialDerivativeInertial(const KDL::Jacobian& bs_J_bs, 
                                                                  const unsigned int& joint_idx, 
                                                                  const unsigned int& column_idx)
{
    int j=joint_idx;
    int i=column_idx;

    SetToZero(t_djdq_);

    if(j < i)
    {
        jac_j_ = bs_J_bs.getColumn(j);
        jac_i_ = bs_J_bs.getColumn(i);

        // S_d_(bs_J^j) * bs_J^bs  ref (23)
        t_djdq_.vel = jac_j_.rot * jac_i_.vel + jac_j_.vel * jac_i_.rot;
        t_djdq_.rot = jac_j_.rot * jac_i_.rot;
    }

    return t_djdq_;
}
void ChainJntToJacDotSolver::setRepresentation(const int& representation)
{
    if(representation == HYBRID ||
        representation == BODYFIXED ||
        representation == INTERTIAL)   
    this->representation_ = representation;
}


int ChainJntToJacDotSolver::setLockedJoints(const std::vector< bool > locked_joints)
{
    if(locked_joints.size()!=locked_joints_.size())
        return -1;
    locked_joints_=locked_joints;
    nr_of_unlocked_joints_=0;
    for(unsigned int i=0;i<locked_joints_.size();i++){
        if(!locked_joints_[i])
            nr_of_unlocked_joints_++;
    }

    return 0;
}
const char* ChainJntToJacDotSolver::strError(const int error) const
{
    if (E_JAC_DOT_FAILED == error) return "Jac Dot Failed";
    else return SolverI::strError(error);
}

ChainJntToJacDotSolver::~ChainJntToJacDotSolver()
{
}
}  // namespace KDL
