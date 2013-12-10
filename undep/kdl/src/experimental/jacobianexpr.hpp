/***************************************************************************
                        JacobianExpr.h -  description
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
#ifndef KDL_JACOBIANEXPR_H
#define KDL_JACOBIANEXPR_H

#include <kdl/traits.h>
#include <kdl/jacobian.hpp>
#include <iostream>
 

#define INLINE2
namespace KDL {

/**
 * \brief A reference to T.
 *
 * Replaces T such that a pointer to T is copied instead of copying T itself.
 * - Jacobian<T> can be used as a template parameter for Expr<T>
 * - This class is used to avoid early destruction of objects and at the same time avoid
 *   copy construction of the Jacobian<T> classes.
 *
 * \warning <b>You should never construct this class with a temperary variable</b>
 */
template <typename T>
class Ref {
public:
	typedef typename T::exprType exprType; 
	typedef typename T::derivType derivType;
	typedef typename T::valueType valueType;
    const T* ref;


    INLINE Ref(const T& _ref):ref(&_ref) {}
	INLINE Ref(const Ref<T>& arg):ref(arg.ref) {}
	Ref<T>& operator = (const Ref<T>& arg) {
		ref = arg.ref;
	}
    INLINE derivType deriv(int i) const{
        return ref->deriv(i);
    }
    INLINE valueType value() const {
        return ref->value();
    }
    INLINE int nrOfDeriv() const {
        return ref->nrOfDeriv();
    }
	INLINE JacobianBitset getDerivs() const {
		return ref->getDerivs();
	}
	INLINE bool hasDeriv(int i) const {
		return ref->hasDeriv(i);
	}
};


/**
 * \brief A type to specify the implementation of a unary operation.
 *
 * An implementation of a unary operation constructs a template specialization.  You can see this
 * as a compile-time lookup table that finds the correct operation depending on the operator and
 * the type of its argument.
 * 
 * <b>A</b> is the type of the value of the argument.  (The type of the derivative of the argument
 * is determined by the GeomTraits classes).
 *
 * The marker class <b>OpID</b> is a type that is created to specify a binary operator.  
 *  For example, the unary - operator
 *  corresponds to OpNegate.  This is done because the operators themself cannot serve as template parameters.
 *  There can only be one specification type for each operator.  E.g. defining
 *   OpMinus also created with the unary - operator for other another type A  will lead to compile-time errors.
 *  This type can be created with an empty class declaration.
 *
 * Specializations should define the following :
 *	- a type <b>valueType</b> defining the type of the value of the result of this unary operator.
 *  - a type <b>derivType</b> defining the type of the derivative of the result of this unary operator.
 *  - a method valueType value(const A& arg)   or  valueType value(A arg)
 *    Sometimes it is much more efficient to pass a type by value instead of by reference.  This is the 
 *    case for double.
 *  - a method derivType deriv(const A& arg, const B& darg).  or equivalent argument types.
 *    <b>B</b> corresponds the type of the derivative of arg. (in general: mTraits<A>::derivType,
 *    you can fill in the specific type in these classes )
 * For example
 * \verbatim
	template <>
	class UnaryOp<OpNegate,double> {
	public:
		typedef double valueType;
		typedef double derivType;
		static valueType value(double F) {
			return -F;
		}
		static derivType deriv(double a ,double da) {
			return -da;
		}
	};
   \endverbatim
 */
template <typename OpID,typename A>
class UnaryOp {
};


/**
 * \brief A type to specify a unary operation.
 *
 * <b>OpID</b> is a specialization of the UnaryOp template class.
 * <b>A</b> is the type of the variable on which the unary operator is applied.
 */
template <class A,class OpID>
class Unary {
public:    
	typedef UnaryOp<OpID,typename A::exprType> MyOp;
    typedef typename MyOp::exprType  exprType;
	typedef typename MyOp::valueType valueType;
	typedef typename MyOp::derivType derivType;
    A a;

    INLINE Unary(const A& _a):a(_a) {}  
    INLINE derivType deriv(int i) const {		
		assert(a.hasDeriv(i)); // should not be called when a is constant.
        return MyOp::deriv(a.value(),a.deriv(i));
    }
    INLINE valueType value() const {
			return MyOp::value(a.value());
    }
    INLINE JacobianBitset getDerivs() const {
		return a.getDerivs();
	}
	INLINE bool hasDeriv(int i) const {
		return a.hasDeriv(i);
	}
	/**
	 * Returns the total number of variables.
	 */
    INLINE int nrOfDeriv() const {
        return a.nrOfDeriv();
    }
};

#if 0  // OBSOLETE
/**
 * \brief A type to specify a unary operation.
 *
 * <b>OpID</b> is a specialization of the UnaryOp template class.
 * <b>A</b> is the type of the variable on which the unary operator is applied.
 */
template <class A,class OpID>
class Unary {
public:    
	typedef UnaryOp<OpID,typename A::valueType> MyOp;
	typedef typename MyOp::valueType valueType;
	typedef typename MyOp::derivType derivType;
    A a;

    INLINE Unary(const A& _a):a(_a) {}  
    INLINE derivType deriv(int i) const {		
		assert(!a.isConstant()); // should not be called when a is constant.
        return MyOp::deriv(a.value(),a.deriv(i));
    }
    INLINE valueType value() const {
			return MyOp::value(a.value());
    }
    INLINE JacobianBitset getDerivs() const {
		return a.getDerivs();
	}
	INLINE bool hasDeriv(int i) const {
		return a.hasDeriv(i);
	}
    INLINE int nrOfDeriv() const {
        return a.nrOfDeriv();
    }
};

#endif


template <typename ID,typename A,typename B>
class BinaryOp {
public:
};



/**
 * \brief A type to specify the implementation of a binary operation.
 *
 * An implementation of a binary operation constructs a template specialization. You can see this
 * as a compile-time lookup table that finds the correct operation depending on the operator and
 * the type of its two arguments.
 * 
 * Template arguments:
 * -<b>A</b> is the type of the value of the argument 1. 
 * -<b>B</b> is the type of the value of the argument 2. 
 *
 * - The marker class <b>OpID</b> is a type that is created to specify a binary operator.  For example, the binary + operator
 *   is specified by OpAdd.  There can only be one specification type for each operator.  E.g. defining
 *   OpSum also created with the + operator for other types A and B will lead to compile-time errors.
 *   This type can be created with an empty class declaration.
 *
 * Specializations should define the following :
 *	- a type <b>valueType</b> defining the type of the value of the result of this unary operator.
 *  - a type <b>derivType</b> defining the type of the derivative of the result of this unary operator.
 *  - a method <b>valueType value(const A& arg1,const B& arg2)</b>
 *  - a method <b>derivType derivVV(const A& arg1, const derivA& darg1, const B& arg2, const derivB& darg2)</b>.  
 *  - additional methods <b>derivVC</b>, <b>derivCV</b>.
 *
 * In the above method names, V stands for variable, C stands for constant (ie derivatives==0).
 *    <b>B</b> corresponds the type of the derivative of arg. (in general: GeomTraits<A>::derivType,
 *    you can fill in the specific type in these classes ).  derivCC does not need to exist because
 *    it is known that in that case the derivatives are always zero.
 *
 * For example
 * \verbatim
		template <>
		class BinaryOp<OpMult,double,double> {
		public:
			typedef double valueType;
			typedef double derivType;
			INLINE2 static double value(double a,double b)  {
				return a*b;
			}
			INLINE2 static double derivVV(double a,double da,double b,double db) {
				return a*db + da*b;
			}
			INLINE2 static derivType derivCV(double a,double b,double db) {
				return a*db;
			}
			INLINE2 static derivType derivVC(double a,double da,double b) {
				return da*b;
			}
		};
   \endverbatim
 */

#if 0   //OBSOLETE
template <class A,class B,class OpID>
class Binary {
public:    
	typedef BinaryOp<OpID,typename A::valueType,typename B::valueType> MyOp;
	typedef typename MyOp::valueType valueType;
	typedef typename MyOp::derivType derivType;
    A a;
    B b;

    INLINE Binary(const A& _a,const B& _b):a(_a),b(_b) {}  
    INLINE derivType deriv(int i) const {
		if (a.isConstant()) {
			// deriv should not be called when the result is constant
			assert(!b.isConstant()); 
			return MyOp::derivCV(a.value(),b.value(),b.deriv(i));
		} 
		if (b.isConstant()) {
			return MyOp::derivVC(a.value(),a.deriv(i),b.value());
		}
        return MyOp::derivVV(a.value(),a.deriv(i),b.value(),b.deriv(i));
    }
    INLINE valueType value() const {
        return MyOp::value(a.value(),b.value());
    }
    INLINE int nrOfDeriv() const {
		if (!a.isConstant()) return a.nrOfDeriv();
		if (!b.isConstant()) return b.nrOfDeriv();
        return 0;
    }
	INLINE bool isConstant() const {
		return a.isConstant() && b.isConstant();
	}
};
#endif  // OBSOLETE

template <class A,class B,class OpID>
class Binary {
public:    
	typedef BinaryOp<OpID,typename A::exprType,typename B::exprType> MyOp;
    
	typedef typename MyOp::exprType  exprType;
	typedef typename MyOp::valueType valueType;
	typedef typename MyOp::derivType derivType;
    A a;
    B b;
	JacobianBitset hasderiv;
	
    INLINE Binary(const A& _a,const B& _b):a(_a),b(_b),hasderiv(_a.getDerivs()|_b.getDerivs()) {}  
    INLINE derivType deriv(int i) const {
		if (a.hasDeriv(i)) {
			if (b.hasDeriv(i)) {
				return MyOp::derivVV(a.value(),a.deriv(i),b.value(),b.deriv(i));
			} else {
				return MyOp::derivVC(a.value(),a.deriv(i),b.value());
			}
		} else {
			assert(b.hasDeriv(i)); 
			return MyOp::derivCV(a.value(),b.value(),b.deriv(i));
		}       
    }
    INLINE valueType value() const {
        return MyOp::value(a.value(),b.value());
    }
    INLINE int nrOfDeriv() const {
		int r = a.nrOfDeriv();
		if (r==0) r = b.nrOfDeriv();
		return r;
    }
	INLINE JacobianBitset getDerivs() const {
		return hasderiv;
	}
	INLINE bool hasDeriv(int i) const {
		return hasderiv[i];
	}
};

/**
 * Defines a template operator to connect a given operator NAME with the implementation IMPL.
 * - NAME stands for the operator, e.g. operator-  or sin
 * - IMPL stands for the maker class corresponding to this operator.
 * The argument of this operator is a type Expr<A>
 */
#define DEFUNARY_EXPR(NAME,IMPL) \
template <typename A>\
INLINE Expr< Unary< A, IMPL> >\
NAME (const Expr<A>& a) {\
    typedef Unary< A, IMPL> MyType;\
    return MyType(a.elem);\
}

/**
 * Defines a template method to connect a given operator NAME with the implementation IMPL.
 * - NAME stands for the operator, e.g. operator-  or sin
 * - IMPL stands for the maker class corresponding to this operator.
 * - TYPE stands for the type of the argument.
 * The argument of this operator is a type TYPE that serves as an argument to our operation
 * TYPE is normally of the form Ref<Jacobian<..> >.
 */
#define DEFUNARY_TYPE(NAME,IMPL,TYPE) \
INLINE Expr< Unary< TYPE, IMPL> >\
NAME(const TYPE& a) {\
    typedef Unary< TYPE , IMPL> MyType;\
    return MyType(a);\
}



/**
 * Defines a template operator to connect a given operator NAME with the implementation IMPL.
 * - NAME stands for the operator, e.g. operator-  or sin
 * - IMPL stands for the maker class corresponding to this operator.
 * The argument of this operator are of type Expr\<A\> and Expr\<B\>
 */
#define DEFBINARY_EXPR(NAME, IMPL) \
template <typename A,typename B>\
INLINE Expr< Binary< A, B, IMPL >  >\
NAME (const Expr<A>& a,const Expr<B>& b) {\
    typedef Binary<A,B, IMPL> MyType;\
    return MyType(a.elem,b.elem);\
}


/**
 * Defines a template method to connect a given operator NAME with the implementation IMPL.
 * - NAME stands for the operator, e.g. operator-  or sin
 * - IMPL stands for the maker class corresponding to this operator.
 * - RTYPE stands for the type of the 2nd argument (<b>R</b>ight hand side)
 * The arguments of this operator are Expr<..> and RTYPE.
 * RTYPE is normally of the form Ref<Jacobian<..> >.
 */
#define DEFBINARY_RTYPE(NAME, IMPL, RTYPE) \
template <typename A>\
INLINE Expr< Binary< A, RTYPE, IMPL >  >\
	NAME (const Expr<A>& a,const RTYPE& b) {\
    typedef Binary<A,RTYPE, IMPL> MyType;\
    return MyType(a.elem,b);\
}

/**
 * Defines a template method to connect a given operator NAME with the implementation IMPL.
 * - NAME stands for the operator, e.g. operator-  or sin
 * - IMPL stands for the maker class corresponding to this operator.
 * - LTYPE stands for the type of the 1st argument (<b>L</b>eft hand side)
 * The arguments of this operator are LTYPE and Expr<..>.
 * LTYPE is normally of the form Ref<Jacobian<..> >.
 */
#define DEFBINARY_LTYPE(NAME, IMPL, LTYPE) \
template <typename B>\
INLINE Expr< Binary< LTYPE , B, IMPL >  >\
	NAME (const LTYPE& a,const Expr<B>& b) {\
    typedef Binary< LTYPE , B, IMPL> MyType;\
    return MyType(a,b.elem);\
}

/**
 * Defines a template method to connect a given operator NAME with the implementation IMPL.
 * - NAME stands for the operator, e.g. operator-  or sin
 * - IMPL stands for the maker class corresponding to this operator.
 * - LTYPE stands for the type of the 1st argument (<b>L</b>eft hand side)
 * - RTYPE stands for the type of the 2nd argument (<b>R</b>ight hand side)
 * The arguments of this operator are LTYPE and RTYPE.
 * LTYPE and RTYPE are normally of the form Ref<Jacobian<..> >.
 */
#define DEFBINARY_RLTYPE(NAME, IMPL, LTYPE,RTYPE) \
INLINE Expr< Binary< LTYPE, RTYPE, IMPL >  >\
	NAME (const LTYPE& a,const RTYPE& b) {\
    typedef Binary< LTYPE, RTYPE, IMPL > MyType;\
    return MyType(a,b);\
}

 /* obsolete
#define DEFBINARY(NAME,IMPL,LTYPE,RTYPE)\
	DEFBINARY_RTYPE(NAME,IMPL,RTYPE) \
	DEFBINARY_LTYPE(NAME,IMPL,LTYPE) \
	DEFBINARY_RLTYPE(NAME,IMPL,LTYPE,RTYPE)
*/


/*****************************************************************************/

/**
 * Outputs a variable of type Jacobian<T>.
 */
template <typename T>
std::ostream& operator << (std::ostream& os, const Jacobian<T>& F) {
	os << "[ Value " << std::endl;
	os << F.value() << std::endl;
	if (F.hasDerivs()) {
		os << "Derivative[" << std::endl;
		for (int i = 0;i<F.nrOfDeriv();++i) 
			if (F.hasDeriv(i)) {
				os << F.deriv(i) <<std::endl;
			} else {
				os << "CONSTANT" <<std::endl;
			}
		os << "]";
	} else {
		os << "ALL CONSTANT" << std::endl;
	}
	os << "]";
	return os;
}


// Some utility function to easily specify a constant :
template <typename T>
Jacobian<T> Constant(const T& arg) {
	return arg;
}

/*****************************************************************************/
/* DEFINE Marker-classes for the operations                                  */
/*  These classes associate a TYPE with an OPERATOR                          */
/*****************************************************************************/

// Binary operators :
class OpMult{};
DEFBINARY_EXPR(operator*,OpMult);
class OpDiv{};
DEFBINARY_EXPR(operator/,OpDiv);
class OpAdd{};
DEFBINARY_EXPR(operator+,OpAdd);
class OpSub{};
DEFBINARY_EXPR(operator-,OpSub);
class OpDot {};
DEFBINARY_EXPR(dot,OpDot);

class OpDiff {};
DEFBINARY_EXPR(Diff,OpDiff);

class OpAtan2 {};
DEFBINARY_EXPR(atan2,OpAtan2);

class OpRefPoint{};
DEFBINARY_EXPR(RefPoint,OpRefPoint);

// Unary operators :
class OpNegate {};
DEFUNARY_EXPR(operator-,OpNegate);
class OpSin {};
DEFUNARY_EXPR(sin,OpSin);
class OpCos {};
DEFUNARY_EXPR(cos,OpCos);
class OpTan {};
DEFUNARY_EXPR(tan,OpTan);
class OpExp {};
DEFUNARY_EXPR(exp,OpExp);
class OpLog {};
DEFUNARY_EXPR(log,OpLog);
class OpSqrt {};
DEFUNARY_EXPR(sqrt,OpSqrt);
class OpAtan {};
DEFUNARY_EXPR(atan,OpAtan);
class OpAsin {};
DEFUNARY_EXPR(asin,OpAsin);
class OpAcos {};
DEFUNARY_EXPR(acos,OpAcos);
class OpAbs {};
DEFUNARY_EXPR(abs,OpAbs);

class OpNorm {};
DEFUNARY_EXPR(norm,OpNorm);
class OpInverse {};
DEFUNARY_EXPR(Inverse,OpInverse);
class OpRotX {};
DEFUNARY_EXPR(RotX,OpRotX);
class OpRotY {};
DEFUNARY_EXPR(RotY,OpRotY);
class OpRotZ {};
DEFUNARY_EXPR(RotZ,OpRotZ);
/*
class OpSelectX {};
DEFUNARY_EXPR(SelectX,OpSelectX);
class OpSelectY {};
DEFUNARY_EXPR(SelectY,OpSelectY);
class OpSelectZ {};
DEFUNARY_EXPR(SelectZ,OpSelectZ);
*/

class OpRotation {};
DEFUNARY_EXPR(RotMat,OpRotation);

class OpOrigin {};
DEFUNARY_EXPR(Origin,OpOrigin);

class OpUnitX {};
DEFUNARY_EXPR(UnitX,OpUnitX);

class OpUnitY {};
DEFUNARY_EXPR(UnitY,OpUnitY);

class OpUnitZ {};
DEFUNARY_EXPR(UnitZ,OpUnitZ);


class OpCoordX {};
DEFUNARY_EXPR(CoordX,OpCoordX);

class OpCoordY {};
DEFUNARY_EXPR(CoordY,OpCoordY);

class OpCoordZ {};
DEFUNARY_EXPR(CoordZ,OpCoordZ);



} // namespace ORO_GEOMETRY
#endif



