/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/StructTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_TwistTypeInfo :
	public RTT::types::StructTypeInfo< ::KDL::Twist >
    {
        KDL_TwistTypeInfo()
            : RTT::types::StructTypeInfo< ::KDL::Twist >("Twist") {}
    };

    RTT::types::TypeInfo* KDL_Twist_TypeInfo()
    { return new KDL_TwistTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< ::KDL::Twist >;
template class RTT::InputPort< ::KDL::Twist >;
template class RTT::Property< ::KDL::Twist >;
template class RTT::Attribute< ::KDL::Twist >;

template class RTT::internal::DataSource< ::KDL::Twist >;
template class RTT::internal::ValueDataSource< ::KDL::Twist >;
template class RTT::internal::ConstantDataSource< ::KDL::Twist >;
template class RTT::internal::AssignableDataSource< ::KDL::Twist >;
template class RTT::internal::ReferenceDataSource< ::KDL::Twist >;



