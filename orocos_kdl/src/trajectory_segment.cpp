/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  trajectory_segment.cxx

                        trajectory_segment.cxx -  description
                           -------------------
    begin                : Mon May 10 2004
    copyright            : (C) 2012 Wouter Bancken
    					   (C) 2004 Erwin Aertbelien
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
 *		$Id: trajectory_segment.cpp,v 1.1.1.1.2.7 2003/07/23 16:44:26 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/

#include "trajectory_segment.hpp"

namespace KDL {

// assume everything is set or at least check if Duration() != 0
int Trajectory_Segment::Create(	PathPtr _geom,
								MotionProfilePtr _motprof,
								TrajectorySegmentPtr& segment,
								bool _aggregate)
{
	segment = TrajectorySegmentPtr(new Trajectory_Segment());
	segment->motprof = _motprof;
	segment->geom = _geom;
	segment->aggregate = _aggregate;
	return 0;
}

// the duration was specified so assume motprof not yet set.
int Trajectory_Segment::Create(	PathPtr _geom,
								MotionProfilePtr _motprof,
								double _duration,
								TrajectorySegmentPtr& segment,
								bool _aggregate)
{
	segment = TrajectorySegmentPtr(new Trajectory_Segment());
	segment->motprof = _motprof;
	segment->geom = _geom;
	segment->aggregate = _aggregate;
	segment->motprof->SetProfileDuration(0, segment->geom->PathLength(), _duration);
	return 0;
}

double Trajectory_Segment::Duration() const
{
	return motprof->Duration();
}

int Trajectory_Segment::Pos(double time, Frame& returned_position) const
{
	double temp;
	int exit_code = motprof->Pos(time,temp);
	if(exit_code != 0){
		return exit_code;
	}
	double position;
	exit_code = motprof->Pos(time,position);
	if(exit_code != 0){
		return exit_code;
	}
	exit_code = geom->Pos(position, returned_position);
	return exit_code;
}

int Trajectory_Segment::Vel(double time, Twist& returned_velocity) const
{
	double position;
	double velocity;
	int exit_code;
	exit_code = motprof->Pos(time,position);
	if(exit_code != 0){
		return exit_code;
	}
	exit_code = motprof->Vel(time, velocity);
	if(exit_code != 0){
		return exit_code;
	}
	exit_code = geom->Vel(position, velocity, returned_velocity);
	return exit_code;
}

int Trajectory_Segment::Acc(double time, Twist& returned_acceleration) const
{
	double position;
	double velocity;
	double acceleration;
	int exit_code;
	exit_code = motprof->Pos(time,position);
	if(exit_code != 0){
		return exit_code;
	}
	exit_code = motprof->Vel(time, velocity);
	if(exit_code != 0){
		return exit_code;
	}
	exit_code = motprof->Acc(time, acceleration);
	if(exit_code != 0){
		return exit_code;
	}
	exit_code = geom->Acc(position, velocity, acceleration, returned_acceleration);
	return exit_code;
}

void Trajectory_Segment::Write(std::ostream& os) const
{
	os << "SEGMENT[ " << std::endl;
	os << "  ";geom->Write(os);os << std::endl;
	os << "  ";motprof->Write(os);os << std::endl;
	os << "]";
}

Trajectory_Segment::~Trajectory_Segment()
{
    if (aggregate)
        {
            motprof.reset();
            geom.reset();
        }
}

boost::shared_ptr<Path> Trajectory_Segment::GetPath() {
	return geom;
}

boost::shared_ptr<MotionProfile> Trajectory_Segment::GetProfile() {
	return motprof;
}


}
