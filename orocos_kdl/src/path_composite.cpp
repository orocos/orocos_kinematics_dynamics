/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  path_composite.cxx

                        path_composite.cxx -  description
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
 *		$Id: path_composite.cpp,v 1.1.1.1.2.7 2003/07/24 13:49:16 rwaarsin Exp $
 *		$Name:  $
 ****************************************************************************/


#include "path_composite.hpp"
#include "utilities/error.h"
#include <memory>
#include <vector>
#include <algorithm>

namespace KDL {

// s should be in allowable limits, this is not checked
// binary search
// uses cached_... variables
// returns the relative path length within the segment
// you propably want to use the cached_index variable
double Path_Composite::Lookup(double s) const
{
	//Asserts
	assert(s>=0);
	assert(s<=pathlength);

	//Test cache
	if ( (cached_starts <=s) && ( s <= cached_ends) ) {
		return s - cached_starts;
	}

	//Search
	std::vector<double>::const_iterator low = lower_bound(dv.begin(), dv.end(), s);

	//Evaluate:
	if(int(low - dv.begin()) < dv.size()){
		cached_index = int(low - dv.begin());
		if(cached_index == 0)
			cached_starts = 0;
		else
			cached_starts = *(low - 1);
		cached_ends = *low;
		return s - cached_starts;
	}
	else {
		cached_index = int(low - dv.begin()) - 1;
		cached_starts = *(low - 2);
		cached_ends = *(low - 1);
		return s - cached_starts;
	}
}

int Path_Composite::Create(PathCompositePtr& composite){
	composite = PathCompositePtr(new Path_Composite());
	composite->pathlength    = 0;
	composite->cached_starts = 0;
	composite->cached_ends   = 0;
	composite->cached_index  = 0;
	return 0;
}

void Path_Composite::Add(PathPtr geom, bool aggregate) {
	pathlength += geom->PathLength();
	dv.insert(dv.end(),pathlength);
	gv.insert( gv.end(),std::make_pair(geom,aggregate) );
}

int Path_Composite::LengthToS(double length, double& returned_length) {
	return 152;
}

double Path_Composite::PathLength() {
	return pathlength;
}

int Path_Composite::Pos(double s, Frame& returned_position) const {
	s = Lookup(s);
	int exit_code = gv[cached_index].first->Pos(s, returned_position);
	return exit_code;
}

int Path_Composite::Vel(double s,double sd, Twist& returned_velocity) const {
	s = Lookup(s);
	int exit_code = gv[cached_index].first->Vel(s,sd,returned_velocity);
	return exit_code;
}

int Path_Composite::Acc(double s,double sd,double sdd, Twist& returned_acceleration) const {
	s = Lookup(s);
	int exit_code = gv[cached_index].first->Acc(s,sd,sdd, returned_acceleration);
	return exit_code;
}

boost::shared_ptr<Path> Path_Composite::Clone()  {
	PathCompositePtr comp;
	Path_Composite::Create(comp);
	for (unsigned int i = 0; i < dv.size(); ++i) {
		comp->Add(gv[i].first->Clone(), gv[i].second);
	}
	return comp;
}

void Path_Composite::Write(std::ostream& os)  {
	os << "COMPOSITE[ " << std::endl;
	os << "   " << dv.size() << std::endl;
	for (unsigned int i=0;i<dv.size();i++) {
		gv[i].first->Write(os);
	}
	os << "]" << std::endl;
}

int Path_Composite::GetNrOfSegments() {
	return dv.size();
}

boost::shared_ptr<Path> Path_Composite::GetSegment(int i) {
	assert(i>=0);
	assert(i<dv.size());
	return gv[i].first;
}

double Path_Composite::GetLengthToEndOfSegment(int i) {
	assert(i>=0);
	assert(i<dv.size());
	return dv[i];
}

void Path_Composite::GetCurrentSegmentLocation(double s, int& segment_number,
		double& inner_s)
{
	inner_s = Lookup(s);
	segment_number= cached_index;
}

Path_Composite::~Path_Composite() {
	PathVector::iterator it;
	for (it=gv.begin();it!=gv.end();++it) {
		if (it->second)
            (it->first).reset();
	}
}

} // namespace KDL
