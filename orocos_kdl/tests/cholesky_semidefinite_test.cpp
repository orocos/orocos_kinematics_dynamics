#include "cholesky_semidefinite_test.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION( CholeskySemiDefiniteTest );

void CholeskySemiDefiniteTest::setUp(){}
void CholeskySemiDefiniteTest::tearDown(){}

void CholeskySemiDefiniteTest::CholeskyTest()
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
	 int exit_value = cholesky_semidefinite(m,output);
	 CPPUNIT_ASSERT(exit_value == 0);
	 MatrixXd transpose = output.transpose();
	 MatrixXd result = output * transpose;
	 CPPUNIT_ASSERT(m == result);
}
