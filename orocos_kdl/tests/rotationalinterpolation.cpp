#include "rotationalinterpolation.hpp"
#include <frames_io.hpp>
#include <utilities/scoped_ptr.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION( RotationalInterpolationTest );

using namespace KDL;

void RotationalInterpolationTest::setUp()
{
}

void RotationalInterpolationTest::tearDown()
{
}

void RotationalInterpolationTest::TestSingleAxis_Basic()
{
    // start == Identity, end is a 90 degree rotation about Z: the derived
    // interpolation axis is then simply the base-frame Z axis.
    RotationalInterpolation_SingleAxis interp;
    interp.SetStartEnd(Rotation::Identity(), Rotation::RotZ(PI_2));

    CPPUNIT_ASSERT_DOUBLES_EQUAL(PI_2, interp.Angle(), epsilon);
    CPPUNIT_ASSERT(Equal(Rotation::Identity(), interp.Pos(0.0)));
    CPPUNIT_ASSERT(Equal(Rotation::RotZ(PI_2), interp.Pos(interp.Angle())));
    CPPUNIT_ASSERT(Equal(Rotation::RotZ(PI_4), interp.Pos(interp.Angle() / 2.0)));
}

void RotationalInterpolationTest::TestSingleAxis_VelAcc()
{
    RotationalInterpolation_SingleAxis interp;
    interp.SetStartEnd(Rotation::Identity(), Rotation::RotZ(PI_2));

    // With an Identity start, the (fixed) interpolation axis expressed in
    // the base frame is just (0,0,1); Vel/Acc scale it by thetad/thetadd.
    CPPUNIT_ASSERT(Equal(Vector(0, 0, 1), interp.Vel(interp.Angle(), 1.0)));
    CPPUNIT_ASSERT(Equal(Vector(0, 0, 2), interp.Vel(interp.Angle(), 2.0)));
    CPPUNIT_ASSERT(Equal(Vector(0, 0, 1), interp.Acc(interp.Angle(), 0.0, 1.0)));
    CPPUNIT_ASSERT(Equal(Vector::Zero(), interp.Acc(interp.Angle(), 1.0, 0.0)));
}

void RotationalInterpolationTest::TestSingleAxis_NonIdentityStart()
{
    // The interpolation axis is fixed in the *start* frame (here the
    // start's own local Z axis), so with a non-identity start rotation,
    // Vel()/Acc() must transform it into the base frame via R_base_start
    // rather than treating it as already expressed in the base frame.
    Rotation start = Rotation::RotX(PI_2);
    Rotation end = start * Rotation::RotZ(PI_2);

    RotationalInterpolation_SingleAxis interp;
    interp.SetStartEnd(start, end);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(PI_2, interp.Angle(), epsilon);
    CPPUNIT_ASSERT(Equal(start, interp.Pos(0.0)));
    CPPUNIT_ASSERT(Equal(end, interp.Pos(interp.Angle())));
    // RotX(pi/2) maps the local Z axis (0,0,1) to (0,-1,0) in the base frame.
    CPPUNIT_ASSERT(Equal(Vector(0, -1, 0), interp.Vel(interp.Angle(), 1.0)));
}

void RotationalInterpolationTest::TestSingleAxis_Clone()
{
    // Regression test: Clone() used to return a fresh, unconfigured
    // RotationalInterpolation_SingleAxis instead of preserving the start/end
    // rotations (and the axis/angle derived from them), which showed up as
    // testCopy failures for both Angle() and Pos().
    RotationalInterpolation_SingleAxis interp;
    interp.SetStartEnd(Rotation::RotX(PI_2), Rotation::RotX(PI_2) * Rotation::RotZ(PI_2));

    scoped_ptr<RotationalInterpolation> clone(interp.Clone());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(interp.Angle(), clone->Angle(), epsilon);
    CPPUNIT_ASSERT(Equal(interp.Pos(0.0), clone->Pos(0.0)));
    CPPUNIT_ASSERT(Equal(interp.Pos(interp.Angle()), clone->Pos(interp.Angle())));
    CPPUNIT_ASSERT(Equal(interp.Vel(interp.Angle(), 1.0), clone->Vel(interp.Angle(), 1.0)));
}
