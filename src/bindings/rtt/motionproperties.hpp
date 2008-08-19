/***************************************************************************
  tag: Peter Soetens  Mon Jan 19 14:11:21 CET 2004  MotionProperties.hpp

                        MotionProperties.hpp -  description
                           -------------------
    begin                : Mon January 19 2004
    copyright            : (C) 2004 Peter Soetens
    email                : peter.soetens@mech.kuleuven.ac.be

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

#ifndef MOTIONPROPERTIES_HPP
#define MOTIONPROPERTIES_HPP

#include "../../frames.hpp"
#include <rtt/Property.hpp>
#include <rtt/PropertyBag.hpp>
#include <rtt/MultiVector.hpp>
#include <rtt/TemplateTypeInfo.hpp>
#include <rtt/RealTimeToolkit.hpp>

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


    template <typename T>
    struct vectorTypeInfo : public TemplateTypeInfo<std::vector<T>,true>
    {
        vectorTypeInfo<T>():TemplateTypeInfo<std::vector<T>,true>("std::vector")
        {};
        virtual bool decomposeTypeImpl(const std::vector<T>& vec, PropertyBag& target)const
        {
            target.setType("std::vector");
            for(unsigned int i=0;i<vec.size();++i){
                std::ostringstream nr;
                nr<<i;
                PropertyBag item;
                decomposeProperty(vec[i],item);
                target.add(new Property<PropertyBag>("Element"+nr.str(),"Element "+nr.str(),item));
            }
            return true;
        }

        virtual bool composeTypeImpl(const PropertyBag& bag, std::vector<T>& vec)const
        {
            if( bag.getType() != std::string("std::vector"))
                return false;
            for(unsigned int i=0;i<vec.size();++i){
                std::ostringstream nr;
                nr<<i;
                PropertyBase* item = bag.find("Element"+nr.str());
                if(!item->ready())
                    return false;
                Property<T> item_prop(item->getName(),
                                      item->getDescription());
                item_prop.getTypeInfo()->composeType(item->getDataSource(),
                                                     item_prop.getDataSource());
                vec[i]=item_prop.value();
            }
            return true;
        }
    };

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
