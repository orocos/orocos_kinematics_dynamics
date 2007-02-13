/***************************************************************************
                        SerialChainCartPos2Jnt 
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Erwin Aertbelien
    email                : firstname.lastname@mech.kuleuven.ac.be

 History (only major changes)( AUTHOR-Description ) :
 
 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/

#include <kdl/kdl.hpp>
#include <kdl/kinfam/transformation.hpp>
#include <kdl/kinfam/serialchaincartvel2jnt.hpp>
#include <kdl/kinfam/serialchainjnt2jac.hpp>
#include <kdl/kinfam/jnt2jac.hpp>
#include <kdl/jacobianframe.hpp>
#include <kdl/constraints.hpp>
#include <iostream>
#include <kdl/frames_io.hpp>

using namespace KDL;

/**
 * \todo 
 *    BUG: ConstraintMatrix cannot be called with the exact number of joints. Why ?
 */
SerialChainCartVel2Jnt::SerialChainCartVel2Jnt(const SerialChain* _chain):
	chain(_chain),
	jnt2jac(new SerialChainJnt2Jac(_chain,0)),
	FJ_base_actual(_chain->nrOfJoints()),
	cm(30,30),   
	q_dot_subset(_chain->nrOfJoints()),
    t_base_ee(Twist::Zero())
{
	assert(jnt2jac!=0);
    weight_trans = 1.0;
    weight_rot   = 2.0;
    max_amp      = 1000;
}

void SerialChainCartVel2Jnt::getConfiguration(std::vector<double>& q_config) {
	assert(q_config.size()==q_dot_subset.size());
    for (unsigned int i=0;i<q_dot_subset.size();++i) {
        q_config[i] = q_dot_subset[i];
    }
}
void SerialChainCartVel2Jnt::setTwist(const Twist& _t_base_ee,int endpoint, int basepoint)
{
    t_base_ee = _t_base_ee;
}

int SerialChainCartVel2Jnt::evaluate(const JointVector& jv_act,JointVector& _qdot) 
{
    int result=jnt2jac->evaluate(jv_act);
	jnt2jac->getJacobian(FJ_base_actual);
    //std::cout <<"Jacobian : " << FJ_base_actual << std::endl;
    cm.eps = 1/max_amp;
	cm.resetConstraints(chain->nrOfJoints());
	cm.addConstraint(FJ_base_actual,0.0,0.0,Frame::Identity(),t_base_ee, weight_trans, weight_rot);	
    cm.calculateOutput(q_dot_subset);	
    for (unsigned int i=0;i<q_dot_subset.size();++i) {
        //std::cout << "qdotsubset[i]="<<q_dot_subset[i]<<std::endl;
        _qdot[i+chain->offset()]=q_dot_subset[i];
    }
    return result;
}

CartVel2Jnt* SerialChainCartVel2Jnt::clone() const {
	return new SerialChainCartVel2Jnt(chain);
}

SerialChainCartVel2Jnt::~SerialChainCartVel2Jnt() {
	delete jnt2jac;
};


