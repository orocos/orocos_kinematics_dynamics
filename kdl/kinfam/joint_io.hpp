#ifndef KDL_JOINT_IO_HPP
#define KDL_JOINT_IO_HPP
/***************************************************************************
                        joint_io.hpp -  description
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
#include <iostream>
#include <fstream>
#include <kdl/kinfam/joint.hpp>

namespace KDL {

/**
 * \brief Writes a Joint to a stream.
 *
 * \param os output stream.
 * \param r  pointer to a joint.
 * \return output stream.
 */
std::ostream& operator << (std::ostream& os,const Joint* r);
std::ostream& operator << (std::ostream& os,const Joint& r);

/**
 * \brief reads from a stream and creates a Joint.
 *
 * \param is input stream
 * \return pointer to the newly created Joint.  The user is responsible for 
 *         deleting this created Joint.
 */
Joint* readJoint(std::istream& is); 

} // end of namespace KDL

#endif
