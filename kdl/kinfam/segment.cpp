
#include "segment.hpp"

namespace KDL {
    
    Segment::Segment(Joint* _joint, const Frame& _f_to_parent):
        joint(_joint),
        f_to_parent(_f_to_parent)
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

}//end of namespace KDL

