/*****************************************************************************
 * \file  
 *      Implements I/O operation on FVector<T,N>
 * 
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
 *      $Id: fvector_io.h,v 1.1.1.1 2002/08/26 14:14:21 rmoreas Exp $
 *      $Name:  $ 
 ****************************************************************************/
#ifndef FVECTOR_IO_H
#define FVECTOR_IO_H

#include <kdl/utility_io.h>
#include <kdl/fvector.h>

namespace KDL {

template <class T,int N>
inline std::ostream& operator << (std::ostream& os,const FVector<T,N>& v)
            {
            os << "FVector(";
            for (int i=0;i<N-1;i++) {
                os << v[i] << ", ";
            }
            os << v[N-1] << ")";
            return os;
            }
}
#endif
