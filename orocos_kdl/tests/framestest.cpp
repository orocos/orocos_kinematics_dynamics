#include "framestest.hpp"
#include <kdl/frames_io.hpp>
#include <kdl/utilities/utility.hpp>
#include <type_traits>
#include <cmath>
#include <functional>
#include <limits>
#include <kdl/config.hpp>

// KDL_VERSION must behave as one value in comparisons, both in #if and in C++
// expressions. Unparenthesised, `KDL_VERSION >= x` parses as
// `(MAJOR << 16) | (MINOR << 8) | (PATCH >= x)`, which is always true.
#define KDL_TEST_EXPECTED_VERSION ((KDL_VERSION_MAJOR << 16) | (KDL_VERSION_MINOR << 8) | KDL_VERSION_PATCH)
#if KDL_VERSION != KDL_TEST_EXPECTED_VERSION || KDL_VERSION >= ((KDL_VERSION_MAJOR + 1) << 16) \
    || KDL_VERSION < (KDL_VERSION_MAJOR << 16)
#error "KDL_VERSION does not compare as a single value"
#endif
static_assert((KDL_VERSION == KDL_TEST_EXPECTED_VERSION) == true, "KDL_VERSION == x must be a bool comparison");
static_assert(!(KDL_VERSION >= ((KDL_VERSION_MAJOR + 1) << 16)), "KDL_VERSION >= next major must be false");
static_assert(!(KDL_VERSION < (KDL_VERSION_MAJOR << 16)), "KDL_VERSION < this major must be false");
static_assert(KDL_VERSION_MAJOR != 2 || (KDL_VERSION >= 0x020000 && KDL_VERSION < 0x030000),
              "a 2.x release lies in [0x020000, 0x030000)");
#undef KDL_TEST_EXPECTED_VERSION

CPPUNIT_TEST_SUITE_REGISTRATION( FramesTest );

using namespace KDL;

void FramesTest::setUp()
{
}

void FramesTest::tearDown()
{
}

void FramesTest::TestVector2(Vector& v) {
    Vector   v2;
    CPPUNIT_ASSERT_EQUAL(2*v-v,v);
	CPPUNIT_ASSERT_EQUAL(v*2-v,v);
	CPPUNIT_ASSERT_EQUAL(v+v+v-2*v,v);
	v2=v;
	CPPUNIT_ASSERT_EQUAL(v,v2);
    CPPUNIT_ASSERT_EQUAL(std::hash<Vector>{}(v), std::hash<Vector>{}(v2));
	v2+=v;
	CPPUNIT_ASSERT_EQUAL(2*v,v2);
	v2-=v;
	CPPUNIT_ASSERT_EQUAL(v,v2);
	v2.ReverseSign();
	CPPUNIT_ASSERT_EQUAL(v,-v2);
}

void FramesTest::TestVector() {
 	Vector   v(3,4,5);
	TestVector2(v);
	Vector   v2(0,0,0);
	TestVector2(v2);

    CPPUNIT_ASSERT_EQUAL(std::hash<Vector>{}(v), static_cast<size_t>(3450679443808348711u));
    CPPUNIT_ASSERT_EQUAL(std::hash<Vector>{}(v2), static_cast<size_t>(11093822414574u));
	
	Vector nu(0,0,0);
	CPPUNIT_ASSERT_EQUAL(nu.Norm(),0.0);
	Vector nu2(10,0,0);
	CPPUNIT_ASSERT_EQUAL(nu2.Norm(),10.0);
}

void FramesTest::TestVector2DNorm() {
    Vector2 nu(0, 0);
	CPPUNIT_ASSERT_EQUAL(nu.Norm(), 0.0);
 	
	CPPUNIT_ASSERT_EQUAL(Vector2(1, 0).Norm(), 1.0);
	CPPUNIT_ASSERT_EQUAL(Vector2(0, 1).Norm(), 1.0);
	CPPUNIT_ASSERT_EQUAL(Vector2(-1, 0).Norm(), 1.0);
	CPPUNIT_ASSERT_EQUAL(Vector2(0, -1).Norm(), 1.0);
}

void FramesTest::TestTwist2(Twist& t) {
	Twist t2(Vector(16,-3,5),Vector(-4,2,1));

	CPPUNIT_ASSERT_EQUAL(2*t-t,t);
	CPPUNIT_ASSERT_EQUAL(t*2-t,t);
	CPPUNIT_ASSERT_EQUAL(t+t+t-2*t,t);
	t2=t;
	CPPUNIT_ASSERT_EQUAL(t,t2);
    CPPUNIT_ASSERT_EQUAL(std::hash<Twist>{}(t), std::hash<Twist>{}(t2));
	t2+=t;
	CPPUNIT_ASSERT_EQUAL(2*t,t2);
	t2-=t;
	CPPUNIT_ASSERT_EQUAL(t,t2);
    t2.ReverseSign();
	CPPUNIT_ASSERT_EQUAL(t,-t2);
}

void FramesTest::TestTwist() {
	Twist    t(Vector(6,3,5),Vector(4,-2,7));
	TestTwist2(t);
	Twist    t2(Vector(0,0,0),Vector(0,0,0));
	TestTwist2(t2);	
	Twist    t3(Vector(0,-9,-3),Vector(1,-2,-4));
	TestTwist2(t3);	

    CPPUNIT_ASSERT_EQUAL(std::hash<Twist>{}(t3), static_cast<size_t>(3373832976806748309u));
    CPPUNIT_ASSERT_EQUAL(std::hash<Twist>{}(t2), static_cast<size_t>(730713428471863u));
}

void FramesTest::TestWrench2(Wrench& w) {
	// Wrench
	Wrench   w2;	
	CPPUNIT_ASSERT_EQUAL(2*w-w,w);
	CPPUNIT_ASSERT_EQUAL(w*2-w,w);
	CPPUNIT_ASSERT_EQUAL(w+w+w-2*w,w);
	w2=w;
	CPPUNIT_ASSERT_EQUAL(w,w2);
    CPPUNIT_ASSERT_EQUAL(std::hash<Wrench>{}(w), std::hash<Wrench>{}(w2));
	w2+=w;
	CPPUNIT_ASSERT_EQUAL(2*w,w2);
	w2-=w;
	CPPUNIT_ASSERT_EQUAL(w,w2);
    w2.ReverseSign();
	CPPUNIT_ASSERT_EQUAL(w,-w2);
}

void FramesTest::TestWrench() {
	Wrench   w(Vector(7,-1,3),Vector(2,-3,3));
	TestWrench2(w);
	Wrench   w2(Vector(0,0,0),Vector(0,0,0));
	TestWrench2(w2);
	Wrench   w3(Vector(2,1,4),Vector(5,3,1));
    TestWrench2(w3);

    CPPUNIT_ASSERT_EQUAL(std::hash<Wrench>{}(w3), static_cast<size_t>(13897938943539516747u));
    CPPUNIT_ASSERT_EQUAL(std::hash<Wrench>{}(w2), static_cast<size_t>(730713428471863u));
}

void FramesTest::TestRotation2(const Vector& v,double a,double b,double c) {
	Vector   v2; 
	// Wrench
	Wrench   w(Vector(7,-1,3),Vector(2,-3,3));
	Twist    t(Vector(6,3,5),Vector(4,-2,7));
	// Rotation		
	Rotation R;
	Rotation R2;
	double ra;
	double rb;
	double rc;
    R = Rotation::RPY(a,b,c);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(dot(R.UnitX(),R.UnitX()),1.0,epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(dot(R.UnitY(),R.UnitY()),1.0,epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(dot(R.UnitZ(),R.UnitZ()),1.0,epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(dot(R.UnitX(),R.UnitY()),0.0,epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(dot(R.UnitX(),R.UnitZ()),0.0,epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(dot(R.UnitY(),R.UnitZ()),0.0,epsilon);
	R2=R;
	CPPUNIT_ASSERT_EQUAL(R,R2);
    CPPUNIT_ASSERT_EQUAL(std::hash<Rotation>{}(R), std::hash<Rotation>{}(R2));
	CPPUNIT_ASSERT_DOUBLES_EQUAL((R*v).Norm(),v.Norm(),epsilon);
	CPPUNIT_ASSERT(Equal(R.Inverse(R*v),v));
	CPPUNIT_ASSERT(Equal(R.Inverse(R*t),t));
	CPPUNIT_ASSERT(Equal(R.Inverse(R*w),w));
	CPPUNIT_ASSERT(Equal(R*R.Inverse(v),v));
	CPPUNIT_ASSERT_EQUAL(R*Rotation::Identity(),R);
	CPPUNIT_ASSERT_EQUAL(Rotation::Identity()*R,R);
	CPPUNIT_ASSERT(Equal(R*(R*(R*v)),(R*R*R)*v));
	CPPUNIT_ASSERT(Equal(R*(R*(R*t)),(R*R*R)*t));
	CPPUNIT_ASSERT(Equal(R*(R*(R*w)),(R*R*R)*w));
	CPPUNIT_ASSERT(Equal(R*R.Inverse(),Rotation::Identity()));
	CPPUNIT_ASSERT(Equal(R.Inverse()*R,Rotation::Identity()));
	CPPUNIT_ASSERT_EQUAL(R.Inverse()*v,R.Inverse(v));
	R.GetRPY(ra,rb,rc);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(ra,a,epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(rb,b,epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(rc,c,epsilon);
	R = Rotation::EulerZYX(a,b,c);
	R.GetEulerZYX(ra,rb,rc);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(ra,a,epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(rb,b,epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(rc,c,epsilon);
	R = Rotation::EulerZYZ(a,b,c);
	R.GetEulerZYZ(ra,rb,rc);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(ra,a,epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(rb,b,epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(rc,c,epsilon);
	double angle= R.GetRotAngle(v2);
	R2=Rotation::Rot2(v2,angle);
	CPPUNIT_ASSERT(Equal(R2,R));
	R2=Rotation::Rot(v2*1E20,angle);
	CPPUNIT_ASSERT(Equal(R,R2));
	v2=Vector(6,2,4);
	CPPUNIT_ASSERT_DOUBLES_EQUAL((v2).Norm(),::sqrt(dot(v2,v2)),epsilon);
}


// compare a rotation R with the expected angle and axis
void FramesTest::TestOneRotation(const std::string& msg,
								 const KDL::Rotation& R,
								 const double expectedAngle,
								 const KDL::Vector& expectedAxis)
{
	double 		angle =0;
	Vector		axis;

	angle = R.GetRotAngle(axis);
	CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE(msg, expectedAngle, angle, epsilon);
	CPPUNIT_ASSERT_MESSAGE(msg, Equal(expectedAxis, axis));
	CPPUNIT_ASSERT_MESSAGE(msg, Equal(expectedAngle * expectedAxis, R.GetRot()));
	CPPUNIT_ASSERT_MESSAGE(msg, Equal(Rotation::Rot(axis, angle), R));
	(void)axis.Normalize();
	CPPUNIT_ASSERT_MESSAGE(msg, Equal(Rotation::Rot2(axis, angle), R));
}



void FramesTest::TestArbitraryRotation(const std::string& msg,
									   const KDL::Vector& v,
									   const double angle,
									   const double expectedAngle,
									   const KDL::Vector& expectedVector)
{
	std::stringstream	ss;
	ss << "rot(" << msg << "],(" << angle << ")";
	TestOneRotation(ss.str(), Rotation::Rot(v,angle*deg2rad), expectedAngle*deg2rad, expectedVector);
}


#define TESTEULERZYX(a,b,g) \
		{\
			double eps=1E-14;\
			Rotation R = Rotation::EulerZYX((a),(b),(g));\
			double alpha,beta,gamma;\
			R.GetEulerZYX(alpha,beta,gamma);\
			CPPUNIT_ASSERT_DOUBLES_EQUAL((a),alpha,eps);\
			CPPUNIT_ASSERT_DOUBLES_EQUAL((b),beta,eps);\
			CPPUNIT_ASSERT_DOUBLES_EQUAL((g),gamma,eps);\
		}

#define TESTEULERZYZ(a,b,g) \
		{\
			double eps=1E-14;\
			Rotation R = Rotation::EulerZYZ((a),(b),(g));\
			double alpha,beta,gamma;\
			R.GetEulerZYZ(alpha,beta,gamma);\
			CPPUNIT_ASSERT_DOUBLES_EQUAL((a),alpha,eps);\
			CPPUNIT_ASSERT_DOUBLES_EQUAL((b),beta,eps);\
			CPPUNIT_ASSERT_DOUBLES_EQUAL((g),gamma,eps);\
		}
#define TESTEULERZYX_INVARIANT(a,b,g,a2,b2,g2)\
		{\
			double eps=1E-14;\
			Rotation R1=Rotation::EulerZYX(a,b,g);\
			Rotation R2=Rotation::EulerZYX(a2,b2,g2);\
			CPPUNIT_ASSERT_DOUBLES_EQUAL(0,diff(R2,R1).Norm(),eps);\
		}
#define TESTEULERZYZ_INVARIANT(a,b,g,a2,b2,g2)\
		{\
			double eps=1E-14;\
			Rotation R1=Rotation::EulerZYZ(a,b,g);\
			Rotation R2=Rotation::EulerZYZ(a2,b2,g2);\
			CPPUNIT_ASSERT_DOUBLES_EQUAL(0,diff(R2,R1).Norm(),eps);\
		}
void FramesTest::TestEuler() {
	using namespace KDL;
	TESTEULERZYX(0.1,0.2,0.3)
	TESTEULERZYX(-0.1,0.2,0.3)
	TESTEULERZYX(0.1,-0.2,0.3)
	TESTEULERZYX(0.1,0.2,-0.3)
	TESTEULERZYX(0,0.2,0.3)
	TESTEULERZYX(0.1,0.2,0)
	TESTEULERZYX(0.1,0,0.3)
	TESTEULERZYX(0.1,0,0)
	TESTEULERZYX(0,0,0.3)
	TESTEULERZYX(0,0,0)
    TESTEULERZYX(0.3,0.999*PI_2,0.1)
	// if beta== +/- PI/2 => multiple solutions available, gamma will be chosen to be zero !
	// so we test with gamma==0 !
    TESTEULERZYX(0.3,0.9999999999*PI_2,0)
    TESTEULERZYX(0.3,0.99999999*PI_2,0)
    TESTEULERZYX(0.3,0.999999*PI_2,0)
    TESTEULERZYX(0.3,0.9999*PI_2,0)
    TESTEULERZYX(0.3,0.99*PI_2,0)
    //TESTEULERZYX(0.1,-PI_2,0.3)
    TESTEULERZYX(0,PI_2,0)

    TESTEULERZYX(0.3,-PI_2,0)
    TESTEULERZYX(0.3,-0.9999999999*PI_2,0)
    TESTEULERZYX(0.3,-0.99999999*PI_2,0)
    TESTEULERZYX(0.3,-0.999999*PI_2,0)
    TESTEULERZYX(0.3,-0.9999*PI_2,0)
    TESTEULERZYX(0.3,-0.99*PI_2,0)
    TESTEULERZYX(0,-PI_2,0)

	// extremes of the range:
    TESTEULERZYX(PI,-PI_2,0)
    TESTEULERZYX(-PI,-PI_2,0)
	TESTEULERZYX(PI,1,0)
	TESTEULERZYX(-PI,1,0)
    //TESTEULERZYX(0,-PI_2,PI)  gamma will be chosen zero
    //TESTEULERZYX(0,PI_2,-PI)  gamma will be chosen zero
	TESTEULERZYX(0,1,PI)

	TESTEULERZYZ(0.1,0.2,0.3)
	TESTEULERZYZ(-0.1,0.2,0.3)
	TESTEULERZYZ(0.1,0.9*PI,0.3)
	TESTEULERZYZ(0.1,0.2,-0.3)
	TESTEULERZYZ(0,0,0)
	TESTEULERZYZ(0,0,0)
	TESTEULERZYZ(0,0,0)
	TESTEULERZYZ(PI,0,0)
	TESTEULERZYZ(0,0.2,PI)
	TESTEULERZYZ(0.4,PI,0)
	TESTEULERZYZ(0,PI,0)
	TESTEULERZYZ(PI,PI,0)
    TESTEULERZYX(0.3,PI_2,0)
    TESTEULERZYZ(0.3,0.9999999999*PI_2,0)
    TESTEULERZYZ(0.3,0.99999999*PI_2,0)
    TESTEULERZYZ(0.3,0.999999*PI_2,0)
    TESTEULERZYZ(0.3,0.9999*PI_2,0)
    TESTEULERZYZ(0.3,0.99*PI_2,0)

	TESTEULERZYX_INVARIANT(0.1,0.2,0.3,   0.1+PI,  PI-0.2, 0.3+PI);
	TESTEULERZYX_INVARIANT(0.1,0.2,0.3,   0.1-PI,  PI-0.2, 0.3-PI);
	TESTEULERZYX_INVARIANT(0.1,0.2,0.3,   0.1-PI,  PI-0.2, 0.3+PI);
	TESTEULERZYX_INVARIANT(0.1,0.2,0.3,   0.1+PI,  PI-0.2, 0.3-PI);

	TESTEULERZYZ_INVARIANT(0.1,0.2,0.3,   0.1+PI,  -0.2, 0.3+PI);
	TESTEULERZYZ_INVARIANT(0.1,0.2,0.3,   0.1-PI,  -0.2, 0.3+PI);
	TESTEULERZYZ_INVARIANT(0.1,0.2,0.3,   0.1+PI,  -0.2, 0.3-PI);
	TESTEULERZYZ_INVARIANT(0.1,0.2,0.3,   0.1-PI,  -0.2, 0.3-PI);
}

void FramesTest::TestRangeArbitraryRotation(const std::string& msg,
											const KDL::Vector& v,
											const KDL::Vector& expectedVector)
{
	TestArbitraryRotation(msg, v, 0,     0, Vector(0,0,1));		// no rotation
	TestArbitraryRotation(msg, v, 45,   45, expectedVector);
	TestArbitraryRotation(msg, v, 90,   90, expectedVector);
	TestArbitraryRotation(msg, v, 179, 179, expectedVector);
//	TestArbitraryRotation(msg, v, 180, 180, expectedVector);	// sign VARIES by case because 180 degrees not
                                                                // full determined: it can return +/- the axis
                                                                // depending on what the original axis was.
                                                                // BOTH RESULTS ARE CORRECT.
	TestArbitraryRotation(msg, v, 181, 179, -expectedVector);	// >+180 rotation => <+180 + negative axis
	TestArbitraryRotation(msg, v, 270,  90, -expectedVector);
	TestArbitraryRotation(msg, v, 359,   1, -expectedVector);
	TestArbitraryRotation(msg, v, 360,   0, Vector(0,0,1));		// no rotation
	TestArbitraryRotation(msg, v, 361,   1, expectedVector);
	TestArbitraryRotation(msg, v, 450,  90, expectedVector);
	TestArbitraryRotation(msg, v, 539, 179, expectedVector);
//	TestArbitraryRotation(msg, v, 540, 180, expectedVector);	// see above 
	TestArbitraryRotation(msg, v, 541, 179, -expectedVector);	// like 181
	TestArbitraryRotation(msg, v, 630,  90, -expectedVector);	// like 270
	TestArbitraryRotation(msg, v, 719,   1, -expectedVector);	// like 259
	TestArbitraryRotation(msg, v, 720,   0, Vector(0,0,1));		// no rotation

	TestArbitraryRotation(msg, v, -45,   45, -expectedVector);
	TestArbitraryRotation(msg, v, -90,   90, -expectedVector);
	TestArbitraryRotation(msg, v, -179, 179, -expectedVector);
//	TestArbitraryRotation(msg, v, -180, 180, expectedVector);	// see above 
	TestArbitraryRotation(msg, v, -181, 179, expectedVector);
	TestArbitraryRotation(msg, v, -270,  90, expectedVector);
	TestArbitraryRotation(msg, v, -359,   1, expectedVector);
	TestArbitraryRotation(msg, v, -360,   0, Vector(0,0,1));	// no rotation
	TestArbitraryRotation(msg, v, -361,   1, -expectedVector);
	TestArbitraryRotation(msg, v, -450,  90, -expectedVector);
	TestArbitraryRotation(msg, v, -539, 179, -expectedVector);
//	TestArbitraryRotation(msg, v, -540, 180, -expectedVector);	// see above 
	TestArbitraryRotation(msg, v, -541, 179, expectedVector);
	TestArbitraryRotation(msg, v, -630,  90, expectedVector);
	TestArbitraryRotation(msg, v, -719,   1, expectedVector);
	TestArbitraryRotation(msg, v, -720,   0, Vector(0,0,1));	// no rotation
}

void FramesTest::TestRotation() {
	TestRotation2(Vector(3,4,5),10*deg2rad,20*deg2rad,30*deg2rad);

	// X axis
	TestRangeArbitraryRotation("[1,0,0]", Vector(1,0,0), Vector(1,0,0));
	TestRangeArbitraryRotation("[-1,0,0]", Vector(-1,0,0), Vector(-1,0,0));
	// Y axis
	TestRangeArbitraryRotation("[0,1,0]", Vector(0,1,0), Vector(0,1,0));
	TestRangeArbitraryRotation("[0,-1,0]", Vector(0,-1,0), Vector(0,-1,0));
	// Z axis
	TestRangeArbitraryRotation("[0,0,1]", Vector(0,0,1), Vector(0,0,1));
	TestRangeArbitraryRotation("[0,0,-1]", Vector(0,0,-1), Vector(0,0,-1));
	// X,Y axes
	TestRangeArbitraryRotation("[1,1,0]", Vector(1,1,0), Vector(1,1,0)/sqrt(2.0));
	TestRangeArbitraryRotation("[-1,-1,0]", Vector(-1,-1,0), Vector(-1,-1,0)/sqrt(2.0));
	// X,Z axes
	TestRangeArbitraryRotation("[1,0,1]", Vector(1,0,1), Vector(1,0,1)/sqrt(2.0));
	TestRangeArbitraryRotation("[-1,0,-1]", Vector(-1,0,-1), Vector(-1,0,-1)/sqrt(2.0));
	// Y,Z axes
	TestRangeArbitraryRotation("[0,1,1]", Vector(0,1,1), Vector(0,1,1)/sqrt(2.0));
	TestRangeArbitraryRotation("[0,-1,-1]", Vector(0,-1,-1), Vector(0,-1,-1)/sqrt(2.0));
	// X,Y,Z axes
	TestRangeArbitraryRotation("[1,1,1]", Vector(1,1,1), Vector(1,1,1)/sqrt(3.0));
	TestRangeArbitraryRotation("[-1,-1,-1]", Vector(-1,-1,-1), Vector(-1,-1,-1)/sqrt(3.0));

	// these change ... some of the -180 are the same as the +180, and some
	// results are the opposite sign.
	TestOneRotation("rot([1,0,0],180)", KDL::Rotation::Rot(KDL::Vector(1,0,0),180*deg2rad), 180*deg2rad, Vector(1,0,0));
	// same as +180
	TestOneRotation("rot([-1,0,0],180)", KDL::Rotation::Rot(KDL::Vector(-1,0,0),180*deg2rad), 180*deg2rad, Vector(1,0,0));
	TestOneRotation("rot([0,1,0],180)", KDL::Rotation::Rot(KDL::Vector(0,1,0),180*deg2rad), 180*deg2rad, Vector(0,1,0));
	// same as +180
	TestOneRotation("rot([0,-1,0],180)", KDL::Rotation::Rot(KDL::Vector(0,-1,0),180*deg2rad), 180*deg2rad, Vector(0,1,0));

	TestOneRotation("rot([0,0,1],180)", KDL::Rotation::Rot(KDL::Vector(0,0,1),180*deg2rad), 180*deg2rad, Vector(0,0,1));
	// same as +180
	TestOneRotation("rot([0,0,-1],180)", KDL::Rotation::Rot(KDL::Vector(0,0,-1),180*deg2rad), 180*deg2rad, Vector(0,0,1));

	TestOneRotation("rot([1,0,1],180)", KDL::Rotation::Rot(KDL::Vector(1,0,1),180*deg2rad), 180*deg2rad, Vector(1,0,1)/sqrt(2.0));
	// same as +180
	TestOneRotation("rot([1,0,1],-180)", KDL::Rotation::Rot(KDL::Vector(1,0,1),-180*deg2rad), 180*deg2rad, Vector(1,0,1)/sqrt(2.0));
	TestOneRotation("rot([-1,0,-1],180)", KDL::Rotation::Rot(KDL::Vector(-1,0,-1),180*deg2rad), 180*deg2rad, Vector(1,0,1)/sqrt(2.0));
	// same as +180
	TestOneRotation("rot([-1,0,-1],-180)", KDL::Rotation::Rot(KDL::Vector(-1,0,-1),-180*deg2rad), 180*deg2rad, Vector(1,0,1)/sqrt(2.0));

	TestOneRotation("rot([1,1,0],180)", KDL::Rotation::Rot(KDL::Vector(1,1,0),180*deg2rad), 180*deg2rad, Vector(1,1,0)/sqrt(2.0));
	// opposite of +180
	TestOneRotation("rot([1,1,0],-180)", KDL::Rotation::Rot(KDL::Vector(1,1,0),-180*deg2rad), 180*deg2rad, Vector(1,1,0)/sqrt(2.0));
	TestOneRotation("rot([-1,-1,0],180)", KDL::Rotation::Rot(KDL::Vector(-1,-1,0),180*deg2rad), 180*deg2rad, Vector(1,1,0)/sqrt(2.0));
	// opposite of +180
	TestOneRotation("rot([-1,-1,0],-180)", KDL::Rotation::Rot(KDL::Vector(-1,-1,0),-180*deg2rad), 180*deg2rad, Vector(1,1,0)/sqrt(2.0));

	TestOneRotation("rot([0,1,1],180)", KDL::Rotation::Rot(KDL::Vector(0,1,1),180*deg2rad), 180*deg2rad, Vector(0,1,1)/sqrt(2.0));
	// same as +180
	TestOneRotation("rot([0,1,1],-180)", KDL::Rotation::Rot(KDL::Vector(0,1,1),-180*deg2rad), 180*deg2rad, Vector(0,1,1)/sqrt(2.0));
	TestOneRotation("rot([0,-1,-1],180)", KDL::Rotation::Rot(KDL::Vector(0,-1,-1),180*deg2rad), 180*deg2rad, Vector(0,1,1)/sqrt(2.0));
	// same as +180
	TestOneRotation("rot([0,-1,-1],-180)", KDL::Rotation::Rot(KDL::Vector(0,-1,-1),-180*deg2rad), 180*deg2rad, Vector(0,1,1)/sqrt(2.0));

	TestOneRotation("rot([1,1,1],180)", KDL::Rotation::Rot(KDL::Vector(1,1,1),180*deg2rad), 180*deg2rad, Vector(1,1,1)/sqrt(3.0));
	// same as +180
	TestOneRotation("rot([1,1,1],-180)", KDL::Rotation::Rot(KDL::Vector(1,1,1),-180*deg2rad), 180*deg2rad, Vector(1,1,1)/sqrt(3.0));
	TestOneRotation("rot([-1,-1,-1],180)", KDL::Rotation::Rot(KDL::Vector(-1,-1,-1),180*deg2rad), 180*deg2rad, Vector(1,1,1)/sqrt(3.0));
	// same as +180
	TestOneRotation("rot([-1,-1,-1],-180)", KDL::Rotation::Rot(KDL::Vector(-1,-1,-1),-180*deg2rad), 180*deg2rad, Vector(1,1,1)/sqrt(3.0));

	TestOneRotation("rot([0.707107, 0, 0.707107", KDL::Rotation::RPY(-2.9811968953315162, -atan(1)*2, -0.1603957582582825), 180*deg2rad, Vector(0.707107,0,0.707107) );

    CPPUNIT_ASSERT_EQUAL(std::hash<Rotation>{}(Rotation::Quaternion(1, 0, 0, 0)), static_cast<size_t>(5526237894416316219u));
    CPPUNIT_ASSERT_EQUAL(std::hash<Rotation>{}(Rotation()), static_cast<size_t>(8386870752212395617u));
}

void FramesTest::TestGetRotAngle() {
    double roll = -2.9811968953315162;
    double pitch = -PI_2;
    double yaw = -0.1603957582582825;

    // rpy -> rotation
    KDL::Rotation kdlRotation1 = KDL::Rotation::RPY(roll, pitch, yaw);

    // rotation -> angle-axis (with KDL::GetRotAngle)
    KDL::Vector kdlAxis;
    double theta = kdlRotation1.GetRotAngle(kdlAxis);


    CPPUNIT_ASSERT(0==isnan(theta));
    CPPUNIT_ASSERT(0==isnan(kdlAxis[0]));
    CPPUNIT_ASSERT(0==isnan(kdlAxis[1]));
    CPPUNIT_ASSERT(0==isnan(kdlAxis[2]));

  // Test GetRotAngle on slightly non-orthogonal rotation matrices
  {
    Vector axis;
    double angle = KDL::Rotation( 1, 0, 0 + 1e-6, 0, 1, 0, 0, 0,  1 + 1e-6).GetRotAngle(axis);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("rot(NON-ORTHOGONAL, 0)", 0.0, angle, epsilon);
  }

  {
    Vector axis;
    double angle = KDL::Rotation(-1, 0, 0 + 1e-6, 0, 1, 0, 0, 0, -1 - 1e-6).GetRotAngle(axis);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("rot(NON-ORTHOGONAL, PI)", PI, angle, epsilon);
  }

  // Tests to show that GetRotAngle does not work for an improper rotation matrix which has a determinant of -1;
  // an improper rotation matrix corresponds to a rotation between a right-hand and left-hand coordinate system
  {
    Vector axis;
    double angle;
    Rotation R, Rout;
    double det;
    // Improper Rotation Matrix for 120 deg rotation
    R = KDL::Rotation( 0, -1, 0, 0, 0, -1, -1, 0, 0);
    det = +R(0,0)*(R(1,1)*R(2,2)-R(2,1)*R(1,2))-R(0,1)*(R(1,0)*R(2,2)-R(2,0)*R(1,2))+R(0,2)*(R(1,0)*R(2,1)-R(2,0)*R(1,1));
    CPPUNIT_ASSERT_EQUAL(det,-1.0);
    angle = R.GetRotAngle(axis);
    Rout = KDL::Rotation::Rot(axis, angle);
    CPPUNIT_ASSERT(!Equal(R,Rout));
    // Improper Rotation matrix for 180 deg rotation (singular)
    R = KDL::Rotation( -1, 0, 0, 0, -1, 0, 0, 0, -1);
    det = +R(0,0)*(R(1,1)*R(2,2)-R(2,1)*R(1,2))-R(0,1)*(R(1,0)*R(2,2)-R(2,0)*R(1,2))+R(0,2)*(R(1,0)*R(2,1)-R(2,0)*R(1,1));
    CPPUNIT_ASSERT_EQUAL(det,-1.0);
    angle = R.GetRotAngle(axis);
    Rout = KDL::Rotation::Rot(axis, angle);
    CPPUNIT_ASSERT(!Equal(R,Rout));
  }

}

void FramesTest::TestQuaternion() {
    Rotation    R;
    Rotation    R2;
    double      x,y,z,w;
    double      x2,y2,z2,w2;

    // identity R -> quat -> R2
    R.GetQuaternion(x,y,z,w);
    R2.Quaternion(x,y,z,w);
	CPPUNIT_ASSERT_EQUAL(R,R2);

    // 45 deg rotation in X
    R = Rotation::EulerZYX(0,0,45*deg2rad);
    R.GetQuaternion(x,y,z,w);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(x, sin((45*deg2rad)/2), epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(y, 0, epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(z, 0, epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(w, cos((45*deg2rad)/2), epsilon);
    R2 = Rotation::Quaternion(x,y,z,w);
	CPPUNIT_ASSERT(Equal(R,R2));

    // direct 45 deg rotation in X
    R2 = Rotation::Quaternion(sin((45*deg2rad)/2), 0, 0, cos((45*deg2rad)/2));
	CPPUNIT_ASSERT(Equal(R,R2));
    R2.GetQuaternion(x2,y2,z2,w2);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(x, x2, epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(y, y2, epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(z, z2, epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(w, w2, epsilon);
    
    // 45 deg rotation in X and in Z
    R = Rotation::EulerZYX(45*deg2rad,0,45*deg2rad);
    R.GetQuaternion(x,y,z,w);
    R2 = Rotation::Quaternion(x,y,z,w);
	CPPUNIT_ASSERT(Equal(R,R2));
    R2.GetQuaternion(x2,y2,z2,w2);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(x, x2, epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(y, y2, epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(z, z2, epsilon);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(w, w2, epsilon);
}

void FramesTest::TestOneRotationDiff(
        const std::string& msg,
        const Rotation& R_a_b1,
        const Rotation& R_a_b2,
        const Vector& expectedDiff) {
    CPPUNIT_ASSERT_MESSAGE(msg, Equal(diff(R_a_b1, R_a_b2), expectedDiff));
    CPPUNIT_ASSERT_MESSAGE(msg, Equal(addDelta(R_a_b1, expectedDiff), R_a_b2));
}

void FramesTest::TestRotationDiff() {

    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(0*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(0*deg2rad), Vector(0,0,0));		// no rotation
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(90*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(90*deg2rad), Vector(PI_2,0,0));
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(180*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(180*deg2rad), Vector(PI,0,0));
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(270*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(270*deg2rad), Vector(-PI_2,0,0));
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(360*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(360*deg2rad), Vector(0,0,0));		// no rotation
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(-360*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(-360*deg2rad), Vector(0,0,0));	// no rotation
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(-270*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(-270*deg2rad), Vector(PI_2,0,0));
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(-180*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(-180*deg2rad), Vector(PI,0,0));
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(-90*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(-90*deg2rad), Vector(-PI_2,0,0));
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotX(-0*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotX(-0*deg2rad), Vector(0,0,0));		// no rotation

    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(0*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(0*deg2rad), Vector(0,0,0));		// no rotation
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(90*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(90*deg2rad), Vector(0,PI_2,0));
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(180*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(180*deg2rad), Vector(0,PI,0));
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(270*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(270*deg2rad), Vector(0,-PI_2,0));
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(360*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(360*deg2rad), Vector(0,0,0));		// no rotation
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(-360*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(-360*deg2rad), Vector(0,0,0));	// no rotation
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(-270*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(-270*deg2rad), Vector(0,PI_2,0));
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(-180*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(-180*deg2rad), Vector(0,PI,0));
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(-90*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(-90*deg2rad), Vector(0,-PI_2,0));
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotY(-0*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotY(-0*deg2rad), Vector(0,0,0));		// no rotation

    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(0*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(0*deg2rad), Vector(0,0,0));		// no rotation
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(90*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(90*deg2rad), Vector(0,0,PI_2));
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(180*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(180*deg2rad), Vector(0,0,PI));
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(270*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(270*deg2rad), Vector(0,0,-PI_2));
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(360*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(360*deg2rad), Vector(0,0,0));		// no rotation
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(-360*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(-360*deg2rad), Vector(0,0,0));	// no rotation
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(-270*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(-270*deg2rad), Vector(0,0,PI_2));
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(-180*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(-180*deg2rad), Vector(0,0,PI));
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(-90*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(-90*deg2rad), Vector(0,0,-PI_2));
    TestOneRotationDiff("diff(RotZ(0*deg2rad),RotZ(-0*deg2rad))",
        Rotation::RotZ(0*deg2rad), Rotation::RotZ(-0*deg2rad), Vector(0,0,0));		// no rotation

    TestOneRotationDiff("diff(RotX(0*deg2rad),RotZ(90*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotZ(90*deg2rad), Vector(0,0,PI_2));
    TestOneRotationDiff("diff(RotX(0*deg2rad),RotY(90*deg2rad))",
        Rotation::RotX(0*deg2rad), Rotation::RotY(90*deg2rad), Vector(0,PI_2,0));
    TestOneRotationDiff("diff(RotY(0*deg2rad),RotZ(90*deg2rad))",
        Rotation::RotY(0*deg2rad), Rotation::RotZ(90*deg2rad), Vector(0,0,PI_2));

    TestOneRotationDiff("diff(Identity(),RotX(90*deg2rad))",
        Rotation::Identity(), Rotation::RotX(90*deg2rad), Vector(PI_2,0,0));
    TestOneRotationDiff("diff(Identity(),RotY(0*deg2rad))",
        Rotation::Identity(), Rotation::RotY(90*deg2rad), Vector(0,PI_2,0));
    TestOneRotationDiff("diff(Identity(),RotZ(0*deg2rad))",
        Rotation::Identity(), Rotation::RotZ(90*deg2rad), Vector(0,0,PI_2));

    TestOneRotationDiff("diff(Rotation::RPY(+0*deg2rad,0,-90*deg2rad),Rotation::RPY(-0*deg2rad,0,+90*deg2rad))",
        Rotation::RPY(+0*deg2rad,0,-90*deg2rad),
        Rotation::RPY(-0*deg2rad,0,+90*deg2rad),
        Vector(0,0,PI));
    TestOneRotationDiff("diff(Rotation::RPY(+5*deg2rad,0,-0*deg2rad),Rotation::RPY(-5*deg2rad,0,+0*deg2rad))",
        Rotation::RPY(+5*deg2rad,0,-0*deg2rad),
        Rotation::RPY(-5*deg2rad,0,+0*deg2rad),
        Vector(-10*deg2rad,0,0));

    KDL::Rotation R1 = Rotation::RPY(+5*deg2rad,0,-90*deg2rad);
    TestOneRotationDiff("diff(Rotation::RPY(+5*deg2rad,0,-90*deg2rad),Rotation::RPY(-5*deg2rad,0,+90*deg2rad))",
        R1, Rotation::RPY(-5*deg2rad,0,+90*deg2rad),
        R1*Vector(0, 0, 180*deg2rad));
}

void FramesTest::TestFrame() {
	Vector   v(3,4,5);
	Wrench   w(Vector(7,-1,3),Vector(2,-3,3)) ;
	Twist    t(Vector(6,3,5),Vector(4,-2,7)) ;
	Rotation R ;
	Frame F;
	Frame F2 ;
	F = Frame(Rotation::EulerZYX(10*deg2rad,20*deg2rad,-10*deg2rad),Vector(4,-2,1));
	F2=F   ;
	CPPUNIT_ASSERT_EQUAL(F,F2);
    CPPUNIT_ASSERT_EQUAL(std::hash<Frame>{}(F), std::hash<Frame>{}(F2));
	CPPUNIT_ASSERT(Equal(F.Inverse(F*v),v));
	CPPUNIT_ASSERT(Equal(F.Inverse(F*t),t));
	CPPUNIT_ASSERT(Equal(F.Inverse(F*w),w));
	CPPUNIT_ASSERT(Equal(F*F.Inverse(v),v));
	CPPUNIT_ASSERT(Equal(F*F.Inverse(t),t));
	CPPUNIT_ASSERT(Equal(F*F.Inverse(w),w));
	CPPUNIT_ASSERT_EQUAL(F*Frame::Identity(),F);
	CPPUNIT_ASSERT_EQUAL(Frame::Identity()*F,F);
	CPPUNIT_ASSERT(Equal(F*(F*(F*v)),(F*F*F)*v));
	CPPUNIT_ASSERT(Equal(F*(F*(F*t)),(F*F*F)*t));
	CPPUNIT_ASSERT(Equal(F*(F*(F*w)),(F*F*F)*w));
	CPPUNIT_ASSERT(Equal(F*F.Inverse(),Frame::Identity()));
	CPPUNIT_ASSERT(Equal(F.Inverse()*F,Frame::Identity()));
	CPPUNIT_ASSERT(Equal(F.Inverse()*v,F.Inverse(v)));

	// Denavit-Hartenberg
    Frame F_DH = Frame(Rotation(1, 0, 0,
                          0, 0, -1,
                          0, 1, 0),
                 Vector(0, 0, 0.36));
    CPPUNIT_ASSERT(Equal(Frame::DH(0.0, M_PI_2, 0.36, 0.0), F_DH));
    CPPUNIT_ASSERT(Equal(Frame().DH(0.0, M_PI_2, 0.36, 0.0), F_DH)); // Only for testing purposes, shouldn't use static function of instances

    Frame F_DH_Craig1989 = Frame(Rotation(1, 0, 0,
                                          0, 0, -1,
                                          0, 1, 0),
                                 Vector(0, -0.36, 0));
    CPPUNIT_ASSERT(Equal(Frame::DH_Craig1989(0.0, M_PI_2, 0.36, 0.0), F_DH_Craig1989));
    CPPUNIT_ASSERT(Equal(Frame().DH_Craig1989(0.0, M_PI_2, 0.36, 0.0), F_DH_Craig1989)); // Only for testing purposes, shouldn't use static function of instances

    CPPUNIT_ASSERT_EQUAL(std::hash<Frame>{}(F), static_cast<size_t>(6112004106257185417u));
    CPPUNIT_ASSERT_EQUAL(std::hash<Frame>{}(Frame()), static_cast<size_t>(8387572672274540708u));
}

JntArray CreateRandomJntArray(int size)
{
    JntArray j(size);
    for (int i = 0; i<size; ++i)
        random(j(i));
    return j;
}

void FramesTest::TestJntArray()
{
    JntArray random1 = CreateRandomJntArray(4);
    JntArray random1_copy(random1);
    CPPUNIT_ASSERT(Equal(random1_copy,random1));

    JntArray zero_set_to_zero(4);
    SetToZero(zero_set_to_zero);
    CPPUNIT_ASSERT(!Equal(random1,zero_set_to_zero));

    JntArray zero(4);
    CPPUNIT_ASSERT(Equal(zero_set_to_zero,zero));

    JntArray almost_zero = CreateRandomJntArray(4);
    almost_zero(0) = almost_zero(0)*1e-7;
    almost_zero(1) = almost_zero(1)*1e-7;
    almost_zero(2) = almost_zero(2)*1e-7;
    almost_zero(3) = almost_zero(3)*1e-7;

    // This should obviously be equal, but fails in old buggy implementation
    CPPUNIT_ASSERT(Equal(almost_zero,zero,1));
    CPPUNIT_ASSERT(Equal(almost_zero,zero,1e-6));
    CPPUNIT_ASSERT(!Equal(almost_zero,zero,1e-8));

    JntArray sum_random_zero(4);

    Add(random1,zero_set_to_zero,sum_random_zero);
    CPPUNIT_ASSERT(Equal(random1,sum_random_zero));

    JntArray add_subtract(4);
    JntArray random2 = CreateRandomJntArray(4);

    Add(random1,random2,add_subtract);
    Subtract(add_subtract,random2,add_subtract);
    CPPUNIT_ASSERT(Equal(random1,add_subtract));

    JntArray random_multiply_by_2(4);
    JntArray sum_random_same_random(4);
    Multiply(random1,2,random_multiply_by_2);
    Add(random1,random1,sum_random_same_random);
    CPPUNIT_ASSERT(Equal(sum_random_same_random,random_multiply_by_2));

    double a;
    random(a);

    JntArray random_multiply_devide(4);
    Multiply(random1,a,random_multiply_devide);
    Divide(random_multiply_devide,a,random_multiply_devide);
    CPPUNIT_ASSERT(Equal(random_multiply_devide,random1));
}

 
void FramesTest::TestJntArrayWhenEmpty()
{
    JntArray a1;
    JntArray a2;
    JntArray a3(a2);
    
 	// won't assert()
    CPPUNIT_ASSERT_EQUAL((unsigned int)0,a1.rows());
    CPPUNIT_ASSERT(Equal(a2,a1));
    
 	a2 = a1;
    CPPUNIT_ASSERT(Equal(a2,a1));
    
 	SetToZero(a2);
    CPPUNIT_ASSERT(Equal(a2,a1));
    
    Add(a1,a2,a3);
    CPPUNIT_ASSERT(Equal(a1,a3));
    
    Subtract(a1,a2,a3);
    CPPUNIT_ASSERT(Equal(a1,a3));
 	
    Multiply(a1,3.1,a3);
    CPPUNIT_ASSERT(Equal(a1,a3));
 	
    Divide(a1,3.1,a3);
    CPPUNIT_ASSERT(Equal(a1,a3));
 	
 	// MultiplyJacobian() - not tested here
    
    
 	/* will assert() - not tested here
       double j1 = a1(0);
 	*/	
    
 	// and now resize, and do just a few tests
    a1.resize(3);
    a2.resize(3);
    CPPUNIT_ASSERT_EQUAL((unsigned int)3,a1.rows());
    CPPUNIT_ASSERT(Equal(a2,a1));
    
    random(a1(0));
    random(a1(1));
    random(a1(2));
    a1 = a2;
    CPPUNIT_ASSERT(Equal(a1,a2));
    CPPUNIT_ASSERT_EQUAL(a1(1),a2(1));
    
    a3.resize(3);
    Subtract(a1,a2,a3);	// a3 = a2 - a1 = {0}
    SetToZero(a1);
    CPPUNIT_ASSERT(Equal(a1,a3));
}

// The value types are plain aggregates of doubles: user-written copy operations would make
// them non-trivially copyable, which costs register passing and memcpy in containers.
void FramesTest::TestTriviallyCopyable() {
    static_assert(std::is_trivially_copyable_v<Vector>, "Vector must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<Rotation>, "Rotation must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<Frame>, "Frame must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<Twist>, "Twist must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<Wrench>, "Wrench must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<Vector2>, "Vector2 must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<Rotation2>, "Rotation2 must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<Frame2>, "Frame2 must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<VectorVel>, "VectorVel must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<RotationVel>, "RotationVel must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<FrameVel>, "FrameVel must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<TwistVel>, "TwistVel must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<VectorAcc>, "VectorAcc must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<RotationAcc>, "RotationAcc must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<FrameAcc>, "FrameAcc must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<TwistAcc>, "TwistAcc must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<doubleVel>, "doubleVel must be trivially copyable");
    static_assert(std::is_trivially_copyable_v<doubleAcc>, "doubleAcc must be trivially copyable");
    // The asserts are compile-time; this keeps the test case from being empty.
    CPPUNIT_ASSERT(true);
}

// D4: Norm() returns 0 only for the exact zero vector, whichever component dominates, and keeps
// the overflow- and underflow-safe scaling.
void FramesTest::TestNormSmallVectors() {
    CPPUNIT_ASSERT_EQUAL(5e-7, Vector(5e-7,0,0).Norm());
    CPPUNIT_ASSERT_EQUAL(5e-7, Vector(0,5e-7,0).Norm());
    CPPUNIT_ASSERT_EQUAL(5e-7, Vector(0,0,5e-7).Norm());
    CPPUNIT_ASSERT_EQUAL(5e-7, Vector2(5e-7,0).Norm());
    CPPUNIT_ASSERT_EQUAL(0.0, Vector::Zero().Norm());
    CPPUNIT_ASSERT_EQUAL(1e-200, Vector(1e-200,0,0).Norm());                    // no underflow
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.4142135623730951e200, Vector(1e200,1e200,0).Norm(), 1e185); // no overflow

    CPPUNIT_ASSERT_EQUAL(0.0, Vector2(0,0).Norm());
    CPPUNIT_ASSERT_EQUAL(5e-7, Vector2(0,-5e-7).Norm());
    const double denorm = std::numeric_limits<double>::denorm_min();
    CPPUNIT_ASSERT_EQUAL(denorm, Vector(0,0,-denorm).Norm());                   // subnormal is not zero
    const doubleVel nv = VectorVel(Vector(5e-7,0,0), Vector(1,0,0)).Norm();
    CPPUNIT_ASSERT_EQUAL(5e-7, nv.t);
    CPPUNIT_ASSERT_EQUAL(1.0, nv.grad);
    const doubleVel nz = VectorVel(Vector::Zero(), Vector(1,0,0)).Norm();
    CPPUNIT_ASSERT_EQUAL(0.0, nz.t);
    CPPUNIT_ASSERT_EQUAL(0.0, nz.grad);
    const doubleAcc na = VectorAcc(Vector(5e-7,0,0), Vector(1,0,0), Vector(0,1,0)).Norm();
    CPPUNIT_ASSERT_EQUAL(5e-7, na.t);
    CPPUNIT_ASSERT_EQUAL(1.0, na.d);
}

// D3: Equal(a, b, eps) <=> a == b || (isfinite(a-b) && |a-b| <= eps * max(1, |a|, |b|)).
void FramesTest::TestEqualTolerance() {
    const double inf = std::numeric_limits<double>::infinity(), nan = std::numeric_limits<double>::quiet_NaN();
    CPPUNIT_ASSERT(Equal(1.0, 1.0, 0.0));
    CPPUNIT_ASSERT(!Equal(1.0, std::nextafter(1.0, 2.0), 0.0));
    CPPUNIT_ASSERT(Equal(inf, inf));   CPPUNIT_ASSERT(!Equal(inf, -inf));
    CPPUNIT_ASSERT(!Equal(inf, 1.0));  CPPUNIT_ASSERT(!Equal(nan, nan));
    CPPUNIT_ASSERT(Equal(0.0, 0.9e-6)); CPPUNIT_ASSERT(!Equal(0.0, 1.1e-6));    // absolute regime unchanged
    CPPUNIT_ASSERT(Equal(1e9, 1e9 + 900.0)); CPPUNIT_ASSERT(!Equal(1e9, 1e9 + 1100.0)); // relative above 1
    CPPUNIT_ASSERT(Equal(Vector(1e9,0,0), Vector(1e9+2e-6,0,0)));
    CPPUNIT_ASSERT(Equal(Vector(inf,0,0), Vector(inf,0,0)));
    CPPUNIT_ASSERT(!Equal(Vector(inf,0,0), Vector(inf,1,0)));                  // inf must not loosen other components
    static_assert(KDL::epsilon == 1e-6, "epsilon is a compile-time constant");

    // Edge cases of the scalar rule.
    const double big = std::numeric_limits<double>::max();
    const double denorm = std::numeric_limits<double>::denorm_min();
    CPPUNIT_ASSERT(Equal(0.0, -0.0, 0.0));
    CPPUNIT_ASSERT(Equal(-inf, -inf, 0.0));
    CPPUNIT_ASSERT(!Equal(nan, 1.0));  CPPUNIT_ASSERT(!Equal(1.0, nan, inf));
    CPPUNIT_ASSERT(!Equal(big, -big));                                          // a-b overflows: not equal
    CPPUNIT_ASSERT(Equal(big, std::nextafter(big, 0.0)));                       // relative at the top of the range
    CPPUNIT_ASSERT(Equal(denorm, 0.0)); CPPUNIT_ASSERT(!Equal(denorm, 0.0, 0.0));
    CPPUNIT_ASSERT(Equal(1.0, 1.0 + 1e-6));                                     // boundary is inclusive
    CPPUNIT_ASSERT(!Equal(1.0, 1.5, -1.0));                                     // negative eps: exact only
    CPPUNIT_ASSERT(Equal(1.0, 1.0, -1.0));

    // Edge cases of the per-quantity rule.
    CPPUNIT_ASSERT(Equal(Vector(1,2,3), Vector(1,2,3), 0.0));
    CPPUNIT_ASSERT(!Equal(Vector(1,2,3), Vector(1,2,std::nextafter(3.0, 4.0)), 0.0));
    CPPUNIT_ASSERT(!Equal(Vector(nan,0,0), Vector(nan,0,0)));
    CPPUNIT_ASSERT(!Equal(Vector(0,nan,0), Vector(0,1,0), inf));                // nan ignored in the scale, still unequal
    CPPUNIT_ASSERT(!Equal(Vector(big,0,0), Vector(-big,0,0)));
    CPPUNIT_ASSERT(Equal(Vector(big,0,0), Vector(std::nextafter(big, 0.0),0,0)));
    CPPUNIT_ASSERT(!Equal(Vector(-inf,0,0), Vector(inf,0,0)));
    CPPUNIT_ASSERT(Equal(Vector2(1e9,0), Vector2(1e9,9e2)));
    CPPUNIT_ASSERT(!Equal(Vector2(1,0), Vector2(1,1.1e-6)));
}

// D3: one scale per physical quantity, never shared between quantities or array elements.
void FramesTest::TestEqualPerQuantity() {
    CPPUNIT_ASSERT(Equal(Vector(1000,1e-3,0), Vector(1000,1.1e-3,0)));         // one scale per vector
    CPPUNIT_ASSERT(!Equal(Vector(1,1e-3,0), Vector(1,1.1e-3,0)));
    const Rotation R = Rotation::RPY(0.1,0.2,0.3), R2 = Rotation::RPY(0.1,0.2,0.3+1e-5);
    CPPUNIT_ASSERT(!Equal(Frame(R, Vector(1e3,0,0)), Frame(R2, Vector(1e3,0,0))));   // translation doesn't loosen M
    CPPUNIT_ASSERT(!Equal(Twist(Vector(1e3,0,0), Vector::Zero()), Twist(Vector(1e3,0,0), Vector(1e-4,0,0))));
    JntArray q1(2), q2(2); q1(0) = q2(0) = 1000; q1(1) = 0; q2(1) = 1e-4;
    CPPUNIT_ASSERT(!Equal(q1, q2));                                             // per element

    CPPUNIT_ASSERT(Equal(Frame(R, Vector(1e3,0,0)), Frame(R, Vector(1e3,1e-4,0))));
    CPPUNIT_ASSERT(!Equal(Wrench(Vector(1e3,0,0), Vector::Zero()), Wrench(Vector(1e3,0,0), Vector(1e-4,0,0))));
    CPPUNIT_ASSERT(Equal(Wrench(Vector(1e3,0,0), Vector::Zero()), Wrench(Vector(1e3,1e-4,0), Vector::Zero())));
    CPPUNIT_ASSERT(!Equal(Frame2(Rotation2(0.3), Vector2(1e3,0)), Frame2(Rotation2(0.3+1e-5), Vector2(1e3,0))));
    CPPUNIT_ASSERT(Equal(Frame2(Rotation2(0.3), Vector2(1e3,0)), Frame2(Rotation2(0.3), Vector2(1e3,1e-4))));
    CPPUNIT_ASSERT(!Equal(Rotation2(0.3), Rotation2(0.3+1e-5)));
    CPPUNIT_ASSERT(Equal(Rotation2(0.3), Rotation2(0.3+1e-7)));
    // The velocity part of a Vel type has its own scale.
    CPPUNIT_ASSERT(!Equal(VectorVel(Vector(1e3,0,0), Vector::Zero()), VectorVel(Vector(1e3,0,0), Vector(1e-4,0,0))));
    CPPUNIT_ASSERT(!Equal(Vector(1e3,0,0), VectorVel(Vector(1e3,0,0), Vector(1e-4,0,0))));
    CPPUNIT_ASSERT(!Equal(VectorAcc(Vector(1e3,0,0), Vector::Zero(), Vector::Zero()),
                          VectorAcc(Vector(1e3,0,0), Vector::Zero(), Vector(1e-4,0,0))));
    CPPUNIT_ASSERT(!Equal(doubleVel(1e3, 0), doubleVel(1e3, 1e-4)));
    CPPUNIT_ASSERT(!Equal(doubleAcc(1e3, 0, 0), doubleAcc(1e3, 0, 1e-4)));
    // Every element of an array type has its own scale.
    Jacobian J1(2), J2(2); J1.data.setZero(); J1(0,0) = 1000; J2 = J1; J2(1,1) = 1e-4;
    CPPUNIT_ASSERT(!Equal(J1, J2));
    J2 = J1; J2(0,0) = 1000 + 1e-4;
    CPPUNIT_ASSERT(Equal(J1, J2));
    CPPUNIT_ASSERT(!Equal(J1, Jacobian(3)));
    JntSpaceInertiaMatrix H1(2), H2(2); H1.data.setZero(); H1(0,0) = 1000; H2 = H1; H2(1,1) = 1e-4;
    CPPUNIT_ASSERT(!Equal(H1, H2));
    H2 = H1; H2(0,0) = 1000 + 1e-4;
    CPPUNIT_ASSERT(Equal(H1, H2));
    CPPUNIT_ASSERT(!Equal(H1, JntSpaceInertiaMatrix(3)));
    q2 = q1; q2(0) = 1000 + 1e-4;
    CPPUNIT_ASSERT(Equal(q1, q2));
    CPPUNIT_ASSERT(!Equal(q1, JntArray(3)));
}

// D6+D7: operator== is exact and consistent with std::hash; Equal is the tolerant comparison.
void FramesTest::TestExactEqualityAndHash() {
    CPPUNIT_ASSERT(!(Vector(1,0,0) == Vector(1+1e-9,0,0)));
    CPPUNIT_ASSERT(Vector(1,0,0) != Vector(1+1e-9,0,0));
    CPPUNIT_ASSERT(Equal(Vector(1,0,0), Vector(1+1e-9,0,0)));
    CPPUNIT_ASSERT(Vector(0,0,0) == Vector(-0.0,0,0));
    CPPUNIT_ASSERT_EQUAL(std::hash<Vector>{}(Vector(0,0,0)), std::hash<Vector>{}(Vector(-0.0,0,0)));
    const Frame F(Rotation::RPY(0.1,0.2,0.3), Vector(1,2,3));
    CPPUNIT_ASSERT(F == Frame(F));
    CPPUNIT_ASSERT_EQUAL(std::hash<Frame>{}(F), std::hash<Frame>{}(Frame(F)));

    const double d = 1e-9;
    const double nan = std::numeric_limits<double>::quiet_NaN();
    CPPUNIT_ASSERT(!(Vector(nan,0,0) == Vector(nan,0,0)));
    const Rotation R = F.M, Rd = Rotation(R.data[0]+d, R.data[1], R.data[2], R.data[3], R.data[4],
                                          R.data[5], R.data[6], R.data[7], R.data[8]);
    CPPUNIT_ASSERT(R != Rd && Equal(R, Rd));
    CPPUNIT_ASSERT(F != Frame(Rd, F.p) && Equal(F, Frame(Rd, F.p)));
    CPPUNIT_ASSERT(Frame(R, Vector(0,0,0)) == Frame(R, Vector(0,-0.0,0)));
    const Twist t(Vector(1,2,3), Vector(4,5,6)), td(Vector(1,2,3), Vector(4,5,6+d));
    CPPUNIT_ASSERT(t == Twist(t) && t != td && Equal(t, td));
    const Wrench w(Vector(1,2,3), Vector(4,5,6)), wd(Vector(1,2,3+d), Vector(4,5,6));
    CPPUNIT_ASSERT(w == Wrench(w) && w != wd && Equal(w, wd));
    CPPUNIT_ASSERT(Vector2(1,2) == Vector2(1,2) && Vector2(1,2) != Vector2(1,2+d) && Equal(Vector2(1,2), Vector2(1,2+d)));
    CPPUNIT_ASSERT(Equal(Rotation2(0.3), Rotation2(0.3+d)) && Equal(Frame2(Rotation2(0.3), Vector2(1,2)), Frame2(Rotation2(0.3), Vector2(1,2+d))));

    // The Vel types, including the mixed comparisons with the double type.
    const VectorVel vv(Vector(1,2,3), Vector(4,5,6)), vvd(Vector(1,2,3), Vector(4,5,6+d));
    CPPUNIT_ASSERT(vv == VectorVel(vv) && vv != vvd && Equal(vv, vvd));
    CPPUNIT_ASSERT(Vector(1,2,3) == VectorVel(Vector(1,2,3)) && VectorVel(Vector(1,2,3)) == Vector(1,2,3));
    CPPUNIT_ASSERT(Vector(1,2,3) != VectorVel(Vector(1,2,3), Vector(0,0,d)) && VectorVel(Vector(1,2,3), Vector(0,0,d)) != Vector(1,2,3));
    const RotationVel rv(R, Vector(1,2,3)), rvd(R, Vector(1,2,3+d));
    CPPUNIT_ASSERT(rv == RotationVel(rv) && rv != rvd && Equal(rv, rvd));
    CPPUNIT_ASSERT(R == RotationVel(R) && RotationVel(R) == R && R != RotationVel(Rd) && RotationVel(Rd) != R);
    const FrameVel fv(rv, vv), fvd(rv, vvd);
    CPPUNIT_ASSERT(fv == FrameVel(fv) && fv != fvd && Equal(fv, fvd));
    CPPUNIT_ASSERT(F == FrameVel(F) && FrameVel(F) == F && F != FrameVel(Frame(Rd, F.p)) && FrameVel(Frame(Rd, F.p)) != F);
    const TwistVel tv(vv, vv), tvd(vv, vvd);
    CPPUNIT_ASSERT(tv == TwistVel(tv) && tv != tvd && Equal(tv, tvd));
    CPPUNIT_ASSERT(t == TwistVel(t) && TwistVel(t) == t && t != TwistVel(td) && TwistVel(td) != t);
    CPPUNIT_ASSERT_EQUAL(std::hash<VectorVel>{}(VectorVel(Vector(0,0,0))), std::hash<VectorVel>{}(VectorVel(Vector(-0.0,0,0))));

    // R16: the scalar Vel and Acc types compare exactly, too.
    CPPUNIT_ASSERT(doubleVel(1, 2) == doubleVel(1, 2) && doubleVel(1, 2) != doubleVel(1, 2+d) && Equal(doubleVel(1, 2), doubleVel(1, 2+d)));
    CPPUNIT_ASSERT(doubleAcc(1, 2, 3) == doubleAcc(1, 2, 3) && doubleAcc(1, 2, 3) != doubleAcc(1, 2, 3+d)
                   && Equal(doubleAcc(1, 2, 3), doubleAcc(1, 2, 3+d)));
    CPPUNIT_ASSERT(doubleVel(0, 0) == doubleVel(-0.0, 0));
    CPPUNIT_ASSERT_EQUAL(std::hash<doubleVel>{}(doubleVel(0, 0)), std::hash<doubleVel>{}(doubleVel(-0.0, 0)));

    // R17: the array types compare exactly, too.
    JntArray q1(2), q2(2); q1(0) = 1; q1(1) = 2; q2 = q1; q2(1) = 2+d;
    CPPUNIT_ASSERT(q1 == JntArray(q1) && !(q1 == q2) && Equal(q1, q2));
    CPPUNIT_ASSERT(!(q1 == JntArray(3)));
    Jacobian J1(2), J2(2); J1.data.setConstant(1); J2 = J1; J2(5,1) = 1+d;
    CPPUNIT_ASSERT(J1 == Jacobian(J1) && !(J1 == J2) && J1 != J2 && Equal(J1, J2));
    CPPUNIT_ASSERT(J1 != Jacobian(3));
    JntSpaceInertiaMatrix H1(2), H2(2); H1.data.setConstant(1); H2 = H1; H2(1,1) = 1+d;
    CPPUNIT_ASSERT(H1 == JntSpaceInertiaMatrix(H1) && !(H1 == H2) && Equal(H1, H2));
    CPPUNIT_ASSERT(!(H1 == JntSpaceInertiaMatrix(3)));
}
