#ifndef PATHTEST_HPP
#define PATHTEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <path_circle.hpp>

class PathTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(PathTest);
    CPPUNIT_TEST(TestCircleCloneKeepsPathLength);
    CPPUNIT_TEST(TestCircleCloneEqualsOriginal);
    CPPUNIT_TEST(TestCircleCloneEqualsOriginalRotationLimited);
    CPPUNIT_TEST(TestCircleCloneEqualsOriginalOffOriginCenter);
    CPPUNIT_TEST(TestCircleWriteReadEqualsOriginalOffOriginCenter);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void TestCircleCloneKeepsPathLength();
    void TestCircleCloneEqualsOriginal();
    void TestCircleCloneEqualsOriginalRotationLimited();
    void TestCircleCloneEqualsOriginalOffOriginCenter();
    void TestCircleWriteReadEqualsOriginalOffOriginCenter();
};

#endif
