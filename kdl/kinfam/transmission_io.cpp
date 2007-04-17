/***************************************************************************
                        transmission_io.cpp 
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
#include <kdl/error_stack.h>
#include <kdl/error.h>
#include <kdl/kinfam/transmission_io.hpp>
#include <kdl/kinfam/unittransmission.hpp>
#include <kdl/kinfam/lineartransmission.hpp>
#include <kdl/kinfam/kuka361transmission.hpp>
#include <memory>

namespace KDL {
/**
 * \brief reads the input stream and creates a Transmission object
 *
 * \param is input stream.
 * \return a pointer to the created Transmission object.  The user is responsible for 
 *        deleting this object.
 */
Transmission* readTransmission(std::istream& is) {
	IOTrace("creating transmission from stream input");
	char storage[20];
	EatWord(is,"[]",storage,sizeof storage);
	if (strcmp(storage,"UNITTRANSMISSION")==0) {
		int nrofjoints;
		Eat(is,"["); 
        Eat(is,"NROFJOINTS"); Eat(is,"["); is >> nrofjoints; Eat(is,"]");
		Eat(is,"]");
		IOTracePop();
		return new UnitTransmission(nrofjoints);
	}
	if (strcmp(storage,"LINEARTRANSMISSION")==0) {
		int nrofjoints;
		Eat(is,"[");	
		Eat(is,"NROFJOINTS");Eat(is,"[");is >> nrofjoints;Eat(is,"]");
		std::vector<double> scale(nrofjoints);
		std::vector<double> offset(nrofjoints);
        std::auto_ptr<LinearTransmission> tr(new LinearTransmission(nrofjoints,scale,offset));
		for (int i=0;i<nrofjoints;++i) {
			double scaleval;
			double offsetval;
			Eat(is,"[");
		    Eat(is,"SCALE");Eat(is,"[");is >> scaleval;Eat(is,"]");
		    Eat(is,"OFFSET");Eat(is,"[");is >> offsetval;Eat(is,"]");
			Eat(is,"]");
            tr->setTransmission(i,scaleval,offsetval);
		}
		Eat(is,"]");
		IOTracePop();
		return tr.release();
	}
    if(strcmp(storage,"KUKA361TRANSMISSION")==0) {
        Eat(is,"[");
        Transmission* trans = readTransmission(is);
        std::auto_ptr<Kuka361Transmission> tr(new Kuka361Transmission(trans));
        Eat(is,"]");
        IOTracePop();
        return tr.release();
    }
    
    throw Error_IO("Unknown Transmission");	
}

/**
 * \brief writes a Transmission oject to an output stream.
 * 
 * \param os output stream
 * \param trans the transmission object that has to be written.
 *
 * This function should know about all implementations of Transmission.
 */
std::ostream& operator << (std::ostream& os, const Transmission* trans) {
	const UnitTransmission* trans_ut = dynamic_cast<const UnitTransmission*>(trans);
	if (trans_ut!=0) {
		os<<"UNITTRANSMISSION["<< std::endl;
		os<<"    NROFJOINTS["<< trans_ut->nrofjoints << "]"   << std::endl;
		os<< "]"<< std::endl;
		return os;
	}
	const LinearTransmission* trans_lin = dynamic_cast<const LinearTransmission*>(trans);
	if (trans_lin!=0) {
		os<<"LINEARTRANSMISSION["<< std::endl;
		os<<"  NROFJOINTS[" << trans_lin->nrofjoints  << "]"<<std::endl;
		for (int i=0;i<trans_lin->nrofjoints;++i) {
			os<<"  [SCALE["<< trans_lin->scale[i] << "] OFFSET["<< trans_lin->offset[i] << "]]"<<std::endl;
		}
		os<<"]";
        return os;
    }
    const Kuka361Transmission* trans_kuka361 = dynamic_cast<const Kuka361Transmission*>(trans);
    if(trans_kuka361!=0){
        os<<"KUKA361TRANSMISSION["<<std::endl;
        os<<trans_kuka361->getTransmission();
        os<<"]";
        return os;
    }
    // default handling :
	os << "UNKNOWN_TRANSMISSION";
	return os;
}


} // end of namespace KDL
