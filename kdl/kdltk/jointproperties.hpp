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
#ifndef JOINTPROPERTIES_HPP
#define JOINTPROPERTIES_HPP

#include <kdl/kinfam/joint.hpp>
#include <rtt/Property.hpp>
#include <rtt/PropertyBag.hpp>


namespace RTT
{
    
    using namespace KDL;
    
    void decomposeProperty(const JointTransX &joint, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, JointTransX &joint);
    
    void decomposeProperty(const JointTransY &joint, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, JointTransY &joint);

    void decomposeProperty(const JointTransZ &joint, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, JointTransZ &joint);

    void decomposeProperty(const JointRotX &joint, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, JointRotX &joint);
    
    void decomposeProperty(const JointRotY &joint, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, JointRotY &joint);

    void decomposeProperty(const JointRotZ &joint, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, JointRotZ &joint);

    bool decomposeJoint(const Joint* joint, PropertyBag& targetbag,std::string name);
    Joint* composeJoint(const Property<PropertyBag>& bag);

}
#endif
    
