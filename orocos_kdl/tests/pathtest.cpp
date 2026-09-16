#include "pathtest.hpp"
#include <frames_io.hpp>
#include <rotational_interpolation_sa.hpp>
#include <utilities/scoped_ptr.hpp>
#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION( PathTest );

using namespace KDL;

void PathTest::setUp()
{
}

void PathTest::tearDown()
{
}

// A quarter circle of radius 1 in the XY plane, centered on the origin,
// without any reorientation. The translation is the limiting factor here.
static Path_Circle* CreateCircle()
{
    return new Path_Circle(Frame(Rotation::Identity(), Vector(1, 0, 0)),
                           Vector(0, 0, 0),
                           Vector(0, 1, 0),
                           Rotation::Identity(),
                           M_PI / 2,
                           new RotationalInterpolation_SingleAxis(),
                           1.0);
}

// A short arc combined with a 90 degree reorientation, such that the
// rotation is the limiting factor (oalpha*eqradius > alpha*radius) and
// scalelin differs from 1.
static Path_Circle* CreateCircleRotationLimited()
{
    return new Path_Circle(Frame(Rotation::Identity(), Vector(1, 0, 0)),
                           Vector(0, 0, 0),
                           Vector(0, 1, 0),
                           Rotation::RotZ(M_PI / 2),
                           0.1,
                           new RotationalInterpolation_SingleAxis(),
                           1.0);
}

// The same quarter circle as CreateCircle(), but translated away from the
// origin, so that the center of the circle is not the origin.
static Path_Circle* CreateCircleOffOriginCenter()
{
    return new Path_Circle(Frame(Rotation::Identity(), Vector(6, 5, 5)),
                           Vector(5, 5, 5),
                           Vector(5, 6, 5),
                           Rotation::Identity(),
                           M_PI / 2,
                           new RotationalInterpolation_SingleAxis(),
                           1.0);
}

// Compares two paths over the full s range of the original, so that a
// difference in shape is caught and not only a difference in length.
static void AssertSamePath(const std::string& message, Path* original, Path* other)
{
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE(message + ": PathLength",
                                         original->PathLength(), other->PathLength(), epsilon);

    const unsigned int samples = 20;
    for (unsigned int i = 0; i <= samples; ++i) {
        const double s = original->PathLength() * i / samples;
        std::stringstream at;
        at << message << " at s=" << s;
        CPPUNIT_ASSERT_MESSAGE(at.str() + ": Pos", Equal(original->Pos(s), other->Pos(s)));
        CPPUNIT_ASSERT_MESSAGE(at.str() + ": Vel", Equal(original->Vel(s, 1.0), other->Vel(s, 1.0)));
        CPPUNIT_ASSERT_MESSAGE(at.str() + ": Acc", Equal(original->Acc(s, 1.0, 1.0), other->Acc(s, 1.0, 1.0)));
    }
}

// Clone() used to pass alpha in degrees to a constructor that expects
// radians, which made the cloned arc 180/pi times too long.
void PathTest::TestCircleCloneKeepsPathLength()
{
    scoped_ptr<Path_Circle> circle(CreateCircle());
    scoped_ptr<Path> clone(circle->Clone());

    CPPUNIT_ASSERT_DOUBLES_EQUAL(circle->PathLength(), clone->PathLength(), epsilon);
}

void PathTest::TestCircleCloneEqualsOriginal()
{
    scoped_ptr<Path_Circle> circle(CreateCircle());
    scoped_ptr<Path> clone(circle->Clone());

    AssertSamePath("Clone of circle", circle.get(), clone.get());
}

// With the rotation as the limiting factor, the too long arc of the clone
// also flipped it into the translation limited branch of the constructor,
// changing scalelin and scalerot, so Pos/Vel/Acc diverged as well.
void PathTest::TestCircleCloneEqualsOriginalRotationLimited()
{
    scoped_ptr<Path_Circle> circle(CreateCircleRotationLimited());
    scoped_ptr<Path> clone(circle->Clone());

    AssertSamePath("Clone of rotation limited circle", circle.get(), clone.get());
}

// Clone() used to pass the direction F_base_center.M.UnitY() where the
// constructor expects a point in the base frame, which put the cloned
// circle in a different plane whenever the center is not the origin.
void PathTest::TestCircleCloneEqualsOriginalOffOriginCenter()
{
    scoped_ptr<Path_Circle> circle(CreateCircleOffOriginCenter());
    scoped_ptr<Path> clone(circle->Clone());

    AssertSamePath("Clone of circle with off origin center", circle.get(), clone.get());
}

// Write() had the same wrong plane argument as Clone(), so a circle with a
// center away from the origin did not survive a Write()/Read() round trip.
void PathTest::TestCircleWriteReadEqualsOriginalOffOriginCenter()
{
    scoped_ptr<Path_Circle> circle(CreateCircleOffOriginCenter());

    std::stringstream ss;
    circle->Write(ss);
    scoped_ptr<Path> restored(Path::Read(ss));

    AssertSamePath("Write/Read of circle with off origin center", circle.get(), restored.get());
}
