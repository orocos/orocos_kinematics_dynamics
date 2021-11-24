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

#include "chainiksolverpos_nr.hpp"

namespace KDL
{
    ChainIkSolverPos_NR::ChainIkSolverPos_NR(const Chain& _chain,ChainFkSolverPos& _fksolver,ChainIkSolverVel& _iksolver,
                                             unsigned int _maxiter, double _eps):
        chain(_chain),nj (chain.getNrOfJoints()),
        iksolver(_iksolver),fksolver(_fksolver),
        delta_q(_chain.getNrOfJoints()),
        maxiter(_maxiter),
        eps(_eps),
        numiter(0),
        ikvelstatus(E_NOERROR)
    {
    }

    void ChainIkSolverPos_NR::updateInternalDataStructures() {
        nj = chain.getNrOfJoints();
        iksolver.updateInternalDataStructures();
        fksolver.updateInternalDataStructures();
        delta_q.resize(nj);
    }

    int ChainIkSolverPos_NR::CartToJnt(const JntArray& q_init, const Frame& p_in, JntArray& q_out)
    {
        if (nj != chain.getNrOfJoints())
            return (error = E_NOT_UP_TO_DATE);

        if(q_init.rows() != nj || q_out.rows() != nj)
            return (error = E_SIZE_MISMATCH);

        q_out = q_init;
        bool degraded = false;

        for(numiter=1; numiter<=maxiter; ++numiter) {
            degraded = false; // prove otherwise
            if (E_NOERROR > fksolver.JntToCart(q_out,f) )
                return (error = E_FKSOLVERPOS_FAILED);
            delta_twist = diff(f,p_in);
            ikvelstatus = iksolver.CartToJnt(q_out,delta_twist,delta_q);
            if (E_NOERROR > ikvelstatus) {
                return (error = E_IKSOLVER_FAILED);
            }
            // check for degraded solution (but can still continue motion)
            else if (E_NOERROR < ikvelstatus) {
                degraded  = true;
            }
            // we choose to continue if the child solver returned a positive
            // "error", which may simply indicate a degraded solution
            Add(q_out,delta_q,q_out);
            if(Equal(delta_twist,Twist::Zero(),eps))
                // converged, but possibly with a degraded solution
                return (ikvelstatus > E_NOERROR ? E_DEGRADED : E_NOERROR);
        }

        // update cartesian output to be in sync with final joint solution
        (void)fksolver.JntToCart(q_out,f);

        // not converged but singularity avoidance is active so okay
        if (degraded)
            return (error = E_DEGRADED);
        else
            return (error = E_MAX_ITERATIONS_EXCEEDED);
    }

    void ChainIkSolverPos_NR::setEps(const double _eps)
    {
        if (0 < _eps) eps = _eps;
        // else silently ignore
    }

    void ChainIkSolverPos_NR::setMaxIter(const unsigned int _maxiter)
    {
        if (1 <= _maxiter) maxiter = _maxiter;
        // else silently ignore
    }

    ChainIkSolverPos_NR::~ChainIkSolverPos_NR()
    {
    }

    const char* ChainIkSolverPos_NR::strError(const int error) const
    {
        if (E_IKSOLVER_FAILED == error) return "Child IK solver failed";
        else if (E_FKSOLVERPOS_FAILED == error) return "Child FK solver failed";
        else return SolverI::strError(error);
    }
}

