// Copyright (C) 2013 Stephen Roderick <kiwi dot net at mac dot com>

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

#ifndef	__SOLVERI_HPP
#define	__SOLVERI_HPP

namespace KDL {

/**
 * Solver interface supporting storage and description of the latest error.
 *
 * Example use
 *
 * \code
 * class MySolver : public SolverI
 * {
 * public:
 *    static const int E_CHILDFAILD = xxx;
 *
 *    MySolver(SomeOtherSolver& other);
 *    virtual ~MySolver();
 * 	  int CartToJnt(...);
 *    virtual const char* strError(const int error) const;
 * protected:
 *    SomeOtherSolver& child;
 * };
 *
 * ...
 *
 * int MySolver::CartToJnt(...)
 * {
 *     error = child->SomeCall();
 *     if (E_NOERROR != error) {
 *         error = E_CHILDFAILED;
 *     } else {
 *         ...
 *     }
 *     return error;
 * }
 *
 * const char* MySolver::strError(const int error) const
 * {
 *     if (E_CHILDFAILED == error) return "Child solver failed";
 *     else return SolverI::strError(error);
 * }
 *
 * void someFunc()
 * {
 *     SomeOtherSolver child = new SomeOtherSolver(...);
 *     MySolver parent = new MySolver(child);
 *     ...
 *     int rc = parent->CartToJnt(...);
 *     if (E_NOERROR != rc) {
 *         if (MySolver::E_CHILDFAILED == rc) {
 *             rc = child->getError();
 *             // cope with child failure 'rc'
 *         }
 *     }
 *     ...
 * }
 * \endcode
 */
class SolverI
{
public:
	/* Zero (0) indicates no error, positive error codes indicate more of a
	   warning (e.g. a degraded solution, but motion can continue), and
	   negative error codes indicate failure (e.g. a singularity, and motion
	   can not continue).
	*/
	static const int E_NOERROR			= 0;	//! No error
	static const int E_NO_CONVERGE		= -1;	//! Failed to converge

	/// Initialize latest error to E_NOERROR
	SolverI() :
			error(E_NOERROR)
	{}

	virtual ~SolverI()
	{}

	/// Return the latest error
	virtual int getError() const { return error; }

	/** Return a description of the latest error
		\return if \a error is known then a description of \a error, otherwise
		"UNKNOWN ERROR"
	*/
	virtual const char* strError(const int error) const
	{
		if (E_NOERROR == error) return "No error";
		else if (E_NO_CONVERGE == error) return "Failed to converge";
		else return "UNKNOWN ERROR";
	}

protected:
	/// Latest error, initialized to E_NOERROR in constructor
	int		error;
};

}	//	namespaces

#endif
