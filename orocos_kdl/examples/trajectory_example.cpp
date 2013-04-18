/**
 * \file path_example.cpp
 * An example to demonstrate the use of trajectory generation
 * functions.
 *
 * There are is a matlab/octave file in the examples directory to visualise the results
 * of this example program. (visualize_trajectory.m)
 *
 */

#include <frames.hpp>
#include <frames_io.hpp>
#include <trajectory.hpp>
#include <trajectory_segment.hpp>
#include <trajectory_stationary.hpp>
#include <trajectory_composite.hpp>
#include <trajectory_composite.hpp>
#include <motionprofile_trap.hpp>
#include <path_roundedcomposite.hpp>
#include <rotational_interpolation_sa.hpp>
#include <utilities/error.h>
#include <trajectory_composite.hpp>
#include <boost/shared_ptr.hpp>
#include <path_spline.hpp>

int main(int argc, char* argv[]) {
	using namespace KDL;

	typedef boost::shared_ptr<RotationalInterpolation_SingleAxis> RotationalInterpolationSingleAxisPtr;
	typedef boost::shared_ptr<Path_RoundedComposite> PathRoundedCompositePtr;
	typedef boost::shared_ptr<MotionProfile_Trap> MotionProfileTrapPtr;
	typedef boost::shared_ptr<Trajectory_Segment> TrajectorySegmentPtr;
	typedef boost::shared_ptr<Trajectory_Stationary> TrajectoryStationaryPtr;
	typedef boost::shared_ptr<Trajectory_Composite> TrajectoryCompositePtr;

	// Create the trajectory:
	// Path_RoundedComposite defines the geometric path along which the robot will move.

	// To create new elements, the Create methods should be used.
	RotationalInterpolationSingleAxisPtr rotational_interpolation;
	RotationalInterpolation_SingleAxis::Create(rotational_interpolation);

	//Exit codes are used to signal errors.
	PathRoundedCompositePtr rounded_composite;
	int exit_code = Path_RoundedComposite::Create(	0.2,
													0.01,
													rotational_interpolation,
													rounded_composite);

	if (exit_code == -1) {
		std::cout << "Error: motion planning not feasible - 1." << std::endl;
		return 1;
	}

	// The routines are now robust against segments that are parallel.
	// When the routines are parallel, no rounding is needed, and no attempt is made
	// add constructing a rounding arc.
	// (It is still not possible when the segments are on top of each other)
	// Note that you can only rotate in a deterministic way over an angle less then M_PI!
	// With an angle == M_PI, you cannot predict over which side will be rotated.
	// With an angle > M_PI, the routine will rotate over 2*M_PI-angle.
	// If you need to rotate over a larger angle, you need to introduce intermediate points.
	// So, there is a common use case for using parallel segments.
	exit_code = rounded_composite->Add(Frame(Rotation::RPY(M_PI, 0, 0), Vector(-1, 0, 0)));
	exit_code += rounded_composite->Add(Frame(Rotation::RPY(M_PI / 2, 0, 0), Vector(-0.5, 0, 0)));
	exit_code += rounded_composite->Add(Frame(Rotation::RPY(0, 0, 0), Vector(0, 0, 0)));
	exit_code += rounded_composite->Add(Frame(Rotation::RPY(0.7, 0.7, 0.7), Vector(1, 1, 1)));
	exit_code += rounded_composite->Add(Frame(Rotation::RPY(0, 0.7, 0), Vector(1.5, 0.3, 0)));
	exit_code += rounded_composite->Add(Frame(Rotation::RPY(0.7, 0.7, 0), Vector(1, 1, 0)));
	if(exit_code != 0){
		std::cout << "An error occured while adding." << std::endl;
		return 0;
	}

	// always call Finish() at the end, otherwise the last segment will not be added.
	rounded_composite->Finish();

	// Trajectory defines a motion of the robot along a path.
	// This defines a trapezoidal motion profile.
	MotionProfileTrapPtr motion_profile;
	exit_code = MotionProfile_Trap::Create(motion_profile, 0.5, 0.1, 0, rounded_composite->PathLength());
	if(exit_code != 0){
		std::cout << "An error occured while creating a motion profile." << std::endl;
		return 0;
	}

	TrajectorySegmentPtr trajectory_segment;
	exit_code = Trajectory_Segment::Create(rounded_composite, motion_profile, trajectory_segment);
	if(exit_code != 0){
		std::cout << "An error occured while creating a trajectory segment." << std::endl;
		return 0;
	}

	TrajectoryStationaryPtr trajectory_stationary;
	Trajectory_Stationary::Create(	1.0,
									Frame(Rotation::RPY(0.7, 0.7, 0),
									Vector(1, 1, 0)),
									trajectory_stationary);

	TrajectoryCompositePtr trajectory_composite;
	exit_code = Trajectory_Composite::Create(trajectory_composite);
	if(exit_code != 0){
		std::cout << "An error occured while creating a trajectory composite." << std::endl;
		return 0;
	}

	trajectory_composite->Add(trajectory_segment);
	trajectory_composite->Add(trajectory_stationary);

	// use the trajectory
	double dt = 0.1;
	std::ofstream of("./trajectory.dat");
	for (double t = 0.0; t <= trajectory_segment->Duration(); t += dt) {
		Frame current_pose;
		exit_code = trajectory_segment->Pos(t, current_pose);
		if(exit_code != 0){
			std::cout << "An error occured using the trajectory." << std::endl;
			return 0;
		}
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				of << current_pose(i, j) << "\t";
		of << "\n";
		// also velocities and accelerations are available !
		//traject->Vel(t);
		//traject->Acc(t);
	}
	of.close();

	// you can get some meta-info on the path:
	for (int segmentnr = 0; segmentnr < rounded_composite->GetNrOfSegments();
			segmentnr++) {
		double starts, ends;
		Path::IdentifierType pathtype;
		if (segmentnr == 0) {
			starts = 0.0;
		} else {
			starts = rounded_composite->GetLengthToEndOfSegment(segmentnr - 1);
		}
		ends = rounded_composite->GetLengthToEndOfSegment(segmentnr);
		pathtype = rounded_composite->GetSegment(segmentnr)->getIdentifier();
		std::cout << "segment " << segmentnr << " runs from s=" << starts
				<< " to s=" << ends;
		switch (pathtype) {
		case Path::ID_CIRCLE:
			std::cout << " circle";
			break;
		case Path::ID_LINE:
			std::cout << " line ";
			break;
		default:
			std::cout << " unknown ";
			break;
		}
		std::cout << std::endl;
	}
	std::cout << " trajectory written to the ./trajectory.dat file " << std::endl;

	trajectory_composite.reset();
}

