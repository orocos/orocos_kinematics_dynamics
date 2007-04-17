#include <kdl/kinfam/joint.hpp>
#include <kdl/frames_io.hpp>
#include <sstream>


namespace KDL { 


    //=============================================
    // implementation of Joint and derived classes 
    //=============================================
    Joint::Joint(Frame _F_before_joint):
        F_before_joint(_F_before_joint) 
    {
    }
    
    Joint::Joint(const Joint& in):
        F_before_joint(in.frame_before_joint())
    {
    }
    Joint& Joint::operator = (const Joint& arg)
    {
        this->frame_before_joint(arg.frame_before_joint());
        return *this;
    }
    
    Frame Joint::frame_before_joint() const {
        return F_before_joint;
    }

    void Joint::frame_before_joint(const Frame& f) {
        F_before_joint = f;
    }

    Joint::~Joint()
    {
    };


    JointRotZ::JointRotZ(const Frame& _F_before_joint):
        Joint(_F_before_joint) 
    {
    }
    Twist JointRotZ::twist() const
    {
        return F_before_joint.M*Twist(Vector::Zero(),Vector(0,0,1));
    }
    
    Frame JointRotZ::pose(double q) const
    {
        return F_before_joint*Frame(Rotation::RotZ(q),Vector::Zero());
    }
    
    Joint* JointRotZ::clone() const 
    {
        return new JointRotZ(F_before_joint);
    }
    std::string JointRotZ::getDescription() const 
    {
        std::ostringstream os;
        os << "Joint Rotation around Z " << std::endl 
           << "with frame : " << F_before_joint << std::endl;
        return os.str();
    }
    
    Joint::JointType JointRotZ::getType() const {
        return RotZ;
    };
    
    JointRotY::JointRotY(const Frame& _F_before_joint):
        Joint(_F_before_joint) 
    {
    }
    Twist JointRotY::twist() const
    {
        return F_before_joint.M*Twist(Vector::Zero(),Vector(0,1,0));
    }
    
    Frame JointRotY::pose(double q) const
    {
        return F_before_joint*Frame(Rotation::RotY(q),Vector::Zero());
    }

    Joint* JointRotY::clone() const 
    {
        return new JointRotY(F_before_joint);
    }
    std::string JointRotY::getDescription() const 
    {
        std::ostringstream os;
        os << "Joint Rotation around Y " << std::endl 
           << "with frame : " << F_before_joint << std::endl;
    return os.str();
    }
    Joint::JointType JointRotY::getType() const {
        return RotY;
    };
    
    
    

    JointRotX::JointRotX(const Frame& _F_before_joint):
        Joint(_F_before_joint) 
    {
    }
    Twist JointRotX::twist() const
    {
        return F_before_joint.M*Twist(Vector::Zero(),Vector(1,0,0));
    }
    
    Frame JointRotX::pose(double q) const
    {
        return F_before_joint*Frame(Rotation::RotX(q),Vector::Zero());
    }
    
    Joint* JointRotX::clone() const 
    {
        return new JointRotX(F_before_joint);
    }
    
    std::string JointRotX::getDescription() const 
    {
        std::ostringstream os;
        os << "Joint Rotation around X " << std::endl 
           << "with frame : " << F_before_joint << std::endl;
        return os.str();
    }
    Joint::JointType JointRotX::getType() const {
        return RotX;
    };
    
    
    
    
    
    JointTransX::JointTransX(const Frame& _F_before_joint):
        Joint(_F_before_joint) 
    {
    }
    Twist JointTransX::twist() const
    {
        return F_before_joint.M*Twist(Vector(1.0, 0.0, 0.0),Vector::Zero());
    }
    
    Frame JointTransX::pose(double q) const
    {
        return F_before_joint*Frame(Rotation::Identity(),Vector(q, 0.0 ,0.0));
    }
    
    Joint* JointTransX::clone() const 
    {
        return new JointTransX(F_before_joint);
    }
    
    std::string JointTransX::getDescription() const 
    {
        std::ostringstream os;
        os << "Joint Translation around X " << std::endl 
           << "with frame : " << F_before_joint << std::endl;
        return os.str();
    }
    Joint::JointType JointTransX::getType() const {
        return TransX;
    };
    
    
    
    
    JointTransY::JointTransY(const Frame& _F_before_joint):
        Joint(_F_before_joint) 
    {
    }
    Twist JointTransY::twist() const
    {
        return F_before_joint.M*Twist(Vector(0.0, 1.0, 0.0),Vector::Zero());
    }
    
    Frame JointTransY::pose(double q) const
    {
        return F_before_joint*Frame(Rotation::Identity(),Vector(0.0, q, 0.0));
    }
    
    Joint* JointTransY::clone() const 
    {
        return new JointTransY(F_before_joint);
    }
    
    std::string JointTransY::getDescription() const 
    {
        std::ostringstream os;
        os << "Joint Translation around Y " << std::endl 
           << "with frame : " << F_before_joint << std::endl;
        return os.str();
    }
    Joint::JointType JointTransY::getType() const {
        return TransY;
    };
    
    
    
    
    
    
    JointTransZ::JointTransZ(const Frame& _F_before_joint):
        Joint(_F_before_joint) 
    {
    }
    Twist JointTransZ::twist() const
    {
        return F_before_joint.M*Twist(Vector(0.0, 0.0, 1.0),Vector::Zero());
    }
    
    Frame JointTransZ::pose(double q) const
    {
        return F_before_joint*Frame(Rotation::Identity(),Vector(0.0, 0.0, q));
    }
    
    Joint* JointTransZ::clone() const 
    {
        return new JointTransZ(F_before_joint);
    }
    
    std::string JointTransZ::getDescription() const 
    {
        std::ostringstream os;
        os << "Joint Translation around Z " << std::endl 
           << "with frame : " << F_before_joint << std::endl;
        return os.str();
    }
    Joint::JointType JointTransZ::getType() const {
        return TransZ;
    };
    
    
} // end of namespace KDL
