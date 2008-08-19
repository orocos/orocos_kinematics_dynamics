#include "kinfamtest.hpp"
#include <frames_io.hpp>
#include <kinfam_io.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION( KinFamTest );

using namespace KDL;
using namespace std;

void KinFamTest::setUp()
{
}

void  KinFamTest::tearDown()
{
}

void KinFamTest::JointTest()
{
    double q;
    Joint j;
    j=Joint(Joint::None);
    CPPUNIT_ASSERT_EQUAL(Joint::None,j.getType());
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame::Identity());
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist::Zero());
    random(q);
    j=Joint(Joint::RotX);
    CPPUNIT_ASSERT_EQUAL(Joint::RotX,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Rotation::RotX(q)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector::Zero(),Vector(q,0,0)));
    random(q);
    j=Joint(Joint::RotY);
    CPPUNIT_ASSERT_EQUAL(Joint::RotY,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Rotation::RotY(q)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector::Zero(),Vector(0,q,0)));
    random(q);
    j=Joint(Joint::RotZ);
    CPPUNIT_ASSERT_EQUAL(Joint::RotZ,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Rotation::RotZ(q)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector::Zero(),Vector(0,0,q)));
    random(q);
    j=Joint(Joint::TransX);
    CPPUNIT_ASSERT_EQUAL(Joint::TransX,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Vector(q,0,0)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector(q,0,0),Vector::Zero()));
    random(q);
    j=Joint(Joint::TransY);
    CPPUNIT_ASSERT_EQUAL(Joint::TransY,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Vector(0,q,0)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector(0,q,0),Vector::Zero()));
    random(q);
    j=Joint(Joint::TransZ);
    CPPUNIT_ASSERT_EQUAL(Joint::TransZ,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Vector(0,0,q)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector(0,0,q),Vector::Zero()));

}

void KinFamTest::SegmentTest()
{
    Segment s;
    double q,qdot;
    Frame f,f1;
    random(f);
    s = Segment(Joint(Joint::None),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).RefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment(Joint(Joint::RotX),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).RefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment(Joint(Joint::RotY),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).RefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment(Joint(Joint::RotZ),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).RefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment(Joint(Joint::TransX),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).RefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment(Joint(Joint::TransY),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).RefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment(Joint(Joint::TransZ),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).RefPoint(f1.p),s.twist(q,qdot));
}

void KinFamTest::ChainTest()
{
    Chain chain1;

    chain1.addSegment(Segment(Joint(Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.0))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,0.9))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,1.2))));
    chain1.addSegment(Segment(Joint(Joint::RotZ),
                              Frame(Vector(0.0,0.0,1.5))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,0.0))));
    chain1.addSegment(Segment(Joint(Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.4))));
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfJoints(),(uint)6);
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfSegments(),(uint)6);
    chain1.addSegment(Segment(Joint(Joint::None),Frame(Vector(0.0,0.1,0.0))));
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfJoints(),(uint)6);
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfSegments(),(uint)7);

    Chain chain2 = chain1;
    CPPUNIT_ASSERT_EQUAL(chain2.getNrOfJoints(),chain1.getNrOfJoints());
    CPPUNIT_ASSERT_EQUAL(chain2.getNrOfSegments(),chain1.getNrOfSegments());
    chain2.addChain(chain1);
    CPPUNIT_ASSERT_EQUAL(chain2.getNrOfJoints(),chain1.getNrOfJoints()*(uint)2);
    CPPUNIT_ASSERT_EQUAL(chain2.getNrOfSegments(),chain1.getNrOfSegments()*(uint)2);
}

void KinFamTest::TreeTest()
{
    Tree tree1;
    Segment segment1(Joint(Joint::None));
    Segment segment2(Joint(Joint::RotX),Frame(Vector(0.1,0.2,0.3)));
    Segment segment3(Joint(Joint::TransZ),Frame(Rotation::RotX(1.57)));

    cout<<tree1<<endl;

    CPPUNIT_ASSERT(tree1.addSegment(segment1,"Segment1","root"));
    CPPUNIT_ASSERT(tree1.addSegment(segment2,"Segment2","root"));
    CPPUNIT_ASSERT(tree1.addSegment(segment3,"Segment3","Segment1"));
    CPPUNIT_ASSERT(tree1.addSegment(segment2,"Segment4","Segment3"));
    CPPUNIT_ASSERT(!tree1.addSegment(segment1,"Segment5","Segment6"));
    CPPUNIT_ASSERT(!tree1.addSegment(segment1,"Segment1","Segment4"));

    cout<<tree1<<endl;

    Tree tree2;
    CPPUNIT_ASSERT(tree2.addSegment(segment1,"Segment1","root"));
    CPPUNIT_ASSERT(tree2.addSegment(segment2,"Segment2","root"));
    CPPUNIT_ASSERT(tree2.addSegment(segment3,"Segment3","Segment1"));

    cout<<tree2<<endl;

    Chain chain1;
    chain1.addSegment(Segment(Joint(Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.0))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,0.9))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,1.2))));
    chain1.addSegment(Segment(Joint(Joint::RotZ),
                              Frame(Vector(0.0,0.0,1.5))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,0.0))));
    chain1.addSegment(Segment(Joint(Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.4))));


    CPPUNIT_ASSERT(tree2.addChain(chain1,"Chain1","Segment2"));
    cout<<tree2<<endl;
    CPPUNIT_ASSERT(tree1.addTree(tree2,"Tree2","Segment2"));
    cout<<tree1<<endl;

}



