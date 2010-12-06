/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/StructTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_WrenchTypeInfo :
	public RTT::types::StructTypeInfo< ::KDL::Wrench >
    {
        KDL_WrenchTypeInfo()
            : RTT::types::StructTypeInfo< ::KDL::Wrench >("Wrench") {}
    };

    RTT::types::TypeInfo* KDL_Wrench_TypeInfo()
    { return new KDL_WrenchTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< ::KDL::Wrench >;
template class RTT::InputPort< ::KDL::Wrench >;
template class RTT::Property< ::KDL::Wrench >;
template class RTT::Attribute< ::KDL::Wrench >;

template class RTT::internal::DataSource< ::KDL::Wrench >;
template class RTT::internal::ValueDataSource< ::KDL::Wrench >;
template class RTT::internal::ConstantDataSource< ::KDL::Wrench >;
template class RTT::internal::AssignableDataSource< ::KDL::Wrench >;
template class RTT::internal::ReferenceDataSource< ::KDL::Wrench >;



