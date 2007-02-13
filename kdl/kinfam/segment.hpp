#ifndef KDL_SEGMENT_HPP
#define KDL_SEGMENT_HPP

#include <kdl/frames.hpp>
#include <vector>
#include <string>

namespace KDL {

/**
 * \brief encapsulates a simple segment.
 *
 * This is an <bold>abstract</bold> class.
 * A simple segment is described by the following properties : 
 *      - joint
 *      - body  
 *      - parent segment
 *      - child segment
 *
 * And supports the following functions:
 *      - twist()
 *      - pose(q)
 *
 */
class Segment {
protected:
    Joint joint;
    Body body;
    Segment* parent;
    Segment* child;
public:
    Segment(Joint joint, Body body, Segment* parent);
    Segment(const Segment& in);
    Segment& operator = ( const Segment& arg);
    
    /**
     * \brief returns the twist of the (origin of) {end} w.r.t. {base} 
     */
    virtual Twist twist() const =0;

   /**
    * \brief returns the transformation of {end} w.r.t. {base}
    */
    virtual Frame pose(double q) const =0;
    
    virtual Segment* clone() const = 0;
    
    virtual ~Segment();
};


#endif
