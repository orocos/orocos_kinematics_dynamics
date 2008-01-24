#include "solvertest.hpp"
#include <frames_io.hpp>
#include <framevel_io.hpp>
#include <kinfam_io.hpp>

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
}

void SolverTest::FkVelAndJacTest()
{
    ChainFkSolverVel_recursive fksolver1(chain1);
    ChainJntToJacSolver jacsolver1(chain1);
    FkVelAndJacLocal(chain1,fksolver1,jacsolver1);
    ChainFkSolverVel_recursive fksolver2(chain2);
    ChainJntToJacSolver jacsolver2(chain2);
    FkVelAndJacLocal(chain2,fksolver2,jacsolver2);
}

void SolverTest::FkVelAndIkVelTest()
{
    ChainFkSolverVel_recursive fksolver1(chain1);
    ChainIkSolverVel_pinv iksolver1(chain1);
    FkVelAndIkVelLocal(chain1,fksolver1,iksolver1);
    ChainFkSolverVel_recursive fksolver2(chain2);
    ChainIkSolverVel_pinv iksolver2(chain2);
    FkVelAndIkVelLocal(chain2,fksolver2,iksolver2);

}

void SolverTest::FkPosAndIkPosTest()
{
    ChainFkSolverPos_recursive fksolver1(chain1);
    ChainIkSolverVel_pinv iksolverv1(chain1);
    ChainIkSolverPos_NR iksolver1(chain1,fksolver1,iksolverv1);
    FkPosAndIkPosLocal(chain1,fksolver1,iksolver1);
    ChainFkSolverPos_recursive fksolver2(chain2);
    ChainIkSolverVel_pinv iksolverv2(chain2);
    ChainIkSolverPos_NR iksolver2(chain2,fksolver2,iksolverv2);
    FkPosAndIkPosLocal(chain2,fksolver2,iksolver2);
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
    CPPUNIT_ASSERT(0==iksolvervel.CartToJnt(qvel.q,cart.deriv(),qdot_solved));
    
    CPPUNIT_ASSERT_EQUAL(qvel.qdot,qdot_solved);
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
    CPPUNIT_ASSERT(0==iksolverpos.CartToJnt(q_init,F1,q_solved));
    CPPUNIT_ASSERT(0==fksolverpos.JntToCart(q_solved,F2));
    
    CPPUNIT_ASSERT_EQUAL(F1,F2);
    CPPUNIT_ASSERT_EQUAL(q,q_solved);
}


