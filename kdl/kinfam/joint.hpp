#ifndef KDL_JOINT_HPP
#define KDL_JOINT_HPP

#include <kdl/frames.hpp>
#include <vector>
#include <string>

namespace KDL {

/**
 * \brief encapsulates a simple joint.
 *
 * This is an <bold>abstract</bold> class.
 * A simple joint is described by the following reference frames : 
 *      - base   
 *      - joint  
 *      - end 
 * The joint consists of a composition of two transformations between the reference frames:
 *  - F_base_joint is a fixed transformation.
 *  - F_joint_end  depends on the joint value.
 *     (normally a rotation or translation)
 *  - The joint is in most of the cases a simple rotation or translation in the joint frame.
 *  The twist is expressed in the end-frame
 *  The pose is expressed as end with respect to the base.
 *  
 *  There are JointRotX,JointRotY,JointRotZ and JointTransX,JointTransY,JointTransZ implementations
 *  of this class, although JointRotX and TranslationZ would be enough.  These other implementations allow
 *  for an easier specification of a kinematic chain.
 *
 */
class Joint {
protected:
    Frame F_before_joint;
public:
    typedef enum { RotX,RotY,RotZ,TransX,TransY,TransZ,Unknown } JointType;
public:
   
    Joint(Frame _F_before_joint=Frame::Identity());
    Joint(const Joint& in);
    Joint& operator = ( const Joint& arg);
    
   /**
    * \brief returns the twist of the (origin of) {end} w.r.t. {base} 
    */
   virtual Twist twist() const =0;

   /**
    * \brief returns the transformation of {end} w.r.t. {base}
    */
   virtual Frame pose(double q) const =0;

   /**
    * \brief returns frame of joint w.r.t. the jointbase
    * 
    */
   virtual Frame frame_before_joint() const;

   /**
    * \brief sets the frame of the joint w.r.t. the jointbase.
    */
   virtual void frame_before_joint(const Frame& f);

   /**
	* \brief makes a deep virtual copy.
	*/
   virtual Joint* clone() const = 0;

	/**
	 * returns a textual description of this joint.
	 */
   virtual std::string getDescription() const = 0;

	/**
	 * returns the type of the Joint.
	 */
   virtual JointType getType() const = 0;

   virtual ~Joint();
};
/**
 * \brief implements Joint for a rotation around X
 */
class JointRotX : public Joint {
public:
    JointRotX(const Frame& _F_before_joint=Frame::Identity());
   virtual Twist twist() const; 

   virtual Frame pose(double q) const;

   virtual Joint* clone() const;

   virtual std::string getDescription() const;
   
   virtual JointType getType() const;

};

/**
 * \brief implements Joint for a rotation around Y 
 */
class JointRotY : public Joint {
public:
    JointRotY(const Frame& _F_before_joint=Frame::Identity());
    virtual Twist twist() const; 

    virtual Frame pose(double q) const;

   virtual Joint* clone() const;

   virtual std::string getDescription() const;
   
   virtual JointType getType() const;
};

/**
 * \brief implements Joint for a rotation around Y 
 */
class JointRotZ : public Joint {
public:
    JointRotZ(const Frame& _F_before_joint=Frame::Identity());
    virtual Twist twist() const; 

    virtual Frame pose(double q) const;

   virtual Joint* clone() const;

   virtual std::string getDescription() const;
   
   virtual JointType getType() const;
};
/**
 * \brief implements Joint for a translation around X 
 */
class JointTransX : public Joint {
public:
    JointTransX(const Frame& _F_before_joint=Frame::Identity());
    virtual Twist twist() const; 

    virtual Frame pose(double q) const;

   virtual Joint* clone() const;

   virtual std::string getDescription() const;
   
   virtual JointType getType() const;
};

/**
 * \brief implements Joint for a translation around X 
 */
class JointTransY : public Joint {
public:
    JointTransY(const Frame& _F_before_joint=Frame::Identity());
    virtual Twist twist() const; 

    virtual Frame pose(double q) const;

   virtual Joint* clone() const;

   virtual std::string getDescription() const;
   
   virtual JointType getType() const;
};

/**
 * \brief implements Joint for a translation around X 
 */
class JointTransZ : public Joint {
public:
    JointTransZ(const Frame& _F_before_joint=Frame::Identity());
    virtual Twist twist() const; 

    virtual Frame pose(double q) const;

   virtual Joint* clone() const;

   virtual std::string getDescription() const;
   
   virtual JointType getType() const;
};




/**
 * a list of Joints describing a serial chain.
 */
typedef std::vector<Joint*> JointList;

} // end of namespace KDL

#endif
