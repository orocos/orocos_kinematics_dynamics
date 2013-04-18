/*******************************************************************************
 *                 This file is part of the OROCOS KDL project                 *
 *                             												   *
 *                        (C) 2012 Wouter Bancken                              *
 *                        (C) 2011 Dominick Vanthienen                         *
 *                        (C) 2010 Tinne De Laet                               *
 *                        (C) 2002 Klaas Gadeyne                               *
 *                    dominick.vanthienen@mech.kuleuven.be,                    *
 *                       <first.last>@mech.kuleuven.be,                        *
 *                    Department of Mechanical Engineering,                    *
 *                   Katholieke Universiteit Leuven, Belgium.                  *
 *                                                                             *
 *       You may redistribute this software and/or modify it under either the  *
 *       terms of the GNU Lesser General Public License version 2.1 (LGPLv2.1  *
 *       <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>) or (at your *
 *       discretion) of the Modified BSD License:                              *
 *       Redistribution and use in source and binary forms, with or without    *
 *       modification, are permitted provided that the following conditions    *
 *       are met:                                                              *
 *       1. Redistributions of source code must retain the above copyright     *
 *       notice, this list of conditions and the following disclaimer.         *
 *       2. Redistributions in binary form must reproduce the above copyright  *
 *       notice, this list of conditions and the following disclaimer in the   *
 *       documentation and/or other materials provided with the distribution.  *
 *       3. The name of the author may not be used to endorse or promote       *
 *       products derived from this software without specific prior written    *
 *       permission.                                                           *
 *       THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  *
 *       IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED        *
 *       WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    *
 *       ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,*
 *       INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    *
 *       (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS       *
 *       OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) *
 *       HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,   *
 *       STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING *
 *       IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE    *
 *       POSSIBILITY OF SUCH DAMAGE.                                           *
 *                                                                             *
 *******************************************************************************/
#include "cholesky_semidefinite.hpp"

namespace KDL{
int cholesky_semidefinite(const Eigen::MatrixXd& input,Eigen::MatrixXd& output)
{
    // apply cholesky to input, which should be a symmetric, semi-definite matrix
    // put result in output=L with LL.transpose()=input
    // result is lower triangular matrix

	int i,j,r,k,l,m;
	double inputIsDiagonal=true;

    output = input;

   int sz = output.rows();
    // check if input is square
    if(sz!=output.cols())
    {
        output.setZero(sz,output.cols());
        return 161;
    }
    //check if input is a symmetric matrix
    for (l=0; l<sz; l++)
    {
        for (m=0; m<l+1; m++)
        {
            if(output(l,m)!=output(m,l))
            {
                output.setZero(sz,sz);
                return 162;
            }else if(l==m)
            {
            	// check if close to zero => put to zero
            	if (output(l,l)< std::numeric_limits<double>::epsilon() && output(l,l)> -std::numeric_limits<double>::epsilon()){
            	    output(l,l) = 0.0; //set to zero, matrix is semidefinite
            	}else if(output(l,l)<0.0)
            	{
            		output.setZero(sz,sz);
            		return 163;
            	}
            }else
            {
            	if(output(l,m)> std::numeric_limits<double>::epsilon() || output(l,m)< -std::numeric_limits<double>::epsilon())
            	{
            		inputIsDiagonal=false;
            	}
            }
        }
    }

    //the algorithm
    //if output is a diagonal matrix, we can calculate this easily
    if(inputIsDiagonal)
    {
    	for(r=0; r<sz; r++)
    	{
    		output(r,r) = sqrt(output(r,r));
    	}
    }
    else
    {
		//iterate over all rows (r)
		for(r=0; r<sz; r++)
		{
			//iterate over all elements (k) of row r from left till diagonal
			for(k=0; k<r; k++)
			{
				output(r,r) -= output(r,k)*output(r,k);
			}
			output(r,r) = sqrt(output(r,r));
			//make sure this value on the diagonal is >0
			if (output(k,k)< std::numeric_limits<double>::epsilon())
			{
				output.setZero(sz,output.cols());
				return 163;
			}
			//invert diagonal element
			double DiagElmntInv = 1/output(r,r);
			//iterate over the part of the diagonal, lower than the current element
			for(i=r+1;i<sz;i++)
			{
				for(j=0;j<r;j++)
				{
					output(i,r) -= output(i,j)*output(r,j);
				}
				output(i,r) *= DiagElmntInv;
				output(r,i)=output(i,r);
			}
		}

		//delete upper  triangle
		for (i=0; i<sz; i++)
		{
			for (j=i+1; j<sz; j++)
			{
				output(i,j)=0.0;
			}
		}
    }
    return 0;
}//end of function
}//end of namespace KDL
