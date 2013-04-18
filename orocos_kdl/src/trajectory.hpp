/***************************************************************************
  tag: Erwin Aertbelien  Mon Jan 10 16:38:39 CET 2005  trajectory.h

                        trajectory.h -  description
                           -------------------
    begin                : Mon January 10 2005
    copyright            : (C) 2005 Erwin Aertbelien
    email                : erwin.aertbelien@mech.kuleuven.ac.be
    History				 : Wouter Bancken (08/2012) - Refactored

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
 *		$Id: trajectory.h,v 1.1.1.1.2.5 2003/07/23 16:44:25 psoetens Exp $
 *		$Name:  $
 *  \todo
 *     Peter's remark : should seperate I/O from other routines in the
 *     motion/chain directories
 *     The problem is that the I/O uses virtual inheritance to write
 *     the trajectories/geometries/velocityprofiles/...
 *     Have no good solution for this, perhaps
 *          * #ifdef's
 *          * declaring dummy ostream/istream and change implementation file .cpp
 *          * declaring some sort of VISITOR object (containing an ostream) ,
 *            the classes contain code to pass this object around along its children
 *            a subroutine can then be called with overloading.
 *     PROBLEM : if you declare a friend you have to fully declare it  ==> exposing I/O with ostream/istream decl
 *     CONSEQUENCE : everything has to be declared public.
 ****************************************************************************/

#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include "frames.hpp"
#include "frames_io.hpp"
#include "path.hpp"
#include "motionprofile.hpp"
#include <boost/shared_ptr.hpp>

namespace KDL {

	/**
	 * An abstract class that implements
	 * a trajectory contains a cartesian space trajectory and an underlying
	 * motion profile.
	 * @ingroup Motion
	 */
	class Trajectory
	{
		typedef boost::shared_ptr<Trajectory> TrajectoryPtr;
		typedef boost::shared_ptr<Path> PathPtr;
		typedef boost::shared_ptr<MotionProfile> MotionProfilePtr;

	public:
		virtual double Duration() const = 0;
		// The duration of the trajectory

		/**
		 * Position of the trajectory at <time>.
		 *
	     * Exit codes: \n
	     * 		0: OK \n
	     * 		153: Error: Motion planning incompatible \n
		 */
		virtual int Pos(double time, Frame& returned_position) const = 0;

		/**
		 * The velocity of the trajectory at <time>.
		 *
	     * Exit codes: \n
	     * 		0: OK \n
	     * 		153: Error: Motion planning incompatible \n
		 */
		virtual int Vel(double time, Twist& returned_velocity) const = 0;

		/**
		 * The acceleration of the trajectory at <time>.
		 *
	     * Exit codes: \n
	     * 		0: OK \n
	     * 		153: Error: Motion planning incompatible \n
		 */
		virtual int Acc(double time, Twist& returned_acceleration) const = 0;


		virtual TrajectoryPtr Clone() const = 0;
		virtual void Write(std::ostream& os) const = 0;

		/**
		 * Exit codes \n
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
		 * 		151: Error: MotionIO unexpected motion profile \n
		 */
		static int Read(std::istream& is, TrajectoryPtr& returned_trajectory);
		virtual ~Trajectory() {}
		// note : you cannot declare this destructor abstract
		// it is always called by the descendant's destructor !
	};

}
#endif
