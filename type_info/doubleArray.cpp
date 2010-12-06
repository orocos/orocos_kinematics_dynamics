/* Generated from orogen/lib/orogen/templates/typekit/type_info/ArrayInfo.cpp */

#include "Types.hpp"
#include <rtt/internal/carray.hpp>
#include <rtt/types/CArrayTypeInfo.hpp>

namespace orogen_typekits {
    struct doubleArrayTypeInfo :
	public RTT::types::CArrayTypeInfo< RTT::internal::carray< double > >
    {
        doubleArrayTypeInfo()
            : RTT::types::CArrayTypeInfo< RTT::internal::carray< double > >("double[]") {}
    };

    RTT::types::TypeInfo* double_ArrayTypeInfo()
    { return new doubleArrayTypeInfo(); }
}


