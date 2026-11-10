#ifndef TRAJECTORYTEST_HPP
#define TRAJECTORYTEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <trajectory_stationary.hpp>
#include <trajectory_segment.hpp>
#include <trajectory_composite.hpp>
#include <path_line.hpp>
#include <velocityprofile_trap.hpp>
#include <rotational_interpolation_sa.hpp>

class TraectoryTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TraectoryTest);
    CPPUNIT_TEST(TestTrajectoryStationary);
    CPPUNIT_TEST(TestTrajectoryStationary_Clone);
    CPPUNIT_TEST(TestTrajectorySegmentWithDuration);
    CPPUNIT_TEST(TestTrajectorySegmentWithoutDuration);
    CPPUNIT_TEST(TestTrajectorySegment_Clone);
    CPPUNIT_TEST(TestTrajectoryComposite);
    CPPUNIT_TEST(TestTrajectoryComposite_Destroy);
    CPPUNIT_TEST(TestTrajectoryComposite_Clone);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void TestTrajectoryStationary();
    void TestTrajectoryStationary_Clone();

    void TestTrajectorySegmentWithDuration();
    void TestTrajectorySegmentWithoutDuration();
    void TestTrajectorySegment_Clone();

    void TestTrajectoryComposite();
    void TestTrajectoryComposite_Destroy();
    void TestTrajectoryComposite_Clone();
};

#endif
