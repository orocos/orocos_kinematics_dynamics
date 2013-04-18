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
 *		$Id: trajectory_composite.cpp 22 2004-09-21 08:58:54Z eaertbellocal $
 *		$Name:  $
 ****************************************************************************/

#include "trajectory_composite.hpp"
#include "path_composite.hpp"

namespace KDL {

    using namespace std;

    int Trajectory_Composite::Create(TrajectoryCompositePtr& trajectory)
    {
    	trajectory = TrajectoryCompositePtr(new Trajectory_Composite());
    	return 0;
    }

    Trajectory_Composite::Trajectory_Composite():duration(0.0)
    {
    }

    double Trajectory_Composite::Duration() const{
        return duration;
    }

    int Trajectory_Composite::Pos(double time, Frame& returned_position) const {
        // not optimal, could be done in log(#elem)
        // or one could buffer the last segment and start looking from there.
        unsigned int i;
        double previoustime;
        TrajectoryPtr traj;
        int exit_code;
        if (time < 0) {
             exit_code = vt[0]->Pos(0, returned_position);
             return exit_code;
        }
        previoustime = 0;
        for (i=0;i<vt.size();i++) {
            if (time < vd[i]) {
                exit_code = vt[i]->Pos(time-previoustime, returned_position);
                return exit_code;
            }
            previoustime = vd[i];
        }
        traj = vt[vt.size()-1];
        exit_code = traj->Pos(traj->Duration(),returned_position);
        return exit_code;
    }

    int Trajectory_Composite::Vel(double time, Twist& returned_velocity) const {
        // not optimal, could be done in log(#elem)
        unsigned int i;
        TrajectoryPtr traj;
        double previoustime;
        int exit_code;
        if (time < 0) {
            exit_code = vt[0]->Vel(0, returned_velocity);
            return exit_code;
        }
        previoustime = 0;
        for (i=0;i<vt.size();i++) {
            if (time < vd[i]) {
                exit_code = vt[i]->Vel(time-previoustime, returned_velocity);
                return exit_code;
            }
            previoustime = vd[i];
        }
        traj = vt[vt.size()-1];
        exit_code = traj->Vel(traj->Duration(),returned_velocity);
        return exit_code;
    }

    int Trajectory_Composite::Acc(double time, Twist& returned_acceleration) const {
        // not optimal, could be done in log(#elem)
    	unsigned int i;
    	TrajectoryPtr traj;
        double previoustime;
        int exit_code;
        if (time < 0) {
            exit_code = vt[0]->Acc(0, returned_acceleration);
            return exit_code;
        }
        previoustime = 0;
        for (i=0;i<vt.size();i++) {
		if (time < vd[i]) {
			exit_code = vt[i]->Acc(time-previoustime, returned_acceleration);
			return exit_code;
		}
		previoustime = vd[i];
        }
        traj = vt[vt.size()-1];
        exit_code = traj->Acc(traj->Duration(), returned_acceleration);
        return exit_code;
    }

    void Trajectory_Composite::Add(TrajectoryPtr elem) {
        vt.push_back(elem);
        duration += elem->Duration();
        vd.push_back(duration);
    }

    void Trajectory_Composite::Destroy() {
        vt.erase(vt.begin(),vt.end());
        vd.erase(vd.begin(),vd.end());
    }

    Trajectory_Composite::~Trajectory_Composite() {
        Destroy();
    }

    void Trajectory_Composite::Write(ostream& os) const {
        os << "COMPOSITE[ " << vt.size() << endl;
        unsigned int i;
        for (i=0;i<vt.size();i++) {
            vt[i]->Write(os);
        }
        os << "]" << endl;
    }

    boost::shared_ptr<Trajectory> Trajectory_Composite::Clone() const{
    	TrajectoryCompositePtr comp;
    	Trajectory_Composite::Create(comp);
        for (unsigned int i = 0; i < vt.size(); ++i) {
            comp->Add(vt[i]->Clone());
        }
        return comp;
    }

}

