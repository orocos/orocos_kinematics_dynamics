/***************************************************************************
  tag: Peter Soetens  Mon Jun 26 13:25:57 CEST 2006  GeometryToolkit.hpp

                        GeometryToolkit.hpp -  description
                           -------------------
    begin                : Mon June 26 2006
    copyright            : (C) 2006 Peter Soetens
    email                : peter.soetens@fmtc.be

 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/

/**
 * @defgroup KDLTK KDL-toolkit for Orocos RTT
 * @brief All classes related to the KDL-toolkit for RTT, to
 * use KDL primitives as properties and in script files of the
 * <a href="http://www.orocos.org/">Orocos</a> Real-Time Toolkit framework.
 *
 */

#ifndef ORO_KDL_TOOLKIT_HPP
#define ORO_KDL_TOOLKIT_HPP

#include <rtt/Toolkit.hpp>
#include "../../frames.hpp"

namespace KDL
{

    /**
     * This interface defines the types of the kdl.
     * @ingroup KDLTK
     */
    class KDLToolkitPlugin
       : public RTT::ToolkitPlugin
    {
    public:
        virtual std::string getName();

        virtual bool loadTypes();
        virtual bool loadConstructors();
        virtual bool loadOperators();
    };

    /**
     * The single global instance of the KDL Toolkit.
     */
    extern KDLToolkitPlugin KDLToolkit;
}

#endif
