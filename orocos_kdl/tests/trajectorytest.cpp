#include "trajectorytest.hpp"
#include <frames_io.hpp>
#include <utilities/scoped_ptr.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION( TraectoryTest );

using namespace KDL;

void TraectoryTest::setUp()
{
}

void TraectoryTest::tearDown()
{
}

void TraectoryTest::TestTrajectoryStationary()
{
    Frame f(Rotation::RPY(0.1, 0.2, 0.3), Vector(1, 2, 3));
    Trajectory_Stationary traj(2.0, f);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(2.0, traj.Duration(), epsilon);
    CPPUNIT_ASSERT_EQUAL(f, traj.Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(f, traj.Pos(1.0));
    CPPUNIT_ASSERT_EQUAL(f, traj.Pos(5.0));
    CPPUNIT_ASSERT_EQUAL(Twist::Zero(), traj.Vel(1.0));
    CPPUNIT_ASSERT_EQUAL(Twist::Zero(), traj.Acc(1.0));
}

void TraectoryTest::TestTrajectoryStationary_Clone()
{
    Frame f(Rotation::Identity(), Vector(1, 0, 0));
    Trajectory_Stationary traj(3.0, f);

    scoped_ptr<Trajectory> traj2(traj.Clone());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(traj.Duration(), traj2->Duration(), epsilon);
    CPPUNIT_ASSERT_EQUAL(f, traj2->Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(Twist::Zero(), traj2->Vel(0.0));
    CPPUNIT_ASSERT_EQUAL(Twist::Zero(), traj2->Acc(0.0));
}

void TraectoryTest::TestTrajectorySegmentWithDuration()
{
    // Path length is 8 (straight line along X), and with maxvel=2, maxacc=1
    // the fastest feasible profile over that distance takes 6s (same shape
    // as the "SetProfile(2,10)" case in velocityprofiletest.cpp, just
    // shifted to start at 0). Requesting an 8s duration is slower than that,
    // so SetProfileDuration() actually stretches the profile to match it.
    Frame start(Rotation::Identity(), Vector(0, 0, 0));
    Frame end(Rotation::Identity(), Vector(8, 0, 0));
    Path* path = new Path_Line(start, end, new RotationalInterpolation_SingleAxis(), 1.0);
    VelocityProfile* motprof = new VelocityProfile_Trap(2, 1);

    Trajectory_Segment segment(path, motprof, 8.0);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(8.0, segment.Duration(), epsilon);
    CPPUNIT_ASSERT_EQUAL(start, segment.Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(Vector(4, 0, 0), segment.Pos(4.0).p);
    CPPUNIT_ASSERT_EQUAL(end, segment.Pos(8.0));
}

void TraectoryTest::TestTrajectorySegmentWithoutDuration()
{
    // Same path as above, but this time the profile is pre-configured with
    // SetProfile() (fastest feasible profile: 6s) and handed to the
    // 2-argument constructor, which just trusts it is already set up.
    Frame start(Rotation::Identity(), Vector(0, 0, 0));
    Frame end(Rotation::Identity(), Vector(8, 0, 0));
    Path* path = new Path_Line(start, end, new RotationalInterpolation_SingleAxis(), 1.0);
    VelocityProfile_Trap* motprof = new VelocityProfile_Trap(2, 1);
    motprof->SetProfile(0, path->PathLength());

    Trajectory_Segment segment(path, motprof);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(6.0, segment.Duration(), epsilon);
    CPPUNIT_ASSERT_EQUAL(start, segment.Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(Vector(4, 0, 0), segment.Pos(3.0).p);
    CPPUNIT_ASSERT_EQUAL(end, segment.Pos(6.0));
}

void TraectoryTest::TestTrajectorySegment_Clone()
{
    Frame start(Rotation::Identity(), Vector(0, 0, 0));
    Frame end(Rotation::Identity(), Vector(2, 0, 0));
    Path* path = new Path_Line(start, end, new RotationalInterpolation_SingleAxis(), 1.0);
    VelocityProfile* motprof = new VelocityProfile_Trap(2, 1);
    Trajectory_Segment segment(path, motprof, 3.0);

    scoped_ptr<Trajectory> segment2(segment.Clone());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(segment.Duration(), segment2->Duration(), epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, (segment2->Pos(0.0).p - segment.Pos(0.0).p).Norm(), epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, (segment2->Pos(1.5).p - segment.Pos(1.5).p).Norm(), epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, (segment2->Pos(3.0).p - segment.Pos(3.0).p).Norm(), epsilon);
}

void TraectoryTest::TestTrajectoryComposite()
{
    Frame f0(Rotation::Identity(), Vector(0, 0, 0));
    Frame f1(Rotation::Identity(), Vector(2, 0, 0));
    Frame f2(Rotation::Identity(), Vector(2, 0, 3));

    Path* path0 = new Path_Line(f0, f1, new RotationalInterpolation_SingleAxis(), 1.0);
    Path* path1 = new Path_Line(f1, f2, new RotationalInterpolation_SingleAxis(), 1.0);

    Trajectory_Composite comp;
    comp.Add(new Trajectory_Segment(path0, new VelocityProfile_Trap(2, 1), 3.0));
    comp.Add(new Trajectory_Segment(path1, new VelocityProfile_Trap(2, 1), 4.0));

    CPPUNIT_ASSERT_DOUBLES_EQUAL(7.0, comp.Duration(), epsilon);
    // Pos() at the junction time returns the start of the second segment,
    // which coincides with the end of the first (f1) here.
    CPPUNIT_ASSERT_EQUAL(f0, comp.Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(f1, comp.Pos(3.0));
    CPPUNIT_ASSERT_EQUAL(f2, comp.Pos(7.0));
}

void TraectoryTest::TestTrajectoryComposite_Destroy()
{
    Frame f0(Rotation::Identity(), Vector(0, 0, 0));
    Frame f1(Rotation::Identity(), Vector(1, 0, 0));

    Trajectory_Composite comp;
    comp.Add(new Trajectory_Segment(
        new Path_Line(f0, f1, new RotationalInterpolation_SingleAxis(), 1.0),
        new VelocityProfile_Trap(2, 1), 2.0));

    // Destroy() deletes the contained trajectories right away. The
    // destructor calls Destroy() again unconditionally, so calling it twice
    // here (once explicitly, once more via the empty container it leaves
    // behind) must be safe rather than double-freeing anything.
    comp.Destroy();
    comp.Destroy();
}

void TraectoryTest::TestTrajectoryComposite_Clone()
{
    Frame f0(Rotation::Identity(), Vector(0, 0, 0));
    Frame f1(Rotation::Identity(), Vector(2, 0, 0));
    Frame f2(Rotation::Identity(), Vector(2, 0, 3));

    Path* path0 = new Path_Line(f0, f1, new RotationalInterpolation_SingleAxis(), 1.0);
    Path* path1 = new Path_Line(f1, f2, new RotationalInterpolation_SingleAxis(), 1.0);

    Trajectory_Composite comp;
    comp.Add(new Trajectory_Segment(path0, new VelocityProfile_Trap(2, 1), 3.0));
    comp.Add(new Trajectory_Segment(path1, new VelocityProfile_Trap(2, 1), 4.0));

    scoped_ptr<Trajectory> comp2(comp.Clone());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(comp.Duration(), comp2->Duration(), epsilon);
    CPPUNIT_ASSERT_EQUAL(f0, comp2->Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(f1, comp2->Pos(3.0));
    CPPUNIT_ASSERT_EQUAL(f2, comp2->Pos(7.0));
}
