/* Generated from orogen/lib/orogen/templates/typekit/typelib/TransportPlugin.cpp */

// First load all RTT interfaces so that we get all "extern template"
// declarations in the TypekitImpl files
#include "Registration.hpp"
#include "TransportPlugin.hpp"
#include <rtt/types/TypekitPlugin.hpp>
#include <typelib/pluginmanager.hh>
#include <utilmm/configfile/pkgconfig.hh>
using namespace RTT;

#define TYPEKIT_PACKAGE_NAME_aux0(target) #target
#define TYPEKIT_PACKAGE_NAME_aux(target) "kdl-typekit-" TYPEKIT_PACKAGE_NAME_aux0(target)
#define TYPEKIT_PACKAGE_NAME TYPEKIT_PACKAGE_NAME_aux(OROCOS_TARGET)

orogen_typekits::kdlTypelibTransportPlugin::kdlTypelibTransportPlugin()
    : m_registry(0)
{
    try {
        utilmm::pkgconfig pkg(TYPEKIT_PACKAGE_NAME);
        std::string tlb = pkg.get("type_registry");
        m_registry = Typelib::PluginManager::load("tlb", tlb);
    }
    catch(utilmm::not_found)
    {
        std::cerr << "cannot find the pkg-config specification associated with this typekit:" << std::endl;
        std::cerr << "  " << TYPEKIT_PACKAGE_NAME << std::endl;
        std::cerr << "this is required to use the typelib transport" << std::endl;
        std::cerr << "No typelib transport will be available for the types in this typekit" << std::endl;
    }

}

bool orogen_typekits::kdlTypelibTransportPlugin::registerTransport(std::string type_name, RTT::types::TypeInfo* ti)
{
    if (!m_registry)
        return false;

    
    if ("Frame" == type_name)
    {
        ti->addProtocol(orogen_transports::TYPELIB_MARSHALLER_ID,
            KDL_Frame_TypelibMarshaller(*m_registry));
        return true;
    }
    
    else if ("Rotation" == type_name)
    {
        ti->addProtocol(orogen_transports::TYPELIB_MARSHALLER_ID,
            KDL_Rotation_TypelibMarshaller(*m_registry));
        return true;
    }
    
    else if ("Twist" == type_name)
    {
        ti->addProtocol(orogen_transports::TYPELIB_MARSHALLER_ID,
            KDL_Twist_TypelibMarshaller(*m_registry));
        return true;
    }
    
    else if ("Vector" == type_name)
    {
        ti->addProtocol(orogen_transports::TYPELIB_MARSHALLER_ID,
            KDL_Vector_TypelibMarshaller(*m_registry));
        return true;
    }
    
    else if ("Wrench" == type_name)
    {
        ti->addProtocol(orogen_transports::TYPELIB_MARSHALLER_ID,
            KDL_Wrench_TypelibMarshaller(*m_registry));
        return true;
    }
    
    return false;
}
std::string orogen_typekits::kdlTypelibTransportPlugin::getTransportName() const
{ return "Typelib"; }
std::string orogen_typekits::kdlTypelibTransportPlugin::getTypekitName() const
{ return "/orogen/kdl"; }
std::string orogen_typekits::kdlTypelibTransportPlugin::getName() const
{ return "/orogen/kdl/TYPELIB"; }

ORO_TYPEKIT_PLUGIN(orogen_typekits::kdlTypelibTransportPlugin);

