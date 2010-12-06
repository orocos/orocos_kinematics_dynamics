/* Generated from orogen/lib/orogen/templates/typekit/Plugin.hpp */

#ifndef KDL_TYPEKIT_HPP
#define KDL_TYPEKIT_HPP

#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/types/TemplateConstructor.hpp>
#include <rtt/internal/mystd.hpp>
#include <rtt/types/Operators.hpp>
#include <rtt/types/OperatorTypes.hpp>
#include "types/kdl/orocos_toolchain/frames.hpp"
using namespace KDL;

namespace Typelib {
    class Registry;
}

namespace orogen_typekits {
    class kdlTypekitPlugin
        : public RTT::types::TypekitPlugin
    {
        Typelib::Registry* m_registry;

    public:
        kdlTypekitPlugin();
        ~kdlTypekitPlugin();
        bool loadTypes();
        bool loadOperators();
        bool loadConstructors();
        std::string getName();
    };

    extern kdlTypekitPlugin kdlTypekit;
}

#endif


