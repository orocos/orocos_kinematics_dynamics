# Copyright  (C)  2020  Ruben Smits <ruben dot smits at intermodalics dot eu>

# Version: 1.0
# Author: Ruben Smits <ruben dot smits at intermodalics dot eu>
# Maintainer: Ruben Smits <ruben dot smits at intermodalics dot eu>
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


from builtins import range

import gc
import psutil
from PyKDL import *
import random
import sys
import unittest


class KinfamTestFunctions(unittest.TestCase):
    def setUp(self):
        self.chain = Chain()
        self.chain.addSegment(Segment(Joint(Joint.RotZ),
                                      Frame(Vector(0.0, 0.0, 0.0))))
        self.chain.addSegment(Segment(Joint(Joint.RotX),
                                      Frame(Vector(0.0, 0.0, 0.9))))
        self.chain.addSegment(Segment(Joint(Joint.Fixed),
                                      Frame(Vector(-0.4, 0.0, 0.0))))
        self.chain.addSegment(Segment(Joint(Joint.RotY),
                                      Frame(Vector(0.0, 0.0, 1.2))))
        self.chain.addSegment(Segment(Joint(Joint.Fixed),
                                      Frame(Vector(0.4, 0.0, 0.0))))
        self.chain.addSegment(Segment(Joint(Joint.TransZ),
                                      Frame(Vector(0.0, 0.0, 1.4))))
        self.chain.addSegment(Segment(Joint(Joint.TransX),
                                      Frame(Vector(0.0, 0.0, 0.0))))
        self.chain.addSegment(Segment(Joint(Joint.TransY),
                                      Frame(Vector(0.0, 0.0, 0.4))))
        self.chain.addSegment(Segment(Joint(Joint.Fixed),
                                      Frame(Vector(0.0, 0.0, 0.0))))

        self.jacsolver = ChainJntToJacSolver(self.chain)
        self.fksolverpos = ChainFkSolverPos_recursive(self.chain)
        self.fksolvervel = ChainFkSolverVel_recursive(self.chain)
        self.iksolvervel = ChainIkSolverVel_pinv(self.chain)
        self.iksolverpos = ChainIkSolverPos_NR(self.chain, self.fksolverpos, self.iksolvervel)

    def testRotationalInertia(self):
        ri = RotationalInertia(1, 2, 3, 4, 7, 5)
        # __getitem__
        for i in range(3):
            for j in range(3):
                self.assertEqual(ri[3*i+j], 2*abs(i-j) + max(i, j) + 1)
        with self.assertRaises(IndexError):
            _ = ri[-1]
        with self.assertRaises(IndexError):
            _ = ri[9]

        # __setitem__
        for i in range(3):
            for j in range(3):
                ri[i] = i
        for i in range(3):
            for j in range(3):
                self.assertEqual(ri[i], i)
        with self.assertRaises(IndexError):
            ri[-1] = 1
        with self.assertRaises(IndexError):
            ri[9] = 1

    def testJacobian(self):
        jac = Jacobian(3)
        for i in range(jac.columns()):
            jac.setColumn(i, Twist(Vector(6*i+1, 6*i+2, 6*i+3), Vector(6*i+4, 6*i+5, 6*i+6)))
        # __getitem__
        for i in range(6):
            for j in range(3):
                self.assertEqual(jac[i, j], 6*j+i+1)
        with self.assertRaises(IndexError):
            _ = jac[-1, 0]
        with self.assertRaises(IndexError):
            _ = jac[6, 0]
        with self.assertRaises(IndexError):
            _ = jac[5, -1]
        with self.assertRaises(IndexError):
            _ = jac[5, 3]

        # __setitem__
        for i in range(6):
            for j in range(3):
                jac[i, j] = 3*i+j
        for i in range(6):
            for j in range(3):
                self.assertEqual(jac[i, j], 3*i+j)
        with self.assertRaises(IndexError):
            jac[-1, 0] = 1
        with self.assertRaises(IndexError):
            jac[6, 0] = 1
        with self.assertRaises(IndexError):
            jac[5, -1] = 1
        with self.assertRaises(IndexError):
            jac[5, 3] = 1

    def testJntArray(self):
        ja = JntArray(3)
        # __getitem__
        for i in range(3):
            self.assertEqual(ja[i], 0)
        with self.assertRaises(IndexError):
            _ = ja[-1]
        with self.assertRaises(IndexError):
            _ = ja[3]

        # __setitem__
        for i in range(3):
            ja[i] = 2*i
        for i in range(3):
            self.assertEqual(ja[i], 2*i)
        with self.assertRaises(IndexError):
            ja[-1] = 1
        with self.assertRaises(IndexError):
            ja[3] = 1

    def testFkPosAndJac(self):
        deltaq = 1E-4
        epsJ = 1E-4

        F1 = Frame()
        F2 = Frame()

        q = JntArray(self.chain.getNrOfJoints())
        jac = Jacobian(self.chain.getNrOfJoints())

        for i in range(q.rows()):
            q[i] = random.uniform(-3.14, 3.14)

        self.jacsolver.JntToJac(q, jac)

        for i in range(q.rows()):
            oldqi = q[i]
            q[i] = oldqi+deltaq
            self.assertTrue(0 == self.fksolverpos.JntToCart(q, F2))
            q[i] = oldqi-deltaq
            self.assertTrue(0 == self.fksolverpos.JntToCart(q, F1))
            q[i] = oldqi
            Jcol1 = diff(F1, F2, 2*deltaq)
            Jcol2 = Twist(Vector(jac[0, i], jac[1, i], jac[2, i]),
                          Vector(jac[3, i], jac[4, i], jac[5, i]))
            self.assertEqual(Jcol1, Jcol2)

    def testFkVelAndJac(self):
        deltaq = 1E-4
        epsJ = 1E-4

        q = JntArray(self.chain.getNrOfJoints())
        qdot = JntArray(self.chain.getNrOfJoints())
        for i in range(q.rows()):
            q[i] = random.uniform(-3.14, 3.14)
            qdot[i] = random.uniform(-3.14, 3.14)

        qvel = JntArrayVel(q, qdot)
        jac = Jacobian(self.chain.getNrOfJoints())

        cart = FrameVel.Identity()
        t = Twist.Zero()

        self.jacsolver.JntToJac(qvel.q, jac)
        self.assertTrue(self.fksolvervel.JntToCart(qvel, cart) == 0)
        MultiplyJacobian(jac, qvel.qdot, t)
        self.assertEqual(cart.deriv(), t)

    def testFkVelAndIkVel(self):
        epsJ = 1E-7

        q = JntArray(self.chain.getNrOfJoints())
        qdot = JntArray(self.chain.getNrOfJoints())
        for i in range(q.rows()):
            q[i] = random.uniform(-3.14, 3.14)
            qdot[i] = random.uniform(-3.14, 3.14)

        qvel = JntArrayVel(q, qdot)
        qdot_solved = JntArray(self.chain.getNrOfJoints())

        cart = FrameVel()

        self.assertTrue(0 == self.fksolvervel.JntToCart(qvel, cart))
        self.assertTrue(0 == self.iksolvervel.CartToJnt(qvel.q, cart.deriv(), qdot_solved))

        self.assertEqual(qvel.qdot, qdot_solved)

    def testFkPosAndIkPos(self):
        q = JntArray(self.chain.getNrOfJoints())
        for i in range(q.rows()):
            q[i] = random.uniform(-3.14, 3.14)

        q_init = JntArray(self.chain.getNrOfJoints())
        for i in range(q_init.rows()):
            q_init[i] = q[i]+0.1*random.random()

        q_solved = JntArray(q.rows())

        F1 = Frame.Identity()
        F2 = Frame.Identity()

        self.assertTrue(0 == self.fksolverpos.JntToCart(q, F1))
        self.assertTrue(0 == self.iksolverpos.CartToJnt(q_init, F1, q_solved))
        self.assertTrue(0 == self.fksolverpos.JntToCart(q_solved, F2))

        self.assertEqual(F1, F2)
        self.assertEqual(q, q_solved)


class KinfamTestTree(unittest.TestCase):

    def setUp(self):
        self.tree = Tree()
        self.tree.addSegment(Segment(Joint(Joint.RotZ),
                                     Frame(Vector(0.0, 0.0, 0.0))), "foo")
        self.tree.addSegment(Segment(Joint(Joint.Fixed),
                                     Frame(Vector(0.0, 0.0, 0.0))), "bar")

    def testTreeGetChainMemLeak(self):
        # test for the memory leak in Tree.getChain described in issue #211
        process = psutil.Process()
        self.tree.getChain("foo", "bar")
        gc.collect()
        mem_before = process.memory_info().vms
        # needs at least 2000 iterations on my system to cause a detectable
        # difference in memory usage
        for _ in range(10000):
            self.tree.getChain("foo", "bar")
        gc.collect()
        mem_after = process.memory_info().vms
        self.assertEqual(mem_before, mem_after)


def suite():
    suite = unittest.TestSuite()
    suite.addTest(KinfamTestFunctions('testRotationalInertia'))
    suite.addTest(KinfamTestFunctions('testJacobian'))
    suite.addTest(KinfamTestFunctions('testJntArray'))
    suite.addTest(KinfamTestFunctions('testFkPosAndJac'))
    suite.addTest(KinfamTestFunctions('testFkVelAndJac'))
    suite.addTest(KinfamTestFunctions('testFkVelAndIkVel'))
    suite.addTest(KinfamTestFunctions('testFkPosAndIkPos'))
    suite.addTest(KinfamTestTree('testTreeGetChainMemLeak'))
    return suite


if __name__ == '__main__':
    suite = suite()
    result = unittest.TextTestRunner(verbosity=3).run(suite)

    if result.wasSuccessful():
        sys.exit(0)
    else:
        sys.exit(1)
