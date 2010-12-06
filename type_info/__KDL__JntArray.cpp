/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/StructTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_JntArrayTypeInfo :
	public RTT::types::StructTypeInfo< ::KDL::JntArray >
    {
        KDL_JntArrayTypeInfo()
            : RTT::types::StructTypeInfo< ::KDL::JntArray >("JntArray") {}
    };

    RTT::types::TypeInfo* KDL_JntArray_TypeInfo()
    { return new KDL_JntArrayTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< ::KDL::JntArray >;
template class RTT::InputPort< ::KDL::JntArray >;
template class RTT::Property< ::KDL::JntArray >;
template class RTT::Attribute< ::KDL::JntArray >;

template class RTT::internal::DataSource< ::KDL::JntArray >;
template class RTT::internal::ValueDataSource< ::KDL::JntArray >;
template class RTT::internal::ConstantDataSource< ::KDL::JntArray >;
template class RTT::internal::AssignableDataSource< ::KDL::JntArray >;
template class RTT::internal::ReferenceDataSource< ::KDL::JntArray >;



