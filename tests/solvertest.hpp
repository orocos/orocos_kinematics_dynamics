#ifndef KDL_SOLVER_TEST_HPP
#define KDL_SOLVER_TEST_HPP

#include <cppunit/extensions/HelperMacros.h>

#include <chain.hpp>
#include <chainfksolverpos_recursive.hpp>
#include <chainfksolvervel_recursive.hpp>
#include <chainiksolvervel_pinv.hpp>
#include <chainiksolverpos_nr.hpp>
#include <chainjnttojacsolver.hpp>

using namespace KDL;

class SolverTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( SolverTest);
    CPPUNIT_TEST(FkPosAndJacTest );
    CPPUNIT_TEST(FkVelAndJacTest );
    CPPUNIT_TEST(FkVelAndIkVelTest );
    CPPUNIT_TEST(FkPosAndIkPosTest );
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp();
    void tearDown();
    
    void FkPosAndJacTest();
    void FkVelAndJacTest();
    void FkVelAndIkVelTest();
    void FkPosAndIkPosTest();

private:
    
    Chain chain;

    ChainFkSolverPos_recursive* fksolverpos;
    ChainJntToJacSolver* jacsolver;
    ChainFkSolverVel_recursive* fksolvervel;
    ChainIkSolverVel_pinv* iksolvervel;
    ChainIkSolverPos_NR* iksolverpos;
    
    
};
#endif

