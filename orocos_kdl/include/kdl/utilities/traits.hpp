#ifndef KDLPV_TRAITS_H 
#define KDLPV_TRAITS_H 

#include "utility.hpp"

 
// forwards declarations :
namespace KDL {
   class Frame;
    class Rotation;
    class Vector;
    class Twist;
    class Wrench;
	class FrameVel;
	class RotationVel;
	class VectorVel;
	class TwistVel;
}


/**
 * @brief Traits are traits classes to determine the type of a derivative of another type.
 *
 * For geometric objects the "geometric" derivative is chosen.  For example the derivative of a Rotation
 * matrix is NOT a 3x3 matrix containing the derivative of the elements of a rotation matrix.  The derivative
 * of the rotation matrix is a Vector corresponding the rotational velocity.  Mostly used in template classes
 * and routines to derive a correct type when needed.
 * 
 * You can see this as a compile-time lookuptable to find the type of the derivative.
 *
 * Example
 * \verbatim
	Rotation R;
    Traits<Rotation> dR;
   \endverbatim
 */
template <typename T>
struct Traits {
	using valueType = T;
	using derivType = T;
};

template <>
struct Traits<KDL::Frame> {
	using valueType = KDL::Frame;
	using derivType = KDL::Twist;
};
template <>
struct Traits<KDL::Twist> {
	using valueType = KDL::Twist;
	using derivType = KDL::Twist;
};
template <>
struct Traits<KDL::Wrench> {
	using valueType = KDL::Wrench;
	using derivType = KDL::Wrench;
};

template <>
struct Traits<KDL::Rotation> {
	using valueType = KDL::Rotation;
	using derivType = KDL::Vector;
};

template <>
struct Traits<KDL::Vector> {
	using valueType = KDL::Vector;
	using derivType = KDL::Vector;
};

template <>
struct Traits<double> {
	using valueType = double;
	using derivType = double;
};

template <>
struct Traits<float> {
	using valueType = float;
	using derivType = float;
};

template <>
struct Traits<KDL::FrameVel> {
	using valueType = KDL::Frame;
	using derivType = KDL::TwistVel;
};
template <>
struct Traits<KDL::TwistVel> {
	using valueType = KDL::Twist;
	using derivType = KDL::TwistVel;
};

template <>
struct Traits<KDL::RotationVel> {
	using valueType = KDL::Rotation;
	using derivType = KDL::VectorVel;
};

template <>
struct Traits<KDL::VectorVel> {
	using valueType = KDL::Vector;
	using derivType = KDL::VectorVel;
};



#endif



