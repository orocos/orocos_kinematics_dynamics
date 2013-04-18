/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  path_cyclic_closed.cxx

                        path_cyclic_closed.cxx -  description
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
 *		$Id: path_cyclic_closed.cpp,v 1.1.1.1.2.5 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/


#include "path_cyclic_closed.hpp"
#include "utilities/error.h"

namespace KDL {

int Path_Cyclic_Closed::Create(	PathPtr _geom,
								int _times,
								PathCyclicClosedPtr& cyclic_closed,
								bool _aggregate)
{
	cyclic_closed = PathCyclicClosedPtr(new Path_Cyclic_Closed());
	cyclic_closed->times = _times;
	cyclic_closed->geom = _geom;
	cyclic_closed->aggregate = _aggregate;
	return 0;
}

int Path_Cyclic_Closed::LengthToS(double length, double& returned_length) {
	return 152;
}

double Path_Cyclic_Closed::PathLength(){
	return geom->PathLength()*times;
}

int Path_Cyclic_Closed::Pos(double s, Frame& returned_position) const  {
	int exit_code = geom->Pos( fmod(s,geom->PathLength()), returned_position );
	return exit_code;
}

int Path_Cyclic_Closed::Vel(double s,double sd, Twist& returned_velocity) const  {
	int exit_code = geom->Vel( fmod(s,geom->PathLength()),sd, returned_velocity);
	return exit_code;
}

int Path_Cyclic_Closed::Acc(double s,double sd,double sdd, Twist& returned_acceleration) const  {
	int exit_code = geom->Acc( fmod(s,geom->PathLength()),sd,sdd, returned_acceleration );
	return exit_code;
}

Path_Cyclic_Closed::~Path_Cyclic_Closed() {
    if (aggregate)
        geom.reset();
}

boost::shared_ptr<Path> Path_Cyclic_Closed::Clone() {
	PathCyclicClosedPtr cyclic_closed;
	Path_Cyclic_Closed::Create(geom->Clone(),times, cyclic_closed, aggregate);
	return cyclic_closed;
}

void Path_Cyclic_Closed::Write(std::ostream& os)  {
	os << "CYCLIC_CLOSED[ ";
	os << "  ";geom->Write(os);os << std::endl;
	os << "  " << times << std::endl;
	os << "]"  << std::endl;
}

}

