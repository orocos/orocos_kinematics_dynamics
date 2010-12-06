/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/StructTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_FrameTypeInfo :
	public RTT::types::StructTypeInfo< ::KDL::Frame >
    {
        KDL_FrameTypeInfo()
            : RTT::types::StructTypeInfo< ::KDL::Frame >("Frame") {}
    };

    RTT::types::TypeInfo* KDL_Frame_TypeInfo()
    { return new KDL_FrameTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< ::KDL::Frame >;
template class RTT::InputPort< ::KDL::Frame >;
template class RTT::Property< ::KDL::Frame >;
template class RTT::Attribute< ::KDL::Frame >;

template class RTT::internal::DataSource< ::KDL::Frame >;
template class RTT::internal::ValueDataSource< ::KDL::Frame >;
template class RTT::internal::ConstantDataSource< ::KDL::Frame >;
template class RTT::internal::AssignableDataSource< ::KDL::Frame >;
template class RTT::internal::ReferenceDataSource< ::KDL::Frame >;



