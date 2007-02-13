/***************************************************************************
                        serialchain_io.cpp -  description
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

#include <kdl/kinfam/serialchain_io.hpp>
#include <kdl/kinfam/transmission_io.hpp>
#include <kdl/kinfam/joint_io.hpp>
#include <kdl/error_stack.h>
#include <kdl/error.h>
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <memory>

using namespace std;
namespace KDL { 

  ostream& operator << (ostream& os, const SerialChain* chain) {
    os << "SERIALCHAIN[" << endl;
    os << "   NAME[" << chain->getName() << "]" << endl;
    os << "   NROFJOINTS[" << chain->nrOfJoints() << "]" << endl;
    os << "   OFFSET[" << chain->offset() << "]" << endl;
	os << chain->transmission << endl;
    for (int j=0;j<chain->nrOfJoints();j++) {
      os << chain->getJoint(j) << endl;
    }
    os << "   ENDEFFECTOR[" << chain->getLastJointToEE() << "]" << endl;
    os << "]" << endl;

    return os;
  }
  ostream& operator << (ostream& os, const SerialChain& chain) {
    os << "SERIALCHAIN[" << endl;
    os << "   NAME[" << chain.getName() << "]" << endl;
    os << "   NROFJOINTS[" << chain.nrOfJoints() << "]" << endl;
    os << "   OFFSET[" << chain.offset() << "]" << endl;
	os << chain.transmission << endl;
    for (int j=0;j<chain.nrOfJoints();j++) {
      os << chain.getJoint(j) << endl;
    }
    os << "   ENDEFFECTOR[" << chain.getLastJointToEE() << "]" << endl;
    os << "]" << endl;
    
    return os;
  }

  SerialChain* readSerialChain(std::istream& is,bool keyword) {
    if (keyword) {
        Eat(is,"SERIALCHAIN");
    }
    IOTrace("creating SerialChain from stream input");
    Eat(is,'[');
    char name[60];
    int nrofjoints;
    int offset;
    Eat(is,"NAME");Eat(is,'[');EatWord(is,"]",name,60);Eat(is,']');
    Eat(is,"NROFJOINTS");Eat(is,'[');is >> nrofjoints;Eat(is,']');
    Eat(is,"OFFSET");Eat(is,'[');is >> offset;Eat(is,']');
    Transmission* trans = readTransmission(is);
    auto_ptr<SerialChain> KF ( new SerialChain(name,nrofjoints,offset,trans) );
    for (int i=0;i<nrofjoints;i++) {
      Joint* jnt = readJoint(is);	
      KF->addJoint(jnt);	
    }
    Frame F;
    Eat(is,"ENDEFFECTOR");Eat(is,'['); is >> F; Eat(is,']');
    KF->setLastJointToEE(F);
    Eat(is,']');
    IOTracePop();
    return KF.release();
  }


} // end of namespace KDL
