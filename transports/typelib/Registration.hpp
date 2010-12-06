/* Generated from orogen/lib/orogen/templates/typekit/typelib/Registration.hpp */

#ifndef KDL_TYPELIB_REGISTRATION_HPP
#define KDL_TYPELIB_REGISTRATION_HPP

#include "transports/typelib/TypelibMarshallerBase.hpp"

namespace orogen_typekits {
    
    /** Creates and returns a TypeInfo object for ::KDL::Frame */
    orogen_transports::TypelibMarshallerBase* KDL_Frame_TypelibMarshaller(Typelib::Registry const& registry);
    
    /** Creates and returns a TypeInfo object for ::KDL::Rotation */
    orogen_transports::TypelibMarshallerBase* KDL_Rotation_TypelibMarshaller(Typelib::Registry const& registry);
    
    /** Creates and returns a TypeInfo object for ::KDL::Twist */
    orogen_transports::TypelibMarshallerBase* KDL_Twist_TypelibMarshaller(Typelib::Registry const& registry);
    
    /** Creates and returns a TypeInfo object for ::KDL::Vector */
    orogen_transports::TypelibMarshallerBase* KDL_Vector_TypelibMarshaller(Typelib::Registry const& registry);
    
    /** Creates and returns a TypeInfo object for ::KDL::Wrench */
    orogen_transports::TypelibMarshallerBase* KDL_Wrench_TypelibMarshaller(Typelib::Registry const& registry);
    
}

#endif


