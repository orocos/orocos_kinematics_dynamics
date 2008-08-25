// Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

// Version: 1.0
// Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// URL: http://www.orocos.org/kdl

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA


//Based on the svd of the KDL-0.2 library by Erwin Aertbelien
#ifndef SVD_BOOST_HH_HPP
#define SVD_BOOST_HH_HPP


#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <algorithm>

namespace ublas = boost::numeric::ublas;

namespace KDL
{
    inline double PYTHAG(double a,double b) {
        double at,bt,ct;
        at = fabs(a);
        bt = fabs(b);
        if (at > bt ) {
            ct=bt/at;
            return at*sqrt(1.0+ct*ct);
        } else {
            if (bt==0)
                return 0.0;
            else {
                ct=at/bt;
                return bt*sqrt(1.0+ct*ct);
            }
        }
    }


    inline double SIGN(double a,double b) {
        return ((b) >= 0.0 ? fabs(a) : -fabs(a));
    }

    /**
     * svd calculation of boost ublas matrices
     *
     * @param A matrix<double>(mxn)
     * @param U matrix<double>(mxn)
     * @param S vector<double> n
     * @param V matrix<double>(nxn)
     * @param tmp vector<double> n
     * @param maxiter defaults to 150
     *
     * @return -2 if maxiter exceeded, 0 otherwise
     */
    int svd_boost_HH(const ublas::matrix<double>& A,ublas::matrix<double>& U,ublas::vector<double>& S,ublas::matrix<double>& V,ublas::vector<double>& tmp,int maxiter=150);
}
#endif
