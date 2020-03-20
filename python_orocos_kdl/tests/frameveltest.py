# Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

# Version: 1.0
# Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
# Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
# URL: http://www.orocos.org/kdl

# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.

# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA


from math import radians
from PyKDL import *
import sys
import unittest


class FrameVelTestFunctions(unittest.TestCase):
    def testdoubleVel(self):
        d = doubleVel()
        self.assertEqual(doubleVel(d), d)
        self.assertEqual(d.t, 0)
        self.assertEqual(d.grad, 0)
        self.assertEqual(d.value(), 0)
        self.assertEqual(d.deriv(), 0)

    def testVectorVel(self):
        v = VectorVel()
        vt = Vector()
        self.testVectorVelImpl(v, vt)
        vt = Vector(-4, -6, -8)
        self.testVectorVelImpl(v, vt)
        v1 = Vector(3, -4, 5)
        v2 = Vector(6, 3, -5)
        v = VectorVel(v1, v2)
        self.testVectorVelImpl(v, vt)

        self.assertEqual(v.p, v1)
        self.assertEqual(v.v, v2)
        self.assertEqual(v.value(), v1)
        self.assertEqual(v.deriv(), v2)

        self.assertEqual(VectorVel(v).p, v.p)
        self.assertEqual(VectorVel(v).v, v.v)
        self.assertFalse(v == -v)  # Doesn't work for zero VectorVel
        self.assertFalse(Equal(v, -v))  # Doesn't work for zero VectorVel
        self.assertTrue(v != -v)  # Doesn't work for zero VectorVel
        self.assertTrue(not Equal(v, -v))  # Doesn't work for zero VectorVel

        v = VectorVel(v1)
        self.assertEqual(v, v1)
        self.assertEqual(v1, v)

        v = VectorVel(v1, v2)
        SetToZero(v)
        self.assertEqual(v, VectorVel())
        self.assertEqual(VectorVel.Zero(), VectorVel())

        v = VectorVel(v1, v2)
        self.assertEqual(dot(v, v), doubleVel(dot(v.p, v.p), dot(v.p, v.v)+dot(v.v, v.p)))
        dot_result = doubleVel(dot(v.p, v1), dot(v.v, v1))
        self.assertEqual(dot(v, v1), dot_result)
        self.assertEqual(dot(v1, v), dot_result)

    def testVectorVelImpl(self, v, vt):
        self.assertTrue(Equal(2*v-v, v))
        self.assertTrue(Equal(v*2-v, v))
        self.assertTrue(Equal(v+v+v-2*v, v))
        v2 = VectorVel(v)
        self.assertTrue(Equal(v, v2))
        v2 += v
        self.assertTrue(Equal(2*v, v2))
        v2 -= v
        self.assertTrue(Equal(v, v2))
        v2.ReverseSign()
        self.assertTrue(Equal(v, -v2))
        self.assertTrue(Equal(v*vt, -vt*v))
        v2 = VectorVel(Vector(-5, -6, -3), Vector(3, 4, 5))
        self.assertTrue(Equal(v*v2, -v2*v))

    def testTwistVel(self):
        t = TwistVel()
        self.testTwistVelImpl(t)
        v1 = Vector(1, 2, 3)
        v2 = Vector(4, 5, 6)
        vv1 = VectorVel(v1, v2)
        vv2 = VectorVel(v2, v1)
        t = TwistVel(vv1, vv2)
        self.testTwistVelImpl(t)

        # Alternative constructor
        tw1 = Twist(v1, v2)
        tw2 = Twist(v2, v1)
        t2 = TwistVel(tw1, tw2)
        self.assertEqual(t, t2)

        # Members
        self.assertEqual(t.vel, vv1)
        self.assertEqual(t.rot, vv2)
        self.assertEqual(t2.value(), tw1)
        self.assertEqual(t2.deriv(), tw2)
        self.assertEqual(t2.GetTwist(), tw1)
        self.assertEqual(t2.GetTwistDot(), tw2)

        # Equality
        self.assertEqual(TwistVel(t).vel, t.vel)
        self.assertEqual(TwistVel(t).rot, t.rot)
        self.assertFalse(t == -t)  # Doesn't work for zero TwistVel
        self.assertFalse(Equal(t, -t))  # Doesn't work for zero TwistVel
        self.assertTrue(t != -t)  # Doesn't work for zero TwistVel
        self.assertTrue(not Equal(t, -t))  # Doesn't work for zero TwistVel

        t = TwistVel(VectorVel(v1), VectorVel(v2))
        t2 = Twist(v1, v2)
        self.assertEqual(t, t2)
        self.assertEqual(t2, t)

        # Zero
        SetToZero(t)
        self.assertEqual(t, TwistVel())
        self.assertEqual(TwistVel.Zero(), TwistVel())

    def testTwistVelImpl(self, t):
        self.assertTrue(Equal(2*t-t, t))
        self.assertTrue(Equal(t*2-t, t))
        self.assertTrue(Equal(t+t+t-2*t, t))
        t2 = TwistVel(t)
        self.assertTrue(Equal(t, t2))
        t2 += t
        self.assertTrue(Equal(2*t, t2))
        t2 -= t
        self.assertTrue(Equal(t, t2))
        t2.ReverseSign()
        self.assertTrue(t, -t2)
        self.assertTrue(t*doubleVel(), doubleVel()*t)
        self.assertTrue(t*doubleVel(5), doubleVel(5)*t)

    def testRotationVel(self):
        v = VectorVel(Vector(9, 4, -2), Vector(-5, 6, -2))
        vt = Vector(2, 3, 4)
        a = radians(-15)
        b = radians(20)
        c = radians(-80)
        R = RotationVel(Rotation.RPY(a, b, c), Vector(2, 4, 1))
        R2 = RotationVel(R)
        self.assertTrue(Equal(R, R2))
        self.assertTrue(Equal((R*v).Norm(), (v.Norm())))
        self.assertTrue(Equal(R.Inverse(R*v), v))
        self.assertTrue(Equal(R*R.Inverse(v), v))
        self.assertTrue(Equal(R*Rotation.Identity(), R))
        self.assertTrue(Equal(Rotation.Identity()*R, R))
        self.assertTrue(Equal(R*(R*(R*v)), (R*R*R)*v))
        self.assertTrue(Equal(R*(R*(R*vt)), (R*R*R)*vt))
        self.assertTrue(Equal(R*R.Inverse(), RotationVel.Identity()))
        self.assertTrue(Equal(R.Inverse()*R, RotationVel.Identity()))
        self.assertTrue(Equal(R.Inverse()*v, R.Inverse(v)))

    def testFrameVel(self):
        v = VectorVel(Vector(3, 4, 5), Vector(-2, -4, -1))
        vt = Vector(-1, 0, -10)
        F = FrameVel(Frame(Rotation.EulerZYX(radians(10), radians(20), radians(-10)), Vector(4, -2, 1)),
                     Twist(Vector(2, -2, -2), Vector(-5, -3, -2)))
        F2 = FrameVel(F)
        self.assertTrue(Equal(F, F2))
        self.assertTrue(Equal(F.Inverse(F*v), v))
        self.assertTrue(Equal(F.Inverse(F*vt), vt))
        self.assertTrue(Equal(F*F.Inverse(v), v))
        self.assertTrue(Equal(F*F.Inverse(vt), vt))
        self.assertTrue(Equal(F*Frame.Identity(), F))
        self.assertTrue(Equal(Frame.Identity()*F, F))
        self.assertTrue(Equal(F*(F*(F*v)), (F*F*F)*v))
        self.assertTrue(Equal(F*(F*(F*vt)), (F*F*F)*vt))
        self.assertTrue(Equal(F*F.Inverse(), FrameVel.Identity()))
        self.assertTrue(Equal(F.Inverse()*F, Frame.Identity()))
        self.assertTrue(Equal(F.Inverse()*vt, F.Inverse(vt)))

    def testPickle(self):
        if sys.version_info < (3, 0):
            import cPickle as pickle
        else:
            import pickle
        data = {}
        data['vv'] = VectorVel(Vector(1, 2, 3), Vector(4, 5, 6))
        data['rv'] = RotationVel(Rotation.RotX(1.3), Vector(4.1, 5.1, 6.1))
        data['fv'] = FrameVel(data['rv'], data['vv'])
        data['tv'] = TwistVel(data['vv'], data['vv'])

        with open('/tmp/pickle_test_kdl_framevel', 'w') as f:
            pickle.dump(data, f, 2)

        with open('/tmp/pickle_test_kdl_framevel', 'r') as f:
            data1 = pickle.load(f)

        self.assertEqual(data, data1)


def suite():
    suite = unittest.TestSuite()
    suite.addTest(FrameVelTestFunctions('testdoubleVel'))
    suite.addTest(FrameVelTestFunctions('testVectorVel'))
    suite.addTest(FrameVelTestFunctions('testTwistVel'))
    suite.addTest(FrameVelTestFunctions('testRotationVel'))
    suite.addTest(FrameVelTestFunctions('testFrameVel'))
    suite.addTest(FrameVelTestFunctions('testPickle'))
    return suite


if __name__ == '__main__':
    suite = suite()
    result = unittest.TextTestRunner(verbosity=3).run(suite)

    if result.wasSuccessful():
        sys.exit(0)
    else:
        sys.exit(1)
