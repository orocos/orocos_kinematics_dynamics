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
    
class FramesTestFunctions(unittest.TestCase):

    def testVector2(self,v):
        self.assertEqual(2*v-v,v)
        self.assertEqual(v*2-v,v)
        self.assertEqual(v+v+v-2*v,v)
        v2=Vector(v)
        self.assertEqual(v,v2)
        v2+=v
        self.assertEqual(2*v,v2)
        v2-=v
        self.assertEqual(v,v2)
        v2.ReverseSign()
        self.assertEqual(v,-v2)

    def testVector(self):
        v=Vector(3,4,5)
        self.testVector2(v)
        v=Vector.Zero()
        self.testVector2(v)
    
    def testTwist2(self,t):
        self.assertEqual(2*t-t,t)
	self.assertEqual(t*2-t,t)
	self.assertEqual(t+t+t-2*t,t)
	t2=Twist(t)
	self.assertEqual(t,t2)
	t2+=t
	self.assertEqual(2*t,t2)
	t2-=t
	self.assertEqual(t,t2)
	t.ReverseSign()
	self.assertEqual(t,-t2)

    def testTwist(self):
        t=Twist(Vector(6,3,5),Vector(4,-2,7))
        self.testTwist2(t)
        t=Twist.Zero()
        self.testTwist2(t)
        t=Twist(Vector(0,-9,-3),Vector(1,-2,-4))

    def testWrench2(self,w):
        self.assertEqual(2*w-w,w)
	self.assertEqual(w*2-w,w)
	self.assertEqual(w+w+w-2*w,w)
	w2=Wrench(w)
	self.assertEqual(w,w2)
	w2+=w
	self.assertEqual(2*w,w2)
	w2-=w
	self.assertEqual(w,w2)
	w.ReverseSign()
	self.assertEqual(w,-w2)

    def testWrench(self):
        w=Wrench(Vector(7,-1,3),Vector(2,-3,3))
	self.testWrench2(w)
	w=Wrench.Zero()
	self.testWrench2(w)
        w=Wrench(Vector(2,1,4),Vector(5,3,1))
	self.testWrench2(w)	

    def testRotation2(self,v,a,b,c):
	w=Wrench(Vector(7,-1,3),Vector(2,-3,3))
	t=Twist(Vector(6,3,5),Vector(4,-2,7))
        R=Rotation.RPY(a,b,c)
        
        self.assertAlmostEqual(dot(R.UnitX(),R.UnitX()),1.0,15)
	self.assertEqual(dot(R.UnitY(),R.UnitY()),1.0)
	self.assertEqual(dot(R.UnitZ(),R.UnitZ()),1.0)
	self.assertAlmostEqual(dot(R.UnitX(),R.UnitY()),0.0,15)
	self.assertAlmostEqual(dot(R.UnitX(),R.UnitZ()),0.0,15)
	self.assertEqual(dot(R.UnitY(),R.UnitZ()),0.0)
	R2=Rotation(R)
	self.assertEqual(R,R2)
	self.assertAlmostEqual((R*v).Norm(),v.Norm(),14)
	self.assertEqual(R.Inverse(R*v),v)
	self.assertEqual(R.Inverse(R*t),t)
	self.assertEqual(R.Inverse(R*w),w)
	self.assertEqual(R*R.Inverse(v),v)
	self.assertEqual(R*Rotation.Identity(),R)
	self.assertEqual(Rotation.Identity()*R,R)
	self.assertEqual(R*(R*(R*v)),(R*R*R)*v)
	self.assertEqual(R*(R*(R*t)),(R*R*R)*t)
	self.assertEqual(R*(R*(R*w)),(R*R*R)*w)
	self.assertEqual(R*R.Inverse(),Rotation.Identity())
	self.assertEqual(R.Inverse()*R,Rotation.Identity())
	self.assertEqual(R.Inverse()*v,R.Inverse(v))
	(ra,rb,rc)=R.GetRPY()
	self.assertEqual(ra,a)
        self.assertEqual(rb,b)
        self.assertEqual(rc,c)
	R = Rotation.EulerZYX(a,b,c)
	(ra,rb,rc)=R.GetEulerZYX()
	self.assertEqual(ra,a)
        self.assertEqual(rb,b)
        self.assertEqual(rc,c)
	R = Rotation.EulerZYZ(a,b,c)
	(ra,rb,rc)=R.GetEulerZYZ()
	self.assertEqual(ra,a)
        self.assertEqual(rb,b)
        self.assertAlmostEqual(rc,c,15)
	(angle,v2)= R.GetRotAngle()
	R2=Rotation.Rot(v2,angle)
	self.assertEqual(R2,R)
	R2=Rotation.Rot(v2*1E20,angle)
	self.assertEqual(R,R2)
	v2=Vector(6,2,4)
	self.assertAlmostEqual(v2.Norm(),sqrt(dot(v2,v2)),14)
    
    def testRotation(self):
        self.testRotation2(Vector(3,4,5),radians(10),radians(20),radians(30))
    
    def testFrame(self):
        v=Vector(3,4,5) 
	w=Wrench(Vector(7,-1,3),Vector(2,-3,3))
	t=Twist(Vector(6,3,5),Vector(4,-2,7))
	F = Frame(Rotation.EulerZYX(radians(10),radians(20),radians(-10)),Vector(4,-2,1))
	F2=Frame(F)
	self.assertEqual(F,F2)
	self.assertEqual(F.Inverse(F*v),v)
	self.assertEqual(F.Inverse(F*t),t)
	self.assertEqual(F.Inverse(F*w),w)
	self.assertEqual(F*F.Inverse(v),v)
	self.assertEqual(F*F.Inverse(t),t)
	self.assertEqual(F*F.Inverse(w),w)
	self.assertEqual(F*Frame.Identity(),F)
	self.assertEqual(Frame.Identity()*F,F)
	self.assertEqual(F*(F*(F*v)),(F*F*F)*v)
	self.assertEqual(F*(F*(F*t)),(F*F*F)*t)
	self.assertEqual(F*(F*(F*w)),(F*F*F)*w)
	self.assertEqual(F*F.Inverse(),Frame.Identity())
	self.assertEqual(F.Inverse()*F,Frame.Identity())
	self.assertEqual(F.Inverse()*v,F.Inverse(v))

    def testPickle(self):
        import pickle
        data = {}
        data['v'] = Vector(1,2,3)
        data['rot'] = Rotation.RotX(1.3)
        data['fr'] = Frame(data['rot'], data['v'])
        data['tw'] = Twist(data['v'], Vector(4,5,6))
        data['wr'] = Wrench(Vector(0.1,0.2,0.3), data['v'])
        
        f = open('/tmp/pickle_test', 'w')
        pickle.dump(data, f)
        f.close()
        
        f = open('/tmp/pickle_test', 'r')
        data1 = pickle.load(f)
        f.close()
       
        self.assertEqual(data, data1)


def suite():
    suite=unittest.TestSuite()
    suite.addTest(FramesTestFunctions('testVector'))
    suite.addTest(FramesTestFunctions('testTwist'))
    suite.addTest(FramesTestFunctions('testWrench'))
    suite.addTest(FramesTestFunctions('testRotation'))
    suite.addTest(FramesTestFunctions('testFrame'))
    suite.addTest(FramesTestFunctions('testPickle'))
    return suite
    
#suite = suite()
#unittest.TextTestRunner(verbosity=3).run(suite)
