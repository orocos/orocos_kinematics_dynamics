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

#ifndef TRANSPROPERTIES_HPP
#define TRANSPROPERTIES_HPP

#include <kdl/kinfam/transmission.hpp>
#include <kdl/kinfam/unittransmission.hpp>
#include <kdl/kinfam/lineartransmission.hpp>
#include <kdl/kinfam/kuka361transmission.hpp>
#include <rtt/Property.hpp>
#include <rtt/PropertyBag.hpp>


namespace RTT
{
    
    using namespace KDL;
    
    void decomposeProperty(const UnitTransmission &trans, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, UnitTransmission &trans);
    
    void decomposeProperty(const LinearTransmission &trans, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, LinearTransmission &trans);

    void decomposeProperty(const Kuka361Transmission &trans, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, Kuka361Transmission &trans);
    
    bool decomposeTrans(const Transmission* trans, PropertyBag& targetbag);
    Transmission* composeTrans(const Property<PropertyBag>& bag);
}
#endif
    
