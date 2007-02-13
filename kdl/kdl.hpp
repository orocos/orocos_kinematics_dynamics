#ifndef KDL_KDL_H
#define KDL_KDL_H

/***************************************************************************
                        kdl.h -  description
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Erwin Aertbelien
    email                : firstname.lastname@mech.kuleuven.ac.be

 History (only major changes)( AUTHOR-Description ) :
 
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


/**
 * \file kdl.hpp This file contains general definitions for the KDL-library.
 */
#include <assert.h>
#include <vector>
/**
 * \todo
 *   decide whether to use a KDL_ASSERT macro we can override to do 
 *   something else (e.g. in orocos : throwing an exception).
 */
#define KDL_ASSERT(x) assert(x)

/**
 * Joint positions, velocities,... are stored in a JointVector.
 */
typedef std::vector<double> JointVector;

#endif

