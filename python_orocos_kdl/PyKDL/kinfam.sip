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

class Joint{

%TypeHeaderCode
#include <kdl/joint.hpp>
using namespace KDL;
%End


public:
    enum JointType {RotAxis,RotX,RotY,RotZ,TransAxis,TransX,TransY,TransZ,None};
    Joint(std::string name, JointType type=None,double scale=1,double offset=0,
              double inertia=0,double damping=0,double stiffness=0);
    Joint(JointType type=None,double scale=1,double offset=0,
          double inertia=0,const double damping=0,double stiffness=0);
    Joint(std::string name, Vector origin, Vector axis, JointType type, double scale=1, double offset=0,
	      double inertia=0, double damping=0, double stiffness=0);
    Joint(Vector origin, Vector axis, JointType type, double scale=1, double offset=0,
	      double inertia=0, double damping=0, double stiffness=0);
    
    Joint(const Joint& in);
    
    Frame pose(const double& q)const /Factory/ ;
    Twist twist(const double& qdot)const /Factory/ ;
    Vector JointAxis() const /Factory/;
    Vector JointOrigin() const /Factory/;
    std::string getName()const;

    JointType getType() const;
    std::string getTypeName() const;
    const char* __repr__();
%MethodCode
    std::ostringstream oss;
    oss<<(*sipCpp);
    std::string s(oss.str());
    sipRes=s.c_str();
%End
};

class RotationalInertia
{
%TypeHeaderCode
#include <kdl/rotationalinertia.hpp>
#include <kdl/kinfam_io.hpp>
using namespace KDL;
%End
public:
    RotationalInertia(double Ixx=0,double Iyy=0,double Izz=0,double Ixy=0,double Ixz=0,double Iyz=0);
        
    static RotationalInertia Zero()/Factory/;
    Vector operator*(Vector omega) const /Factory/;
};
RotationalInertia operator*(double a, const RotationalInertia& I)/Factory/;
RotationalInertia operator+(const RotationalInertia& Ia, const RotationalInertia& Ib)/Factory/;


class RigidBodyInertia
{
%TypeHeaderCode
#include <kdl/rigidbodyinertia.hpp>
#include <kdl/kinfam_io.hpp>
using namespace KDL;
%End
public:
    RigidBodyInertia(double m=0, const Vector& oc=Vector::Zero(), const RotationalInertia& Ic=RotationalInertia::Zero());
    static RigidBodyInertia Zero() /Factory/;        
    RigidBodyInertia RefPoint(const Vector& p) /Factory/;
    double getMass()const /Factory/;        
    Vector getCOG() const /Factory/;
    RotationalInertia getRotationalInertia() const /Factory/;
};
RigidBodyInertia operator*(double a,const RigidBodyInertia& I) /Factory/;
RigidBodyInertia operator+(const RigidBodyInertia& Ia,const RigidBodyInertia& Ib) /Factory/;
Wrench operator*(const RigidBodyInertia& I,const Twist& t) /Factory/;
RigidBodyInertia operator*(const Frame& T,const RigidBodyInertia& I) /Factory/;
RigidBodyInertia operator*(const Rotation& R,const RigidBodyInertia& I) /Factory/;

class Segment
{
    
%TypeHeaderCode
#include <kdl/segment.hpp>
#include <kdl/kinfam_io.hpp>
using namespace KDL;
%End
public:
    Segment(const std::string& name, const Joint& joint=Joint(Joint::None), const Frame& f_tip=Frame::Identity(),const RigidBodyInertia& I = RigidBodyInertia::Zero());
    Segment(const Joint& joint=Joint(Joint::None), const Frame& f_tip=Frame::Identity(),const RigidBodyInertia& I = RigidBodyInertia::Zero());
    Segment(const Segment& in);

    const char* __repr__();
%MethodCode
    std::stringstream ss;
    ss<<(*sipCpp);
    std::string s(ss.str());
    sipRes=s.c_str();
%End
    
    const Frame& getFrameToTip()const /Factory/;
    Frame pose(const double& q)const /Factory/ ;
    Twist twist(const double& q,const double& qdot)const /Factory/ ;
    const std::string& getName()const /Factory/;
    const Joint& getJoint()const /Factory/;
    const RigidBodyInertia& getInertia()const /Factory/;
    void setInertia(const RigidBodyInertia& Iin);
};

class Chain
{
    
%TypeHeaderCode
#include <kdl/chain.hpp>
using namespace KDL;
%End

public:
    Chain();
    Chain(const Chain& in);
    
    void addSegment(const Segment& segment);
    void addChain(const Chain& chain);
        
    unsigned int getNrOfJoints()const;
    unsigned int getNrOfSegments()const;
        
    const Segment& getSegment(unsigned int nr)const /Factory/;

};

class Tree {
%TypeHeaderCode
#include <kdl/tree.hpp>
using namespace KDL;
%End
public:
    Tree(const std::string& root_name="root");
    bool addSegment(const Segment& segment, const std::string& hook_name);
    unsigned int getNrOfJoints()const;
    unsigned int getNrOfSegments()const;
    Chain* getChain(const std::string& chain_root, const std::string& chain_tip)const;
%MethodCode
    Chain* chain = new Chain();
    sipCpp->getChain(*a0, *a1, *chain);
    sipRes = chain;
%End
};

class JntArray{

%TypeHeaderCode
#include <kdl/jntarray.hpp>
using namespace KDL;
%End

public:
    JntArray(unsigned int size);
    JntArray(const JntArray& arg);
    unsigned int rows()const;
    unsigned int columns()const;
    void resize(unsigned int newSize);

    double __getitem__ (int index);
%MethodCode
    if (a0 < 0 || a0 >= sipCpp->rows()) {
        PyErr_SetString(PyExc_IndexError, "JntArray index out of range");
        return 0;
    }
    sipRes=(*sipCpp)(a0);
%End
    
    void __setitem__(int index, double value);
%MethodCode
    if (a0 < 0 || a0 >= sipCpp->rows()) {
        PyErr_SetString(PyExc_IndexError, "JntArray index out of range");
        return 0;
    }
    (*sipCpp)(a0)=a1;
%End

    const char* __repr__();
%MethodCode
    std::stringstream ss;
    ss<<sipCpp->data;
    std::string s(ss.str());
    sipRes=s.c_str();
%End
};

void Add(const JntArray& src1,const JntArray& src2,JntArray& dest);
void Subtract(const JntArray& src1,const JntArray& src2,JntArray& dest);
void Multiply(const JntArray& src,const double& factor,JntArray& dest);
void Divide(const JntArray& src,const double& factor,JntArray& dest);
void MultiplyJacobian(const Jacobian& jac, const JntArray& src, Twist& dest);
void SetToZero(JntArray& array);
bool Equal(const JntArray& src1,const JntArray& src2,double eps=epsilon);
bool operator==(const JntArray& src1,const JntArray& src2);
//bool operator!=(const JntArray& src1,const JntArray& src2);

class JntArrayVel
{
%TypeHeaderCode
#include <kdl/jntarrayvel.hpp>
using namespace KDL;
%End

public:
    JntArray q;
    JntArray qdot;
    JntArrayVel(unsigned int size);
    JntArrayVel(const JntArray& q,const JntArray& qdot);
    JntArrayVel(const JntArray& q);
    void resize(unsigned int newSize);
    
    JntArray value()const /Factory/;
    JntArray deriv()const /Factory/;
};

void Add(const JntArrayVel& src1,const JntArrayVel& src2,JntArrayVel& dest);
void Add(const JntArrayVel& src1,const JntArray& src2,JntArrayVel& dest);
void Subtract(const JntArrayVel& src1,const JntArrayVel& src2,JntArrayVel& dest);
void Subtract(const JntArrayVel& src1,const JntArray& src2,JntArrayVel& dest);
void Multiply(const JntArrayVel& src,const double& factor,JntArrayVel& dest);
void Multiply(const JntArrayVel& src,const doubleVel& factor,JntArrayVel& dest);
void Divide(const JntArrayVel& src,const double& factor,JntArrayVel& dest);
void Divide(const JntArrayVel& src,const doubleVel& factor,JntArrayVel& dest);
void SetToZero(JntArrayVel& array);
bool Equal(const JntArrayVel& src1,const JntArrayVel& src2,double eps=epsilon);

class Jacobian
{
%TypeHeaderCode
#include <kdl/jntarray.hpp>
using namespace KDL;
%End
public:
    Jacobian(unsigned int size);
    Jacobian(const Jacobian& arg);
    unsigned int rows()const;
    unsigned int columns()const;
    void resize(unsigned int newNrOfColumns);

    double __getitem__ (SIP_PYTUPLE);
%MethodCode
    int i,j;
    PyArg_ParseTuple(a0,"ii",&i,&j);
    if (i < 0 || j < 0 || i > 5 || j >= sipCpp->columns()) {
        PyErr_SetString(PyExc_IndexError, "Jacobian index out of range");
        return 0;
    }
    sipRes=(*sipCpp)(i,j);
%End
    
    void __setitem__(SIP_PYTUPLE,double value);
%MethodCode
    int i,j;
    PyArg_ParseTuple(a0,"ii",&i,&j);
    if (i < 0 || j < 0 || i > 5 || j >= sipCpp->columns()) {
        PyErr_SetString(PyExc_IndexError, "Jacobian index out of range");
        return 0;
    }
    (*sipCpp)(i,j)=a1;
%End

    const char* __repr__();
%MethodCode
    std::stringstream ss;
    ss<<sipCpp->data;
    std::string s(ss.str());
    sipRes=s.c_str();
%End
    Twist getColumn(unsigned int i) const /Factory/;
    void setColumn(unsigned int i,const Twist& t);
    
    void changeRefPoint(const Vector& base_AB);
    void changeBase(const Rotation& rot);
    void changeRefFrame(const Frame& frame);

};
void SetToZero(Jacobian& jac);
    
void changeRefPoint(const Jacobian& src1, const Vector& base_AB, Jacobian& dest);
void changeBase(const Jacobian& src1, const Rotation& rot, Jacobian& dest);
void changeRefFrame(const Jacobian& src1,const Frame& frame, Jacobian& dest);


class ChainFkSolverPos
{
%TypeHeaderCode
#include <kdl/chainfksolver.hpp>
using namespace KDL;
%End
    virtual int JntToCart(const JntArray& q_in, Frame& p_out,int segmentNr=-1)=0;
};

class ChainFkSolverVel
{
%TypeHeaderCode
#include <kdl/chainfksolver.hpp>
using namespace KDL;
%End
    virtual int JntToCart(const JntArrayVel& q_in, FrameVel& p_out,int
    segmentNr=-1)=0;
};

class ChainFkSolverPos_recursive : ChainFkSolverPos
{
%TypeHeaderCode
#include <kdl/chainfksolverpos_recursive.hpp>
using namespace KDL;
%End

public:
    ChainFkSolverPos_recursive(const Chain& chain);
    virtual int JntToCart(const JntArray& q_in, Frame& p_out,int segmentNr=-1);
};

class ChainFkSolverVel_recursive : ChainFkSolverVel
{
%TypeHeaderCode
#include <kdl/chainfksolvervel_recursive.hpp>
using namespace KDL;
%End
public:
    ChainFkSolverVel_recursive(const Chain& chain);
    virtual int JntToCart(const JntArrayVel& q_in ,FrameVel& out,int
    segmentNr=-1 );
};

class ChainIkSolverPos {
%TypeHeaderCode
#include <kdl/chainiksolver.hpp>
using namespace KDL;
%End
public:
    virtual int CartToJnt(const JntArray& q_init , const Frame& p_in, JntArray& q_out )=0;
};

class ChainIkSolverVel {
%TypeHeaderCode
#include <kdl/chainiksolver.hpp>
using namespace KDL;
%End
public:
    virtual int CartToJnt(const JntArray& q_in , const Twist& v_in , JntArray& qdot_out )=0;
    virtual int CartToJnt(const JntArray& q_init , const FrameVel& v_in , JntArrayVel& q_out )=0;
};

class ChainIkSolverPos_NR : ChainIkSolverPos
{
%TypeHeaderCode
#include <kdl/chainiksolverpos_nr.hpp>
using namespace KDL;
%End
public:
    ChainIkSolverPos_NR(const Chain& chain,ChainFkSolverPos& fksolver,ChainIkSolverVel& iksolver,
                        unsigned int maxiter=100,double eps=epsilon);
    
    virtual int CartToJnt(const JntArray& q_init , const Frame& p_in ,JntArray& q_out);
};

class ChainIkSolverPos_NR_JL : ChainIkSolverPos
{
%TypeHeaderCode
#include <kdl/chainiksolverpos_nr_jl.hpp>
using namespace KDL;
%End
public:
    ChainIkSolverPos_NR_JL(const Chain& chain,const JntArray &q_min,const JntArray &q_max, 
                        ChainFkSolverPos& fksolver,ChainIkSolverVel& iksolver,
                        unsigned int maxiter=100,double eps=epsilon);
    
    virtual int CartToJnt(const JntArray& q_init , const Frame& p_in ,JntArray& q_out);
};

class ChainIkSolverVel_pinv : ChainIkSolverVel
{
%TypeHeaderCode
#include <kdl/chainiksolvervel_pinv.hpp>
using namespace KDL;
%End
public:
    ChainIkSolverVel_pinv(const Chain& chain,double eps=0.00001,int maxiter=150);
        
    virtual int CartToJnt(const JntArray& q_in, const Twist& v_in, JntArray& qdot_out);
};

class ChainIkSolverVel_wdls : ChainIkSolverVel
{
%TypeHeaderCode
#include <kdl/chainiksolvervel_wdls.hpp>
using namespace KDL;
%End
public:
    ChainIkSolverVel_wdls(const Chain& chain,double eps=0.00001,int maxiter=150);
        
    virtual int CartToJnt(const JntArray& q_in, const Twist& v_in, JntArray& qdot_out);
    void setWeightTS(SIP_PYLIST);
%MethodCode
    //void setWeightTS(const Eigen::MatrixXd& Mx);
    //Mx has to be a 6x6 Matrix

    Py_ssize_t numRows,numCols;
    double c_item;
    PyObject *list=a0;
    numRows=PyList_Size(list);
    PyObject *temp1;
    temp1=PyList_GetItem(list,0);
    numCols=PyList_Size(temp1);
    if (numRows!=numCols) {
       sipIsErr=1; //todo: raise exception
    }
    if (numRows!=6) {
       sipIsErr=1; //todo: raise exception
    }
    Eigen::MatrixXd Mx;
    Mx=Eigen::MatrixXd::Identity(numRows,numCols);
    
    for (Py_ssize_t r=0;r<numRows;r++) {
        PyObject *row;
        row=PyList_GetItem(list,r);
        if (numCols!=PyList_Size(row)) {
           sipIsErr=1; //todo: raise exception
        }
        for (Py_ssize_t c=0;c<numCols;c++) {
            PyObject *item;
            item=PyList_GetItem(row,c);
            c_item=PyFloat_AsDouble(item);
            Mx(r,c)= c_item;
        }
    }
    sipCpp->setWeightTS(Mx);
%End

    void setWeightJS(SIP_PYLIST);
%MethodCode
    //void setWeightJS(const Eigen::MatrixXd& Mx);
    //Mx has to be a simetric positive definite Matrix
    //unsigned int nOfJoints=sipCpp->chain.getNrOfJoints(); //To check that we are receiving valid data dimensions. This doesn't work, chain is a private member. todo: How can we check for this?
    Py_ssize_t numRows,numCols;
    double c_item;
    PyObject *list=a0;
    numRows=PyList_Size(list);
    PyObject *temp1;
    temp1=PyList_GetItem(list,0);
    numCols=PyList_Size(temp1);
    if (numRows!=numCols) {
       sipIsErr=1; //todo: raise exception
    }
    Eigen::MatrixXd Mq;
    Mq=Eigen::MatrixXd::Identity(numRows,numCols);
    for (Py_ssize_t r=0;r<numRows;r++) {
        PyObject *row;
        row=PyList_GetItem(list,r);
        if (numCols!=PyList_Size(row)) {
           sipIsErr=1; //todo: raise exception
        }
        for (Py_ssize_t c=0;c<numCols;c++) {
            PyObject *item;
            item=PyList_GetItem(row,c);
            c_item=PyFloat_AsDouble(item);
            Mq(r,c)= c_item;
        }
    }
    sipCpp->setWeightJS(Mq);
%End

    void setLambda(const double& lambda);

};

class ChainJntToJacSolver
{
%TypeHeaderCode
#include <kdl/chainjnttojacsolver.hpp>
using namespace KDL;
%End
public:
    ChainJntToJacSolver(const Chain& chain);
    int JntToJac(const JntArray& q_in,Jacobian& jac);
};


