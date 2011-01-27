/* Generated from orogen/lib/orogen/templates/typekit/Types.hpp */

#ifndef KDL_TYPES_HPP
#define KDL_TYPES_HPP

#include <kdl/frames.hpp>
#include <kdl/chain.hpp>
#include <kdl/jacobian.hpp>
#include <kdl/segment.hpp>
#include <kdl/jntarray.hpp>



// This is a hack. We include it unconditionally as it may be required by some
// typekits *and* it is a standard header. Ideally, we would actually check if
// some of the types need std::vector.
#include <vector>
#include <boost/cstdint.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/array.hpp>


#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Frame >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Frame >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Frame >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Frame >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Frame >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Frame >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Frame >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Frame >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Frame >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Frame& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            a & make_nvp("p", b.p);
a & make_nvp("M", b.M);
        }
    }
}


#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Rotation >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Rotation >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Rotation >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Rotation >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Rotation >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Rotation >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Rotation >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Rotation >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Rotation >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Rotation& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            a & make_nvp("X_x", b.data[0]);
            a & make_nvp("X_y", b.data[3]);
            a & make_nvp("X_z", b.data[6]);
            a & make_nvp("Y_x", b.data[1]);
            a & make_nvp("Y_y", b.data[4]);
            a & make_nvp("Y_z", b.data[7]);
            a & make_nvp("Z_x", b.data[2]);
            a & make_nvp("Z_y", b.data[5]);
            a & make_nvp("Z_z", b.data[8]);
        }
    }
}

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Twist >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Twist >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Twist >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Twist >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Twist >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Twist >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Twist >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Twist >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Twist >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Twist& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            a & make_nvp("vel", b.vel);
a & make_nvp("rot", b.rot);
        }
    }
}



#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Vector >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Vector >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Vector >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Vector >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Vector >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Vector >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Vector >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Vector >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Vector >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Vector& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            a & make_nvp("X", b.data[0]);
            a & make_nvp("Y", b.data[1]);
            a & make_nvp("Z", b.data[2]);
        }
    }
}


#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Wrench >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Wrench >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Wrench >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Wrench >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Wrench >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Wrench >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Wrench >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Wrench >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Wrench >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Wrench& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            a & make_nvp("force", b.force);
            a & make_nvp("torque", b.torque);
        }
    }
}

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Chain >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Chain >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Chain >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Chain >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Chain >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Chain >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Chain >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Chain >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Chain >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Chain& b, unsigned int version)
        {}
    }
}

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Joint >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Joint >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Joint >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Joint >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Joint >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Joint >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Joint >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Joint >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Joint >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Joint& b, unsigned int version)
        {}
    }
}

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Segment >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Segment >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Segment >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Segment >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Segment >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Segment >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Segment >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Segment >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Segment >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Segment& b, unsigned int version)
        {}
    }
}
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::Jacobian >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::Jacobian >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::Jacobian >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::Jacobian >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::Jacobian >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::Jacobian >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::Jacobian >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::Jacobian >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::Jacobian >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::Jacobian& b, unsigned int version)
        {}
    }
}

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::KDL::JntArray >;
    extern template class RTT::internal::AssignableDataSource< ::KDL::JntArray >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::KDL::JntArray >;
    extern template class RTT::internal::ConstantDataSource< ::KDL::JntArray >;
    extern template class RTT::internal::ReferenceDataSource< ::KDL::JntArray >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< ::KDL::JntArray >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< ::KDL::JntArray >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::KDL::JntArray >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::KDL::JntArray >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, ::KDL::JntArray& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            for(int i=0; i<b.data.size(); i++)
            {
              a & make_nvp("data", b.data[i]);
            }
        }
    }
}

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< std::vector<KDL::Rotation> >;
    extern template class RTT::internal::AssignableDataSource< std::vector<KDL::Rotation> >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< std::vector<KDL::Rotation> >;
    extern template class RTT::internal::ConstantDataSource< std::vector<KDL::Rotation> >;
    extern template class RTT::internal::ReferenceDataSource< std::vector<KDL::Rotation> >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< std::vector<KDL::Rotation> >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< std::vector<KDL::Rotation> >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< std::vector<KDL::Rotation> >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< std::vector<KDL::Rotation> >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, std::vector<KDL::Rotation>& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            for(unsigned int i=0; i < b.size(); i++){
              boost::serialization::serialize(a, b[i], version);
            }
        }
    }
}
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< std::vector<KDL::Vector> >;
    extern template class RTT::internal::AssignableDataSource< std::vector<KDL::Vector> >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< std::vector<KDL::Vector> >;
    extern template class RTT::internal::ConstantDataSource< std::vector<KDL::Vector> >;
    extern template class RTT::internal::ReferenceDataSource< std::vector<KDL::Vector> >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< std::vector<KDL::Vector> >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< std::vector<KDL::Vector> >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< std::vector<KDL::Vector> >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< std::vector<KDL::Vector> >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, std::vector<KDL::Vector>& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            for(unsigned int i=0; i < b.size(); i++){
              boost::serialization::serialize(a, b[i], version);

            }
        }
    }
}
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< std::vector<KDL::Frame> >;
    extern template class RTT::internal::AssignableDataSource< std::vector<KDL::Frame> >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< std::vector<KDL::Frame> >;
    extern template class RTT::internal::ConstantDataSource< std::vector<KDL::Frame> >;
    extern template class RTT::internal::ReferenceDataSource< std::vector<KDL::Frame> >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< std::vector<KDL::Frame> >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< std::vector<KDL::Frame> >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< std::vector<KDL::Frame> >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< std::vector<KDL::Frame> >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, std::vector<KDL::Frame>& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            for(unsigned int i=0; i < b.size(); i++){
              boost::serialization::serialize(a, b[i], version);

            }
        }
    }
}
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< std::vector<KDL::Twist> >;
    extern template class RTT::internal::AssignableDataSource< std::vector<KDL::Twist> >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< std::vector<KDL::Twist> >;
    extern template class RTT::internal::ConstantDataSource< std::vector<KDL::Twist> >;
    extern template class RTT::internal::ReferenceDataSource< std::vector<KDL::Twist> >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< std::vector<KDL::Twist> >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< std::vector<KDL::Twist> >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< std::vector<KDL::Twist> >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< std::vector<KDL::Twist> >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, std::vector<KDL::Twist>& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            for(unsigned int i=0; i < b.size(); i++){
              boost::serialization::serialize(a, b[i], version);

            }
        }
    }
}
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< std::vector<KDL::Wrench> >;
    extern template class RTT::internal::AssignableDataSource< std::vector<KDL::Wrench> >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< std::vector<KDL::Wrench> >;
    extern template class RTT::internal::ConstantDataSource< std::vector<KDL::Wrench> >;
    extern template class RTT::internal::ReferenceDataSource< std::vector<KDL::Wrench> >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< std::vector<KDL::Wrench> >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< std::vector<KDL::Wrench> >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< std::vector<KDL::Wrench> >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< std::vector<KDL::Wrench> >;
#endif


namespace boost
{
    namespace serialization
    {
        template<typename Archive>
        void serialize(Archive& a, std::vector<KDL::Wrench>& b, unsigned int version)
        {
            using boost::serialization::make_nvp;
            for(unsigned int i=0; i < b.size(); i++){
              boost::serialization::serialize(a, b[i], version);

            }
        }
    }
}
#endif

