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

#include "kinfamproperties.hpp"
#include <rtt/Logger.hpp>
#include <string>

namespace RTT
{
    bool JointTypeInfo::decomposeTypeImpl(const Joint& joint, PropertyBag& targetbag)
    {
        targetbag.setType("KDL::Joint");
        targetbag.add( new Property<std::string>("Type", "Type of Joint",joint.getTypeName()));
        return true;
    }

    bool JointTypeInfo::composeTypeImpl(const PropertyBag& bag, Joint& joint)
    {
        if ( bag.getType() == "KDL::Joint" ){ // check the type
            Property<std::string> type_name = bag.getProperty<std::string>("Type");
            if ( !type_name.ready() )
                return false;
            if (type_name.value()=="RotX"){
                joint=Joint(Joint::RotX);
                return true;
            }else if(type_name.value()=="RotY"){
                joint=Joint(Joint::RotY);
                return true;
            }else if(type_name.value()=="RotZ"){
                joint=Joint(Joint::RotZ);
                return true;
            }else if(type_name.value()=="TransX"){
                joint=Joint(Joint::TransX);
                return true;
            }else if(type_name.value()=="TransY"){
                joint=Joint(Joint::TransY);
                return true;
            }else if(type_name.value()=="TransZ"){
                joint=Joint(Joint::TransZ);
                return true;
            }
            else
                return false;
        }
        return false;
    }

    bool decomposeTypeImpl(const Segment& segment, PropertyBag& targetbag)
    {
        targetbag.setType("KDL::Segment");
        targetbag.add( new Property<Joint>("joint", "The joint at the base of this segment",segment.getJoint()));
        targetbag.add(new Property<Frame>("frame","The offset frame from the joint at the base to the end of the link",segment.getFrameToTip()));
        return true;
    }

    bool composeTypeImpl(const PropertyBag& bag, Segment& segment)
    {
        if ( bag.getType() == "KDL::Segment" ){ // check the type
            Property<PropertyBag> joint_bag = bag.getProperty<PropertyBag>("joint");
            Property<PropertyBag> frame_bag = bag.getProperty<PropertyBag>("frame");
            if(!(frame_bag.ready()&&joint_bag.ready()))
                return false;
            Property<Joint> joint_prop(joint_bag.getName(),joint_bag.getDescription());
            joint_prop.getTypeInfo()->composeType(joint_bag.getDataSource(),
                                                 joint_prop.getDataSource());
            Property<Frame> frame_prop(frame_bag.getName(),frame_bag.getDescription());
            frame_prop.getTypeInfo()->composeType(frame_bag.getDataSource(),
                                                 frame_prop.getDataSource());
            segment=Segment(joint_prop.value(),frame_prop.value());
            return true;
        }
        else
            return false;
    }

    bool decomposeTypeImpl(const Chain& chain, PropertyBag& targetbag)
    {
        targetbag.setType("KDL::Chain");
        for(unsigned int i=0;i<chain.getNrOfSegments();i++)
            targetbag.add(new Property<Segment>("Segment","Segment of the chain",chain.getSegment(i)));
        return true;
    }

    bool composeTypeImpl(const PropertyBag& bag, Chain& chain)
    {
        Chain chain_new;
        if( bag.getType() =="KDL::Chain"){
            for(unsigned int i=0;i<bag.size();i++){
                PropertyBase* segment_bag = bag.getItem(i);
                if(!segment_bag->ready())
                    return false;
                Property<Segment> segment_prop(segment_bag->getName(),
                                               segment_bag->getDescription());
                segment_prop.getTypeInfo()->composeType(segment_bag->getDataSource(),
                                                       segment_prop.getDataSource());
                chain_new.addSegment(segment_prop.value());
            }
            chain = chain_new;
            return true;
        }else
            return false;
    }
}


