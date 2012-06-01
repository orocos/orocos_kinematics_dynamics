/**
 * \file path_example.cpp
 * An example to demonstrate the use of trajectory generation
 * functions.
 */
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <kdl/trajectory.hpp>
#include <kdl/trajectory_segment.hpp>
#include <kdl/trajectory_stationary.hpp>
#include <kdl/trajectory_composite.hpp>
#include <kdl/trajectory_composite.hpp>
#include <kdl/velocityprofile_trap.hpp>
#include <kdl/path_roundedcomposite.hpp>
#include <kdl/rotational_interpolation_sa.hpp>
#include <kdl/utilities/error.h>

int main(int argc,char* argv[]) {
	using namespace KDL;
	// Create the trajectory:
    // use try/catch to catch any exceptions thrown.
    // NOTE:  exceptions will become obsolete in a future version.
	try {
        // Path_RoundedComposite defines the geometric path along
        // which the robot will move.
		//
		Path_RoundedComposite* path = new Path_RoundedComposite(0.2,0.01,new RotationalInterpolation_SingleAxis());
		// The routines are now robust against segments that are parallel.
		// When the routines are parallel, no rounding is needed, and no attempt is made
		// add constructing a rounding arc.
		// (It is still not possible when the segments are on top of each other)
		// Note that you can only rotate in a deterministic way over an angle less then M_PI!
		// With an angle == M_PI, you cannot predict over which side will be rotated.
		// With an angle > M_PI, the routine will rotate over 2*M_PI-angle.
		// If you need to rotate over a larger angle, you need to introduce intermediate points.
		// So, there is a common use case for using parallel segments.
		path->Add(Frame(Rotation::RPY(M_PI,0,0), Vector(-1,0,0)));
		path->Add(Frame(Rotation::RPY(M_PI/2,0,0), Vector(-0.5,0,0)));
		path->Add(Frame(Rotation::RPY(0,0,0), Vector(0,0,0)));
		path->Add(Frame(Rotation::RPY(0.7,0.7,0.7), Vector(1,1,1)));
		path->Add(Frame(Rotation::RPY(0,0.7,0), Vector(1.5,0.3,0)));
		path->Add(Frame(Rotation::RPY(0.7,0.7,0), Vector(1,1,0)));

		// always call Finish() at the end, otherwise the last segment will not be added.
		path->Finish();

        // Trajectory defines a motion of the robot along a path.
		Trajectory* traject;
        // This defines a trapezoidal velocity profile.
		VelocityProfile* velpref = new VelocityProfile_Trap(0.5,0.1);
		velpref->SetProfile(0,path->PathLength());  
		traject = new Trajectory_Segment(path, velpref);

		// use the trajectory
		double dt=0.1;
		std::ofstream of("./trajectory.dat");
		for (double t=0.0; t <= traject->Duration(); t+= dt) {
			Frame current_pose;
			current_pose = traject->Pos(t);
			for (int i=0;i<4;++i)
				for (int j=0;j<4;++j)
					of << current_pose(i,j) << "\t";
			of << "\n";
			// also velocities and accelerations are available !
			//traject->Vel(t);
			//traject->Acc(t);
		}
		of.close();
		delete traject;
        std::cout << " trajectory written to the ./trajectory.dat file " << std::endl;
	} catch(Error& error) {
		std::cout <<"I encountered this error : " << error.Description() << std::endl;
		std::cout << "with the following type " << error.GetType() << std::endl;
	}

}


