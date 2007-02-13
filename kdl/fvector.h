/*****************************************************************************
 * \file  
 *      Implements a very simple fixed-size vector type that allocates all its 
 *      memory on the stack.
 * 
 *       
 *  \author 
 *      Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version 
 *      ORO_Geometry V2
 *
 *  \par Note
 *      Optimalisations under VC++ 6 :
 *      one writes normally for (int i=0;i<N;i++) {...}
 *      although for (int i=0;i<N;++i) {} is faster even with optmimalization.
 *  \par History
 *      - $log$
 * 
 *  \par Release
 *      $Id: fvector.h,v 1.1.1.1 2002/08/26 14:14:21 rmoreas Exp $
 *      $Name:  $ 
 ****************************************************************************/

#ifndef FVECTOR_H
#define FVECTOR_H

#include <kdl/utility.h>
#include <math.h>

namespace KDL {

/**
 * FVector is a vectortype with following properties :
 *  - fully inlined code.
 *  - memory is allocated on the stack
 *  - math. operators are defined on the vector
 *  - fixed size N
 *  - element type T
 *  - provides a SetToZero and Equal function
 * \par Class Type
 * Concrete implementation
 *
 */
template <class T,int N>
class FVector 
{
public:
// = Private members
    T vect[N];

// = Constructors
    FVector() {}
    
    FVector(const T arg[]) {
        int count=N;
        while (count--) vect[count] = arg[count];
    }

    FVector(typename TI<T>::Arg arg1) {vect[0]=arg1;}
    
    FVector(typename TI<T>::Arg arg1,typename TI<T>::Arg arg2) {vect[0]=arg1;vect[1]=arg2;}
    
    FVector(typename TI<T>::Arg arg1,typename TI<T>::Arg arg2,typename TI<T>::Arg arg3) {vect[0]=arg1;vect[1]=arg2;vect[2]=arg3;}

    // always provide a copy constructor
FVector(const FVector<T,N>& arg) {
        int count=N;
        while (count--) vect[count] = arg.vect[count];
    }

    static FVector Zero() {
        FVector<T,N> tmp;
        SetToZero(tmp);
        return tmp;
    }
    
    static FVector Identity() {
        FVector<T,N> tmp;
        SetToIdentity(tmp);
        return tmp;
    }

// = Assignment operators
    FVector<T,N>& operator = (const FVector<T,N>& arg) {
        int count;
        count=N;
        while (count--) vect[count] = arg.vect[count];
        return *this;
    }
    
    FVector<T,N>& operator +=(const FVector<T,N>& arg) {    
        int count;
        count=N;
        while (count--) vect[count] += arg.vect[count];
        return *this;
    }
    FVector<T,N>& operator -=(const FVector<T,N>& arg) {
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
    // = Operators between FVector objects  
    friend FVector<T,N> operator + ( const FVector<T,N>& a,const FVector<T,N>& b);
    friend FVector<T,N> operator - ( const FVector<T,N>& a,const FVector<T,N>& b);
    friend FVector<T,N> operator - ( const FVector<T,N>& a);
    friend FVector<T,N> operator * ( const T& a,const FVector<T,N>& b);
    friend FVector<T,N> operator * ( const FVector<T,N>& a,const T& b);
    friend FVector<T,N> operator / ( const FVector<T,N>& a,const T& b);

    // = Functions that operate on FVector
    friend double Norm(const FVector<T,N>& a);
    // returns norm of the vector contained in FVector


    friend FVector<T,N> LinComb(const T& alfa,const FVector<T,N>& a,
        const T& beta,const FVector<T,N>& b );
    
    friend void LinCombR(const T& alfa,const FVector<T,N>& a,
            const T& beta,const FVector<T,N>& b,FVector<T,N>& result );
*/  
};

template <class T,int N>
INLINE FVector<T,N> operator + ( const FVector<T,N>& a,const FVector<T,N>& b) {
    int i;
    FVector<T,N> tmp;
    i=N;while (i--)
        tmp[i]=a[i]+b[i];
    return tmp;
}

template <class T,int N>
INLINE FVector<T,N> operator - ( const FVector<T,N>& a,const FVector<T,N>& b) {
    int i;
    FVector<T,N> tmp;
    i=N;while (i--)
        tmp[i]=a[i]-b[i];
    return tmp;
}

template <class T,int N>
INLINE FVector<T,N> operator - ( const FVector<T,N>& a) {
    int i;
    FVector<T,N> tmp;
    i=N;while (i--)
        tmp[i]=-a[i];
    return tmp;
}

template <class T,int N>
INLINE FVector<T,N> operator * (typename TI<T>::Arg a,const FVector<T,N>& b) {
    int i;
    FVector<T,N> tmp;
    i=N;while (i--)
        tmp[i]=a*b[i];
    return tmp;
}



template <class T,int N>
INLINE FVector<T,N> operator * ( const FVector<T,N>& a,typename TI<T>::Arg b) {
    int i;
    FVector<T,N> tmp;
    i=N;while (i--)
        tmp[i]=a[i]*b;
    return tmp;
}

template <class T,int N>
INLINE FVector<T,N> operator / ( const FVector<T,N>& a,typename TI<T>::Arg b) {
    FVector<T,N> tmp;
    int i;
    i=N;while (i--)
        tmp[i]=a[i]/b;
    return tmp;
}


template <class T,int N>
INLINE double Norm(const FVector<T,N>& a)  {
    double sum;
    int i;
    sum = 0;
    i=N;while (i--) {
        sum+=sqr(Norm(a.vect[i]));
    }
    return sqrt(sum);
}
// returns norm of the vector contained in FVector

template <class T,int N>
INLINE FVector<T,N> LinComb(typename TI<T>::Arg alfa,const FVector<T,N>& a,
                            typename TI<T>::Arg beta,const FVector<T,N>& b ) {
    FVector<T,N> tmp;
    int i;
    i=N;while (i--) LinCombR(alfa,a[i],beta,b[i],tmp[i]);
    return tmp;
}

template <class T,int N>
INLINE void LinCombR(typename TI<T>::Arg alfa,const FVector<T,N>& a,
                     typename TI<T>::Arg beta,const FVector<T,N>& b,FVector<T,N>& result ) {
            int i;
            i=N;while (i--) LinCombR(alfa,a[i],beta,b[i],result[i]);
}



template <class T, int N>
INLINE void SetToZero(FVector<T,N>& value) {
    int i;
    i=N;while (i--) SetToZero(value[i]);
}

template <class T, int N>
INLINE void SetToIdentity(FVector<T,N>& value) {
    int i;
    i=N;while (i--) SetToIdentity(value[i]);
}

template <class T,int N>
bool Equal(const FVector<T,N>& a,const FVector<T,N>& b,double eps) {
    int i;
    for (i=0;i<N;i++) {
        if (!Equal(a[i],b[i],eps)) return false;
    }
    return true;
}


/*
 *
 * To make it faster, some specialisations :
 * 
 * Canceled because VC6++ does not handle the template specialisation of 
 * friend functions very well when combined with STL. It then suddenly does not
 * recognize any more operators for other template classes (Compiler Bug ?)
 * (under GCC no problem).
 * solved, concerns the overloading rules regarding namespaces.
 */
/*
//template <class T>
class FVector<double,2> {
    typedef double T;
    enum {N=2};
public:
    T a1,a2;

    FVector() {}
    FVector(const T& b1,const T& b2):a1(b1),a2(b2) {}

    // always provide a copy constructor
    FVector(const FVector<T,N>& arg):a1(arg.a1),a2(arg.a2) {}


    static FVector Zero() {
        FVector<T,N> tmp;
        SetToZero(tmp);
        return tmp;
    }


    // Assignment operators
    FVector<T,N>& operator = (const FVector<T,N>& arg) {
        a1=arg.a1;
        a2=arg.a2;
        return *this;
    }
    // User must define
    // ---------- LinearSpaceCategory ---------------
    // AbelianGroupCategory 
    FVector<T,N>& operator +=(const FVector<T,N>& arg) {
        a1+=arg.a1;
        a2+=arg.a2;
        return *this;
    }
    
    FVector<T,N>& operator -=(const FVector<T,N>& arg) {
        a1-=arg.a1;
        a2-=arg.a2;
        return *this;
    }
    
    friend FVector<T,N> operator + ( const FVector<T,N>& a,const FVector<T,N>& b) {
        return FVector<T,N>(a.a1+b.a1,a.a2+b.a2);
    }
    friend FVector<T,N> operator - ( const FVector<T,N>& a,const FVector<T,N>& b) {
        return FVector<T,N>(a.a1-b.a1,a.a2-b.a2);
    }
    
    friend FVector<T,N> operator - ( const FVector<T,N>& a) {
        return FVector<T,N>(-a.a1,-a.a2);
    }
    
    // FieldScalarsCategory with T

    friend FVector<T,N> operator * ( const T& a,const FVector<T,N>& b) {
        return FVector<T,N>(a*b.a1,a*b.a2);
    }
    friend FVector<T,N> operator * ( const FVector<T,N>& a,const T& b) {
        return FVector<T,N>(a.a1*b,a.a2*b);
    }
    friend FVector<T,N> operator / ( const FVector<T,N>& a,const T& b) {

        return FVector<T,N>(a.a1/b,a.a2/b);
    }

    friend FVector<T,N> LinComb(const T& alfa,const FVector<T,N>& a,
        const T& beta,const FVector<T,N>& b ) {
            return FVector<T,N>(LinComb(alfa,a.a1,beta,b.a1),
                                LinComb(alfa,a.a2,beta,b.a2) );
    }
    friend void LinCombR(const T& alfa,const FVector<T,N>& a,
        const T& beta,const FVector<T,N>& b,FVector<T,N>& result ) {
            LinCombR(alfa,a.a1,beta,b.a1,result.a1);
            LinCombR(alfa,a.a2,beta,b.a2,result.a2);
    }



    // additional operators for easy use :
    T& operator[] (int i) {
        return i==0?a1:a2;
    }

    const T& operator[] (int i) const {
        return i==0?a1:a2;
    }

    // max. of the abs. value of each el
    double max_abs() {
        return max(fabs(a1),fabs(a2));  
    }
    friend double Norm(const FVector<T,N>& a) {
        return sqrt(a.a1*a.a1+a.a2*a.a2);
    }

};

class FVector<double,3> {
    typedef double T;
    enum {N=3};
public:
    T a1,a2,a3;

    FVector() {}
    FVector(const T& b1,const T& b2,const T& b3):a1(b1),a2(b2),a3(b3) {}

    // always provide a copy constructor
    FVector(const FVector<T,N>& arg):a1(arg.a1),a2(arg.a2),a3(arg.a3) {}


    static FVector Zero() {
        FVector<T,N> tmp;
        SetToZero(tmp);
        return tmp;
    }


    // Assignment operators
    FVector<T,N>& operator = (const FVector<T,N>& arg) {
        a1=arg.a1;
        a2=arg.a2;
        a3=arg.a3;
        return *this;
    }
    // User must define
    // ---------- LinearSpaceCategory ---------------
    // AbelianGroupCategory 
    FVector<T,N>& operator +=(const FVector<T,N>& arg) {
        a1+=arg.a1;
        a2+=arg.a2;
        a3+=arg.a3;
        return *this;
    }
    
    friend FVector<T,N> operator + ( const FVector<T,N>& a,const FVector<T,N>& b) {
        return FVector<T,N>(a.a1+b.a1,a.a2+b.a2,a.a3+b.a3);
    }
    
    FVector<T,N>& operator -=(const FVector<T,N>& arg) {
        a1-=arg.a1;
        a2-=arg.a2;
        a3-=arg.a3;
        return *this;
    }
    
    friend FVector<T,N> operator - ( const FVector<T,N>& a,const FVector<T,N>& b) {
        return FVector<T,N>(a.a1-b.a1,a.a2-b.a2,a.a3-b.a3);
    }
    
    friend FVector<T,N> operator - ( const FVector<T,N>& a) {
        return FVector<T,N>(-a.a1,-a.a2,-a.a3);
    }
    

    // FieldScalarsCategory with T

    friend FVector<T,N> operator * ( const T& a,const FVector<T,N>& b) {
        return FVector<T,N>(a*b.a1,a*b.a2,a*b.a3);
    }
    friend FVector<T,N> operator * ( const FVector<T,N>& a,const T& b) {
        return FVector<T,N>(a.a1*b,a.a2*b,a.a3*b);
    }
    friend FVector<T,N> operator / ( const FVector<T,N>& a,const T& b) {

        return FVector<T,N>(a.a1/b,a.a2/b,a.a3/b);
    }
    friend FVector<T,N> LinComb(const T& alfa,const FVector<T,N>& a,
        const T& beta,const FVector<T,N>& b ) {
            return FVector<T,N>(LinComb(alfa,a.a1,beta,b.a1),
                                LinComb(alfa,a.a2,beta,b.a2),
                                LinComb(alfa,a.a3,beta,b.a3) );
    }
    friend void LinCombR(const T& alfa,const FVector<T,N>& a,
        const T& beta,const FVector<T,N>& b,FVector<T,N>& result ) {
            LinCombR(alfa,a.a1,beta,b.a1,result.a1);
            LinCombR(alfa,a.a2,beta,b.a2,result.a2);
            LinCombR(alfa,a.a3,beta,b.a3,result.a3);
    }


    // additional operators for easy use :
    T& operator[] (int i) {
        return i==0?a1:(i==1?a2:a3);
    }

    const T& operator[] (int i) const {
        return i==0?a1:(i==1?a2:a3);
    }

    // max. of the abs. value of each el
    double max_abs() {
        return max(fabs(a1),max(fabs(a2),fabs(a3)));    
    }
    friend double Norm(const FVector<T,N>& a) {
        return sqrt(a.a1*a.a1+a.a2*a.a2+a.a3*a.a3);
    }

};
*/




}

#endif 
