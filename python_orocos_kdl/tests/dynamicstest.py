# Copyright  (C)  2020  Matthijs van der Burgh <MatthijsBurgh at outlook dot com>

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


from PyKDL import *
import unittest


class DynamicsTestFunctions(unittest.TestCase):
    def testJntSpaceInertiaMatrix(self):
        ll = 3
        jm = JntSpaceInertiaMatrix(3)
        # __getitem__
        for i in range(ll):
            for j in range(ll):
                self.assertEqual(jm[i, j], 0)
        with self.assertRaises(IndexError):
            _ = jm[-1, 0]
        with self.assertRaises(IndexError):
            _ = jm[3, 0]
        with self.assertRaises(IndexError):
            _ = jm[2, -1]
        with self.assertRaises(IndexError):
            _ = jm[2, 3]

        # __setitem__
        for i in range(ll):
            for j in range(ll):
                jm[i, j] = 3 * i + j
        for i in range(ll):
            for j in range(ll):
                self.assertEqual(jm[i, j], 3 * i + j)
        with self.assertRaises(IndexError):
            jm[-1, 0] = 1
        with self.assertRaises(IndexError):
            jm[3, 0] = 1
        with self.assertRaises(IndexError):
            jm[2, -1] = 1
        with self.assertRaises(IndexError):
            jm[2, 3] = 1

    def testJntSpaceInertiaMatrixData(self):
        ll = 3
        jm = JntSpaceInertiaMatrix(ll)
        for i in range(ll):
            for j in range(ll):
                jm[i, j] = 3 * i + j

        arr = jm.data
        self.assertEqual(arr.shape, (ll, ll))
        for i in range(ll):
            for j in range(ll):
                self.assertEqual(arr[i, j], jm[i, j])

        arr[0, 0] = 42
        self.assertEqual(jm[0, 0], 42)
        jm[2, 2] = 99
        self.assertEqual(arr[2, 2], 99)

        with self.assertRaises(AttributeError):
            jm.data = JntSpaceInertiaMatrix(ll)


def suite():
    suite = unittest.TestSuite()
    suite.addTest(DynamicsTestFunctions('testJntSpaceInertiaMatrix'))
    suite.addTest(DynamicsTestFunctions('testJntSpaceInertiaMatrixData'))
    return suite


if __name__ == '__main__':
    import sys
    suite = suite()
    result = unittest.TextTestRunner(verbosity=3).run(suite)

    if result.wasSuccessful():
        sys.exit(0)
    else:
        sys.exit(1)
