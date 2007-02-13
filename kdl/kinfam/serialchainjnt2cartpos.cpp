/***************************************************************************
                        SerialChainJnt2CartPos 
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



#include <kdl/kinfam/serialchainjnt2cartpos.hpp>

namespace KDL {


//===========================================
// implementation of SerialChainJnt2CartPos
//===========================================

/**
 * \todo
 *    have to use transmission when calculating the transformations. 
 */
int SerialChainJnt2CartPos::evaluate(const JointVector& q) {
	trans->fwdPos(q,q_geom,chain->offset());
	Frame F_base_j = Frame::Identity();
	for (int i=0;i<chain->nrOfJoints();++i) {
		F_base_j = F_base_j * chain->getJoint(i)->pose( q_geom[i] );
	}
	F_base_ee = F_base_j * chain->getLastJointToEE();
	return 0;
}

void SerialChainJnt2CartPos::getFrame(Frame& _F_base_ee,int endpoint,int basepoint) {
	_F_base_ee =  F_base_ee;
}

SerialChainJnt2CartPos::SerialChainJnt2CartPos(const SerialChain* _chain):
	chain(_chain),
    q_geom(_chain->nrOfJoints()),
    trans(_chain->transmission->clone()) 
{
}

void SerialChainJnt2CartPos::getConfiguration(std::vector<double>& q_config) {
	assert(q_config.size()==q_geom.size());
    trans->invPos(q_geom,q_config,0);
}


Jnt2CartPos* SerialChainJnt2CartPos::clone() const {
	return new SerialChainJnt2CartPos(chain);
}
SerialChainJnt2CartPos::~SerialChainJnt2CartPos() {
    delete trans;
}



} // end of namespace KDL
