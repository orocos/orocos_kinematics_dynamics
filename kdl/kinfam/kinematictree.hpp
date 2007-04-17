#ifndef  _KDL_KINEMATICTREE_HPP_
#define _KDL_KINEMATICTREE_HPP_

/***************************************************************************
                        tree.hpp -  description
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Ruben Smits
    email                : firstname.lastname@mech.kuleuven.be

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

#include <kdl/kinfam/jnt2cartpos.hpp>
#include <kdl/kinfam/cartpos2jnt.hpp>
#include <kdl/kinfam/jnt2jac.hpp>
#include <kdl/kinfam/kinematicfamily.hpp>
#include <kdl/kinfam/joint.hpp>
#include <kdl/kinfam/transmission.hpp>
#include <boost/graph/adjacency_list.hpp>

namespace KDL {

    struct VertexProp{
        int vertexnr;
    };
    
    struct EdgeProp
    {
        Joint* joint;
        std::string edgename;
    };
    
    /**
     * \brief Implementation of KinematicFamily for trees
     * 
     */
    class KinematicTree: public KinematicFamily {
    private:
        std::string name;
        int nrofjoints;
        
        typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,VertexProp,EdgeProp> Graph;
        typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
        typedef boost::graph_traits<Graph>::edge_descriptor Edge;

        Graph kinematicgraph;
        
    public:
                
        KinematicTree(const std::string& name,int offset,Transmission* transmission=0);
        
        ~KinematicTree();

        Transmission* transmission;
        
        ///Implementation of KinematicFamily :
        virtual Jnt2CartPos* createJnt2CartPos() const;
        virtual Jnt2Jac* createJnt2Jac() const;
        virtual CartPos2Jnt* createCartPos2Jnt() const;
        virtual KinematicFamily* clone() const;
        
        ///implementation of meta-information for KinematicFamily :
        virtual std::string getTypeName() const {return "tree";};
        virtual std::string getName() const {return name;};
        virtual int nrOfJoints() const {return nrofjoints;};
        
        /// implementation of KinematicTree specific functions

        
        /** 
         * Function to add a joint to the tree
         * 
         * @param parentjoint name of the parent joint
         * @param joint TreeJoint structure containing the new Joint     
         * 
         * @return true if parentjoint was found
         */
        bool addJoint(int vertex1, int vertex2, std::string newjoint, Joint* joint);
        
    };//class
    
} // namespace KDL

#endif
