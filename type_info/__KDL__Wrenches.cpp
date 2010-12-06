/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/SequenceTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_WrenchesTypeInfo :
	public RTT::types::SequenceTypeInfo< std::vector<KDL::Wrench> >
    {
        KDL_WrenchesTypeInfo()
            : RTT::types::SequenceTypeInfo< std::vector<KDL::Wrench> >("Wrenches") {}
    };

    RTT::types::TypeInfo* KDL_Wrenches_TypeInfo()
    { return new KDL_WrenchesTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< std::vector<KDL::Wrench> >;
template class RTT::InputPort< std::vector<KDL::Wrench> >;
template class RTT::Property< std::vector<KDL::Wrench> >;
template class RTT::Attribute< std::vector<KDL::Wrench> >;

template class RTT::internal::DataSource< std::vector<KDL::Wrench> >;
template class RTT::internal::ValueDataSource< std::vector<KDL::Wrench> >;
template class RTT::internal::ConstantDataSource< std::vector<KDL::Wrench> >;
template class RTT::internal::AssignableDataSource< std::vector<KDL::Wrench> >;
template class RTT::internal::ReferenceDataSource< std::vector<KDL::Wrench> >;



