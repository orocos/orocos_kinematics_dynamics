#include "solvertest.hpp"
#include <frames_io.hpp>
#include <framevel_io.hpp>
#include <kinfam_io.hpp>
#include <ctime>


CPPUNIT_TEST_SUITE_REGISTRATION( SolverTest );

using namespace KDL;

void SolverTest::setUp()
{
    chain1.addSegment(Segment(Joint(Joint::RotZ),
                             Frame(Vector(0.0,0.0,0.0))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                             Frame(Vector(0.0,0.0,0.9))));
    chain1.addSegment(Segment(Joint(Joint::None),
                             Frame(Vector(-0.4,0.0,0.0))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                             Frame(Vector(0.0,0.0,1.2))));
    chain1.addSegment(Segment(Joint(Joint::None),
                             Frame(Vector(0.4,0.0,0.0))));
    chain1.addSegment(Segment(Joint(Joint::RotZ),
                             Frame(Vector(0.0,0.0,1.4))));
    chain1.addSegment(Segment(Joint(Joint::RotX),
                             Frame(Vector(0.0,0.0,0.0))));
    chain1.addSegment(Segment(Joint(Joint::RotZ),
                             Frame(Vector(0.0,0.0,0.4))));
    chain1.addSegment(Segment(Joint(Joint::None),
                             Frame(Vector(0.0,0.0,0.0))));

    chain2.addSegment(Segment(Joint(Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.5))));
    chain2.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,0.4))));
    chain2.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,0.3))));
    chain2.addSegment(Segment(Joint(Joint::RotX),
                              Frame(Vector(0.0,0.0,0.2))));
    chain2.addSegment(Segment(Joint(Joint::RotZ),
                              Frame(Vector(0.0,0.0,0.1))));


    chain3.addSegment(Segment(Joint(Joint::RotZ),
                             Frame(Vector(0.0,0.0,0.0))));
    chain3.addSegment(Segment(Joint(Joint::RotX),
                             Frame(Vector(0.0,0.0,0.9))));
    chain3.addSegment(Segment(Joint(Joint::RotZ),
                             Frame(Vector(-0.4,0.0,0.0))));
    chain3.addSegment(Segment(Joint(Joint::RotX),
                             Frame(Vector(0.0,0.0,1.2))));
    chain3.addSegment(Segment(Joint(Joint::None),
                             Frame(Vector(0.4,0.0,0.0))));
    chain3.addSegment(Segment(Joint(Joint::RotZ),
                             Frame(Vector(0.0,0.0,1.4))));
    chain3.addSegment(Segment(Joint(Joint::RotX),
                             Frame(Vector(0.0,0.0,0.0))));
    chain3.addSegment(Segment(Joint(Joint::RotZ),
                             Frame(Vector(0.0,0.0,0.4))));
    chain3.addSegment(Segment(Joint(Joint::RotY),
                             Frame(Vector(0.0,0.0,0.0))));

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
}

void SolverTest::FkVelAndIkVelTest()
{
    //Chain1
    //std::cout<<"square problem"<<std::endl;
    ChainFkSolverVel_recursive fksolver1(chain1);
    ChainIkSolverVel_pinv iksolver1(chain1);
    ChainIkSolverVel_pinv_boost_givens iksolver_pinv_boost_givens1(chain1);
    //std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkVelAndIkVelLocal(chain1,fksolver1,iksolver1);
    //std::cout<<"KDL-Boost-SVD-Givens"<<std::endl;
    FkVelAndIkVelLocal(chain1,fksolver1,iksolver_pinv_boost_givens1);

    //Chain2
    //std::cout<<"underdetermined problem"<<std::endl;
    ChainFkSolverVel_recursive fksolver2(chain2);
    ChainIkSolverVel_pinv iksolver2(chain2);
    ChainIkSolverVel_pinv_boost_givens iksolver_pinv_boost_givens2(chain2);
    //std::cout<<"KDL-SVD-HouseHolder"<<std::endl;
    FkVelAndIkVelLocal(chain2,fksolver2,iksolver2);
    //std::cout<<"KDL-Boost-SVD-Givens"<<std::endl;
    FkVelAndIkVelLocal(chain2,fksolver2,iksolver_pinv_boost_givens2);

    //Chain3
    //std::cout<<"overdetermined problem"<<std::endl;
    ChainFkSolverVel_recursive fksolver3(chain3);
    ChainIkSolverVel_pinv iksolver3(chain3);
    ChainIkSolverVel_pinv_boost_givens iksolver_pinv_boost_givens3(chain3);
    FkVelAndIkVelLocal(chain3,fksolver3,iksolver3);
    //std::cout<<"KDL-Boost-SVD-Givens"<<std::endl;
    FkVelAndIkVelLocal(chain3,fksolver3,iksolver_pinv_boost_givens3);

}

void SolverTest::FkPosAndIkPosTest()
{
    ChainFkSolverPos_recursive fksolver1(chain1);
    ChainIkSolverVel_pinv iksolver1v(chain1);
    ChainIkSolverVel_pinv_boost_givens iksolverv_pinv_boost_givens1(chain1);
    ChainIkSolverPos_NR iksolver1(chain1,fksolver1,iksolver1v);
    ChainIkSolverPos_NR iksolver1_givens(chain1,fksolver1,iksolverv_pinv_boost_givens1);

    FkPosAndIkPosLocal(chain1,fksolver1,iksolver1);
    FkPosAndIkPosLocal(chain1,fksolver1,iksolver1_givens);

    ChainFkSolverPos_recursive fksolver2(chain2);
    ChainIkSolverVel_pinv iksolverv2(chain2);
    ChainIkSolverVel_pinv_boost_givens iksolverv_pinv_boost_givens2(chain2);
    ChainIkSolverPos_NR iksolver2(chain2,fksolver2,iksolverv2);
    ChainIkSolverPos_NR iksolver2_givens(chain2,fksolver2,iksolverv_pinv_boost_givens2);

    FkPosAndIkPosLocal(chain2,fksolver2,iksolver2);
    FkPosAndIkPosLocal(chain2,fksolver2,iksolver2_givens);


    ChainFkSolverPos_recursive fksolver3(chain3);
    ChainIkSolverVel_pinv iksolverv3(chain3);
    ChainIkSolverVel_pinv_boost_givens iksolverv_pinv_boost_givens3(chain3);
    ChainIkSolverPos_NR iksolver3(chain3,fksolver3,iksolverv3);
    ChainIkSolverPos_NR iksolver3_givens(chain3,fksolver3,iksolverv_pinv_boost_givens3);

    FkPosAndIkPosLocal(chain3,fksolver3,iksolver3);
    FkPosAndIkPosLocal(chain3,fksolver3,iksolver3_givens);

}



void SolverTest::FkPosAndJacLocal(Chain& chain,ChainFkSolverPos& fksolverpos,ChainJntToJacSolver& jacsolver)
{
    double deltaq = 1E-4;
    double epsJ   = 1E-4;

    Frame F1,F2;

    JntArray q(chain.getNrOfJoints());
    Jacobian jac(chain.getNrOfJoints());

    for(unsigned int i=0;i<chain.getNrOfJoints();i++){
        random(q(i));
    }

    jacsolver.JntToJac(q,jac);

    for (int i=0; i< q.rows() ;i++) {
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

    for(unsigned int i=0;i<chain.getNrOfJoints();i++){
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
    for(unsigned int i=0;i<chain.getNrOfJoints();i++){
        random(q(i));
        random(qdot(i));
    }
    JntArrayVel qvel(q,qdot);
    JntArray qdot_solved(chain.getNrOfJoints());

    FrameVel cart;

    CPPUNIT_ASSERT(0==fksolvervel.JntToCart(qvel,cart));
    for(unsigned int i=0;i<1;i++){
        int ret = iksolvervel.CartToJnt(qvel.q,cart.deriv(),qdot_solved);
        CPPUNIT_ASSERT(0<=ret);
    }

    qvel.deriv()=qdot_solved;

    if(chain.getNrOfJoints()<=6)
        CPPUNIT_ASSERT(Equal(qvel.qdot,qdot_solved,1e-7));
    else{
        FrameVel cart_solved;
        CPPUNIT_ASSERT(0==fksolvervel.JntToCart(qvel,cart_solved));
        CPPUNIT_ASSERT(Equal(cart.deriv(),cart_solved.deriv(),1e-5));
    }

}



void SolverTest::FkPosAndIkPosLocal(Chain& chain,ChainFkSolverPos& fksolverpos, ChainIkSolverPos& iksolverpos)
{
    JntArray q(chain.getNrOfJoints());
    for(unsigned int i=0;i<chain.getNrOfJoints();i++){
        random(q(i));
    }
    JntArray q_init(chain.getNrOfJoints());
    double tmp;
    for(unsigned int i=0;i<chain.getNrOfJoints();i++){
        random(tmp);
        q_init(i)=q(i)+0.1*tmp;
    }
    JntArray q_solved(q);

    Frame F1,F2;

    CPPUNIT_ASSERT(0==fksolverpos.JntToCart(q,F1));
    int ret = iksolverpos.CartToJnt(q_init,F1,q_solved);
    CPPUNIT_ASSERT(0<=ret);
    CPPUNIT_ASSERT(0==fksolverpos.JntToCart(q_solved,F2));

    CPPUNIT_ASSERT_EQUAL(F1,F2);
    //CPPUNIT_ASSERT_EQUAL(q,q_solved);

}


