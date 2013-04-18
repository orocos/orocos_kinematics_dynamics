/*****************************************************************************
 *  \author
 *  	Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version
 *		LRL V0.2
 *
 *	\par History
 *		- $log$
 *		- Wouter Bancken (08/2012) - Refactored
 *
 *	\par Release
 *		$Id: trajectory_stationary.cpp 22 2004-09-21 08:58:54Z eaertbellocal $
 *		$Name:  $
 ****************************************************************************/


#include "trajectory_stationary.hpp"

namespace KDL {

    using namespace std;

int Trajectory_Stationary::Create(double _duration,const Frame& _pos, TrajectoryStationaryPtr& trajectory)
{
	trajectory = TrajectoryStationaryPtr(new Trajectory_Stationary());
	trajectory->pos = _pos;
	trajectory->duration = _duration;
	return 0;
}

void Trajectory_Stationary::Write(ostream& os) const {
	os << "STATIONARY[ " << duration << endl;
	os << pos << endl;
	os << "]";
}

}

