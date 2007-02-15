#ifndef KDL_SEGMENT_HPP
#define KDL_SEGMENT_HPP

#include "../frames.hpp"
#include "joint.hpp"

namespace KDL {
    
    /**
     * \brief encapsulates a simple segment.
     *
     * This is an <bold>abstract</bold> class.
     * A simple segment is described by the following properties : 
     *      - joint
     *      - mass, stiffnes, damping
     *      - parent segment
     *      - child segment
     *      - Connection offset to the parent
     *
     * @ingroup KinematicFamily
     */
    class Segment {
        typedef double Mass;
        typedef double Stiffness;
        typedef double Damping;
        
    private:
        Joint joint;
        Mass mass;
        Stiffness stiffness;
        Damping damping;
        Segment* parent;
        Segment* child;
        Frame f_to_parent;
        
    public:
        Segment(Joint joint, Frame f_to_parent);
        Segment(const Segment& in);
        Segment& operator = ( const Segment& arg);
        
        virtual ~Segment();
    };
}//end of namespace KDL

#endif
