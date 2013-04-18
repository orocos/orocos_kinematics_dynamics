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

#include "tree.hpp"
#include <sstream>
#include <algorithm>

namespace KDL {
using namespace std;

Tree::Tree(const std::string& _root_name) :
  nrOfSegments(0), nrOfJoints(0),root_name(_root_name) {
    segments.insert(make_pair(root_name, TreeElement::Root(root_name)));
}

Tree::Tree(const Tree& in)
{
    segments.clear();
    leafSegments.clear();
    nrOfSegments = 0;
    nrOfJoints = 0;
    root_name = in.root_name;

    segments.insert(make_pair(root_name, TreeElement::Root(root_name)));
    this->addTree(in, root_name);
}

Tree& Tree::operator=(const Tree& in)
{
    segments.clear();
    leafSegments.clear();
    nrOfSegments = 0;
    nrOfJoints = 0;
    root_name = in.root_name;

    segments.insert(make_pair(in.root_name, TreeElement::Root(root_name)));
    this->addTree(in, root_name);
    return *this;
}

bool Tree::addSegment(const Segment& segment, const std::string& hook_name)
{
    SegmentMap::iterator parent = segments.find(hook_name);
    //check if parent exists
    if (parent == segments.end())
        return false;
    pair<SegmentMap::iterator, bool> retval;
    //insert new element
    unsigned int q_nr = segment.getJoint().getType() != Joint::None ? nrOfJoints : 0;

    pair<std::string,TreeElement> paar = make_pair(segment.getName(), TreeElement(segment, parent, q_nr));
    retval = segments.insert(paar);
    //check if insertion succeeded
    if (!retval.second)
        return false;
    //add iterator to new element in parents children list
    parent->second.children.push_back(retval.first);
    //increase number of segments
    nrOfSegments++;
    //increase number of joints
    if (segment.getJoint().getType() != Joint::None)
        nrOfJoints++;

    //Update leafslist
    leafSegments.erase((*parent).first); //Remove parent if it is in the map.
    leafSegments.insert(paar); //Add the new segment (a new pair is created so it must be a leaf).

    return true;
}

bool Tree::addChain(const Chain& chain, const std::string& hook_name)
{
    string parent_name = hook_name;
    for (unsigned int i = 0; i < chain.getNrOfSegments(); i++) {
    	Segment segm;
    	chain.getSegment(i,segm);
        if (this->addSegment(segm, parent_name))
            parent_name = segm.getName();
        else
            return false;
    }
    return true;
}

bool Tree::addTree(const Tree& tree, const std::string& hook_name)
{
	SegmentMap::const_iterator it;
	bool exit_code = tree.getRootSegment(it);
	if(exit_code == false){
		return false;
	}
    return this->addTreeRecursive(it, hook_name);
}

bool Tree::addTreeRecursive(SegmentMap::const_iterator root, const std::string& hook_name)
{
    //get iterator for root-segment
    SegmentMap::const_iterator child;
    //try to add all of root's children
    for (unsigned int i = 0; i < root->second.children.size(); i++) {
        child = root->second.children[i];
        //Try to add the child
        if (this->addSegment(child->second.segment, hook_name)) {
            //if child is added, add all the child's children
            if (!(this->addTreeRecursive(child, child->first)))
                //if it didn't work, return false
                return false;
        } else
            //If the child could not be added, return false
            return false;
    }
    return true;
}
    
SegmentMap::const_iterator Tree::getSegment(const std::string& segment_name) const
{
    return segments.find(segment_name);
};

bool Tree::getSegment(const std::string& segment_name, SegmentMap::const_iterator& returned_it) const
{
    returned_it = segments.find(segment_name);
    if(returned_it == segments.end())
    	return false;
    else
    	return true;
};

SegmentMap::const_iterator Tree::getRootSegment() const
{
  return segments.find(root_name);
};

const SegmentMap& Tree::getSegments() const
{
    return segments;
}

bool Tree::getChain(const std::string& chain_root, const std::string& chain_tip, Chain& chain) const
{
	// clear chain
	chain = Chain();

	// walk down from chain_root and chain_tip to the root of the tree
	vector<SegmentMap::key_type> parents_chain_root, parents_chain_tip;

	SegmentMap::const_iterator s;
	getSegment(chain_root, s);
	for (; s != segments.end(); s = s->second.parent) {
		parents_chain_root.push_back(s->first);
		if (s->first == root_name)
			break;
	}

	if (parents_chain_root.empty() || parents_chain_root.back() != root_name)
		return false;

	getSegment(chain_tip, s);
	for (; s != segments.end(); s = s->second.parent) {
		parents_chain_tip.push_back(s->first);
		if (s->first == root_name)
			break;
	}

	if (parents_chain_tip.empty() || parents_chain_tip.back() != root_name)
		return false;

	// remove common part of segment lists
	SegmentMap::key_type last_segment = root_name;
	while (!parents_chain_root.empty() && !parents_chain_tip.empty()
			&& parents_chain_root.back() == parents_chain_tip.back()) {
		last_segment = parents_chain_root.back();
		parents_chain_root.pop_back();
		parents_chain_tip.pop_back();
	}
	parents_chain_root.push_back(last_segment);

	// add the segments from the root to the common frame
	for (unsigned int s = 0; s < parents_chain_root.size() - 1; s++) {
		SegmentMap::const_iterator arg_segm;
		getSegment(parents_chain_root[s], arg_segm);
		Segment seg = arg_segm->second.segment;
		Frame f_tip = seg.pose(0.0).Inverse();
		Joint jnt = seg.getJoint();
		if (jnt.getType() == Joint::RotX || jnt.getType() == Joint::RotY
				|| jnt.getType() == Joint::RotZ
				|| jnt.getType() == Joint::RotAxis)
			jnt = Joint(jnt.getName(), f_tip * jnt.JointOrigin(),
					f_tip.M * (-jnt.JointAxis()), Joint::RotAxis);
		else if (jnt.getType() == Joint::TransX
				|| jnt.getType() == Joint::TransY
				|| jnt.getType() == Joint::TransZ
				|| jnt.getType() == Joint::TransAxis)
			jnt = Joint(jnt.getName(), f_tip * jnt.JointOrigin(),
					f_tip.M * (-jnt.JointAxis()), Joint::TransAxis);

		getSegment(parents_chain_root[s + 1], arg_segm);
		chain.addSegment(
				Segment(arg_segm->second.segment.getName(), jnt, f_tip,
						arg_segm->second.segment.getInertia()));
	}

	// add the segments from the common frame to the tip frame
	for (int s = parents_chain_tip.size() - 1; s > -1; s--) {
		SegmentMap::const_iterator seg;
		getSegment(parents_chain_tip[s], seg);
		chain.addSegment(seg->second.segment);
	}
	return true;
}

bool Tree::getChain(const std::string& chain_root,const std::string& chain_tip,Tree& tree, const std::string& rootname) const
{
 	// clear tree
   	tree = Tree(rootname);
   	std::string hook = rootname;

   	// walk down from chain_root and chain_tip to the root of the tree
   	vector<SegmentMap::key_type> parents_chain_root, parents_chain_tip;

   	SegmentMap::const_iterator s;
   	getSegment(chain_root, s);
   	for (; s != segments.end(); s = s->second.parent) {
   		parents_chain_root.push_back(s->first);
  		if (s->first == root_name)
   			break;
   	}

   	if (parents_chain_root.empty() || parents_chain_root.back() != root_name)
   		return false;

   	getSegment(chain_tip, s);
   	for (; s != segments.end(); s = s->second.parent) {
   		parents_chain_tip.push_back(s->first);
   		if (s->first == root_name)
   			break;
   	}

   	if (parents_chain_tip.empty() || parents_chain_tip.back() != root_name)
   		return false;

   	// remove common part of segment lists
    SegmentMap::key_type last_segment = root_name;
    while (!parents_chain_root.empty() && !parents_chain_tip.empty()
    		&& parents_chain_root.back() == parents_chain_tip.back()) {
    	last_segment = parents_chain_root.back();
    	parents_chain_root.pop_back();
    	parents_chain_tip.pop_back();
    }
    parents_chain_root.push_back(last_segment);

    // add the segments from the root to the common frame
    for (unsigned int s = 0; s < parents_chain_root.size() - 1; s++) {
    	SegmentMap::const_iterator arg_segm;
    	getSegment(parents_chain_root[s], arg_segm);
    	Segment seg = arg_segm->second.segment;
    	Frame f_tip = seg.pose(0.0).Inverse();
    	Joint jnt = seg.getJoint();
    	if (jnt.getType() == Joint::RotX || jnt.getType() == Joint::RotY
    			|| jnt.getType() == Joint::RotZ
    			|| jnt.getType() == Joint::RotAxis)
    		jnt = Joint(jnt.getName(), f_tip * jnt.JointOrigin(),
    				f_tip.M * (-jnt.JointAxis()), Joint::RotAxis);
    	else if (jnt.getType() == Joint::TransX
    			|| jnt.getType() == Joint::TransY
    			|| jnt.getType() == Joint::TransZ
    			|| jnt.getType() == Joint::TransAxis)
    		jnt = Joint(jnt.getName(), f_tip * jnt.JointOrigin(),
    				f_tip.M * (-jnt.JointAxis()), Joint::TransAxis);

    	getSegment(parents_chain_root[s + 1], arg_segm);
    	bool exit_code = tree.addSegment(
    			Segment(arg_segm->second.segment.getName(), jnt, f_tip,
    					arg_segm->second.segment.getInertia()),
    					hook);
    	if(!exit_code){ // If the segment could not be added (segment with the same name already exists)...
    		tree = Tree();
    		return false;
    	}
    	hook = arg_segm->second.segment.getName();
    }

    // add the segments from the common frame to the tip frame
    for (int s = parents_chain_tip.size() - 1; s > -1; s--) {
    	SegmentMap::const_iterator seg;
    	getSegment(parents_chain_tip[s], seg);
    	bool exit_code = tree.addSegment(seg->second.segment,hook);
    	if(!exit_code){ // If the segment could not be added (segment with the same name already exists)...
    		tree = Tree();
    		return false;
    	}
    	hook = seg->second.segment.getName();
    }
    return true;
}

bool Tree::copy(const std::string& segm, Tree& returned_tree) const
{
   	std::vector<string> vect;
   	vect.push_back(segm);
   	return copy(vect,returned_tree);
}

bool Tree::copy(std::vector<std::string> list_of_segments, Tree& returned_tree) const
{
   	bool exit_code;
   	returned_tree = Tree();
   	SegmentMap::const_iterator root;
   	exit_code = getRootSegment(root);
   	if(!exit_code){
       	returned_tree = Tree();
   		return exit_code;
   	}
   	returned_tree = Tree(root->first);
   	for(int i = 0; i < root->second.children.size();i++)
   	{
   		std::vector<std::string>::iterator it = find(list_of_segments.begin(),list_of_segments.end(),root->second.children[i]->first);
   		if(it == list_of_segments.end()){
			exit_code = copyAid(list_of_segments, root, root->second.children[i], returned_tree);
			if(!exit_code){
				returned_tree = Tree();
				return exit_code;
			}
   		}
   	}
   	return true;
}

bool Tree::copyAid(	std::vector<std::string> list_of_segments,
   					SegmentMap::const_iterator parent,
   					SegmentMap::const_iterator child,
   					Tree& returned_tree) const
{
   	bool exit_code;
   	exit_code = returned_tree.addSegment(child->second.segment,parent->first);
	if(!exit_code)
	   return exit_code;
   	for(int i = 0; i < child->second.children.size();i++)
   	{
   		std::vector<std::string>::iterator it = find(list_of_segments.begin(),list_of_segments.end(),child->second.children[i]->first);
   		if(it == list_of_segments.end()){
			exit_code = copyAid(list_of_segments, child, child->second.children[i], returned_tree);
			if(!exit_code)
			   return exit_code;
   		}
   	}
   	return true;
}

}//end of namespace
