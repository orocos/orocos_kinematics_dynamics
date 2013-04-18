#include "kinfamtest.hpp"
#include <frames_io.hpp>
#include <kinfam_io.hpp>
#include <chainfksolverpos_recursive.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION( KinFamTest );

#ifdef  __APPLE__
typedef unsigned int uint;
#endif

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
    j=Joint("Joint 1", Joint::None);
    CPPUNIT_ASSERT_EQUAL(Joint::None,j.getType());
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame::Identity());
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist::Zero());
    random(q);
    j=Joint("Joint 2", Joint::RotX);
    CPPUNIT_ASSERT_EQUAL(Joint::RotX,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Rotation::RotX(q)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector::Zero(),Vector(q,0,0)));
    random(q);
    j=Joint("Joint 3", Joint::RotY);
    CPPUNIT_ASSERT_EQUAL(Joint::RotY,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Rotation::RotY(q)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector::Zero(),Vector(0,q,0)));
    random(q);
    j=Joint("Joint 4", Joint::RotZ);
    CPPUNIT_ASSERT_EQUAL(Joint::RotZ,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Rotation::RotZ(q)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector::Zero(),Vector(0,0,q)));
    random(q);
    j=Joint("Joint 5", Joint::TransX);
    CPPUNIT_ASSERT_EQUAL(Joint::TransX,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Vector(q,0,0)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector(q,0,0),Vector::Zero()));
    random(q);
    j=Joint("Joint 6", Joint::TransY);
    CPPUNIT_ASSERT_EQUAL(Joint::TransY,j.getType());
    CPPUNIT_ASSERT_EQUAL(j.pose(q),Frame(Vector(0,q,0)));
    random(q);
    CPPUNIT_ASSERT_EQUAL(j.twist(q),Twist(Vector(0,q,0),Vector::Zero()));
    random(q);
    j=Joint("Joint 7", Joint::TransZ);
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
    s = Segment("Segment 0", Joint("Joint 0", Joint::None),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).ChangeRefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment("Segment 1", Joint("Joint 1", Joint::RotX),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).ChangeRefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment("Segment 3", Joint("Joint 3", Joint::RotY),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).ChangeRefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment("Segment 4", Joint("Joint 4", Joint::RotZ),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).ChangeRefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment("Segment 5", Joint("Joint 5", Joint::TransX),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).ChangeRefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment("Segment 6", Joint("Joint 6", Joint::TransY),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).ChangeRefPoint(f1.p),s.twist(q,qdot));
    random(f);
    s = Segment("Segment 7", Joint("Joint 7", Joint::TransZ),f);
    random(q);
    random(qdot);
    f1=s.getJoint().pose(q)*f;
    CPPUNIT_ASSERT_EQUAL(f1,s.pose(q));
    CPPUNIT_ASSERT_EQUAL(s.getJoint().twist(qdot).ChangeRefPoint(f1.p),s.twist(q,qdot));
}

void KinFamTest::ChainTest()
{
    Chain chain1;

    //Testing addSegment
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 0", Joint("Joint 0", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.0)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 1", Joint("Joint 1", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.9)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 2", Joint("Joint 2", Joint::RotX),
                              Frame(Vector(0.0,0.0,1.2)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 3", Joint("Joint 3", Joint::RotZ),
                              Frame(Vector(0.0,0.0,1.5)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 4", Joint("Joint 4", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.0)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 5", Joint("Joint 5", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.4)))));
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfJoints(),(uint)6);
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfSegments(),(uint)6);
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 6", Joint("Joint 6", Joint::None),Frame(Vector(0.0,0.1,0.0)))));
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfJoints(),(uint)6);
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfSegments(),(uint)7);

    //Testing getSegment and getLeafSegment
    Segment segm;
    CPPUNIT_ASSERT(chain1.getSegment("Segment 1",segm));
    CPPUNIT_ASSERT(!chain1.getSegment("Segment 1546",segm));
    CPPUNIT_ASSERT(chain1.getSegment(1,segm));
    CPPUNIT_ASSERT(!chain1.getSegment(5614,segm));

    //Testing = operator
    Chain chain2 = chain1;
    CPPUNIT_ASSERT_EQUAL(chain2.getNrOfJoints(),chain1.getNrOfJoints());
    CPPUNIT_ASSERT_EQUAL(chain2.getNrOfSegments(),chain1.getNrOfSegments());

    Chain chain3;
    CPPUNIT_ASSERT(chain3.addSegment(Segment("Segment 7", Joint("Joint 7", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.0)))));
    CPPUNIT_ASSERT(chain3.addSegment(Segment("Segment 8", Joint("Joint 8", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.9)))));
    CPPUNIT_ASSERT(chain3.addSegment(Segment("Segment 9", Joint("Joint 9", Joint::RotX),
                              Frame(Vector(0.0,0.0,1.2)))));
    CPPUNIT_ASSERT(chain3.addSegment(Segment("Segment 10", Joint("Joint 10", Joint::RotZ),
                              Frame(Vector(0.0,0.0,1.5)))));
    CPPUNIT_ASSERT(chain3.addSegment(Segment("Segment 11", Joint("Joint 11", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.0)))));
    CPPUNIT_ASSERT(chain3.addSegment(Segment("Segment 12", Joint("Joint 12", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.4)))));
    CPPUNIT_ASSERT(chain3.addSegment(Segment("Segment 13", Joint("Joint 13", Joint::None),
    						  Frame(Vector(0.0,0.1,0.0)))));

    //Testing addChain - true case
    CPPUNIT_ASSERT(chain1.addChain(chain3));
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfJoints(),chain3.getNrOfJoints()*(uint)2);
    CPPUNIT_ASSERT_EQUAL(chain1.getNrOfSegments(),chain3.getNrOfSegments()*(uint)2);

    //Testing addChain - false case
    //Chain2 will remain unchanged
    Chain chain4;
    CPPUNIT_ASSERT(chain4.addSegment(Segment("Segment 1", Joint("Joint 1", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.0)))));
    int nrOfJoints = chain2.getNrOfJoints();
    int nrOfSegments = chain2.getNrOfSegments();
    CPPUNIT_ASSERT(!chain2.addChain(chain4));
    CPPUNIT_ASSERT(nrOfJoints==chain2.getNrOfJoints());
    CPPUNIT_ASSERT(nrOfSegments==chain2.getNrOfSegments());

    //Testing getChain()
    Chain chain5;
    Chain chain8;
    CPPUNIT_ASSERT(chain1.getChain_Including("Segment 1", "Segment 4",chain5));
    CPPUNIT_ASSERT(chain1.getChain_Excluding("Segment 1", "Segment 4",chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 4);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 3);
    CPPUNIT_ASSERT(chain1.getChain_Including(1, 4,chain5));
    CPPUNIT_ASSERT(chain1.getChain_Excluding(1, 4,chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 4);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 3);

    CPPUNIT_ASSERT(chain1.getChain_Including("Segment 4", "Segment 1",chain5));
    CPPUNIT_ASSERT(chain1.getChain_Excluding("Segment 4", "Segment 1",chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 4);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 3);
    CPPUNIT_ASSERT(chain1.getChain_Including(4, 1,chain5));
    CPPUNIT_ASSERT(chain1.getChain_Excluding(4, 1,chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 4);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 3);

    //Case tip not found
    CPPUNIT_ASSERT(!chain1.getChain_Including("Segment 4", "Segment 100",chain5));
    CPPUNIT_ASSERT(!chain1.getChain_Excluding("Segment 4", "Segment 100",chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(!chain1.getChain_Including(4, 100,chain5));
    CPPUNIT_ASSERT(!chain1.getChain_Excluding(4, 100,chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 0);

    //Case head not found
    CPPUNIT_ASSERT(!chain1.getChain_Including("Segment 100", "Segment 4",chain5));
    CPPUNIT_ASSERT(!chain1.getChain_Excluding("Segment 100", "Segment 4",chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(!chain1.getChain_Including(100, 4,chain5));
    CPPUNIT_ASSERT(!chain1.getChain_Excluding(100, 4,chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 0);

    //Case head and tip not found
    CPPUNIT_ASSERT(!chain1.getChain_Including("Segment 100", "Segment 150",chain5));
    CPPUNIT_ASSERT(!chain1.getChain_Excluding("Segment 100", "Segment 150",chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(!chain1.getChain_Including(100, 150,chain5));
    CPPUNIT_ASSERT(!chain1.getChain_Excluding(100, 150,chain8));
    CPPUNIT_ASSERT(chain5.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(chain8.getNrOfSegments() == 0);

    //Testing copy(name)
    Chain chain6;
    CPPUNIT_ASSERT(chain6.addSegment(Segment("Segment 0", Joint("Joint 0", Joint::RotZ),Frame(Vector(0.0,0.0,0.0)))));
    CPPUNIT_ASSERT(chain6.addSegment(Segment("Segment 1", Joint("Joint 1", Joint::RotX),Frame(Vector(0.0,0.0,0.9)))));
    CPPUNIT_ASSERT(chain6.addSegment(Segment("Segment 2", Joint("Joint 2", Joint::RotX),Frame(Vector(0.0,0.0,1.2)))));
    CPPUNIT_ASSERT(chain6.addSegment(Segment("Segment 3", Joint("Joint 3", Joint::RotZ),Frame(Vector(0.0,0.0,1.5)))));
    Chain chain6_copy;
    CPPUNIT_ASSERT(chain6.copy("Segment 2",chain6_copy));
    CPPUNIT_ASSERT(chain6_copy.getNrOfSegments() == 2);
    CPPUNIT_ASSERT(chain6.copy("Segment 5",chain6_copy)); //Does not change anything
    CPPUNIT_ASSERT(chain6_copy.getNrOfSegments() == 4);

    //Testing copy(nr)
    Chain chain7;
    CPPUNIT_ASSERT(chain7.addSegment(Segment("Segment 0", Joint("Joint 0", Joint::RotZ),Frame(Vector(0.0,0.0,0.0)))));
    CPPUNIT_ASSERT(chain7.addSegment(Segment("Segment 1", Joint("Joint 1", Joint::RotX),Frame(Vector(0.0,0.0,0.9)))));
    CPPUNIT_ASSERT(chain7.addSegment(Segment("Segment 2", Joint("Joint 2", Joint::RotX),Frame(Vector(0.0,0.0,1.2)))));
    CPPUNIT_ASSERT(chain7.addSegment(Segment("Segment 3", Joint("Joint 3", Joint::RotZ),Frame(Vector(0.0,0.0,1.5)))));
    Chain chain7_copy;
    CPPUNIT_ASSERT(chain7.copy(2,chain7_copy));
    CPPUNIT_ASSERT(chain7_copy.getNrOfSegments() == 2);
    CPPUNIT_ASSERT(!chain7.copy(100,chain7_copy)); //Does not change anything
    CPPUNIT_ASSERT(chain7_copy.getNrOfSegments() == 0);
}

void KinFamTest::TreeTest()
{
    Tree tree1;
    Segment segment1("Segment 1", Joint("Joint 1", Joint::None));
    Segment segment2("Segment 2", Joint("Joint 2", Joint::RotX),Frame(Vector(0.1,0.2,0.3)));
    Segment segment3("Segment 3", Joint("Joint 3", Joint::TransZ),Frame(Rotation::RotX(1.57)));
    Segment segment4("Segment 4", Joint("Joint 4", Joint::RotX),Frame(Vector(0.1,0.2,0.3)));
    Segment segment5("Segment 5", Joint("Joint 5", Joint::RotX),Frame(Vector(0.1,0.2,0.3)));
    Segment segment6("Segment 6", Joint("Joint 6", Joint::RotX),Frame(Vector(0.1,0.2,0.3)));
    Segment segment7("Segment 7", Joint("Joint 7", Joint::RotX),Frame(Vector(0.1,0.2,0.3)));

    cout<<tree1<<endl;

    //Testing addSegment
    CPPUNIT_ASSERT(tree1.addSegment(segment1,"root"));
    CPPUNIT_ASSERT(tree1.addSegment(segment2,"root"));
    CPPUNIT_ASSERT(tree1.addSegment(segment3,"Segment 1"));
    CPPUNIT_ASSERT(tree1.addSegment(segment4,"Segment 3"));
    CPPUNIT_ASSERT(!tree1.addSegment(segment1,"Segment 6"));
    CPPUNIT_ASSERT(!tree1.addSegment(segment1,"Segment 4"));

    //Testing getLeafSegments
    SegmentMap leafs;
    CPPUNIT_ASSERT(tree1.getLeafSegments(leafs));
    CPPUNIT_ASSERT(leafs.size() == 2);

    cout<<tree1<<endl;

    Tree tree2;
    CPPUNIT_ASSERT(tree2.addSegment(segment5,"root"));
    CPPUNIT_ASSERT(tree2.addSegment(segment6,"root"));
    CPPUNIT_ASSERT(tree2.addSegment(segment7,"Segment 6"));

    cout<<tree2<<endl;

    Chain chain1;
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 8", Joint("Joint 8", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.0)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 9", Joint("Joint 9", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.9)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 10", Joint("Joint 10", Joint::RotX),
                              Frame(Vector(0.0,0.0,1.2)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 11", Joint("Joint 11", Joint::RotZ),
                              Frame(Vector(0.0,0.0,1.5)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 12", Joint("Joint 12", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.0)))));
    CPPUNIT_ASSERT(chain1.addSegment(Segment("Segment 13", Joint("Joint 13", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.4)))));

    //Testing addChain
    CPPUNIT_ASSERT(tree2.addChain(chain1, "Segment 6"));
    cout<<tree2<<endl;
    //Testing addTree
    CPPUNIT_ASSERT(tree1.addTree(tree2, "Segment 2"));
    cout<<tree1<<endl;

    //Testing getLeafSegments
    CPPUNIT_ASSERT(tree1.getLeafSegments(leafs));
    CPPUNIT_ASSERT(leafs.size() == 4);

    //Testing getSegment
    SegmentMap::const_iterator segm;
    CPPUNIT_ASSERT(tree1.getSegment("Segment 1", segm));
    CPPUNIT_ASSERT(!tree1.getSegment("Segment 1458", segm));

    //Testing getChain methods
    Chain extract_chain1;
    Tree extract_tree1;
    CPPUNIT_ASSERT(tree1.getChain("Segment 2", "Segment 4", extract_chain1));
    CPPUNIT_ASSERT( (tree1.getChain("Segment 2", "Segment 4", extract_tree1,"root")) == false); //Zelfde root naam check
    CPPUNIT_ASSERT(extract_tree1.getNrOfSegments() == 0);
    CPPUNIT_ASSERT(tree1.getChain("Segment 2", "Segment 4", extract_tree1,"root1"));
    CPPUNIT_ASSERT(extract_tree1.getNrOfSegments() == 4);

    Chain extract_chain2;
    Tree extract_tree2;
    CPPUNIT_ASSERT(tree1.getChain("Segment 4", "Segment 2", extract_chain2));
    CPPUNIT_ASSERT(tree1.getChain("Segment 4", "Segment 2", extract_tree2,"root1"));
    CPPUNIT_ASSERT(extract_tree1.getNrOfSegments() == 4);

    CPPUNIT_ASSERT(extract_chain1.getNrOfJoints()==extract_chain2.getNrOfJoints());
    CPPUNIT_ASSERT(extract_chain1.getNrOfSegments()==extract_chain2.getNrOfSegments());
    CPPUNIT_ASSERT(extract_tree1.getNrOfJoints()==extract_tree2.getNrOfJoints());
    CPPUNIT_ASSERT(extract_tree1.getNrOfSegments()==extract_tree2.getNrOfSegments());
    ChainFkSolverPos_recursive solver1(extract_chain1);
    ChainFkSolverPos_recursive solver2(extract_chain2);

    Frame f1, f2;
    JntArray jnt1(extract_chain2.getNrOfJoints());
    JntArray jnt2(extract_chain2.getNrOfJoints());
    for (int i=0; i<(int)extract_chain2.getNrOfJoints(); i++){
      jnt1(i) = (i+1)*2;
      jnt2((int)extract_chain2.getNrOfJoints()-i-1) = jnt1(i);
    }
    solver1.JntToCart(jnt1, f1);
    solver2.JntToCart(jnt2, f2);
    CPPUNIT_ASSERT(f1 == f2.Inverse());

    //Testing copy
    Tree testing_tree = Tree("Root");
    testing_tree.addSegment(segment1,"Root");
    testing_tree.addSegment(segment2,"Root");
    testing_tree.addSegment(segment3,"Segment 1");
    testing_tree.addSegment(segment4,"Segment 1");
    testing_tree.addSegment(segment5,"Segment 2");
    testing_tree.addSegment(segment6,"Segment 5");
    testing_tree.addSegment(segment7,"Segment 5");

    Tree testing_tree_copy;
    SegmentMap leafMap;
    CPPUNIT_ASSERT(testing_tree.copy("Segment 1",testing_tree_copy));
    CPPUNIT_ASSERT(testing_tree_copy.getNrOfSegments() == 4);
    CPPUNIT_ASSERT(testing_tree_copy.getLeafSegments(leafMap));
    CPPUNIT_ASSERT(leafMap.size() == 2);

    vector<string> vect;
    vect.push_back("Segment 3");
    vect.push_back("Segment 5");
    CPPUNIT_ASSERT(testing_tree.copy(vect,testing_tree_copy));
    CPPUNIT_ASSERT(testing_tree_copy.getNrOfSegments() == 3);
    CPPUNIT_ASSERT(testing_tree_copy.getLeafSegments(leafMap));
    CPPUNIT_ASSERT(leafMap.size() == 2);
}
