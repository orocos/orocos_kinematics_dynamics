#ifndef KDL_BODY_HPP
#define KDL_BODY_HPP

#include <kdl/frames.hpp>

namespace KDL {

/**
 * \brief encapsulates a simple body.
 *
 * This is an <bold>abstract</bold> class.
 * A simple body is described by the following properties : 
 *      - a frame describing the connection offset wrt to the previous joint
 *      - a frame describing the link lenght: connection of the next joint
 *      - inertia
 * @ingroup KinematicFamily
 */
class Body {
protected:
    Frame offset;
    Frame link;
    double inertia;
    
public:
    Body(Frame link, Frame offset = Frame::Identity(), double inertia=0.0);
    Body(const Body& in);
    Body& operator = ( const Body& arg);
    
   virtual ~Body();
};

} // end of namespace KDL

#endif
