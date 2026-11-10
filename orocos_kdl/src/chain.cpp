// Copyright  (C)  2007  Ruben Smits <ruben dot smits at intermodalics dot eu>

// Version: 1.0
// Author: Ruben Smits <ruben dot smits at intermodalics dot eu>
// Maintainer: Ruben Smits <ruben dot smits at intermodalics dot eu>
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
        if(segment.getJoint().getType()!=Joint::Fixed)
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
        if(nr >= nrOfSegments)
            return 0;
        for(unsigned int i=nr;i<nrOfSegments;i++)
            if(segments[i].getJoint().getType()!=Joint::Fixed)
                nrOfJoints--;
        const unsigned int nrDeleted = nrOfSegments - nr;
        segments.resize(nr);
        nrOfSegments = nr;
        return nrDeleted;
    }

    unsigned int Chain::deleteSegmentsFrom(const std::string& name)
    {
        // Search from the tip, as names don't need to be unique
        for(unsigned int i=nrOfSegments;i>0;i--)
            if(segments[i-1].getName()==name)
                return deleteSegmentsFrom(i-1);
        return 0;
    }

    Chain::~Chain()
    {
    }

}

