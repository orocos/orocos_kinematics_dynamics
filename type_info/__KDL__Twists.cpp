/* Generated from orogen/templates/typekit/type_info/Info.cpp */

#include "Types.hpp"
#include <rtt/types/SequenceTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_TwistsTypeInfo :
	public RTT::types::SequenceTypeInfo< std::vector<KDL::Twist> >
    {
        KDL_TwistsTypeInfo()
            : RTT::types::SequenceTypeInfo< std::vector<KDL::Twist> >("Twists") {}
    };

    RTT::types::TypeInfo* KDL_Twists_TypeInfo()
    { return new KDL_TwistsTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< std::vector<KDL::Twist> >;
template class RTT::InputPort< std::vector<KDL::Twist> >;
template class RTT::Property< std::vector<KDL::Twist> >;
template class RTT::Attribute< std::vector<KDL::Twist> >;

template class RTT::internal::DataSource< std::vector<KDL::Twist> >;
template class RTT::internal::ValueDataSource< std::vector<KDL::Twist> >;
template class RTT::internal::ConstantDataSource< std::vector<KDL::Twist> >;
template class RTT::internal::AssignableDataSource< std::vector<KDL::Twist> >;
template class RTT::internal::ReferenceDataSource< std::vector<KDL::Twist> >;



