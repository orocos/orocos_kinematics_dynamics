/***************************************************************************
  tag: Peter Soetens  Mon May 10 19:10:36 CEST 2004  plane.cxx 

                        plane.cxx -  description
                           -------------------
    begin                : Mon May 10 2004
    copyright            : (C) 2004 Peter Soetens
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

#include <kdl/plane.h>

namespace KDL 
{

    Plane::Plane()
        : n(Vector(0,0,1)), d(0)
    {
    }

    Plane::Plane(double a, double b, double c, double d) : n(Vector(a,b,c)), d(d) 
    {
        double length=n.Norm();
        d/=length;
        n.Normalize();
    }

    Plane::Plane(const Vector &v1, const Vector &v2, const Vector &v3) 
    {
        Vector v_1(v2-v1);
        Vector v_2(v2-v3);
        n = v_2 * v_1;
        n.Normalize();
        d=-dot(v1, n);
    }

    Plane::~Plane() 
    {
    }

    void Plane::flip() 
    {
        n.x(-n.x());
        n.y(-n.y());
        n.z(-n.z());
        d=-d;
    }

    Vector Plane::project(const Vector& v) const
    {
        return v-n*dot(v,n);
    }

    Vector Plane::normal() const
    {
        return n;
    }

    void
    Plane::reset(const Vector &v1, const Vector &v2, const Vector &v3) 
    {
        n = v2-v3 * v2-v1;
        n.Normalize();
        d = -dot(v1, n);
    }
}
