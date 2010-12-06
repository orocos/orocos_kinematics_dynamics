/* Generated from orogen/lib/orogen/templates/typekit/corba/Registration.hpp */

#ifndef KDL_CORBA_REGISTRATION_HPP
#define KDL_CORBA_REGISTRATION_HPP

#include <rtt/transports/corba/CorbaTypeTransporter.hpp>

namespace orogen_typekits {
    
    RTT::corba::CorbaTypeTransporter*  KDL_Frame_CorbaTransport();
    
    RTT::corba::CorbaTypeTransporter*  KDL_Rotation_CorbaTransport();
    
    RTT::corba::CorbaTypeTransporter*  KDL_Twist_CorbaTransport();
    
    RTT::corba::CorbaTypeTransporter*  KDL_Vector_CorbaTransport();
    
    RTT::corba::CorbaTypeTransporter*  KDL_Wrench_CorbaTransport();
}

#endif


