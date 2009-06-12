#ifndef INERTIA_TEST_HPP
#define INERTIA_TEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <rotationalinertia.hpp>
#include <rigidbodyinertia.hpp>

using namespace KDL;

class InertiaTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( InertiaTest);
    CPPUNIT_TEST(TestRotationalInertia);
    CPPUNIT_TEST(TestRigidBodyInertia);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void TestRotationalInertia();
    void TestRigidBodyInertia();

};

#endif
