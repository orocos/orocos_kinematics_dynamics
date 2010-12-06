/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/StructTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_RotationTypeInfo :
	public RTT::types::StructTypeInfo< ::KDL::Rotation >
    {
        KDL_RotationTypeInfo()
            : RTT::types::StructTypeInfo< ::KDL::Rotation >("Rotation") {}
    };

    RTT::types::TypeInfo* KDL_Rotation_TypeInfo()
    { return new KDL_RotationTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< ::KDL::Rotation >;
template class RTT::InputPort< ::KDL::Rotation >;
template class RTT::Property< ::KDL::Rotation >;
template class RTT::Attribute< ::KDL::Rotation >;

template class RTT::internal::DataSource< ::KDL::Rotation >;
template class RTT::internal::ValueDataSource< ::KDL::Rotation >;
template class RTT::internal::ConstantDataSource< ::KDL::Rotation >;
template class RTT::internal::AssignableDataSource< ::KDL::Rotation >;
template class RTT::internal::ReferenceDataSource< ::KDL::Rotation >;



