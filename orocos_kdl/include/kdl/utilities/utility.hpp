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
 *		$Id: utility.h,v 1.1.1.1.2.4 2003/07/18 14:58:36 psoetens Exp $
 *		$Name:  $ 
 *  \file
 *    Included by most lrl-files to provide some general
 *    functions and macro definitions.
 *  
 *  \par history
 *   - changed layout of the comments to accommodate doxygen
 */


#ifndef KDL_UTILITY_H
#define KDL_UTILITY_H

#include <cstdlib>
#include <cassert>
#include <cmath>


namespace KDL {

#ifdef __GNUC__
    // so that sin,cos can be overloaded and complete 
    // resolution of overloaded functions work.
    using ::sin;
    using ::cos;
    using ::exp;
    using ::log;
    using ::sin;
    using ::cos;
    using ::tan;
    using ::sinh;
    using ::cosh;
    using ::pow;
    using ::sqrt;
    using ::atan;
    using ::hypot;
    using ::asin;
    using ::acos;
    using ::tanh;
    using ::atan2;
#endif
#ifndef __GNUC__
    //only real solution : get Rall1d and varia out of namespaces.
    #pragma warning (disable:4786)

    inline double sin(double a) {
        return ::sin(a);
    }
    
    inline double cos(double a) {
        return ::cos(a);
    }
    inline double exp(double a) {
        return ::exp(a);
    }
    inline double log(double a) {
        return ::log(a);
    }
    inline double tan(double a) {
        return ::tan(a);
    }
    inline double cosh(double a) {
        return ::cosh(a);
    }
    inline double sinh(double a) {
        return ::sinh(a);
    }
    inline double sqrt(double a) {
        return ::sqrt(a);
    }
    inline double atan(double a) {
        return ::atan(a);
    }
    inline double acos(double a) {
        return ::acos(a);
    }
    inline double asin(double a) {
        return ::asin(a);
    }
    inline double tanh(double a) {
        return ::tanh(a);
    }
    inline double pow(double a,double b) {
        return ::pow(a,b);
    }
    inline double atan2(double a,double b) {
        return ::atan2(a,b);
    }
#endif  

#if (__cplusplus > 199711L)
using std::isnan;
#endif

/** 
 * Auxiliary class for argument types (Trait-template class )
 * 
 * Is used to pass doubles by value, and arbitrary objects by const reference.
 * This is TWICE as fast (2 x less memory access) and avoids bugs in VC6++ concerning
 * the assignment of the result of intrinsic functions to const double&-typed variables,
 * and optimization on.
 */
template <class T>
class TI
{
    public:
        using Arg = const T &; //!< Arg is used for passing the element to a function.
};

template <>
class TI<double> {
public:
    using Arg = double;
};

template <>
class TI<int> {
public:
    using Arg = int;
};





/**
 * \note linkage
 * STREAMBUFFERSIZE and MAXLENFILENAME are mutable globals with external linkage.
 * The mathematical constants and the default tolerance epsilon are compile-time
 * constants: they cannot be changed, so reading them never races with a writer.
 */
//! 
extern int          STREAMBUFFERSIZE;

//! maximal length of a file name
extern int          MAXLENFILENAME;

//! the value of pi
inline constexpr double PI      = 3.141592653589793238462643383279502884;

//! the value of pi/2
inline constexpr double PI_2    = 1.570796326794896619231321691639751442;

//! the value of pi/4
inline constexpr double PI_4    = 0.785398163397448309615660845819875721;

//! the value pi/180
inline constexpr double deg2rad = 0.017453292519943295769236907684886127;

//! the value 180/pi
inline constexpr double rad2deg = 57.29577951308232087679815481410517033;

/**
 * Default tolerance of the Equal(..,..) functions, and default degeneracy
 * threshold of Normalize() and Rotation::GetRotAngle(). Pass a different value
 * as their eps argument instead of changing a global.
 */
inline constexpr double epsilon = 1e-6;

//! the number of derivatives used in the RN-... objects.
extern int          VSIZE;



#ifndef _MFC_VER
#undef max
inline double max(double a,double b) {
    if (b<a) 
        return a;
    else
        return b;
}

#undef min
inline double min(double a,double b) {
    if (b<a) 
        return b;
    else
        return a;
}
#endif


inline double LinComb(double alfa,double a,
        double beta,double b ) {
            return alfa*a+beta*b;
}

inline void LinCombR(double alfa,double a,
        double beta,double b,double& result ) {
            result=alfa*a+beta*b;
         }

//! to uniformly set double, RNDouble,Vector,... objects to zero in template-classes
inline void SetToZero(double& arg) {
    arg=0;
}

//! to uniformly set double, RNDouble,Vector,... objects to the identity element in template-classes
inline void SetToIdentity(double& arg) {
    arg=1;
}

inline double sign(double arg) {
    return (arg<0)?(-1):(1);
}

inline double sqr(double arg) { return arg*arg;}
inline double Norm(double arg) {
    return fabs(  (double)arg );
}

#if defined __WIN32__ && !defined __GNUC__
inline double hypot(double y,double x) { return ::_hypot(y,x);}
inline double abs(double x) { return ::fabs(x);}
#endif

/**
 * Tolerant comparison of two doubles:
 * a == b, or a-b is finite and |a-b| <= eps * max(1, |a|, |b|).
 *
 * The tolerance is absolute up to magnitude 1 and relative above it. eps = 0
 * means exact equality, +-inf is equal only to itself and NaN is never equal.
 * Use operator== for exact comparison.
 */
inline bool Equal(double a,double b,double eps=epsilon)
{
    if (a == b)
        return true;
    const double diff = a - b;
    if (!std::isfinite(diff))
        return false;
    double scale = 1.0;
    if (std::fabs(a) > scale)
        scale = std::fabs(a);
    if (std::fabs(b) > scale)
        scale = std::fabs(b);
    return std::fabs(diff) <= eps * scale;
}

namespace detail {
/**
 * Tolerant comparison of one physical quantity of n components a[i] and b[i]:
 * every component satisfies a[i] == b[i], or a[i]-b[i] is finite and
 * |a[i]-b[i]| <= eps * S, with S = max(1, largest finite |a[i]|, |b[i]|).
 *
 * Infinite components set no scale, so they don't loosen the others. This
 * backs the Equal() of the geometric types, with one call per quantity
 * (e.g. Frame::p and Frame::M separately).
 */
bool equalScaled(const double* a, const double* b, int n, double eps);
}

inline void random(double& a) {
	a = 1.98*rand()/(double)RAND_MAX -0.99;
}

inline void posrandom(double& a) {
	a = 0.001+0.99*rand()/(double)RAND_MAX;
}

inline double diff(double a,double b,double dt) {
	return (b-a)/dt;
}
//inline float diff(float a,float b,double dt) {
//return (b-a)/dt;
//}
inline double addDelta(double a,double da,double dt) {
	return a+da*dt;
}

//inline float addDelta(float a,float da,double dt) {
//	return a+da*dt;
//}


}



#endif
