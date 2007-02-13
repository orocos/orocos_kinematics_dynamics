// Copyright (C) 2007 Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
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
#include <kdl/kdltk/kinfamproperties.hpp>
#include <kdl/kdltk/transproperties.hpp>
#include <kdl/kdltk/jointproperties.hpp>
#include <sstream>

namespace RTT
{
    using namespace KDL;
    using namespace std;
    
    bool decomposeProperty(const SerialChain &chain, PropertyBag& targetbag)
    {
        targetbag.setType("SerialChain");
        
        if(!decomposeTrans(chain.transmission,targetbag))
            return false;
            
        targetbag.add( new Property<std::string>("name","name of the serialchain",chain.getName()));
        targetbag.add( new Property<int>("offset","offset for the first joint of the serialchain",chain.offset()));
        targetbag.add( new Property<int>("nrofjoints","nr of joints in the serialchain",chain.nrOfJoints()));
        for(unsigned int i = 0; i<chain.nrOfJoints();i++){
            stringstream joint_ss;
            joint_ss<<"Joint"<<i;
            if(!decomposeJoint(chain.getJoint(i),targetbag,joint_ss.str()))
                return false;
        }
        targetbag.add( new Property<Frame>("frame_lastjoint_to_ee","frame from the last joint to the end effector of the chain",
                                           chain.getLastJointToEE()));
        return true;
    }
    
    bool composeProperty(const PropertyBag& bag, SerialChain &chain)
    {
        if ( bag.getType() == std::string("SerialChain") ){ // check the type
            //Transmission
            Property<PropertyBag> trans_bag = bag.getProperty<PropertyBag>("transmission");
            if ( !trans_bag.ready() )
                return false;
            Transmission* transp = composeTrans(trans_bag);
            if(transp == NULL)
                return false;
                                                
            //Name
            Property<std::string> name = bag.getProperty<std::string>("name");
            if ( !name.ready() )
                return false;

            //Offset
            Property<int> offset = bag.getProperty<int>("offset");
            if ( !offset.ready() )
                return false;
            
            //NrOfJoints
            Property<int> nrofjoints = bag.getProperty<int>("nrofjoints");
            if ( !nrofjoints.ready() )
                return false;
            
            chain = SerialChain(name.value(),nrofjoints.value(),offset.value(),transp);
            for(unsigned int i=0;i<chain.nrOfJoints();i++){
                stringstream joint_ss;
                joint_ss<<"Joint"<<i;
                Property<PropertyBag> joint_bag = bag.getProperty<PropertyBag>(joint_ss.str());
                if ( !joint_bag.ready() )
                    return false;
                
                Joint* jointp = composeJoint(joint_bag);
                if(jointp==NULL)
                    return false;
                chain.addJoint(jointp->clone());
            }
            
            //Frame from last joint to ee
            Property<PropertyBag> f_bag = bag.getProperty<PropertyBag>("frame_lastjoint_to_ee");
            if(!f_bag.ready())
                return false;
            Property<Frame> f(f_bag.getName(),f_bag.getDescription());
            f.getTypeInfo()->composeType(f_bag.getDataSource(),f.getDataSource());
            
            chain.setLastJointToEE(f.value());
            return true;
        }
        return false;
        // unknown type !
    }
    
    bool decomposeProperty(const ZXXZXZ &chain, PropertyBag& targetbag)
    {
        targetbag.setType("ZXXZXZ");
        
        if(!decomposeTrans(chain.transmission,targetbag))
            return false;
            
        targetbag.add( new Property<string>("name","name of the chain",chain.getName()));
        targetbag.add( new Property<int>("offset","offset for the first joint of the chain",chain.offset()));
        targetbag.add( new Property<double>("link1","lenght of link 1",chain.getLinkLength(1)));
        targetbag.add( new Property<double>("link2","lenght of link 2",chain.getLinkLength(2)));
        targetbag.add( new Property<double>("link3","lenght of link 3",chain.getLinkLength(3)));
        targetbag.add( new Property<double>("link6","lenght of link 6",chain.getLinkLength(6)));
        
        return true;
    }
    bool composeProperty(const PropertyBag& bag, ZXXZXZ &chain)
    {
        if ( bag.getType() == std::string("ZXXZXZ") ){ // check the type
            //Transmission
            Property<PropertyBag> trans_bag = bag.getProperty<PropertyBag>("transmission");
            if ( !trans_bag.ready() )
                return false;
            Transmission* transp = composeTrans(trans_bag);
            if(transp == NULL)
                return false;
            
            //Name
            Property<std::string> name = bag.getProperty<std::string>("name");
            if ( !name.ready() )
                return false;
            
            //Offset
            Property<int> offset = bag.getProperty<int>("offset");
            if ( !offset.ready() )
                return false;
            
            chain = ZXXZXZ(name.value(),offset.value(),transp);
            
            //LinkLenghts
            Property<double> l1 = bag.getProperty<double>("link1");
            Property<double> l2 = bag.getProperty<double>("link2");
            Property<double> l3 = bag.getProperty<double>("link3");
            Property<double> l6 = bag.getProperty<double>("link6");
            
            if(!(l1.ready()&&l2.ready()&&l3.ready()&&l6.ready()))
                return false;
            
            chain.setLinkLengths(l1.value(),l2.value(),l3.value(),l6.value());
            return true;
        }
        return false;
        // unknown type !
    }
}


