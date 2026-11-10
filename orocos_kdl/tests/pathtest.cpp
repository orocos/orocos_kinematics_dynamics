#include "pathtest.hpp"
#include <frames_io.hpp>
#include <utilities/error.h>
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

void PathTest::TestPathPoint()
{
    Frame f(Rotation::RPY(0.1, 0.2, 0.3), Vector(1, 2, 3));
    Path_Point p(f);

    CPPUNIT_ASSERT_EQUAL(Path::ID_POINT, p.getIdentifier());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, p.PathLength(), epsilon);
    CPPUNIT_ASSERT_EQUAL(f, p.Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(f, p.Pos(1.234));
    CPPUNIT_ASSERT_EQUAL(Twist::Zero(), p.Vel(0.0, 1.0));
    CPPUNIT_ASSERT_EQUAL(Twist::Zero(), p.Acc(0.0, 1.0, 1.0));
}

void PathTest::TestPathPoint_Clone()
{
    Frame f(Rotation::Identity(), Vector(1, 0, 0));
    Path_Point p(f);

    scoped_ptr<Path> p2(p.Clone());
    CPPUNIT_ASSERT_EQUAL(Path::ID_POINT, p2->getIdentifier());
    CPPUNIT_ASSERT_EQUAL(f, p2->Pos(0.0));
}

void PathTest::TestPathLine()
{
    Frame start(Rotation::Identity(), Vector(0, 0, 0));
    Frame end(Rotation::Identity(), Vector(3, 4, 0));
    Path_Line line(start, end, new RotationalInterpolation_SingleAxis(), 1.0);

    CPPUNIT_ASSERT_EQUAL(Path::ID_LINE, line.getIdentifier());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5.0, line.PathLength(), epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5.0, line.LengthToS(5.0), epsilon);

    CPPUNIT_ASSERT_EQUAL(start, line.Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(end, line.Pos(5.0));
    CPPUNIT_ASSERT_EQUAL(Vector(1.5, 2.0, 0.0), line.Pos(2.5).p);

    Twist vel = line.Vel(2.5, 2.0);
    CPPUNIT_ASSERT_EQUAL(Vector(1.2, 1.6, 0.0), vel.vel);
    CPPUNIT_ASSERT_EQUAL(Vector::Zero(), vel.rot);
}

void PathTest::TestPathLine_Clone()
{
    Frame start(Rotation::Identity(), Vector(0, 0, 0));
    Frame end(Rotation::Identity(), Vector(1, 0, 0));
    Path_Line line(start, end, new RotationalInterpolation_SingleAxis(), 1.0);

    scoped_ptr<Path> line2(line.Clone());
    CPPUNIT_ASSERT_EQUAL(Path::ID_LINE, line2->getIdentifier());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(line.PathLength(), line2->PathLength(), epsilon);
}

void PathTest::TestPathCircle()
{
    double radius = 1.0;
    double alpha = PI_2;
    Vector center(0, 0, 0);
    Frame start(Rotation::Identity(), Vector(radius, 0, 0));
    Vector plane_point(0, radius, 0);

    Path_Circle circle(start, center, plane_point, Rotation::Identity(),
                        alpha, new RotationalInterpolation_SingleAxis(), 1.0);

    CPPUNIT_ASSERT_EQUAL(Path::ID_CIRCLE, circle.getIdentifier());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(radius * alpha, circle.PathLength(), epsilon);
    CPPUNIT_ASSERT_EQUAL(start.p, circle.Pos(0.0).p);

    Frame end_pos = circle.Pos(circle.PathLength());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(radius, (end_pos.p - center).Norm(), epsilon);

    Frame mid_pos = circle.Pos(circle.PathLength() / 2);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(radius, (mid_pos.p - center).Norm(), epsilon);
}

void PathTest::TestPathCircle_TooSmall()
{
    Frame start(Rotation::Identity(), Vector(0, 0, 0));
    CPPUNIT_ASSERT_THROW(
        Path_Circle(start, Vector(0, 0, 0), Vector(0, 1, 0), Rotation::Identity(),
                    PI_2, new RotationalInterpolation_SingleAxis(), 1.0),
        Error_MotionPlanning_Circle_ToSmall);
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

void PathTest::TestPathComposite()
{
    Frame f0(Rotation::Identity(), Vector(0, 0, 0));
    Frame f1(Rotation::Identity(), Vector(3, 4, 0));
    Frame f2(Rotation::Identity(), Vector(3, 4, 4));

    Path_Composite comp;
    comp.Add(new Path_Line(f0, f1, new RotationalInterpolation_SingleAxis(), 1.0));
    comp.Add(new Path_Line(f1, f2, new RotationalInterpolation_SingleAxis(), 1.0));

    CPPUNIT_ASSERT_EQUAL(Path::ID_COMPOSITE, comp.getIdentifier());
    CPPUNIT_ASSERT_EQUAL(2, comp.GetNrOfSegments());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5.0, comp.GetLengthToEndOfSegment(0), epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(9.0, comp.GetLengthToEndOfSegment(1), epsilon);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(9.0, comp.PathLength(), epsilon);

    CPPUNIT_ASSERT_EQUAL(f0, comp.Pos(0.0));
    CPPUNIT_ASSERT_EQUAL(f1, comp.Pos(5.0));
    CPPUNIT_ASSERT_EQUAL(f2, comp.Pos(9.0));

    // LengthToS() is only applicable to non-composed paths
    CPPUNIT_ASSERT_THROW(comp.LengthToS(1.0), Error_MotionPlanning_Not_Applicable);
}

void PathTest::TestPathComposite_Clone()
{
    Frame f0(Rotation::Identity(), Vector(0, 0, 0));
    Frame f1(Rotation::Identity(), Vector(1, 0, 0));

    Path_Composite comp;
    comp.Add(new Path_Line(f0, f1, new RotationalInterpolation_SingleAxis(), 1.0));

    scoped_ptr<Path> comp2(comp.Clone());
    CPPUNIT_ASSERT_EQUAL(Path::ID_COMPOSITE, comp2->getIdentifier());
    CPPUNIT_ASSERT_EQUAL(1, static_cast<Path_Composite*>(comp2.get())->GetNrOfSegments());
}

void PathTest::TestPathRoundedComposite()
{
    Path_RoundedComposite path(0.5, 0.1, new RotationalInterpolation_SingleAxis());
    path.Add(Frame(Rotation::Identity(), Vector(0, 0, 0)));
    path.Add(Frame(Rotation::Identity(), Vector(4, 0, 0)));
    path.Add(Frame(Rotation::Identity(), Vector(4, 4, 0)));
    path.Finish();

    CPPUNIT_ASSERT_EQUAL(Path::ID_ROUNDED_COMPOSITE, path.getIdentifier());
    CPPUNIT_ASSERT_EQUAL(3, path.GetNrOfSegments());

    // rounding the corner shortens the path compared to the two unrounded
    // segments (8), but it cannot be shorter than a straight line from
    // start to end
    CPPUNIT_ASSERT(path.PathLength() > 7.0);
    CPPUNIT_ASSERT(path.PathLength() < 8.0);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, (path.Pos(0.0).p - Vector(0, 0, 0)).Norm(), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, (path.Pos(path.PathLength()).p - Vector(4, 4, 0)).Norm(), 1e-6);
}

void PathTest::TestPathCyclicClosed()
{
    Frame f0(Rotation::Identity(), Vector(0, 0, 0));
    Frame f1(Rotation::Identity(), Vector(1, 0, 0));

    Path_Cyclic_Closed cyclic(new Path_Line(f0, f1, new RotationalInterpolation_SingleAxis(), 1.0), 3);

    CPPUNIT_ASSERT_EQUAL(Path::ID_CYCLIC_CLOSED, cyclic.getIdentifier());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(3.0, cyclic.PathLength(), epsilon);
    CPPUNIT_ASSERT_EQUAL(f0, cyclic.Pos(0.0));
}
