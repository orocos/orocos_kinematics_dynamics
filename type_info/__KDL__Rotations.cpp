/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/SequenceTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_RotationsTypeInfo :
	public RTT::types::SequenceTypeInfo< std::vector<KDL::Rotation> >
    {
        KDL_RotationsTypeInfo()
            : RTT::types::SequenceTypeInfo< std::vector<KDL::Rotation> >("Rotations") {}
    };

    RTT::types::TypeInfo* KDL_Rotations_TypeInfo()
    { return new KDL_RotationsTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< std::vector<KDL::Rotation> >;
template class RTT::InputPort< std::vector<KDL::Rotation> >;
template class RTT::Property< std::vector<KDL::Rotation> >;
template class RTT::Attribute< std::vector<KDL::Rotation> >;

template class RTT::internal::DataSource< std::vector<KDL::Rotation> >;
template class RTT::internal::ValueDataSource< std::vector<KDL::Rotation> >;
template class RTT::internal::ConstantDataSource< std::vector<KDL::Rotation> >;
template class RTT::internal::AssignableDataSource< std::vector<KDL::Rotation> >;
template class RTT::internal::ReferenceDataSource< std::vector<KDL::Rotation> >;



