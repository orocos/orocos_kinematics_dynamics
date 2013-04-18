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

#ifndef KDL_CHAIN_HPP
#define KDL_CHAIN_HPP

#include "segment.hpp"
#include <string>

namespace KDL {
    /**
	  * \brief This class encapsulates a <strong>serial</strong> kinematic
	  * interconnection structure. It is build out of segments.
     *
     * @ingroup KinematicFamily
     */
    class Chain {
    private:
        int nrOfJoints;
        int nrOfSegments;
        std::vector<Segment> segments;

    public:
        /**
         * The constructor of a chain, a new chain is always empty.
         */
        Chain();
        Chain(const Chain& in);
        Chain& operator = (const Chain& arg);

        /**
         * Adds a new segment to the <strong>end</strong> of the chain.
         *
         * @param segment The segment to add
         * @return  false: 	when there is already a segment with the same name in the chain.
         * 					"NoName" is ignored in this test (so it will return true even when there are multiple "NoName" segments in the chain).
         * 					In this case the segment will not be added.
         * 			true: 	in the other cases
         */
        //void addSegment(const Segment& segment);
        bool addSegment(const Segment& segment);

        /**
         * Adds a complete chain to the <strong>end</strong> of the chain
         * The added chain is copied.
         *
         * @param chain The chain to add
         * @return 	false: 	when the chain already contains at least one segment of the given chain.
         * 					"NoName" is ignored in this test (so it will return true even when there are multiple "NoName" segments in the new chain).
         * 					In this case the chain will not be added.
         *			true:	in the other cases
         */
        //void addChain(const Chain& chain);
        bool addChain(const Chain& chain);

        /**
         * Request the total number of joints in the chain.\n
         * <strong> Important:</strong> It is not the
         * same as the total number of segments since a segment does not
         * need to have a joint. This function is important when
         * creating a KDL::JntArray to use with this chain.
         * @return total nr of joints
         */
        unsigned int getNrOfJoints()const {return nrOfJoints;};
        /**
         * Request the total number of segments in the chain.
         * @return total number of segments
         */
        unsigned int getNrOfSegments()const {return nrOfSegments;};

//        /**
//         * Request the nr'd segment of the chain. There is no boundary
//         * checking.
//         *
//         * @param nr the nr of the segment starting from 0
//         *
//         * @return a constant reference to the nr'd segment
//         */
//        const Segment& getSegment(unsigned int nr)const;

		/**
		 * Request the nr'd segment of the chain.
		 *
		 * @param nr the nr of the segment starting from 0
		 * @param returned_segment: the return value. A constant reference to the nr'd segment.
		 *
		 * @return success or failure (out of bounds)
		 */
		 bool getSegment(unsigned int nr, Segment& returned_segment) const;

//        /**
//         * Request the root segment of the chain
//         * @return The root segment.
//         */
//        const Segment & getRootSegment() const
//        {
//            return getSegment(0);
//        }

		/**
		 * Request the root segment of the chain
		 * @param returned_segment: the return value. The root segment.
		 * @return true
		 */
		bool getRootSegment(Segment& returned_segment) const {
			getSegment(0,returned_segment); //Returns true
			return true;
		}

//        /**
//         * Request the segments of the tree.
//         */
//        const std::vector<Segment> & getSegments() const{
//        	return segments;
//        }

        /**
         * Request the segments of the tree.
         */
        bool getSegments(std::vector<Segment>& returned_segments) const{
        	returned_segments = segments;
        	return true;
        }

//        /**
//         * Request the segment with the given name in the chain.
//         * In case of "NoName", it will return the first "NoName"-segment.
//         *
//         * @param segment_name: the name of the segment that should be returned.
//         *
//         * @return: a constant reference to the first segment with the given name.
//         * 			If there is no segment with the given name in the chain,
//         * 			the last element will be returned.
//         */
//        const Segment & getSegment(const std::string &segment_name) const;

		/**
		 * Request the segment with the given name in the chain.
		 * In case of "NoName", it will return the first "NoName"-segment.
		 *
		 * @param segment_name: the name of the segment that should be returned.
		 * @param returned_segment: the return value. A constant reference to the first segment with the given name.
		 *
		 * @return: success or failure (not found)
		 */
		bool getSegment(const std::string &segment_name, Segment& returned_segment) const;

//        /**
//         * Request the last element in the chain.
//         * @return: the last element in the chain.
//         */
//        const Segment & getLeafSegment() const;

        /**
         * Request the last element in the chain.
         * @param returned_segment: the return value. The last element in the chain.
         * @return: success or failure
         */
        bool getLeafSegment(Segment& returned_segment) const;

        /**
         * Request the subchain of the chain between chain_root and chain_tip. The chain_root can be
         * after chain_tip in the original chain, or vice versa.
         *
         * @param chain_root the name of the root segment of the chain
         * @param chain_tip the name of the tip segment of the chain
         * @param chain the resulting chain
         *
         * @return success or failure
         */
        bool getChain(const std::string& chain_root, const std::string& chain_tip, Chain& chain) const;

        virtual ~Chain();
    };

}//end of namespace KDL

#endif
