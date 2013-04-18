#ifndef MOTIONPROFILE_SPLINE_H
#define MOTIONPROFILE_SPLINE_H

#include "motionprofile.hpp"
#include <boost/shared_ptr.hpp>

namespace KDL
{
	/**
	 * \brief A spline MotionProfile trajectory interpolation.
	 * @ingroup Motion
	 */
class MotionProfile_Spline : public MotionProfile
{
	typedef boost::shared_ptr<MotionProfile_Spline> MotionProfileSplinePtr;
	typedef boost::shared_ptr<MotionProfile> MotionProfilePtr;

public:

	static int Create(MotionProfileSplinePtr& profile);
	// constructs motion profile class. It also sets a trajectory from pos1 to pos2.
	static int Create(MotionProfileSplinePtr& profile, double pos1, double pos2);
	static int Create(const MotionProfile_Spline& p, MotionProfileSplinePtr& profile);
	// constructs motion profile class. It also sets a trajectory from pos1 to pos2.
	static int Create(const MotionProfile_Spline& p,MotionProfileSplinePtr& profile,double pos1, double pos2);

	virtual ~MotionProfile_Spline();
	
    virtual void SetProfile(double pos1, double pos2);
    /**
     * Generate linear interpolation coefficients.
     *
     * @param pos1 begin position.
     * @param pos2 end position.
     * @param duration duration of the profile.
     */
    virtual void SetProfileDuration(
      double pos1, double pos2, double duration);

    /**
     * Generate cubic spline interpolation coefficients.
     *
     * @param pos1 begin position.
     * @param vel1 begin velocity.
     * @param pos2 end position.
     * @param vel2 end velocity.
     * @param duration duration of the profile.
     */
    virtual void SetProfileDuration(
      double pos1, double vel1, double pos2, double vel2, double duration);

    /**
     * Generate quintic spline interpolation coefficients.
     *
     * @param pos1 begin position.
     * @param vel1 begin velocity.
     * @param acc1 begin acceleration
     * @param pos2 end position.
     * @param vel2 end velocity.
     * @param acc2 end acceleration.
     * @param duration duration of the profile.
     */
    virtual void SetProfileDuration(double pos1, double vel1, double acc1, double pos2, double vel2, double acc2, double duration);
    virtual double Duration() const;
    virtual int Pos(double time, double& returned_position) const;
    virtual int Vel(double time, double& returned_velocity) const;
    virtual int Acc(double time, double& returned_acceleration) const;
    virtual void Write(std::ostream& os) const;
    virtual MotionProfilePtr Clone() const;
private:
    MotionProfile_Spline(){};
    double coeff_[6];
    double duration_;
};
}
#endif // MOTIONPROFILE_CUBICSPLINE_H
