/***************************************************************************
  tag: Erwin Aertbelien  Mon Jan 10 16:38:38 CET 2005  path_composite.h

                        path_composite.h -  description
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
 *		$Id: path_composite.h,v 1.1.1.1.2.5 2003/07/24 13:49:16 rwaarsin Exp $
 *		$Name:  $
 ****************************************************************************/

#ifndef KDL_PATHCOMPOSITE_H
#define KDL_PATHCOMPOSITE_H

#include "frames.hpp"
#include "frames_io.hpp"
#include "path.hpp"
#include <vector>
#include <boost/shared_ptr.hpp>


namespace KDL {

	 /**
	  * A Path being the composition of other Path objects.
	  *
	  * For several of its methods, this class needs to lookup the segment corresponding to a value
	  * of the path variable s.  To increase efficiency, this value is cached.
	  *
	  * \TODO Increase the efficiency for caching for the common case of a fine grained monotonously increasing path variable s.
	  *
	  * \TODO For all Path.., VelocityProfile.., Trajectory... check the bounds on the inputs with asserts.
	  *
	  * \TODO explain this routine in the wiki.
	  *
	  * @ingroup Motion
	  */
	 class Path_Composite : public Path
	{
		typedef boost::shared_ptr<Path> PathPtr;
		typedef boost::shared_ptr<Path_Composite> PathCompositePtr;

		typedef std::vector< std::pair<PathPtr,bool> > PathVector;
		typedef std::vector<double> DoubleVector;

		PathVector gv;
		DoubleVector dv;
		double pathlength;

		// lookup mechanism :
		mutable double cached_starts;
		mutable double cached_ends;
		mutable int    cached_index;
		double Lookup(double s) const;

	public:

		static int Create(PathCompositePtr& composite);

		/**
		 * Adds a Path* to this composite
		 */
		void Add(PathPtr geom, bool aggregate=true);

		virtual int LengthToS(double length, double& returned_length);
		/**
		 * Returns the total path length of the trajectory
		 * (has dimension LENGTH)
		 * This is not always a physical length , ie when dealing with rotations
		 * that are dominant.
		 */
		virtual double PathLength();

		/**
		 * Returns the Frame at the current path length s
		 */
		virtual int Pos(double s, Frame& returned_position) const;

		/**
		 * Returns the velocity twist at path length s theta and with
		 * derivative of s == sd
		 */
		virtual int Vel(double s,double sd, Twist& returned_velocity) const;

		/**
		 * Returns the acceleration twist at path length s and with
		 * derivative of s == sd, and 2nd derivative of s == sdd
		 */
		virtual int Acc(double s,double sd,double sdd, Twist& returned_acceleration) const;

		virtual PathPtr Clone();

		/**
		 * Writes one of the derived objects to the stream
		 */
		virtual void Write(std::ostream& os);

		/**
		 * returns the number of underlying segments.
		 */
		virtual int GetNrOfSegments();

		/**
		 * returns a pointer to the underlying Path of the given segment number i.
		 * \param i segment number
		 * \return pointer to the underlying Path
		 * \warning The pointer is still owned by this class and is lifetime depends on the lifetime
		 *          of this class.
		 */
		virtual PathPtr GetSegment(int i);

		/**
		 * gets the length to the end of the given segment.
		 * \param i segment number
		 * \return length to the end of the segment, i.e. the value for s corresponding to the end of
		 *         this segment.
		 */
		virtual double GetLengthToEndOfSegment(int i);

		/**
		 * \param s [INPUT] path length variable for the composite.
		 * \param segment_number [OUTPUT] segments that corresponds to the path length variable s.
		 * \param inner_s [OUTPUT] path length to use within the segment.
		 */
		virtual void GetCurrentSegmentLocation(double s, int& segment_number, double& inner_s);

		/**
		 * gets an identifier indicating the type of this Path object
		 */
		virtual IdentifierType getIdentifier() const {
			return ID_COMPOSITE;
		}

		virtual ~Path_Composite();

	private:
		Path_Composite() {};
	};



}


#endif
