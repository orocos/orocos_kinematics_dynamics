/***************************************************************************
                        joint_io.cpp -  description
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

#include <kdl/error_stack.h>
#include <kdl/error.h>
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <kdl/kinfam/joint_io.hpp>
#include <kdl/kinfam/serialchain.hpp>
#include <memory>

using namespace std;
namespace KDL {

std::ostream& operator << (std::ostream& os,const Joint& r) {
	switch (r.getType() ) {
		case Joint::TransX:
			os << "TRANSX[";
			break;
		case Joint::TransY:
			os << "TRANSY[";
			break;
		case Joint::TransZ:
			os << "TRANSZ[";
			break;
		case Joint::RotX:
			os << "ROTX[";
			break;
		case Joint::RotY:
			os << "ROTY[";
			break;
		case Joint::RotZ:
			os << "ROTZ[";
			break;
		default:
			os << "UNKNOWN[";	
	}
	Frame F;
	os << r.frame_before_joint(); 
	os << "]";
	return os;
}
std::ostream& operator << (std::ostream& os,const Joint* r) {
	switch (r->getType() ) {
		case Joint::TransX:
			os << "TRANSX[";
			break;
		case Joint::TransY:
			os << "TRANSY[";
			break;
		case Joint::TransZ:
			os << "TRANSZ[";
			break;
		case Joint::RotX:
			os << "ROTX[";
			break;
		case Joint::RotY:
			os << "ROTY[";
			break;
		case Joint::RotZ:
			os << "ROTZ[";
			break;
		default:
			os << "UNKNOWN[";	
	}
	Frame F;
	os << r->frame_before_joint(); 
	os << "]";
	return os;
}

Joint* readJoint(std::istream& is) {
	Joint* jnt;
	IOTrace("creating Joint from stream input");
	char storage[10];
	EatWord(is,"[]",storage,10);
	if (strcmp(storage,"TRANSX")==0) {
		Eat(is,'[');
		Frame F;
		is >> F;	
		jnt = new JointTransX(F);
		Eat(is,']');
		IOTracePop();
		return jnt;
	}
	if (strcmp(storage,"TRANSY")==0) {
		Eat(is,'[');
		Frame F;
		is >> F;	
		jnt = new JointTransY(F);
		Eat(is,']');
		IOTracePop();
		return jnt;
	}
	if (strcmp(storage,"TRANSZ")==0) {
		Eat(is,'[');
		Frame F;
		is >> F;	
		jnt = new JointTransZ(F);
		Eat(is,']');
		IOTracePop();
		return jnt;
	}
	if (strcmp(storage,"ROTX")==0) {
		Eat(is,'[');
		Frame F;
		is >> F;	
		jnt = new JointRotX(F);
		Eat(is,']');
		IOTracePop();
		return jnt;
	}
	if (strcmp(storage,"ROTY")==0) {
		Eat(is,'[');
		Frame F;
		is >> F;	
		jnt = new JointRotY(F);
		Eat(is,']');
		IOTracePop();
		return jnt;
	}
	if (strcmp(storage,"ROTZ")==0) {
		Eat(is,'[');
		Frame F;
		is >> F;	
		jnt = new JointRotZ(F);
		Eat(is,']');
		IOTracePop();
		return jnt;
	}
	throw Error_IO("Joint expected");
}

std::istream& operator >> (std::istream& is, JointRotZ& joint) {
	IOTrace("creating Joint from stream input");
	char storage[10];
	EatWord(is,"[]",storage,10);
	if (strcmp(storage,"ROTZ")==0) {
		Eat(is,'[');
		Frame F;
		is >> F;	
		joint = JointRotZ(F);
		Eat(is,']');
		IOTracePop();
		return is;
	}
	throw Error_IO("Joint expected");
}

} // end of namespace KDL
