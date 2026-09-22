# Copyright  (C)  2024  Matthijs van der Burgh <MatthijsBurgh at outlook dot com>

# Version: 1.0
# Author: Matthijs van der Burgh <MatthijsBurgh at outlook dot com>
# Maintainer: Ruben Smits <ruben dot smits at intermodalics dot eu>
# Maintainer: Matthijs van der Burgh <MatthijsBurgh at outlook dot com>
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


from math import pi
from PyKDL import *
import copy
import unittest


# Absolute tolerance used for the (mostly exact) closed form results below.
EPS = 1e-9


class VelocityProfileDiracTest(unittest.TestCase):
    def testSetProfile(self):
        pos1 = 10.0
        pos2 = -1.0
        vp = VelocityProfile_Dirac()
        vp.SetProfile(pos1, pos2)

        # without an explicit duration the profile is an instantaneous jump
        self.assertAlmostEqual(vp.Duration(), 0.0, delta=EPS)
        self.assertAlmostEqual(vp.Pos(-1.0), pos1, delta=EPS)
        self.assertAlmostEqual(vp.Pos(0.0), pos1, delta=EPS)
        self.assertAlmostEqual(vp.Pos(0.1), pos2, delta=EPS)
        self.assertAlmostEqual(vp.Pos(1.0), pos2, delta=EPS)

        # velocity/acceleration are not defined for an instantaneous jump
        with self.assertRaises(RuntimeError):
            vp.Vel(0.0)
        with self.assertRaises(RuntimeError):
            vp.Acc(0.0)

    def testSetProfileDuration(self):
        pos1 = 10.0
        pos2 = -1.0
        duration = 5.0
        vp = VelocityProfile_Dirac()
        vp.SetProfileDuration(pos1, pos2, duration)

        self.assertAlmostEqual(vp.Duration(), duration, delta=EPS)

        self.assertAlmostEqual(vp.Pos(-1.0), pos1, delta=EPS)
        self.assertAlmostEqual(vp.Vel(-1.0), 0.0, delta=EPS)

        self.assertAlmostEqual(vp.Pos(duration / 2), (pos1 + pos2) / 2, delta=EPS)
        self.assertAlmostEqual(vp.Vel(duration / 2), (pos2 - pos1) / duration, delta=EPS)

        self.assertAlmostEqual(vp.Pos(duration), pos2, delta=EPS)

        self.assertAlmostEqual(vp.Pos(duration + 1.0), pos2, delta=EPS)
        self.assertAlmostEqual(vp.Vel(duration + 1.0), 0.0, delta=EPS)

        # acceleration is never defined for VelocityProfile_Dirac
        with self.assertRaises(RuntimeError):
            vp.Acc(duration / 2)

    def testCopy(self):
        vp = VelocityProfile_Dirac()
        vp.SetProfileDuration(0.0, 2.0, 1.0)

        vp2 = copy.copy(vp)
        self.assertIsInstance(vp2, VelocityProfile_Dirac)
        self.assertIsNot(vp, vp2)
        self.assertAlmostEqual(vp2.Duration(), 1.0, delta=EPS)
        self.assertAlmostEqual(vp2.Pos(0.5), 1.0, delta=EPS)

        vp3 = copy.deepcopy(vp)
        self.assertIsInstance(vp3, VelocityProfile_Dirac)
        self.assertIsNot(vp, vp3)
        self.assertAlmostEqual(vp3.Duration(), 1.0, delta=EPS)


class VelocityProfileRectangularTest(unittest.TestCase):
    def testSetProfile(self):
        vp = VelocityProfile_Rectangular(2.0)
        vp.SetProfile(0.0, 10.0)

        self.assertAlmostEqual(vp.Duration(), 5.0, delta=EPS)

        self.assertAlmostEqual(vp.Pos(-1.0), 0.0, delta=EPS)
        self.assertAlmostEqual(vp.Pos(0.0), 0.0, delta=EPS)
        self.assertAlmostEqual(vp.Pos(2.5), 5.0, delta=EPS)
        self.assertAlmostEqual(vp.Pos(5.0), 10.0, delta=EPS)
        self.assertAlmostEqual(vp.Pos(6.0), 10.0, delta=EPS)

        self.assertAlmostEqual(vp.Vel(-1.0), 0.0, delta=EPS)
        self.assertAlmostEqual(vp.Vel(2.5), 2.0, delta=EPS)
        self.assertAlmostEqual(vp.Vel(6.0), 0.0, delta=EPS)

        # acceleration is never defined for a rectangular profile
        with self.assertRaises(RuntimeError):
            vp.Acc(2.5)

    def testSetProfileReverse(self):
        vp = VelocityProfile_Rectangular(2.0)
        vp.SetProfile(10.0, 0.0)

        self.assertAlmostEqual(vp.Duration(), 5.0, delta=EPS)
        self.assertAlmostEqual(vp.Vel(2.5), -2.0, delta=EPS)
        self.assertAlmostEqual(vp.Pos(5.0), 0.0, delta=EPS)

    def testSetMax(self):
        vp = VelocityProfile_Rectangular()
        vp.SetMax(5.0)
        vp.SetProfile(0.0, 10.0)

        self.assertAlmostEqual(vp.Duration(), 2.0, delta=EPS)
        self.assertAlmostEqual(vp.Vel(1.0), 5.0, delta=EPS)

    def testSetProfileDuration(self):
        vp = VelocityProfile_Rectangular(5.0)
        vp.SetProfileDuration(0.0, 10.0, 10.0)

        self.assertAlmostEqual(vp.Duration(), 10.0, delta=EPS)
        self.assertAlmostEqual(vp.Vel(5.0), 1.0, delta=EPS)
        self.assertAlmostEqual(vp.Pos(10.0), 10.0, delta=EPS)

    def testCopy(self):
        vp = VelocityProfile_Rectangular(2.0)
        vp.SetProfile(0.0, 10.0)

        vp2 = copy.copy(vp)
        self.assertIsInstance(vp2, VelocityProfile_Rectangular)
        self.assertIsNot(vp, vp2)
        self.assertAlmostEqual(vp2.Duration(), vp.Duration(), delta=EPS)
        self.assertAlmostEqual(vp2.Pos(2.5), vp.Pos(2.5), delta=EPS)


class VelocityProfileTrapTest(unittest.TestCase):
    def testMaxVelocity1(self):
        # 2 second ramp up (cover 2 distance),
        # 2 second flat velocity (cover 4 distance)
        # 2 second ramp down (cover 2 distance)
        v = VelocityProfile_Trap(2, 1)
        v.SetProfile(2, 10)
        self.assertAlmostEqual(v.Duration(), 6.0, delta=EPS)

        # start
        self.assertAlmostEqual(v.Pos(0), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(0), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(0), 1.0, delta=EPS)

        # end of ramp up
        self.assertAlmostEqual(v.Pos(2), 4.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(2), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(2), 0.0, delta=EPS)

        # middle of flat velocity
        self.assertAlmostEqual(v.Pos(3), 6.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(3), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(3), 0.0, delta=EPS)

        # end of flat velocity
        self.assertAlmostEqual(v.Pos(4), 8.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(4), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(4), -1.0, delta=EPS)

        # middle of ramp down
        self.assertAlmostEqual(v.Pos(5), 9.5, delta=EPS)
        self.assertAlmostEqual(v.Vel(5), 1.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(5), -1.0, delta=EPS)

        # end
        self.assertAlmostEqual(v.Pos(6), 10.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(6), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(6), -1.0, delta=EPS)

        # fenceposts - before and after
        self.assertAlmostEqual(v.Pos(-1), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(-1), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(-1), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Pos(11), 10.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(11), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(11), 0.0, delta=EPS)

    def testMaxVelocity2(self):
        # 2 second ramp up (cover -2 distance),
        # 2 second flat velocity (cover -4 distance)
        # 2 second ramp down (cover -2 distance)
        v = VelocityProfile_Trap(2, 1)
        v.SetProfile(2, -6)
        self.assertAlmostEqual(v.Duration(), 6.0, delta=EPS)

    def testMaxVelocity3(self):
        # 2 second ramp up (cover 4 distance),
        # 0 second flat velocity (cover 0 distance)
        # 2 second ramp down (cover 4 distance)
        v = VelocityProfile_Trap(4, 2)
        v.SetProfile(2, 10)
        self.assertAlmostEqual(v.Duration(), 4.0, delta=EPS)

        # new profile
        v.SetProfile(2, -6)
        self.assertAlmostEqual(v.Duration(), 4.0, delta=EPS)

        # another new profile: ramp + 2 sec + ramp
        v.SetProfile(13, 13 + 4 + 8 + 4)
        self.assertAlmostEqual(v.Duration(), 6.0, delta=EPS)

    def testSetProfileDuration(self):
        # same as MaxVelocity1, but twice as long (max velocity gives 6 seconds)
        v = VelocityProfile_Trap(2, 1)
        v.SetProfileDuration(2, 10, 12.0)
        self.assertAlmostEqual(v.Duration(), 12.0, delta=EPS)

        self.assertAlmostEqual(v.Pos(0), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(0), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(0), 0.25, delta=EPS)

        self.assertAlmostEqual(v.Pos(4), 4.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(4), 1.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(4), 0.0, delta=EPS)

        self.assertAlmostEqual(v.Pos(6), 6.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(6), 1.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(6), 0.0, delta=EPS)

        self.assertAlmostEqual(v.Pos(8), 8.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(8), 1.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(8), -0.25, delta=EPS)

        self.assertAlmostEqual(v.Pos(10), 9.5, delta=EPS)
        self.assertAlmostEqual(v.Vel(10), 0.5, delta=EPS)
        self.assertAlmostEqual(v.Acc(10), -0.25, delta=EPS)

        self.assertAlmostEqual(v.Pos(12), 10.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(12), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(12), -0.25, delta=EPS)

    def testSetProfileVelocity(self):
        # SetProfileVelocity() scales the full-speed profile by a factor in
        # ]0, 1] (it does NOT take an absolute velocity), which stretches
        # the duration by 1 / factor while keeping start/end positions fixed.
        v = VelocityProfile_Trap(2, 1)
        v.SetProfile(0, 10)
        full_duration = v.Duration()
        self.assertAlmostEqual(full_duration, 7.0, delta=EPS)

        v.SetProfileVelocity(0, 10, 0.5)
        self.assertAlmostEqual(v.Duration(), full_duration / 0.5, delta=EPS)
        self.assertAlmostEqual(v.Pos(0.0), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Pos(v.Duration()), 10.0, delta=EPS)

    def testCopy(self):
        v = VelocityProfile_Trap(2, 1)
        v.SetProfile(2, 10)

        v2 = copy.copy(v)
        self.assertIsInstance(v2, VelocityProfile_Trap)
        self.assertIsNot(v, v2)
        self.assertAlmostEqual(v2.Duration(), v.Duration(), delta=EPS)
        self.assertAlmostEqual(v2.Pos(3), v.Pos(3), delta=EPS)


class VelocityProfileTrapHalfTest(unittest.TestCase):
    def testSetProfileStart(self):
        # 2 second ramp up (cover 2 distance),
        # 2 second flat velocity (cover 4 distance)
        v = VelocityProfile_TrapHalf(2, 1, True)
        v.SetProfile(2, 2 + 6)
        self.assertAlmostEqual(v.Duration(), 4.0, delta=EPS)

        # start
        self.assertAlmostEqual(v.Pos(0), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(0), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(0), 1.0, delta=EPS)

        # end of ramp up
        self.assertAlmostEqual(v.Pos(2), 4.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(2), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(2), 0.0, delta=EPS)

        # middle of flat velocity
        self.assertAlmostEqual(v.Pos(3), 6.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(3), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(3), 0.0, delta=EPS)

        # end
        self.assertAlmostEqual(v.Pos(4), 8.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(4), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(4), 0.0, delta=EPS)

        # fenceposts - before and after
        self.assertAlmostEqual(v.Pos(-1), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(-1), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(-1), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Pos(5), 8.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(5), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(5), 0.0, delta=EPS)

    def testSetProfileEnd(self):
        # 2 second flat velocity (cover 4 distance)
        # 2 second ramp up (cover 2 distance)
        v = VelocityProfile_TrapHalf(2, 1, False)
        v.SetProfile(9, 9 - 6)
        self.assertAlmostEqual(v.Duration(), 4.0, delta=EPS)

        # start - flat velocity
        self.assertAlmostEqual(v.Pos(0), 9.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(0), -2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(0), 0.0, delta=EPS)

        # end of flat velocity
        self.assertAlmostEqual(v.Pos(2), 5.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(2), -2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(2), 1.0, delta=EPS)

        # middle of ramp down
        self.assertAlmostEqual(v.Pos(3), 3.5, delta=EPS)
        self.assertAlmostEqual(v.Vel(3), -1.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(3), 1.0, delta=EPS)

        # end
        self.assertAlmostEqual(v.Pos(4), 3.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(4), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(4), 0.0, delta=EPS)

        # fenceposts - before and after
        self.assertAlmostEqual(v.Pos(-1), 9.0, delta=EPS)
        self.assertAlmostEqual(v.Pos(5), 3.0, delta=EPS)

    def testSetDurationStart(self):
        # same as testSetProfileStart() but twice as slow: lingers at the
        # start position with zero velocity, then ramps with a lower,
        # scaled acceleration
        v = VelocityProfile_TrapHalf(2, 1, True)
        v.SetProfileDuration(2, 2 + 6, 8)
        self.assertAlmostEqual(v.Duration(), 8.0, delta=EPS)

        # start - no motion
        self.assertAlmostEqual(v.Pos(0), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(0), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(0), 0.0, delta=EPS)

        # no motion
        self.assertAlmostEqual(v.Pos(1.9), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(1.9), 0.0, delta=EPS)

        # begin ramp at scaled acceleration
        self.assertAlmostEqual(v.Pos(2), 2.0, delta=0.001)
        self.assertAlmostEqual(v.Vel(2), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(2), 0.333, delta=0.001)

        # middle of ramp up
        self.assertAlmostEqual(v.Pos(5), 3.5, delta=0.001)
        self.assertAlmostEqual(v.Vel(5), 1.0, delta=0.001)
        self.assertAlmostEqual(v.Acc(5), 0.3333, delta=0.001)

        # end - continue with given velocity
        self.assertAlmostEqual(v.Pos(8), 8.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(8), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(8), 0.0, delta=EPS)

        # fenceposts - before and after
        self.assertAlmostEqual(v.Pos(-1), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Pos(9), 8.0, delta=EPS)

    def testSetDurationEnd(self):
        v = VelocityProfile_TrapHalf(2, 1, True)
        v.SetProfileDuration(2 + 6, 2, 8)
        self.assertAlmostEqual(v.Duration(), 8.0, delta=EPS)

        # start - no motion
        self.assertAlmostEqual(v.Pos(0), 8.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(0), 0.0, delta=EPS)

        # no motion
        self.assertAlmostEqual(v.Pos(1.9), 8.0, delta=EPS)

        # begin ramp at scaled acceleration (backwards)
        self.assertAlmostEqual(v.Pos(2), 8.0, delta=0.001)
        self.assertAlmostEqual(v.Vel(2), 0.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(2), -0.333, delta=0.001)

        # middle of ramp
        self.assertAlmostEqual(v.Pos(5), 6.5, delta=0.001)
        self.assertAlmostEqual(v.Vel(5), -1.0, delta=0.001)
        self.assertAlmostEqual(v.Acc(5), -0.3333, delta=0.001)

        # end - continue with given velocity
        self.assertAlmostEqual(v.Pos(8), 2.0, delta=EPS)
        self.assertAlmostEqual(v.Vel(8), -2.0, delta=EPS)
        self.assertAlmostEqual(v.Acc(8), 0.0, delta=EPS)

        # fenceposts - before and after
        self.assertAlmostEqual(v.Pos(-1), 8.0, delta=EPS)
        self.assertAlmostEqual(v.Pos(9), 2.0, delta=EPS)

    def testCopy(self):
        v = VelocityProfile_TrapHalf(2, 1, True)
        v.SetProfile(2, 8)

        v2 = copy.copy(v)
        self.assertIsInstance(v2, VelocityProfile_TrapHalf)
        self.assertIsNot(v, v2)
        self.assertAlmostEqual(v2.Duration(), v.Duration(), delta=EPS)


class VelocityProfileSplineTest(unittest.TestCase):
    def testCubic(self):
        pos1, vel1 = 0.0, 1.0
        pos2, vel2 = 10.0, -1.0
        duration = 4.0

        v = VelocityProfile_Spline()
        v.SetProfileDuration(pos1, vel1, pos2, vel2, duration)

        self.assertAlmostEqual(v.Duration(), duration, delta=EPS)
        self.assertAlmostEqual(v.Pos(0.0), pos1, delta=EPS)
        self.assertAlmostEqual(v.Vel(0.0), vel1, delta=EPS)
        self.assertAlmostEqual(v.Pos(duration), pos2, delta=1e-6)
        self.assertAlmostEqual(v.Vel(duration), vel2, delta=1e-6)

    def testQuintic(self):
        pos1, vel1, acc1 = 0.0, 0.0, 0.0
        pos2, vel2, acc2 = 10.0, 0.0, 0.0
        duration = 5.0

        v = VelocityProfile_Spline()
        v.SetProfileDuration(pos1, vel1, acc1, pos2, vel2, acc2, duration)

        self.assertAlmostEqual(v.Duration(), duration, delta=EPS)
        self.assertAlmostEqual(v.Pos(0.0), pos1, delta=EPS)
        self.assertAlmostEqual(v.Vel(0.0), vel1, delta=EPS)
        self.assertAlmostEqual(v.Acc(0.0), acc1, delta=EPS)
        self.assertAlmostEqual(v.Pos(duration), pos2, delta=1e-6)
        self.assertAlmostEqual(v.Vel(duration), vel2, delta=1e-6)
        self.assertAlmostEqual(v.Acc(duration), acc2, delta=1e-6)

    def testCopy(self):
        v = VelocityProfile_Spline()
        v.SetProfileDuration(0.0, 1.0, 10.0, -1.0, 4.0)

        v2 = copy.copy(v)
        self.assertIsInstance(v2, VelocityProfile_Spline)
        self.assertIsNot(v, v2)
        self.assertAlmostEqual(v2.Pos(2.0), v.Pos(2.0), delta=EPS)


class RotationalInterpolationSingleAxisTest(unittest.TestCase):
    def testSetStartEnd(self):
        start = Rotation.Identity()
        end = Rotation.RotZ(pi / 2)

        ri = RotationalInterpolation_SingleAxis()
        ri.SetStartEnd(start, end)

        self.assertAlmostEqual(ri.Angle(), pi / 2, delta=EPS)
        self.assertTrue(Equal(ri.Pos(0.0), start))
        self.assertTrue(Equal(ri.Pos(ri.Angle()), end))

        # rotating purely about the z-axis
        vel = ri.Vel(0.0, 1.0)
        self.assertTrue(Equal(vel, Vector(0.0, 0.0, 1.0)))

    def testCopy(self):
        ri = RotationalInterpolation_SingleAxis()
        ri.SetStartEnd(Rotation.Identity(), Rotation.RotZ(pi / 2))

        ri2 = copy.copy(ri)
        self.assertIsInstance(ri2, RotationalInterpolation_SingleAxis)
        self.assertIsNot(ri, ri2)
        self.assertAlmostEqual(ri2.Angle(), ri.Angle(), delta=EPS)


class PathPointTest(unittest.TestCase):
    def testBasic(self):
        f = Frame(Rotation.RPY(0.1, 0.2, 0.3), Vector(1, 2, 3))
        p = Path_Point(f)

        self.assertEqual(p.getIdentifier(), Path.ID_POINT)
        self.assertAlmostEqual(p.PathLength(), 0.0, delta=EPS)
        self.assertTrue(Equal(p.Pos(0.0), f))
        self.assertTrue(Equal(p.Pos(1.234), f))
        self.assertTrue(Equal(p.Vel(0.0, 1.0), Twist.Zero()))
        self.assertTrue(Equal(p.Acc(0.0, 1.0, 1.0), Twist.Zero()))

    def testCopy(self):
        f = Frame(Rotation.Identity(), Vector(1, 0, 0))
        p = Path_Point(f)

        p2 = copy.copy(p)
        self.assertIsInstance(p2, Path_Point)
        self.assertIsNot(p, p2)
        self.assertTrue(Equal(p2.Pos(0.0), f))


class PathLineTest(unittest.TestCase):
    def testStraightLine(self):
        start = Frame(Rotation.Identity(), Vector(0, 0, 0))
        end = Frame(Rotation.Identity(), Vector(3, 4, 0))
        line = Path_Line(start, end, RotationalInterpolation_SingleAxis(), 1.0)

        self.assertEqual(line.getIdentifier(), Path.ID_LINE)
        self.assertAlmostEqual(line.PathLength(), 5.0, delta=EPS)
        self.assertAlmostEqual(line.LengthToS(5.0), 5.0, delta=EPS)

        self.assertTrue(Equal(line.Pos(0.0), start))
        self.assertTrue(Equal(line.Pos(5.0), end))
        self.assertTrue(Equal(line.Pos(2.5).p, Vector(1.5, 2.0, 0.0)))

        vel = line.Vel(2.5, 2.0)
        self.assertTrue(Equal(vel.vel, Vector(1.2, 1.6, 0.0)))
        self.assertTrue(Equal(vel.rot, Vector.Zero()))

    def testCopy(self):
        start = Frame(Rotation.Identity(), Vector(0, 0, 0))
        end = Frame(Rotation.Identity(), Vector(1, 0, 0))
        line = Path_Line(start, end, RotationalInterpolation_SingleAxis(), 1.0)

        line2 = copy.copy(line)
        self.assertIsInstance(line2, Path_Line)
        self.assertIsNot(line, line2)
        self.assertAlmostEqual(line2.PathLength(), line.PathLength(), delta=EPS)


class PathCircleTest(unittest.TestCase):
    def testQuarterCircle(self):
        radius = 1.0
        alpha = pi / 2
        center = Vector(0, 0, 0)
        start = Frame(Rotation.Identity(), Vector(radius, 0, 0))
        plane_point = Vector(0, radius, 0)

        circle = Path_Circle(start, center, plane_point, Rotation.Identity(),
                              alpha, RotationalInterpolation_SingleAxis(), 1.0)

        self.assertEqual(circle.getIdentifier(), Path.ID_CIRCLE)
        self.assertAlmostEqual(circle.PathLength(), radius * alpha, delta=EPS)
        self.assertTrue(Equal(circle.Pos(0.0).p, start.p))

        end_pos = circle.Pos(circle.PathLength())
        self.assertAlmostEqual((end_pos.p - center).Norm(), radius, delta=EPS)

        mid_pos = circle.Pos(circle.PathLength() / 2)
        self.assertAlmostEqual((mid_pos.p - center).Norm(), radius, delta=EPS)

    def testCircleTooSmall(self):
        start = Frame(Rotation.Identity(), Vector(0, 0, 0))
        with self.assertRaises(RuntimeError):
            Path_Circle(start, Vector(0, 0, 0), Vector(0, 1, 0), Rotation.Identity(),
                        pi / 2, RotationalInterpolation_SingleAxis(), 1.0)

    def testCopy(self):
        start = Frame(Rotation.Identity(), Vector(1, 0, 0))
        circle = Path_Circle(start, Vector(0, 0, 0), Vector(0, 1, 0), Rotation.Identity(),
                              pi / 2, RotationalInterpolation_SingleAxis(), 1.0)

        circle2 = copy.copy(circle)
        self.assertIsInstance(circle2, Path_Circle)
        self.assertIsNot(circle, circle2)
        self.assertAlmostEqual(circle2.PathLength(), circle.PathLength(), delta=EPS)


class PathCompositeTest(unittest.TestCase):
    def testComposite(self):
        f0 = Frame(Rotation.Identity(), Vector(0, 0, 0))
        f1 = Frame(Rotation.Identity(), Vector(3, 4, 0))
        f2 = Frame(Rotation.Identity(), Vector(3, 4, 4))

        line1 = Path_Line(f0, f1, RotationalInterpolation_SingleAxis(), 1.0)
        line2 = Path_Line(f1, f2, RotationalInterpolation_SingleAxis(), 1.0)

        comp = Path_Composite()
        comp.Add(line1)
        comp.Add(line2)

        self.assertEqual(comp.getIdentifier(), Path.ID_COMPOSITE)
        self.assertEqual(comp.GetNrOfSegments(), 2)
        self.assertAlmostEqual(comp.GetLengthToEndOfSegment(0), 5.0, delta=EPS)
        self.assertAlmostEqual(comp.GetLengthToEndOfSegment(1), 9.0, delta=EPS)
        self.assertAlmostEqual(comp.PathLength(), 9.0, delta=EPS)

        self.assertTrue(Equal(comp.Pos(0.0), f0))
        self.assertTrue(Equal(comp.Pos(5.0), f1))
        self.assertTrue(Equal(comp.Pos(9.0), f2))

        # LengthToS() is only applicable to non-composed paths
        with self.assertRaises(RuntimeError):
            comp.LengthToS(1.0)

    def testCopy(self):
        f0 = Frame(Rotation.Identity(), Vector(0, 0, 0))
        f1 = Frame(Rotation.Identity(), Vector(1, 0, 0))
        line = Path_Line(f0, f1, RotationalInterpolation_SingleAxis(), 1.0)

        comp = Path_Composite()
        comp.Add(line)

        comp2 = copy.copy(comp)
        self.assertIsInstance(comp2, Path_Composite)
        self.assertIsNot(comp, comp2)
        self.assertEqual(comp2.GetNrOfSegments(), 1)


class PathRoundedCompositeTest(unittest.TestCase):
    def testRoundedCorner(self):
        path = Path_RoundedComposite(0.5, 0.1, RotationalInterpolation_SingleAxis())
        path.Add(Frame(Rotation.Identity(), Vector(0, 0, 0)))
        path.Add(Frame(Rotation.Identity(), Vector(4, 0, 0)))
        path.Add(Frame(Rotation.Identity(), Vector(4, 4, 0)))
        path.Finish()

        self.assertEqual(path.getIdentifier(), Path.ID_ROUNDED_COMPOSITE)
        self.assertEqual(path.GetNrOfSegments(), 3)

        # rounding the corner shortens the path compared to the two
        # unrounded segments (8), but it cannot be shorter than a straight
        # line from start to end
        self.assertTrue(7.0 < path.PathLength() < 8.0)

        self.assertTrue(Equal(path.Pos(0.0).p, Vector(0, 0, 0), 1e-6))
        self.assertTrue(Equal(path.Pos(path.PathLength()).p, Vector(4, 4, 0), 1e-6))


class PathCyclicClosedTest(unittest.TestCase):
    def testCyclic(self):
        f0 = Frame(Rotation.Identity(), Vector(0, 0, 0))
        f1 = Frame(Rotation.Identity(), Vector(1, 0, 0))
        line = Path_Line(f0, f1, RotationalInterpolation_SingleAxis(), 1.0)

        cyclic = Path_Cyclic_Closed(line, 3)

        self.assertEqual(cyclic.getIdentifier(), Path.ID_CYCLIC_CLOSED)
        self.assertAlmostEqual(cyclic.PathLength(), 3.0, delta=EPS)
        self.assertTrue(Equal(cyclic.Pos(0.0), f0))


class TrajectoryStationaryTest(unittest.TestCase):
    def testBasic(self):
        f = Frame(Rotation.Identity(), Vector(1, 2, 3))
        traj = Trajectory_Stationary(5.0, f)

        self.assertAlmostEqual(traj.Duration(), 5.0, delta=EPS)
        self.assertTrue(Equal(traj.Pos(0.0), f))
        self.assertTrue(Equal(traj.Pos(2.5), f))
        self.assertTrue(Equal(traj.Vel(1.0), Twist.Zero()))
        self.assertTrue(Equal(traj.Acc(1.0), Twist.Zero()))

    def testCopy(self):
        f = Frame(Rotation.Identity(), Vector(1, 2, 3))
        traj = Trajectory_Stationary(5.0, f)

        traj2 = copy.copy(traj)
        self.assertIsInstance(traj2, Trajectory_Stationary)
        self.assertIsNot(traj, traj2)
        self.assertAlmostEqual(traj2.Duration(), 5.0, delta=EPS)
        self.assertTrue(Equal(traj2.Pos(0.0), f))


class TrajectorySegmentTest(unittest.TestCase):
    def testWithDuration(self):
        start = Frame(Rotation.Identity(), Vector(0, 0, 0))
        end = Frame(Rotation.Identity(), Vector(3, 4, 0))
        path = Path_Line(start, end, RotationalInterpolation_SingleAxis(), 1.0)
        vel_profile = VelocityProfile_Trap(2.0, 1.0)

        # this constructor configures vel_profile for us: [0, path.PathLength()]
        # in the requested duration
        traj = Trajectory_Segment(path, vel_profile, 10.0)

        self.assertAlmostEqual(traj.Duration(), 10.0, delta=EPS)
        self.assertTrue(Equal(traj.Pos(0.0), start))
        self.assertTrue(Equal(traj.Pos(10.0), end))

        self.assertAlmostEqual(traj.GetPath().PathLength(), 5.0, delta=EPS)
        self.assertAlmostEqual(traj.GetProfile().Duration(), 10.0, delta=EPS)

    def testWithoutDuration(self):
        start = Frame(Rotation.Identity(), Vector(0, 0, 0))
        end = Frame(Rotation.Identity(), Vector(1, 0, 0))
        path = Path_Line(start, end, RotationalInterpolation_SingleAxis(), 1.0)

        # this constructor assumes the profile has already been configured
        vel_profile = VelocityProfile_Trap(2.0, 1.0)
        vel_profile.SetProfile(0.0, path.PathLength())

        traj = Trajectory_Segment(path, vel_profile)

        self.assertAlmostEqual(traj.Duration(), vel_profile.Duration(), delta=EPS)
        self.assertTrue(Equal(traj.Pos(0.0), start))
        self.assertTrue(Equal(traj.Pos(traj.Duration()), end))

    def testCopy(self):
        start = Frame(Rotation.Identity(), Vector(0, 0, 0))
        end = Frame(Rotation.Identity(), Vector(1, 0, 0))
        path = Path_Line(start, end, RotationalInterpolation_SingleAxis(), 1.0)
        vel_profile = VelocityProfile_Trap(2.0, 1.0)
        traj = Trajectory_Segment(path, vel_profile, 5.0)

        traj2 = copy.copy(traj)
        self.assertIsInstance(traj2, Trajectory_Segment)
        self.assertIsNot(traj, traj2)
        self.assertAlmostEqual(traj2.Duration(), traj.Duration(), delta=EPS)


class TrajectoryCompositeTest(unittest.TestCase):
    def testComposite(self):
        f1 = Frame(Rotation.Identity(), Vector(0, 0, 0))
        f2 = Frame(Rotation.Identity(), Vector(1, 0, 0))

        traj = Trajectory_Composite()
        traj.Add(Trajectory_Stationary(2.0, f1))
        traj.Add(Trajectory_Stationary(3.0, f2))

        self.assertAlmostEqual(traj.Duration(), 5.0, delta=EPS)
        self.assertTrue(Equal(traj.Pos(-1.0), f1))
        self.assertTrue(Equal(traj.Pos(1.0), f1))
        self.assertTrue(Equal(traj.Pos(2.5), f2))
        self.assertTrue(Equal(traj.Pos(5.0), f2))

    def testDestroy(self):
        traj = Trajectory_Composite()
        traj.Add(Trajectory_Stationary(1.0, Frame.Identity()))
        traj.Add(Trajectory_Stationary(1.0, Frame.Identity()))
        self.assertAlmostEqual(traj.Duration(), 2.0, delta=EPS)

        # Destroy() should not raise
        traj.Destroy()

    def testCopy(self):
        traj = Trajectory_Composite()
        traj.Add(Trajectory_Stationary(2.0, Frame.Identity()))

        traj2 = copy.copy(traj)
        self.assertIsInstance(traj2, Trajectory_Composite)
        self.assertIsNot(traj, traj2)
        self.assertAlmostEqual(traj2.Duration(), 2.0, delta=EPS)


def suite():
    suite = unittest.TestSuite()
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(VelocityProfileDiracTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(VelocityProfileRectangularTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(VelocityProfileTrapTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(VelocityProfileTrapHalfTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(VelocityProfileSplineTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(RotationalInterpolationSingleAxisTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(PathPointTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(PathLineTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(PathCircleTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(PathCompositeTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(PathRoundedCompositeTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(PathCyclicClosedTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(TrajectoryStationaryTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(TrajectorySegmentTest))
    suite.addTest(unittest.TestLoader().loadTestsFromTestCase(TrajectoryCompositeTest))
    return suite


if __name__ == '__main__':
    import sys
    suite = suite()
    result = unittest.TextTestRunner(verbosity=3).run(suite)

    if result.wasSuccessful():
        sys.exit(0)
    else:
        sys.exit(1)
