/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/StructTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_VectorTypeInfo :
	public RTT::types::StructTypeInfo< ::KDL::Vector >
    {
        KDL_VectorTypeInfo()
            : RTT::types::StructTypeInfo< ::KDL::Vector >("Vector") {}
    };

    RTT::types::TypeInfo* KDL_Vector_TypeInfo()
    { return new KDL_VectorTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< ::KDL::Vector >;
template class RTT::InputPort< ::KDL::Vector >;
template class RTT::Property< ::KDL::Vector >;
template class RTT::Attribute< ::KDL::Vector >;

template class RTT::internal::DataSource< ::KDL::Vector >;
template class RTT::internal::ValueDataSource< ::KDL::Vector >;
template class RTT::internal::ConstantDataSource< ::KDL::Vector >;
template class RTT::internal::AssignableDataSource< ::KDL::Vector >;
template class RTT::internal::ReferenceDataSource< ::KDL::Vector >;



