// Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

// Version: 1.0
// Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
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

#ifndef KDL_CHAIN_IKSOLVERVEL_WDLS_HPP
#define KDL_CHAIN_IKSOLVERVEL_WDLS_HPP

#include "chainiksolver.hpp"
#include "chainjnttojacsolver.hpp"
#include <boost/numeric/ublas/symmetric.hpp>

namespace ublas = boost::numeric::ublas;


namespace KDL
{
    /**
     * Implementation of a inverse velocity kinematics algorithm based
     * on the weighted pseudo inverse with damped least-square to calculate the velocity
     * transformation from Cartesian to joint space of a general
     * KDL::Chain. It uses a svd-calculation based on householders
     * rotations.
     * 
     * J# = M_q*V*pinv_dls(D)*U'*M_x
     *
     * @ingroup KinematicFamily
     */
    class ChainIkSolverVel_wdls : public ChainIkSolverVel
    {
    public:
        /** 
         * Constructor of the solver
         * 
         * @param chain the chain to calculate the inverse velocity
         * kinematics for
         * @param eps if a singular value is below this value, its
         * inverse is set to zero, default: 0.00001
         * @param maxiter maximum iterations for the svd calculation,
         * default: 150
         * 
         */
        
        ChainIkSolverVel_wdls(const Chain& chain,double eps=0.00001,int maxiter=150);
        //=ublas::identity_matrix<double>
        ~ChainIkSolverVel_wdls();
        
        virtual int CartToJnt(const JntArray& q_in, const Twist& v_in, JntArray& qdot_out);
        /** 
         * not (yet) implemented.
         * 
         */
        virtual int CartToJnt(const JntArray& q_init, const FrameVel& v_in, JntArrayVel& q_out){return -1;};
        
        /* 
         * Set the joint space weighting matrix
         *
         * @param weight_js joint space weighting symetric matrix, default : identity.
         * M_q : This matrix being used as a weight for the norm of the joint space speed it HAS TO BE symmetric and positive definite. We can actually deal with matrices containing a symmetric and positive definite block and 0s otherwise. Taking a diagonal matrix as an example, a 0 on the diagonal means that the corresponding joints will not contribute to the motion of the system. On the other hand, the bigger the value, the most the corresponding joint will contribute to the overall motion. The obtained solution q_dot will actually minimize the weighted norm sqrt(q_dot'*(M_q^-2)*q_dot). In the special case we deal with, it does not make sense to invert M_q but what is important is the physical meaning of all this : a joint that has a zero weight in M_q will not contribute to the motion of the system and this is equivalent to saying that it gets an infinite weight in the norm computation.
         * For more detailed explanation : vincent.padois@upmc.fr
         */
        void setWeightJS(const ublas::symmetric_matrix<double> Mq);
        
        /* 
         * Set the task space weighting matrix
         *
         * @param weight_ts task space weighting symetric matrix, default: identity
         * M_x : This matrix being used as a weight for the norm of the error (in terms of task space speed) it HAS TO BE symmetric and positive definite. We can actually deal with matrices containing a symmetric and positive definite block and 0s otherwise. Taking a diagonal matrix as an example, a 0 on the diagonal means that the corresponding task coordinate will not be taken into account (ie the corresponding error can be really big). If the rank of the jacobian is equal to the number of task space coordinates which do not have a 0 weight in M_x, the weighting will actually not impact the results (ie there is an exact solution to the velocity inverse kinematics problem). In cases without an exact solution, the bigger the value, the most the corresponding task coordinate will be taken into account (ie the more the corresponding error will be reduced). The obtained solution will minimize the weighted norm sqrt(|x_dot-Jq_dot|'*(M_x^2)*|x_dot-Jq_dot|).
         * For more detailed explanation : vincent.padois@upmc.fr
         */  
        void setWeightTS(const ublas::symmetric_matrix<double> Mx);
        
        void setLambda(const double& lambda);
        
    private:        
        const Chain chain;
        ChainJntToJacSolver jnt2jac;
        Jacobian jac;
        ublas::matrix<double> U;
        ublas::vector<double> S;
        ublas::matrix<double> V;
        double eps;
        int maxiter;
        ublas::vector<double> tmp;
        ublas::matrix<double> tmp_jac;
        ublas::matrix<double> tmp_ts;
        ublas::matrix<double> tmp_js;
        ublas::symmetric_matrix<double> weight_ts;
        ublas::symmetric_matrix<double> weight_js;
        double lambda;
    };
}

#endif

