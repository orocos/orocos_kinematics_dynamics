#include <gtest/gtest.h>
#include <ocl/DeploymentComponent.hpp>
#include <rtt/types/TypekitRepository.hpp>
#include <rtt/types/Types.hpp>
#include <rtt/marsh/Marshalling.hpp>
#include <kdl/frames.hpp>
#include <kdl/chain.hpp>
#include <kdl/jacobian.hpp>
#include <kdl/jntarray.hpp>
#include <rtt/os/main.h>

class KDLPluginTest : public testing::Test {

#define COMPNAME "Deployer"

protected:
    KDLPluginTest():
        depl(COMPNAME),
        chain_prop("chain",""),
        frame_prop("frame",""),
        jacobian_prop("jacobian",""),
        jntarray_prop("jntarray",""),
        joint_prop("joint",""),
        rotation_prop("rotation",""),
        segment_prop("segment",""),
        twist_prop("twist",""),
        vector_prop("vector",""),
        wrench_prop("wrench","")
    {}

    virtual void SetUp(){
         
    }
    virtual void TearDown(){
    }
    
    OCL::DeploymentComponent depl;
    KDL::Chain chain;
    KDL::Frame frame;
    KDL::Jacobian jac;
    KDL::JntArray jntarray;
    KDL::Joint joint;
    KDL::Rotation rotation;
    KDL::Segment segment;
    KDL::Twist twist;
    KDL::Vector vector;
    KDL::Wrench wrench;
    RTT::Property<KDL::Chain> chain_prop;
    RTT::Property<KDL::Frame> frame_prop;
    RTT::Property<KDL::Jacobian> jacobian_prop;
    RTT::Property<KDL::JntArray> jntarray_prop;
    RTT::Property<KDL::Joint> joint_prop;
    RTT::Property<KDL::Rotation> rotation_prop;
    RTT::Property<KDL::Segment> segment_prop;
    RTT::Property<KDL::Twist> twist_prop;
    RTT::Property<KDL::Vector> vector_prop;
    RTT::Property<KDL::Wrench> wrench_prop;
};

TEST_F(KDLPluginTest,loadTypekit)
{
    ASSERT_TRUE(depl.import("kdl_typekit"));
}

TEST_F(KDLPluginTest,getKDLTypes)
{
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Chain>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Frame>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Jacobian>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::JntArray>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Joint>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Rotation>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Segment>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Twist>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Vector>());
    EXPECT_FALSE(NULL==RTT::types::Types()->getTypeInfo<KDL::Wrench>());
}
//What do we want test:
//Create every type as property
//Write all types to file
//Read all types from file
//Write to other file
//Read again, are they the same??


TEST_F(KDLPluginTest,createProperties)
{
    EXPECT_TRUE(depl.addProperty(chain_prop));
    EXPECT_TRUE(depl.getProperty(chain_prop.getName())->ready());
    EXPECT_TRUE(depl.addProperty(frame_prop));
    EXPECT_TRUE(depl.addProperty(jacobian_prop));
    EXPECT_TRUE(depl.addProperty(jntarray_prop));
    EXPECT_TRUE(depl.addProperty(joint_prop));
    EXPECT_TRUE(depl.addProperty(rotation_prop));
    EXPECT_TRUE(depl.addProperty(segment_prop));
    EXPECT_TRUE(depl.addProperty(twist_prop));
    EXPECT_TRUE(depl.addProperty(vector_prop));
    EXPECT_TRUE(depl.addProperty(wrench_prop));

    
}

TEST_F(KDLPluginTest,writeProperties)
{
    boost::shared_ptr<RTT::Marshalling> marsh = depl.getProvider<RTT::Marshalling>("marshalling");
    EXPECT_TRUE(depl.addProperty(chain_prop));
    EXPECT_TRUE(depl.getProperty(chain_prop.getName())->ready());
    EXPECT_TRUE(depl.addProperty(frame_prop));
    EXPECT_TRUE(depl.addProperty(jacobian_prop));
    EXPECT_TRUE(depl.addProperty(jntarray_prop));
    EXPECT_TRUE(depl.addProperty(joint_prop));
    EXPECT_TRUE(depl.addProperty(rotation_prop));
    EXPECT_TRUE(depl.addProperty(segment_prop));
    EXPECT_TRUE(depl.addProperty(twist_prop));
    EXPECT_TRUE(depl.addProperty(vector_prop));
    EXPECT_TRUE(depl.addProperty(wrench_prop));
    
    EXPECT_TRUE(marsh->storeProperties("test/test.cpf"));
    EXPECT_TRUE(marsh->writeProperties("test/test1.cpf"));
    EXPECT_TRUE(marsh->updateFile("test/test1.cpf"));
    EXPECT_TRUE(marsh->readProperties("test/test.cpf"));
}

int ORO_main(int argc, char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

