#ifndef CHOLESKY_SEMIDEFINITE_TEST_HPP_
#define CHOLESKY_SEMIDEFINITE_TEST_HPP_

#include <cppunit/extensions/HelperMacros.h>
#include "utilities/cholesky_semidefinite.hpp"
#include <iostream>

using namespace KDL;

class CholeskySemiDefiniteTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( CholeskySemiDefiniteTest);
    CPPUNIT_TEST(CholeskyTest);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void CholeskyTest();
};

#endif /* CHOLESKY_SEMIDEFINITE_TEST_HPP_ */
