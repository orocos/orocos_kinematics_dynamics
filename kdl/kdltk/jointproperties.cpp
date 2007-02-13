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

#include <kdl/kdltk/jointproperties.hpp>

namespace RTT
{

    bool decomposeJoint(const Joint* joint, PropertyBag& targetbag,std::string name)
    {
        switch(joint->getType()){
        case Joint::TransX:
            targetbag.add(new Property<JointTransX>(name,"Joint in the serialchain",*((JointTransX*)joint)));
            return true;
        case Joint::TransY:
            targetbag.add(new Property<JointTransY>(name,"Joint in the serialchain",*((JointTransY*)joint)));
            return true;
        case Joint::TransZ:
            targetbag.add(new Property<JointTransZ>(name,"Joint in the serialchain",*((JointTransZ*)joint)));
            return true;
        case Joint::RotX:
            targetbag.add(new Property<JointRotX>(name,"Joint in the serialchain",*((JointRotX*)joint)));
            return true;
        case Joint::RotY:
            targetbag.add(new Property<JointRotY>(name,"Joint in the serialchain",*((JointRotY*)joint)));
            return true;
        case Joint::RotZ:
            targetbag.add(new Property<JointRotZ>(name,"Joint in the serialchain",*((JointRotZ*)joint)));
            return true;
        }
        return false;
    }

    Joint* composeJoint(const Property<PropertyBag>& joint_bag)
    {
        {
            Property<JointTransX> joint(joint_bag.getName(), joint_bag.getDescription());
            if(joint.getTypeInfo()->composeType(joint_bag.getDataSource(),
                                                joint.getDataSource() )){
                return joint.value().clone();
            }
        }
        {
            Property<JointTransY> joint(joint_bag.getName(), joint_bag.getDescription());
            if(joint.getTypeInfo()->composeType(joint_bag.getDataSource(),
                                                joint.getDataSource() )){
                return joint.value().clone();
            }
        }
        {
            Property<JointTransZ> joint(joint_bag.getName(), joint_bag.getDescription());
            if(joint.getTypeInfo()->composeType(joint_bag.getDataSource(),
                                                joint.getDataSource() )){
                return joint.value().clone();
            }
        }
        {
            Property<JointRotX> joint(joint_bag.getName(), joint_bag.getDescription());
            if(joint.getTypeInfo()->composeType(joint_bag.getDataSource(),
                                                joint.getDataSource() )){
                return joint.value().clone();
            }
        }
        {
            Property<JointRotY> joint(joint_bag.getName(), joint_bag.getDescription());
            if(joint.getTypeInfo()->composeType(joint_bag.getDataSource(),
                                                joint.getDataSource() )){
                return joint.value().clone();
            }
        }
        {
            Property<JointRotZ> joint(joint_bag.getName(), joint_bag.getDescription());
            if(joint.getTypeInfo()->composeType(joint_bag.getDataSource(),
                                                joint.getDataSource() )){
                return joint.value().clone();
            }
        }
        return NULL;
    }
    
    void decomposeProperty(const JointTransX &joint, PropertyBag& targetbag)
    {
        targetbag.setType("JointTransX");
        targetbag.add( new Property<Frame>("F_before_joint", "frame that represents the link between the previous joint and the current", joint.frame_before_joint() ));
    }
    
    bool composeProperty(const PropertyBag& bag, JointTransX &joint)
    {
        if ( bag.getType() == std::string("JointTransX") ){ // check the type
            Property<PropertyBag> f_bag = bag.getProperty<PropertyBag>("F_before_joint");
            if ( !f_bag.ready() )
                return false;
            // Now create the frame locally:
            Property<Frame> f_frame(f_bag.getName(), f_bag.getDescription());
            // Fill it in with the values of the bag:
            f_frame.getTypeInfo()->composeType(f_bag.getDataSource(),
                                               f_frame.getDataSource() );
            joint.frame_before_joint(f_frame.value());
            return true;
        }
        return false;
    }
    
    void decomposeProperty(const JointTransY &joint, PropertyBag& targetbag)
    {
        targetbag.setType("JointTransY");
        targetbag.add( new Property<Frame>("F_before_joint", "frame that represents the link between the previous joint and the current", joint.frame_before_joint() ));
    }

    bool composeProperty(const PropertyBag& bag, JointTransY &joint)
    {
        if ( bag.getType() == std::string("JointTransY") ){ // check the type
            Property<PropertyBag> f_bag = bag.getProperty<PropertyBag>("F_before_joint");
            if ( !f_bag.ready() )
                return false;
            // Now create the frame locally:
            Property<Frame> f_frame(f_bag.getName(), f_bag.getDescription());
            // Fill it in with the values of the bag:
            f_frame.getTypeInfo()->composeType(f_bag.getDataSource(),
                                               f_frame.getDataSource() );
            joint.frame_before_joint(f_frame.value());
            return true;
        }
        return false;
        // unknown type !
    }
    

    void decomposeProperty(const JointTransZ &joint, PropertyBag& targetbag)
    {
        targetbag.setType("JointTransZ");
        targetbag.add( new Property<Frame>("F_before_joint", "frame that represents the link between the previous joint and the current", joint.frame_before_joint() ));
    }
    
    bool composeProperty(const PropertyBag& bag, JointTransZ &joint)
    {
        if ( bag.getType() == std::string("JointTransZ") ){ // check the type
            Property<PropertyBag> f_bag = bag.getProperty<PropertyBag>("F_before_joint");
            if ( !f_bag.ready() )
                return false;
            // Now create the frame locally:
            Property<Frame> f_frame(f_bag.getName(), f_bag.getDescription());
            // Fill it in with the values of the bag:
            f_frame.getTypeInfo()->composeType(f_bag.getDataSource(),
                                               f_frame.getDataSource() );
            joint.frame_before_joint(f_frame.value());
            return true;
        }
        return false;
        // unknown type !
    }

    void decomposeProperty(const JointRotX &joint, PropertyBag& targetbag)
    {
        targetbag.setType("JointRotX");
        targetbag.add( new Property<Frame>("F_before_joint", "frame that represents the link between the previous joint and the current", joint.frame_before_joint() ));
    }
    bool composeProperty(const PropertyBag& bag, JointRotX &joint)
    {
        if ( bag.getType() == std::string("JointRotX") ){ // check the type
            Property<PropertyBag> f_bag = bag.getProperty<PropertyBag>("F_before_joint");
            if ( !f_bag.ready() )
                return false;
            // Now create the frame locally:
            Property<Frame> f_frame(f_bag.getName(), f_bag.getDescription());
            // Fill it in with the values of the bag:
            f_frame.getTypeInfo()->composeType(f_bag.getDataSource(),
                                               f_frame.getDataSource() );
            joint.frame_before_joint(f_frame.value());
            return true;
        }
        return false;
        // unknown type !
    }
    
    void decomposeProperty(const JointRotY &joint, PropertyBag& targetbag)
    {
        targetbag.setType("JointRotY");
        targetbag.add( new Property<Frame>("F_before_joint", "frame that represents the link between the previous joint and the current", joint.frame_before_joint() ));
    }
    bool composeProperty(const PropertyBag& bag, JointRotY &joint)
    {
        if ( bag.getType() == std::string("JointRotY") ){ // check the type
            Property<PropertyBag> f_bag = bag.getProperty<PropertyBag>("F_before_joint");
            if ( !f_bag.ready() )
                return false;
            // Now create the frame locally:
            Property<Frame> f_frame(f_bag.getName(), f_bag.getDescription());
            // Fill it in with the values of the bag:
            f_frame.getTypeInfo()->composeType(f_bag.getDataSource(),
                                               f_frame.getDataSource() );
            joint.frame_before_joint(f_frame.value());
            return true;
        }
        return false;
        // unknown type !
    }

    void decomposeProperty(const JointRotZ &joint, PropertyBag& targetbag)
    {
        targetbag.setType("JointRotZ");
        targetbag.add( new Property<Frame>("F_before_joint", "frame that represents the link between the previous joint and the current",joint.frame_before_joint() ));
    }

    bool composeProperty(const PropertyBag& bag, JointRotZ &joint)
    {
        if ( bag.getType() == std::string("JointRotZ") ){ // check the type
            Property<PropertyBag> f_bag = bag.getProperty<PropertyBag>("F_before_joint");
            if ( !f_bag.ready() )
                return false;
            // Now create the frame locally:
            Property<Frame> f_frame(f_bag.getName(), f_bag.getDescription());
            // Fill it in with the values of the bag:
            f_frame.getTypeInfo()->composeType(f_bag.getDataSource(),
                                               f_frame.getDataSource() );
            joint.frame_before_joint(f_frame.value());
            return true;
        }
        return false;
        // unknown type !
    }
}

