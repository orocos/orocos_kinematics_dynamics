/*
 * choleski_semidefinite_test.cpp
 *
 *  Created on: Aug 23, 2012
 *      Author: wouter
 */

#include "choleski_semidefinite_test.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION( CholeskiSemiDefiniteTest );

void CholeskiSemiDefiniteTest::setUp(){}
void CholeskiSemiDefiniteTest::tearDown(){}

void CholeskiSemiDefiniteTest::CholeskiTest()
{
	 MatrixXd m(3,3);
	 m(0,0) = 4;
	 m(1,0) = 2;
	 m(2,0) = -2;
	 m(0,1) = 2;
	 m(1,1) = 10;
	 m(2,1) = 2;
	 m(0,2) = -2;
	 m(1,2) = 2;
	 m(2,2) = 5;

	 MatrixXd output;
	 cholesky_semidefinite(m,output);
	 MatrixXd transpose = output.transpose();
	 MatrixXd result = output * transpose;

	 CPPUNIT_ASSERT(m == result);
}
