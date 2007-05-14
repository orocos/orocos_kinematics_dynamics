#ifndef  KDL_SERIALCHAIN_CPP
#define KDL_SERIALCHAIN_CPP

/***************************************************************************
                        serialchain.hpp -  description
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Erwin Aertbelien
    email                : firstname.lastname@mech.kuleuven.ac.be

 History (only major changes)( AUTHOR-Description ) :
 
 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/

#include <kdl/kinfam/transmission.hpp>
#include <kdl/kinfam/jnt2cartpos.hpp>
#include <kdl/kinfam/cartpos2jnt.hpp>
#include <kdl/kinfam/jnt2jac.hpp>
#include <kdl/kinfam/kinematicfamily.hpp>
#include <kdl/kinfam/joint.hpp>
#include <kdl/jacobianframe.hpp>
#include <kdl/frames.hpp>
#include <vector>



namespace KDL {

// forward declaration of SerialChain.
class SerialChain;



/**
 * \brief Implementation of KinematicFamily for serial chains.
 * \ingroup kinfam
 */
class SerialChain: public KinematicFamily {
	std::string name;
    JointList joints;       // all the joints
    Frame F_lj_ee;          // end effector wrt last joint (parameter)


public:
  Transmission* transmission;
  /**
   * \param name       : name of the kinematic chain.
   * \param nrofjoints : the number of joints that this serial chain will contain.
   * \param offset     : offset that is applied to the index of the joints. 
   *                     To get a subset of a jointvector.
   * \param transmission: The transmission between actuated joints and geometric joints.
   *			  transmission will be owned by the SerialChain object.
   */
    SerialChain(const std::string& name="default",int nrofjoints=0,int offset=0,Transmission* transmission= 0);
    SerialChain(const SerialChain& sc);
    SerialChain& operator = (const SerialChain& in);
    
    ~SerialChain();

public: // implementation of KinematicFamily :

  virtual Jnt2CartPos* createJnt2CartPos() const;
  virtual Jnt2Jac* createJnt2Jac() const;
  virtual CartPos2Jnt* createCartPos2Jnt() const;
  virtual Jnt2CartVel* createJnt2CartVel() const;
  virtual CartVel2Jnt* createCartVel2Jnt() const;
  virtual KinematicFamily* clone() const;
public: // implementation of meta-information for KinematicFamily :
  virtual std::string getTypeName() const {
    return "serialchain";
  }
  virtual std::string getName() const {
    return name;
  }
  
public: // methods for this class only :
	/**
	 * \brief add a joint to the kinematic chain.
	 * 
	 * The SerialChain object owns the object pointed to by "joint"
	 */
  void addJoint(Joint* joint);
  
  /**
   * \brief get the transformation from the last joint to the end effector.
   */
  Frame getLastJointToEE() const;
  
  /**
   * \brief set the transformation from the last joint to the end effector.
   */
  void setLastJointToEE(const Frame& F_lj_ee);
  
  /**
   * \brief returns the ith joint
   *
   * The instance returned by this method is still owned by SerialChain and will be
   * deleted when the serialchain instance is deleted.  There is a routine returning a
   * a const pointer and a routine returning a normal pointer.
   */
  const Joint* getJoint(unsigned int i) const;
  
  /**
   * \brief returns the ith joint
   */
  Joint* getJoint(unsigned int i);
  
  /**
   * \brief adds the joints of another chain after this chain and takes into account lastJointToEE.
   * \todo
   *    This method does not take into account transmission.  For now there exists no composition for
   *    transmissions.
   */
  void addChain(const SerialChain* chain);
  
  
private:
  void clear();
};
  
} // namespace KDL

#endif
