/***************************************************************************
                        SerialChainJnt2Jac.hpp 
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

#include <kdl/kinfam/serialchainjnt2jac.hpp>

namespace KDL {


//===========================================
// implementation of SerialChainJnt2Jac
//===========================================

SerialChainJnt2Jac::SerialChainJnt2Jac(const SerialChain* _chain,int _offset):
	chain(_chain),
    offset(_offset),
	frames(_chain->nrOfJoints()),
	q_geom(_chain->nrOfJoints()),
	FJ_base_ee_geom(_chain->nrOfJoints()),
    trans(_chain->transmission->clone())
{
}

SerialChainJnt2Jac::SerialChainJnt2Jac(const SerialChain* _chain):
	chain(_chain),
    offset(_chain->offset()),
	frames(_chain->nrOfJoints()),
	q_geom(_chain->nrOfJoints()),
	FJ_base_ee_geom(_chain->nrOfJoints()),
    trans(_chain->transmission->clone())
{
}


void SerialChainJnt2Jac::getConfiguration(std::vector<double>& q_config) {
	assert(q_config.size()==q_geom.size());
    trans->invPos(q_geom,q_config,0);
}



int SerialChainJnt2Jac::evaluate(const JointVector& q) {
  trans->fwdPos(q,q_geom,offset);
  unsigned int length = chain->nrOfJoints();
  Frame F_base_j = Frame::Identity();
  for (unsigned int i=0;i<length;++i) {
    F_base_j   = F_base_j * chain->getJoint(i)->pose( q_geom[i] );
    frames[i]  = F_base_j;
  }
  F_base_ee = F_base_j * chain->getLastJointToEE(); 
  return 0;
}

void SerialChainJnt2Jac::getJacobian(Jacobian<Frame>& FJ_base_ee,int endpoint, int basepoint) {
    unsigned int length = chain->nrOfJoints();
	FJ_base_ee_geom = F_base_ee;
	Vector p_base_ee  = F_base_ee.p;
	// fill in Jacobian :
    for (unsigned int i=0;i<length;++i) {
       Twist t_base = frames[i].M * (chain->getJoint(i)->twist());
       FJ_base_ee_geom.deriv(i) = t_base.RefPoint(p_base_ee-frames[i].p);
    }
	trans->invJac(FJ_base_ee_geom,FJ_base_ee,offset);
}

Jnt2Jac* SerialChainJnt2Jac::clone() const {
	return new SerialChainJnt2Jac(chain);
}

SerialChainJnt2Jac::~SerialChainJnt2Jac() {
    delete trans;
}

} // end of namespace KDL
