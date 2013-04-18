/***************************************************************************
  tag: Erwin Aertbelien  Mon Jan 10 16:38:38 CET 2005  path_cyclic_closed.h

                        path_cyclic_closed.h -  description
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
 *		ORO_Geometry V2
 *
 *	\par History
 *		- $log$
 *
 *	\par Release
 *		$Id: path_cyclic_closed.h,v 1.1.1.1.2.3 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/

#ifndef KDL_MOTION_PATH_CYCLIC_CLOSED_H
#define KDL_MOTION_PATH_CYCLIC_CLOSED_H

#include "frames.hpp"
#include "frames_io.hpp"
#include "path.hpp"
#include <vector>
#include <boost/shared_ptr.hpp>

namespace KDL {

	 /**
	  * A Path representing a closed circular movement,
	  * which is traversed a number of times.
	  * @ingroup Motion
	  */
	 class Path_Cyclic_Closed : public Path
	{
		typedef boost::shared_ptr<Path> PathPtr;
		typedef boost::shared_ptr<Path_Cyclic_Closed> PathCyclicClosedPtr;

		int times;
		PathPtr geom;
		bool aggregate;

	public:
		static int Create(	PathPtr _geom,
							int _times,
							PathCyclicClosedPtr& cyclic_closed,
							bool _aggregate=true);
		virtual int LengthToS(double length, double& returned_length);
		virtual double PathLength();
		virtual int Pos(double s, Frame& returned_position) const;
		virtual int Vel(double s,double sd, Twist& returned_velocity) const;
		virtual int Acc(double s,double sd,double sdd, Twist& returned_acceleration) const;

		virtual void Write(std::ostream& os);
		virtual PathPtr Clone();
		/**
		 * gets an identifier indicating the type of this Path object
		 */
		virtual IdentifierType getIdentifier() const {
			return ID_CYCLIC_CLOSED;
		}
		virtual ~Path_Cyclic_Closed();

	private:
		Path_Cyclic_Closed() {};
	};
}


#endif
