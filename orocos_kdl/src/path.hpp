/***************************************************************************
  tag: Erwin Aertbelien  Mon Jan 10 16:38:38 CET 2005  path.h

                        path.h -  description
                           -------------------
    begin                : Mon January 10 2005
    copyright            : (C) 2012 Wouter Bancken
    					   (C) 2005 Erwin Aertbelien
    email                : erwin.aertbelien@mech.kuleuven.ac.be

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


 /*****************************************************************************
 *  \author
 *  	Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version
 *		ORO_Geometry V0.2
 *
 *	\par History
 *		- $log$
 *
 *	\par Release
 *		$Id: path.h,v 1.1.1.1.2.3 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/

#ifndef KDL_MOTION_PATH_H
#define KDL_MOTION_PATH_H

#include "frames.hpp"
#include <vector>
#include "frames_io.hpp"
#include <boost/shared_ptr.hpp>


namespace KDL {

/**
 * The specification of the path of a trajectory.
 */
class Path
	{
	typedef boost::shared_ptr<Path> PathPtr;

	public:
		enum IdentifierType {
			ID_LINE=1,
			ID_CIRCLE=2,
			ID_COMPOSITE=3,
			ID_ROUNDED_COMPOSITE=4,
			ID_POINT=5,
			ID_CYCLIC_CLOSED=6,
			ID_SPLINE=7
		};
		/**
		 * LengthToS() converts a physical length along the trajectory
		 * to the parameter s used in Pos, Vel and Acc.  This is used because
		 * in cases with large rotations the parameter s does NOT correspond to
		 * the lineair length along the trajectory.
		 * User should be sure that the lineair distance travelled by this
		 * path object is NOT zero, when using this method !
		 * (e.g. the case of only rotational change)
		 *
		 * Exit value: \n
		 * 		0: OK \n
		 * 		152: Error: Motion planning not applicable (if used on composed path objects). \n
		 *
		 * @ingroup Motion
		 */
		virtual int LengthToS(double length, double& returned_length)  = 0;

		/**
		 * Returns the total path length of the trajectory
		 * (has dimension LENGTH)
		 * This is not always a physical length , ie when dealing with rotations
		 * that are dominant.
		 */
		virtual double PathLength() = 0;

		/**
		 * Returns the Frame at the current path length s
		 *
	     * Exit codes: \n
	     * 		0: OK \n
	     * 		153: Error: Motion planning incompatible \n
		 */
		virtual int Pos(double s, Frame& returned_position) const = 0;

		/**
		 * Returns the velocity twist at path length s theta and with
		 * derivative of s == sd
		 *
	     * Exit codes: \n
	     * 		0: OK \n
	     * 		153: Error: Motion planning incompatible \n
		 */
		virtual int Vel(double s,double sd, Twist& returned_velocity) const  = 0;

		/**
		 * Returns the acceleration twist at path length s and with
		 * derivative of s == sd, and 2nd derivative of s == sdd
		 *
	     * Exit codes: \n
	     * 		0: OK \n
	     * 		153: Error: Motion planning incompatible \n
		 */
		virtual int Acc(double s,double sd,double sdd, Twist& returned_acceleration) const  = 0;

		/**
		 * Writes one of the derived objects to the stream
		 */
		virtual void Write(std::ostream& os)  = 0;

	/**
	 * Reads one of the derived objects from the stream and returns a pointer
	 * (factory method)
	 *
	 * Exit codes: \n
	 * 		0: OK \n
	 * 		141: Error: Motion planning not feasible: the eq. radius <= 0 \n
	 *		142: Error: Motion planning not feasible: the first segment in a rounding has zero length \n
	 *		143: Error: Motion planning not feasible: the second segment in a rounding has zero length \n
	 *		144: Error: Motion planning not feasible: the angle between the first and the second segment is close to M_PI (meaning that the segments are on top of each other) \n
	 *		145: Error: Motion planning not feasible: the distance needed for the rounding is larger then the first segment \n
	 *		146: Error: Motion planning not feasible: the distance needed for the rounding is larger then the second segment \n
	 * 		147: Error: MotionIO unexpected trajectory. \n
	 * 		148: Error: Call to an operation that hasn't been implemented. \n
	 *		149: Error: Motion planning circle too small \n
	 * 		150: Error: Motion planning circle no plane \n
	 */
		static int Read(std::istream& is, PathPtr& returned_path);

		/**
		 * Virtual constructor, constructing by copying,
		 * Returns a deep copy of this Path Object
		 */
		virtual PathPtr Clone() = 0;

		/**
		 * gets an identifier indicating the type of this Path object
		 */
		virtual IdentifierType getIdentifier() const=0;

		virtual ~Path() {}
	};

}


#endif
