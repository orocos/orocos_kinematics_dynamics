/***************************************************************************
  tag: Erwin Aertbelien  Mon Jan 10 16:38:38 CET 2005  velocityprofile_rect.h

                        velocityprofile_rect.h -  description
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
 *		$Id: velocityprofile_rect.h,v 1.1.1.1.2.4 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/

#ifndef MOTIONPROFILE_RECT_H
#define MOTIONPROFILE_RECT_H

#include "motionprofile.hpp"
#include <boost/shared_ptr.hpp>


namespace KDL {
	/**
	 * A rectangular MotionProfile generates a constant velocity
	 * for moving from A to B.
	 * @ingroup Motion
	 */
	class MotionProfile_Rectangular : public MotionProfile
		// Defines a rectangular motionprofile.
		// (i.e. constant velocity)
	{
		typedef boost::shared_ptr<MotionProfile_Rectangular> MotionProfileRectangularPtr;
		typedef boost::shared_ptr<MotionProfile> MotionProfilePtr;

		double d,p,v;
	public:
		double maxvel;

		// constructs motion profile class with <maxvel> as parameter of the
		// trajectory.
		static int Create(MotionProfileRectangularPtr& profile, double _maxvel=0);
		// constructs motion profile class with <maxvel> as parameter of the
		// trajectory. It also sets a trajectory from pos1 to pos2.
		static int Create(MotionProfileRectangularPtr& profile, double _maxvel, double pos1, double pos2);

		void SetMax( double _maxvel );
		void SetProfile(double pos1,double pos2);
		virtual void SetProfileDuration(
			double pos1,double pos2,double duration);
		virtual double Duration() const;
		virtual int Pos(double time, double& returned_position) const;
		virtual int Vel(double time, double& returned_velocity) const;
		virtual int Acc(double time, double& returned_acceleration) const;
		virtual void Write(std::ostream& os) const;
		virtual MotionProfilePtr Clone() const{
			MotionProfileRectangularPtr profile;
			MotionProfile_Rectangular::Create(profile, maxvel);
			profile->SetProfileDuration( p, p+v*d, d );
			return profile;
		}
		// returns copy of current MotionProfile object. (virtual constructor)
		virtual ~MotionProfile_Rectangular() {}

	private:
		MotionProfile_Rectangular() {}
	};

}


#endif
