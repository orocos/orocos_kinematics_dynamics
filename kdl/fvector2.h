/*****************************************************************************
 * \file  
 *   FVector2 is a fast and simple class for a vector on which certain
 *   arithmetic functions are defined.  The storage space is
 *   located on the stack, and special definitions for N=2 and N=3 are provided
 *   all member functions are inlined.
 *   Also provides a scalar type S
 *       
 *  \author 
 *      Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version 
 *      ORO_Geometry V2
 *
 *  \par History
 *      - $log$
 * 
 *  \par Release
 *      $Id: fvector2.h,v 1.1.1.1 2002/08/26 14:14:21 rmoreas Exp $
 *      $Name:  $ 
 ****************************************************************************/

#ifndef FVector2_H
#define FVector2_H
#include <kdl/utility.h>
#include <math.h>

namespace KDL {

/**
 * FVector2 is a vectortype with following properties :
 *  - fully inlined code.
 *  - memory is allocated on the stack
 *  - math. operators are defined on the vector
 *  - fixed size N
 *  - element type T
 *  - SCALAR TYPE S is explicitly specified. Scalar multiplication should exist
 *    between T and S.
 *  - provides a SetToZero and Equal function
 * \par Class Type
 * Concrete implementation
 *
 */
template <class T,int N,class S>
class FVector2 
{
public:
// = Private members
    T vect[N];

// = Constructors
    FVector2() {}
    
    FVector2(const T arg[]) {
        int count=N;
        while (count--) vect[count] = arg[count];
    }

    FVector2(const T& arg1) {vect[0]=arg1;}
    
    FVector2(const T& arg1,const T& arg2) {vect[0]=arg1;vect[1]=arg2;}
    
    FVector2(const T& arg1,const T& arg2,const T& arg3) {vect[0]=arg1;vect[1]=arg2;vect[2]=arg3;}

    // always provide a copy constructor
    FVector2(const FVector2<T,N,S>& arg) {
        int count=N;
        while (count--) vect[count] = arg.vect[count];
    }

    static FVector2 Zero() {
        FVector2<T,N,S> tmp;
        SetToZero(tmp);
        return tmp;
    }

// = Assignment operators
    FVector2<T,N,S>& operator = (const FVector2<T,N,S>& arg) {
        int count;
        count=N;
        while (count--) vect[count] = arg.vect[count];
        return *this;
    }
    
    FVector2<T,N,S>& operator +=(const FVector2<T,N,S>& arg) {  
        int count;
        count=N;
        while (count--) vect[count] += arg.vect[count];
        return *this;
    }
    FVector2<T,N,S>& operator -=(const FVector2<T,N,S>& arg) {
        int count=N;
        while (count--) vect[count] -= arg.vect[count];
        return *this;
    }

    // = additional operators for easy use :
    T& operator[] (int i) {
        return vect[i];
    }

    const T& operator[] (int i) const {
        return vect[i];
    }

    // = Utility functions
    
    double max_abs() {
        double tmp(0.0);
        int i;
        i=N;while (i--) {
            double el=fabs(vect[i]);
            if (el > tmp) tmp=el;
        }
        return tmp; 
    }
    // max. of the abs. value of each el
/*  
    // = Operators between FVector2 objects 
    friend FVector2<T,N,S> operator + ( const FVector2<T,N,S>& a,const FVector2<T,N,S>& b);
    friend FVector2<T,N,S> operator - ( const FVector2<T,N,S>& a,const FVector2<T,N,S>& b);
    friend FVector2<T,N,S> operator - ( const FVector2<T,N,S>& a);
    friend FVector2<T,N,S> operator * ( const T& a,const FVector2<T,N,S>& b);
    friend FVector2<T,N,S> operator * ( const FVector2<T,N,S>& a,const T& b);
    friend FVector2<T,N,S> operator / ( const FVector2<T,N,S>& a,const T& b);

    // = Functions that operate on FVector2
    friend double Norm(const FVector2<T,N,S>& a);
    // returns norm of the vector contained in FVector2


    friend FVector2<T,N,S> LinComb(const T& alfa,const FVector2<T,N,S>& a,
        const T& beta,const FVector2<T,N,S>& b );
    
    friend void LinCombR(const T& alfa,const FVector2<T,N,S>& a,
            const T& beta,const FVector2<T,N,S>& b,FVector2<T,N,S>& result );
*/  
};

template <class T,int N,class S>
INLINE FVector2<T,N,S> operator + ( const FVector2<T,N,S>& a,const FVector2<T,N,S>& b) {
    int i;
    FVector2<T,N,S> tmp;
    i=N;while (i--)
        tmp[i]=a[i]+b[i];
    return tmp;
}

template <class T,int N,class S>
INLINE FVector2<T,N,S> operator - ( const FVector2<T,N,S>& a,const FVector2<T,N,S>& b) {
    int i;
    FVector2<T,N,S> tmp;
    i=N;while (i--)
        tmp[i]=a[i]-b[i];
    return tmp;
}

template <class T,int N,class S>
INLINE FVector2<T,N,S> operator - ( const FVector2<T,N,S>& a) {
    int i;
    FVector2<T,N,S> tmp;
    i=N;while (i--)
        tmp[i]=-a[i];
    return tmp;
}

template <class T,int N,class S>
INLINE FVector2<T,N,S> operator * (const T& a,const FVector2<T,N,S>& b) {
    int i;
    FVector2<T,N,S> tmp;
    i=N;while (i--)
        tmp[i]=a*b[i];
    return tmp;
}

template <class T,int N,class S>
INLINE FVector2<T,N,S> operator * ( const FVector2<T,N,S>& a,const T& b) {
    int i;
    FVector2<T,N,S> tmp;
    i=N;while (i--)
        tmp[i]=a[i]*b;
    return tmp;
}
/* ? voor GNU ok, voor visual niet OK ? */
template <class T,int N,class S>
INLINE FVector2<T,N,S> operator * (S a,const FVector2<T,N,S>& b) {
    int i;
    FVector2<T,N,S> tmp;
    i=N;while (i--)
        tmp[i]=a*b[i];
    return tmp;
}

template <class T,int N,class S>
INLINE FVector2<T,N,S> operator * ( const FVector2<T,N,S>& a,S b) {
    int i;
    FVector2<T,N,S> tmp;
    i=N;while (i--)
        tmp[i]=a[i]*b;
    return tmp;
}




template <class T,int N,class S>
INLINE FVector2<T,N,S> operator / ( const FVector2<T,N,S>& a,const T& b) {
    FVector2<T,N,S> tmp;
    int i;
    i=N;while (i--)
        tmp[i]=a[i]/b;
    return tmp;
}


template <class T,int N,class S>
INLINE double Norm(const FVector2<T,N,S>& a)  {
    double sum;
    int i;
    sum = 0;
    i=N;while (i--) {
        sum+=sqr(Norm(a.vect[i]));
    }
    return sqrt(sum);
}
// returns norm of the vector contained in FVector2

template <class T,int N,class S>
INLINE FVector2<T,N,S> LinComb(const T& alfa,const FVector2<T,N,S>& a,
                            const T& beta,const FVector2<T,N,S>& b ) {
    FVector2<T,N,S> tmp;
    int i;
    i=N;while (i--) LinCombR(alfa,a[i],beta,b[i],tmp[i]);
    return tmp;
}

template <class T,int N,class S>
INLINE void LinCombR(const T& alfa,const FVector2<T,N,S>& a,
                     const T& beta,const FVector2<T,N,S>& b,FVector2<T,N,S>& result ) {
            int i;
            i=N;while (i--) LinCombR(alfa,a[i],beta,b[i],result[i]);
}



template <class T, int N,class S>
INLINE void SetToZero(FVector2<T,N,S>& value) {
    int i;
    i=N;while (i--) SetToZero(value[i]);
}


template <class T,int N,class S>
bool Equal(const FVector2<T,N,S>& a,const FVector2<T,N,S>& b,double eps) {
    int i;
    for (i=0;i<N;i++) {
        if (!Equal(a[i],b[i],eps)) return false;
    }
    return true;
}

template <class T,int N,class S>
bool Equal(const T& a,const FVector2<T,N,S>& b,double eps) {
    int i;
    for (i=0;i<N;i++) {
        if (!Equal(a,b[i],eps)) return false;
    }
    return true;
}

template <class T,int N,class S>
bool Equal(const FVector2<T,N,S>& a,const T& b,double eps) {
    int i;
    for (i=0;i<N;i++) {
        if (!Equal(a[i],b,eps)) return false;
    }
    return true;
}


}

#endif 
