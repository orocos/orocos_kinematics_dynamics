/* Generated from orogen/lib/orogen/templates/typekit/typelib/TransportPlugin.hpp */

#ifndef OROCOS_KDL_TYPELIB_PLUGIN_HPP
#define OROCOS_KDL_TYPELIB_PLUGIN_HPP

#include <rtt/types/TransportPlugin.hpp>

namespace Typelib
{
    // Forward declaration for the plugin
    class Registry;
}

namespace orogen_typekits {
    class kdlTypelibTransportPlugin
        : public RTT::types::TransportPlugin
    {
        Typelib::Registry* m_registry;

    public:
        kdlTypelibTransportPlugin();
        virtual bool registerTransport(std::string type_name, RTT::types::TypeInfo* ti);
        virtual std::string getTransportName() const;
        virtual std::string getTypekitName() const;
        virtual std::string getName() const;
    };

    extern kdlTypelibTransportPlugin kdlTypelibTransport;
}

#endif

