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

inline void random(doubleVel& F) {
	random(F.t);
	random(F.grad);
}
inline void posrandom(doubleVel& F) {
	posrandom(F.t);
	posrandom(F.grad);
}

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
inline bool Equal(const VectorVel& r1,const VectorVel& r2,double eps=epsilon);
inline bool Equal(const Vector& r1,const VectorVel& r2,double eps=epsilon);
inline bool Equal(const VectorVel& r1,const Vector& r2,double eps=epsilon);
inline bool Equal(const RotationVel& r1,const RotationVel& r2,double eps=epsilon);
inline bool Equal(const Rotation& r1,const RotationVel& r2,double eps=epsilon);
inline bool Equal(const RotationVel& r1,const Rotation& r2,double eps=epsilon);
inline bool Equal(const FrameVel& r1,const FrameVel& r2,double eps=epsilon);
inline bool Equal(const Frame& r1,const FrameVel& r2,double eps=epsilon);
inline bool Equal(const FrameVel& r1,const Frame& r2,double eps=epsilon);
inline bool Equal(const TwistVel& a,const TwistVel& b,double eps=epsilon);
inline bool Equal(const Twist& a,const TwistVel& b,double eps=epsilon);
inline bool Equal(const TwistVel& a,const Twist& b,double eps=epsilon);


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

    inline VectorVel& operator = (const VectorVel& arg);
    inline VectorVel& operator = (const Vector& arg);
    inline VectorVel& operator += (const VectorVel& arg);
    inline VectorVel& operator -= (const VectorVel& arg);
    inline static VectorVel Zero();
    inline void ReverseSign();
    inline doubleVel Norm(double eps=epsilon) const;
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


    inline friend bool Equal(const VectorVel& r1,const VectorVel& r2,double eps);
    inline friend bool Equal(const Vector& r1,const VectorVel& r2,double eps);
    inline friend bool Equal(const VectorVel& r1,const Vector& r2,double eps);

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


    inline RotationVel& operator = (const RotationVel& arg);
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
    inline void DoRotX(const doubleVel& angle);
    inline void DoRotY(const doubleVel& angle);
    inline void DoRotZ(const doubleVel& angle);
    inline static RotationVel RotX(const doubleVel& angle);
    inline static RotationVel RotY(const doubleVel& angle);
    inline static RotationVel RotZ(const doubleVel& angle);
    inline static RotationVel Rot(const Vector& rotvec,const doubleVel& angle);
    // rotvec has arbitrary norm
    // rotation around a constant vector !
    inline static RotationVel Rot2(const Vector& rotvec,const doubleVel& angle);
    // rotvec is normalized.
    // rotation around a constant vector !
    inline friend RotationVel operator* (const RotationVel& r1,const RotationVel& r2);
    inline friend RotationVel operator* (const Rotation& r1,const RotationVel& r2);
    inline friend RotationVel operator* (const RotationVel& r1,const Rotation& r2);
    inline friend bool Equal(const RotationVel& r1,const RotationVel& r2,double eps);
    inline friend bool Equal(const Rotation& r1,const RotationVel& r2,double eps);
    inline friend bool Equal(const RotationVel& r1,const Rotation& r2,double eps);

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
    inline FrameVel& operator = (const FrameVel& arg);
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
    inline friend bool Equal(const FrameVel& r1,const FrameVel& r2,double eps);
    inline friend bool Equal(const Frame& r1,const FrameVel& r2,double eps);
    inline friend bool Equal(const FrameVel& r1,const Frame& r2,double eps);

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
     // do not use operator == because the definition of Equal(.,.) is slightly
     // different.  It compares whether the 2 arguments are equal in an eps-interval
     inline friend bool Equal(const TwistVel& a,const TwistVel& b,double eps);
     inline friend bool Equal(const Twist& a,const TwistVel& b,double eps);
     inline friend bool Equal(const TwistVel& a,const Twist& b,double eps);

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
inline VectorVel diff(const RotationVel& a,const RotationVel& b,double dt = 1.0) {
	return VectorVel(diff(a.R,b.R,dt),diff(a.w,b.w,dt));
}

inline RotationVel addDelta(const RotationVel& a,const VectorVel&da,double dt=1.0) {
	return RotationVel(addDelta(a.R,da.p,dt),addDelta(a.w,da.v,dt));
}

inline TwistVel diff(const FrameVel& a,const FrameVel& b,double dt=1.0) {
	return TwistVel(diff(a.p,b.p,dt),diff(a.M,b.M,dt));
}

inline FrameVel addDelta(const FrameVel& a,const TwistVel& da,double dt=1.0) {
	return FrameVel(
			addDelta(a.M,da.rot,dt),
			addDelta(a.p,da.vel,dt)
		   );
}

inline void random(VectorVel& a) {
	random(a.p);
	random(a.v);
}
inline void random(TwistVel& a) {
	random(a.vel);
	random(a.rot);
}

inline void random(RotationVel& R) {
	random(R.R);
	random(R.w);
}

inline void random(FrameVel& F) {
	random(F.M);
	random(F.p);
}
inline void posrandom(VectorVel& a) {
	posrandom(a.p);
	posrandom(a.v);
}
inline void posrandom(TwistVel& a) {
	posrandom(a.vel);
	posrandom(a.rot);
}

inline void posrandom(RotationVel& R) {
	posrandom(R.R);
	posrandom(R.w);
}

inline void posrandom(FrameVel& F) {
	posrandom(F.M);
	posrandom(F.p);
}

#include "framevel.inl"

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
