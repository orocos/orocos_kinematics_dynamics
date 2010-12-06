/* Generated from orogen/lib/orogen/templates/typekit/corba/Convertions.hpp */

#ifndef OROCOS_KDL_CORBA_CONVERTIONS_HPP
#define OROCOS_KDL_CORBA_CONVERTIONS_HPP

#include "Types.hpp"
#include "transports/corba/kdlTypesC.h"
#include <boost/cstdint.hpp>

namespace orogen_typekits {
    
    bool toCORBA( orogen::KDL::Corba::Frame& corba, ::KDL::Frame const& value );
    bool fromCORBA( ::KDL::Frame& value, orogen::KDL::Corba::Frame const& corba );
    
    bool toCORBA( orogen::KDL::Corba::Rotation& corba, ::KDL::Rotation const& value );
    bool fromCORBA( ::KDL::Rotation& value, orogen::KDL::Corba::Rotation const& corba );
    
    bool toCORBA( orogen::KDL::Corba::Twist& corba, ::KDL::Twist const& value );
    bool fromCORBA( ::KDL::Twist& value, orogen::KDL::Corba::Twist const& corba );
    
    bool toCORBA( orogen::KDL::Corba::Vector& corba, ::KDL::Vector const& value );
    bool fromCORBA( ::KDL::Vector& value, orogen::KDL::Corba::Vector const& corba );
    
    bool toCORBA( orogen::KDL::Corba::Wrench& corba, ::KDL::Wrench const& value );
    bool fromCORBA( ::KDL::Wrench& value, orogen::KDL::Corba::Wrench const& corba );
    
    bool toCORBA( CORBA::Double* corba, double const* value, int length );
    bool fromCORBA( double* value, int length, CORBA::Double const* corba );
    
    
}

#endif

