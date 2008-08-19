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

#ifndef JOINTPROPERTIES_HPP
#define JOINTPROPERTIES_HPP

#include "../../joint.hpp"
#include "../../segment.hpp"
#include "../../kinfam_io.hpp"

#include <rtt/Property.hpp>
#include <rtt/PropertyBag.hpp>
#include <rtt/TemplateTypeInfo.hpp>


namespace RTT
{

    using namespace KDL;
    struct JointTypeInfo : public TemplateTypeInfo<Joint,true>
    {
        JointTypeInfo():TemplateTypeInfo<Joint,true>("Joint")
        {};
        bool decomposeTypeImpl(const Joint& joint, PropertyBag& targetbag);
        bool composeTypeImpl(const PropertyBag& bag, Joint& joint);
    };
    struct SegmentTypeInfo : public TemplateTypeInfo<Segment,true>
    {
        SegmentTypeInfo():TemplateTypeInfo<Segment,true>("Segment")
        {};
        bool decomposeTypeImpl(const Segment& segment, PropertyBag& targetbag);
        bool composeTypeImpl(const PropertyBag& bag, Segment& segment);
    };
    struct ChainTypeInfo : public TemplateTypeInfo<Chain,true>
    {
        ChainTypeInfo():TemplateTypeInfo<Chain,true>("Chain")
        {};
        bool decomposeTypeImpl(const Chain& chain, PropertyBag& targetbag);
        bool composeTypeImpl(const PropertyBag& bag, Chain& chain);
    };

}
#endif

