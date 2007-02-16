#include "joint.hpp"
#include "../frames.hpp"

namespace KDL {

    JointType type;
    double scale;
    double stiffness;
    double damping;
    double inertia;
    
    Joint::Joint(JointType _type, double _scale, double _offset,
                 double _stiffness,double _damping, double _inertia):
        type(_type),
        scale(_scale),
        offset(_offset),
        stiffness(_stiffness),
        damping(_damping),
        inertia(_inertia)
    {
    }
    
    Joint(const Joint& in)
    {
    }
    
    Joint& operator = ( const Joint& arg)
    {
    }
    
    
    ~Joint()
    {
    }
    
    Frame Joint::pose(double q)
    {
        switch(type){
        case RotX:
            return Frame(Rotation::RotX(q),Vector::Zero());
        case RotY:
            return Frame(Rotation::RotY(q),Vector::Zero());
        case RotZ:
            return Frame(Rotation::RotZ(q),Vector::Zero());
        case TransX:
            return Frame(Rotation::Identity(),Vector(q,0.0,0.0));
        case TransY:
            return Frame(Rotation::Identity(),Vector(0.0,q,0.0));
        case TransZ:
            return Frame(Rotation::Identity(),Vector(0.0,q,0.0));
        default:
            return Frame::Identity();
        }
        
    }

    Twist Joint::twist(double q)
    {
        return q*jac();
    }

    Twist Joint::jac()
    {
        switch(type){
        case RotX:
            return Twist(Vector(0.0,0.0,0.0),Vector(1,0.0,0.0));
        case RotY:
            return Twist(Vector(0.0,0.0,0.0),Vector(0.0,1,0.0));
        case RotZ:
            return Twist(Vector(0.0,0.0,0.0),Vector(0.0,0.0,1));
        case TransX:
            return Twist(Vector(1,0.0,0.0),Vector(0.0,0.0,0.0));
        case TransY:
            return Twist(Vector(0.0,1,0.0),Vector(0.0,0.0,0.0));
        case TransZ:
            return Twist(Vector(0.0,0.0,1),Vector(0.0,0.0,0.0));
        default:
            return Twist::Zero()
    }
    
};

} // end of namespace KDL

#endif
