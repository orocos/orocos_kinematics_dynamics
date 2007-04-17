/***************************************************************************
                        SerialChainJnt2CartVel.hpp 
                       ----------------------------
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

#include <kdl/kinfam/serialchainjnt2cartvel.hpp>
#include <iostream>
#include <kdl/frames_io.hpp>
namespace KDL {


//===========================================
// implementation of SerialChainJnt2Jac
//===========================================

SerialChainJnt2CartVel::SerialChainJnt2CartVel(const SerialChain* _chain):
	chain(_chain),
	frames(_chain->nrOfJoints()),
	q_geom(_chain->nrOfJoints()),
    q_geom_dot(_chain->nrOfJoints()),
    trans(_chain->transmission->clone())
{
}

void SerialChainJnt2CartVel::getConfiguration(std::vector<double>& q_config) {
	assert(q_config.size()==q_geom.size());
    trans->invPos(q_geom,q_config,0);
}


int SerialChainJnt2CartVel::evaluate(const JointVector& q,const JointVector& qdot) 
{
    trans->fwdPos(q,q_geom,chain->offset());
    trans->fwdVel(q,qdot,q_geom_dot,chain->offset());
    unsigned int length = chain->nrOfJoints();
    Frame F_base_j = Frame::Identity();
    for (unsigned int i=0;i<length;++i) {
        F_base_j   = F_base_j * chain->getJoint(i)->pose( q_geom[i] );
        frames[i]  = F_base_j;
    }
    F_base_ee = F_base_j * chain->getLastJointToEE(); 
    return 0;
}

void SerialChainJnt2CartVel::getFrameVel(FrameVel& F_base_end,int endpoint,int basepoint) 
{
    unsigned int length = chain->nrOfJoints();
	Vector p_base_ee  = F_base_ee.p;
	// fill in Jacobian :
    Twist t = Twist::Zero(); 
    for (unsigned int i=0;i<length;++i) {
        Twist t_base = frames[i].M * (chain->getJoint(i)->twist());
        t += t_base.RefPoint(p_base_ee-frames[i].p)*q_geom_dot[i];
    }
    F_base_end = FrameVel(F_base_ee,t);
}

Jnt2CartVel* SerialChainJnt2CartVel::clone() const {
	return new SerialChainJnt2CartVel(chain);
}

SerialChainJnt2CartVel::~SerialChainJnt2CartVel() {
    delete trans;
}

} // end of namespace KDL
