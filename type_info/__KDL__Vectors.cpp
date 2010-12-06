/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/SequenceTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_VectorsTypeInfo :
	public RTT::types::SequenceTypeInfo< std::vector<KDL::Vector> >
    {
        KDL_VectorsTypeInfo()
            : RTT::types::SequenceTypeInfo< std::vector<KDL::Vector> >("Vectors") {}
    };

    RTT::types::TypeInfo* KDL_Vectors_TypeInfo()
    { return new KDL_VectorsTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< std::vector<KDL::Vector> >;
template class RTT::InputPort< std::vector<KDL::Vector> >;
template class RTT::Property< std::vector<KDL::Vector> >;
template class RTT::Attribute< std::vector<KDL::Vector> >;

template class RTT::internal::DataSource< std::vector<KDL::Vector> >;
template class RTT::internal::ValueDataSource< std::vector<KDL::Vector> >;
template class RTT::internal::ConstantDataSource< std::vector<KDL::Vector> >;
template class RTT::internal::AssignableDataSource< std::vector<KDL::Vector> >;
template class RTT::internal::ReferenceDataSource< std::vector<KDL::Vector> >;



