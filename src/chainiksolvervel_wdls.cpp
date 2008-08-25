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

#include "chainiksolvervel_wdls.hpp"
#include "utilities/svd_boost_HH.hpp"

namespace KDL
{
    using namespace ublas;
    
    ChainIkSolverVel_wdls::ChainIkSolverVel_wdls(const Chain& _chain,double _eps,int _maxiter):
        chain(_chain),
        jnt2jac(chain),
        jac(chain.getNrOfJoints()),
        U(ublas::matrix<double>(6,chain.getNrOfJoints())),
        S(ublas::vector<double>(chain.getNrOfJoints())),
        V(ublas::matrix<double>(chain.getNrOfJoints(),chain.getNrOfJoints())),
        eps(_eps),
        maxiter(_maxiter),
        tmp(ublas::vector<double>(chain.getNrOfJoints())),
        tmp_jac(ublas::matrix<double>(6,chain.getNrOfJoints())),
        tmp_ts(ublas::matrix<double>(6,6)),
        tmp_js(ublas::matrix<double>(chain.getNrOfJoints(),chain.getNrOfJoints())),
        weight_ts(ublas::identity_matrix<double>(6)),
        weight_js(ublas::identity_matrix<double>(chain.getNrOfJoints())),
        lambda(0.0)
    {
    }
    
    ChainIkSolverVel_wdls::~ChainIkSolverVel_wdls()
    {
    }
    
    void ChainIkSolverVel_wdls::setWeightJS(const ublas::symmetric_matrix<double> Mq){
        weight_js = Mq;
    }
    
    void ChainIkSolverVel_wdls::setWeightTS(const ublas::symmetric_matrix<double> Mx){
        weight_ts = Mx;
    }

    void ChainIkSolverVel_wdls::setLambda(const double& lambda_in)
    {
        lambda=lambda_in;
    }
    
    int ChainIkSolverVel_wdls::CartToJnt(const JntArray& q_in, const Twist& v_in, JntArray& qdot_out)
    {
        jnt2jac.JntToJac(q_in,jac);
        
        double sum;
        unsigned int i,j;
        
        for (i=0;i<jac.rows();i++) {
            for (j=0;j<jac.columns();j++)
                tmp_jac(i,j) = jac(i,j);
        }
        
        int ret = svd_boost_HH(tmp_jac,U,S,V,tmp,maxiter);
        
        //Pre-multiply U and V by the task space and joint space weighting matrix respectively
        noalias(tmp_ts) = prod(weight_ts,project(U,range(0,6),range(0,6)));
        noalias(tmp_js) = prod(weight_js,V); 
        
        // tmp = (Si*U'*Ly*y), 
        for (i=0;i<jac.columns();i++) {
            sum = 0.0;
            for (j=0;j<jac.rows();j++) {
                if(i<6)
                    sum+= tmp_ts(j,i)*v_in(j);
                else
                    sum+=0.0;
            }
            tmp(i) = sum*((S(i)/(S(i)*S(i)+lambda*lambda)));   
        }
        // x = Lx^-1*V*tmp + x
        for (i=0;i<jac.columns();i++) {
            sum = 0.0;
            for (j=0;j<jac.columns();j++) {
                sum+=tmp_js(i,j)*tmp(j);
            }
            qdot_out(i)=sum;
        }
        return ret;
    }
    
}
