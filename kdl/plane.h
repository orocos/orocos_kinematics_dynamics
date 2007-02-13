/***************************************************************************
  tag: Peter Soetens  Fri Feb 11 15:59:12 CET 2005  plane.h 

                        plane.h -  description
                           -------------------
    begin                : Fri February 11 2005
    copyright            : (C) 2005 Peter Soetens
    email                : peter.soetens@mech.kuleuven.ac.be
 
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
 
 
#ifndef KDL_PLANE_H
#define KDL_PLANE_H

#include <kdl/frames.hpp>

namespace KDL 
{
    /**
     * This class represents a plane in cartesian space.
     */
    class Plane 
    {
        /**
         * The norm of the plane.
         */
        Vector n;
        /**
         * The distance on the norm of the plane from the origin.
         */
        double d;
    public:
        /**
         * Create a plane defined by three points.
         */
        Plane(const Vector &v1, const Vector &v2, const Vector &v3);
        /**
         * Create a plane equal to the XY plane.
         */
        Plane();

        /**
         * Create a plane using the homogenous numbers.
         */
        Plane(double a, double b, double c, double d);

        /**
         * Destructor.
         */
        ~Plane();
        /**
         * Flip the plane's norm, but not its position. (Norm and distance change
         * their sign)
         */
        void flip();
        /**
         * Project a Vector on this plane.
         */
        Vector project(const Vector& v) const;
        /**
         * The normal of this Plane.
         */
        Vector normal() const;
        /**
         * Redefine the plane.
         */
        void reset( const Vector &v1, const Vector &v2, const Vector &v3 );
    };

}

#endif
