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

#include <kdl/kinfam/kinematicfamily_io.hpp>
#include <kdl/kinfam/serialchain_io.hpp>
#include <kdl/kinfam/zxxzxz_io.hpp>
#include <kdl/kinfam/transmission_io.hpp>
#include <kdl/error_stack.h>
#include <kdl/error.h>
#include <memory>

namespace KDL 
{

  void readKinematicFamilies(std::istream& is,std::vector<KinematicFamily*>& chains) {
    IOTrace("reading KinematicFamily vector");
    char storage[20];
    EatWord(is,"[]",storage,20);
    if (strcmp(storage,"NROFCHAINS")==0) {
        Eat(is,'[');
        int nrofchains;
        is >> nrofchains;
        Eat(is,']');
        chains.resize(nrofchains);
        for(int i = 0 ; i<nrofchains;i++)
        chains[i] = readKinematicFamily(is);
    } else {
        throw Error_IO("NROFCHAINS expected");
    }
    IOTracePop();
  }
  
  
  KinematicFamily* readKinematicFamily(std::istream& is) {
    char storage[20];
    IOTrace("creating KinematicFamily from stream input");
    EatWord(is,"[]",storage,20);
    if (strcmp(storage,"SERIALCHAIN")==0) {
        IOTracePop();
        return readSerialChain(is,false);
    } else if (strcmp(storage,"ZXXZXZ")==0) {
        IOTracePop();
        return readZXXZXZ(is,false);
    } else {
        throw Error_IO("SERIALCHAIN or ZXXZXZ expected");
    }
  }
  
  std::ostream& operator << (std::ostream& os, const std::vector<KinematicFamily*>& chains)
  {
    os << "NROFCHAINS[" << chains.size() << "]" << std::endl;
    for(unsigned int i = 0;i<chains.size();i++) {
        os << chains[i];
    }
    return os;
  }
  
  std::ostream& operator << (std::ostream& os, const KinematicFamily* chain) {
    if (chain->getTypeName()=="serialchain") {
        os << ((SerialChain*)chain);
    } else if (chain->getTypeName()=="zxxzxz") {
        os << ((ZXXZXZ*)chain);
    } else {
      Error_IO("unknown type!");
    }
    return os;
  }
  
}//namespace


  
  
