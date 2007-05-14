#ifndef KDL_KUKA361_HPP
#define KDL_KUKA361_HPP
/***************************************************************************
                        Kuka160.hpp -  description
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


#include <kdl/kinfam/zxxzxz.hpp>
#include <kdl/kinfam/kuka361transmission.hpp>

namespace KDL {

/**
 * \brief constructs a ZXXZXZ object with the parameters of a Kuka361 robot.
 * \ingroup kinfam
 */
  class Kuka361 : public ZXXZXZ {
  public:
    explicit Kuka361(const std::string& name="Kuka361", int jointoffset=0) :	
      ZXXZXZ(name, 
             jointoffset,
             new Kuka361Transmission() )
    {
        double link1 = 1.020;
        double link2 = 0.480;
        double link3 = 0.645;
        double link6 = 0.120;
      this->setLinkLengths(link1,link2,link3,link6);
    };
  };
  
} // end of namespace KDL

#endif
