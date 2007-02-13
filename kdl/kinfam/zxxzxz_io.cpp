// Copyright (C) 2006 Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//  

#include <kdl/kinfam/transmission_io.hpp>
#include <kdl/kinfam/zxxzxz_io.hpp>
#include <kdl/error_stack.h>
#include <kdl/error.h>
#include <memory>

using namespace std;

namespace KDL
{
  
  ZXXZXZ* readZXXZXZ(std::istream& is,bool keyword)
  {
    if (keyword) {
        Eat(is,"ZXXZXZ");
    }
    Eat(is,'[');
    char name[60];
    int nrofjoints;
    int offset;
    double l1,l2,l3,l6;
    Eat(is,"NAME");Eat(is,'[');EatWord(is,"]",name,60);Eat(is,']');
    Eat(is,"NROFJOINTS");Eat(is,'[');is >> nrofjoints;Eat(is,']');
    Eat(is,"OFFSET");Eat(is,'[');is >> offset;Eat(is,']');
    Transmission* trans = readTransmission(is);
    auto_ptr<ZXXZXZ> KF ( new ZXXZXZ(name, offset,trans) );
    Eat(is,"L1");Eat(is,'[');is>>l1;Eat(is,']');
    Eat(is,"L2");Eat(is,'[');is>>l2;Eat(is,']');
    Eat(is,"L3");Eat(is,'[');is>>l3;Eat(is,']');
    Eat(is,"L6");Eat(is,'[');is>>l6;Eat(is,']');
    Eat(is,']');
    KF->setLinkLengths(l1,l2,l3,l6);
    return KF.release();
  }
    
  std::ostream& operator << (std::ostream& os, const ZXXZXZ* chain)
  {
    os << "ZXXZXZ[" << endl;
    os << "   NAME[" << chain->getName() << "]" << endl;
    os << "   NROFJOINTS[" << chain->nrOfJoints() << "]" << endl;
    os << "   OFFSET[" << chain->offset() << "]" << endl;
    os << chain->transmission << endl;
    os << "L1["<<chain->getLinkLength(1)<<"]"<<endl;
    os << "L2["<<chain->getLinkLength(2)<<"]"<<endl;
    os << "L3["<<chain->getLinkLength(3)<<"]"<<endl;
    os << "L6["<<chain->getLinkLength(6)<<"]"<<endl;
    os<<"]"<<endl;
    return os;
  }
  
}//namespace

