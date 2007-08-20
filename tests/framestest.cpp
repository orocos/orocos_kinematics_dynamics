#include <math.h>
#include "framestest.hpp"
#include <frames_io.hpp>
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
	
	Vector nu(0,0,0);
	CPPUNIT_ASSERT_EQUAL(nu.Norm(),0.0);
	Vector nu2(10,0,0);
	CPPUNIT_ASSERT_EQUAL(nu2.Norm(),10.0);
}

void FramesTest::TestTwist2(Twist& t) {
	Twist t2(Vector(16,-3,5),Vector(-4,2,1));

	CPPUNIT_ASSERT_EQUAL(2*t-t,t);
	CPPUNIT_ASSERT_EQUAL(t*2-t,t);
	CPPUNIT_ASSERT_EQUAL(t+t+t-2*t,t);
	t2=t;
	CPPUNIT_ASSERT_EQUAL(t,t2);
	t2+=t;
	CPPUNIT_ASSERT_EQUAL(2*t,t2);
	t2-=t;
	CPPUNIT_ASSERT_EQUAL(t,t2);
	t.ReverseSign();
	CPPUNIT_ASSERT_EQUAL(t,-t2);
}

void FramesTest::TestTwist() {
	Twist    t(Vector(6,3,5),Vector(4,-2,7));
	TestTwist2(t);
	Twist    t2(Vector(0,0,0),Vector(0,0,0));
	TestTwist2(t2);	
	Twist    t3(Vector(0,-9,-3),Vector(1,-2,-4));
	TestTwist2(t3);	
}

void FramesTest::TestWrench2(Wrench& w) {
	// Wrench
	Wrench   w2;	
	CPPUNIT_ASSERT_EQUAL(2*w-w,w);
	CPPUNIT_ASSERT_EQUAL(w*2-w,w);
	CPPUNIT_ASSERT_EQUAL(w+w+w-2*w,w);
	w2=w;
	CPPUNIT_ASSERT_EQUAL(w,w2);
	w2+=w;
	CPPUNIT_ASSERT_EQUAL(2*w,w2);
	w2-=w;
	CPPUNIT_ASSERT_EQUAL(w,w2);
	w.ReverseSign();
	CPPUNIT_ASSERT_EQUAL(w,-w2);
}

void FramesTest::TestWrench() {
	Wrench   w(Vector(7,-1,3),Vector(2,-3,3));
	TestWrench2(w);
	Wrench   w2(Vector(0,0,0),Vector(0,0,0));
	TestWrench2(w2);
	Wrench   w3(Vector(2,1,4),Vector(5,3,1));
	TestWrench2(w3);		
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
	CPPUNIT_ASSERT_DOUBLES_EQUAL((R*v).Norm(),v.Norm(),epsilon);
	CPPUNIT_ASSERT_EQUAL(R.Inverse(R*v),v);
	CPPUNIT_ASSERT_EQUAL(R.Inverse(R*t),t);
	CPPUNIT_ASSERT_EQUAL(R.Inverse(R*w),w);
	CPPUNIT_ASSERT_EQUAL(R*R.Inverse(v),v);
	CPPUNIT_ASSERT_EQUAL(R*Rotation::Identity(),R);
	CPPUNIT_ASSERT_EQUAL(Rotation::Identity()*R,R);
	CPPUNIT_ASSERT_EQUAL(R*(R*(R*v)),(R*R*R)*v);
	CPPUNIT_ASSERT_EQUAL(R*(R*(R*t)),(R*R*R)*t);
	CPPUNIT_ASSERT_EQUAL(R*(R*(R*w)),(R*R*R)*w);
	CPPUNIT_ASSERT_EQUAL(R*R.Inverse(),Rotation::Identity());
	CPPUNIT_ASSERT_EQUAL(R.Inverse()*R,Rotation::Identity());
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
	CPPUNIT_ASSERT_EQUAL(R2,R);
	R2=Rotation::Rot(v2*1E20,angle);
	CPPUNIT_ASSERT_EQUAL(R,R2);
	v2=Vector(6,2,4);
	CPPUNIT_ASSERT_DOUBLES_EQUAL((v2).Norm(),::sqrt(dot(v2,v2)),epsilon);
}

void FramesTest::TestRotation() {
	TestRotation2(Vector(3,4,5),10*deg2rad,20*deg2rad,30*deg2rad);
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
	CPPUNIT_ASSERT_EQUAL(F.Inverse(F*v),v);
	CPPUNIT_ASSERT_EQUAL(F.Inverse(F*t),t);
	CPPUNIT_ASSERT_EQUAL(F.Inverse(F*w),w);
	CPPUNIT_ASSERT_EQUAL(F*F.Inverse(v),v);
	CPPUNIT_ASSERT_EQUAL(F*F.Inverse(t),t);
	CPPUNIT_ASSERT_EQUAL(F*F.Inverse(w),w);
	CPPUNIT_ASSERT_EQUAL(F*Frame::Identity(),F);
	CPPUNIT_ASSERT_EQUAL(Frame::Identity()*F,F);
	CPPUNIT_ASSERT_EQUAL(F*(F*(F*v)),(F*F*F)*v);
	CPPUNIT_ASSERT_EQUAL(F*(F*(F*t)),(F*F*F)*t);
	CPPUNIT_ASSERT_EQUAL(F*(F*(F*w)),(F*F*F)*w);
	CPPUNIT_ASSERT_EQUAL(F*F.Inverse(),Frame::Identity());
	CPPUNIT_ASSERT_EQUAL(F.Inverse()*F,Frame::Identity());
	CPPUNIT_ASSERT_EQUAL(F.Inverse()*v,F.Inverse(v));
}

void FramesTest::TestJntArray()
{
    JntArray a1(4);
    random(a1(0));
    random(a1(1));
    random(a1(2));
    random(a1(3));
    JntArray a2(a1);
    CPPUNIT_ASSERT(Equal(a2,a1));

    SetToZero(a2);
    CPPUNIT_ASSERT(!Equal(a1,a2));
    
    JntArray a3(4);
    CPPUNIT_ASSERT(Equal(a2,a3));
    
    a1=a2;
    CPPUNIT_ASSERT(Equal(a1,a3));

    random(a1(0));
    random(a1(1));
    random(a1(2));
    random(a1(3));
    
    Add(a1,a2,a3);
    CPPUNIT_ASSERT(Equal(a1,a3));
    
    random(a2(0));
    random(a2(1));
    random(a2(2));
    random(a2(3));
    Add(a1,a2,a3);
    Substract(a3,a2,a3);
    CPPUNIT_ASSERT(Equal(a1,a3));
    
    Multiply(a1,2,a3);
    Add(a1,a1,a2);
    CPPUNIT_ASSERT(Equal(a2,a3));
    
    double a;
    random(a);
    Multiply(a1,a,a3);
    Divide(a3,a,a2);
    CPPUNIT_ASSERT(Equal(a2,a1));
}

