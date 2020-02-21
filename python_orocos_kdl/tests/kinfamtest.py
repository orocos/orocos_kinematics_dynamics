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


import gc
import random
import unittest
from math import *

import psutil
from PyKDL import *


class KinfamTestFunctions(unittest.TestCase):

    def setUp(self):
        self.chain = Chain()
        self.chain.addSegment(Segment(Joint(Joint.RotZ),
                                 Frame(Vector(0.0,0.0,0.0))))
        self.chain.addSegment(Segment(Joint(Joint.RotX),
                                 Frame(Vector(0.0,0.0,0.9))))
        self.chain.addSegment(Segment(Joint(Joint.None),
                                 Frame(Vector(-0.4,0.0,0.0))))
        self.chain.addSegment(Segment(Joint(Joint.RotY),
                             Frame(Vector(0.0,0.0,1.2))))
        self.chain.addSegment(Segment(Joint(Joint.None),
                                 Frame(Vector(0.4,0.0,0.0))))
        self.chain.addSegment(Segment(Joint(Joint.TransZ),
                                 Frame(Vector(0.0,0.0,1.4))))
        self.chain.addSegment(Segment(Joint(Joint.TransX),
                                 Frame(Vector(0.0,0.0,0.0))))
        self.chain.addSegment(Segment(Joint(Joint.TransY),
                                 Frame(Vector(0.0,0.0,0.4))))
        self.chain.addSegment(Segment(Joint(Joint.None),
                                 Frame(Vector(0.0,0.0,0.0))))

        self.jacsolver   = ChainJntToJacSolver(self.chain)
        self.fksolverpos = ChainFkSolverPos_recursive(self.chain)
        self.fksolvervel = ChainFkSolverVel_recursive(self.chain)
        self.iksolvervel = ChainIkSolverVel_pinv(self.chain)
        self.iksolverpos = ChainIkSolverPos_NR(self.chain,self.fksolverpos,self.iksolvervel)

    def testFkPosAndJac(self):
        deltaq = 1E-4
        epsJ = 1E-4

        F1=Frame()
        F2=Frame()

        q=JntArray(self.chain.getNrOfJoints())
        jac=Jacobian(self.chain.getNrOfJoints())

        for i in range(q.rows()):
            q[i]=random.uniform(-3.14,3.14)

        self.jacsolver.JntToJac(q,jac)

        for i in range(q.rows()):
            oldqi=q[i];
            q[i]=oldqi+deltaq
            self.assertTrue(0==self.fksolverpos.JntToCart(q,F2))
            q[i]=oldqi-deltaq
            self.assertTrue(0==self.fksolverpos.JntToCart(q,F1))
            q[i]=oldqi
            Jcol1 = diff(F1,F2,2*deltaq)
            Jcol2 = Twist(Vector(jac[0,i],jac[1,i],jac[2,i]),
                          Vector(jac[3,i],jac[4,i],jac[5,i]))
            self.assertEqual(Jcol1,Jcol2);

    def testFkVelAndJac(self):
        deltaq = 1E-4
        epsJ   = 1E-4

        q=JntArray(self.chain.getNrOfJoints())
        qdot=JntArray(self.chain.getNrOfJoints())
        for i in range(q.rows()):
            q[i]=random.uniform(-3.14,3.14)
            qdot[i]=random.uniform(-3.14,3.14)

        qvel=JntArrayVel(q,qdot);
        jac=Jacobian(self.chain.getNrOfJoints())

        cart = FrameVel.Identity();
        t = Twist.Zero();

        self.jacsolver.JntToJac(qvel.q,jac)
        self.assertTrue(self.fksolvervel.JntToCart(qvel,cart)==0)
        MultiplyJacobian(jac,qvel.qdot,t)
        self.assertEqual(cart.deriv(),t)

    def testFkVelAndIkVel(self):
        epsJ = 1E-7

        q=JntArray(self.chain.getNrOfJoints())
        qdot=JntArray(self.chain.getNrOfJoints())
        for i in range(q.rows()):
            q[i]=random.uniform(-3.14,3.14)
            qdot[i]=random.uniform(-3.14,3.14)

        qvel=JntArrayVel(q,qdot)
        qdot_solved=JntArray(self.chain.getNrOfJoints())

        cart = FrameVel()

        self.assertTrue(0==self.fksolvervel.JntToCart(qvel,cart))
        self.assertTrue(0==self.iksolvervel.CartToJnt(qvel.q,cart.deriv(),qdot_solved))

        self.assertEqual(qvel.qdot,qdot_solved);

    def testFkPosAndIkPos(self):
        q=JntArray(self.chain.getNrOfJoints())
        for i in range(q.rows()):
            q[i]=random.uniform(-3.14,3.14)

        q_init=JntArray(self.chain.getNrOfJoints())
        for i in range(q_init.rows()):
            q_init[i]=q[i]+0.1*random.random()

        q_solved=JntArray(q.rows())

        F1=Frame.Identity()
        F2=Frame.Identity()

        self.assertTrue(0==self.fksolverpos.JntToCart(q,F1))
        self.assertTrue(0==self.iksolverpos.CartToJnt(q_init,F1,q_solved))
        self.assertTrue(0==self.fksolverpos.JntToCart(q_solved,F2))

        self.assertEqual(F1,F2)
        self.assertEqual(q,q_solved)


class KinfamTestTree(unittest.TestCase):

    def setUp(self):
        self.tree = Tree()
        self.tree.addSegment(Segment(Joint(Joint.RotZ),
                                     Frame(Vector(0.0, 0.0, 0.0))), "foo")
        self.tree.addSegment(Segment(Joint(Joint.None),
                                     Frame(Vector(0.0, 0.0, 0.0))), "bar")

    def testTreeGetChainMemLeak(self):
        """ test for the memory leak in Tree.getChain described in issue #211 """
        process = psutil.Process()
        self.tree.getChain("foo", "bar")
        gc.collect()
        mem_before = process.memory_info().vms
        # needs at least 2000 iterations on my system to cause a detectable
        # difference in memory usage
        for _ in xrange(10000):
            self.tree.getChain("foo", "bar")
        gc.collect()
        mem_after = process.memory_info().vms
        self.assertEqual(mem_before, mem_after)


def suite():
    suite = unittest.TestSuite()
    suite.addTest(KinfamTestFunctions('testFkPosAndJac'))
    suite.addTest(KinfamTestFunctions('testFkVelAndJac'))
    suite.addTest(KinfamTestFunctions('testFkVelAndIkVel'))
    suite.addTest(KinfamTestFunctions('testFkPosAndIkPos'))
    suite.addTest(KinfamTestTree('testTreeGetChainMemLeak'))
    return suite


if __name__ == '__main__':
    suite = suite()
    unittest.TextTestRunner(verbosity=3).run(suite)
