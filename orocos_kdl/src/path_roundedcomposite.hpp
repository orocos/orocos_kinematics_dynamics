/***************************************************************************
  tag: Erwin Aertbelien  Mon Jan 10 16:38:38 CET 2005  path_roundedcomposite.h

                        path_roundedcomposite.h -  description
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
 *		$Id: path_roundedcomposite.h,v 1.1.1.1.2.3 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/

#ifndef KDL_MOTION_ROUNDEDCOMPOSITE_H
#define KDL_MOTION_ROUNDEDCOMPOSITE_H

#include "path.hpp"
#include "path_composite.hpp"
#include "rotational_interpolation.hpp"
#include <boost/shared_ptr.hpp>

namespace KDL {

/**
 * The specification of a path, composed of way-points with rounded corners.
 *
 * @ingroup Motion
 */
class Path_RoundedComposite : public Path
	{
		typedef boost::shared_ptr<Path_Composite> PathCompositePtr;
		typedef boost::shared_ptr<RotationalInterpolation> RotationalInterpolationPtr;
		typedef boost::shared_ptr<Path> PathPtr;
		typedef boost::shared_ptr<Path_RoundedComposite> PathRoundedCompositePtr;

		/** a Path_Composite is aggregated to hold the rounded trajectory
		 * with circles and lines
		 */
		PathCompositePtr comp;

		double radius;
		double eqradius;
		RotationalInterpolationPtr orient;
		// cached from underlying path objects for generating the rounding :
		Frame F_base_start;
		Frame F_base_via;
		//Frame F_base_end;
		int nrofpoints;

		bool aggregate;

	public:

		/**
		 * @param radius : radius of the rounding circles
		 * @param eqradius : equivalent radius to compare rotations/velocities
		 * @param orient   : method of rotational_interpolation interpolation
		 * @param aggregate : if true, this object will own the _orient pointer, i.e. it will delete the _orient pointer
		 *                    when the destructor of this object is called.
		 *
		 * Exit codes: \n
		 * 		0: OK \n
		 * 		141: Error: Motion planning not feasible: the eq. radius <= 0 \n
		 */
		static int Create(	double radius,
							double eqradius,
							RotationalInterpolationPtr orient,
							PathRoundedCompositePtr& rounded_composite,
							bool aggregate=true);

		/**
		 * Adds a point to this rounded composite, between to adjacent points
		 * a Path_Line will be created, between two lines there will be
		 * rounding with the given radius with a Path_Circle
		 *
		 * @param F_base_point the pose of a new via point.
		 *
		 * Exit codes: \n
		 * 		0: OK \n
		 *		142: Error: Motion planning not feasible: the first segment in a rounding has zero length \n
		 *		143: Error: Motion planning not feasible: the second segment in a rounding has zero length \n
		 *		144: Error: Motion planning not feasible: the angle between the first and the second segment is close to M_PI (meaning that the segments are on top of each other) \n
		 *		145: Error: Motion planning not feasible: the distance needed for the rounding is larger then the first segment \n
		 *		146: Error: Motion planning not feasible: the distance needed for the rounding is larger then the second segment \n
		 *		149: Error: Motion planning circle too small \n
		 *		150: Error: Motion planning circle no plane \n
		 *
		 * @TODO handle the case of error type 5 and 6 by skipping segments, such that the class could be applied
		 *       with points that are very close to each other.
		 */
		int Add(const Frame& F_base_point);

		/**
		 * to be called after the last line is added to finish up
		 * the work
		 */
		void Finish();

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

		/**
		 * virtual constructor, constructing by copying.
		 * In this case it returns the Clone() of the aggregated Path_Composite
		 * because this is all one ever will need.
		 */
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
			return ID_ROUNDED_COMPOSITE;
		}


		virtual ~Path_RoundedComposite();

	private:
		static int Create(  PathCompositePtr comp,
							double radius,
							double eqradius,
							RotationalInterpolationPtr orient,
							bool aggregate,
							int nrofpoints,
							PathRoundedCompositePtr& composite
							);

		Path_RoundedComposite() {};
	};



}


#endif
