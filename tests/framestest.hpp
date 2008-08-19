#ifndef FRAMES_TEST_HPP
#define FRAMES_TEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <frames.hpp>
#include <jntarray.hpp>

using namespace KDL;

class FramesTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( FramesTest);
    CPPUNIT_TEST(TestVector);
    CPPUNIT_TEST(TestTwist);
    CPPUNIT_TEST(TestWrench);
    CPPUNIT_TEST(TestRotation);
    CPPUNIT_TEST(TestFrame);
    CPPUNIT_TEST(TestJntArray);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void TestVector();
    void TestTwist();
    void TestWrench();
    void TestRotation();
    void TestFrame();
    void TestJntArray();

private:
    void TestVector2(Vector& v);
    void TestTwist2(Twist& t);
    void TestWrench2(Wrench& w);
    void TestRotation2(const Vector& v,double a,double b,double c);

};

#endif

