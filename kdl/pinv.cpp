/***************************************************************************
                        pinv.cxx -  description
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


#include <math.h>
#include <assert.h>
#include <kdl/pinv.hpp>
#include <iostream>
#include <algorithm>

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
 * - this routine computes its singular value decomposition, a = u*w*v'
 * - the dimensions of a are m*n, m >= n, otherwise fill a up to square with zero rows
 *   in that case take only the mxm part of the v matrix. and the mxm of w
 * - The singular values are not ordered in descending order!!
 *   So, also the columns of U and V are not ordered!!
 * - The algorithm does not calculate a full m xm matrix U! only an mxn one !
 * ARGUMENTS :
 * a,stridea,int m,int n  : description of matrix a[1..m][1..n],
 *				input: matrix a
 *				output: matrix u
 * w                      : w[1..n]
 *				output : singular values (not sorted)
 * v,stridev		  : description of matrix v[1..n][1..n]
 *				output : the matrix v
 * NrIts		  : max nr of iterations
 * vec			  : temporary storage with max dimension of a ( ie m)
 *
 * RETURNS:	0 if no errors occured during computations;
 *		1 if `m' < `n';
 *		2 if maximum number of iterations is exceeded.
 *
 * Based on the book 
 *       NUMERICAL RECIPES IN C: THE ART OF SCIENTIFIC COMPUTING (ISBN 0-521-43108-5)
 *       http://www.library.cornell.edu/nr/bookcpdf.html
 */
int svdcmp(
	double *a,
	int stridea,
	int m,int n,
	double* w,
	double* v,
	int stridev,
	int NrIts,
	double* vec )
{
	double maxarg1,maxarg2;
	int flag,i,its=0,j,jj,k,l=0,nm=0;
	double c,f,h,s,x,y,z;
	double anorm=0.0,g=0.0,scale=0.0;
	
	/* adapt conventions from 0-based to 1-based */
	a = a - stridea - 1;
	w = w - 1;
	v = v - stridev - 1;
	vec = vec - 1;
	/*****/
	if (m<n)  return(1);
	/* Householder reduction to bidiagonal form. */
	for (i=1;i<=n;++i) {
		l=i+1;
		vec[i]=scale*g;
		g=s=scale=0.0;
		if (i<=m) {
			for (k=i;k<=m;++k) scale += fabs(a[k*stridea+i]);
			if (scale) {
				for (k=i;k<=m;++k) {
					a[k*stridea+i] /= scale;
					s += a[k*stridea+i]*a[k*stridea+i];
				}
				f=a[i*stridea+i];
				g = -SIGN(sqrt(s),f);
				h=f*g-s;
				a[i*stridea+i]=f-g;
				if (i != n) {
		  			for (j=l;j<=n;++j) {
		    				for (s=0.0,k=i;k<=m;++k) s += a[k*stridea+i]*a[k*stridea+j];
		    				f=s/h;
		    				for (k=i;k<=m;++k) a[k*stridea+j] += f*a[k*stridea+i];
		  			}
				}
				for (k=i;k<=m;++k) a[k*stridea+i] *= scale;
			}
		}
		w[i]=scale*g;
		g=s=scale=0.0;
		if (i <= m && i != n) {
			for (k=l;k<=n;++k) scale += fabs(a[i*stridea+k]);
			if (scale) {
				for (k=l;k<=n;++k) {
		  			a[i*stridea+k] /= scale;
		  			s += a[i*stridea+k]*a[i*stridea+k];
				}
				f=a[i*stridea+l];
				g = -SIGN(sqrt(s),f);
				h=f*g-s;
				a[i*stridea+l]=f-g;
				for (k=l;k<=n;k++) vec[k]=a[i*stridea+k]/h;
				if (i != m) {
		  			for (j=l;j<=m;++j) {
		    				for (s=0.0,k=l;k<=n;k++) s += a[j*stridea+k]*a[i*stridea+k];
		    				for (k=l;k<=n;k++) a[j*stridea+k] += s*vec[k];
		  			}
				}
				for (k=l;k<=n;++k) a[i*stridea+k] *= scale;
			}
		}
		maxarg1=anorm;
		maxarg2=(fabs(w[i])+fabs(vec[i]));
		anorm = maxarg1 > maxarg2 ?	maxarg1 : maxarg2;		
	}
	/* Accumulation of right-hand transformations. */
	for (i=n;i>=1;--i) {
	if (i<n) {
		if (g) {
			for (j=l;j<=n;++j) v[j*stridev+i]=(a[i*stridea+j]/a[i*stridea+l])/g;
		  	for (j=l;j<=n;++j) {
	  			for (s=0.0,k=l;k<=n;++k) s += a[i*stridea+k]*v[k*stridev+j];
	  			for (k=l;k<=n;++k) v[k*stridev+j] += s*v[k*stridev+i];
			}
		}
		for (j=l;j<=n;++j) v[i*stridev+j]=v[j*stridev+i]=0.0;
	}
	v[i*stridev+i]=1.0;
	g=vec[i];
	l=i;
	}
	/* Accumulation of left-hand transformations. */
	for (i=n;i>=1;--i) {
	l=i+1;
	g=w[i];
	if (i<n) for (j=l;j<=n;++j) a[i*stridea+j]=0.0;
	if (g) {
		g=1.0/g;
		if (i != n) {
			for (j=l;j<=n;++j) {
				for (s=0.0,k=l;k<=m;++k) s += a[k*stridea+i]*a[k*stridea+j];
	  			f=(s/a[i*stridea+i])*g;
	  			for (k=i;k<=m;++k) a[k*stridea+j] += f*a[k*stridea+i];
			}
		}
		for (j=i;j<=m;++j) a[j*stridea+i] *= g;
	} else {
		for (j=i;j<=m;++j) a[j*stridea+i]=0.0;
	}
	++a[i*stridea+i];
	}
	/* Diagonalization of the bidiagonal form. */
	for (k=n;k>=1;--k) { /* Loop over singular values. */
	for (its=1;its<=NrIts;its++) {  /* Loop over allowed iterations. */
		flag=1;
		for (l=k;l>=1;--l) {  /* Test for splitting. */
			nm=l-1;             /* Note that vec[1] is always zero. */
			if ((double)(fabs(vec[l])+anorm) == anorm) {
				flag=0;
	  			break;
			}
		  	if ((double)(fabs(w[nm])+anorm) == anorm) break;
		}
		if (flag) {
			c=0.0;           /* Cancellation of vec[l], if l>1: */
			s=1.0;
			for (i=l;i<=k;++i) {
	  			f=s*vec[i];
	  			vec[i]=c*vec[i];
	  			if ((double)(fabs(f)+anorm) == anorm) break;
	  			g=w[i];
	  			w[i]=h=PYTHAG(f,g);
	  			h=1.0/h;
	  			c=g*h;
	  			s=(-f*h);
	  			for (j=1;j<=m;++j) {
	    				y=a[j*stridea+nm];
	    				z=a[j*stridea+i];
						a[j*stridea+nm]=y*c+z*s;
	    				a[j*stridea+i]=z*c-y*s;
	  			}
			}
		}
		z=w[k];
		if (l == k) {       /* Convergence. */
			if (z <= 0.0) {   /* Singular value is made nonnegative. */
				w[k] = -z;
	  			for (j=1;j<=n;++j) v[j*stridev+k]=(-v[j*stridev+k]);
			}
			break;
		}
		x=w[l];            /* Shift from bottom 2-by-2 minor: */
		nm=k-1;
		y=w[nm];
		g=vec[nm];
		h=vec[k];
		f=((y-z)*(y+z)+(g-h)*(g+h))/(2.0*h*y);
		g=PYTHAG(f,1.0);
		f=((x-z)*(x+z)+h*((y/(f+SIGN(g,f)))-h))/x;
		/* Next QR transformation: */
		c=s=1.0;
		for (j=l;j<=nm;++j) {
			i=j+1;
			g=vec[i];
			y=w[i];
			h=s*g;
			g=c*g;
			z=PYTHAG(f,h);
			vec[j]=z;
			c=f/z;
			s=h/z;
		  	f=x*c+g*s;
		  	g=g*c-x*s;
		  	h=y*s;
		  	y=y*c;
		  	for (jj=1;jj<=n;++jj) {
				x=v[jj*stridev+j];
				z=v[jj*stridev+i];
				v[jj*stridev+j]=x*c+z*s;
				v[jj*stridev+i]=z*c-x*s;
		 	}
		  	z=PYTHAG(f,h);
		  	w[j]=z;
		  	if (z) {
				z=1.0/z;
				c=f*z;
				s=h*z;
			}
		  	f=(c*g)+(s*y);
		  	x=(c*y)-(s*g);
		  	for (jj=1;jj<=m;++jj) {
				y=a[jj*stridea+j];
			 	z=a[jj*stridea+i];
			 	a[jj*stridea+j]=y*c+z*s;
			 	a[jj*stridea+i]=z*c-y*s;
		  	}
		}
		vec[l]=0.0;
		vec[k]=f;
		w[k]=x;
	}
	}
	if (its == NrIts) 
	return (2);
	else 
	return (0);
}














PseudoInverse::PseudoInverse(int _maxsize):
	maxsize(_maxsize)
{
    tmp = new double[maxsize];
    y2 = new double[maxsize];
	S   = new double[maxsize];
	V   = new double[maxsize*maxsize];
	U   = new double[maxsize*maxsize];
    ndx = new int[maxsize];
	strideV = maxsize;
	strideU = maxsize;
    prepared = false;
}

PseudoInverse::~PseudoInverse() {
    delete[] ndx;
	delete[] U;
	delete[] V;
	delete[] S;
    delete[] y2;
	delete[] tmp;
}

void PseudoInverse::inverse(
    const double* y,
    double* x,
    double eps) 
{
    assert( prepared );
   
    int i,j; 
    double sum;

	// tmp = (Si*U'*Ly*y), 
    for (i=0;i<n;++i) {
        sum = 0.0;
        for (j=0;j<m;++j) {
            sum+= U[strideU*j+i]*Ly[j]*y[j];
        }
        tmp[i] = sum*(fabs(S[i])<eps?0.0:1.0/S[i]);        
    }
    // x = Lx^-1*V*tmp + x
    for (i=0;i<n;++i) {
        sum = 0.0;
        for (j=0;j<n;++j) {
            sum+=V[strideV*i+j]*tmp[j];
        }
        x[i]=sum/Lx[i];
    }
}


void PseudoInverse::inverseWithNullSpace(
    const double* y,
    double* x,
    const double* xd,
    double eps) 
{
    // uses y2 with size m
	int i,j;
   	double sum;
    assert( prepared );
	assert( (0 <=m)&&(m < maxsize));
	assert( (0 <=n)&&(n < maxsize));

    // y2=y-A*xd;
    for (i=0;i<m;++i) {
        sum = 0.0;
        for (j=0;j<n;++j) {
            sum+= A[i*strideA+j]*xd[j];
        }
        y2[i] = y[i]-sum;
    }
    inverse(y2,x,eps);

    // x = x + xd
    for (i=0;i<n;++i) {
        x[i]+= xd[i];
    }
}


class SVD_Ordering {
        const double* S;
    public:
        SVD_Ordering(const double *_S):S(_S) {}
        bool operator()(int i,int j) {
            return S[i]>S[j];
        }
};

/**
 * - prepare calculations for solving equations A.x = y.
 *   \param [in] A
 *   \param [in] strideA : stride of A, i.e. the amount of elements 
 *                         in the array between each row of A
 *   \param [in] m number of rows of A.
 *   \param [in] n number of columns of A.
 *   \param [in] Lx  vector describing the square root of the diagonal
 *                   weight matrix in x-space, has n elements.
 *   \param [in] Ly  vector describing the square root of the diagonal
 *                   weight matrix in y-space, has m elements.
 *   \return 0 if successfull.
 *   \warning changes the U, V, S, tmp members
 */
int PseudoInverse::prepare(
    const double* _A,int _strideA,int _m,int _n,
    const double *_Ly,const double* _Lx,
    int nrOfIts) {
    // uses tmp with size m for svdcmp
    // uses tmp with size n for matrix*vector multiplication
	int i,j;
	int result;
    m=_m;
    n=_n;
    A=_A;
    strideA=_strideA;
    Lx=_Lx;
    Ly=_Ly;
	assert( (0 <=m)&&(m < maxsize));
	assert( (0 <=n)&&(n < maxsize));

	// copy A into U and if necessary, (m<n) fill with zeros    
    // Dim U =  max(m,n) x n
    // scale with the weight matrices 
    // U = Ly*A*lx^-1
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) {
			U[strideU*i+j] = Ly[i]*A[strideA*i+j]/Lx[j];
		}
	}
	for (i=m;i<n;i++) {
		for (j=0;j<n;j++) {
			U[strideU*i+j] = 0.0;
		}
	}
    int m2 = m < n ? n: m;
	result = svdcmp(U,strideU,m2,n,S,V,strideV,nrOfIts,tmp);
    prepared = (result==0);
    // PERFORM SORTING OF THE SVD TO OBTAIN AN INDEX :
    for (j=0;j<n;j++) ndx[j]=j;
    SVD_Ordering order(S);
    std::sort(ndx,ndx+n,order); 
	return result;
}


int PseudoInverse::smallestSV(double eps) {
    assert(prepared);
    for (int i=n-1;i>=0;i--) {
        if (S[ndx[i]] >= eps) {
            return ndx[i];
        }
    }
	return 0;
}
double PseudoInverse::derivsv(
        const double* Adot, 
        int strideAdot,
        int svnr)
{
   assert(prepared);
   int i,j;
   double sum;
   sum = 0.0;
   for (i=0;i<m;++i) {
       for (j=0;j<n;++j) {
            // sum += U[i,r]*Ly[i]*Adot[i,j]/Lx[j]*V[j,r]
            sum += U[strideU*i+svnr]*Ly[i]*Adot[strideAdot*i+j]/Lx[j]*V[strideV*j+svnr];
       }
   }
   return sum;
}



