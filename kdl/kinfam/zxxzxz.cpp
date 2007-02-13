// Copyright (C) 2006 Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//  

#include <kdl/kinfam/zxxzxz.hpp>

//transformation classes:
#include <kdl/kinfam/zxxzxzcartpos2jnt.hpp>
#include <kdl/kinfam/zxxzxzjnt2cartpos.hpp>
#include <kdl/kinfam/zxxzxzjnt2jac.hpp>
#include <kdl/kinfam/zxxzxzjnt2cartvel.hpp>
#include <kdl/kinfam/zxxzxzcartvel2jnt.hpp>
#include <kdl/kinfam/unittransmission.hpp>

namespace KDL
{
    ZXXZXZ::ZXXZXZ(const std::string& _name,int offset,
                   Transmission* _transmission):
        KinematicFamily(6,offset),
        name(_name),
        l1(0),
        l2(0),
        l3(0),
        l6(0),
        transmission(_transmission)
    {
        if (transmission==0){
            transmission = new UnitTransmission(6);
        }
    }
    
    ZXXZXZ::ZXXZXZ(const ZXXZXZ& in):
        KinematicFamily(6,in.offset()),
        name(in.getName()),
        l1(in.getLinkLength(1)),
        l2(in.getLinkLength(2)),
        l3(in.getLinkLength(3)),
        l6(in.getLinkLength(6)),
        transmission(in.transmission->clone())
    {
    }
    
    ZXXZXZ& ZXXZXZ::operator = (const ZXXZXZ& in)
    {
        this->transmission = in.transmission->clone();
        this->name = in.getName();
        this->_offset = in.offset();
        this->_nrofjoints = 6;
        this->setLinkLengths(in.getLinkLength(1),in.getLinkLength(2),
                             in.getLinkLength(3),in.getLinkLength(6));
        return *this;
    }
    
    
 
    Jnt2CartPos* ZXXZXZ::createJnt2CartPos() const {
        return new ZXXZXZJnt2CartPos(this);
    }
  
    Jnt2Jac* ZXXZXZ::createJnt2Jac() const {
        return new ZXXZXZJnt2Jac(this);
    }
  
    CartPos2Jnt* ZXXZXZ::createCartPos2Jnt() const {
        return new ZXXZXZCartPos2Jnt(this); 
    }

    Jnt2CartVel* ZXXZXZ::createJnt2CartVel() const {
        return new ZXXZXZJnt2CartVel(this);
    }

    CartVel2Jnt* ZXXZXZ::createCartVel2Jnt() const {
        return new ZXXZXZCartVel2Jnt(this);
    }


    ZXXZXZ::~ZXXZXZ() {
        delete transmission;
    }
  
    KinematicFamily* ZXXZXZ::clone() const {
        return new ZXXZXZ(name,offset(),transmission->clone());
    }

    SerialChain* ZXXZXZ::createSerialChain() const {
        SerialChain* serialZXXZXZ = new SerialChain(name,nrOfJoints(),offset(),transmission->clone());
        serialZXXZXZ->addJoint(new JointRotZ(Frame::Identity())); // j1
        serialZXXZXZ->addJoint(new JointRotX(Frame(Rotation::Identity(),Vector(0,0,l1))));// j2
        serialZXXZXZ->addJoint(new JointRotX(Frame(Rotation::Identity(),Vector(0,0,l2))));// j3
        serialZXXZXZ->addJoint(new JointRotZ(Frame(Rotation::Identity(),Vector(0,0,l3)))); // j4
        serialZXXZXZ->addJoint(new JointRotX(Frame(Rotation::Identity(),Vector(0,0,0))));// j5
        serialZXXZXZ->addJoint(new JointRotZ(Frame(Rotation::Identity(),Vector(0,0,0)))); // j6
        serialZXXZXZ->setLastJointToEE(Frame(Rotation::Identity(),Vector(0,0,l6)));
        return serialZXXZXZ;
    }
    
    
    void ZXXZXZ::setLinkLengths( const double _l1, const double _l2, const double _l3, const double _l6 )
    {
        l1 = _l1;
        l2 = _l2;
        l3 = _l3;
        l6 = _l6;
    }
  
    double ZXXZXZ::getLinkLength(int i) const
    {
        if (i==1)
            return l1;
        if (i==2)
            return l2;
        if (i==3)
            return l3;
        if (i==6)
            return l6;
        return 0.0;
    }

    /**
     */
    int ZXXZXZ::getConfigurationFromJoints(const std::vector<double>& q) const {
        assert(q.size()==6);
        double dWh = - sin(q[1])*getLinkLength(2) - sin(q[1]+q[2])*getLinkLength(3);	
        int config = 0;
        if (dWh < 0) config|=Backward;	
        if (q[4]< 0) config|=Flip;
        if (q[2]< 0) config|=ElbowDown;
        return config;
    }

    /**
     */
    void ZXXZXZ::setConfigurationToJoints(int config,std::vector<double>& q) const {
        assert(q.size()==6);
        q[5]=0;
        switch(config) {
        case 0:
            q[0]=0.0;q[1]=-PI/2;q[2]=PI/3;q[3]=PI;q[4]=PI/2;
            break;
        case 4:
            q[0]=0.0;q[1]=0.0;q[2]=-PI/2;q[3]=PI;q[4]=PI/2;
            break;
        case 2:
            q[0]=0.0;q[1]=-PI/2;q[2]=PI/3;q[3]=0;q[4]=-5*PI/6;
            break;
        case 6:
            q[0]=0.0;q[1]=0.0;q[2]=-PI/2;q[3]=0.0;q[4]=-PI/2;
            break;
        case 1:
            q[0]=0.0;q[1]=0.0;q[2]=PI/2;q[3]=0.0;q[4]=PI/2;
            break;
        case 5:
            q[0]=0.0;q[1]=PI/2;q[2]=-PI/3;q[3]=0;q[4]=5*PI/6;
            break;
        case 3:
            q[0]=0.0;q[1]=0.0;q[2]=PI/2;q[3]=PI;q[4]=-PI/2;
            break;
        case 7:
            q[0]=0.0;q[1]=PI/2;q[2]=-PI/3;q[3]=PI;q[4]=-5*PI/6;
            break;
        default:
            assert(0); 
        }
    }
    
    std::string ZXXZXZ::getConfigurationDescription(int config) const {
        std::string description="CONFIGURATION[";
        if ( (config & Backward) == Backward) 
            description+="BACKWARD,";
        else
            description+="FORWARD ,";
        
        if ( (config & ElbowDown) == ElbowDown) 
            description+="ELBOW DOWN,";
        else
            description+="ELBOW UP  ,";
        
        if ( (config & Flip) == Flip) 
            description+="FLIP   ]";
        else
            description+="NO FLIP]";
        
        return description;
    }
    
    /** decision variable: XY distance between wrist and shoulder */
    const double ZXXZXZ::EPS_WRIST_ABOVE_BASE = 0.001; // units: m
    
    /** decision variable: distance of wrist to shoulder must lie between
        sqrt(sq(L2+L3)) and sqrt(sq(L2-L3)). */
    const double ZXXZXZ::EPS_ARM_EXTENDED = 0.001; // units: m
    
    /** decision variable: sine of flip angle (fifth joint) goes to zero. */
    const double ZXXZXZ::EPS_PARALLEL_WRIST = 0.001; // units: dimensionless
    
    /** Considered VERY small in the context of kinematic calculations. */
    const double ZXXZXZ::KINEMATICS_EPS = 1.0e-8;
    
}//namespace
