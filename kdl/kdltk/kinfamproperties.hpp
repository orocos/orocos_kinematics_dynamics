#ifndef KINFAMPROPERTIES_HPP
#define KINFAMPROPERTIES_HPP

#include <kdl/kinfam/kinematicfamily.hpp>
#include <kdl/kinfam/serialchain.hpp>
#include <kdl/kinfam/zxxzxz.hpp>
#include <rtt/Property.hpp>
#include <rtt/PropertyBag.hpp>


namespace RTT
{
    
    using namespace KDL;
    
    bool decomposeProperty(const SerialChain &chain, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, SerialChain &chain);
    
    bool decomposeProperty(const ZXXZXZ &chain, PropertyBag& targetbag);
    bool composeProperty(const PropertyBag& bag, ZXXZXZ &chain);

//    bool decomposeJoint(const KinematicFamily* joint, PropertyBag& targetbag);
//    KinematicFamily* composeJoint(const Property<PropertyBag>& bag);

}
#endif
