/***************************************************************************
                        JacobianDouble.h -  description
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Erwin Aertbelien
    email                : firstname.lastname@mech.kuleuven.ac.be

 History (only major changes)( AUTHOR-Description ) :
 
 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef KDL_JACOBIANDOUBLE_H
#define KDL_JACOBIANDOUBLE_H

#include <kdl/jacobianexpr.hpp>
#include <math.h>

#define INLINE2 
 
/**
 * \file
 * The classes defined in this file are normally never used by the user of this 
 * library.  They are used to implement the operations on Jacobian<double>.
 *
 * OPERATIONS implemented on Jacobian<double> :
 *   binary operators : + - * / atan2
 *   unary operators  : - sin cos asin acos exp log sqrt atan abs
 */

namespace KDL {
/*****************************************************************************/
template <>
class BinaryOp<OpMult,double,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	INLINE2 static double value(double a,double b)  {
		return a*b;
	}
	INLINE2 static double derivVV(double a,double da,double b,double db) {
        return a*db + da*b;
	}
	INLINE2 static derivType derivCV(double a,double /* b*/,double db) {
        return a*db;
	}
	INLINE2 static derivType derivVC(double /*a*/,double da,double b) {
        return da*b;
	}
};

DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<double> >) 
DEFBINARY_LTYPE(operator*,OpMult,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<double> >,Ref<Jacobian<double> >)

template <>
class BinaryOp<OpDiv,double,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	INLINE2 static double value(double a,double b)  {
		return a/b;
	}
	INLINE2 static double derivVV(double a,double da,double b,double db) {
        return (b*da-a*db)/b/b;
	}
	INLINE2 static derivType derivCV(double a,double b,double db) {
        return -a/b/b*db;
	}
	INLINE2 static derivType derivVC(double /*a*/,double da,double b) {
        return da/b;
	}
};

DEFBINARY_RTYPE(operator/,OpDiv,Ref<Jacobian<double> >) 
DEFBINARY_LTYPE(operator/,OpDiv,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(operator/,OpDiv,Ref<Jacobian<double> >,Ref<Jacobian<double> >)


template <>
class BinaryOp<OpAdd,double,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	INLINE2 static double value(double a,double b)  {
		return a+b;
	}
	INLINE2 static double derivVV(double ,double da,double ,double db) {
        return da+db;
	}
	INLINE2 static derivType derivCV(double ,double ,double db) {
        return db;
	}
	INLINE2 static derivType derivVC(double ,double da,double ) {
        return da;
	}
};
DEFBINARY_RTYPE(operator+,OpAdd,Ref<Jacobian<double> >) 
DEFBINARY_LTYPE(operator+,OpAdd,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(operator+,OpAdd,Ref<Jacobian<double> >,Ref<Jacobian<double> >)

template <>
class BinaryOp<OpSub,double,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	INLINE2 static double value(double a,double b)  {
		return a-b;
	}
	INLINE2 static double derivVV(double /*a*/,double da,double /*b*/,double db) {
        return da-db;
	}
	INLINE2 static derivType derivCV(double /*a*/,double /*b*/,double db) {
        return db;
	}
	INLINE2 static derivType derivVC(double /*a*/,double da,double /*b*/) {
        return da;
	}
};
DEFBINARY_RTYPE(operator-,OpSub,Ref<Jacobian<double> >) 
DEFBINARY_LTYPE(operator-,OpSub,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(operator-,OpSub,Ref<Jacobian<double> >,Ref<Jacobian<double> >)


template <>
class UnaryOp<OpNegate,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double F) {
		return -F;
	}
	static INLINE2 derivType deriv(double /*a*/ ,double da) {
		return -da;
	}
};
DEFUNARY_TYPE(operator-,OpNegate,Ref< Jacobian<double> >)

template <>
class UnaryOp<OpSin,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::sin(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
        return ::cos(a)*da;
	}
};
DEFUNARY_TYPE(sin,OpSin,Ref< Jacobian<double> >)


template <>
class UnaryOp<OpAbs,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::fabs(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
        return sign(a)*da;
	}
};
DEFUNARY_TYPE(abs,OpAbs,Ref< Jacobian<double> >)

template <>
class UnaryOp<OpTan,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::tan(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
        double c = ::cos(a);
		return da/c/c;
	}
};
DEFUNARY_TYPE(tan,OpTan,Ref< Jacobian<double> >)

template <>
class UnaryOp<OpCos,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::cos(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
        return -::sin(a)*da;
	}
};
DEFUNARY_TYPE(cos,OpCos,Ref< Jacobian<double> >)

template <>
class UnaryOp<OpExp,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::exp(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
        return ::exp(a)*da;
	}
};
DEFUNARY_TYPE(exp,OpExp,Ref< Jacobian<double> >)

template <>
class UnaryOp<OpLog,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::log(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
		return da/a;
	}
};
DEFUNARY_TYPE(log,OpLog,Ref< Jacobian<double> >)


template<>
class UnaryOp<OpSqrt,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::sqrt(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
		return 0.5/::sqrt(a)*da;
	}
};
DEFUNARY_TYPE(sqrt,OpSqrt,Ref< Jacobian<double> >)

template<>
class UnaryOp<OpAtan,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::atan(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
		return da/(1+a*a);
	}
};
DEFUNARY_TYPE(atan,OpAtan,Ref< Jacobian<double> >)

template<>
class UnaryOp<OpAsin,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::asin(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
		return da/::sqrt(1-a*a);
	}
};
DEFUNARY_TYPE(asin,OpAsin,Ref< Jacobian<double> >)

template<>
class UnaryOp<OpAcos,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(double a) {
        return ::acos(a);
	}
	static INLINE2 derivType deriv(double a,double da) {
		return -da/::sqrt(1-a*a);
	}
};
DEFUNARY_TYPE(acos,OpAcos,Ref< Jacobian<double> >)


/*****************************************************************************/
template<>
class BinaryOp<OpAtan2,double,double> {
public:
    typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	INLINE2 static double value(double a,double b)  {
		return ::atan2(a,b);
	}
	INLINE2 static double derivVV(double a,double da,double b,double db) {
        return (-a*db+b*da)/(a*a+b*b);
	}
	INLINE2 static derivType derivCV(double a,double b,double db) {
        return (-a*db)/(a*a+b*b);
	}
	INLINE2 static derivType derivVC(double a,double da,double b) {
        return (b*da)/(a*a+b*b);
	}
};

DEFBINARY_RTYPE(atan2,OpAtan2,Ref<Jacobian<double> >) 
DEFBINARY_LTYPE(atan2,OpAtan2,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(atan2,OpAtan2,Ref<Jacobian<double> >,Ref<Jacobian<double> >)











} // namespace
#endif


