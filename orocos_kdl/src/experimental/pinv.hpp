/***************************************************************************
                        pinv.h -  description
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


#ifndef PINV_H
#define PINV_H

#include <math.h>
/*
inline void MatrixOutput(std::ostream& os,double* a,int stridea,int rows,int cols) {
	int i,j;
	for (i=0;i<rows;++i) {
		for (j=0;j<cols;++j) {
			os << a[stridea*i+j];
			if (j!=cols-1) os << "\t";
		}
		if (i!=rows-1) os << "\n";
	}
}
*/

/**
 * \brief handles (weighted) pseudo-inverses and related operations.
 */
class PseudoInverse {
	int maxsize;
	double * tmp;
    double* y2;
public:

    /**
     * a reference to the matrix of which you take the pseudo-inverse
     */
    const double* A;

    /**
     * stride A
     */
    int strideA;

    /**
     * weights in x-space
     */
    const double* Lx;

    /**
     * weights in y-space
     */
    const double* Ly;

    /**
     * nr of rows 
     */
    int m;

    /**
     * nr of columns
     */
    int n;

    /**
     * \brief the prepare method() has been called
     */
    bool prepared;
    /**
     * \brief left orthonormal matrix
     * when prepare() is called, U contains the left orthonormal matrix of the
     * singular value decomposition.
     */
	double * U;
    /**
     * \brief the stride for U.
     */
	int strideU;
    /**
     * \brief right orthonormal matrix
     * when prepare is called, V contains the right orthonormal matrix of the
     * singular value decomposition.
     */
	double * V;
    /**
     * \brief the stride for V
     */
	int strideV;
    /**
     * array containing the diagonal elements of \f$ \Sigma \f$
     */
	double * S;
    /**
     * index to determine the sorted singular values :
     *    i = ndx[j],  where j==1 corresponds to the largest, and j==n corresponds to the smallest singular value
     *    and where i corresponds to the index in S.
     */
    int *ndx;

public:
	/**
	 * Allocate temporary space for calculating the pseudo-inverse of a matrix with
	 * maxrows rows or less , and maxcols collumns or less.
	 * maxrows > maxcols, because if nrofrows < nrofcols, 
	 * extra rows have to be added to the matrix.
	 */
	PseudoInverse(int _maxsize);

    /**
     * \brief Smallest eigenvalue larger then eps
     * \param eps : tollerance level, singular values smaller than eps
     *              are considered to be zero.
     * \return the index into S of the smallest eigenvalue larger then eps.
     */
    int smallestSV(double eps);

	/*int pinv(double* A,int strideA,int m,int n,double *Ai,int strideAi,
	        int nrOfIts,double eps);
	**
	 * Weighted PseudoInverse
	 *   - t = A*q
	 *   - The norm of t is given by t'*Wt*t
	 *   - The norm of q is given by q'*Wq*q
	 *   - Wt is POSITIVE SEMI-DEFINITE diagonal matrix
	 *   - Wq is POSITIVE DEFINITE diagonal matrix
	 *   - Lt is a diagonal matrix of size m x m, such that Wt = Lt'*Lt
	 *   - Lq is a diagonal matrix of size n x n, such that Wq = Lq'*Lq
	 *
	 * \todo 
	 *   check Lq for POS DEF. COND
	 *
	void wpinv(
		double* A,int strideA,int m,int n,double *Awi,int strideAwi,
	    double* Lt,double* Lq,int nrOfIts,double eps);
    */
	~PseudoInverse();

    /**
     * \brief prepares for solving Ax=y by calculating the singular value decomposition.
     *
    * - prepare calculations for solving equations A.x = y.
    *   \param [in] A
    *   \param [in] strideA : stride of A, i.e. the amount of elements 
    *                         in the array between each row of A
    *   \param [in] m number of rows of A.
    *   \param [in] n number of columns of A.
    *   \param [in] Ly  vector describing the square root of the diagonal
    *                   weight matrix in y-space, has m elements.
    *   \param [in] Lx  vector describing the square root of the diagonal
    *                   weight matrix in x-space, has n elements.
 
    *   \param [in] nrOfIts  maximal number of iterations while calculating 
    *       the singular value decomposition of A.
    *   \return 0 if successfull.
    *   \warning a REFERENCE to _A,_Lx,_Ly is kept.  So do not change these variables as long as you 
    *            want to perform additional operations.
    */
    int prepare( const double* _A,int _strideA,int _m,int _n,
                                 const double *_Ly,const double* _Lx,
                                 int nrOfIts);


    /**
    * - given : y = A.x
    * - Calculates x = A# y + (I-A# A) xd with A the weighted inverse
    * - A is specified with the prepare() method.
    * - Method : uses x = A# ( y -A.xd) + xd and calculates this via S.V.D.
    * \param [in] y
    * \param [out] x 
    * \param [in] xd
    * \param [in] eps tollerance for determining the nullspace.  This is lowest value a singular value
    *             may have without entering the nullspace.
    * \warning prepare() has to be called first.
    * \warning uses inverse method;
    * \warning changes y2 members;
    */
    void inverseWithNullSpace(
        const double* y,
        double* x,
        const double* xd,
        double eps);
   /**
    *  - solves an equation with the weighted pseudo-inverse
    *  - given :  A.x = y
    *  - Calculates x = A# y  for the prepared matrix and weights.
    * \warning first call prepare()
    * \param [in] y right hand side of the equations
    * \param [out] x
    * \param [in] eps tollerance for determining the nullspace.  This is lowest value a singular value
    *             may have without entering the nullspace.
    * \warning uses the U, V, S members
    * \warning changes the tmp member 
    */
    void inverse(
        const double* y,
        double* x,
        double eps);

   /**
    * function to calculate :
    * \f[
    * \frac{\partial \tilde{\sigma}_r }{\partial x_i} = u^T_r  L_y \frac{\partial A }{\partial x_i} L^{-1}_x  v_r
    * \f] 
    * \param [in] Adot the derivative (towards some variable) of the A matrix
    * \param [in] strideAdot 
    * \param [in] svnr indicates for which singular value the derivative is taken.
    * \warning prepare() should have been called 
    */
    double derivsv(
        const double* Adot, 
        int strideAdot,
        int svnr);

};



#endif

