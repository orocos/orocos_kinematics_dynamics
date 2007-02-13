#ifndef KDL_TRANSMISSION_IO_HPP
#define KDL_TRANSMISSION_IO_HPP

/***************************************************************************
                        transmission_io.hpp 
                       ----------------------
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
#include <fstream>
#include <kdl/kinfam/transmission.hpp>

namespace KDL {

/**
 * \brief reads the input stream and creates a Transmission object
 *
 * \param is input stream.
 * \return a pointer to the created Transmission object.  The user is responsible for 
 *        deleting this object.
 */
 Transmission* readTransmission(std::istream& is);

/**
 * \brief writes a Transmission oject to an output stream.
 * 
 * \param os output stream
 * \param trans the transmission object that has to be written.
 */
 std::ostream& operator << (std::ostream& os, const Transmission* trans);

} // end of namespace KDL

#endif


