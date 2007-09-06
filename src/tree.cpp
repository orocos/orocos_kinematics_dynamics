// Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

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
namespace KDL
{
    using namespace std;
    
    Tree::Tree()
    {
        element root_element;
        segments.insert(make_pair("root",root_element));
    }

    Tree::Tree(const Tree& in)
    {
    }
    
    Tree& Tree::operator=(const Tree& in)
    {
        return *this;
    }
    
    bool Tree::addSegment(const Segment& segment,const std::string& segment_name,const std::string& hook_name)
    {
        SegmentMap::iterator parent = segments.find(hook_name);
        if(parent==segments.end())
            return false;
        element new_element;
        new_element.segment=segment;
        nrOfSegments++;
        if(segment.getJoint().getType()!=Joint::None)
            nrOfJoints++;
        new_element.parent=parent;
        pair<SegmentMap::iterator,bool> retval;
        retval=segments.insert(make_pair(segment_name,new_element));
        if(!retval.second)
            return false;
        parent->second.children.push_back(retval.first);
        return true;
    }
    
    bool Tree::addChain(const Chain& chain, const std::string& chain_name, const std::string& hook_name)
    {
        string parent_name=hook_name;
        for(unsigned int i=0;i<chain.getNrOfSegments();i++){
            ostringstream segment_name;
            segment_name<<chain_name<<".Segment"<<i;
            if(this->addSegment(chain.getSegment(i),segment_name.str(),parent_name))
                parent_name=segment_name.str();
            else
                return false;
        }
        return true;
    }
    
    bool Tree::addTree(const Tree& tree, const std::string& tree_name,const std::string& hook_name)
    {
        SegmentMap::const_iterator root=tree.getSegments().find("root");
        
        for(unsigned int i=0;i<root->second.children.size();i++){
            if(!(this->addTreePart(root->second.children[i],tree_name,hook_name)))
                return false;
        }
        return true;
    }
    
    bool Tree::addTreePart(const SegmentMap::const_iterator& pos,const std::string& tree_name, const std::string& hook_name)
    {
        if(this->addSegment(pos->second.segment,tree_name+"."+pos->first,hook_name)){
            for(unsigned int i=0;i<pos->second.children.size();i++){
                if(!(this->addTreePart(pos->second.children[i],tree_name,tree_name+"."+pos->first)))
                    return false;
            }
        }
        else 
            return false;
        return true;
    }

}


