/* Generated from orogen/lib/orogen/templates/typekit/corba/Convertions.cpp */

#include "Convertions.hpp"
#include <memory>






bool orogen_typekits::toCORBA( orogen::KDL::Corba::Frame& corba, ::KDL::Frame const& value )
{
    if (!toCORBA(corba.p, value.p)) return false;
    if (!toCORBA(corba.M, value.M)) return false;

    return true;
}
bool orogen_typekits::fromCORBA( ::KDL::Frame& value, orogen::KDL::Corba::Frame const& corba )
{
    if (!fromCORBA(value.p, corba.p)) return false;
    if (!fromCORBA(value.M, corba.M)) return false;

    return true;
}

bool orogen_typekits::toCORBA( orogen::KDL::Corba::Rotation& corba, ::KDL::Rotation const& value )
{
    if (!toCORBA(corba.data, reinterpret_cast< double const*>(value.data), 9)) return false;

    return true;
}
bool orogen_typekits::fromCORBA( ::KDL::Rotation& value, orogen::KDL::Corba::Rotation const& corba )
{
    if (!fromCORBA(reinterpret_cast< double*>(value.data), 9, corba.data)) return false;

    return true;
}

bool orogen_typekits::toCORBA( orogen::KDL::Corba::Twist& corba, ::KDL::Twist const& value )
{
    if (!toCORBA(corba.vel, value.vel)) return false;
    if (!toCORBA(corba.rot, value.rot)) return false;

    return true;
}
bool orogen_typekits::fromCORBA( ::KDL::Twist& value, orogen::KDL::Corba::Twist const& corba )
{
    if (!fromCORBA(value.vel, corba.vel)) return false;
    if (!fromCORBA(value.rot, corba.rot)) return false;

    return true;
}

bool orogen_typekits::toCORBA( orogen::KDL::Corba::Vector& corba, ::KDL::Vector const& value )
{
    if (!toCORBA(corba.data, reinterpret_cast< double const*>(value.data), 3)) return false;

    return true;
}
bool orogen_typekits::fromCORBA( ::KDL::Vector& value, orogen::KDL::Corba::Vector const& corba )
{
    if (!fromCORBA(reinterpret_cast< double*>(value.data), 3, corba.data)) return false;

    return true;
}

bool orogen_typekits::toCORBA( orogen::KDL::Corba::Wrench& corba, ::KDL::Wrench const& value )
{
    if (!toCORBA(corba.force, value.force)) return false;
    if (!toCORBA(corba.torque, value.torque)) return false;

    return true;
}
bool orogen_typekits::fromCORBA( ::KDL::Wrench& value, orogen::KDL::Corba::Wrench const& corba )
{
    if (!fromCORBA(value.force, corba.force)) return false;
    if (!fromCORBA(value.torque, corba.torque)) return false;

    return true;
}


bool orogen_typekits::toCORBA( CORBA::Double* corba, double const* value, int length )
{
    for(int i0 = 0; i0 < length; ++i0)
    {
      corba[i0] = value[i0];
    }

    return true;
}
bool orogen_typekits::fromCORBA( double* value, int length, CORBA::Double const* corba )
{
    for(int i0 = 0; i0 < length; ++i0)
    {
      value[i0] = corba[i0];
    }

    return true;
}
