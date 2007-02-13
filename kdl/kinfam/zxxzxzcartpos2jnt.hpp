/***************************************************************************
                        zxxzxzcartpos2jnt.hpp -  description
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


#ifndef KDL_ZXXZXZCARTPOS2JNT_HPP
#define KDL_ZXXZXZCARTPOS2JNT_HPP

#include <kdl/kdl.hpp>
#include <kdl/frames.hpp>
#include <kdl/kinfam/cartpos2jnt.hpp>
#include <kdl/kinfam/zxxzxz.hpp>
#include <kdl/kinfam/transmission.hpp>

namespace KDL {
  
  /**
   * \brief calculates joint values from a cartesian position.
   *
   */
  class ZXXZXZCartPos2Jnt : public CartPos2Jnt {
    typedef ZXXZXZ      ChainType;
    const ZXXZXZ*       chain;
    Frame                           F_base_ee;
    int								configuration;
    JointVector		                q;
    Transmission*                   trans;
  public:
    
    ZXXZXZCartPos2Jnt(const ChainType* _chain);
    /**
     * \brief sets the desired Frame for an endpoint.
     */
    virtual void setFrame(const Frame& f,int endpoint=0,int basepoint=0);
    
    /**
     * \brief evaluates and returns the joint values.
     *
     * \param q will contain the resulting joint values.
     * \return errorcode.  0 if succesfull. 1 if the robot is in a
     * singular position
     */
    virtual int evaluate(JointVector& _q);
    
    /**
     * \brief make a deep virtual copy 
     */
    virtual ZXXZXZCartPos2Jnt* clone() const;

   	/**
	 * \brief sets the desired configuration.
	 *
	 * \param q_config double vector that describes the configuration.  
 	 *
	 * This q_config is used to calculate a compact representation of the configuration
	 * that is used in the evaluate() routine. 
	 */ 
    virtual void setConfiguration(const std::vector<double>& q_config);


	/**
	 * \brief gets the desired configuration.
	 *
	 * \param q_config double vector that describes the configuration.
     *
	 * Out of the compact representation a q_config is calculated. 
	 */
    virtual void getConfiguration(std::vector<double>& q_config);

	/**
	 * \brief sets configuration in a compact way.
	 *
	 */
	virtual void setConfiguration(int config); 

	/**
	 * \brief gets compact representation of the configuration.
	 */
	virtual void getConfiguration(int& config);


    virtual ~ZXXZXZCartPos2Jnt();
  };
  
} // end of namespace KDL

#endif
