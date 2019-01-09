#include <math.h>
#include "inertiatest.hpp"
#include <frames_io.hpp>
#include <rotationalinertia.hpp>
#include <rigidbodyinertia.hpp>
#include <articulatedbodyinertia.hpp>
#include <eigen_types.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION(InertiaTest);

using namespace KDL;

void InertiaTest::setUp()
{
}

void InertiaTest::tearDown()
{
}

void InertiaTest::TestRotationalInertia()
{
    //Check if construction works fine
    RotationalInertia I0 = RotationalInertia::Zero();
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I0.data).isZero());
    RotationalInertia I1;
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I1.data).isZero());
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I0.data).isApprox(Eigen::Map<Mat3d>(I1.data)));
    RotationalInertia I2(1, 2, 3, 4, 5, 6);

    //Check if copying works fine
    RotationalInertia I3 = I2;
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I3.data).isApprox(Eigen::Map<Mat3d>(I2.data)));
    I2.data[0] = 0.0;
    CPPUNIT_ASSERT(!Eigen::Map<Mat3d>(I3.data).isApprox(Eigen::Map<Mat3d>(I2.data)));

    //Check if addition and multiplication works fine
    Eigen::Map<Mat3d>(I0.data).setRandom();
    I1 = -2 * I0;
    CPPUNIT_ASSERT(!Eigen::Map<Mat3d>(I1.data).isZero());
    I1 = I1 + I0 + I0;
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I1.data).isZero());

    //Check if matrix is symmetric
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I2.data).isApprox(Eigen::Map<Mat3d>(I2.data).transpose()));

    //Check if angular momentum is correctly calculated:
    Vector omega;
    random(omega);
    Vector momentum = I2 * omega;

    CPPUNIT_ASSERT(Eigen::Map<Vec3d>(momentum.data).isApprox(Eigen::Map<Mat3d>(I2.data) * Eigen::Map<Vec3d>(omega.data)));
}

void InertiaTest::TestRigidBodyInertia()
{
    RigidBodyInertia I1(0.0);
    double mass;
    Vector c;
    RotationalInertia Ic;
    random(mass);
    random(c);
    Mat3d Ic_eig = Mat3d::Random();
    //make it symmetric:
    Eigen::Map<Mat3d>(Ic.data) = Ic_eig + Ic_eig.transpose();
    RigidBodyInertia I2(mass, c, Ic);
    //Check if construction works fine
    CPPUNIT_ASSERT_EQUAL(I2.getMass(), mass);
    CPPUNIT_ASSERT(!Eigen::Map<Mat3d>(I2.getRotationalInertia().data).isZero());
    CPPUNIT_ASSERT_EQUAL(I2.getCOG(), c);
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I2.getRotationalInertia().data).isApprox(Eigen::Map<Mat3d>(Ic.data) - mass * (Eigen::Map<Vec3d>(c.data) * Eigen::Map<Vec3d>(c.data).transpose() - (Eigen::Map<Vec3d>(c.data).dot(Eigen::Map<Vec3d>(c.data)) * Mat3d::Identity()))));

    RigidBodyInertia I3 = I2;
    //check if copying works fine
    CPPUNIT_ASSERT_EQUAL(I2.getMass(), I3.getMass());
    CPPUNIT_ASSERT_EQUAL(I2.getCOG(), I3.getCOG());
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I2.getRotationalInertia().data).isApprox(Eigen::Map<Mat3d>(I3.getRotationalInertia().data)));
    //Check if multiplication and addition works fine
    RigidBodyInertia I4 = -2 * I2 + I3 + I3;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(I4.getMass(), 0.0, epsilon);
    CPPUNIT_ASSERT_EQUAL(I4.getCOG(), Vector::Zero());
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I4.getRotationalInertia().data).isZero());

    //Check if transformations work fine
    //Check only rotation transformation
    //back and forward
    Rotation R;
    random(R);
    I3 = R * I2;
    I4 = R.Inverse() * I3;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(I2.getMass(), I4.getMass(), epsilon);
    CPPUNIT_ASSERT_EQUAL(I2.getCOG(), I4.getCOG());
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I2.getRotationalInertia().data).isApprox(Eigen::Map<Mat3d>(I4.getRotationalInertia().data)));
    //rotation and total with p=0
    Frame T(R);
    I4 = T * I2;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(I3.getMass(), I4.getMass(), epsilon);
    CPPUNIT_ASSERT_EQUAL(I3.getCOG(), I4.getCOG());
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I3.getRotationalInertia().data).isApprox(Eigen::Map<Mat3d>(I4.getRotationalInertia().data)));

    //Check only transformation
    Vector p;
    random(p);
    I3 = I2.RefPoint(p);
    I4 = I3.RefPoint(-p);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(I2.getMass(), I4.getMass(), epsilon);
    CPPUNIT_ASSERT_EQUAL(I2.getCOG(), I4.getCOG());
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I2.getRotationalInertia().data).isApprox(Eigen::Map<Mat3d>(I4.getRotationalInertia().data)));
    T = Frame(-p);
    I4 = T * I2;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(I3.getMass(), I4.getMass(), epsilon);
    CPPUNIT_ASSERT_EQUAL(I3.getCOG(), I4.getCOG());
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I3.getRotationalInertia().data).isApprox(Eigen::Map<Mat3d>(I4.getRotationalInertia().data)));

    random(T);
    I3 = T * I2;
    I4 = T.Inverse() * I3;

    Twist a;
    random(a);
    Wrench f = I2 * a;
    CPPUNIT_ASSERT_EQUAL(T * f, (T * I2) * (T * a));

    random(T);
    I3 = T * I2;
    I4 = T.Inverse() * I3;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(I2.getMass(), I4.getMass(), epsilon);
    CPPUNIT_ASSERT_EQUAL(I2.getCOG(), I4.getCOG());
    CPPUNIT_ASSERT(Eigen::Map<Mat3d>(I2.getRotationalInertia().data).isApprox(Eigen::Map<Mat3d>(I4.getRotationalInertia().data)));
}
void InertiaTest::TestArticulatedBodyInertia()
{
    double mass;
    Vector c;
    RotationalInertia Ic;
    random(mass);
    random(c);
    Mat3d::Map(Ic.data).triangularView<Eigen::Lower>() = Mat3d::Random().triangularView<Eigen::Lower>();
    RigidBodyInertia RBI2(mass, c, Ic);
    ArticulatedBodyInertia I2(RBI2);
    ArticulatedBodyInertia I1(mass, c, Ic);
    //Check if construction works fine
    CPPUNIT_ASSERT_EQUAL(I2.M, I1.M);
    CPPUNIT_ASSERT_EQUAL(I2.H, I1.H);
    CPPUNIT_ASSERT_EQUAL(I2.I, I1.I);
    I1 = ArticulatedBodyInertia(I2);
    CPPUNIT_ASSERT_EQUAL(I2.M, I1.M);
    CPPUNIT_ASSERT_EQUAL(I2.H, I1.H);
    CPPUNIT_ASSERT_EQUAL(I2.I, I1.I);

    //CPPUNIT_ASSERT_EQUAL(I2.M,(Mat3d::Identity()*mass).eval());
    CPPUNIT_ASSERT(!I2.I.isZero());
    //CPPUNIT_ASSERT(I2.I.isApprox(Eigen::Map<Mat3d>(Ic.data)-mass*(Eigen::Map<Vec3d>(c.data)*Eigen::Map<Vec3d>(c.data).transpose()-(Eigen::Map<Vec3d>(c.data).dot(Eigen::Map<Vec3d>(c.data))*Mat3d::Identity())),epsilon));
    //CPPUNIT_ASSERT(I2.H.isApprox(Eigen::Map<Vec3d>(c.data)*Eigen::Map<Vec3d>(c.data).transpose()-(Eigen::Map<Vec3d>(c.data).dot(Eigen::Map<Vec3d>(c.data))*Mat3d::Identity()),epsilon));
    ArticulatedBodyInertia I3 = I2;
    //check if copying works fine
    CPPUNIT_ASSERT(I2.M.isApprox(I3.M));
    CPPUNIT_ASSERT(I2.H.isApprox(I3.H));
    CPPUNIT_ASSERT(I2.I.isApprox(I3.I));
    //Check if multiplication and addition works fine
    ArticulatedBodyInertia I4 = -2 * I2 + I3 + I3;
    CPPUNIT_ASSERT(I4.M.isApprox(Mat3d::Zero().eval()));
    CPPUNIT_ASSERT(I4.H.isApprox(Mat3d::Zero().eval()));
    CPPUNIT_ASSERT(I4.I.isApprox(Mat3d::Zero().eval()));

    //Check if transformations work fine
    //Check only rotation transformation
    //back and forward
    Rotation R;
    random(R);
    I3 = R * I2;
    Eigen::Map<Mat3d> E(R.data);
    Mat3d tmp = E.transpose() * I2.M * E;
    CPPUNIT_ASSERT(I3.M.isApprox(tmp));
    tmp = E.transpose() * I2.H * E;
    CPPUNIT_ASSERT(I3.H.isApprox(tmp));
    tmp = E.transpose() * I2.I * E;
    CPPUNIT_ASSERT(I3.I.isApprox(tmp));

    I4 = R.Inverse() * I3;
    CPPUNIT_ASSERT(I2.M.isApprox(I4.M));
    CPPUNIT_ASSERT(I2.H.isApprox(I4.H));
    CPPUNIT_ASSERT(I2.I.isApprox(I4.I));
    //rotation and total with p=0
    Frame T(R);
    I4 = T * I2;
    CPPUNIT_ASSERT(I3.M.isApprox(I4.M));
    CPPUNIT_ASSERT(I3.H.isApprox(I4.H));
    CPPUNIT_ASSERT(I3.I.isApprox(I4.I));

    //Check only transformation
    Vector p;
    random(p);
    I3 = I2.RefPoint(p);
    I4 = I3.RefPoint(-p);
    CPPUNIT_ASSERT(I2.M.isApprox(I4.M));
    CPPUNIT_ASSERT(I2.H.isApprox(I4.H));
    CPPUNIT_ASSERT(I2.I.isApprox(I4.I));
    T = Frame(-p);
    I4 = T * I2;
    CPPUNIT_ASSERT(I3.M.isApprox(I4.M));
    CPPUNIT_ASSERT(I3.H.isApprox(I4.H));
    CPPUNIT_ASSERT(I3.I.isApprox(I4.I));

    random(T);
    I3 = T * I2;
    I4 = T.Inverse() * I3;

    Twist a;
    random(a);
    Wrench f = I2 * a;
    CPPUNIT_ASSERT_EQUAL(T * f, (T * I2) * (T * a));

    random(T);
    I3 = T * I2;
    I4 = T.Inverse() * I3;
    CPPUNIT_ASSERT(I2.M.isApprox(I4.M));
    CPPUNIT_ASSERT(I2.H.isApprox(I4.H));
    CPPUNIT_ASSERT(I2.I.isApprox(I4.I));
}
