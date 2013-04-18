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

#ifndef KDL_TREE_HPP
#define KDL_TREE_HPP

#include "segment.hpp"
#include "chain.hpp"

#include <string>
#include <map>

namespace KDL
{
    //Forward declaration
    class TreeElement;
    typedef std::map<std::string,TreeElement> SegmentMap;

    class TreeElement
    {
    private:
        TreeElement(const std::string& name):segment(name), q_nr(0)
        {};
    public:
        Segment segment;
        unsigned int q_nr;
        SegmentMap::const_iterator  parent;
        std::vector<SegmentMap::const_iterator > children;
        TreeElement(const Segment& segment_in,const SegmentMap::const_iterator& parent_in,unsigned int q_nr_in)
        {
			q_nr=q_nr_in;
            segment=segment_in;
            parent=parent_in;
        };
        static TreeElement Root(const std::string& root_name)
        {
            return TreeElement(root_name);
        };
    };

    /**
     * \brief  This class encapsulates a <strong>tree</strong>
     * kinematic interconnection structure. It is build out of segments.
     *
     * @ingroup KinematicFamily
     */
    class Tree
    {
    private:
        SegmentMap segments;
        SegmentMap leafSegments;
        int nrOfJoints;
        int nrOfSegments;

        std::string root_name;

        bool addTreeRecursive(SegmentMap::const_iterator root, const std::string& hook_name);
        bool copyAid(	std::vector<std::string> list_of_segments,
        				SegmentMap::const_iterator parent,
        				SegmentMap::const_iterator child,
        				Tree& returned_tree) const;
    public:
        /**
         * The constructor of a tree, a new tree is always empty
         */
        explicit Tree(const std::string& root_name="root");
        Tree(const Tree& in);
        Tree& operator= (const Tree& arg);

        /**
         * Adds a new segment to the end of the segment with
         * hook_name as segment_name
         *
         * @param segment new segment to add
         * @param hook_name name of the segment to connect this
         * segment with.
         *
         * @return false: if hook_name could not be found. \n
         * 			true: in the other cases.
         */
         bool addSegment(const Segment& segment, const std::string& hook_name);

        /**
         * Adds a complete chain to the end of the segment with
         * hook_name as segment_name. 
         *
         * @param hook_name name of the segment to connect the chain with.
         *
         * @return false: if hook_name could not be found. \n
         * 			true: in the other cases.
         */
        bool addChain(const Chain& chain, const std::string& hook_name);

        /**
         * Adds a complete tree to the end of the segment with
         * hookname as segment_name. 
         *
         * @param tree Tree to add
         * @param hook_name name of the segment to connect the tree with
         *
         * @return false: if hook_name could not be found \n
         * 			true: in the other cases.
         */
        bool addTree(const Tree& tree, const std::string& hook_name);

        /**
         * Request the total number of joints in the tree.\n
         * <strong> Important:</strong> It is not the same as the
         * total number of segments since a segment does not need to have
         * a joint.
         *
         * @return total nr of joints
         */
        unsigned int getNrOfJoints()const
        {
            return nrOfJoints;
        };

        /**
         * Request the total number of segments in the tree.
         * @return total number of segments
         */
        unsigned int getNrOfSegments()const {return nrOfSegments;};

        /**
         * Request the segment of the tree with name segment_name.
         *
         * @param segment_name the name of the requested segment
         *
         * @return constant iterator pointing to the requested segment
         *
         * @deprecated use bool getSegment(const std::string& segment_name, SegmentMap::const_iterator& returned_it)const instead!
         */
        SegmentMap::const_iterator getSegment(const std::string& segment_name) const __attribute__ ((deprecated));

        /**
         * Request the segment of the tree with name segment_name.
         *
         * @param segment_name the name of the requested segment
         * @param returned_it The return value. A constant iterator pointing to the requested segment.
         *
         * @return success or failure (not found)
         */
        bool getSegment(const std::string& segment_name, SegmentMap::const_iterator& returned_it) const;

        /**
         * Request the root segment of the tree
         *
         * @return constant iterator pointing to the root segment
         *
         * @deprecated use bool getRootSegment(SegmentMap::const_iterator& returned_it) const instead!
         */
        SegmentMap::const_iterator getRootSegment() const __attribute__ ((deprecated));

        /**
         * Request the root segment of the tree
         *
         * @param returned_it The return value; Constant iterator pointing to the root segment
         *
         * @return success or failure (not found)
         *
         */
        bool getRootSegment(SegmentMap::const_iterator& returned_it) const
        {
          returned_it = segments.find(root_name);
          if(returned_it == segments.end())
        	  return false;
          else
        	  return true;
        };

        /**
         * Request the chain of the tree between chain_root and chain_tip.  The chain_root
         * and chain_tip can be in different branches of the tree, the chain_root can be
         * an ancestor of chain_tip, and chain_tip can be an ancestor of chain_root.
         *
         * @param chain_root the name of the root segment of the chain
         * @param chain_tip the name of the tip segment of the chain
         * @param chain the resulting chain
         *
         * @return success or failure
         */
		  bool getChain(const std::string& chain_root, const std::string& chain_tip, Chain& chain)const;

		  /**
		   * Request the chain of the tree between chain_root and chain_tip as a tree. The chain_root
		   * and chain_tip can be in different branches of the tree, the chain_root can be
		   * an ancestor of chain_tip, and chain_tip can be an ancestor of chain_root.
		   *
		   * @param chain_root the name of the root segment of the chain
		   * @param chain_tip the name of the tip segment of the chain
		   * @param tree the resulting tree
		   *
		   * @return success or failure
		   */
		  bool getChain(const std::string& chain_root,const std::string& chain_tip,Tree& tree, const std::string& rootname = "root") const;

		  /**
		   * Request the leaf segments of the tree.
		   *
		   * @param returned_map The return value. The leaf segments of the tree.
		   *
		   * @return true
		   */
		  bool getLeafSegments(SegmentMap& returned_map) const
		  {
			  returned_map.clear();
			  returned_map = leafSegments;
			  return true;
		  }

		  const SegmentMap& getSegments() const __attribute__ ((deprecated));

		  bool getSegments(SegmentMap& returned_map) const
		  {
			  returned_map.clear();
			  returned_map = segments;
			  return true;
		  }

		  /**
		   * Create a copy excluding the given segment and all its descendants.
		   * This corresponds to creating a new Tree in which the given segment and all its descendants are \b deleted.
		   *
		   * @param segm The segment that should be excluded with its descendants.
		   * @param returned_tree The resulting tree.
		   *
		   * @return 	false: if an error occurs while adding segments to the copy. \n
		   * 			true:  in the other cases.
		   */
		  bool copy(const std::string& segm, Tree& returned_tree) const;

		  /**
		   * Create a copy excluding the given segments and all their descendants.
		   * This corresponds to creating a new Tree in which the given segments and all their descendants are \b deleted.
		   *
		   * @param list_of_segments The segments that should be excluded in the copy.
		   * @param returned_tree The resulting tree.
		   *
		   * @return 	false: if an error occurs while adding the segments to the copy.\n
		   * 			true:  in the other cases.
		   */
		  bool copy(std::vector<std::string> list_of_segments, Tree& returned_tree) const;

		  virtual ~Tree(){};

    };
}
#endif





