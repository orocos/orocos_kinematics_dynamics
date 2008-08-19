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

#include "chainiksolvervel_pinv_boost_givens.hpp"
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include "utilities/svd_boost_Macie.hpp"

namespace KDL
{
    ChainIkSolverVel_pinv_boost_givens::ChainIkSolverVel_pinv_boost_givens(const Chain& _chain):
        chain(_chain),
        jnt2jac(chain),
        jac(chain.getNrOfJoints()),
        transpose(chain.getNrOfJoints()>6),
        m((int)max(6,chain.getNrOfJoints())),
        n((int)min(6,chain.getNrOfJoints())),
        jac_boost(m,n),
        U(ublas::identity_matrix<double>(m)),
        V(ublas::identity_matrix<double>(n)),
        S(n),
        B(m,n),
        tempi(m),
        tempj(m),
        UY(ublas::zero_vector<double>(6)),
        SUY(ublas::zero_vector<double>(chain.getNrOfJoints())),
        qdot_boost(chain.getNrOfJoints()),
        v_in_boost(6)
    {
    }

    ChainIkSolverVel_pinv_boost_givens::~ChainIkSolverVel_pinv_boost_givens()
    {
    }


    int ChainIkSolverVel_pinv_boost_givens::CartToJnt(const JntArray& q_in, const Twist& v_in, JntArray& qdot_out)
    {
        toggle!=toggle;

        jnt2jac.JntToJac(q_in,jac);

        for(unsigned int i=0;i<6;i++)
            v_in_boost(i)=v_in(i);

        for(unsigned int i=0;i<m;i++){
            for(unsigned int j=0;j<n;j++)
                if(transpose)
                    jac_boost(i,j)=jac(j,i);
                else
                    jac_boost(i,j)=jac(i,j);
        }
        int ret = svd_boost_Macie(jac_boost,U,S,V,B,tempi,1e-15,toggle);
        //std::cout<<"# sweeps: "<<ret<<std::endl;

        if(transpose)
            UY.assign(prod(trans(V),v_in_boost));
        else
            UY.assign(prod(trans(U),v_in_boost));

        for (unsigned int i = 0; i < n; i++){
            double wi = UY(i);
            double alpha = S(i);

            if (alpha != 0)
                alpha = 1.0 / alpha;
            else
                alpha = 0.0;
            SUY(i)= alpha * wi;
        }
        if(transpose)
            qdot_boost.assign(prod(U,SUY));
        else
            qdot_boost.assign(prod(V,SUY));

        for (unsigned int j=0;j<chain.getNrOfJoints();j++)
            qdot_out(j)=qdot_boost(j);

        return ret;

    }

}
