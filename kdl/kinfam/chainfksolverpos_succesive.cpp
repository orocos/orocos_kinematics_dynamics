//
// C++ Implementation: chainfksolverpos_succesive
//
// Description: 
//
//
// Author: Ruben Smits <first dot last at mech dot kuleuven dot be>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "chainfksolverpos_succesive.hpp"

namespace KDL {

ChainFkSolverPos_succesive::ChainFkSolverPos_succesive(Chain* _chain):
    chain(_chain)
{
}

ChainFkSolverPos_succesive::jnt2cart(const ChainJntArray& q_in, ChainCartPos& p_out)
{
    Frame p_local;
    p_out = Frame::Identity();
    for(unsigned int i;i<chain.nrOfJoints;i++){
        chain.segments[i]->jnt2cart(q_in[i],p_local);
        p_out = p_local*p_out;
    }
}


ChainFkSolverPos_succesive::~ChainFkSolverPos_succesive()
{
}


}
