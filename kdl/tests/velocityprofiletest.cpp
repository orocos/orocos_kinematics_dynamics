#include "velocityprofiletest.hpp"
#include <frames_io.hpp>
CPPUNIT_TEST_SUITE_REGISTRATION( VelocityProfileTest );

using namespace KDL;

void VelocityProfileTest::setUp()
{
}

void VelocityProfileTest::tearDown()
{
}

void VelocityProfileTest::TestTrap_MaxVelocity1()
{
	// 2 second ramp up (cover 2 distance),
	// 2 second flat velocity (cover 4 distance)
	// 2 second ramp down (cover 2 distance),
	VelocityProfile_Trap	v(2, 1);
	double					time;
	v.SetProfile(2, 10);
	CPPUNIT_ASSERT_EQUAL(6.0, v.Duration());

	// start
	time = 0;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(1.0, v.Acc(time));

	// end of ramp up
	time = 2;
	CPPUNIT_ASSERT_EQUAL(4.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// middle of flat velocity
	time = 3;
	CPPUNIT_ASSERT_EQUAL(6.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// end of flat velocity
	time = 4;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(-1.0, v.Acc(time));

	// middle of ramp down
	time = 5;
	CPPUNIT_ASSERT_EQUAL(9.5, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(1.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(-1.0, v.Acc(time));

	// end
	time = 6;
	CPPUNIT_ASSERT_EQUAL(10.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(-1.0, v.Acc(time));

	// fenceposts - before and after
	time = -1;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));
	time = 11;
	CPPUNIT_ASSERT_EQUAL(10.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));
}

void VelocityProfileTest::TestTrap_MaxVelocity2()
{
	// 2 second ramp up (cover -2 distance),
	// 2 second flat velocity (cover -4 distance)
	// 2 second ramp down (cover -2 distance),
	VelocityProfile_Trap	v(2, 1);
	v.SetProfile(2, -6);
	CPPUNIT_ASSERT_EQUAL(6.0, v.Duration());
}

void VelocityProfileTest::TestTrap_MaxVelocity3()
{
	// 2 second ramp up (cover 4 distance),
	// 0 second flat velocity (cover 0 distance)
	// 2 second ramp down (cover 4 distance),
	VelocityProfile_Trap	v(4, 2);
	v.SetProfile(2, 10);
	CPPUNIT_ASSERT_EQUAL(4.0, v.Duration());

	// new profile
	v.SetProfile(2, -6);
	CPPUNIT_ASSERT_EQUAL(4.0, v.Duration());

	// another new profile : ramp + 2 sec + ramp
	v.SetProfile(13, 13 + 4 + 8 + 4);
	CPPUNIT_ASSERT_EQUAL(6.0, v.Duration());
}

void VelocityProfileTest::TestTrap_SetDuration1()
{
	// same as first max velocity test, but twice as
	// long (max velocity gives 6 seconds)
	VelocityProfile_Trap	v(2, 1);
	double					time;
	v.SetProfileDuration(2, 10, 12.0);
	CPPUNIT_ASSERT_EQUAL(12.0, v.Duration());

	// start
	time = 0;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.25, v.Acc(time));

	// end of ramp up
	time = 4;
	CPPUNIT_ASSERT_EQUAL(4.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(1.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// middle of flat velocity
	time = 6;
	CPPUNIT_ASSERT_EQUAL(6.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(1.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// end of flat velocity
	time = 8;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(1.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(-0.25, v.Acc(time));

	// middle of ramp down
	time = 10;
	CPPUNIT_ASSERT_EQUAL(9.5, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.5, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(-0.25, v.Acc(time));

	// end
	time = 12;
	CPPUNIT_ASSERT_EQUAL(10.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(-0.25, v.Acc(time));
}

void VelocityProfileTest::TestTrapHalf_SetProfile_Start()
{
	// 2 second ramp up (cover 2 distance),
	// 2 second flat velocity (cover 4 distance)
	VelocityProfile_TrapHalf	v(2, 1, true);
	double						time;
	v.SetProfile(2, 2+6);
	CPPUNIT_ASSERT_EQUAL(4.0, v.Duration());

	// start
	time = 0;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(1.0, v.Acc(time));

	// end of ramp up
	time = 2;
	CPPUNIT_ASSERT_EQUAL(4.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// middle of flat velocity
	time = 3;
	CPPUNIT_ASSERT_EQUAL(6.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// end
	time = 4;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// fenceposts - before and after
	time = -1;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));
	time = 5;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));
}

void VelocityProfileTest::TestTrapHalf_SetProfile_End()
{
	// 2 second flat velocity (cover 4 distance)
	// 2 second ramp up (cover 2 distance),
	VelocityProfile_TrapHalf	v(2, 1, false);
	double						time;
	v.SetProfile(9, 9-6);
	CPPUNIT_ASSERT_EQUAL(4.0, v.Duration());

	// start - flat velocity
	time = 0;
	CPPUNIT_ASSERT_EQUAL(9.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(-2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// end of flat velocity
	time = 2;
	CPPUNIT_ASSERT_EQUAL(5.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(-2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(1.0, v.Acc(time));

	// middle of ramp down
	time = 3;
	CPPUNIT_ASSERT_EQUAL(3.5, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(-1.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(1.0, v.Acc(time));

	// end
	time = 4;
	CPPUNIT_ASSERT_EQUAL(3.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// fenceposts - before and after
	time = -1;
	CPPUNIT_ASSERT_EQUAL(9.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));
	time = 5;
	CPPUNIT_ASSERT_EQUAL(3.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));
}

void VelocityProfileTest::TestTrapHalf_SetDuration_Start()
{
	// same as TestTrapHalf__SetProfile_Start() but twice as slow
	// Lingers at start position with zero velocity for a period of time,
	// as does not scale the velocity; only scales the acceleration!?
	VelocityProfile_TrapHalf	v(2, 1, true);
	double						time;
	v.SetProfileDuration(2, 2+6, 8);
	CPPUNIT_ASSERT_EQUAL(8.0, v.Duration());

	// start - no motion
	time = 0;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// no motion
	time = 1.9;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// begin ramp at scaled acceleration
	time = 2;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(2.0, v.Pos(time), 0.001);
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.333, v.Acc(time), 0.001);

	// middle of ramp up
	time = 5;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(3.5, v.Pos(time), 0.001);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, v.Vel(time), 0.001);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.3333, v.Acc(time), 0.001);

	// end - continue with given velocity
	time = 8;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// fenceposts - before and after
	time = -1;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));
	time = 9;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

}

void VelocityProfileTest::TestTrapHalf_SetDuration_End()
{
	// same as TestTrapHalf__SetProfile_Start() but twice as slow
	// Lingers at start position with zero velocity for a period of time,
	// as does not scale the velocity; only scales the acceleration!?
	VelocityProfile_TrapHalf	v(2, 1, true);
	double						time;
	v.SetProfileDuration(2+6, 2, 8);
	CPPUNIT_ASSERT_EQUAL(8.0, v.Duration());

	// start - no motion
	time = 0;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// no motion
	time = 1.9;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// begin ramp at scaled acceleration
	time = 2;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(8.0, v.Pos(time), 0.001);// WRONG, backwards!
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.333, v.Acc(time), 0.001);

	// middle of ramp up
	time = 5;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(6.5, v.Pos(time), 0.001);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.0, v.Vel(time), 0.001);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.3333, v.Acc(time), 0.001);

	// end - continue with given velocity
	time = 8;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(-2.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

	// fenceposts - before and after
	time = -1;
	CPPUNIT_ASSERT_EQUAL(8.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));
	time = 9;
	CPPUNIT_ASSERT_EQUAL(2.0, v.Pos(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Vel(time));
	CPPUNIT_ASSERT_EQUAL(0.0, v.Acc(time));

}
