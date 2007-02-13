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

#include "kinematictree.hpp"
//#include <kdl/kinfam/kinematictreecartpos2jnt.hpp>
//#include <kdl/kinfam/kinematictreejnt2cartpos.hpp>
//#include <kdl/kinfam/kinematictreejnt2jac.hpp>

using namespace std;

namespace KDL
{
    KinematicTree::KinematicTree(const std::string& _name,int offset,Transmission* transmission):
        KinematicFamily(0,0),
        name(_name),
        nrofjoints(0)
    {
        //create root vertex
        VertexProp vprop;
        vprop.vertexnr=nrofjoints++;
        add_vertex(vprop,kinematicgraph);
    }
    
    KinematicTree::~KinematicTree()
    {
    }
    
    Jnt2CartPos* KinematicTree::createJnt2CartPos() const
    {
        //return new KinematicTreeJnt2CartPos(this);
    }

    Jnt2Jac* KinematicTree::createJnt2Jac() const
    {
        //return new KinematicTreeJnt2Jac(this);
    }
    
    CartPos2Jnt* KinematicTree::createCartPos2Jnt() const
    {
        //return new KinematicTreeCartPos2Jnt(this);
    }

    KinematicFamily* KinematicTree::clone() const
    {
        //        return new KinematicTree();
    }

    bool KinematicTree::addJoint(int vertex1, int vertex2, string newjoint, Joint* joint)
    {
        //Find out if vertex1 or vertex2 already exists
        
        //Create new vertex if necessairy
        //    VertexProp vprop;
        //    vprop.vertexnr=nrofjoints++;
        //    add_vertex(vprop,kinematicgraph);
        //    //Create Edge
        //    EdgeProp eprop;
        //    eprop.edgename = newjoint;
        //    eprop.joint = joint;
        //    //Add edge to graph
        //    add_edge(v1,v2,eprop,kinematicgraph);
    }
    
}//namespace

    
