#include <math.h>
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <kdl/test_macros.h>

using namespace KDL;
using namespace std;


// some tests for the frames classes
// A note on compiler optimisation :
//   The following is optimized to NOTHING on VC6 in Release,
//   with max. speed opt.( at least the Vector / Twist / Wrench part )
//   If one invalidates 1 option, all the others are evaluated because the compiler
//   does not know whether cout << changes the values ! Optimisation does not work
//   algebraicly but on the numerical values that are evaluated. const declaration
//   of Vector does not help ! When you insert a v = Vector(1,2,3) line later, the compiler
//   knows again it's constant, and it's optimised.
//	 So, do not declare your (semi-) constant values until you need them.
//#pragma optimize( "", off )

void TestVector2(Vector& v) {
    KDL_CTX;
	Vector   v2;
	// Vector
	KDL_DIFF(2*v-v,v);
	KDL_DIFF(v*2-v,v);
	KDL_DIFF(v+v+v-2*v,v);
	v2=v;
	KDL_DIFF(v,v2);
	v2+=v;
	KDL_DIFF(2*v,v2);
	v2-=v;
	KDL_DIFF(v,v2);
	v2.ReverseSign();
	KDL_DIFF(v,-v2);
}
void TestVector() {
    KDL_CTX;
	Vector   v(3,4,5);
	TestVector2(v);
	Vector   v2(0,0,0);
	TestVector2(v2);
	
	Vector nu(0,0,0);
	KDL_DIFF(nu.Norm(),0);
	Vector nu2(10,0,0);
	KDL_DIFF(nu2.Norm(),10);
}

void TestTwist2(Twist& t) {
    KDL_CTX;
	// Twist	
	Twist    t2(Vector(16,-3,5),Vector(-4,2,1));

	KDL_DIFF(2*t-t,t);
	KDL_DIFF(t*2-t,t);
	KDL_DIFF(t+t+t-2*t,t);
	t2=t;
	KDL_DIFF(t,t2);
	t2+=t;
	KDL_DIFF(2*t,t2);
	t2-=t;
	KDL_DIFF(t,t2);
	t.ReverseSign();
	KDL_DIFF(t,-t2);
}

void TestTwist() {
    KDL_CTX
	Twist    t(Vector(6,3,5),Vector(4,-2,7));
	TestTwist2(t);
	Twist    t2(Vector(0,0,0),Vector(0,0,0));
	TestTwist2(t2);	
	Twist    t3(Vector(0,-9,-3),Vector(1,-2,-4));
	TestTwist2(t3);	
}

void TestWrench2(Wrench& w) {
	// Wrench
    KDL_CTX;	
	Wrench   w2;	
	KDL_DIFF(2*w-w,w);
	KDL_DIFF(w*2-w,w);
	KDL_DIFF(w+w+w-2*w,w);
	w2=w;
	KDL_DIFF(w,w2);
	w2+=w;
	KDL_DIFF(2*w,w2);
	w2-=w;
	KDL_DIFF(w,w2);
	w.ReverseSign();
	KDL_DIFF(w,-w2);
}

void TestWrench() {
    KDL_CTX;
	Wrench   w(Vector(7,-1,3),Vector(2,-3,3));
	TestWrench2(w);
	Wrench   w2(Vector(0,0,0),Vector(0,0,0));
	TestWrench2(w2);
	Wrench   w3(Vector(2,1,4),Vector(5,3,1));
	TestWrench2(w3);		
}

void TestRotation2(const Vector& v,double a,double b,double c) {
    KDL_CTX;
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

	KDL_DIFF(dot(R.UnitX(),R.UnitX()),1);
	KDL_DIFF(dot(R.UnitY(),R.UnitY()),1);
	KDL_DIFF(dot(R.UnitZ(),R.UnitZ()),1);
	KDL_DIFF(dot(R.UnitX(),R.UnitY()),0);
	KDL_DIFF(dot(R.UnitX(),R.UnitZ()),0);
	KDL_DIFF(dot(R.UnitY(),R.UnitZ()),0);
	R2=R;
	KDL_DIFF(R,R2);
	KDL_DIFF((R*v).Norm(),v.Norm());
	KDL_DIFF(R.Inverse(R*v),v);
	KDL_DIFF(R.Inverse(R*t),t);
	KDL_DIFF(R.Inverse(R*w),w);
	KDL_DIFF(R*R.Inverse(v),v);
	KDL_DIFF(R*Rotation::Identity(),R);
	KDL_DIFF(Rotation::Identity()*R,R);
	KDL_DIFF(R*(R*(R*v)),(R*R*R)*v);
	KDL_DIFF(R*(R*(R*t)),(R*R*R)*t);
	KDL_DIFF(R*(R*(R*w)),(R*R*R)*w);
	KDL_DIFF(R*R.Inverse(),Rotation::Identity());
	KDL_DIFF(R.Inverse()*R,Rotation::Identity());
	KDL_DIFF(R.Inverse()*v,R.Inverse(v));
	R.GetRPY(ra,rb,rc);
	KDL_DIFF(ra,a);
    KDL_DIFF(rb,b);KDL_DIFF(rc,c);
	R = Rotation::EulerZYX(a,b,c);
	R.GetEulerZYX(ra,rb,rc);
	KDL_DIFF(ra,a);KDL_DIFF(rb,b);KDL_DIFF(rc,c);
	R = Rotation::EulerZYZ(a,b,c);
	R.GetEulerZYZ(ra,rb,rc);
	KDL_DIFF(ra,a);KDL_DIFF(rb,b);KDL_DIFF(rc,c);
	double angle= R.GetRotAngle(v2);
	R2=Rotation::Rot2(v2,angle);
	KDL_DIFF(R2,R);
	R2=Rotation::Rot(v2*1E20,angle);
	KDL_DIFF(R,R2);
	v2=Vector(6,2,4);
	KDL_DIFF((v2).Norm(),::sqrt(dot(v2,v2)) );
}

void TestRotation() {
    KDL_CTX;
	TestRotation2(Vector(3,4,5),10*deg2rad,20*deg2rad,30*deg2rad);
}


void TestFrame() {
    KDL_CTX;
	Vector   v(3,4,5); 
	Wrench   w(Vector(7,-1,3),Vector(2,-3,3)) ;
	Twist    t(Vector(6,3,5),Vector(4,-2,7)) ;
	Rotation R ;
	Frame F;
	Frame F2 ;
	F = Frame(Rotation::EulerZYX(10*deg2rad,20*deg2rad,-10*deg2rad),Vector(4,-2,1));
	F2=F   ;
	KDL_DIFF(F,F2);
	KDL_DIFF(F.Inverse(F*v),v);
	KDL_DIFF(F.Inverse(F*t),t);
	KDL_DIFF(F.Inverse(F*w),w);
	KDL_DIFF(F*F.Inverse(v),v);
	KDL_DIFF(F*F.Inverse(t),t);
	KDL_DIFF(F*F.Inverse(w),w);
	KDL_DIFF(F*Frame::Identity(),F);
	KDL_DIFF(Frame::Identity()*F,F);
	KDL_DIFF(F*(F*(F*v)),(F*F*F)*v);
	KDL_DIFF(F*(F*(F*t)),(F*F*F)*t);
	KDL_DIFF(F*(F*(F*w)),(F*F*F)*w);
	KDL_DIFF(F*F.Inverse(),Frame::Identity());
	KDL_DIFF(F.Inverse()*F,Frame::Identity());
	KDL_DIFF(F.Inverse()*v,F.Inverse(v));
}



//#pragma optimize( "", on )
// cout to brake optimization in smaller pieces
int main() {
    KDL_CTX;
	TestVector();
	TestTwist(); 
	TestWrench();
	TestRotation();
	TestFrame();
	return 0;
}



// Some old code :

/*

#define KDL_DIFF(tst) \
	cout << #tst << endl;\
	cout << (tst) << endl;

void Test2D() {
	Vector2 v(1,5);
	Vector2 v2(4,3);
	// Testing rotations
	cout << "Testing Rotation2 " << endl;
	Rotation2 r(Rotation2::Rot(30*deg2rad));
	DISP( r );
	DISP((r*r));
	DISP(  r*r.Inverse() );
	DISP( v);
	DISP( v2);
	DISP( r.Inverse(r*v));
	DISP( Rotation2::Identity());
	DISP( v+v2);
	DISP( v-v2);
	DISP( v+2*v2 );
	DISP( v+v2*2 );
	cout << "Testing Frame2 " << endl;
	Frame2 f(r,v);
	DISP( f );
	DISP( f*f );
	DISP( f*f.Inverse() );
	DISP( v);
	DISP( f.Inverse(f*v) );
	cout << setw(20) << r << endl;
}
void Test3D() {
	Vector v(1,5,2);
	Vector v2(4,3,1);
	// Testing rotations
	cout << "Testing Rotation2 " << endl;
	Rotation r(Rotation::EulerZYX(30*deg2rad,20*deg2rad,10*deg2rad));
	DISP( r );
	DISP((r*r));
	DISP(  r*r.Inverse() );
	DISP( v);
	DISP( v2);
	DISP( r.Inverse(r*v));
	DISP( Rotation2::Identity());
	DISP( v+v2);
	DISP( v-v2);
	DISP( v+2*v2 );
	DISP( v+v2*2 );
	cout << "Testing Frame2 " << endl;
	Frame f(r,v);
	DISP( f );
	DISP( f*f );
	DISP( f*f.Inverse() );
	DISP( v);
	DISP( f.Inverse(f*v) );
	cout << setw(20) << r << endl;
}
*/




/*
 A VC6++ bug : generates INTERNAL COMPILER ERROR :

#include "math.h" 
class A { 
public: 
	void Method(const double& d); 
}; 

void BugFunc() { 
	A v; 
	v.Method(fabs(100.0)); 
} 

int main() {

	BugFunc();
	return 0;
}

*/

/******
// It is better to pass double then passing const double&
// Tst() is TWICE as fast !
// Generation of a function argument;

double Tst_ref(const double& a) {
	return a*(3+2*(a+1))+1;
}

double Tst(double a) {
	return a*(3+2*(a+1))+1;
}




int main() {
//	Test();
	int N=1000000;
	HighResTimer T;
	QW d;
	
	int i;
	double y;

	SetPriorityClass(::GetCurrentProcess(),HIGH_PRIORITY_CLASS);
	T.Mark();
	y = 0;
	for (i=0;i<N;i++) y=y+Tst_ref(i);
	d = T.GetTimeDiff();
	cout << "Tst_ref  "<<y<<endl;
	cout << "time     "<<d<<endl;


	T.Mark();
	y = 0;
	for (i=0;i<N;i++) y=y+Tst(i);
	d = T.GetTimeDiff();
	cout << "Tst      "<<y<<endl;
	cout << "time     "<<d<<endl;

	SetPriorityClass(::GetCurrentProcess(),NORMAL_PRIORITY_CLASS);
	return 0;
}
********/
