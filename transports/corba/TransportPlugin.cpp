/* Generated from orogen/lib/orogen/templates/typekit/corba/TransportPlugin.cpp */

// First load all RTT interfaces so that we get all "extern template"
// declarations in the TypekitImpl files
#include "transports/corba/Registration.hpp"
#include "transports/corba/TransportPlugin.hpp"
#include <rtt/transports/corba/CorbaLib.hpp>
#include <rtt/types/TypekitPlugin.hpp>
using namespace RTT;

bool orogen_typekits::kdlCorbaTransportPlugin::registerTransport(std::string type_name, RTT::types::TypeInfo* ti)
{
    
    if ("Frame" == type_name)
    {
        ti->addProtocol(ORO_CORBA_PROTOCOL_ID,
            KDL_Frame_CorbaTransport());
        return true;
    }
    
    else if ("Rotation" == type_name)
    {
        ti->addProtocol(ORO_CORBA_PROTOCOL_ID,
            KDL_Rotation_CorbaTransport());
        return true;
    }
    
    else if ("Twist" == type_name)
    {
        ti->addProtocol(ORO_CORBA_PROTOCOL_ID,
            KDL_Twist_CorbaTransport());
        return true;
    }
    
    else if ("Vector" == type_name)
    {
        ti->addProtocol(ORO_CORBA_PROTOCOL_ID,
            KDL_Vector_CorbaTransport());
        return true;
    }
    
    else if ("Wrench" == type_name)
    {
        ti->addProtocol(ORO_CORBA_PROTOCOL_ID,
            KDL_Wrench_CorbaTransport());
        return true;
    }
    
    return false;
}
std::string orogen_typekits::kdlCorbaTransportPlugin::getTransportName() const
{ return "CORBA"; }
std::string orogen_typekits::kdlCorbaTransportPlugin::getTypekitName() const
{ return "/orogen/kdl"; }
std::string orogen_typekits::kdlCorbaTransportPlugin::getName() const
{ return "/orogen/kdl/CORBA"; }

ORO_TYPEKIT_PLUGIN(orogen_typekits::kdlCorbaTransportPlugin);

