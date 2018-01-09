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


class Vector{

%TypeHeaderCode
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <sstream>
using namespace KDL;
%End

public:
    Vector();
    Vector(double x, double y, double z);
    Vector(const Vector& arg);

    void x(double);
    void y(double);
    void z(double);

    double x() const;
    double y() const;
    double z() const;

    double __getitem__ (int index) const;
%MethodCode
    if (a0 < 0 || a0 > 2) {
	    PyErr_SetString(PyExc_IndexError, "Vector index out of range");
	    return 0;
    }
    sipRes=(*sipCpp)(a0);
%End

    void __setitem__(int index, double value);
%MethodCode
    if (a0 < 0 || a0 > 2) {
        PyErr_SetString(PyExc_IndexError, "Vector index out of range");
        return 0;
    }
    (*sipCpp)(a0)=a1;
%End

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    void ReverseSign();

    Vector& operator-=(const Vector& arg);
    Vector& operator +=(const Vector& arg);

    static Vector Zero()/Factory/;

    double Norm();
    double Normalize(double eps=epsilon);

%PickleCode
    sipRes = Py_BuildValue("ddd", sipCpp->x(), sipCpp->y(), sipCpp->z());
%End
};

void SetToZero(Vector& v);
Vector operator-(const Vector& arg)/Factory/;
Vector operator*(const Vector& lhs,double rhs)/Factory/;
Vector operator*(double lhs,const Vector& rhs)/Factory/;
Vector operator/(const Vector& lhs,double rhs)/Factory/;
Vector operator+(const Vector& lhs,const Vector& rhs)/Factory/;
Vector operator-(const Vector& lhs,const Vector& rhs)/Factory/;
Vector operator*(const Vector& lhs,const Vector& rhs)/Factory/;
double dot(const Vector& lhs,const Vector& rhs);
bool operator==(const Vector& a,const Vector& b);
bool operator!=(const Vector& a,const Vector& b);
bool Equal(const Vector& a,const Vector& b,double eps=epsilon);

class Rotation{

%TypeHeaderCode
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <sstream>
using namespace KDL;
%End

public:
    Rotation();
    Rotation(double Xx,double Yx,double Zx,
             double Xy,double Yy,double Zy,
             double Xz,double Yz,double Zz);
    Rotation(const Vector& x,const Vector& y,const Vector& z);
    
    double __getitem__(SIP_PYTUPLE) const;
%MethodCode
    int i,j;
    PyArg_ParseTuple(a0, "ii", &i, &j);
    if (i < 0 || j < 0 || i > 2 || j > 2) {
        PyErr_SetString(PyExc_IndexError, "Rotation index out of range");
        return 0;
    }
    sipRes=((const Rotation)(*sipCpp))(i,j);
%End

    void __setitem__(SIP_PYTUPLE,double value);
%MethodCode
    int i,j;
    PyArg_ParseTuple(a0,"ii",&i,&j);
    if (i < 0 || j < 0 || i > 2 || j > 2) {
        PyErr_SetString(PyExc_IndexError, "Rotation index out of range");
        return 0;
    }
    (*sipCpp)(i,j)=a1;
%End

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End
    
    void SetInverse();
    Rotation Inverse() const /Factory/;
    Vector Inverse(const Vector& v) const /Factory/;
    Wrench Inverse(const Wrench& w) const /Factory/;
    Twist Inverse(const Twist& t) const /Factory/;
    
    static Rotation Identity()/Factory/;
    static Rotation RotX(double angle)/Factory/;
    static Rotation RotY(double angle)/Factory/;
    static Rotation RotZ(double angle)/Factory/;
    static Rotation Rot(const Vector& vec,double angle)/Factory/;
    static Rotation Rot2(const Vector& vec,double angle)/Factory/;
    static Rotation EulerZYZ(double Alfa,double Beta,double Gamma)/Factory/;
    static Rotation RPY(double roll,double pitch,double yaw)/Factory/;
    static Rotation EulerZYX(double Alfa,double Beta,double Gamma)/Factory/;
    static Rotation Quaternion(double x, double y, double z, double w)/Factory/;
    

    void DoRotX(double angle);
    void DoRotY(double angle);
    void DoRotZ(double angle);
    
    Vector GetRot() const /Factory/;
    double GetRotAngle(Vector& axis /Out/,double eps=epsilon) const;
    void GetEulerZYZ(double& alfa /Out/,double& beta /Out/,double& gamma /Out/) const;
    void GetRPY(double& roll /Out/,double& pitch /Out/,double& yaw /Out/) const;
    void GetEulerZYX(double& Alfa /Out/,double& Beta /Out/,double& Gamma /Out/) const;
    void GetQuaternion(double& x /Out/,double& y /Out/,double& z /Out/, double& w) const;

    
    Vector operator*(const Vector& v) const /Numeric,Factory/;
    Twist operator*(const Twist& arg) const /Numeric,Factory/;
    Wrench operator*(const Wrench& arg) const /Numeric,Factory/;
    
    Vector UnitX() const /Factory/;
    Vector UnitY() const /Factory/;
    Vector UnitZ() const /Factory/;

    void UnitX(const Vector& X);
    void UnitY(const Vector& X);
    void UnitZ(const Vector& X);

%PickleCode
    sipRes = Py_BuildValue("ddddddddd", (*sipCpp)(0,0), (*sipCpp)(0,1), (*sipCpp)(0,2),
                                        (*sipCpp)(1,0), (*sipCpp)(1,1), (*sipCpp)(1,2),
                                        (*sipCpp)(2,0), (*sipCpp)(2,1), (*sipCpp)(2,2));
%End
};
bool Equal(const Rotation& a,const Rotation& b,double eps=epsilon);
bool operator==(const Rotation& a,const Rotation& b);
bool operator!=(const Rotation& a,const Rotation& b);
Rotation operator *(const Rotation& lhs,const Rotation& rhs)/Factory/;

class Frame{

%TypeHeaderCode
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <sstream>
using namespace KDL;
%End

public:
    Frame(const Rotation& R,const Vector& V);
    Frame(const Vector& V);
    Frame(const Rotation& R);
    Frame();
    
    Vector p;
    Rotation M;
    
    double __getitem__ (SIP_PYTUPLE) const;
%MethodCode
    int i,j;
    PyArg_ParseTuple(a0,"ii",&i,&j);
    if (i < 0 || j < 0 || i > 2 || j > 3) {
        PyErr_SetString(PyExc_IndexError, "Frame index out of range");
        return 0;
    }
    sipRes=(*sipCpp)(i,j);
%End

    void __setitem__(SIP_PYTUPLE,double value);
%MethodCode
    int i,j;
    PyArg_ParseTuple(a0,"ii",&i,&j);
    if (i < 0 || j < 0 || i > 2 || j > 3) {
        PyErr_SetString(PyExc_IndexError, "Frame index out of range");
        return 0;
    }
    if(j==3)
        (*sipCpp).p(i)=a1;
    else
        (*sipCpp).M(i,j)=a1;
%End

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    Frame DH_Craig1989(double a,double alpha,double d,double theta);
    Frame DH(double a,double alpha,double d,double theta);
    Frame Inverse()/Factory/;
    Vector Inverse(const Vector& arg) const /Factory/;
    Wrench Inverse(const Wrench& arg) const /Factory/;
    Twist Inverse(const Twist& arg) const /Factory/;

    Vector operator*(const Vector& arg) const /Numeric,Factory/;
    Wrench operator * (const Wrench& arg) const /Numeric,Factory/;
    Twist operator * (const Twist& arg) const /Numeric,Factory/;
    
    static Frame Identity() /Factory/;
    
    void Integrate(const Twist& t_this,double frequency);

%PickleCode
    const sipTypeDef *vector_type = sipFindType("Vector");
    const sipTypeDef *rotation_type = sipFindType("Rotation");
    sipRes = Py_BuildValue("OO", sipConvertFromType(&(sipCpp->M), rotation_type, Py_None),
                                 sipConvertFromType(&(sipCpp->p), vector_type, Py_None));
%End
};
Frame operator *(const Frame& lhs,const Frame& rhs)/Factory/;

bool Equal(const Frame& a,const Frame& b,double eps=epsilon);
bool operator==(const Frame& a,const Frame& b);
bool operator!=(const Frame& a,const Frame& b);

class Twist 
{

%TypeHeaderCode
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <sstream>
using namespace KDL;
%End
public:
    Vector vel;
    Vector rot;
    
    Twist();
    Twist(const Vector& _vel,const Vector& _rot);
    
    Twist& operator-=(const Twist& arg);
    Twist& operator+=(const Twist& arg);

    double __getitem__ (int i) const;
%MethodCode
    if (a0 < 0 || a0 > 5) {
        PyErr_SetString(PyExc_IndexError, "Twist index out of range");
        return 0;
    }
    sipRes=(*sipCpp)(a0);
%End

    void __setitem__(int i, double value);
%MethodCode
    if (a0 < 0 || a0 > 5) {
        PyErr_SetString(PyExc_IndexError, "Twist index out of range");
        return 0;
    }
    (*sipCpp)(a0)=a1;
%End

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    static Twist Zero() /Factory/;
    void ReverseSign();
    
    Twist RefPoint(const Vector& v_base_AB) const /Factory/;
    
%PickleCode
    const sipTypeDef *vector_type = sipFindType("Vector");
    sipRes = Py_BuildValue("OO", sipConvertFromType(&(sipCpp->vel), vector_type, Py_None),
                                 sipConvertFromType(&(sipCpp->rot), vector_type, Py_None));
%End
};

Twist operator*(const Twist& lhs,double rhs)/Factory/;
Twist operator*(double lhs,const Twist& rhs)/Factory/;
Twist operator/(const Twist& lhs,double rhs)/Factory/;
Twist operator+(const Twist& lhs,const Twist& rhs)/Factory/;
Twist operator-(const Twist& lhs,const Twist& rhs)/Factory/;
Twist operator-(const Twist& arg)/Factory/;
double dot(const Twist& lhs,const Wrench& rhs);
double dot(const Wrench& rhs,const Twist& lhs);
void SetToZero(Twist& v);

bool Equal(const Twist& a,const Twist& b,double eps=epsilon);
bool operator==(const Twist& a,const Twist& b);
bool operator!=(const Twist& a,const Twist& b);

class Wrench
{
    
%TypeHeaderCode
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <sstream>
using namespace KDL;
%End

public:
    Vector force;
    Vector torque;
    
    Wrench();
    Wrench(const Vector& force,const Vector& torque);
    
    Wrench& operator-=(const Wrench& arg);
    Wrench& operator+=(const Wrench& arg);


    double __getitem__ (int i) const;
%MethodCode
    if (a0 < 0 || a0 > 5) {
        PyErr_SetString(PyExc_IndexError, "Twist index out of range");
        return 0;
    }
    sipRes=(*sipCpp)(a0);
%End

    void __setitem__(int i, double value);
%MethodCode
    if (a0 < 0 || a0 > 5) {
        PyErr_SetString(PyExc_IndexError, "Twist index out of range");
        return 0;
    }
    (*sipCpp)(a0)=a1;
%End

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    static Wrench Zero() /Factory/;
    void ReverseSign();
    Wrench RefPoint(const Vector& v_base_AB) const /Factory/;

%PickleCode
    const sipTypeDef *vector_type = sipFindType("Vector");
    sipRes = Py_BuildValue("OO", sipConvertFromType(&(sipCpp->force), vector_type, Py_None),
                                 sipConvertFromType(&(sipCpp->torque), vector_type, Py_None));
%End
};

Wrench operator*(const Wrench& lhs,double rhs) /Factory/;
Wrench operator*(double lhs,const Wrench& rhs) /Factory/;
Wrench operator/(const Wrench& lhs,double rhs) /Factory/;
Wrench operator+(const Wrench& lhs,const Wrench& rhs) /Factory/;
Wrench operator-(const Wrench& lhs,const Wrench& rhs) /Factory/;
Wrench operator-(const Wrench& arg) /Factory/;
void SetToZero(Wrench& v);
bool Equal(const Wrench& a,const Wrench& b,double eps=epsilon);
bool operator==(const Wrench& a,const Wrench& b);
bool operator!=(const Wrench& a,const Wrench& b);

Vector diff(const Vector& a,const Vector& b,double dt=1)/Factory/;
Vector diff(const Rotation& R_a_b1,const Rotation& R_a_b2,double dt=1)/Factory/;
Twist diff(const Frame& F_a_b1,const Frame& F_a_b2,double dt=1)/Factory/;
Twist diff(const Twist& a,const Twist& b,double dt=1)/Factory/;
Wrench diff(const Wrench& W_a_p1,const Wrench& W_a_p2,double dt=1)/Factory/;
Vector addDelta(const Vector& a,const Vector&da,double dt=1)/Factory/;
Rotation addDelta(const Rotation& a,const Vector&da,double dt=1)/Factory/;
Frame addDelta(const Frame& a,const Twist& da,double dt=1)/Factory/;
Twist addDelta(const Twist& a,const Twist&da,double dt=1)/Factory/;
Wrench addDelta(const Wrench& a,const Wrench&da,double dt=1)/Factory/;

