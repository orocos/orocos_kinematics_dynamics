/******************************************************************************
*                    This file is part of the KDL project                     *
*                                                                             *
*                         (C) 2004 Peter Soetens                              *
*                       peter.soetens@mech.kuleuven.be                        *
*                    Department of Mechanical Engineering,                    *
*                   Katholieke Universiteit Leuven, Belgium.                  *
*                                                                             *
*       You may redistribute this software and/or modify it under either the  *
*       terms of the GNU Lesser General Public License version 2.1 (LGPLv2.1  *
*       <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>) or (at your *
*       discretion) of the Modified BSD License:                              *
*       Redistribution and use in source and binary forms, with or without    *
*       modification, are permitted provided that the following conditions    *
*       are met:                                                              *
*       1. Redistributions of source code must retain the above copyright     *
*       notice, this list of conditions and the following disclaimer.         *
*       2. Redistributions in binary form must reproduce the above copyright  *
*       notice, this list of conditions and the following disclaimer in the   *
*       documentation and/or other materials provided with the distribution.  *
*       3. The name of the author may not be used to endorse or promote       *
*       products derived from this software without specific prior written    *
*       permission.                                                           *
*       THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  *
*       IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED        *
*       WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    *
*       ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,*
*       INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    *
*       (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS       *
*       OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) *
*       HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,   *
*       STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING *
*       IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE    *
*       POSSIBILITY OF SUCH DAMAGE.                                           *
*                                                                             *
*******************************************************************************/
/* @Description:
 * @brief KDL typekit for Orocos RTT
 * @Author: Peter Soetens
 */

#ifndef MOTIONPROPERTIES_HPP
#define MOTIONPROPERTIES_HPP

#include <kdl/frames.hpp>
#include <rtt/Property.hpp>
#include <rtt/PropertyBag.hpp>
#include <rtt/extras/MultiVector.hpp>
#include <rtt/types/TemplateTypeInfo.hpp>
#include <rtt/typekit/RealTimeTypekit.hpp>

#include <sstream>

namespace RTT
{
    using namespace KDL;
//    /**
//     * Additional functionality for handling a Property<JntArray>
//     */
//    void decomposeProperty(const JntArray &v, PropertyBag& targetbag );
//
//    /**
//     * Aim of this kind of functions : given a Property<PropertyBag> with one of the
//     * properties being a bag containing a JntArray, fill the given non primitive Property<T>.
//     */
//    bool composeProperty(const PropertyBag& bag, JntArray &v);
//

    /**
     * Additional functionality for handling a Property<Vector>
     */
    void decomposeProperty(const Vector &v, PropertyBag& targetbag );

    /**
     * Aim of this kind of functions : given a Property<PropertyBag> with one of the
     * properties being a bag containing a Vector, fill the given non primitive Property<T>.
     */
    bool composeProperty(const PropertyBag& bag, Vector &v);


    /**
     * Additional functionality for handling a Property<Rotation>
     */
    void decomposeProperty(const Rotation &b, PropertyBag& targetbag);

    /**
     * Aim of this kind of functions : given a Property<PropertyBag> with one of the
     * properties being a bag containing a Rotation, fill the given non primitive Property<T>.
     */
    bool composeProperty(const PropertyBag& bag, Rotation &r);

    /**
     *
     *    ORO_Geometry::Twist
     *
     */

    /**
     * Additional functionality for handling a Property<Twist>
     */
    void decomposeProperty(const Twist &t, PropertyBag& targetbag);

    /**
     * Aim of this kind of functions : given a Property<PropertyBag> with one of the
     * properties being a bag containing a Twist, fill the given non primitive Property<T>.
     */
    bool composeProperty(const PropertyBag& bag, Twist &t);

    /**
     *
     *    ORO_Geometry::Wrench
     *
     */

    /**
     * Additional functionality for handling a Property<Wrench>
     */
    void decomposeProperty( const Wrench &b, PropertyBag& targetbag);

    /**
     * Aim of this kind of functions : given a Property<PropertyBag> with one of the
     * properties being a bag containing a Wrench, fill the given non primitive Property<T>.
     */
    bool composeProperty(const PropertyBag& bag, Wrench &w);

    /**
     *
     *    ORO_Geometry::Frame
     *
     */

    /**
     * Additional functionality for handling a Property<Frame>
     */
    void decomposeProperty(const Frame &f, PropertyBag& target);

    /**
     * Aim of this kind of functions : given a Property<PropertyBag> with one of the
     * properties being a bag containing a Frame, fill the given non primitive Property<T>.
     */
    bool composeProperty(const PropertyBag& bag, Frame &f);
}

namespace RTT
{
    extern template class Property<KDL::Frame>;
    //extern template class Property<KDL::JntArray>;
    extern template class Property<KDL::Wrench>;
    extern template class Property<KDL::Twist>;
    extern template class Property<KDL::Rotation>;
    extern template class Property<KDL::Vector>;
}

#endif
