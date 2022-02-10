// Copyright  (C)  2020  Ruben Smits <ruben dot smits at intermodalics dot eu>

// Version: 1.0
// Author: Francois Cauwe <francois at cauwe dot org>
// Author: Ruben Smits <ruben dot smits at intermodalics dot eu>
// Maintainer: Ruben Smits <ruben dot smits at intermodalics dot eu>
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

#include "chainfksolverpos_recursive.hpp"
#include <iostream>

namespace KDL {

    ChainFkSolverPos_recursive::ChainFkSolverPos_recursive(const Chain& _chain):
        chain(_chain)
    {
    }

    int ChainFkSolverPos_recursive::JntToCart(const JntArray& q_in, Frame& p_out, int seg_nr)    {
        unsigned int segmentNr;
        if(seg_nr<0)
            segmentNr=chain.getNrOfSegments();
        else
            segmentNr = seg_nr;

        p_out = Frame::Identity();

        if(q_in.rows()!=chain.getNrOfJoints())
            return (error = E_SIZE_MISMATCH);
        else if(segmentNr>chain.getNrOfSegments())
            return (error = E_OUT_OF_RANGE);
        else{
            int j=0;
            for(unsigned int i=0;i<segmentNr;i++){
                if(chain.getSegment(i).getJoint().getType()!=Joint::Fixed) {
                    p_out = p_out*chain.getSegment(i).pose(q_in(j));
                    j++;
                }else{
                    p_out = p_out*chain.getSegment(i).pose(0.0);
                }
            }
            return (error = E_NOERROR);
        }
    }
    int ChainFkSolverPos_recursive::JntToCart(const JntArray& q_in, std::vector<Frame>& p_out, int seg_nr)    {
        unsigned int segmentNr;
        if(seg_nr<0)
            segmentNr=chain.getNrOfSegments();
        else
            segmentNr = seg_nr;

        if(q_in.rows()!=chain.getNrOfJoints())
            return -1;
        else if(segmentNr>chain.getNrOfSegments())
            return -1;
        else if(p_out.size() != segmentNr)
            return -1;
        else if(segmentNr == 0)
            return -1;
        else{
            int j=0;
            // Initialization
            if(chain.getSegment(0).getJoint().getType()!=Joint::Fixed) {
                p_out[0] = chain.getSegment(0).pose(q_in(j));
                j++;
            }else
                p_out[0] = chain.getSegment(0).pose(0.0);

            for(unsigned int i=1;i<segmentNr;i++){
                if(chain.getSegment(i).getJoint().getType()!=Joint::Fixed) {
                    p_out[i] = p_out[i-1]*chain.getSegment(i).pose(q_in(j));
                    j++;
                }else{
                    p_out[i] = p_out[i-1]*chain.getSegment(i).pose(0.0);
                }
            }
            return 0;
        }
    }

    ChainFkSolverPos_recursive::~ChainFkSolverPos_recursive()
    {
    }


}
