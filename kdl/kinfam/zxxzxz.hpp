#ifndef KDL_ZXXZXZ_HPP
#define KDL_ZXXZXZ_HPP

/***************************************************************************
                        zxxzxz.hpp -  description
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

#include <kdl/jacobianframe.hpp>
#include <kdl/frames.hpp>
#include <vector>
#include <kdl/kinfam/transmission.hpp>
#include <kdl/kinfam/jnt2cartpos.hpp>
#include <kdl/kinfam/cartpos2jnt.hpp>
#include <kdl/kinfam/jnt2jac.hpp>
#include <kdl/kinfam/kinematicfamily.hpp>
#include <kdl/kinfam/serialchain.hpp>



// \TODO Until there is a  implementation for all transformations.
#include <kdl/kinfam/serialchain.hpp>

namespace KDL {

    // forward declaration of the kinematic family ZXXZXZ :
    class ZXXZXZ;
    
    /**
     * \brief implements KinematicFamily for a  ZXXZXZ kinematic chain.
     * \ingroup kinfam
     */
    class ZXXZXZ: public KinematicFamily {
        std::string name;
        int jointoffset;
        double l1,l2,l3,l6;
        mutable SerialChain* serchain; //\TODO
    public:
        Transmission* transmission;
        /**
         * \param name : name of the kinematic chain.
         * \param offset : offset to the INDEX of the joint values.
         * \param transmission: The transmission between actuated joints and geometric joints.
         *			  transmission will be owned by the ZXXZXZ object.
         */
        ZXXZXZ(const std::string& name="default",int offset=0,Transmission* transmission = 0);
        ZXXZXZ(const ZXXZXZ& in);
        ZXXZXZ& operator = (const ZXXZXZ& in);
        
        ~ZXXZXZ();

        
    public: // implementation of KinematicFamily :
        
        virtual Jnt2CartPos* createJnt2CartPos() const;
        virtual Jnt2Jac* createJnt2Jac() const;
        virtual CartPos2Jnt* createCartPos2Jnt() const;
        virtual CartVel2Jnt* createCartVel2Jnt() const;
        virtual Jnt2CartVel* createJnt2CartVel() const;
        
        virtual KinematicFamily* clone() const;
        
    public: //
        /**
         * \brief creates a serial chain that has the same kinematics as this class.
         * \warning The user is responsible for deleting the SerialChain after its use.
         */
        virtual SerialChain* createSerialChain() const;
        
        /**
         * \brief description of a configuration.
         * The configuration can exist of a combination of the tree possibilities in the 
         * enumeration type.
         */
        typedef enum { Backward=0x1, Flip=0x2, ElbowDown=0x4 } ConfigurationType;	
        
        /**
         * \brief converts q-vector in a compact description of the configuration.
         * \warning In general, the q's you give for configuration could be unrelated to the q's
         *          describing the position of the robot.  In this case, the q's correspond to the
         *          geometric joints of the class.  Always get and set the q's with the configuration
         *          routines.
         */
        virtual int getConfigurationFromJoints(const std::vector<double>& q) const;
        
        /**
         * \brief converts a compact description of the configuration in a q-vector.
         * \warning See remark for getConfigurationFromJoints.
         */
        virtual void setConfigurationToJoints(int config,std::vector<double>& q) const;
        
        /**
         * \brief gets a string representation of a configuration.
         */
        virtual std::string getConfigurationDescription(int config) const; 
        
    public: // implementation of meta-information for KinematicFamily :
        /**
         * \brief returns the type of the kinematic family object.
         */
        virtual std::string getTypeName() const{
            return "zxxzxz";
        }
        /**
         * \brief returns the name of this instance of the kinematic family object, 
         */
        virtual std::string getName() const{
            return name;
        }
    
    public: //implementation of  specific meta information
        
        /**
         *  Set the armlength of all robot links.
         *
         * \param l1: 
         * \param l2: 
         * \param l3: 
         * \param l6: 
         * The other link lengts are zero.
         */
        virtual void setLinkLengths( const double l1, const double l2, const double l3, const double l6);
        
        /**
         * \brief Get the link lengths from link 1, link 2, link 3 and link 6.
         */
        virtual double getLinkLength(int i) const;
        
        /** decision variable: XY distance between wrist and shoulder */
        static const double EPS_WRIST_ABOVE_BASE; // units: m
        
        /** decision variable: distance of wrist to shoulder must lie between
            sqrt(sq(L2+L3)) and sqrt(sq(L2-L3)). */
        static const double EPS_ARM_EXTENDED; // units: m
    
        /** decision variable: sine of flip angle (fifth joint) goes to zero. */
        static const double EPS_PARALLEL_WRIST; // units: dimensionless
        
        /** Considered VERY small in the context of kinematic calculations. */
        static const double KINEMATICS_EPS;
        
    };
} // namespace
#endif
