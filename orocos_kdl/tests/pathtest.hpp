#ifndef PATHTEST_HPP
#define PATHTEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <path_point.hpp>
#include <path_line.hpp>
#include <path_circle.hpp>
#include <path_composite.hpp>
#include <path_roundedcomposite.hpp>
#include <path_cyclic_closed.hpp>
#include <rotational_interpolation_sa.hpp>

class PathTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(PathTest);
    CPPUNIT_TEST(TestPathPoint);
    CPPUNIT_TEST(TestPathPoint_Clone);
    CPPUNIT_TEST(TestPathLine);
    CPPUNIT_TEST(TestPathLine_Clone);
    CPPUNIT_TEST(TestPathCircle);
    CPPUNIT_TEST(TestPathCircle_TooSmall);
    CPPUNIT_TEST(TestCircleCloneKeepsPathLength);
    CPPUNIT_TEST(TestCircleCloneEqualsOriginal);
    CPPUNIT_TEST(TestCircleCloneEqualsOriginalRotationLimited);
    CPPUNIT_TEST(TestCircleCloneEqualsOriginalOffOriginCenter);
    CPPUNIT_TEST(TestCircleWriteReadEqualsOriginalOffOriginCenter);
    CPPUNIT_TEST(TestPathComposite);
    CPPUNIT_TEST(TestPathComposite_Clone);
    CPPUNIT_TEST(TestPathRoundedComposite);
    CPPUNIT_TEST(TestPathCyclicClosed);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void TestPathPoint();
    void TestPathPoint_Clone();

    void TestPathLine();
    void TestPathLine_Clone();

    void TestPathCircle();
    void TestPathCircle_TooSmall();

    void TestCircleCloneKeepsPathLength();
    void TestCircleCloneEqualsOriginal();
    void TestCircleCloneEqualsOriginalRotationLimited();
    void TestCircleCloneEqualsOriginalOffOriginCenter();
    void TestCircleWriteReadEqualsOriginalOffOriginCenter();

    void TestPathComposite();
    void TestPathComposite_Clone();

    void TestPathRoundedComposite();

    void TestPathCyclicClosed();
};

#endif
