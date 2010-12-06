/* Generated from orogen/lib/orogen/templates/typekit/mqueue/TransportPlugin.cpp */

// First load all RTT interfaces so that we get all "extern template"
// declarations in the TypekitImpl files
#include "transports/mqueue/Registration.hpp"
#include "transports/mqueue/TransportPlugin.hpp"
#include <rtt/transports/mqueue/MQLib.hpp>
#include <rtt/types/TypekitPlugin.hpp>
using namespace RTT;

bool orogen_typekits::kdlMQueueTransportPlugin::registerTransport(std::string type_name, RTT::types::TypeInfo* ti)
{
    
    if ("Frame" == type_name)
    {
        ti->addProtocol(ORO_MQUEUE_PROTOCOL_ID,
            KDL_Frame_MQueueTransport());
        return true;
    }
    
    else if ("Rotation" == type_name)
    {
        ti->addProtocol(ORO_MQUEUE_PROTOCOL_ID,
            KDL_Rotation_MQueueTransport());
        return true;
    }
    
    else if ("Twist" == type_name)
    {
        ti->addProtocol(ORO_MQUEUE_PROTOCOL_ID,
            KDL_Twist_MQueueTransport());
        return true;
    }
    
    else if ("Vector" == type_name)
    {
        ti->addProtocol(ORO_MQUEUE_PROTOCOL_ID,
            KDL_Vector_MQueueTransport());
        return true;
    }
    
    else if ("Wrench" == type_name)
    {
        ti->addProtocol(ORO_MQUEUE_PROTOCOL_ID,
            KDL_Wrench_MQueueTransport());
        return true;
    }
    return false;
}
std::string orogen_typekits::kdlMQueueTransportPlugin::getTransportName() const
{ return "MQueue"; }
std::string orogen_typekits::kdlMQueueTransportPlugin::getTypekitName() const
{ return "/orogen/kdl"; }
std::string orogen_typekits::kdlMQueueTransportPlugin::getName() const
{ return "/orogen/kdl/MQueue"; }

ORO_TYPEKIT_PLUGIN(orogen_typekits::kdlMQueueTransportPlugin);

