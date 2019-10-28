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

#include "chain.hpp"
#include <algorithm>

namespace KDL {
    using namespace std;

    Chain::Chain():
            nrOfJoints(0),
            nrOfSegments(0),
            segments(0)
    {
    }

    Chain::Chain(const Chain& in):
            nrOfJoints(0),
            nrOfSegments(0),
            segments(0)
    {
        for(unsigned int i=0;i<in.getNrOfSegments();i++)
            this->addSegment(in.getSegment(i));
    }

    Chain& Chain::operator=(const Chain& arg)
    {
        nrOfJoints=0;
        nrOfSegments=0;
        segments.resize(0);
        for(unsigned int i=0;i<arg.nrOfSegments;i++)
            addSegment(arg.getSegment(i));
        return *this;

    }

    void Chain::addSegment(const Segment& segment)
    {
        segments.push_back(segment);
        nrOfSegments++;
        if(segment.getJoint().getType()!=Joint::None)
            nrOfJoints++;
    }

    void Chain::addChain(const Chain& chain)
    {
        for(unsigned int i=0;i<chain.getNrOfSegments();i++)
            this->addSegment(chain.getSegment(i));
    }

    const Segment& Chain::getSegment(unsigned int nr)const
    {
        return segments[nr];
    }

    Segment& Chain::getSegment(unsigned int nr)
    {
        return segments[nr];
    }

    unsigned int Chain::deleteSegmentsFrom(unsigned int nr)
    {
      // make sure the index is valid
      if(nr >= nrOfSegments)
        return 0;
      // decrease the number of joints (once for each moving joint that is removed)
      nrOfJoints -= std::count_if(
        segments.begin()+nr, segments.end(),
        [](const Segment& seg) { return seg.getJoint().getType() != Joint::None; }
      );
      // number of segments to be deleted
      unsigned int to_del = nrOfSegments - nr;
      // reset the number of segments
      nrOfSegments = nr;
      segments.resize(nr);
      return to_del;
    }

    unsigned int Chain::deleteSegmentsFrom(const std::string& name)
    {
      unsigned int irev;
      for(unsigned int i=0; i<nrOfSegments; i++) {
        irev = nrOfSegments-i-1;
        if(segments[irev].getName() == name) {
          // remove the segment
          return deleteSegmentsFrom(irev);
        }
      }
      return 0;
    }

    Chain::~Chain()
    {
    }

}

