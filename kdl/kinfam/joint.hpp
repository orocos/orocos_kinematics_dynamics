#ifndef KDL_JOINT_HPP
#define KDL_JOINT_HPP

namespace KDL {

/**
 * \brief encapsulates a simple joint.
 *
 * This is an <bold>abstract</bold> class.
 * A simple joint is described by the following properties : 
 *      - scale
 *      - offset  
 *      - type
 *      - stiffness and damping
 *
 *  for an easier specification of a kinematic chain.
 *
 */
class Joint {
    typedef enum { RotX,RotY,RotZ,TransX,TransY,TransZ,Unknown } JointType;
protected:
    JointType type;
    double scale;
    double offset;
    double stiffness;
    double damping;
    
public:
    Joint(JointType type, double scale=1.0, double offset=0.0,double stiffness=0.0,double damping=0.0);
    Joint(const Joint& in);
    Joint& operator = ( const Joint& arg);
    
   virtual ~Joint();
};

} // end of namespace KDL

#endif
