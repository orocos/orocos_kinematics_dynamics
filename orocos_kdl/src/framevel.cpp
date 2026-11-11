/*****************************************************************************
 *  \author
 *  	Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version
 *		ORO_Geometry V0.2
 *
 *	\par History
 *		- $log$
 *
 *	\par Release
 *		$Id: rframes.cpp,v 1.1.1.1 2002/08/26 14:14:21 rmoreas Exp $
 *		$Name:  $
 ****************************************************************************/


#include "framevel.hpp"

namespace KDL {

void random(doubleVel& F) {
	random(F.t);
	random(F.grad);
}

void posrandom(doubleVel& F) {
	posrandom(F.t);
	posrandom(F.grad);
}

VectorVel diff(const RotationVel& a,const RotationVel& b,double dt) {
	return VectorVel(diff(a.R,b.R,dt),diff(a.w,b.w,dt));
}

RotationVel addDelta(const RotationVel& a,const VectorVel&da,double dt) {
	return RotationVel(addDelta(a.R,da.p,dt),addDelta(a.w,da.v,dt));
}

TwistVel diff(const FrameVel& a,const FrameVel& b,double dt) {
	return TwistVel(diff(a.p,b.p,dt),diff(a.M,b.M,dt));
}

FrameVel addDelta(const FrameVel& a,const TwistVel& da,double dt) {
	return FrameVel(
			addDelta(a.M,da.rot,dt),
			addDelta(a.p,da.vel,dt)
		   );
}

void random(VectorVel& a) {
	random(a.p);
	random(a.v);
}

void random(TwistVel& a) {
	random(a.vel);
	random(a.rot);
}

void random(RotationVel& R) {
	random(R.R);
	random(R.w);
}

void random(FrameVel& F) {
	random(F.M);
	random(F.p);
}

void posrandom(VectorVel& a) {
	posrandom(a.p);
	posrandom(a.v);
}

void posrandom(TwistVel& a) {
	posrandom(a.vel);
	posrandom(a.rot);
}

void posrandom(RotationVel& R) {
	posrandom(R.R);
	posrandom(R.w);
}

void posrandom(FrameVel& F) {
	posrandom(F.M);
	posrandom(F.p);
}

bool Equal(const FrameVel& r1,const FrameVel& r2,double eps) {
    return (Equal(r1.M,r2.M,eps) && Equal(r1.p,r2.p,eps));
}
bool Equal(const Frame& r1,const FrameVel& r2,double eps) {
    return (Equal(r1.M,r2.M,eps) && Equal(r1.p,r2.p,eps));
}
bool Equal(const FrameVel& r1,const Frame& r2,double eps) {
    return (Equal(r1.M,r2.M,eps) && Equal(r1.p,r2.p,eps));
}

// = Rotations
// The Rot... static functions give the value of the appropriate rotation matrix back.
// The DoRot... functions apply a rotation R to *this,such that *this = *this * R.

void RotationVel::DoRotX(const doubleVel& angle) {
    w+=R*Vector(angle.grad,0,0);
    R.DoRotX(angle.t);
}
RotationVel RotationVel::RotX(const doubleVel& angle) {
    return RotationVel(Rotation::RotX(angle.t),Vector(angle.grad,0,0));
}

void RotationVel::DoRotY(const doubleVel& angle) {
    w+=R*Vector(0,angle.grad,0);
    R.DoRotY(angle.t);
}
RotationVel RotationVel::RotY(const doubleVel& angle) {
    return RotationVel(Rotation::RotY(angle.t),Vector(0,angle.grad,0));
}

void RotationVel::DoRotZ(const doubleVel& angle) {
    w+=R*Vector(0,0,angle.grad);
    R.DoRotZ(angle.t);
}
RotationVel RotationVel::RotZ(const doubleVel& angle) {
    return RotationVel(Rotation::RotZ(angle.t),Vector(0,0,angle.grad));
}

RotationVel RotationVel::Rot(const Vector& rotvec,const doubleVel& angle) 
// rotvec has arbitrary norm
// rotation around a constant vector !
{
    Vector v(rotvec);
	v.Normalize();
    return RotationVel(Rotation::Rot2(v,angle.t),v*angle.grad);
}

RotationVel RotationVel::Rot2(const Vector& rotvec,const doubleVel& angle) 
    // rotvec is normalized.
{
    return RotationVel(Rotation::Rot2(rotvec,angle.t),rotvec*angle.grad);
}
doubleVel VectorVel::Norm(double eps) const {
    double n = p.Norm(eps);
    if (n < eps) // Setting norm  of p and v to 0 in case norm of p is smaller than eps
        return doubleVel(0, 0);
    return doubleVel(n, dot(p,v)/n);
}

bool Equal(const VectorVel& r1,const VectorVel& r2,double eps) {
    return (Equal(r1.p,r2.p,eps) && Equal(r1.v,r2.v,eps));
}
bool Equal(const Vector& r1,const VectorVel& r2,double eps) {
    return (Equal(r1,r2.p,eps) && Equal(Vector::Zero(),r2.v,eps));
}
bool Equal(const VectorVel& r1,const Vector& r2,double eps) {
    return (Equal(r1.p,r2,eps) && Equal(r1.v,Vector::Zero(),eps));
}

bool Equal(const RotationVel& r1,const RotationVel& r2,double eps) {
    return (Equal(r1.w,r2.w,eps) && Equal(r1.R,r2.R,eps));
}
bool Equal(const Rotation& r1,const RotationVel& r2,double eps) {
    return (Equal(Vector::Zero(),r2.w,eps) && Equal(r1,r2.R,eps));
}
bool Equal(const RotationVel& r1,const Rotation& r2,double eps) {
    return (Equal(r1.w,Vector::Zero(),eps) && Equal(r1.R,r2,eps));
}

bool Equal(const TwistVel& a,const TwistVel& b,double eps) {
        return (Equal(a.rot,b.rot,eps)&&
                Equal(a.vel,b.vel,eps)  );
}
bool Equal(const Twist& a,const TwistVel& b,double eps) {
        return (Equal(a.rot,b.rot,eps)&&
                Equal(a.vel,b.vel,eps)  );
}
bool Equal(const TwistVel& a,const Twist& b,double eps) {
        return (Equal(a.rot,b.rot,eps)&&
                Equal(a.vel,b.vel,eps)  );
}

}
