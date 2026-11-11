/*****************************************************************************
 * \file
 *      This file contains the definition of classes for a
 *      Rall Algebra of (subset of) the classes defined in frames,
 *      i.e. classes that contain a pair (value,derivative) and define operations on that pair
 *      this classes are useful for automatic differentiation ( <-> symbolic diff , <-> numeric diff)
 *      Defines VectorVel, RotationVel, FrameVel.  Look at Frames.h for details on how to work
 *      with Frame objects.
 *  \author
 *      Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version
 *      ORO_Geometry V0.2
 *
 *  \par History
 *      - $log$
 *
 *  \par Release
 *      $Id: rframes.h,v 1.1.1.1 2002/08/26 14:14:21 rmoreas Exp $
 *      $Name:  $
 ****************************************************************************/

#ifndef KDL_FRAMEVEL_H
#define KDL_FRAMEVEL_H

#include "utilities/utility.h"
#include "utilities/rall1d.h"
#include "utilities/traits.h"

#include "frames.hpp"


namespace KDL {

typedef Rall1d<double> doubleVel;

inline doubleVel diff(const doubleVel& a,const doubleVel& b,double dt=1.0) {
	return doubleVel((b.t-a.t)/dt,(b.grad-a.grad)/dt);
}

inline doubleVel addDelta(const doubleVel& a,const doubleVel&da,double dt=1.0) {
	return doubleVel(a.t+da.t*dt,a.grad+da.grad*dt);
}

void random(doubleVel& F);
void posrandom(doubleVel& F);

}

template <>
struct Traits<KDL::doubleVel> {
	typedef double valueType;
	typedef KDL::doubleVel derivType;
};

namespace KDL {

class TwistVel;
class VectorVel;
class FrameVel;
class RotationVel;

// Equal is friend function, but default arguments for friends are forbidden (§8.3.6.4)
bool Equal(const VectorVel& r1,const VectorVel& r2,double eps=epsilon);
bool Equal(const Vector& r1,const VectorVel& r2,double eps=epsilon);
bool Equal(const VectorVel& r1,const Vector& r2,double eps=epsilon);
bool Equal(const RotationVel& r1,const RotationVel& r2,double eps=epsilon);
bool Equal(const Rotation& r1,const RotationVel& r2,double eps=epsilon);
bool Equal(const RotationVel& r1,const Rotation& r2,double eps=epsilon);
bool Equal(const FrameVel& r1,const FrameVel& r2,double eps=epsilon);
bool Equal(const Frame& r1,const FrameVel& r2,double eps=epsilon);
bool Equal(const FrameVel& r1,const Frame& r2,double eps=epsilon);
bool Equal(const TwistVel& a,const TwistVel& b,double eps=epsilon);
bool Equal(const Twist& a,const TwistVel& b,double eps=epsilon);
bool Equal(const TwistVel& a,const Twist& b,double eps=epsilon);


class VectorVel
// = TITLE
//     An VectorVel is a Vector and its first derivative
// = CLASS TYPE
//     Concrete
{
public:
    Vector p;       // position vector
    Vector v;       // velocity vector
public:
    VectorVel():p(),v(){}
    VectorVel(const Vector& _p,const Vector& _v):p(_p),v(_v) {}
    explicit VectorVel(const Vector& _p):p(_p),v(Vector::Zero()) {}

    Vector value() const { return p;}
    Vector deriv() const { return v;}

    inline VectorVel& operator = (const Vector& arg);
    inline VectorVel& operator += (const VectorVel& arg);
    inline VectorVel& operator -= (const VectorVel& arg);
    inline static VectorVel Zero();
    inline void ReverseSign();
    //! The norm and its derivative; (0, 0) only for the exact zero vector p.
    doubleVel Norm() const;
    inline friend VectorVel operator + (const VectorVel& r1,const VectorVel& r2);
    inline friend VectorVel operator - (const VectorVel& r1,const VectorVel& r2);
    inline friend VectorVel operator + (const Vector& r1,const VectorVel& r2);
    inline friend VectorVel operator - (const Vector& r1,const VectorVel& r2);
    inline friend VectorVel operator + (const VectorVel& r1,const Vector& r2);
    inline friend VectorVel operator - (const VectorVel& r1,const Vector& r2);
    inline friend VectorVel operator * (const VectorVel& r1,const VectorVel& r2);
    inline friend VectorVel operator * (const VectorVel& r1,const Vector& r2);
    inline friend VectorVel operator * (const Vector& r1,const VectorVel& r2);
    inline friend VectorVel operator * (const VectorVel& r1,double r2);
    inline friend VectorVel operator * (double r1,const VectorVel& r2);
    inline friend VectorVel operator * (const doubleVel& r1,const VectorVel& r2);
    inline friend VectorVel operator * (const VectorVel& r2,const doubleVel& r1);
    inline friend VectorVel operator*(const Rotation& R,const VectorVel& x);

    inline friend VectorVel operator / (const VectorVel& r1,double r2);
    inline friend VectorVel operator / (const VectorVel& r2,const doubleVel& r1);
    inline friend void SetToZero(VectorVel& v);


    friend bool Equal(const VectorVel& r1,const VectorVel& r2,double eps);
    friend bool Equal(const Vector& r1,const VectorVel& r2,double eps);
    friend bool Equal(const VectorVel& r1,const Vector& r2,double eps);

    inline friend bool operator==(const VectorVel& r1,const VectorVel& r2);
    inline friend bool operator!=(const VectorVel& r1,const VectorVel& r2);
    inline friend bool operator==(const Vector& r1,const VectorVel& r2);
    inline friend bool operator!=(const Vector& r1,const VectorVel& r2);
    inline friend bool operator==(const VectorVel& r1,const Vector& r2);
    inline friend bool operator!=(const VectorVel& r1,const Vector& r2);

    inline friend VectorVel operator - (const VectorVel& r);
    inline friend doubleVel dot(const VectorVel& lhs,const VectorVel& rhs);
    inline friend doubleVel dot(const VectorVel& lhs,const Vector& rhs);
    inline friend doubleVel dot(const Vector& lhs,const VectorVel& rhs);
};


class RotationVel
// = TITLE
//     An RotationVel is a Rotation and its first derivative, a rotation vector
// = CLASS TYPE
//     Concrete
{
public:
    Rotation R; // Rotation matrix
    Vector   w; // rotation vector
public:
    RotationVel():R(),w() {}
    explicit RotationVel(const Rotation& _R):R(_R),w(Vector::Zero()){}
    RotationVel(const Rotation& _R,const Vector& _w):R(_R),w(_w){}


    Rotation value() const { return R;}
    Vector   deriv() const { return w;}


    inline RotationVel& operator = (const Rotation& arg);
	inline VectorVel UnitX() const;
	inline VectorVel UnitY() const;
	inline VectorVel UnitZ() const;
    inline static RotationVel Identity();
    inline RotationVel Inverse() const;
    inline VectorVel Inverse(const VectorVel& arg) const;
    inline VectorVel Inverse(const Vector& arg) const;
    inline VectorVel operator*(const VectorVel& arg) const;
    inline VectorVel operator*(const Vector& arg) const;
    void DoRotX(const doubleVel& angle);
    void DoRotY(const doubleVel& angle);
    void DoRotZ(const doubleVel& angle);
    static RotationVel RotX(const doubleVel& angle);
    static RotationVel RotY(const doubleVel& angle);
    static RotationVel RotZ(const doubleVel& angle);
    static RotationVel Rot(const Vector& rotvec,const doubleVel& angle);
    // rotvec has arbitrary norm
    // rotation around a constant vector !
    static RotationVel Rot2(const Vector& rotvec,const doubleVel& angle);
    // rotvec is normalized.
    // rotation around a constant vector !
    inline friend RotationVel operator* (const RotationVel& r1,const RotationVel& r2);
    inline friend RotationVel operator* (const Rotation& r1,const RotationVel& r2);
    inline friend RotationVel operator* (const RotationVel& r1,const Rotation& r2);
    friend bool Equal(const RotationVel& r1,const RotationVel& r2,double eps);
    friend bool Equal(const Rotation& r1,const RotationVel& r2,double eps);
    friend bool Equal(const RotationVel& r1,const Rotation& r2,double eps);

    inline friend bool operator==(const RotationVel& r1,const RotationVel& r2);
    inline friend bool operator!=(const RotationVel& r1,const RotationVel& r2);
    inline friend bool operator==(const Rotation& r1,const RotationVel& r2);
    inline friend bool operator!=(const Rotation& r1,const RotationVel& r2);
    inline friend bool operator==(const RotationVel& r1,const Rotation& r2);
    inline friend bool operator!=(const RotationVel& r1,const Rotation& r2);

    inline TwistVel Inverse(const TwistVel& arg) const;
    inline TwistVel Inverse(const Twist& arg) const;
    inline TwistVel operator * (const TwistVel& arg) const;
    inline TwistVel operator * (const Twist& arg) const;
};


class FrameVel
// = TITLE
//     An FrameVel is a Frame and its first derivative, a Twist vector
// = CLASS TYPE
//     Concrete
// = CAVEATS
//
{
public:
    RotationVel M;
    VectorVel   p;
public:
    FrameVel(){}

    explicit FrameVel(const Frame& _T):
        M(_T.M),p(_T.p) {}

    FrameVel(const Frame& _T,const Twist& _t):
        M(_T.M,_t.rot),p(_T.p,_t.vel) {}

    FrameVel(const RotationVel& _M,const VectorVel& _p):
        M(_M),p(_p) {}


    Frame value() const { return Frame(M.value(),p.value());}
    Twist deriv() const { return Twist(p.deriv(),M.deriv());}


    inline FrameVel& operator = (const Frame& arg);
    inline static FrameVel Identity();
    inline FrameVel Inverse() const;
    inline VectorVel Inverse(const VectorVel& arg) const;
    inline VectorVel operator*(const VectorVel& arg) const;
    inline VectorVel operator*(const Vector& arg) const;
    inline VectorVel Inverse(const Vector& arg) const;
    inline Frame GetFrame() const;
    inline Twist GetTwist() const;
    inline friend FrameVel operator * (const FrameVel& f1,const FrameVel& f2);
    inline friend FrameVel operator * (const Frame& f1,const FrameVel& f2);
    inline friend FrameVel operator * (const FrameVel& f1,const Frame& f2);
    friend bool Equal(const FrameVel& r1,const FrameVel& r2,double eps);
    friend bool Equal(const Frame& r1,const FrameVel& r2,double eps);
    friend bool Equal(const FrameVel& r1,const Frame& r2,double eps);

    inline friend bool operator==(const FrameVel& a,const FrameVel& b);
    inline friend bool operator!=(const FrameVel& a,const FrameVel& b);
    inline friend bool operator==(const Frame& a,const FrameVel& b);
    inline friend bool operator!=(const Frame& a,const FrameVel& b);
    inline friend bool operator==(const FrameVel& a,const Frame& b);
    inline friend bool operator!=(const FrameVel& a,const Frame& b);

    inline TwistVel  Inverse(const TwistVel& arg) const;
    inline TwistVel  Inverse(const Twist& arg) const;
    inline TwistVel operator * (const TwistVel& arg) const;
    inline TwistVel operator * (const Twist& arg) const;
};


//very similar to Wrench class.
class TwistVel
// = TITLE
// This class represents a TwistVel. This is a velocity and rotational velocity together
{
public:
    VectorVel vel;
    VectorVel rot;
public:

// = Constructors
    TwistVel():vel(),rot() {};
    TwistVel(const VectorVel& _vel,const VectorVel& _rot):vel(_vel),rot(_rot) {};
    TwistVel(const Twist& p,const Twist& v):vel(p.vel, v.vel), rot( p.rot, v.rot) {};
    TwistVel(const Twist& p):vel(p.vel), rot( p.rot) {};

    Twist value() const {
        return Twist(vel.value(),rot.value());
    }
    Twist deriv() const {
        return Twist(vel.deriv(),rot.deriv());
    }
// = Operators
     inline TwistVel& operator-=(const TwistVel& arg);
     inline TwistVel& operator+=(const TwistVel& arg);

// = External operators
     inline friend TwistVel operator*(const TwistVel& lhs,double rhs);
     inline friend TwistVel operator*(double lhs,const TwistVel& rhs);
     inline friend TwistVel operator/(const TwistVel& lhs,double rhs);

     inline friend TwistVel operator*(const TwistVel& lhs,const doubleVel& rhs);
     inline friend TwistVel operator*(const doubleVel& lhs,const TwistVel& rhs);
     inline friend TwistVel operator/(const TwistVel& lhs,const doubleVel& rhs);

     inline friend TwistVel operator+(const TwistVel& lhs,const TwistVel& rhs);
     inline friend TwistVel operator-(const TwistVel& lhs,const TwistVel& rhs);
     inline friend TwistVel operator-(const TwistVel& arg);
     inline friend void SetToZero(TwistVel& v);


// = Zero
     static inline TwistVel Zero();

// = Reverse Sign
     inline void ReverseSign();

// = Change Reference point
     inline TwistVel RefPoint(const VectorVel& v_base_AB);
     // Changes the reference point of the TwistVel.
     // The VectorVel v_base_AB is expressed in the same base as the TwistVel
     // The VectorVel v_base_AB is a VectorVel from the old point to
     // the new point.
     // Complexity : 6M+6A

     // = Equality operators
     // Tolerant comparison: equal within eps, scaled per physical quantity (see KDL::Equal).
     // operator== compares exactly.
     friend bool Equal(const TwistVel& a,const TwistVel& b,double eps);
     friend bool Equal(const Twist& a,const TwistVel& b,double eps);
     friend bool Equal(const TwistVel& a,const Twist& b,double eps);

     inline friend bool operator==(const TwistVel& a,const TwistVel& b);
     inline friend bool operator!=(const TwistVel& a,const TwistVel& b);
     inline friend bool operator==(const Twist& a,const TwistVel& b);
     inline friend bool operator!=(const Twist& a,const TwistVel& b);
     inline friend bool operator==(const TwistVel& a,const Twist& b);
     inline friend bool operator!=(const TwistVel& a,const Twist& b);

// = Conversion to other entities
     inline Twist GetTwist() const;
     inline Twist GetTwistDot() const;
// = Friends
    friend class RotationVel;
    friend class FrameVel;

};

inline VectorVel diff(const VectorVel& a,const VectorVel& b,double dt=1.0) {
	return VectorVel(diff(a.p,b.p,dt),diff(a.v,b.v,dt));
}

inline VectorVel addDelta(const VectorVel& a,const VectorVel&da,double dt=1.0) {
	return VectorVel(addDelta(a.p,da.p,dt),addDelta(a.v,da.v,dt));
}

VectorVel diff(const RotationVel& a,const RotationVel& b,double dt = 1.0);
RotationVel addDelta(const RotationVel& a,const VectorVel&da,double dt=1.0);
TwistVel diff(const FrameVel& a,const FrameVel& b,double dt=1.0);
FrameVel addDelta(const FrameVel& a,const TwistVel& da,double dt=1.0);

void random(VectorVel& a);
void random(TwistVel& a);
void random(RotationVel& R);
void random(FrameVel& F);
void posrandom(VectorVel& a);
void posrandom(TwistVel& a);
void posrandom(RotationVel& R);
void posrandom(FrameVel& F);

// Methods and operators related to FrameVelVel
// They all delegate most of the work to RotationVelVel and VectorVelVel
inline FrameVel FrameVel::Identity() {
    return FrameVel(RotationVel::Identity(),VectorVel::Zero());
}

inline FrameVel operator *(const FrameVel& lhs,const FrameVel& rhs)
{
    return FrameVel(lhs.M*rhs.M,lhs.M*rhs.p+lhs.p);
}
inline FrameVel operator *(const FrameVel& lhs,const Frame& rhs)
{
    return FrameVel(lhs.M*rhs.M,lhs.M*rhs.p+lhs.p);
}
inline FrameVel operator *(const Frame& lhs,const FrameVel& rhs)
{
    return FrameVel(lhs.M*rhs.M , lhs.M*rhs.p+lhs.p );
}

inline VectorVel FrameVel::operator *(const VectorVel & arg) const
{
    return M*arg+p;
}
inline VectorVel FrameVel::operator *(const Vector & arg) const
{
    return M*arg+p;
}

inline VectorVel FrameVel::Inverse(const VectorVel& arg) const
{
    return M.Inverse(arg-p);
}

inline VectorVel FrameVel::Inverse(const Vector& arg) const
{
    return M.Inverse(arg-p);
}

inline FrameVel FrameVel::Inverse() const
{
    return FrameVel(M.Inverse(),-M.Inverse(p));
}

inline FrameVel& FrameVel::operator = (const Frame& arg) {
    M = arg.M;
    p = arg.p;
    return *this;
}
inline bool operator==(const FrameVel& r1,const FrameVel& r2) {
    return r1.M == r2.M && r1.p == r2.p;
}
inline bool operator!=(const FrameVel& r1,const FrameVel& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const Frame& r1,const FrameVel& r2) {
    return r1.M == r2.M && r1.p == r2.p;
}
inline bool operator!=(const Frame& r1,const FrameVel& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const FrameVel& r1,const Frame& r2) {
    return r1.M == r2.M && r1.p == r2.p;
}
inline bool operator!=(const FrameVel& r1,const Frame& r2) {
    return !operator==(r1,r2);
}

inline Frame FrameVel::GetFrame() const {
    return Frame(M.R,p.p);
}

inline Twist FrameVel::GetTwist() const {
    return Twist(p.v,M.w);
}

inline RotationVel operator* (const RotationVel& r1,const RotationVel& r2) {
    return RotationVel( r1.R*r2.R, r1.w + r1.R*r2.w );
}

inline RotationVel operator* (const Rotation& r1,const RotationVel& r2) {
    return RotationVel( r1*r2.R, r1*r2.w );
}

inline RotationVel operator* (const RotationVel& r1,const Rotation& r2) {
    return RotationVel( r1.R*r2, r1.w );
}

inline RotationVel& RotationVel::operator = (const Rotation& arg) {
    R=arg;
    w=Vector::Zero();
    return *this;
}

inline VectorVel   RotationVel::UnitX() const {
	return VectorVel(R.UnitX(),w*R.UnitX()); 
}

inline VectorVel   RotationVel::UnitY() const {
	return VectorVel(R.UnitY(),w*R.UnitY()); 
}

inline VectorVel   RotationVel::UnitZ() const {
	return VectorVel(R.UnitZ(),w*R.UnitZ()); 
}

inline RotationVel RotationVel::Identity() {
    return RotationVel(Rotation::Identity(),Vector::Zero());
}

inline RotationVel RotationVel::Inverse() const {
    return RotationVel(R.Inverse(),-R.Inverse(w));
}

inline VectorVel RotationVel::Inverse(const VectorVel& arg) const {
    Vector tmp=R.Inverse(arg.p);
    return VectorVel(tmp,
                    R.Inverse(arg.v-w*arg.p)
                    );
}

inline VectorVel RotationVel::Inverse(const Vector& arg) const {
    Vector tmp=R.Inverse(arg);
    return VectorVel(tmp,
                    R.Inverse(-w*arg)
                    );
}

inline VectorVel RotationVel::operator*(const VectorVel& arg) const {
    Vector tmp=R*arg.p;
    return VectorVel(tmp,w*tmp+R*arg.v);
}

inline VectorVel RotationVel::operator*(const Vector& arg) const {
    Vector tmp=R*arg;
    return VectorVel(tmp,w*tmp);
}

inline VectorVel operator + (const VectorVel& r1,const VectorVel& r2) {
    return VectorVel(r1.p+r2.p,r1.v+r2.v);
}

inline VectorVel operator - (const VectorVel& r1,const VectorVel& r2) {
    return VectorVel(r1.p-r2.p,r1.v-r2.v);
}

inline VectorVel operator + (const VectorVel& r1,const Vector& r2) {
    return VectorVel(r1.p+r2,r1.v);
}

inline VectorVel operator - (const VectorVel& r1,const Vector& r2) {
    return VectorVel(r1.p-r2,r1.v);
}

inline VectorVel operator + (const Vector& r1,const VectorVel& r2) {
    return VectorVel(r1+r2.p,r2.v);
}

inline VectorVel operator - (const Vector& r1,const VectorVel& r2) {
    return VectorVel(r1-r2.p,-r2.v);
}

// unary -
inline VectorVel operator - (const VectorVel& r) {
    return VectorVel(-r.p,-r.v);
}

inline void SetToZero(VectorVel& v){
    SetToZero(v.p);
    SetToZero(v.v);
}

// cross prod.
inline VectorVel operator * (const VectorVel& r1,const VectorVel& r2) {
    return VectorVel(r1.p*r2.p, r1.p*r2.v+r1.v*r2.p);
}

inline VectorVel operator * (const VectorVel& r1,const Vector& r2) {
    return VectorVel(r1.p*r2, r1.v*r2);
}

inline VectorVel operator * (const Vector& r1,const VectorVel& r2) {
    return VectorVel(r1*r2.p, r1*r2.v);
}

// scalar mult.
inline VectorVel operator * (double r1,const VectorVel& r2) {
    return VectorVel(r1*r2.p, r1*r2.v);
}

inline VectorVel operator * (const VectorVel& r1,double r2) {
    return VectorVel(r1.p*r2, r1.v*r2);
}

inline VectorVel operator * (const doubleVel& r1,const VectorVel& r2) {
    return VectorVel(r1.t*r2.p, r1.t*r2.v + r1.grad*r2.p);
}

inline VectorVel operator * (const VectorVel& r2,const doubleVel& r1) {
    return VectorVel(r1.t*r2.p, r1.t*r2.v + r1.grad*r2.p);
}

inline VectorVel operator / (const VectorVel& r1,double r2) {
    return VectorVel(r1.p/r2, r1.v/r2);
}

inline VectorVel operator / (const VectorVel& r2,const doubleVel& r1) {
    return VectorVel(r2.p/r1.t, r2.v/r1.t - r2.p*r1.grad/r1.t/r1.t);
}

inline VectorVel operator*(const Rotation& R,const VectorVel& x) {
    return VectorVel(R*x.p,R*x.v);
}

inline VectorVel& VectorVel::operator = (const Vector& arg) {
    p=arg;
    v=Vector::Zero();
    return *this;
}
inline VectorVel& VectorVel::operator += (const VectorVel& arg) {
    p+=arg.p;
    v+=arg.v;
    return *this;
}
inline VectorVel& VectorVel::operator -= (const VectorVel& arg) {
    p-=arg.p;
    v-=arg.v;
    return *this;
}

inline VectorVel VectorVel::Zero() {
    return VectorVel(Vector::Zero(),Vector::Zero());
}
inline void VectorVel::ReverseSign() {
    p.ReverseSign();
    v.ReverseSign();
}
// operator== is exact and member-wise, consistent with std::hash; a double type
// equals a Vel type when the derivative is exactly zero. Use Equal() for tolerance.
inline bool operator==(const VectorVel& r1,const VectorVel& r2) {
    return r1.p == r2.p && r1.v == r2.v;
}
inline bool operator!=(const VectorVel& r1,const VectorVel& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const Vector& r1,const VectorVel& r2) {
    return r1 == r2.p && r2.v == Vector::Zero();
}
inline bool operator!=(const Vector& r1,const VectorVel& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const VectorVel& r1,const Vector& r2) {
    return r1.p == r2 && r1.v == Vector::Zero();
}
inline bool operator!=(const VectorVel& r1,const Vector& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const RotationVel& r1,const RotationVel& r2) {
    return r1.R == r2.R && r1.w == r2.w;
}
inline bool operator!=(const RotationVel& r1,const RotationVel& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const Rotation& r1,const RotationVel& r2) {
    return r1 == r2.R && r2.w == Vector::Zero();
}
inline bool operator!=(const Rotation& r1,const RotationVel& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const RotationVel& r1,const Rotation& r2) {
    return r1.R == r2 && r1.w == Vector::Zero();
}
inline bool operator!=(const RotationVel& r1,const Rotation& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const TwistVel& a,const TwistVel& b) {
    return a.vel == b.vel && a.rot == b.rot;
}
inline bool operator!=(const TwistVel& a,const TwistVel& b) {
    return !operator==(a,b);
}
inline bool operator==(const Twist& a,const TwistVel& b) {
    return a.vel == b.vel && a.rot == b.rot;
}
inline bool operator!=(const Twist& r1,const TwistVel& r2) {
    return !operator==(r1,r2);
}
inline bool operator==(const TwistVel& r1,const Twist& r2) {
    return r1.vel == r2.vel && r1.rot == r2.rot;
}
inline bool operator!=(const TwistVel& r1,const Twist& r2) {
    return !operator==(r1,r2);
}

inline doubleVel dot(const VectorVel& lhs,const VectorVel& rhs) {
    return doubleVel(dot(lhs.p,rhs.p),dot(lhs.p,rhs.v)+dot(lhs.v,rhs.p));
}
inline doubleVel dot(const VectorVel& lhs,const Vector& rhs) {
    return doubleVel(dot(lhs.p,rhs),dot(lhs.v,rhs));
}
inline doubleVel dot(const Vector& lhs,const VectorVel& rhs) {
    return doubleVel(dot(lhs,rhs.p),dot(lhs,rhs.v));
}

inline TwistVel TwistVel::Zero()
{
    return TwistVel(VectorVel::Zero(),VectorVel::Zero());
}

inline void TwistVel::ReverseSign()
{   
    vel.ReverseSign();
    rot.ReverseSign();
}

inline TwistVel TwistVel::RefPoint(const VectorVel& v_base_AB)
     // Changes the reference point of the TwistVel.
     // The VectorVel v_base_AB is expressed in the same base as the TwistVel
     // The VectorVel v_base_AB is a VectorVel from the old point to
     // the new point.
     // Complexity : 6M+6A
{
    return TwistVel(this->vel+this->rot*v_base_AB,this->rot);
}

inline TwistVel& TwistVel::operator-=(const TwistVel& arg)
{
    vel-=arg.vel;
    rot -=arg.rot;
    return *this;
}

inline TwistVel& TwistVel::operator+=(const TwistVel& arg)
{
    vel+=arg.vel;
    rot +=arg.rot;
    return *this;
}

inline TwistVel operator*(const TwistVel& lhs,double rhs)
{
    return TwistVel(lhs.vel*rhs,lhs.rot*rhs);
}

inline TwistVel operator*(double lhs,const TwistVel& rhs)
{
    return TwistVel(lhs*rhs.vel,lhs*rhs.rot);
}

inline TwistVel operator/(const TwistVel& lhs,double rhs)
{
    return TwistVel(lhs.vel/rhs,lhs.rot/rhs);
}

inline TwistVel operator*(const TwistVel& lhs,const doubleVel& rhs)
{
    return TwistVel(lhs.vel*rhs,lhs.rot*rhs);
}

inline TwistVel operator*(const doubleVel& lhs,const TwistVel& rhs)
{
    return TwistVel(lhs*rhs.vel,lhs*rhs.rot);
}

inline TwistVel operator/(const TwistVel& lhs,const doubleVel& rhs)
{
    return TwistVel(lhs.vel/rhs,lhs.rot/rhs);
}

// addition of TwistVel's
inline TwistVel operator+(const TwistVel& lhs,const TwistVel& rhs)
{
    return TwistVel(lhs.vel+rhs.vel,lhs.rot+rhs.rot);
}

inline TwistVel operator-(const TwistVel& lhs,const TwistVel& rhs)
{
    return TwistVel(lhs.vel-rhs.vel,lhs.rot-rhs.rot);
}

// unary -
inline TwistVel operator-(const TwistVel& arg) 
{
    return TwistVel(-arg.vel,-arg.rot);
}

inline void SetToZero(TwistVel& v)
{
   SetToZero(v.vel);
   SetToZero(v.rot);
}

inline TwistVel RotationVel::Inverse(const TwistVel& arg) const
{
    return TwistVel(Inverse(arg.vel),Inverse(arg.rot));
}

inline TwistVel RotationVel::operator * (const TwistVel& arg) const
{
    return TwistVel((*this)*arg.vel,(*this)*arg.rot);
}

inline TwistVel RotationVel::Inverse(const Twist& arg) const
{
    return TwistVel(Inverse(arg.vel),Inverse(arg.rot));
}

inline TwistVel RotationVel::operator * (const Twist& arg) const
{
    return TwistVel((*this)*arg.vel,(*this)*arg.rot);
}

inline TwistVel FrameVel::operator * (const TwistVel& arg) const
{
    TwistVel tmp;
    tmp.rot = M*arg.rot;
    tmp.vel = M*arg.vel+p*tmp.rot;
    return tmp;
}

inline TwistVel FrameVel::operator * (const Twist& arg) const
{
    TwistVel tmp;
    tmp.rot = M*arg.rot;
    tmp.vel = M*arg.vel+p*tmp.rot;
    return tmp;
}

inline TwistVel FrameVel::Inverse(const TwistVel& arg) const
{
    TwistVel tmp;
    tmp.rot =  M.Inverse(arg.rot);
    tmp.vel = M.Inverse(arg.vel-p*arg.rot);
    return tmp;
}

inline TwistVel FrameVel::Inverse(const Twist& arg) const
{
    TwistVel tmp;
    tmp.rot =  M.Inverse(arg.rot);
    tmp.vel = M.Inverse(arg.vel-p*arg.rot);
    return tmp;
}

inline Twist TwistVel::GetTwist() const {
    return Twist(vel.p,rot.p);
}

inline Twist TwistVel::GetTwistDot() const {
    return Twist(vel.v,rot.v);
}

} // namespace KDL

template<> struct std::hash<KDL::doubleVel>
{
    std::size_t operator()(KDL::doubleVel const& dv) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, dv.value());
        KDL::hash_combine(seed, dv.deriv());
        return seed;
    }
};

template<> struct std::hash<KDL::VectorVel>
{
    std::size_t operator()(KDL::VectorVel const& vv) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, vv.p);
        KDL::hash_combine(seed, vv.v);
        return seed;
    }
};

template<> struct std::hash<KDL::RotationVel>
{
    std::size_t operator()(KDL::RotationVel const& rv) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, rv.R);
        KDL::hash_combine(seed, rv.w);
        return seed;
    }
};

template<> struct std::hash<KDL::FrameVel>
{
    std::size_t operator()(KDL::FrameVel const& fv) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, fv.M);
        KDL::hash_combine(seed, fv.p);
        return seed;
    }
};

template<> struct std::hash<KDL::TwistVel>
{
    std::size_t operator()(KDL::TwistVel const& tv) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, tv.vel);
        KDL::hash_combine(seed, tv.rot);
        return seed;
    }
};

#endif
