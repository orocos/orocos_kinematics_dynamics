
#include "chain.hpp"

namespace KDL {
    
    Chain::Chain(const string& _name):
        segments(0),
        nrOfJoints(0),
        name(_name)
    {
    }
    
    Chain::Chain(const Chain& in)
    {
    }
    
    Chain& Chain::operator = ( const Chain& arg)
    {
    }
    
    void Chain::addSegment(Segment* segment)
    {
        segments.push_back(segment);
        nrOfJoints++;
    }
    
    Chain::~Chain()
    {
    }
    
}

