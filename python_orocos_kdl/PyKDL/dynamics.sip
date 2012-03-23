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
    if (i < 0 || j < 0 || i > sipCpp->rows() || j >= sipCpp->columns()) {
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
