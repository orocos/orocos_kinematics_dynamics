#ifndef FRAMES_CONSISTENCY_TEST_HPP
#define FRAMES_CONSISTENCY_TEST_HPP

#include <cppunit/extensions/HelperMacros.h>

/**
 * Pins the behaviour of every function of the frame core (frames, framevel,
 * frameacc and utility.h) against references that do not use KDL itself:
 * Eigen matrices, closed-form parameterizations, and finite differences of the
 * plain double operations for the Vel and Acc types.
 *
 * The suite is deterministic: every test method starts from srand(42).
 */
class FramesConsistencyTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(FramesConsistencyTest);
    CPPUNIT_TEST(TestDoubleTypesAgainstEigen);
    CPPUNIT_TEST(TestParameterizationRoundTrips);
    CPPUNIT_TEST(TestVelTypesByFiniteDifference);
    CPPUNIT_TEST(TestAccTypesByFiniteDifference);
    CPPUNIT_TEST(TestHelpers);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void TestDoubleTypesAgainstEigen();
    void TestParameterizationRoundTrips();
    void TestVelTypesByFiniteDifference();
    void TestAccTypesByFiniteDifference();
    void TestHelpers();
};

#endif
