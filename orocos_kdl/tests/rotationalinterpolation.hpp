#ifndef ROTATIONALINTERPOLATION_HPP
#define ROTATIONALINTERPOLATION_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <rotational_interpolation_sa.hpp>

class RotationalInterpolationTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(RotationalInterpolationTest);
    CPPUNIT_TEST(TestSingleAxis_Basic);
    CPPUNIT_TEST(TestSingleAxis_VelAcc);
    CPPUNIT_TEST(TestSingleAxis_NonIdentityStart);
    CPPUNIT_TEST(TestSingleAxis_Clone);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void TestSingleAxis_Basic();
    void TestSingleAxis_VelAcc();
    void TestSingleAxis_NonIdentityStart();
    void TestSingleAxis_Clone();
};

#endif
