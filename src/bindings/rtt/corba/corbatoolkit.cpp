// Copyright  (C)  2008  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

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

#include "../toolkit.hpp"
#include <rtt/Types.hpp>
#include <rtt/corba/CorbaTemplateProtocol.hpp>
#include <rtt/os/StartStopManager.hpp>
#include "CorbaKDLConversion.hpp"

namespace KDL
{
    namespace Corba
    {
        using namespace RTT;
        using namespace RTT::Corba;
        using namespace RTT::detail;

        struct CorbaKDLRegistrator
            : public TransportRegistrator
        {
            bool registerTransport(std::string name, TypeInfo* ti)
            {
                assert( name == ti->getTypeName() );
                if ( name == "vector" )
                    return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new CorbaTemplateProtocol< KDL::Vector >() );
                if ( name == "rotation" )
                    return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new CorbaTemplateProtocol< KDL::Rotation >() );
                if ( name == "frame" )
                    return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new CorbaTemplateProtocol< KDL::Frame >() );
                if ( name == "wrench" )
                    return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new CorbaTemplateProtocol< KDL::Wrench >() );
                if ( name == "twist" )
                    return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new CorbaTemplateProtocol< KDL::Twist >() );
                return false;
            }

            std::string getTransportName() const {
                return "CORBA";
            }

        } CorbaKDLRegistrator;

    };
}

namespace RTT
{
    class TaskContext;
}
using namespace RTT;
using namespace KDL;
extern "C" {
bool loadRTTPlugin(RTT::TaskContext* )
{
    log(Info) << "Loading CorbaKDL in RTT type system." <<endlog();
    TypeInfoRepository::Instance()->registerTransport( &KDL::Corba::CorbaKDLRegistrator );
    return true;
}

std::string getRTTPluginName()
{
    return "CorbaKDL";
}
}
