#include "solvertest.hpp"
#include <frames_io.hpp>
#include <framevel_io.hpp>
#include <kinfam_io.hpp>
#include <time.h>


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
									Frame::DH_Craig1989(0.0, M_PI_2, 0.0, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, -M_PI_2, 0.36, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, M_PI_2, 0.0, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, -M_PI_2, 0.36, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, M_PI_2, 0.0, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame::DH_Craig1989(0.0, -M_PI_2, 0.0, 0.0)));
	motomansia10.addSegment(Segment(Joint(Joint::RotZ),
									Frame(Rotation::Identity(),Vector(0.0,0.0,0.155))));
}

void SolverTest::tearDown()
{
//     delete fksolverpos;
//     delete jacsolver;
//     delete fksolvervel;
//     delete iksolvervel;
//     delete iksolverpos;
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
	q(3) = -M_PI_2 ;
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
	q(3) = -M_PI_2 ;
	q(4) = 0. ;
	q(5) = 0. ;
	q(6) = 0. ;

	dF.M = KDL::Rotation::RPY(0.1, 0.1, 0.1) ;
	dF.p = KDL::Vector(0.01,0.01,0.01) ;

	CPPUNIT_ASSERT_EQUAL(0, fksolver.JntToCart(q,F));
	F_des = F * dF ;

	CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NO_CONVERGE,
                         iksolver1.CartToJnt(q,F_des,q_solved)); // no converge
	CPPUNIT_ASSERT_EQUAL((int)ChainIkSolverVel_pinv::E_CONVERGE_PINV_SINGULAR,
                         ikvelsolver1.getError());        	// truncated SV solution
	CPPUNIT_ASSERT_EQUAL((unsigned int)2,
                         ikvelsolver1.getNrZeroSigmas()) ;		//	2 singular values (jac pseudoinverse singular)

	std::cout<<"nonconvergence:  large displacement, low iterations"<<std::endl;

	q(0) = 0. ;
	q(1) = 0.5 ;
	q(2) = 0.4 ;
	q(3) = -M_PI_2 ;
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

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NO_CONVERGE,
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

    CPPUNIT_ASSERT_EQUAL(0, fksolver.JntToCart(q,F));
    F_des = F * dF ;

    CPPUNIT_ASSERT_EQUAL((int)SolverI::E_NO_CONVERGE,
                         iksolver1.CartToJnt(q,F_des,q_solved)); // no converge
    CPPUNIT_ASSERT_EQUAL((int)ChainIkSolverVel_pinv::E_CONVERGE_PINV_SINGULAR,
                         ikvelsolver1.getError());        	// truncated SV solution
    CPPUNIT_ASSERT_EQUAL((unsigned int)3,
                         ikvelsolver1.getNrZeroSigmas());
}


void SolverTest::IkVelSolverWDLSTest()
{
	int rc ;
	int maxiter = 30;
	double	eps = 0.1 ;
	double lambda = 0.1 ;
	double sigma_min ;

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
	q(3) = -M_PI_2 ;
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
    double epsJ   = 1E-4;

    Frame F1,F2;

    JntArray q(chain.getNrOfJoints());
    Jacobian jac(chain.getNrOfJoints());

    for(unsigned int i=0; i<chain.getNrOfJoints(); i++)
    {
        random(q(i));
    }

    jacsolver.JntToJac(q,jac);

    for (int i=0; i< q.rows() ; i++)
    {
        // test the derivative of J towards qi
        double oldqi = q(i);
        q(i) = oldqi+deltaq;
        CPPUNIT_ASSERT(0==fksolverpos.JntToCart(q,F2));
        q(i) = oldqi-deltaq;
        CPPUNIT_ASSERT(0==fksolverpos.JntToCart(q,F1));
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
    double deltaq = 1E-4;
    double epsJ   = 1E-4;

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
    CPPUNIT_ASSERT(fksolvervel.JntToCart(qvel,cart)==0);
    MultiplyJacobian(jac,qvel.qdot,t);
    CPPUNIT_ASSERT_EQUAL(cart.deriv(),t);
}

void SolverTest::FkVelAndIkVelLocal(Chain& chain, ChainFkSolverVel& fksolvervel, ChainIkSolverVel& iksolvervel)
{
    double epsJ   = 1E-7;

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

    CPPUNIT_ASSERT(0==fksolvervel.JntToCart(qvel,cart));

    int ret = iksolvervel.CartToJnt(qvel.q,cart.deriv(),qdot_solved);
    CPPUNIT_ASSERT(0<=ret);

    qvel.deriv()=qdot_solved;

    if(chain.getNrOfJoints()<=6)
        CPPUNIT_ASSERT(Equal(qvel.qdot,qdot_solved,1e-5));
    else
    {
        FrameVel cart_solved;
        CPPUNIT_ASSERT(0==fksolvervel.JntToCart(qvel,cart_solved));
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

    CPPUNIT_ASSERT(0==fksolverpos.JntToCart(q,F1));
    CPPUNIT_ASSERT(0==iksolverpos.CartToJnt(q_init,F1,q_solved));
    CPPUNIT_ASSERT(0==fksolverpos.JntToCart(q_solved,F2));

    CPPUNIT_ASSERT_EQUAL(F1,F2);
    //CPPUNIT_ASSERT_EQUAL(q,q_solved);

}


void SolverTest::VereshchaginTest()
{

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
    ChainIdSolver_Vereshchagin constraintSolver(chaindyn, twist1, numberOfConstraints);

    //These arrays of joint values contain actual and desired values
    //actual is generated by a solver and integrator
    //desired is given by an interpolator
    //error is the difference between desired-actual
    //in this test only the actual values are printed.
    const int k = 1;
    JntArray jointPoses[k];
    JntArray jointRates[k];
    JntArray jointAccelerations[k];
    JntArray jointTorques[k];
    for (int i = 0; i < k; i++)
    {
        JntArray jointValues(chaindyn.getNrOfJoints());
        jointPoses[i] = jointValues;
        jointRates[i] = jointValues;
        jointAccelerations[i] = jointValues;
        jointTorques[i] = jointValues;
    }

    // Initial arm position configuration/constraint
    JntArray jointInitialPose(chaindyn.getNrOfJoints());
    jointInitialPose(0) = 0.0; // initial joint0 pose
    jointInitialPose(1) = M_PI/6.0; //initial joint1 pose, negative in clockwise
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
    int status;

    const std::string msg = "Assertion failed, check matrix and array sizes";

    for (double t = 0.0; t <=simulationTime; t = t + timeDelta)
    {
        status = constraintSolver.CartToJnt(jointPoses[0], jointRates[0], jointAccelerations[0], alpha, betha, externalNetForce, jointTorques[0]);

        CPPUNIT_ASSERT((status == 0));
        if (status != 0)
        {
            std::cout << "Check matrix and array sizes. Something does not match " << std::endl;
            exit(1);
        }
        else
        {
            //Integration(robot joint values for rates and poses; actual) at the given "instanteneous" interval for joint position and velocity.
            jointRates[0](0) = jointRates[0](0) + jointAccelerations[0](0) * timeDelta; //Euler Forward
            jointPoses[0](0) = jointPoses[0](0) + (jointRates[0](0) - jointAccelerations[0](0) * timeDelta / 2.0) * timeDelta; //Trapezoidal rule
            jointRates[0](1) = jointRates[0](1) + jointAccelerations[0](1) * timeDelta; //Euler Forward
            jointPoses[0](1) = jointPoses[0](1) + (jointRates[0](1) - jointAccelerations[0](1) * timeDelta / 2.0) * timeDelta;
            //printf("time, j0_pose, j1_pose, j0_rate, j1_rate, j0_acc, j1_acc, j0_constraintTau, j1_constraintTau \n");
            printf("%f          %f      %f       %f     %f       %f      %f     %f      %f\n", t, jointPoses[0](0), jointPoses[0](1), jointRates[0](0), jointRates[0](1), jointAccelerations[0](0), jointAccelerations[0](1), jointTorques[0](0), jointTorques[0](1));
        }
    }
}
