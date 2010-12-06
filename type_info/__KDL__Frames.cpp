#include "Types.hpp"
#include <rtt/types/SequenceTypeInfo.hpp>

namespace orogen_typekits {
    struct KDL_FramesTypeInfo :
	public RTT::types::SequenceTypeInfo< std::vector<KDL::Frame> >
    {
        KDL_FramesTypeInfo()
            : RTT::types::SequenceTypeInfo< std::vector<KDL::Frame> >("Frames") {}
    };

    RTT::types::TypeInfo* KDL_Frames_TypeInfo()
    { return new KDL_FramesTypeInfo(); }
}

/* Generated from orogen/lib/orogen/templates/typekit/TemplateInstanciation.cpp */

#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <rtt/internal/DataSource.hpp>

template class RTT::OutputPort< std::vector<KDL::Frame> >;
template class RTT::InputPort< std::vector<KDL::Frame> >;
template class RTT::Property< std::vector<KDL::Frame> >;
template class RTT::Attribute< std::vector<KDL::Frame> >;

template class RTT::internal::DataSource< std::vector<KDL::Frame> >;
template class RTT::internal::ValueDataSource< std::vector<KDL::Frame> >;
template class RTT::internal::ConstantDataSource< std::vector<KDL::Frame> >;
template class RTT::internal::AssignableDataSource< std::vector<KDL::Frame> >;
template class RTT::internal::ReferenceDataSource< std::vector<KDL::Frame> >;



