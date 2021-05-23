#include "solvertest.hpp"
#include <frames_io.hpp>
#include <framevel_io.hpp>
#include <kinfam_io.hpp>
#include <random>
#include <time.h>
#include <utilities/utility.h>

CPPUNIT_TEST_SUITE_REGISTRATION( SolverTest );

using namespace KDL;

void SolverTest::setUp()
{
    srand( (unsigned)time( NULL ));

    chain1.addSegment(Segment("Segment 1", Joint("Joint 1", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.0))));
    chain1.addSegment(Segment("Segment 2", Joint("Joint 2", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.9))));
    chain1.addSegment(Segment("Segment 3", Joint("Joint 3", Joint::None),
                              Frame(Vector(-0.4,0.0,0.0))));
    chain1.addSegment(Segment("Segment 4", Joint("Joint 4", Joint::RotX),
                              Frame(Vector(0.0,0.0,1.2))));
    chain1.addSegment(Segment("Segment 5", Joint("Joint 5", Joint::None),
                              Frame(Vector(0.4,0.0,0.0))));
    chain1.addSegment(Segment("Segment 6", Joint("Joint 6", Joint::RotZ),
                              Frame(Vector(0.0,0.0,1.4))));
    chain1.addSegment(Segment("Segment 7", Joint("Joint 7", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.0))));
    chain1.addSegment(Segment("Segment 8", Joint("Joint 8", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.4))));
    chain1.addSegment(Segment("Segment 9", Joint("Joint 9", Joint::None),
                              Frame(Vector(0.0,0.0,0.0))));

    chain2.addSegment(Segment("Segment 1", Joint("Joint 1", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.5))));
    chain2.addSegment(Segment("Segment 2", Joint("Joint 2", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.4))));
    chain2.addSegment(Segment("Segment 3", Joint("Joint 3", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.3))));
    chain2.addSegment(Segment("Segment 4", Joint("Joint 4", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.2))));
    chain2.addSegment(Segment("Segment 5", Joint("Joint 5", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.1))));


    chain3.addSegment(Segment("Segment 1", Joint("Joint 1", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.0))));
    chain3.addSegment(Segment("Segment 2", Joint("Joint 2", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.9))));
    chain3.addSegment(Segment("Segment 3", Joint("Joint 3", Joint::RotZ),
                              Frame(Vector(-0.4,0.0,0.0))));
    chain3.addSegment(Segment("Segment 4", Joint("Joint 4", Joint::RotX),
                              Frame(Vector(0.0,0.0,1.2))));
    chain3.addSegment(Segment("Segment 5", Joint("Joint 5", Joint::None),
                              Frame(Vector(0.4,0.0,0.0))));
    chain3.addSegment(Segment("Segment 6", Joint("Joint 6", Joint::RotZ),
                              Frame(Vector(0.0,0.0,1.4))));
    chain3.addSegment(Segment("Segment 7", Joint("Joint 7", Joint::RotX),
                              Frame(Vector(0.0,0.0,0.0))));
    chain3.addSegment(Segment("Segment 8", Joint("Joint 8", Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.4))));
    chain3.addSegment(Segment("Segment 9", Joint("Joint 9", Joint::RotY),
                              Frame(Vector(0.0,0.0,0.0))));


    chain4.addSegment(Segment("Segment 1", Joint("Joint 1", Vector(10,0,0), Vector(1,0,1),Joint::RotAxis),
                              Frame(Vector(0.0,0.0,0.5))));
    chain4.addSegment(Segment("Segment 2", Joint("Joint 2", Vector(0,5,0), Vector(1,0,0),Joint::RotAxis),
                              Frame(Vector(0.0,0.0,0.4))));
    chain4.addSegment(Segment("Segment 3", Joint("Joint 3", Vector(0,0,5), Vector(1,0,4),Joint::RotAxis),
                              Frame(Vector(0.0,0.0,0.3))));
    chain4.addSegment(Segment("Segment 4", Joint("Joint 4", Vector(0,0,0), Vector(1,0,0),Joint::RotAxis),
                              Frame(Vector(0.0,0.0,0.2))));
    chain4.addSegment(Segment("Segment 5", Joint("Joint 5", Vector(0,0,0), Vector(0,0,1),Joint::RotAxis),
                              Frame(Vector(0.0,0.0,0.1))));



    //chain definition for vereshchagin's dynamic solver
    Joint rotJoint0 = Joint(Joint::RotZ, 1, 0, 0.01);
    Joint rotJoint1 = Joint(Joint::RotZ, 1, 0, 0.01);

    Frame refFrame(Rotation::RPY(0.0, 0.0, 0.0), Vector(0.0, 0.0, 0.0));
    Frame frame1(Rotation::RPY(0.0, 0.0, 0.0), Vector(0.0, -0.4, 0.0));
    Frame frame2(Rotation::RPY(0.0, 0.0, 0.0), Vector(0.0, -0.4, 0.0));

    //chain segments
    Segment segment1 = Segment(rotJoint0, frame1);
    Segment segment2 = Segment(rotJoint1, frame2);

    //rotational inertia around symmetry axis of rotation
    RotationalInertia rotInerSeg1(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

    //spatial inertia
    RigidBodyInertia inerSegment1(0.3, Vector(0.0, -0.4, 0.0), rotInerSeg1);
    RigidBodyInertia inerSegment2(0.3, Vector(0.0, -0.4, 0.0), rotInerSeg1);
    segment1.setInertia(inerSegment1);
    segment2.setInertia(inerSegment2);

    //chain
    chaindyn.addSegment(segment1);
    chaindyn.addSegment(segment2);

	// Motoman SIA10 Chain (for IK singular value tests)
	motomansia10.addSegment(Segment(Joint(Joint::None),
									Frame::DH_Craig1989(0.0, 0.0, 0.36, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, PI_2, 0.0, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, -PI_2, 0.36, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, PI_2, 0.0, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, -PI_2, 0.36, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, PI_2, 0.0, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, -PI_2, 0.0, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame(Rotation::Identity(),Vector(0.0,0.0,0.155))));

    // Motoman SIA10 Chain with Mass Parameters (for forward dynamics tests)

    //  effective motor inertia is included as joint inertia
    static const double scale=1;
    static const double offset=0;
    static const double inertiamotorA=5.0;      // effective motor inertia kg-m^2
    static const double inertiamotorB=3.0;      // effective motor inertia kg-m^2
    static const double inertiamotorC=1.0;      // effective motor inertia kg-m^2
    static const double damping=0;
    static const double stiffness=0;

    //  Segment Inertias
    KDL::RigidBodyInertia inert1(15.0, KDL::Vector(0.0, -0.02, 0.0),                       // mass, CM
                                 KDL::RotationalInertia(0.1, 0.05, 0.1, 0.0, 0.0, 0.0));   // inertia
    KDL::RigidBodyInertia inert2(5.0, KDL::Vector(0.0, -0.02, -0.1),
                                 KDL::RotationalInertia(0.01, 0.1, 0.1, 0.0, 0.0, 0.0));
    KDL::RigidBodyInertia inert3(5.0, KDL::Vector(0.0, -0.05, 0.02),
                                 KDL::RotationalInertia(0.05, 0.01, 0.05, 0.0, 0.0, 0.0));
    KDL::RigidBodyInertia inert4(3.0, KDL::Vector(0.0, 0.02, -0.15),
                                 KDL::RotationalInertia(0.1, 0.1, 0.01, 0.0, 0.0, 0.0));
    KDL::RigidBodyInertia inert5(3.0, KDL::Vector(0.0, -0.05, 0.01),
                                 KDL::RotationalInertia(0.02, 0.01, 0.02, 0.0, 0.0, 0.0));
    KDL::RigidBodyInertia inert6(3.0, KDL::Vector(0.0, -0.01, -0.1),
                                 KDL::RotationalInertia(0.1, 0.1, 0.01, 0.0, 0.0, 0.0));
    KDL::RigidBodyInertia inert7(1.0, KDL::Vector(0.0, 0.0, 0.05),
                                 KDL::RotationalInertia(0.01, 0.01, 0.1, 0.0, 0.0, 0.0));

    motomansia10dyn.addSegment(Segment(Joint(Joint::RotZ, scale, offset, inertiamotorA, damping, stiffness),
                               Frame::DH(0.0, PI_2, 0.36, 0.0),
                               inert1));
    motomansia10dyn.addSegment(Segment(Joint(Joint::RotZ, scale, offset, inertiamotorA, damping, stiffness),
                               Frame::DH(0.0, -PI_2, 0.0, 0.0),
                               inert2));
    motomansia10dyn.addSegment(Segment(Joint(Joint::RotZ, scale, offset, inertiamotorB, damping, stiffness),
                               Frame::DH(0.0, PI_2, 0.36, 0.0),
                               inert3));
    motomansia10dyn.addSegment(Segment(Joint(Joint::RotZ, scale, offset, inertiamotorB, damping, stiffness),
                               Frame::DH(0.0, -PI_2, 0.0, 0.0),
                               inert4));
    motomansia10dyn.addSegment(Segment(Joint(Joint::RotZ, scale, offset, inertiamotorC, damping, stiffness),
                               Frame::DH(0.0, PI_2, 0.36, 0.0),
                               inert5));
    motomansia10dyn.addSegment(Segment(Joint(Joint::RotZ, scale, offset, inertiamotorC, damping, stiffness),
                               Frame::DH(0.0, -PI_2, 0.0, 0.0),
                               inert6));
    motomansia10dyn.addSegment(Segment(Joint(Joint::RotZ, scale, offset, inertiamotorC, damping, stiffness),
                               Frame::DH(0.0, 0.0, 0.0, 0.0),
                               inert7));
    motomansia10dyn.addSegment(Segment(Joint(Joint::None),
                                       Frame(Rotation::Identity(),Vector(0.0,0.0,0.155))));

    /** 
     * KUKA LWR 4 Chain with Dynamics Parameters (for Forward Dynamics and Vereshchagin solver tests)
     * Necessary test model for the Vereshchagin solver: KDL's implementation of the Vereshchagin solver 
     * can only work with the robot chains that have equal number of joints and segments.
     * Note: Joint effective inertia values in this model are closely aligned with the joint inertia
     * of the real robot. These parameters are published in: Jubien, A., Gautier, M. and Janot, A., 
     * "Dynamic identification of the Kuka LWR robot using motor torques and joint torque sensors data.",
     * IFAC Proceedings Volumes, 2014., 47(3), pp.8391-8396.
     */
	kukaLWR.addSegment(Segment(Joint(Joint::RotZ, scale, offset, 3.19, damping, stiffness),
				  Frame::DH_Craig1989(0.0, 1.5707963, 0.0, 0.0),
				  Frame::DH_Craig1989(0.0, 1.5707963, 0.0, 0.0).Inverse()*RigidBodyInertia(2,
												 Vector::Zero(),
												 RotationalInertia(0.0,0.0,0.0115343,0.0,0.0,0.0))));

	kukaLWR.addSegment(Segment(Joint(Joint::RotZ, scale, offset, 3.05, damping, stiffness),
				  Frame::DH_Craig1989(0.0, -1.5707963, 0.4, 0.0),
				  Frame::DH_Craig1989(0.0, -1.5707963, 0.4, 0.0).Inverse()*RigidBodyInertia(2,
												   Vector(0.0,-0.3120511,-0.0038871),
												   RotationalInertia(-0.5471572,-0.0000302,-0.5423253,0.0,0.0,0.0018828))));

	kukaLWR.addSegment(Segment(Joint(Joint::RotZ, scale, offset, 1.98, damping, stiffness),
				  Frame::DH_Craig1989(0.0, -1.5707963, 0.0, 0.0),
				  Frame::DH_Craig1989(0.0, -1.5707963, 0.0, 0.0).Inverse()*RigidBodyInertia(2,
												   Vector(0.0,-0.0015515,0.0),
												   RotationalInertia(0.0063507,0.0,0.0107804,0.0,0.0,-0.0005147))));

	kukaLWR.addSegment(Segment(Joint(Joint::RotZ, scale, offset, 2.05, damping, stiffness),
				  Frame::DH_Craig1989(0.0, 1.5707963, 0.39, 0.0),
				  Frame::DH_Craig1989(0.0, 1.5707963, 0.39, 0.0).Inverse()*RigidBodyInertia(2,
												   Vector(0.0,0.5216809,0.0),
												   RotationalInertia(-1.0436952,0.0,-1.0392780,0.0,0.0,0.0005324))));

	kukaLWR.addSegment(Segment(Joint(Joint::RotZ, scale, offset, 0.787, damping, stiffness),
				  Frame::DH_Craig1989(0.0, 1.5707963, 0.0, 0.0),
				  Frame::DH_Craig1989(0.0, 1.5707963, 0.0, 0.0).Inverse()*RigidBodyInertia(2,
												   Vector(0.0,0.0119891,0.0),
												   RotationalInertia(0.0036654,0.0,0.0060429,0.0,0.0,0.0004226))));

	kukaLWR.addSegment(Segment(Joint(Joint::RotZ, scale, offset, 0.391, damping, stiffness),
				  Frame::DH_Craig1989(0.0, -1.5707963, 0.0, 0.0),
				  Frame::DH_Craig1989(0.0, -1.5707963, 0.0, 0.0).Inverse()*RigidBodyInertia(2,
												   Vector(0.0,0.0080787,0.0),
												   RotationalInertia(0.0010431,0.0,0.0036376,0.0,0.0,0.0000101))));

	kukaLWR.addSegment(Segment(Joint(Joint::RotZ, scale, offset, 0.394, damping, stiffness),
				               Frame::Identity(),
				               RigidBodyInertia(2, Vector::Zero(), RotationalInertia(0.000001,0.0,0.0001203,0.0,0.0,0.0))));
}

void SolverTest::tearDown()
{
//     delete fksolverpos;
//     delete jacsolver;
//     delete fksolvervel;
//     delete iksolvervel;
//     delete iksolverpos;
}

void SolverTest::UpdateChainTest()
{
    ChainFkSolverPos_recursive fksolverpos(chain2);
    ChainFkSolverVel_recursive fksolvervel(chain2);
    ChainJntToJacSolver jacsolver1(chain2);
    ChainJntToJacDotSolver jacdotsolver1(chain2);
    ChainIkSolverVel_pinv iksolver2(chain2);
    ChainIkSolverVel_pinv_givens iksolver_pinv_givens2(chain2);
    ChainIkSolverVel_pinv_nso  iksolver_pinv_nso(chain2);
    ChainIkSolverVel_wdls iksolver_wdls(chain2,1e-6,30);
    ChainIkSolverPos_NR iksolverpos(chain2,fksolverpos,iksolver2);
    ChainIkSolverPos_NR_JL iksolverpos2(chain2,fksolverpos,iksolver2);
    ChainIkSolverPos_LMA iksolverpos3(chain2);
    ChainDynParam dynparam(chain2, Vector::Zero());
    ChainIdSolver_RNE idsolver1(chain2, Vector::Zero());
    unsigned int nr_of_constraints = 4;
    ChainHdSolver_Vereshchagin hdsolver(chain2,Twist::Zero(),4);
    ChainExternalWrenchEstimator extwrench_estimator(chain2,Vector::Zero(), 100.0, 30.0, 0.5);

    JntArray q_in(chain2.getNrOfJoints());
    JntArray q_in2(chain2.getNrOfJoints());
    JntArrayVel q_in3(chain2.getNrOfJoints());
    for(unsigned int i=0; i<chain2.getNrOfJoints(); i++)
    {
        random(q_in(i));
        random(q_in2(i));
    }
    JntArray q_out(chain2.getNrOfJoints());
    JntArray q_out2(chain2.getNrOfJoints());
    JntArray ff_tau(chain2.getNrOfJoints());
    JntArray constraint_tau(chain2.getNrOfJoints());
    Jacobian jac(chain2.getNrOfJoints());
    Frame T;
    Twist t;
    FrameVel T2;
    Wrenches wrenches(chain2.getNrOfSegments());
    JntSpaceInertiaMatrix m(chain2.getNrOfJoints());
    Wrench wrench_out;

    Jacobian alpha(nr_of_constraints - 1);
    JntArray beta(nr_of_constraints - 1);
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_OUT_OF_RANGE,fksolverpos.JntToCart(q_in, T, chain2.getNrOfSegments()+1));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_OUT_OF_RANGE,fksolvervel.JntToCart(q_in3, T2, chain2.getNrOfSegments()+1));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_OUT_OF_RANGE, jacsolver1.JntToJac(q_in, jac, chain2.getNrOfSegments()+1));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_OUT_OF_RANGE, jacdotsolver1.JntToJacDot(q_in3, t, chain2.getNrOfSegments()+1));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_OUT_OF_RANGE, jacdotsolver1.JntToJacDot(q_in3, jac, chain2.getNrOfSegments()+1));
    chain2.addSegment(Segment("Segment 6", Joint("Joint 6", Joint::RotX),
            Frame(Vector(0.0,0.0,0.1))));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, jacsolver1.JntToJac(q_in, jac, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, jacdotsolver1.JntToJacDot(q_in3, jac, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, jacdotsolver1.JntToJacDot(q_in3, t, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, iksolver2.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, iksolver_pinv_givens2.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, iksolver_pinv_nso.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, iksolver_wdls.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, iksolverpos.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, iksolverpos2.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, iksolverpos3.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, idsolver1.CartToJnt(q_in,q_in2,q_out,wrenches,q_out2));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, dynparam.JntToCoriolis(q_in, q_in2, q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, dynparam.JntToGravity(q_in, q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, dynparam.JntToMass(q_in, m));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOT_UP_TO_DATE, extwrench_estimator.JntToExtWrench(q_in,q_in2,ff_tau,wrench_out));

    jacsolver1.updateInternalDataStructures();
    jacdotsolver1.updateInternalDataStructures();
    iksolver2.updateInternalDataStructures();
    iksolver_pinv_givens2.updateInternalDataStructures();
    iksolver_pinv_nso.updateInternalDataStructures();
    iksolver_wdls.updateInternalDataStructures();
    iksolverpos.updateInternalDataStructures();
    iksolverpos2.updateInternalDataStructures();
    iksolverpos3.updateInternalDataStructures();
    idsolver1.updateInternalDataStructures();
    hdsolver.updateInternalDataStructures();
    dynparam.updateInternalDataStructures();
    extwrench_estimator.updateInternalDataStructures();

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH,fksolverpos.JntToCart(q_in, T, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH,fksolvervel.JntToCart(q_in3, T2, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, jacsolver1.JntToJac(q_in, jac, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, jacdotsolver1.JntToJacDot(q_in3, t, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, jacdotsolver1.JntToJacDot(q_in3, jac, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolver2.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolver_pinv_givens2.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolver_pinv_nso.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolver_wdls.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolverpos.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolverpos2.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolverpos3.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, idsolver1.CartToJnt(q_in,q_in2,q_out,wrenches,q_out2));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, dynparam.JntToCoriolis(q_in, q_in2, q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, dynparam.JntToGravity(q_in, q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, dynparam.JntToMass(q_in, m));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, extwrench_estimator.JntToExtWrench(q_in,q_in2,ff_tau,wrench_out));

    q_in.resize(chain2.getNrOfJoints());
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, jacsolver1.JntToJac(q_in, jac, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolver2.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolver_pinv_givens2.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolver_pinv_nso.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolver_wdls.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolverpos.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolverpos2.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolverpos3.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolverpos2.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, iksolverpos3.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, idsolver1.CartToJnt(q_in,q_in2,q_out,wrenches,q_out2));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, dynparam.JntToCoriolis(q_in, q_in2, q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, dynparam.JntToGravity(q_in, q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, dynparam.JntToMass(q_in, m));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, extwrench_estimator.JntToExtWrench(q_in,q_in2,ff_tau,wrench_out));
    q_in2.resize(chain2.getNrOfJoints());
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, dynparam.JntToCoriolis(q_in, q_in2, q_out));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, idsolver1.CartToJnt(q_in,q_in2,q_out,wrenches,q_out2));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, extwrench_estimator.JntToExtWrench(q_in,q_in2,ff_tau,wrench_out));
    wrenches.resize(chain2.getNrOfSegments());
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, idsolver1.CartToJnt(q_in,q_in2,q_out,wrenches,q_out2));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    q_out2.resize(chain2.getNrOfSegments());
    ff_tau.resize(chain2.getNrOfSegments());
    constraint_tau.resize(chain2.getNrOfSegments());
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, idsolver1.CartToJnt(q_in,q_in2,q_out,wrenches,q_out2));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    alpha.resize(nr_of_constraints);
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    beta.resize(nr_of_constraints);
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    jac.resize(chain2.getNrOfJoints());
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_SIZE_MISMATCH, jacdotsolver1.JntToJacDot(q_in3, jac, chain2.getNrOfSegments()));
    q_out.resize(chain2.getNrOfJoints());
    q_in3.resize(chain2.getNrOfJoints());
    m.resize(chain2.getNrOfJoints());
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR,fksolverpos.JntToCart(q_in, T, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR,fksolvervel.JntToCart(q_in3, T2, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, jacsolver1.JntToJac(q_in, jac, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, jacdotsolver1.JntToJacDot(q_in3, jac, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, jacdotsolver1.JntToJacDot(q_in3, t, chain2.getNrOfSegments()));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolver2.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolver_pinv_givens2.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolver_pinv_nso.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolver_wdls.CartToJnt(q_in,t,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolverpos.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolverpos2.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolverpos3.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolverpos2.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= iksolverpos3.CartToJnt(q_in,T,q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= idsolver1.CartToJnt(q_in,q_in2,q_out,wrenches,q_out2));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= hdsolver.CartToJnt(q_in,q_in2,q_out,alpha,beta,wrenches, ff_tau, constraint_tau));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= dynparam.JntToCoriolis(q_in, q_in2, q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= dynparam.JntToGravity(q_in, q_out));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= dynparam.JntToMass(q_in, m));
    CPPUNIT_ASSERT((int)SolverI::E_NOERROR <= extwrench_estimator.JntToExtWrench(q_in,q_in2,ff_tau,wrench_out));
}
void SolverTest::FkPosAndJacTest()
{
    ChainFkSolverPos_recursive fksolver1(chain1);
    ChainJntToJacSolver jacsolver1(chain1);
    FkPosAndJacLocal(chain1,fksolver1,jacsolver1);
    ChainFkSolverPos_recursive fksolver2(chain2);
    ChainJntToJacSolver jacsolver2(chain2);
    FkPosAndJacLocal(chain2,fksolver2,jacsolver2);
    ChainFkSolverPos_recursive fksolver3(chain3);
    ChainJntToJacSolver jacsolver3(chain3);
    FkPosAndJacLocal(chain3,fksolver3,jacsolver3);
    ChainFkSolverPos_recursive fksolver4(chain4);
    ChainJntToJacSolver jacsolver4(chain4);
    FkPosAndJacLocal(chain4,fksolver4,jacsolver4);
}

void SolverTest::FkVelAndJacTest()
{
    ChainFkSolverVel_recursive fksolver1(chain1);
    ChainJntToJacSolver jacsolver1(chain1);
    FkVelAndJacLocal(chain1,fksolver1,jacsolver1);
    ChainFkSolverVel_recursive fksolver2(chain2);
    ChainJntToJacSolver jacsolver2(chain2);
    FkVelAndJacLocal(chain2,fksolver2,jacsolver2);
    ChainFkSolverVel_recursive fksolver3(chain3);
    ChainJntToJacSolver jacsolver3(chain3);
    FkVelAndJacLocal(chain3,fksolver3,jacsolver3);
    ChainFkSolverVel_recursive fksolver4(chain4);
    ChainJntToJacSolver jacsolver4(chain4);
    FkVelAndJacLocal(chain4,fksolver4,jacsolver4);
}

void SolverTest::FkVelAndIkVelTest()
{
    //Chain1
    std::cout<<"square problem"<<std::endl;
    ChainFkSolverVel_recursive fksolver1(chain1);
    ChainIkSolverVel_pinv iksolver1(chain1);
    ChainIkSolverVel_pinv_givens iksolver_pinv_givens1(chain1);
    std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkVelAndIkVelLocal(chain1,fksolver1,iksolver1);
    std::cout<<"KDL-SVD-Givens"<<std::endl;
    FkVelAndIkVelLocal(chain1,fksolver1,iksolver_pinv_givens1);

    //Chain2
    std::cout<<"underdetermined problem"<<std::endl;
    ChainFkSolverVel_recursive fksolver2(chain2);
    ChainIkSolverVel_pinv iksolver2(chain2);
    ChainIkSolverVel_pinv_givens iksolver_pinv_givens2(chain2);
    std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkVelAndIkVelLocal(chain2,fksolver2,iksolver2);
    std::cout<<"KDL-SVD-Givens"<<std::endl;
    FkVelAndIkVelLocal(chain2,fksolver2,iksolver_pinv_givens2);

    //Chain3
    std::cout<<"overdetermined problem"<<std::endl;
    ChainFkSolverVel_recursive fksolver3(chain3);
    ChainIkSolverVel_pinv iksolver3(chain3);
    ChainIkSolverVel_pinv_givens iksolver_pinv_givens3(chain3);
    std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkVelAndIkVelLocal(chain3,fksolver3,iksolver3);
    std::cout<<"KDL-SVD-Givens"<<std::endl;
    FkVelAndIkVelLocal(chain3,fksolver3,iksolver_pinv_givens3);

    //Chain4
    std::cout<<"overdetermined problem"<<std::endl;
    ChainFkSolverVel_recursive fksolver4(chain4);
    ChainIkSolverVel_pinv iksolver4(chain4);
    ChainIkSolverVel_pinv_givens iksolver_pinv_givens4(chain4);
    std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkVelAndIkVelLocal(chain4,fksolver4,iksolver4);
    std::cout<<"KDL-SVD-Givens"<<std::endl;
    FkVelAndIkVelLocal(chain4,fksolver4,iksolver_pinv_givens4);
}

void SolverTest::FkPosAndIkPosTest()
{
    std::cout<<"square problem"<<std::endl;
    ChainFkSolverPos_recursive fksolver1(chain1);
    ChainIkSolverVel_pinv iksolver1v(chain1);
    ChainIkSolverVel_pinv_givens iksolverv_pinv_givens1(chain1);
    ChainIkSolverPos_NR iksolver1(chain1,fksolver1,iksolver1v);
    ChainIkSolverPos_NR iksolver1_givens(chain1,fksolver1,iksolverv_pinv_givens1,1000);

    std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkPosAndIkPosLocal(chain1,fksolver1,iksolver1);
    std::cout<<"KDL-SVD-Givens"<<std::endl;
    FkPosAndIkPosLocal(chain1,fksolver1,iksolver1_givens);

    std::cout<<"underdetermined problem"<<std::endl;
    ChainFkSolverPos_recursive fksolver2(chain2);
    ChainIkSolverVel_pinv iksolverv2(chain2);
    ChainIkSolverVel_pinv_givens iksolverv_pinv_givens2(chain2);
    ChainIkSolverPos_NR iksolver2(chain2,fksolver2,iksolverv2);
    ChainIkSolverPos_NR iksolver2_givens(chain2,fksolver2,iksolverv_pinv_givens2,1000);

    std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkPosAndIkPosLocal(chain2,fksolver2,iksolver2);
    std::cout<<"KDL-SVD-Givens"<<std::endl;
    FkPosAndIkPosLocal(chain2,fksolver2,iksolver2_givens);

    std::cout<<"overdetermined problem"<<std::endl;
    ChainFkSolverPos_recursive fksolver3(chain3);
    ChainIkSolverVel_pinv iksolverv3(chain3);
    ChainIkSolverVel_pinv_givens iksolverv_pinv_givens3(chain3);
    ChainIkSolverPos_NR iksolver3(chain3,fksolver3,iksolverv3);
    ChainIkSolverPos_NR iksolver3_givens(chain3,fksolver3,iksolverv_pinv_givens3,1000);

    std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkPosAndIkPosLocal(chain3,fksolver3,iksolver3);
    std::cout<<"KDL-SVD-Givens"<<std::endl;
    FkPosAndIkPosLocal(chain3,fksolver3,iksolver3_givens);

    std::cout<<"underdetermined problem with WGs segment constructor"<<std::endl;
    ChainFkSolverPos_recursive fksolver4(chain4);
    ChainIkSolverVel_pinv iksolverv4(chain4);
    ChainIkSolverVel_pinv_givens iksolverv_pinv_givens4(chain4);
    ChainIkSolverPos_NR iksolver4(chain4,fksolver4,iksolverv4,1000);
    ChainIkSolverPos_NR iksolver4_givens(chain4,fksolver4,iksolverv_pinv_givens4,1000);

    std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkPosAndIkPosLocal(chain4,fksolver4,iksolver4);
    std::cout<<"KDL-SVD-Givens"<<std::endl;
    FkPosAndIkPosLocal(chain4,fksolver4,iksolver4_givens);
}

void SolverTest::IkSingularValueTest()
{
	unsigned int maxiter = 30;
	double	eps = 1e-6 ;
	int maxiter_vel = 30;
	double	eps_vel = 0.1 ;
    Frame F, dF, F_des,F_solved;
	KDL::Twist F_error ;

	std::cout<<"KDL-IK Solver Tests for Near Zero SVs"<<std::endl;

    ChainFkSolverPos_recursive fksolver(motomansia10);
    ChainIkSolverVel_pinv ikvelsolver1(motomansia10,eps_vel,maxiter_vel);
    ChainIkSolverPos_NR iksolver1(motomansia10,fksolver,ikvelsolver1,maxiter,eps);
	unsigned int nj = motomansia10.getNrOfJoints();
    JntArray q(nj), q_solved(nj) ;


	std::cout<<"norminal case:  convergence"<<std::endl;

	q(0) = 0. ;
	q(1) = 0.5 ;
	q(2) = 0.4 ;
	q(3) = -PI_2 ;
	q(4) = 0. ;
	q(5) = 0. ;
	q(6) = 0. ;

	dF.M = KDL::Rotation::RPY(0.1, 0.1, 0.1) ;
	dF.p = KDL::Vector(0.01,0.01,0.01) ;

	CPPUNIT_ASSERT_EQUAL(0, fksolver.JntToCart(q,F));
	F_des = F * dF ;

	CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR,
                         iksolver1.CartToJnt(q, F_des, q_solved));	// converges
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR,
                         ikvelsolver1.getError());
	CPPUNIT_ASSERT_EQUAL((unsigned int)1,
                         ikvelsolver1.getNrZeroSigmas()) ;		//	1 singular value

	CPPUNIT_ASSERT_EQUAL(0, fksolver.JntToCart(q_solved,F_solved));
	F_error = KDL::diff(F_solved,F_des);
	CPPUNIT_ASSERT_EQUAL(F_des,F_solved);

	std::cout<<"nonconvergence:  pseudoinverse singular"<<std::endl;

	q(0) = 0. ;
	q(1) = 0.2 ;
	q(2) = 0.4 ;
	q(3) = -PI_2 ;
	q(4) = 0. ;
	q(5) = 0. ;
	q(6) = 0. ;

	dF.M = KDL::Rotation::RPY(0.1, 0.1, 0.1) ;
	dF.p = KDL::Vector(0.01,0.01,0.01) ;

	CPPUNIT_ASSERT_EQUAL(0, fksolver.JntToCart(q,F));
	F_des = F * dF ;

	CPPUNIT_ASSERT_EQUAL((int)SolverI::E_MAX_ITERATIONS_EXCEEDED,
                         iksolver1.CartToJnt(q,F_des,q_solved)); // no converge
	CPPUNIT_ASSERT_EQUAL((int)ChainIkSolverVel_pinv::E_CONVERGE_PINV_SINGULAR,
                         ikvelsolver1.getError());        	// truncated SV solution
	CPPUNIT_ASSERT_EQUAL((unsigned int)2,
                         ikvelsolver1.getNrZeroSigmas()) ;		//	2 singular values (jac pseudoinverse singular)

	std::cout<<"nonconvergence:  large displacement, low iterations"<<std::endl;

	q(0) = 0. ;
	q(1) = 0.5 ;
	q(2) = 0.4 ;
	q(3) = -PI_2 ;
	q(4) = 0. ;
	q(5) = 0. ;
	q(6) = 0. ;

	// big displacement
	dF.M = KDL::Rotation::RPY(0.2, 0.2, 0.2) ;
	dF.p = KDL::Vector(-0.2,-0.2, -0.2) ;

	// low iterations
	maxiter = 5 ;
    ChainIkSolverPos_NR iksolver2(motomansia10,fksolver,ikvelsolver1,maxiter,eps);

	CPPUNIT_ASSERT_EQUAL(0, fksolver.JntToCart(q,F));
	F_des = F * dF ;

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_MAX_ITERATIONS_EXCEEDED,
                         iksolver2.CartToJnt(q,F_des,q_solved));	//  does not converge
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR,
                        ikvelsolver1.getError());
	CPPUNIT_ASSERT_EQUAL((unsigned int)1,
                         ikvelsolver1.getNrZeroSigmas()) ;		//	1 singular value (jac pseudoinverse exists)

	std::cout<<"nonconvergence:  fully singular"<<std::endl;

    q(0) = 0. ;
    q(1) = 0. ;
    q(2) = 0. ;
    q(3) = 0. ;
    q(4) = 0. ;
    q(5) = 0. ;
    q(6) = 0. ;

    dF.M = KDL::Rotation::RPY(0.1, 0.1, 0.1) ;
    dF.p = KDL::Vector(0.01,0.01,0.01) ;

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, fksolver.JntToCart(q,F));
    F_des = F * dF ;

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_MAX_ITERATIONS_EXCEEDED,
                         iksolver1.CartToJnt(q,F_des,q_solved)); // no converge
    CPPUNIT_ASSERT_EQUAL((int)ChainIkSolverVel_pinv::E_CONVERGE_PINV_SINGULAR,
                         ikvelsolver1.getError());        	// truncated SV solution
    CPPUNIT_ASSERT_EQUAL((unsigned int)3,
                         ikvelsolver1.getNrZeroSigmas());
}


void SolverTest::IkVelSolverWDLSTest()
{
	int maxiter = 30;
	double	eps = 0.1 ;
	double lambda = 0.1 ;

	std::cout<<"KDL-IK WDLS Vel Solver Tests for Near Zero SVs"<<std::endl;

	KDL::ChainIkSolverVel_wdls ikvelsolver(motomansia10,eps,maxiter) ;
	ikvelsolver.setLambda(lambda) ;
	unsigned int nj = motomansia10.getNrOfJoints();
    JntArray q(nj), dq(nj) ;

	KDL::Vector	v05(0.05,0.05,0.05) ;
	KDL::Twist dx(v05,v05) ;

	std::cout<<"smallest singular value is above threshold (no WDLS)"<<std::endl;

	q(0) = 0. ;
	q(1) = 0.5 ;
	q(2) = 0.4 ;
	q(3) = -PI_2 ;
	q(4) = 0. ;
	q(5) = 0. ;
	q(6) = 0. ;

	CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR,
                         ikvelsolver.CartToJnt(q, dx, dq)) ;	// wdls mode
	CPPUNIT_ASSERT(1==ikvelsolver.getNrZeroSigmas()) ;		//	1 singular value


	std::cout<<"smallest singular value is below threshold (lambda is scaled)"<<std::endl;

	q(1) = 0.2 ;

	CPPUNIT_ASSERT_EQUAL((int)ChainIkSolverVel_wdls::E_CONVERGE_PINV_SINGULAR,
                         ikvelsolver.CartToJnt(q, dx, dq)) ;	// wdls mode
	CPPUNIT_ASSERT_EQUAL((unsigned int)2,ikvelsolver.getNrZeroSigmas()) ;		//	2 singular values
	CPPUNIT_ASSERT_EQUAL(ikvelsolver.getLambdaScaled(),
                         sqrt(1.0-(ikvelsolver.getSigmaMin()/eps)*(ikvelsolver.getSigmaMin()/eps))*lambda) ;

	std::cout<<"smallest singular value is zero (lambda_scaled=lambda)"<<std::endl;

	q(1) = 0.0 ;

    CPPUNIT_ASSERT_EQUAL((int)ChainIkSolverVel_wdls::E_CONVERGE_PINV_SINGULAR,
                         ikvelsolver.CartToJnt(q, dx, dq)) ;	// wdls mode
	CPPUNIT_ASSERT_EQUAL((unsigned int)2,ikvelsolver.getNrZeroSigmas()) ;		//	2 singular values
	CPPUNIT_ASSERT_EQUAL(ikvelsolver.getLambdaScaled(),lambda) ;	// full value

	// fully singular
	q(2) = 0.0 ;
	q(3) = 0.0 ;

    CPPUNIT_ASSERT_EQUAL((int)ChainIkSolverVel_wdls::E_CONVERGE_PINV_SINGULAR,
                         ikvelsolver.CartToJnt(q, dx, dq)) ;	// wdls mode
	CPPUNIT_ASSERT_EQUAL(4,(int)ikvelsolver.getNrZeroSigmas()) ;
	CPPUNIT_ASSERT_EQUAL(ikvelsolver.getLambdaScaled(),lambda) ;	// full value
}


void SolverTest::FkPosAndJacLocal(Chain& chain,ChainFkSolverPos& fksolverpos,ChainJntToJacSolver& jacsolver)
{
    double deltaq = 1E-4;

    Frame F1,F2;

    JntArray q(chain.getNrOfJoints());
    Jacobian jac(chain.getNrOfJoints());

    for(unsigned int i=0; i<chain.getNrOfJoints(); i++)
    {
        random(q(i));
    }

    jacsolver.JntToJac(q,jac);

    for (unsigned int i=0; i< q.rows() ; i++)
    {
        // test the derivative of J towards qi
        double oldqi = q(i);
        q(i) = oldqi+deltaq;
        CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, fksolverpos.JntToCart(q,F2));
        q(i) = oldqi-deltaq;
        CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, fksolverpos.JntToCart(q,F1));
        q(i) = oldqi;
        // check Jacobian :
        Twist Jcol1 = diff(F1,F2,2*deltaq);
        Twist Jcol2(Vector(jac(0,i),jac(1,i),jac(2,i)),
                    Vector(jac(3,i),jac(4,i),jac(5,i)));

        //CPPUNIT_ASSERT_EQUAL(true,Equal(Jcol1,Jcol2,epsJ));
        CPPUNIT_ASSERT_EQUAL(Jcol1,Jcol2);
    }
}

void SolverTest::FkVelAndJacLocal(Chain& chain, ChainFkSolverVel& fksolvervel, ChainJntToJacSolver& jacsolver)
{
    JntArray q(chain.getNrOfJoints());
    JntArray qdot(chain.getNrOfJoints());

    for(unsigned int i=0; i<chain.getNrOfJoints(); i++)
    {
        random(q(i));
        random(qdot(i));
    }
    JntArrayVel qvel(q,qdot);
    Jacobian jac(chain.getNrOfJoints());

    FrameVel cart;
    Twist t;

    jacsolver.JntToJac(qvel.q,jac);
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, fksolvervel.JntToCart(qvel,cart));
    MultiplyJacobian(jac,qvel.qdot,t);
    CPPUNIT_ASSERT_EQUAL(cart.deriv(),t);
}

void SolverTest::FkVelAndIkVelLocal(Chain& chain, ChainFkSolverVel& fksolvervel, ChainIkSolverVel& iksolvervel)
{

    JntArray q(chain.getNrOfJoints());
    JntArray qdot(chain.getNrOfJoints());

    for(unsigned int i=0; i<chain.getNrOfJoints(); i++)
    {
        random(q(i));
        random(qdot(i));
    }
    JntArrayVel qvel(q,qdot);
    JntArray qdot_solved(chain.getNrOfJoints());

    FrameVel cart;

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, fksolvervel.JntToCart(qvel,cart));

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, iksolvervel.CartToJnt(qvel.q,cart.deriv(),qdot_solved));

    qvel.deriv()=qdot_solved;

    if(chain.getNrOfJoints()<=6)
        CPPUNIT_ASSERT(Equal(qvel.qdot,qdot_solved,1e-5));
    else
    {
        FrameVel cart_solved;
        CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR,fksolvervel.JntToCart(qvel,cart_solved));
        CPPUNIT_ASSERT(Equal(cart.deriv(),cart_solved.deriv(),1e-5));
    }
}


void SolverTest::FkPosAndIkPosLocal(Chain& chain,ChainFkSolverPos& fksolverpos, ChainIkSolverPos& iksolverpos)
{
    JntArray q(chain.getNrOfJoints());
    for(unsigned int i=0; i<chain.getNrOfJoints(); i++)
    {
        random(q(i));
    }
    JntArray q_init(chain.getNrOfJoints());
    double tmp;
    for(unsigned int i=0; i<chain.getNrOfJoints(); i++)
    {
        random(tmp);
        q_init(i)=q(i)+0.1*tmp;
    }
    JntArray q_solved(q);

    Frame F1,F2;

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, fksolverpos.JntToCart(q,F1));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, iksolverpos.CartToJnt(q_init,F1,q_solved));
    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, fksolverpos.JntToCart(q_solved,F2));

    CPPUNIT_ASSERT_EQUAL(F1,F2);
    //CPPUNIT_ASSERT_EQUAL(q,q_solved);

}


void SolverTest::VereshchaginTest()
{
    std::cout << "KDL Vereshchagin Hybrid Dynamics Tests" <<std::endl;

    // ########################################################################################
    // Vereshchagin solver test 1
    // ########################################################################################
    /**
     * Compute Hybrid Dynamics for KUKA LWR 4.
     * 
     * Test setup:
     * - Operational-space task imposes acceleration constraints on the end-effector
     * - External forces and feedforward joint torques are acting on the robot's structure, 
     *   as disturbances from the environment
     * 
     * Expected result:
     * - The solver computes the required joint torque commands (joint constraint torques)
     *   that satisfy imposed acceleration constraints and at the same time, compensate for 
     *   the above mentioned disturbances
     * 
     * Method to evaluate:
     * - Compare the _resultant_ Cartesian accelerations of the end-effector's segment with 
     *   the task-specified acceleration constraints
     */
    int solver_return = 0;
    double eps = 1.e-3;

    unsigned int nj = kukaLWR.getNrOfJoints();
    unsigned int ns = kukaLWR.getNrOfSegments();

    // Necessary test for the used robot model: KDL's implementation of the Vereshchagin solver 
    // can only work with the robot chains that have equal number of joints and segments
    CPPUNIT_ASSERT(Equal(nj, ns));

    // Joint position, velocity, acceleration, feed-forward and constraint torques
    KDL::JntArray q(nj); //input
    KDL::JntArray qd(nj); //input
    KDL::JntArray qdd(nj); //output
    KDL::JntArray ff_tau(nj); //input
    KDL::JntArray constraint_tau(nj); //output

    // Random configuration
    q(0) =  1.6;
    q(1) =  0.0;
    q(2) = -1.6;
    q(3) = -1.57;
    q(4) =  0.0;
    q(5) =  1.57;
    q(6) = -0.8;

    qd(0) =  1.0;
    qd(1) = -2.0;
    qd(2) =  3.0;
    qd(3) = -4.0;
    qd(4) =  5.0;
    qd(5) = -6.0;
    qd(6) =  7.0;

    // Random feedforwad torques acting on robot joints
    ff_tau(0) =  5.0;
    ff_tau(1) =  0.0;
    ff_tau(2) =  0.0;
    ff_tau(3) =  0.0;
    ff_tau(4) =  0.0;
    ff_tau(5) = -6.0;
    ff_tau(6) =  0.0;

    // External Wrench acting on the end-effector, expressed in base link coordinates
    // Vereshchagin solver expects that external wrenches are expressed w.r.t. robot's base frame
    KDL::Vector f(10.0, 15.0, 0.0);
    KDL::Vector n(0.0, 0.0, 5.0);
    KDL::Wrench f_tool(f, n);
    KDL::Wrenches f_ext(ns);
    f_ext[ns - 1] = f_tool; //input

    /**
     * Definition of the Cartesian Acceleration Constraints imposed on the end-effector.
     * Note: the Vereshchagin solver expects that the input values in alpha parameters 
     * (unit constraint forces) are expressed w.r.t. robot's base frame. 
     * However, the acceleration energy setpoints, i.e. beta parameters, are expressed w.r.t. above
     * defined unit constraint forces. More specifically, each DOF (element) in beta parameter corresponds
     * to its respective DOF (column) of the unit constraint force matrix (alpha).
    */
    int number_of_constraints = 6;

    // Constraint Unit forces defined for the end-effector
    Jacobian alpha_unit_force(number_of_constraints);

    // Set directions in which the constraint force should work. Alpha in the solver
    Twist unit_force_x_l(
        Vector(1.0, 0.0, 0.0), 
        Vector(0.0, 0.0, 0.0));
    alpha_unit_force.setColumn(0, unit_force_x_l); // constraint active

    Twist unit_force_y_l(
        Vector(0.0, 1.0, 0.0),
        Vector(0.0, 0.0, 0.0));
    alpha_unit_force.setColumn(1, unit_force_y_l); // constraint active

    Twist unit_force_z_l(
        Vector(0.0, 0.0, 1.0),
        Vector(0.0, 0.0, 0.0));
    alpha_unit_force.setColumn(2, unit_force_z_l); // constraint active

    Twist unit_force_x_a(
        Vector(0.0, 0.0, 0.0),
        Vector(0.0, 0.0, 0.0));
    alpha_unit_force.setColumn(3, unit_force_x_a); // constraint diabled... In this direction, end-effector's motion is left to emerge naturally

    Twist unit_force_y_a(
        Vector(0.0, 0.0, 0.0),
        Vector(0.0, 0.0, 0.0));
    alpha_unit_force.setColumn(4, unit_force_y_a); // constraint diabled... In this direction, end-effector's motion is left to emerge naturally

    Twist unit_force_z_a(
        Vector(0.0, 0.0, 0.0),
        Vector(0.0, 0.0, 1.0));
    alpha_unit_force.setColumn(5, unit_force_z_a); // constraint active

    // Acceleration energy for the end-effector.
    JntArray beta_energy(number_of_constraints);
    beta_energy(0) = -0.5;
    beta_energy(1) = -0.5;
    beta_energy(2) =  0.0;
    beta_energy(3) =  0.0; // this value has no impact on computations, since its corresponding constraint is disabled
    beta_energy(4) =  0.0; // this value has no impact on computations, since its corresponding constraint is disabled
    beta_energy(5) =  0.2;

    // Arm root acceleration (robot's base mounted on an even surface)
    // Note: Vereshchagin solver takes root acc. with opposite sign comparead to the KDL's FD and RNE solvers
    Twist root_Acc(Vector(0.0, 0.0, 9.81), Vector(0.0, 0.0, 0.0));

    ChainHdSolver_Vereshchagin vereshchaginSolver(kukaLWR, root_Acc, number_of_constraints);
    solver_return = vereshchaginSolver.CartToJnt(q, qd, qdd, alpha_unit_force, beta_energy, f_ext, ff_tau, constraint_tau);
    if (solver_return < 0) std::cout << "KDL: Vereshchagin solver ERROR: " << solver_return << std::endl;

    // ########################################################################################
    // Final comparison of the _resultant_ end-effector's Cartesian accelerations
    // and the task-specified acceleration constraints

    // Number of frames on the robot = ns + 1
    std::vector<Twist> xDotdot(ns + 1);
    // This solver's function returns Cartesian accelerations of links in robot base coordinates
    vereshchaginSolver.getTransformedLinkAcceleration(xDotdot);
    CPPUNIT_ASSERT(Equal(beta_energy(0), xDotdot[ns].vel(0), eps));
    CPPUNIT_ASSERT(Equal(beta_energy(1), xDotdot[ns].vel(1), eps));
    CPPUNIT_ASSERT(Equal(beta_energy(2), xDotdot[ns].vel(2), eps));
    CPPUNIT_ASSERT(Equal(beta_energy(5), xDotdot[ns].rot(2), eps));

    // Additional getters for the intermediate solver's outputs: Useful for state- simulation and estimation purposes
    // Magnitude of the constraint forces acting on the end-effector: Lagrange Multiplier
    Eigen::VectorXd nu(number_of_constraints);
    vereshchaginSolver.getContraintForceMagnitude(nu);
    CPPUNIT_ASSERT(Equal(nu(0), 669693.30355, eps));
    CPPUNIT_ASSERT(Equal(nu(1), 5930.60826, eps));
    CPPUNIT_ASSERT(Equal(nu(2), -639.5238, eps));
    CPPUNIT_ASSERT(Equal(nu(3), 0.000, eps)); // constraint was not active in the task specification
    CPPUNIT_ASSERT(Equal(nu(4), 0.000, eps)); // constraint was not active in the task specification
    CPPUNIT_ASSERT(Equal(nu(5), 573.90485, eps));

    // Total torque acting on each joint
    JntArray total_tau(nj);
    vereshchaginSolver.getTotalTorque(total_tau);
    CPPUNIT_ASSERT(Equal(total_tau(0), 2013.3541, eps));
    CPPUNIT_ASSERT(Equal(total_tau(1), -6073.4999, eps));
    CPPUNIT_ASSERT(Equal(total_tau(2), 2227.4487, eps));
    CPPUNIT_ASSERT(Equal(total_tau(3), 56.87456, eps));
    CPPUNIT_ASSERT(Equal(total_tau(4), -11.3789, eps));
    CPPUNIT_ASSERT(Equal(total_tau(5), -6.05957, eps));
    CPPUNIT_ASSERT(Equal(total_tau(6), 569.0776, eps));

    // ########################################################################################
    // Vereshchagin solver test 2
    // ########################################################################################
    Vector constrainXLinear(1.0, 0.0, 0.0);
    Vector constrainXAngular(0.0, 0.0, 0.0);
    Vector constrainYLinear(0.0, 0.0, 0.0);
    Vector constrainYAngular(0.0, 0.0, 0.0);
    // Vector constrainZLinear(0.0, 0.0, 0.0);
    //Vector constrainZAngular(0.0, 0.0, 0.0);
    Twist constraintForcesX(constrainXLinear, constrainXAngular);
    Twist constraintForcesY(constrainYLinear, constrainYAngular);
    //Twist constraintForcesZ(constrainZLinear, constrainZAngular);
    Jacobian alpha(1);
    //alpha.setColumn(0, constraintForcesX);
    alpha.setColumn(0, constraintForcesX);
    //alpha.setColumn(0, constraintForcesZ);

    //Acceleration energy at  the end-effector
    JntArray betha(1); //set to zero
    betha(0) = 0.0;
    //betha(1) = 0.0;
    //betha(2) = 0.0;

    //arm root acceleration
    Vector linearAcc(0.0, 10, 0.0); //gravitational acceleration along Y
    Vector angularAcc(0.0, 0.0, 0.0);
    Twist twist1(linearAcc, angularAcc);

    //external forces on the arm
    Vector externalForce1(0.0, 0.0, 0.0);
    Vector externalTorque1(0.0, 0.0, 0.0);
    Vector externalForce2(0.0, 0.0, 0.0);
    Vector externalTorque2(0.0, 0.0, 0.0);
    Wrench externalNetForce1(externalForce1, externalTorque1);
    Wrench externalNetForce2(externalForce2, externalTorque2);
    Wrenches externalNetForce;
    externalNetForce.push_back(externalNetForce1);
    externalNetForce.push_back(externalNetForce2);
    //~Definition of constraints and external disturbances
    //-------------------------------------------------------------------------------------//


    //Definition of solver and initial configuration
    //-------------------------------------------------------------------------------------//
    int numberOfConstraints = 1;
    ChainHdSolver_Vereshchagin constraintSolver(chaindyn, twist1, numberOfConstraints);

    //These arrays of joint values contain actual and desired values
    //actual is generated by a solver and integrator
    //desired is given by an interpolator
    //error is the difference between desired-actual
    //in this test only the actual values are printed.
    const int k = 1;
    JntArray jointPoses[k];
    JntArray jointRates[k];
    JntArray jointAccelerations[k];
    JntArray jointFFTorques[k];
    JntArray jointConstraintTorques[k];
    for (int i = 0; i < k; i++)
    {
        JntArray jointValues(chaindyn.getNrOfJoints());
        jointPoses[i] = jointValues;
        jointRates[i] = jointValues;
        jointAccelerations[i] = jointValues;
        jointFFTorques[i] = jointValues;
        jointConstraintTorques[i] = jointValues;
    }

    // Initial arm position configuration/constraint
    JntArray jointInitialPose(chaindyn.getNrOfJoints());
    jointInitialPose(0) = 0.0; // initial joint0 pose
    jointInitialPose(1) = PI/6.0; //initial joint1 pose, negative in clockwise
    //j0=0.0, j1=pi/6.0 correspond to x = 0.2, y = -0.7464
    //j0=2*pi/3.0, j1=pi/4.0 correspond to x = 0.44992, y = 0.58636

    //actual
    jointPoses[0](0) = jointInitialPose(0);
    jointPoses[0](1) = jointInitialPose(1);

    //~Definition of solver and initial configuration
    //-------------------------------------------------------------------------------------//


    //Definition of process main loop
    //-------------------------------------------------------------------------------------//
    //Time required to complete the task move(frameinitialPose, framefinalPose)
    double taskTimeConstant = 0.1;
    double simulationTime = 1*taskTimeConstant;
    double timeDelta = 0.01;

    const std::string msg = "Assertion failed, check matrix and array sizes";

    for (double t = 0.0; t <=simulationTime; t = t + timeDelta)
    {
        CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NOERROR, constraintSolver.CartToJnt(jointPoses[0], jointRates[0], jointAccelerations[0], alpha, betha, externalNetForce, jointFFTorques[0], jointConstraintTorques[0]));

        //Integration(robot joint values for rates and poses; actual) at the given "instanteneous" interval for joint position and velocity.
        jointRates[0](0) = jointRates[0](0) + jointAccelerations[0](0) * timeDelta; //Euler Forward
        jointPoses[0](0) = jointPoses[0](0) + (jointRates[0](0) - jointAccelerations[0](0) * timeDelta / 2.0) * timeDelta; //Trapezoidal rule
        jointRates[0](1) = jointRates[0](1) + jointAccelerations[0](1) * timeDelta; //Euler Forward
        jointPoses[0](1) = jointPoses[0](1) + (jointRates[0](1) - jointAccelerations[0](1) * timeDelta / 2.0) * timeDelta;
        jointFFTorques[0] = jointConstraintTorques[0];
        //printf("time, j0_pose, j1_pose, j0_rate, j1_rate, j0_acc, j1_acc, j0_constraintTau, j1_constraintTau \n");
        printf("%f          %f      %f       %f     %f       %f      %f     %f      %f\n", t, jointPoses[0](0), jointPoses[0](1), jointRates[0](0), jointRates[0](1), jointAccelerations[0](0), jointAccelerations[0](1), jointConstraintTorques[0](0), jointConstraintTorques[0](1));
    }
}

void SolverTest::FkPosVectTest()
{
    ChainFkSolverPos_recursive fksolver1(chain1);
    std::vector<Frame> v_out(chain1.getNrOfSegments());
    
    JntArray q(chain1.getNrOfJoints());
    JntArray qdot(chain1.getNrOfJoints());

    for(unsigned int i=0; i<chain1.getNrOfJoints(); i++)
    {
        random(q(i));
        random(qdot(i));
    }
    Frame f_out;
    fksolver1.JntToCart(q,v_out);
    fksolver1.JntToCart(q,f_out);
     
    CPPUNIT_ASSERT(Equal(v_out[chain1.getNrOfSegments()-1],f_out,1e-5));
}

void SolverTest::FkVelVectTest()
{
    ChainFkSolverVel_recursive fksolver1(chain1);
    std::vector<FrameVel> v_out(chain1.getNrOfSegments());
    
    JntArray q(chain1.getNrOfJoints());
    JntArray qdot(chain1.getNrOfJoints());

    for(unsigned int i=0; i<chain1.getNrOfJoints(); i++)
    {
        random(q(i));
        random(qdot(i));
    }
    JntArrayVel qvel(q,qdot);
    FrameVel f_out;
    fksolver1.JntToCart(qvel,v_out);
    fksolver1.JntToCart(qvel,f_out);
    
    CPPUNIT_ASSERT(Equal(v_out[chain1.getNrOfSegments()-1],f_out,1e-5));
}

void SolverTest::FdSolverDevelopmentTest()
{
    int ret;
    double eps=1.e-3;

    std::cout<<"KDL FD Solver Development Test for Motoman SIA10"<<std::endl;

    //  NOTE:  This is prototype code for the KDL forward dynamics solver class
    //         based on the Recurse Newton Euler Method:  ChainFdSolver_RNE

    //  Dynamics Solver
    Vector gravity(0.0, 0.0, -9.81);  // base frame
    ChainDynParam DynSolver = KDL::ChainDynParam(motomansia10dyn, gravity);

    unsigned int nj = motomansia10dyn.getNrOfJoints();
    unsigned int ns = motomansia10dyn.getNrOfSegments();

    // Joint position, velocity, and acceleration
    JntArray q(nj);
    JntArray qd(nj);
    JntArray qdd(nj);

    //  random
    q(0) = 0.2;
    q(1) = 0.6;
    q(2) = 1.;
    q(3) = 0.5;
    q(4) = -1.4;
    q(5) = 0.3;
    q(6) = -0.8;

    qd(0) = 1.;
    qd(1) = -2.;
    qd(2) = 3.;
    qd(3) = -4.;
    qd(4) = 5.;
    qd(5) = -6.;
    qd(6) = 7.;

    // Validate FK
    ChainFkSolverPos_recursive fksolver(motomansia10dyn);
    Frame f_out;
    fksolver.JntToCart(q,f_out);
    CPPUNIT_ASSERT(Equal(-0.547, f_out.p(0), eps));
    CPPUNIT_ASSERT(Equal(-0.301, f_out.p(1), eps));
    CPPUNIT_ASSERT(Equal(0.924, f_out.p(2), eps));
    CPPUNIT_ASSERT(Equal(0.503, f_out.M(0,0), eps));
    CPPUNIT_ASSERT(Equal(0.286, f_out.M(0,1), eps));
    CPPUNIT_ASSERT(Equal(-0.816, f_out.M(0,2), eps));
    CPPUNIT_ASSERT(Equal(-0.859, f_out.M(1,0), eps));
    CPPUNIT_ASSERT(Equal(0.269, f_out.M(1,1), eps));
    CPPUNIT_ASSERT(Equal(-0.436, f_out.M(1,2), eps));
    CPPUNIT_ASSERT(Equal(0.095, f_out.M(2,0), eps));
    CPPUNIT_ASSERT(Equal(0.920, f_out.M(2,1), eps));
    CPPUNIT_ASSERT(Equal(0.381, f_out.M(2,2), eps));

    // Validate Jacobian
    ChainJntToJacSolver jacsolver(motomansia10dyn);
    Jacobian jac(nj);
    jacsolver.JntToJac(q, jac);
    double Jac[6][7] =
        {{0.301,-0.553,0.185,0.019,0.007,-0.086,0.},
        {-0.547,-0.112,-0.139,-0.376,-0.037,0.063,0.},
        {0.,-0.596,0.105,-0.342,-0.026,-0.113,0.},
        {0.,0.199,-0.553,0.788,-0.615,0.162,-0.816},
        {0.,-0.980,-0.112,-0.392,-0.536,-0.803,-0.436},
        {1.,0.,0.825,0.475,0.578,-0.573,0.381}};
    for ( unsigned int i=0; i<6; i++ ) {
        for ( unsigned int j=0; j<nj; j++ ) {
            CPPUNIT_ASSERT(Equal(jac(i,j), Jac[i][j], eps));
        }
    }

    // Return values
    JntArray taugrav(nj);
    JntArray taucor(nj);
    JntSpaceInertiaMatrix H(nj), Heff(nj);

    // Compute Dynamics (torque in N-m)
    ret = DynSolver.JntToGravity(q, taugrav);
    if (ret < 0) std::cout << "KDL: inverse dynamics ERROR: " << ret << std::endl;
    CPPUNIT_ASSERT(Equal(0.000, taugrav(0), eps));
    CPPUNIT_ASSERT(Equal(-36.672, taugrav(1), eps));
    CPPUNIT_ASSERT(Equal(4.315, taugrav(2), eps));
    CPPUNIT_ASSERT(Equal(-11.205, taugrav(3), eps));
    CPPUNIT_ASSERT(Equal(0.757, taugrav(4), eps));
    CPPUNIT_ASSERT(Equal(1.780, taugrav(5), eps));
    CPPUNIT_ASSERT(Equal(0.000, taugrav(6), eps));

    ret = DynSolver.JntToCoriolis(q, qd, taucor);
    if (ret < 0) std::cout << "KDL: inverse dynamics ERROR: " << ret << std::endl;
    CPPUNIT_ASSERT(Equal(-15.523, taucor(0), eps));
    CPPUNIT_ASSERT(Equal(24.250, taucor(1), eps));
    CPPUNIT_ASSERT(Equal(-6.862, taucor(2), eps));
    CPPUNIT_ASSERT(Equal(6.303, taucor(3), eps));
    CPPUNIT_ASSERT(Equal(0.110, taucor(4), eps));
    CPPUNIT_ASSERT(Equal(-4.898, taucor(5), eps));
    CPPUNIT_ASSERT(Equal(-0.249, taucor(6), eps));

    ret = DynSolver.JntToMass(q, H);
    if (ret < 0) std::cout << "KDL: inverse dynamics ERROR: " << ret << std::endl;
    double Hexp[7][7] =
        {{6.8687,-0.4333,0.4599,0.6892,0.0638,-0.0054,0.0381},
        {-0.4333,8.8324,-0.5922,0.7905,0.0003,-0.0242,0.0265},
        {0.4599,-0.5922,3.3496,-0.0253,0.1150,-0.0243,0.0814},
        {0.6892,0.7905,-0.0253,3.9623,-0.0201,0.0087,-0.0291},
        {0.0638,0.0003,0.1150,-0.0201,1.1234,0.0029,0.0955},
        {-0.0054,-0.0242,-0.0243,0.0087,0.0029,1.1425,0},
        {0.0381,0.0265,0.0814,-0.0291,0.0955,0,1.1000}};
    for ( unsigned int i=0; i<nj; i++ ) {
        for ( unsigned int j=0; j<nj; j++ ) {
            CPPUNIT_ASSERT(Equal(H(i,j), Hexp[i][j], eps));
        }
    }

    // Inverse Dynamics:
    //   T = H * qdd + Tcor + Tgrav - J^T * Fext
    // Forward Dynamics
    //   1. Call JntToMass from ChainDynParam to get H
    //   2. Call ID with qdd=0 to get T=Tcor+Tgrav+J^T*Fext
    //   3. Calculate qdd = H^-1 * T
    KDL::ChainIdSolver_RNE IdSolver = KDL::ChainIdSolver_RNE(motomansia10dyn, gravity);

    // In tool coordinates
    Vector f(10,-20,30) ;
    Vector n(3,-4,5) ;
    Wrench f_tool(f,n);
    // In local link coordinates
    Wrenches f_ext(ns);
    for(unsigned int i=0;i<ns;i++){
        SetToZero(f_ext[i]);
    }
    f_ext[ns-1]=f_tool;

    JntArray Tnoninertial(nj);
    JntArray jntarraynull(nj);
    SetToZero(jntarraynull);
    IdSolver.CartToJnt(q, qd, jntarraynull, f_ext, Tnoninertial);
    CPPUNIT_ASSERT(Equal(-21.252, Tnoninertial(0), eps));
    CPPUNIT_ASSERT(Equal(-37.933, Tnoninertial(1), eps));
    CPPUNIT_ASSERT(Equal(-2.497, Tnoninertial(2), eps));
    CPPUNIT_ASSERT(Equal(-15.289, Tnoninertial(3), eps));
    CPPUNIT_ASSERT(Equal(-4.646, Tnoninertial(4), eps));
    CPPUNIT_ASSERT(Equal(-9.201, Tnoninertial(5), eps));
    CPPUNIT_ASSERT(Equal(-5.249, Tnoninertial(6), eps));

    // get acceleration using inverse symmetric matrix times vector
    Eigen::MatrixXd H_eig(nj,nj), L(nj,nj);
    Eigen::VectorXd Tnon_eig(nj), D(nj), r(nj), acc_eig(nj);
    for(unsigned int i=0;i<nj;i++){
        Tnon_eig(i) =  -Tnoninertial(i);
        for(unsigned int j=0;j<nj;j++){
            H_eig(i,j) =  H(i,j);
        }
    }
    ldl_solver_eigen(H_eig, Tnon_eig, L, D, r, acc_eig);
    for(unsigned int i=0;i<nj;i++){
        qdd(i) = acc_eig(i);
    }
    CPPUNIT_ASSERT(Equal(2.998, qdd(0), eps));
    CPPUNIT_ASSERT(Equal(4.289, qdd(1), eps));
    CPPUNIT_ASSERT(Equal(0.946, qdd(2), eps));
    CPPUNIT_ASSERT(Equal(2.518, qdd(3), eps));
    CPPUNIT_ASSERT(Equal(3.530, qdd(4), eps));
    CPPUNIT_ASSERT(Equal(8.150, qdd(5), eps));
    CPPUNIT_ASSERT(Equal(4.254, qdd(6), eps));
}

void SolverTest::FdSolverConsistencyTest()
{
    int ret;
    double eps=1.e-3;

    std::cout<<"KDL FD Solver Consistency Test for Motoman SIA10"<<std::endl;

    //  NOTE:  Compute the forward and inverse dynamics and test for consistency

    //  Forward Dynamics Solver
    Vector gravity(0.0, 0.0, -9.81);  // base frame
    KDL::ChainFdSolver_RNE FdSolver = KDL::ChainFdSolver_RNE(motomansia10dyn, gravity);

    unsigned int nj = motomansia10dyn.getNrOfJoints();
    unsigned int ns = motomansia10dyn.getNrOfSegments();

    // Joint position, velocity, and acceleration
    KDL::JntArray q(nj);
    KDL::JntArray qd(nj);
    KDL::JntArray qdd(nj);
    KDL::JntArray tau(nj);

    //  random
    q(0) = 0.2;
    q(1) = 0.6;
    q(2) = 1.;
    q(3) = 0.5;
    q(4) = -1.4;
    q(5) = 0.3;
    q(6) = -0.8;

    qd(0) = 1.;
    qd(1) = -2.;
    qd(2) = 3.;
    qd(3) = -4.;
    qd(4) = 5.;
    qd(5) = -6.;
    qd(6) = 7.;

    // actuator torques
    tau(0) = 50.;
    tau(1) = -20.;
    tau(2) = 10.;
    tau(3) = 40.;
    tau(4) = -60.;
    tau(5) = 15.;
    tau(6) = -10.;

    KDL::Vector f(10,-20,30) ;
    KDL::Vector n(3,-4,5) ;
    KDL::Wrench f_tool(f,n);
    // In local link coordinates
    KDL::Wrenches f_ext(ns);
    for(unsigned int i=0;i<ns;i++){
        SetToZero(f_ext[i]);
    }
    f_ext[ns-1]=f_tool;

    // Call FD function
    ret = FdSolver.CartToJnt(q, qd, tau, f_ext, qdd);
    if (ret < 0) std::cout << "KDL: forward dynamics ERROR: " << ret << std::endl;
    CPPUNIT_ASSERT(Equal(9.486, qdd(0), eps));
    CPPUNIT_ASSERT(Equal(1.830, qdd(1), eps));
    CPPUNIT_ASSERT(Equal(4.726, qdd(2), eps));
    CPPUNIT_ASSERT(Equal(11.665, qdd(3), eps));
    CPPUNIT_ASSERT(Equal(-50.108, qdd(4), eps));
    CPPUNIT_ASSERT(Equal(21.403, qdd(5), eps));
    CPPUNIT_ASSERT(Equal(-0.381, qdd(6), eps));

    // Check against ID solver for consistency
    KDL::ChainIdSolver_RNE IdSolver = KDL::ChainIdSolver_RNE(motomansia10dyn, gravity);
    KDL::JntArray torque(nj);
    IdSolver.CartToJnt(q, qd, qdd, f_ext, torque);
    for ( unsigned int i=0; i<nj; i++ )
    {
        CPPUNIT_ASSERT(Equal(torque(i), tau(i), eps));
    }

    return;
}

void SolverTest::LDLdecompTest()
{
    std::cout<<"LDL Solver Test"<<std::endl;
    double eps=1.e-6;

    //  Given A and b, solve Ax=b for x, where A is a symmetric real matrix
    //  https://en.wikipedia.org/wiki/Cholesky_decomposition
    Eigen::MatrixXd A(3,3), Aout(3,3);
    Eigen::VectorXd b(3);
    Eigen::MatrixXd L(3,3), Lout(3,3);
    Eigen::VectorXd d(3), dout(3);
    Eigen::VectorXd x(3), xout(3);
    Eigen::VectorXd r(3);  // temp variable used internally by ldl solver
    Eigen::MatrixXd Dout(3,3);  // diagonal matrix

    // Given
    A <<  4, 12, -16,
         12, 37, -43,
        -16, -43, 98;
    b << 28, 117, 98;
    // Results to verify
    L <<  1, 0, 0,
          3, 1, 0,
          -4, 5, 1;
    d << 4, 1, 9;
    x << 3, 8, 5;

    ldl_solver_eigen(A, b, Lout, dout, r, xout);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            CPPUNIT_ASSERT(Equal(L(i,j), Lout(i,j), eps));
        }
    }

    Dout.setZero();
    for(int i=0;i<3;i++){
        Dout(i,i) = dout(i);
    }

    // Verify solution for x
    for(int i=0;i<3;i++){
        CPPUNIT_ASSERT(Equal(xout(i), x(i), eps));
    }

    // Test reconstruction of A from LDL^T decomposition
    Aout = Lout * Dout * Lout.transpose();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            CPPUNIT_ASSERT(Equal(A(i,j), Aout(i,j), eps));
        }
    }

    return;
}

void SolverTest::FdAndVereshchaginSolversConsistencyTest()
{
    int ret;
    double eps=1.e-3;
    ChainFkSolverPos_recursive fksolverpos(kukaLWR);
    Frame end_effector_pose;

    /**
     * Compute the forward dynamics (joint accelearitions given actuator torques) 
     * using both solvers and test for consistency
     */
    std::cout << "KDL FD (inverse-inertia version) and Vereshchagin Solvers Consistency Test for KUKA LWR 4 robot" << std::endl;

    // ########################################################################################
    // Experiment (common state) setup
    unsigned int nj = kukaLWR.getNrOfJoints();
    unsigned int ns = kukaLWR.getNrOfSegments();

    // Necessary test for the used robot model: KDL's implementation of the Vereshchagin solver 
    // can only work with the robot chains that have equal number of joints and segments
    CPPUNIT_ASSERT(Equal(nj, ns));

    // Joint position, velocity, acceleration and torques
    KDL::JntArray q(nj);
    KDL::JntArray qd(nj);
    KDL::JntArray qdd(nj);
    KDL::JntArray ff_tau(nj);

    // random input state
    q(0) = 1.0;
    q(1) = 0.0;
    q(2) = 0.0;
    q(3) = -1.57;
    q(4) = 0.0;
    q(5) = 1.57;
    q(6) = -0.8;

    qd(0) = 1.0;
    qd(1) = -2.0;
    qd(2) = 3.0;
    qd(3) = -4.0;
    qd(4) = 5.0;
    qd(5) = -6.0;
    qd(6) = 7.0;

    // actuator torques
    ff_tau(0) = 50.0;
    ff_tau(1) = -20.0;
    ff_tau(2) = 10.0;
    ff_tau(3) = 40.0;
    ff_tau(4) = -60.0;
    ff_tau(5) = 15.0;
    ff_tau(6) = -10.0;

    // External Wrench acting on the end-effector, expressed in local link coordinates
    KDL::Vector f(10.0, -20.0, 30.0);
    KDL::Vector n(3.0, -4.0, 5.0);
    KDL::Wrench f_tool(f, n);

    KDL::Wrenches f_ext(ns);
    for(unsigned int i=0 ;i<ns; i++)
        SetToZero(f_ext[i]);
    f_ext[ns - 1] = f_tool;

    // ########################################################################################
    // Forward Dynamics Solver (inverse-inertia version)
    Vector gravity(0.0, 0.0, -9.81);  // base frame (Robot base mounted on an even surface)
    KDL::ChainFdSolver_RNE FdSolver = KDL::ChainFdSolver_RNE(kukaLWR, gravity);

    // Call FD function
    ret = FdSolver.CartToJnt(q, qd, ff_tau, f_ext, qdd);
    if (ret < 0)
        std::cout << "KDL: forward dynamics ERROR: " << ret << std::endl;

    // #########################################################################################
    // Vereshchagin Hybrid Dynamics solver
    // When the Cartesian Acceleration Constraints are deactivated, the computations perfomed 
    // in the Vereshchagin solver are completely the same as the computations perfomed in 
    // the well-known FD Articulated Body Algorithm (ABA) developed by Featherstone 

    // Constraint Unit forces at the end-effector. Set to zero to deactivate all constraints
    int numberOfConstraints = 6;
    Jacobian alpha(numberOfConstraints);
    KDL::SetToZero(alpha);

    // Acceleration energy at the end-effector. Set to zero since all constraints are deactivated
    JntArray beta(numberOfConstraints); //set to zero
    KDL::SetToZero(beta);

    // Arm root acceleration (robot's base mounted on an even surface)
    // Note: Vereshchagin solver takes root acc. with opposite sign comparead to the above FD and RNE solvers
    Vector linearAcc(0.0, 0.0, 9.81); Vector angularAcc(0.0, 0.0, 0.0);
    Twist root_Acc(linearAcc, angularAcc);

    // Torques felt in robot's joints due to constrait forces acting on the end-effector
    JntArray constraint_tau(nj); // In this test, all elements of this array should result to zero
    JntArray q_dd_Ver(nj); // Resultant joint accelerations

    // External Wrench acting on the end-effector, this time expressed in base link coordinates
    // Vereshchagin solver expects that external wrenches are expressed w.r.t. robot's base frame
    fksolverpos.JntToCart(q, end_effector_pose, kukaLWR.getNrOfSegments());
    f_ext[ns - 1] = end_effector_pose.M * f_tool;

    ChainHdSolver_Vereshchagin constraintSolver(kukaLWR, root_Acc, numberOfConstraints);
    ret = constraintSolver.CartToJnt(q, qd, q_dd_Ver, alpha, beta, f_ext, ff_tau, constraint_tau);
    if (ret < 0)
        std::cout << "KDL: Vereshchagin solver ERROR: " << ret << std::endl;

    // ########################################################################################
    // Final comparison
    CPPUNIT_ASSERT(Equal(q_dd_Ver(0), qdd(0), eps));
    CPPUNIT_ASSERT(Equal(q_dd_Ver(1), qdd(1), eps));
    CPPUNIT_ASSERT(Equal(q_dd_Ver(2), qdd(2), eps));
    CPPUNIT_ASSERT(Equal(q_dd_Ver(3), qdd(3), eps));
    CPPUNIT_ASSERT(Equal(q_dd_Ver(4), qdd(4), eps));
    CPPUNIT_ASSERT(Equal(q_dd_Ver(5), qdd(5), eps));
    CPPUNIT_ASSERT(Equal(q_dd_Ver(6), qdd(6), eps));

    return;
}

void SolverTest::ExternalWrenchEstimatorTest()
{
    /**
     * Closed-loop test for the external wrench estimator class:
     * Simple controlled behaviour of the robot subjected to an external force is simulated.
     * The external wrench estimator is called in each iteration of the control loop 
     * so to converge to final wrench value.
     * In the end, estimated wrench is compared to the ground-truth values of the simulated wrench. 
     */
    std::cout << "KDL External Wrench Estimator Test" << std::endl;

    /**
     * This EPS has a slightly different purpose than the EPSes of the other solver-tests. While other EPSes are taking care of the differences that
     * originate from e.g. floating-number imprecisions, different compilers (or same compiler but different flags) used between different machines (OS), etc. 
     * The EPS specified bellow is there to cover those imperfections as well but, it's also there to
     * take into account the noise in estimated signals (the differences between estimated and ground-truth wrenches), caused by other computations in this test
     * (ones coming from the implemented controller and the dynamics simulator) not just those coming from the estimator itself.
     */
    double eps_wrench = 0.5, eps_torque = 0.3;
    int ret;
    unsigned int nj = kukaLWR.getNrOfJoints();
    unsigned int ns = kukaLWR.getNrOfSegments();
    CPPUNIT_ASSERT(Equal(nj, ns)); // Current implementation of the Vereshchagin solver can only work with chains that have equal number of joints and segments

    // Initialize state and control variables
    JntArray q(nj); // Current joint position
    JntArray qd(nj); // Current joint velocity
    JntArray qdd(nj); // Resultant joint accelerations
    JntArrayVel jnt_position_velocity(nj); // variable necessary for the FK vel solver
    JntArray jnt_array_zero(nj); // Zero joint input for RNE
    JntArray command_torque(nj); // Control torque to actuate the robot
    JntArray constraint_tau(nj); // It will result in zero in Vereshchagin for this test
    JntArray gravity_torque(nj); // Gravity torque computed by RNE
    JntArray ext_torque_reference(nj); // Ground-truth joint torques due to the external force applied on the end-effector
    JntArray ext_torque_estimated(nj); // Estimated joint torques
    Wrenches f_ext_base(ns); // External Wrenches acting on the end-effector, expressed in base-link coordinates
    Wrenches f_ext_zero(ns); // Zero Wrenches
    Wrench f_tool_estimated; // External Wrenches estimated by the momentum-observer
    Frame end_effector_pose;
    Frame desired_end_eff_pose;
    Jacobian jacobian_end_eff(nj);
    FrameVel end_eff_twist;
    FrameVel desired_end_eff_twist;
    Eigen::Matrix<double, 6, 1> end_eff_force; // variable necessary for the control
    Eigen::Matrix<double, 6, 1> end_eff_pos_error; // variable necessary for the control
    Eigen::Matrix<double, 6, 1> end_eff_vel_error; // variable necessary for the control

    // Arm root acceleration (robot's base mounted on an even surface)
    Vector linearAcc(0.0, 0.0, -9.81); Vector angularAcc(0.0, 0.0, 0.0);
    
    // Initialize kinematics solvers
    ChainFkSolverPos_recursive fksolverpos(kukaLWR);
    ChainFkSolverVel_recursive fksolvervel(kukaLWR);
    ChainJntToJacSolver jacobian_solver(kukaLWR);

    // RNE ID solver for control purposes
    KDL::ChainIdSolver_RNE IdSolver(kukaLWR, linearAcc);

    // Vereshchagin Hybrid Dynamics solver for simulation purposes
    int numberOfConstraints = 6;
    Jacobian alpha(numberOfConstraints); // Constraint Unit forces at the end-effector
    JntArray beta(numberOfConstraints); // Acceleration energy at the end-effector
    KDL::SetToZero(alpha); // Set to zero to deactivate all constraints
    KDL::SetToZero(beta); // Set to zero to deactivate all constraints
    Twist vereshchagin_root_Acc(-linearAcc, angularAcc); // Note: Vereshchagin solver takes root acc. with opposite sign comparead to the above FD and RNE solvers
    ChainHdSolver_Vereshchagin constraintSolver(kukaLWR, vereshchagin_root_Acc, numberOfConstraints);

    // External Wrench Estimator
    double sample_frequency = 1000.0; // Hz
    double estimation_gain  = 45.0;
    double filter_constant  = 0.5;
    ChainExternalWrenchEstimator extwrench_estimator(kukaLWR, linearAcc, sample_frequency, estimation_gain, filter_constant);

    // Prepare test cases
    std::vector<KDL::JntArray> jnt_pos;
    std::vector<KDL::Wrench> wrench_reference;

    // Intialize random generator
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis_force(-15.0, 15.0);
    std::uniform_real_distribution<> dis_moment(-0.9, 0.9);
    std::uniform_real_distribution<> dis_jnt_vel(-0.5, 0.5);

    // Set first test case
    q(0) = 1.0;
    q(1) = 0.0;
    q(2) = 0.0;
    q(3) = 4.71;
    q(4) = 0.0;
    q(5) = 1.57;
    q(6) = 5.48;
    jnt_pos.push_back(q);
    wrench_reference.push_back(Wrench(Vector(dis_force(gen), dis_force(gen), dis_force(gen)), Vector(0.0, 0.0, 0.0))); // Ground-truth external wrench acting on the end-effector expressed in local end-effector's frame

    // Set second test case
    q(0) = 2.96;
    q(1) = 1.02;
    q(2) = 6.15;
    q(3) = 1.61;
    q(4) = 0.22;
    q(5) = 0.17;
    q(6) = 0.01;
    jnt_pos.push_back(q);
    wrench_reference.push_back(Wrench(Vector(0.0, 0.0, 0.0), Vector(dis_moment(gen), dis_moment(gen), 0.0))); // expressed in local end-effector's frame

    // Set third test case
    q(0) = 1.12;
    q(1) = 0.66;
    q(2) = 6.15;
    q(3) = 4.09;
    q(4) = 1.64;
    q(5) = 0.12;
    q(6) = 0.01;
    jnt_pos.push_back(q);
    wrench_reference.push_back(Wrench(Vector(dis_force(gen), dis_force(gen), dis_force(gen)), Vector(dis_moment(gen), 0.0, dis_moment(gen)))); // expressed in local end-effector's frame

    // ##########################################################################################
    // Control and simulation
    // ##########################################################################################

    // Control gains for a simple PD controller
    double k_p = 1500.0; // Proportional
    double k_d = 300.0; // Derivative

    // Time required to complete the task
    double simulationTime = 0.4; // in seconds
    double timeDelta = 1.0 / sample_frequency; // unit of seconds

    // Iterate over test cases
    for (unsigned int i = 0; i < jnt_pos.size(); i++)
    {
        // Re-set control and simulation variables
        q = jnt_pos[i];
        qd(0) = dis_jnt_vel(gen);
        qd(1) = dis_jnt_vel(gen);
        qd(2) = dis_jnt_vel(gen);
        qd(3) = dis_jnt_vel(gen);
        qd(4) = dis_jnt_vel(gen);
        qd(5) = dis_jnt_vel(gen);
        qd(6) = dis_jnt_vel(gen);

        end_eff_force.setZero();
        end_eff_pos_error.setZero();
        end_eff_vel_error.setZero();
        f_ext_base = f_ext_zero;

        // Initialize the estimator
        extwrench_estimator.updateInternalDataStructures();
        extwrench_estimator.setInitialMomentum(q, qd); // sets the offset for future estimation (momentum calculation)

        // Set the desired Cartesian state
        fksolverpos.JntToCart(q, end_effector_pose);
        desired_end_eff_pose.p(0) = end_effector_pose.p(0) + 0.02;
        desired_end_eff_pose.p(1) = end_effector_pose.p(1) + 0.02;
        desired_end_eff_pose.p(2) = end_effector_pose.p(2) + 0.02;
        desired_end_eff_twist.p.v(0) = 0.0;
        desired_end_eff_twist.p.v(1) = 0.0;
        desired_end_eff_twist.p.v(2) = 0.0;

        for (double t = 0.0; t <= simulationTime; t = t + timeDelta)
        {
            ret = jacobian_solver.JntToJac(q, jacobian_end_eff);
            if (ret < 0)
            {
                std::cout << "Jacobian solver ERROR: " << ret << std::endl;
                break;
            }

            ret = fksolverpos.JntToCart(q, end_effector_pose);
            if (ret < 0)
            {
                std::cout << "FK pos solver ERROR: " << ret << std::endl;
                break;
            }

            jnt_position_velocity.q = q;
            jnt_position_velocity.qdot = qd;
            ret = fksolvervel.JntToCart(jnt_position_velocity, end_eff_twist);
            if (ret < 0)
            {
                std::cout << "FK vel solver ERROR: " << ret << std::endl;
                break;
            }

            end_eff_pos_error(0) = end_effector_pose.p(0) - desired_end_eff_pose.p(0);
            end_eff_pos_error(1) = end_effector_pose.p(1) - desired_end_eff_pose.p(1);
            end_eff_pos_error(2) = end_effector_pose.p(2) - desired_end_eff_pose.p(2);

            end_eff_vel_error(0) = end_eff_twist.p.v(0) - desired_end_eff_twist.p.v(0);
            end_eff_vel_error(1) = end_eff_twist.p.v(1) - desired_end_eff_twist.p.v(1);
            end_eff_vel_error(2) = end_eff_twist.p.v(2) - desired_end_eff_twist.p.v(2);

            end_eff_force = -end_eff_pos_error * k_p - end_eff_vel_error * k_d;

            // Compute gravity joint torques (hide external wrench from this dynamics calculation)
            ret = IdSolver.CartToJnt(q, jnt_array_zero, jnt_array_zero, f_ext_zero, gravity_torque);
            if (ret < 0)
            {
                std::cout << "KDL RNE solver ERROR: " << ret << std::endl;
                break;
            }

            // Compute joint control commands
            command_torque.data =  jacobian_end_eff.data.transpose() * end_eff_force;
            command_torque.data += gravity_torque.data;

            // Start simulating the external force
            if (t > 0.2) f_ext_base[ns - 1] = end_effector_pose.M * wrench_reference[i];

            // Compute resultant joint accelerations that simulate robot's behaviour, given the command torques (add external wrench in this dynamics calculation)
            ret = constraintSolver.CartToJnt(q, qd, qdd, alpha, beta, f_ext_base, command_torque, constraint_tau);
            if (ret < 0)
            {
                std::cout << "KDL Vereshchagin solver ERROR: " << ret << std::endl;
                break;
            }
            
            // State integration: integrate from model accelerations to next joint state (positions and velocities)
            qd.data = qd.data + qdd.data * timeDelta; // Euler Forward
            q.data = q.data + qd.data * timeDelta; // Symplectic Euler

            // Saturate integrated joint position for full circle crossing
            for (unsigned int j = 0; j < nj; j++)
            {
                q(j) = std::fmod(q(j), 360 * deg2rad);
                if (q(j) < 0.0) q(j) += 360 * deg2rad;
            }
            
            // Estimate external wrench
            extwrench_estimator.JntToExtWrench(q, qd, command_torque, f_tool_estimated);
        }

        // Inverse Force Kinematics
        Eigen::Matrix<double, 6, 1> wrench;
        wrench(0) = f_ext_base[ns - 1](0);
        wrench(1) = f_ext_base[ns - 1](1);
        wrench(2) = f_ext_base[ns - 1](2);
        wrench(3) = f_ext_base[ns - 1](3);
        wrench(4) = f_ext_base[ns - 1](4);
        wrench(5) = f_ext_base[ns - 1](5);
        ext_torque_reference.data = jacobian_end_eff.data.transpose() * wrench;

        // Get estimated joint torque 
        extwrench_estimator.getEstimatedJntTorque(ext_torque_estimated);

        // ##################################################################################
        // Final comparison
        // ##################################################################################
        CPPUNIT_ASSERT(Equal(f_tool_estimated(0), wrench_reference[i](0), eps_wrench));
        CPPUNIT_ASSERT(Equal(f_tool_estimated(1), wrench_reference[i](1), eps_wrench));
        CPPUNIT_ASSERT(Equal(f_tool_estimated(2), wrench_reference[i](2), eps_wrench));
        CPPUNIT_ASSERT(Equal(f_tool_estimated(3), wrench_reference[i](3), eps_wrench));
        CPPUNIT_ASSERT(Equal(f_tool_estimated(4), wrench_reference[i](4), eps_wrench));
        CPPUNIT_ASSERT(Equal(f_tool_estimated(5), wrench_reference[i](5), eps_wrench));

        CPPUNIT_ASSERT(Equal(ext_torque_estimated(0), ext_torque_reference(0), eps_torque));
        CPPUNIT_ASSERT(Equal(ext_torque_estimated(1), ext_torque_reference(1), eps_torque));
        CPPUNIT_ASSERT(Equal(ext_torque_estimated(2), ext_torque_reference(2), eps_torque));
        CPPUNIT_ASSERT(Equal(ext_torque_estimated(3), ext_torque_reference(3), eps_torque));
        CPPUNIT_ASSERT(Equal(ext_torque_estimated(4), ext_torque_reference(4), eps_torque));
        CPPUNIT_ASSERT(Equal(ext_torque_estimated(5), ext_torque_reference(5), eps_torque));
        CPPUNIT_ASSERT(Equal(ext_torque_estimated(6), ext_torque_reference(6), eps_torque));
    }

    return;
}
