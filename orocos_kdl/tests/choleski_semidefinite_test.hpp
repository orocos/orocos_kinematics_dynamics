/*
 * choleski_semidefinite_test.hpp
 *
 *  Created on: Aug 23, 2012
 *      Author: wouter
 */

#ifndef CHOLESKI_SEMIDEFINITE_TEST_HPP_
#define CHOLESKI_SEMIDEFINITE_TEST_HPP_

#include <cppunit/extensions/HelperMacros.h>
#include <choleski_semidefinite.hpp>
#include <iostream>

using namespace KDL;

class CholeskiSemiDefiniteTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( CholeskiSemiDefiniteTest);
    CPPUNIT_TEST(CholeskiTest);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void CholeskiTest();
};

#endif /* CHOLESKI_SEMIDEFINITE_TEST_HPP_ */
