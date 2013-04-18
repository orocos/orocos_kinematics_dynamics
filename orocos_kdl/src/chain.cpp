// 	Copyright	 (C)  2012  Wouter Bancken <wouter dot bancken at gmail dot com>
//   			 (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

// Version: 1.0
// Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// URL: http://www.orocos.org/kdl

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include "chain.hpp"

namespace KDL {
    using namespace std;

    Chain::Chain():
        segments(0),
        nrOfJoints(0),
        nrOfSegments(0)
    {
    }

    Chain::Chain(const Chain& in):nrOfJoints(0),
                                  nrOfSegments(0)
    {
        for(unsigned int i=0;i<in.getNrOfSegments();i++){
        	Segment segm;
        	in.getSegment(i,segm);
            this->addSegment(segm);
        }
    }

    Chain& Chain::operator=(const Chain& arg)
    {
        nrOfJoints=0;
        nrOfSegments=0;
        segments.resize(0);
        for(unsigned int i=0;i<arg.nrOfSegments;i++){
        	Segment segm;
        	arg.getSegment(i,segm);
            addSegment(segm);
        }
        return *this;
    }

    bool Chain::addSegment(const Segment& segment)
    {
    	if (segment.getName() != "NoName") {
    		for (int i = 0; i < segments.size(); i++) {
    			if (segments[i].getName() == segment.getName())
    				return false;
    		}
    	}
    	segments.push_back(segment);
    	nrOfSegments++;
    	if (segment.getJoint().getType() != Joint::None)
    		nrOfJoints++;
    	return true;
    }

    bool Chain::addChain(const Chain& chain)
    {
    	Chain tmp_copy = *this;
    	for (unsigned int i = 0; i < chain.getNrOfSegments(); i++){
    		Segment segm;
    		chain.getSegment(i,segm);
			bool exit_code = this->addSegment(segm);
			if(exit_code == false){
				*this = tmp_copy;
				return false;
			}
    	}
    	return true;
    }

    const Segment& Chain::getSegment(unsigned int nr)const
    {
        return segments[nr];
    }

    bool Chain::getSegment(unsigned int nr, Segment& returned_segment) const
    {
    	if(nr < 0 || nr >= segments.size()){
    		return false;
    	}
    	returned_segment = segments[nr];
    	return true;
    }

    bool Chain::getSegment(const std::string &segment_name, Segment& returned_segment) const
    {
    	for(int i = 0; i < segments.size(); i++){
    		if(segments[i].getName() == segment_name){
    			returned_segment = segments[i];
    			return true;
    		}
    	}
    	return false;
    }

    const Segment & Chain::getRootSegment() const
    {
        return getSegment(0);
    }

    const std::vector<Segment> & Chain::getSegments() const
    {
    	return segments;
    }

    bool Chain::getLeafSegment(Segment& returned_segment) const{
    	returned_segment = segments[segments.size()-1];
    	return true;
    }

    bool Chain::getChain(const std::string& chain_root, const std::string& chain_tip, Chain& chain)const
    {
    	chain = Chain();

    	//When the chain_root is after the chain_tip in the chain, the segments are pushed_back to this vector first.
    	//At the end, the segments are placed in the new chain in the right order.
    	vector<Segment> vect;

    	enum Status {none_found, root_found, tip_found};

    	Status stat = none_found;
    	bool exit_value;

    	//Go through the list
    	for(int i = 0; i < segments.size();i++){

    		if(stat == none_found){
    			if(segments[i].getName() == chain_root){
    				stat = root_found;
    				exit_value = chain.addSegment(segments[i]);
        			if(!exit_value){
        		    	chain = Chain();
        				return false;
        			}
    				if(chain_root == chain_tip){ //Case start == end
    					return true;
    				}
    			}
    			else if(segments[i].getName() == chain_tip){
    				stat = tip_found;
    				if(chain_root == chain_tip){ //Case start == end
    					exit_value = chain.addSegment(segments[i]);
    	    			if(!exit_value){
    	    		    	chain = Chain();
    	    				return false;
    	    			}
    					return true;
    				}
    				vect.push_back(segments[i]);
    			}
    		}
    		else if(stat == root_found){
    			if(segments[i].getName() == chain_tip){
    				exit_value = chain.addSegment(segments[i]);
        			if(!exit_value){
        		    	chain = Chain();
        				return false;
        			}
    				return true;
    			}
    			else {
    				if(i == (segments.size()-1)){ //Reached end without finding tip
    					chain = Chain();
    					return false;
    				}
    				exit_value = chain.addSegment(segments[i]);
        			if(!exit_value){
        		    	chain = Chain();
        				return false;
        			}
    			}
    		}
    		else { //tip_found
    			if(segments[i].getName() == chain_root){
    				vect.push_back(segments[i]);
    				for(int j = vect.size()-1; j >= 0; j--){
    					exit_value = chain.addSegment(vect[j]);
    	    			if(!exit_value){
    	    		    	chain = Chain();
    	    				return false;
    	    			}
    				}
    				return true;
    			}
    			else {
    				if(i == (segments.size()-1)){ //Reached end without finding root
       					chain = Chain();
    					return false;
    				}
    				vect.push_back(segments[i]);
    			}
    		}
    	}
    	return false;
    }

    bool Chain::getChain(unsigned int nr_root, unsigned int nr_tip, Chain& chain)const
    {
    	chain = Chain();

    	if( nr_root < 0 || nr_root >= segments.size())
    		return false;
    	if( nr_tip < 0 || nr_tip >= segments.size())
    		return false;

    	bool exit_value;

    	if(nr_root < nr_tip){
    		for(int i = nr_root; i <= nr_tip; i++){
    			exit_value = chain.addSegment(segments[i]);
    			if(!exit_value){
    		    	chain = Chain();
    				return false;
    			}
    		}
    	}
    	else {
    		for(int i = nr_root; i >= nr_tip;i--){
    			exit_value = chain.addSegment(segments[i]);
    			if(!exit_value){
    		    	chain = Chain();
    				return false;
    			}
    		}
    	}
		return true;
    }

    bool Chain::copy(unsigned int nr,Chain& returned_chain) const
    {
    	bool exit_code;
    	returned_chain = Chain();
    	if(nr < 0 || nr > getNrOfSegments())
    		return false;
        for(unsigned int i=0;i<nr;i++){
        	Segment segm;
        	exit_code = getSegment(i,segm);
        	if(!exit_code){
        		returned_chain = Chain();
        		return false;
        	}
            exit_code = returned_chain.addSegment(segm);
        	if(!exit_code){
        		returned_chain = Chain();
        		return false;
        	}
        }
    	return true;
    }

    bool Chain::copy(const std::string& segment, Chain& returned_chain) const
    {
    	bool exit_code;
    	returned_chain = Chain();
    	for(unsigned int i=0;i<getNrOfSegments() && segments[i].getName() != segment;i++)
    	{
    	    Segment segm;
    	    exit_code = getSegment(i,segm);
    	    if(!exit_code)
    	    {
    	    	returned_chain = Chain();
    	        return false;
    	    }
    	    exit_code = returned_chain.addSegment(segm);
    	    if(!exit_code)
    	    {
    	        returned_chain = Chain();
    	        return false;
    	   	}
    	}
  	    return true;
    }

    Chain::~Chain()
    {
    }
}
