/***************************************************************************
                        transformation.h -  description
                       ----------------------------------
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


#ifndef KDL_TRANSFORMATION_H
#define KDL_TRANSFORMATION_H

namespace KDL {

/**
 * \brief Base class for all transformations.
 * 
 * To get an instance for a transformation, instantiate a kinematic family and
 * ask it for a transformation with one of its factory methods.
 *
 * Normally, the transformation is evaluated by an operator() method with arguments depending on the type.  
 * This method should be executable in real-time.  It should take a deterministic 
 * time and not use allocators.
 *
 * You can set and get a configuration object.  To get an instance of a configuration object for your 
 * kinematic family use the createConfiguration method of that family.
 *
 * Guideline for the naming of derivatives for this class :
 *  - In the cartesian domain we have "CartPos" (cartesian pose : 3 rotations / 3 translations) 
 *       "CartVel" ( cartesian velocity or twist : 3 translational velocities and 3 rotational velocities)
 *       "Jac"     ( jacobian ) 
 *  - "Jnt" means the joint space domain.  For the joint spaces the order of derivative is not specified
 *    but derived from the corresponding cartesian domain.
 *
 *  - e.g. of naming :  
 *      - Jnt2CartPos  :    joint positions   -> cartesian position
 *      - CartPos2Jnt  :    cartesian position -> joint positions
 *      - Jnt2CartVel  :    joint positions and joint velocities   ->  cartesian position and velocity.
 *      - CartVel2Jnt  :    joint positions and cartesian velocity ->  joint velocity.
 *      - Jnt2Jac      :    joint positions   -> Jacobian.
 */
class Transformation {
private:
    // users should not copy this object with the copy constructor.
    // should always use the clone() method.
    Transformation(const Transformation& tf) {}
public:
    Transformation() {}

	/**
	 * \brief sets the desired configuration.
	 *
	 * \param q_config double vector that describes the configuration. The 
	 *        meaning and interpretation of q_config is up to the specific 
	 *        kinematic family and transformation object.  
 	 * \warning Do not confuse these q_config vector with the joint values.  Sometimes they could
     *          be the same, sometimes the meaning could be totally different. Look at this vector as
     *          an opaque representation of the configuration.
	 */ 
    virtual void setConfiguration(const std::vector<double>& q_config) {};

	/**
	 * \brief gets the desired configuration.
	 *
	 * \param q_config double vector that describes the configuration. The
	 *        meaning and interpretation of q_config is up to the specific 
	 *        kinematic family and transformation object. 
	 * \warning See remark for setConfiguration.
	 * Should always return a value that can be accepted by setConfiguration(xxx).
	 *
	 */
    virtual void getConfiguration(std::vector<double>& q_config) {};

	virtual ~Transformation() {};
};

} // end of namespace KDL
#endif
