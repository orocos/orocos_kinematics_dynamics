//Copyright  (C)  2020  Ruben Smits <ruben dot smits at intermodalics dot eu>
//
//Version: 1.0
//Author: Ruben Smits <ruben dot smits at intermodalics dot eu>
//Maintainer: Ruben Smits <ruben dot smits at intermodalics dot eu>
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


class doubleVel
{

%TypeHeaderCode
#include <kdl/framevel.hpp>
#include <kdl/framevel_io.hpp>
using namespace KDL;
%End
public:
    doubleVel();
    doubleVel(const double c);
    doubleVel(const double tn, const double afg);
    doubleVel(const doubleVel& r);
    double t;
    double grad;
    double value();
    double deriv();

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    SIP_PYOBJECT __copy__() const;
%MethodCode
    sipRes = sipConvertFromNewType(new doubleVel(*sipCpp), sipFindType("doubleVel"), NULL);
%End

    SIP_PYOBJECT __deepcopy__(SIP_PYOBJECT) const;
%MethodCode
    sipRes = sipConvertFromNewType(new doubleVel(*sipCpp), sipFindType("doubleVel"), NULL);
%End
};

doubleVel operator - (const doubleVel& r);

doubleVel diff(const doubleVel& a,const doubleVel& b,double dt=1.0);
doubleVel addDelta(const doubleVel& a,const doubleVel&da,double dt=1.0);

bool Equal(const doubleVel& r1,const doubleVel& r2,double eps=epsilon);

bool operator==(const doubleVel& r1,const doubleVel& r2);
bool operator!=(const doubleVel& r1,const doubleVel& r2);


class VectorVel
{
%TypeHeaderCode
#include <kdl/framevel.hpp>
#include <kdl/framevel_io.hpp>
using namespace KDL;
%End
public:
    Vector p;
    Vector v;

    VectorVel();
    VectorVel(const Vector& _p,const Vector& _v);
    VectorVel(const Vector& _p);
    Vector value() const;
    Vector deriv() const;

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    SIP_PYOBJECT __copy__() const;
%MethodCode
    sipRes = sipConvertFromNewType(new VectorVel(*sipCpp), sipFindType("VectorVel"), NULL);
%End

    SIP_PYOBJECT __deepcopy__(SIP_PYOBJECT) const;
%MethodCode
    sipRes = sipConvertFromNewType(new VectorVel(*sipCpp), sipFindType("VectorVel"), NULL);
%End

    VectorVel& operator += (const VectorVel& arg);
    VectorVel& operator -= (const VectorVel& arg);
    static VectorVel Zero();
    void ReverseSign();
    doubleVel Norm(double eps=epsilon) const;

%PickleCode
    const sipTypeDef *vector_type = sipFindType("Vector");
    sipRes = Py_BuildValue("OO", sipConvertFromType(&(sipCpp->p), vector_type, Py_None),
                                 sipConvertFromType(&(sipCpp->v), vector_type, Py_None));
%End
};

VectorVel operator + (const VectorVel& r1,const VectorVel& r2);
VectorVel operator - (const VectorVel& r1,const VectorVel& r2);
VectorVel operator + (const Vector& r1,const VectorVel& r2);
VectorVel operator - (const Vector& r1,const VectorVel& r2);
VectorVel operator + (const VectorVel& r1,const Vector& r2);
VectorVel operator - (const VectorVel& r1,const Vector& r2);

VectorVel operator * (const VectorVel& r1,const VectorVel& r2);
VectorVel operator * (const VectorVel& r1,const Vector& r2);
VectorVel operator * (const Vector& r1,const VectorVel& r2);
VectorVel operator * (const VectorVel& r1,double r2);
VectorVel operator * (double r1,const VectorVel& r2);
VectorVel operator * (const doubleVel& r1,const VectorVel& r2);
VectorVel operator * (const VectorVel& r2,const doubleVel& r1);
VectorVel operator * (const Rotation& R,const VectorVel& x);

VectorVel operator / (const VectorVel& r1,double r2);
VectorVel operator / (const VectorVel& r2,const doubleVel& r1);
void SetToZero(VectorVel& v);
bool Equal(const VectorVel& r1,const VectorVel& r2,double eps=epsilon);
bool Equal(const Vector& r1,const VectorVel& r2,double eps=epsilon);
bool Equal(const VectorVel& r1,const Vector& r2,double eps=epsilon);

bool operator==(const VectorVel& r1,const VectorVel& r2);
bool operator!=(const VectorVel& r1,const VectorVel& r2);
bool operator==(const Vector& r1,const VectorVel& r2);
bool operator!=(const Vector& r1,const VectorVel& r2);
bool operator==(const VectorVel& r1,const Vector& r2);
bool operator!=(const VectorVel& r1,const Vector& r2);

VectorVel operator - (const VectorVel& r);
doubleVel dot(const VectorVel& lhs,const VectorVel& rhs);
doubleVel dot(const VectorVel& lhs,const Vector& rhs);
doubleVel dot(const Vector& lhs,const VectorVel& rhs);


class RotationVel
{
%TypeHeaderCode
#include <kdl/framevel.hpp>
#include <kdl/framevel_io.hpp>
using namespace KDL;
%End

public:
    Rotation R;
    Vector   w;
    RotationVel();
    RotationVel(const Rotation& _R);
    RotationVel(const Rotation& _R,const Vector& _w);

    Rotation value() const;
    Vector   deriv() const;

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    SIP_PYOBJECT __copy__() const;
%MethodCode
    sipRes = sipConvertFromNewType(new RotationVel(*sipCpp), sipFindType("RotationVel"), NULL);
%End

    SIP_PYOBJECT __deepcopy__(SIP_PYOBJECT) const;
%MethodCode
    sipRes = sipConvertFromNewType(new RotationVel(*sipCpp), sipFindType("RotationVel"), NULL);
%End

    VectorVel UnitX() const;
    VectorVel UnitY() const;
    VectorVel UnitZ() const;
    static RotationVel Identity();
    RotationVel Inverse() const;
    VectorVel Inverse(const VectorVel& arg) const;
    VectorVel Inverse(const Vector& arg) const;
    VectorVel operator*(const VectorVel& arg) const;
    VectorVel operator*(const Vector& arg) const;
    void DoRotX(const doubleVel& angle);
    void DoRotY(const doubleVel& angle);
    void DoRotZ(const doubleVel& angle);
    static RotationVel RotX(const doubleVel& angle);
    static RotationVel RotY(const doubleVel& angle);
    static RotationVel RotZ(const doubleVel& angle);
    static RotationVel Rot(const Vector& rotvec,const doubleVel& angle);
    static RotationVel Rot2(const Vector& rotvec,const doubleVel& angle);

    TwistVel Inverse(const TwistVel& arg) const;
    TwistVel Inverse(const Twist& arg) const;
    TwistVel operator * (const TwistVel& arg) const;
    TwistVel operator * (const Twist& arg) const;

%PickleCode
    const sipTypeDef *vector_type = sipFindType("Vector");
    const sipTypeDef *rotation_type = sipFindType("Rotation");
    sipRes = Py_BuildValue("OO", sipConvertFromType(&(sipCpp->R), rotation_type, Py_None),
                                 sipConvertFromType(&(sipCpp->w), vector_type, Py_None));
%End
};
RotationVel operator* (const RotationVel& r1,const RotationVel& r2);
RotationVel operator* (const Rotation& r1,const RotationVel& r2);
RotationVel operator* (const RotationVel& r1,const Rotation& r2);
bool Equal(const RotationVel& r1,const RotationVel& r2,double eps=epsilon);
bool Equal(const Rotation& r1,const RotationVel& r2,double eps=epsilon);
bool Equal(const RotationVel& r1,const Rotation& r2,double eps=epsilon);

bool operator==(const RotationVel& r1,const RotationVel& r2);
bool operator!=(const RotationVel& r1,const RotationVel& r2);
bool operator==(const Rotation& r1,const RotationVel& r2);
bool operator!=(const Rotation& r1,const RotationVel& r2);
bool operator==(const RotationVel& r1,const Rotation& r2);
bool operator!=(const RotationVel& r1,const Rotation& r2);


class FrameVel
{

%TypeHeaderCode
#include <kdl/framevel.hpp>
#include <kdl/framevel_io.hpp>
using namespace KDL;
%End

public:
    RotationVel M;
    VectorVel   p;

    FrameVel();
    FrameVel(const Frame& _T);
    FrameVel(const Frame& _T,const Twist& _t);
    FrameVel(const RotationVel& _M,const VectorVel& _p);

    Frame value() const;
    Twist deriv() const;

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    SIP_PYOBJECT __copy__() const;
%MethodCode
    sipRes = sipConvertFromNewType(new FrameVel(*sipCpp), sipFindType("FrameVel"), NULL);
%End

    SIP_PYOBJECT __deepcopy__(SIP_PYOBJECT) const;
%MethodCode
    sipRes = sipConvertFromNewType(new FrameVel(*sipCpp), sipFindType("FrameVel"), NULL);
%End

    static FrameVel Identity();
    FrameVel Inverse() const;
    VectorVel Inverse(const VectorVel& arg) const;
    VectorVel operator*(const VectorVel& arg) const;
    VectorVel operator*(const Vector& arg) const;
    VectorVel Inverse(const Vector& arg) const;
    Frame GetFrame() const;
    Twist GetTwist() const;

    TwistVel  Inverse(const TwistVel& arg) const;
    TwistVel  Inverse(const Twist& arg) const;
    TwistVel operator * (const TwistVel& arg) const;
    TwistVel operator * (const Twist& arg) const;

%PickleCode
    const sipTypeDef *vectorvel_type = sipFindType("VectorVel");
    const sipTypeDef *rotationvel_type = sipFindType("RotationVel");
    sipRes = Py_BuildValue("OO", sipConvertFromType(&(sipCpp->M), rotationvel_type, Py_None),
                                 sipConvertFromType(&(sipCpp->p), vectorvel_type, Py_None));
%End
};
FrameVel operator * (const FrameVel& f1,const FrameVel& f2);
FrameVel operator * (const Frame& f1,const FrameVel& f2);
FrameVel operator * (const FrameVel& f1,const Frame& f2);
bool Equal(const FrameVel& r1,const FrameVel& r2,double eps=epsilon);
bool Equal(const Frame& r1,const FrameVel& r2,double eps=epsilon);
bool Equal(const FrameVel& r1,const Frame& r2,double eps=epsilon);

bool operator==(const FrameVel& r1,const FrameVel& r2);
bool operator!=(const FrameVel& r1,const FrameVel& r2);
bool operator==(const Frame& r1,const FrameVel& r2);
bool operator!=(const Frame& r1,const FrameVel& r2);
bool operator==(const FrameVel& r1,const Frame& r2);
bool operator!=(const FrameVel& r1,const Frame& r2);


class TwistVel
{
%TypeHeaderCode
#include <kdl/framevel.hpp>
#include <kdl/framevel_io.hpp>
using namespace KDL;
%End

public:
    VectorVel vel;
    VectorVel rot;

    TwistVel();
    TwistVel(const VectorVel& _vel,const VectorVel& _rot);
    TwistVel(const Twist& p,const Twist& v);
    TwistVel(const Twist& p);

    Twist value() const;
    Twist deriv() const;

    const std::string* __repr__() const;
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=&s;
%End

    SIP_PYOBJECT __copy__() const;
%MethodCode
    sipRes = sipConvertFromNewType(new TwistVel(*sipCpp), sipFindType("TwistVel"), NULL);
%End

    SIP_PYOBJECT __deepcopy__(SIP_PYOBJECT) const;
%MethodCode
    sipRes = sipConvertFromNewType(new TwistVel(*sipCpp), sipFindType("TwistVel"), NULL);
%End

    TwistVel& operator-=(const TwistVel& arg);
    TwistVel& operator+=(const TwistVel& arg);

    static TwistVel Zero();

    void ReverseSign();

    TwistVel RefPoint(const VectorVel& v_base_AB);
    Twist GetTwist() const;
    Twist GetTwistDot() const;
%PickleCode
    const sipTypeDef *vectorvel_type = sipFindType("VectorVel");
    sipRes = Py_BuildValue("OO", sipConvertFromType(&(sipCpp->vel), vectorvel_type, Py_None),
                                 sipConvertFromType(&(sipCpp->rot), vectorvel_type, Py_None));
%End
};
TwistVel operator*(const TwistVel& lhs,double rhs);
TwistVel operator*(double lhs,const TwistVel& rhs);
TwistVel operator/(const TwistVel& lhs,double rhs);

TwistVel operator*(const TwistVel& lhs,const doubleVel& rhs);
TwistVel operator*(const doubleVel& lhs,const TwistVel& rhs);
TwistVel operator/(const TwistVel& lhs,const doubleVel& rhs);

TwistVel operator+(const TwistVel& lhs,const TwistVel& rhs);
TwistVel operator-(const TwistVel& lhs,const TwistVel& rhs);
TwistVel operator-(const TwistVel& arg);
void SetToZero(TwistVel& v);
bool Equal(const TwistVel& a,const TwistVel& b,double eps=epsilon);
bool Equal(const Twist& a,const TwistVel& b,double eps=epsilon);
bool Equal(const TwistVel& a,const Twist& b,double eps=epsilon);

bool operator==(const TwistVel& r1,const TwistVel& r2);
bool operator!=(const TwistVel& r1,const TwistVel& r2);
bool operator==(const Twist& r1,const TwistVel& r2);
bool operator!=(const Twist& r1,const TwistVel& r2);
bool operator==(const TwistVel& r1,const Twist& r2);
bool operator!=(const TwistVel& r1,const Twist& r2);


VectorVel diff(const VectorVel& a,const VectorVel& b,double dt=1.0);
VectorVel addDelta(const VectorVel& a,const VectorVel&da,double dt=1.0);
VectorVel diff(const RotationVel& a,const RotationVel& b,double dt = 1.0);
RotationVel addDelta(const RotationVel& a,const VectorVel&da,double dt=1.0);
TwistVel diff(const FrameVel& a,const FrameVel& b,double dt=1.0);
FrameVel addDelta(const FrameVel& a,const TwistVel& da,double dt=1.0);

