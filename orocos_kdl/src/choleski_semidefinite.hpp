/*******************************************************************************
 *                 This file is part of the OROCOS KDL project                 *
 *                         													   *
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

//Based on the cholesky_semidefinite function in matriw_wrapper of Orocos BFL by Tinne De Laet and Klaas Gadeyne
#ifndef KDL_CHOLESKI_SEMIDEFINITE_HPP
#define KDL_CHOLESKI_SEMIDEFINITE_HPP

#include <Eigen/Core>
#include <math.h>

using namespace Eigen;

namespace KDL
{
    /**
     * calculation of the Cholesky decomposition of a matrix
     *
     * @param input matrix<double>(mxm), should be a symmetric, semi-definite matrix
     * @param output matrix<double>(mxm)=L for which LL.transpose()=input
     *
     * @return true if succeeded, false otherwise
     */
bool cholesky_semidefinite(const Eigen::MatrixXd& input, Eigen::MatrixXd& output);
}

#endif
