/***************************************************************************
                        serialchain.cpp -  description
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

#include <kdl/kinfam/serialchain.hpp>

// transformation classes :
#include <kdl/kinfam/serialchaincartpos2jnt.hpp>
#include <kdl/kinfam/serialchainjnt2cartpos.hpp>
#include <kdl/kinfam/serialchainjnt2cartvel.hpp>
#include <kdl/kinfam/serialchaincartvel2jnt.hpp>
#include <kdl/kinfam/serialchainjnt2jac.hpp>


#include <kdl/kinfam/unittransmission.hpp>


namespace KDL {

 

SerialChain::SerialChain(const std::string& _name, int nrofjoints,int offset,Transmission* _transmission):
    KinematicFamily(nrofjoints,offset),
	name(_name),
	F_lj_ee(Frame::Identity()), 
	transmission(_transmission)
{
	if (transmission==0) {
		transmission = new UnitTransmission(nrofjoints);
	}
}
SerialChain::SerialChain(const SerialChain& in):
    KinematicFamily(in.nrOfJoints(),in.offset()),
    name(in.getName()),
    F_lj_ee(in.getLastJointToEE()),
    transmission(in.transmission->clone())
{
    for(unsigned int i = 0;i<in.joints.size();i++){
        this->addJoint(in.getJoint(i)->clone());
    } 
}

SerialChain& SerialChain::operator = (const SerialChain& in)
{
    this->clear();
    
    this->transmission = in.transmission->clone() ;
        
    this->name = in.getName();
    this->_offset = in.offset();
    this->_nrofjoints = in.nrOfJoints();
    this->setLastJointToEE(in.getLastJointToEE());
    for(unsigned int i = 0;i<in.joints.size();i++){
        this->addJoint(in.getJoint(i)->clone());
    } 
    return *this;
}


Jnt2CartPos* SerialChain::createJnt2CartPos() const {
	return new SerialChainJnt2CartPos(this);
}

Jnt2Jac* SerialChain::createJnt2Jac() const {
	return new SerialChainJnt2Jac(this);
}

CartPos2Jnt* SerialChain::createCartPos2Jnt() const {
	return new SerialChainCartPos2Jnt(this);
}

CartVel2Jnt* SerialChain::createCartVel2Jnt() const {
	return new SerialChainCartVel2Jnt(this);
}


void SerialChain::addJoint(Joint* joint) {
    joints.push_back(joint);
}

void SerialChain::addChain(const SerialChain* chain) {
        if (chain->joints.size()==0) {
            F_lj_ee = F_lj_ee * chain->F_lj_ee;
            return;
        }
        Joint* joint = chain->joints[0]->clone();
        joint->frame_before_joint( F_lj_ee * joint->frame_before_joint() );
        addJoint(joint);
        for (unsigned int i=1;i < chain->joints.size();++i) {
            addJoint( chain->joints[i]->clone() );
        } 
        F_lj_ee = chain->F_lj_ee;
}

const Joint* SerialChain::getJoint(unsigned int i) const {
        KDL_ASSERT( (0<= i) && (i<joints.size()) );
        return joints[i];
}


Joint* SerialChain::getJoint(unsigned int i) {
        KDL_ASSERT( (0<= i) && (i<joints.size()) );
        return joints[i];
}


/**
 * specifies the transformation from the last joint
 * to the end effector.
\ */
void SerialChain::setLastJointToEE(const Frame& _F_lj_ee) {
    F_lj_ee = _F_lj_ee;
}

Frame SerialChain::getLastJointToEE() const {
   return F_lj_ee;
}

void SerialChain::clear() {
        for (unsigned int i=0;i<joints.size();++i) {
            delete joints[i];
        }
        F_lj_ee = Frame::Identity();
        joints.erase(joints.begin(),joints.end());
        delete transmission;
}

SerialChain::~SerialChain() {
   clear();
}

KinematicFamily* SerialChain::clone() const {
	SerialChain* kf = new SerialChain(name,nrOfJoints(),offset(),transmission->clone());
    kf->addChain(this);
    return kf;
}

Jnt2CartVel* SerialChain::createJnt2CartVel() const {
    return new SerialChainJnt2CartVel(this);
}

} // namespace KDL


