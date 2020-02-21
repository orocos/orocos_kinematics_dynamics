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


import unittest
from PyKDL import *
from math import *

class FrameVelTestFunctions(unittest.TestCase):

    def testVectorVel(self):
        v=VectorVel(Vector(3,-4,5),Vector(6,3,-5))
        vt = Vector(-4,-6,-8);
        self.assertTrue(Equal( 2*v-v,v))
        self.assertTrue(Equal( v*2-v,v))
        self.assertTrue(Equal( v+v+v-2*v,v))
        v2=VectorVel(v)
        self.assertTrue(Equal( v,v2))
        v2+=v
        self.assertTrue(Equal( 2*v,v2))
        v2-=v
        self.assertTrue(Equal( v,v2))
        v2.ReverseSign()
        self.assertTrue(Equal( v,-v2))
        self.assertTrue(Equal( v*vt,-vt*v))
        v2 = VectorVel(Vector(-5,-6,-3),Vector(3,4,5))
        self.assertTrue(Equal( v*v2,-v2*v))

    def testRotationVel(self):
        v=VectorVel(Vector(9,4,-2),Vector(-5,6,-2))
        vt=Vector(2,3,4)
        a= radians(-15)
        b= radians(20)
        c= radians(-80)
        R = RotationVel(Rotation.RPY(a,b,c),Vector(2,4,1))
        R2=RotationVel(R)
        self.assertTrue(Equal(R,R2))
        self.assertTrue(Equal((R*v).Norm(),(v.Norm())))
        self.assertTrue(Equal(R.Inverse(R*v),v))
        self.assertTrue(Equal(R*R.Inverse(v),v))
        self.assertTrue(Equal(R*Rotation.Identity(),R))
        self.assertTrue(Equal(Rotation.Identity()*R,R))
        self.assertTrue(Equal(R*(R*(R*v)),(R*R*R)*v))
        self.assertTrue(Equal(R*(R*(R*vt)),(R*R*R)*vt))
        self.assertTrue(Equal(R*R.Inverse(),RotationVel.Identity()))
        self.assertTrue(Equal(R.Inverse()*R,RotationVel.Identity()))
        self.assertTrue(Equal(R.Inverse()*v,R.Inverse(v)))

    def testFrameVel(self):
        v=VectorVel(Vector(3,4,5),Vector(-2,-4,-1))
        vt=Vector(-1,0,-10)
        F = FrameVel(Frame(Rotation.EulerZYX(radians(10),radians(20),radians(-10)),Vector(4,-2,1)),
                     Twist(Vector(2,-2,-2),Vector(-5,-3,-2)))
        F2=FrameVel(F)
        self.assertTrue(Equal( F,F2))
        self.assertTrue(Equal( F.Inverse(F*v),v))
        self.assertTrue(Equal( F.Inverse(F*vt), vt))
        self.assertTrue(Equal( F*F.Inverse(v),v))
        self.assertTrue(Equal( F*F.Inverse(vt),vt))
        self.assertTrue(Equal( F*Frame.Identity(),F))
        self.assertTrue(Equal( Frame.Identity()*F,F))
        self.assertTrue(Equal( F*(F*(F*v)),(F*F*F)*v))
        self.assertTrue(Equal( F*(F*(F*vt)),(F*F*F)*vt))
        self.assertTrue(Equal( F*F.Inverse(),FrameVel.Identity()))
        self.assertTrue(Equal( F.Inverse()*F,Frame.Identity()))
        self.assertTrue(Equal( F.Inverse()*vt,F.Inverse(vt)))

    def testPickle(self):
        rot = Rotation.RotX(1.3)
        import pickle
        data = {}
        data['vv'] = VectorVel(Vector(1,2,3), Vector(4,5,6))
        data['rv'] = RotationVel(rot, Vector(4.1,5.1,6.1))
        data['fv'] = FrameVel(data['rv'], data['vv'])
        data['tv'] = TwistVel(data['vv'], data['vv'])

        f = open('/tmp/pickle_test_kdl_framevel', 'w')
        pickle.dump(data, f)
        f.close()

        f = open('/tmp/pickle_test_kdl_framevel', 'r')
        data1 = pickle.load(f)
        f.close()

        self.assertEqual(data['vv'].p, data1['vv'].p)
        self.assertEqual(data['vv'].v, data1['vv'].v)
        self.assertEqual(data['rv'].R, data1['rv'].R)
        self.assertEqual(data['rv'].w, data1['rv'].w)
        self.assertEqual(data['fv'].M.R, data1['fv'].M.R)
        self.assertEqual(data['fv'].M.w, data1['fv'].M.w)
        self.assertEqual(data['fv'].p.p, data1['fv'].p.p)
        self.assertEqual(data['fv'].p.v, data1['fv'].p.v)
        self.assertEqual(data['tv'].vel.p, data1['tv'].vel.p)
        self.assertEqual(data['tv'].vel.v, data1['tv'].vel.v)
        self.assertEqual(data['tv'].rot.p, data1['tv'].rot.p)
        self.assertEqual(data['tv'].rot.v, data1['tv'].rot.v)


def suite():
    suite=unittest.TestSuite()
    suite.addTest(FrameVelTestFunctions('testVectorVel'))
    suite.addTest(FrameVelTestFunctions('testRotationVel'))
    suite.addTest(FrameVelTestFunctions('testFrameVel'))
    suite.addTest(FrameVelTestFunctions('testPickle'))
    return suite


if __name__ == '__main__':
    suite = suite()
    unittest.TextTestRunner(verbosity=3).run(suite)
