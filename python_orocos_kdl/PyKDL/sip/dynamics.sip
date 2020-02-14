//Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//
//Version: 1.0
//Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//URL: http://www.orocos.org/kdl
//
//This library is free software; you can redistribute it and/or
//modify it under the terms of the GNU Lesser General Public
//License as published by the Free Software Foundation; either
//version 2.1 of the License, or (at your option) any later version.
//
//This library is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//Lesser General Public License for more details.
//
//You should have received a copy of the GNU Lesser General Public
//License along with this library; if not, write to the Free Software
//Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

%Include std_string.sip

class JntSpaceInertiaMatrix {
%TypeHeaderCode
#include <kdl/jntspaceinertiamatrix.hpp>
using namespace KDL;
%End
public:
    JntSpaceInertiaMatrix();
    JntSpaceInertiaMatrix(int size);
    JntSpaceInertiaMatrix(const JntSpaceInertiaMatrix& arg);
    void resize(unsigned int newSize);
    unsigned int rows()const;
    unsigned int columns()const;
    //JntSpaceInertiaMatrix& operator = ( const JntSpaceInertiaMatrix& arg);
    double __getitem__(SIP_PYTUPLE);
%MethodCode
    int i,j;
    PyArg_ParseTuple(a0,"ii",&i,&j);
    if (i < 0 || j < 0 || i > (int)sipCpp->rows() || j >= (int)sipCpp->columns()) {
        PyErr_SetString(PyExc_IndexError, "Inertia index out of range");
        return NULL;
    }
    sipRes=(*sipCpp)(i,j);
%End
    //double operator()(unsigned int i,unsigned int j)const;
    //double& operator()(unsigned int i,unsigned int j);
    //bool operator==(const JntSpaceInertiaMatrix& src1,const JntSpaceInertiaMatrix& src2);
    //bool operator!=(const JntSpaceInertiaMatrix& src1,const JntSpaceInertiaMatrix& src2);

};
void Add(const JntSpaceInertiaMatrix& src1,const JntSpaceInertiaMatrix& src2,JntSpaceInertiaMatrix& dest);
void Subtract(const JntSpaceInertiaMatrix& src1,const JntSpaceInertiaMatrix& src2,JntSpaceInertiaMatrix& dest);
void Multiply(const JntSpaceInertiaMatrix& src,const double& factor,JntSpaceInertiaMatrix& dest);
void Divide(const JntSpaceInertiaMatrix& src,const double& factor,JntSpaceInertiaMatrix& dest);
void Multiply(const JntSpaceInertiaMatrix& src, const JntArray& vec, JntArray& dest);
void SetToZero(JntSpaceInertiaMatrix& matrix);
bool Equal(const JntSpaceInertiaMatrix& src1,const JntSpaceInertiaMatrix& src2,double eps=epsilon);
bool operator==(const JntSpaceInertiaMatrix& src1,const JntSpaceInertiaMatrix& src2);

class ChainDynParam {
    
%TypeHeaderCode
#include <kdl/chaindynparam.hpp>
using namespace KDL;
%End

public:
    ChainDynParam(const Chain& chain, Vector _grav);

    int JntToCoriolis(const JntArray &q, const JntArray &q_dot, JntArray &coriolis);
	int JntToMass(const JntArray &q, JntSpaceInertiaMatrix& H);
	int JntToGravity(const JntArray &q,JntArray &gravity);
};
