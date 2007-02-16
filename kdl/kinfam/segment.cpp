
#include "segment.hpp"

namespace KDL {
    
    Segment::Segment(Joint* _joint, const Frame& _f_from_parent):
        joint(_joint),
        f_from_parent(_f_from_parent)
        mass(0),
        stiffness(0),
        damping(0)
    {
    }
    
    Segment::Segment(const Segment& in)
    {
    }
    
    Segment::Segment& operator = ( const Segment& arg)
    {
    }
    
    
    Segment::~Segment()
    {
    }

    Frame Segment::pose(double q)
    {
        return f_from_parent*joint->pose(q);
    }
    
    Twist Segment::twist(double q, Twist& t)
    {
        return f_from_parent.M*joint->twist(q);
    }

    Twist Segment::jac()
    {
        return f_from_parent.M*joint->jac
    }
    
}//end of namespace KDL

