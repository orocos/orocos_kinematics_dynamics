/*****************************************************************************
 *  \author
 *  	Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version
 *		LRL V0.2
 *
 *	\par History
 *		- $log$
 *
 *	\par Release
 *		$Id: trajectory_stationary.h 22 2004-09-21 08:58:54Z eaertbellocal $
 *		$Name:  $
 ****************************************************************************/

#ifndef TRAJECTORY_STATIONARY_H
#define TRAJECTORY_STATIONARY_H

#include "trajectory.hpp"
#include <boost/shared_ptr.hpp>


namespace KDL {
  /**
   * Implements a "trajectory" of a stationary position
   * for an amount of time.
   * @ingroup Motion
   */
	class Trajectory_Stationary : public Trajectory
	  {

		typedef boost::shared_ptr<Trajectory_Stationary> TrajectoryStationaryPtr;
		typedef boost::shared_ptr<Trajectory> TrajectoryPtr;


		double duration;
		Frame pos;

	public:
		static int Create(double _duration,const Frame& _pos, TrajectoryStationaryPtr& trajectory);

		virtual double Duration() const {
			return duration;
		}

		virtual int Pos(double time, Frame& returned_position) const {
			returned_position = pos;
			return 0;
		}

		virtual int Vel(double time, Twist& returned_velocity) const {
			returned_velocity = Twist::Zero();
			return 0;
		}

		virtual int Acc(double time, Twist& returned_acceleration) const {
			returned_acceleration = Twist::Zero();
			return 0;
		}

		virtual void Write(std::ostream& os) const;

		virtual TrajectoryPtr Clone() const {
			TrajectoryStationaryPtr trajectory;
			Trajectory_Stationary::Create(duration,pos, trajectory);
			return trajectory;
		}

		virtual ~Trajectory_Stationary() {}

	private:
		Trajectory_Stationary() {};
	};


}

#endif
