/***************************************************************************
 Copyright (c) 2009 S Roderick <xxxkiwi DOT xxxnet AT macxxx DOT comxxx>
                               (remove the x's above)

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
 ***************************************************************************/

#ifndef ORO_KDL_CORBATOOLKIT_HPP
#define ORO_KDL_CORBATOOLKIT_HPP 1

#include <string>
#include <rtt/TransportPlugin.hpp>
#include <rtt/Plugin.hpp>

namespace KDL
{
    namespace Corba
    {
    class CorbaKDLPlugin : public RTT::TransportPlugin
        {
        public:
            bool registerTransport(std::string name, RTT::TypeInfo* ti);

            std::string getTransportName() const;

            std::string getName() const;

        };

        extern CorbaKDLPlugin   corbaKDLPlugin;

    }

}

#endif
