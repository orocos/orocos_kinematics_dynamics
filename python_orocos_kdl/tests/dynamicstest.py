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
from chains import create_kuka_lwr
import math
import random
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


    def testVereshchagin(self):
        """
        Port of SolverTest::VereshchaginTest (first test case).

        Compares the resultant Cartesian accelerations of the end-effector segment with the
        task-specified acceleration constraints, and checks the intermediate solver outputs
        against the reference values of the C++ test.
        """
        eps = 1.e-3
        chain = create_kuka_lwr()
        nj = chain.getNrOfJoints()
        ns = chain.getNrOfSegments()
        # The Vereshchagin solver only works with chains that have equal joints and segments
        self.assertEqual(nj, ns)

        q = JntArray(nj)
        qd = JntArray(nj)
        qdd = JntArray(nj)
        ff_tau = JntArray(nj)
        constraint_tau = JntArray(nj)

        for i, value in enumerate([1.6, 0.0, -1.6, -1.57, 0.0, 1.57, -0.8]):
            q[i] = value
        for i, value in enumerate([1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0]):
            qd[i] = value
        for i, value in enumerate([5.0, 0.0, 0.0, 0.0, 0.0, -6.0, 0.0]):
            ff_tau[i] = value

        # External wrench acting on the end-effector, expressed in base link coordinates
        f_ext = [Wrench() for _ in range(ns)]
        f_ext[ns - 1] = Wrench(Vector(10.0, 15.0, 0.0), Vector(0.0, 0.0, 5.0))

        # Unit constraint forces imposed on the end-effector, expressed w.r.t. the base frame.
        # Columns 3 and 4 are left at zero, leaving those directions to emerge naturally.
        number_of_constraints = 6
        alpha = Jacobian(number_of_constraints)
        alpha.setColumn(0, Twist(Vector(1.0, 0.0, 0.0), Vector(0.0, 0.0, 0.0)))
        alpha.setColumn(1, Twist(Vector(0.0, 1.0, 0.0), Vector(0.0, 0.0, 0.0)))
        alpha.setColumn(2, Twist(Vector(0.0, 0.0, 1.0), Vector(0.0, 0.0, 0.0)))
        alpha.setColumn(3, Twist(Vector(0.0, 0.0, 0.0), Vector(0.0, 0.0, 0.0)))
        alpha.setColumn(4, Twist(Vector(0.0, 0.0, 0.0), Vector(0.0, 0.0, 0.0)))
        alpha.setColumn(5, Twist(Vector(0.0, 0.0, 0.0), Vector(0.0, 0.0, 1.0)))

        # Acceleration energy setpoints, expressed w.r.t. the unit constraint forces above
        beta = JntArray(number_of_constraints)
        for i, value in enumerate([-0.5, -0.5, 0.0, 0.0, 0.0, 0.2]):
            beta[i] = value

        # The Vereshchagin solver takes the root acceleration with the sign opposite to the
        # one used by the FD and RNE solvers
        root_acc = Twist(Vector(0.0, 0.0, 9.81), Vector(0.0, 0.0, 0.0))
        solver = ChainHdSolver_Vereshchagin(chain, root_acc, number_of_constraints)
        self.assertEqual(solver.CartToJnt(q, qd, qdd, alpha, beta, f_ext, ff_tau, constraint_tau), 0)

        # The resultant Cartesian accelerations must match the constrained directions of beta.
        # The number of frames on the robot is ns + 1.
        xdd = solver.getTransformedLinkAcceleration([Twist() for _ in range(ns + 1)])
        self.assertAlmostEqual(beta[0], xdd[ns].vel[0], delta=eps)
        self.assertAlmostEqual(beta[1], xdd[ns].vel[1], delta=eps)
        self.assertAlmostEqual(beta[2], xdd[ns].vel[2], delta=eps)
        self.assertAlmostEqual(beta[5], xdd[ns].rot[2], delta=eps)

        # Magnitude of the constraint forces acting on the end-effector: Lagrange multiplier.
        # Elements 3 and 4 correspond to the constraints disabled in the task specification.
        nu = solver.getContraintForceMagnitude([0.0] * number_of_constraints)
        for value, expected in zip(nu, [669693.30355, 5930.60826, -639.5238, 0.0, 0.0, 573.90485]):
            self.assertAlmostEqual(value, expected, delta=eps)

        # Total torque acting on each joint (constraints + nature + external forces)
        total_tau = JntArray(nj)
        solver.getTotalTorque(total_tau)
        expected_tau = [2013.3541, -6073.4999, 2227.4487, 56.87456, -11.3789, -6.05957, 569.0776]
        for i, expected in enumerate(expected_tau):
            self.assertAlmostEqual(total_tau[i], expected, delta=eps)

    def testExternalWrenchEstimator(self):
        """
        Port of SolverTest::ExternalWrenchEstimatorTest.

        Closed-loop test for the external wrench estimator: the controlled behaviour of a robot
        subjected to an external force is simulated, calling the estimator in each iteration of
        the control loop so it converges to the final wrench value. The estimated wrench is then
        compared to the ground-truth values of the simulated wrench.

        Unlike the C++ test, the random inputs are drawn from a fixed seed. The estimated signal
        is only accurate to within eps_wrench, and a nondeterministic draw has historically
        produced configurations in which that tolerance is exceeded; a fixed seed keeps a failure
        reproducible.
        """
        # These tolerances cover floating-point imprecision, but mostly the noise in the estimated
        # signals caused by the controller and the dynamics simulator used in this test.
        eps_wrench = 0.5
        eps_torque = 0.3
        rng = random.Random(42)

        chain = create_kuka_lwr()
        nj = chain.getNrOfJoints()
        ns = chain.getNrOfSegments()
        self.assertEqual(nj, ns)

        # Arm root acceleration (robot's base mounted on an even surface)
        linear_acc = Vector(0.0, 0.0, -9.81)
        angular_acc = Vector(0.0, 0.0, 0.0)

        fksolverpos = ChainFkSolverPos_recursive(chain)
        fksolvervel = ChainFkSolverVel_recursive(chain)
        jacobian_solver = ChainJntToJacSolver(chain)
        id_solver = ChainIdSolver_RNE(chain, linear_acc)

        # Vereshchagin hybrid dynamics solver, used here as a simulator. It takes the root
        # acceleration with the sign opposite to the FD and RNE solvers above.
        number_of_constraints = 6
        alpha = Jacobian(number_of_constraints)
        SetToZero(alpha)  # deactivate all constraints
        beta = JntArray(number_of_constraints)
        SetToZero(beta)  # deactivate all constraints
        constraint_solver = ChainHdSolver_Vereshchagin(
            chain, Twist(-linear_acc, angular_acc), number_of_constraints)

        sample_frequency = 1000.0  # Hz
        estimation_gain = 45.0
        filter_constant = 0.5
        estimator = ChainExternalWrenchEstimator(
            chain, linear_acc, sample_frequency, estimation_gain, filter_constant)

        # Ground-truth external wrenches acting on the end-effector, in the local end-effector frame
        jnt_pos = []
        wrench_reference = []

        jnt_pos.append([1.0, 0.0, 0.0, 4.71, 0.0, 1.57, 5.48])
        wrench_reference.append(Wrench(Vector(rng.uniform(-15.0, 15.0), rng.uniform(-15.0, 15.0),
                                              rng.uniform(-15.0, 15.0)),
                                       Vector(0.0, 0.0, 0.0)))

        jnt_pos.append([2.96, 1.02, 6.15, 1.61, 0.22, 0.17, 0.01])
        wrench_reference.append(Wrench(Vector(0.0, 0.0, 0.0),
                                       Vector(rng.uniform(-0.9, 0.9), rng.uniform(-0.9, 0.9), 0.0)))

        jnt_pos.append([1.12, 0.66, 6.15, 4.09, 1.64, 0.12, 0.01])
        wrench_reference.append(Wrench(Vector(rng.uniform(-15.0, 15.0), rng.uniform(-15.0, 15.0),
                                              rng.uniform(-15.0, 15.0)),
                                       Vector(rng.uniform(-0.9, 0.9), 0.0, rng.uniform(-0.9, 0.9))))

        # Control gains for a simple PD controller
        k_p = 1500.0  # Proportional
        k_d = 300.0  # Derivative
        # Rotational gains: keep the end-effector's orientation close to its initial state. Without
        # orientation control, the random external moments can drive the arm into a near-singular
        # configuration, in which the applied wrench cannot be observed from the joint torques.
        k_p_rot = 100.0
        k_d_rot = 20.0
        # Joint-space damping: the arm is redundant (7 DOF), so the Cartesian controller leaves the
        # null-space self-motion undamped, which lets random initial velocities drift the arm into
        # a near-singular configuration.
        k_d_jnt = 5.0

        simulation_time = 0.4  # seconds
        time_delta = 1.0 / sample_frequency

        for case in range(len(jnt_pos)):
            q = JntArray(nj)
            qd = JntArray(nj)
            qdd = JntArray(nj)
            command_torque = JntArray(nj)
            constraint_tau = JntArray(nj)
            gravity_torque = JntArray(nj)
            jnt_array_zero = JntArray(nj)
            jnt_position_velocity = JntArrayVel(nj)
            jacobian_end_eff = Jacobian(nj)
            end_effector_pose = Frame()
            end_eff_twist = FrameVel()
            f_tool_estimated = Wrench()

            for i, value in enumerate(jnt_pos[case]):
                q[i] = value
            for i in range(nj):
                qd[i] = rng.uniform(-0.5, 0.5)

            f_ext_zero = [Wrench() for _ in range(ns)]
            f_ext_base = [Wrench() for _ in range(ns)]

            estimator.updateInternalDataStructures()
            # Sets the offset for the future estimation (momentum calculation)
            estimator.setInitialMomentum(q, qd)

            # Set the desired Cartesian state
            self.assertGreaterEqual(fksolverpos.JntToCart(q, end_effector_pose), 0)
            desired_end_eff_pose = Frame(end_effector_pose.M,
                                         end_effector_pose.p + Vector(0.02, 0.02, 0.02))

            steps = int(simulation_time / time_delta) + 1
            for step in range(steps):
                self.assertGreaterEqual(jacobian_solver.JntToJac(q, jacobian_end_eff), 0)
                self.assertGreaterEqual(fksolverpos.JntToCart(q, end_effector_pose), 0)

                jnt_position_velocity.q = q
                jnt_position_velocity.qdot = qd
                self.assertGreaterEqual(fksolvervel.JntToCart(jnt_position_velocity, end_eff_twist), 0)

                pos_error = end_effector_pose.p - desired_end_eff_pose.p
                vel_error = end_eff_twist.p.v
                rot_error = diff(end_effector_pose.M, desired_end_eff_pose.M)

                # Desired end-effector velocity is zero, so the velocity error is the twist itself
                end_eff_force = [-pos_error[i] * k_p - vel_error[i] * k_d for i in range(3)]
                end_eff_force += [rot_error[i] * k_p_rot - end_eff_twist.M.w[i] * k_d_rot
                                  for i in range(3)]

                # Compute gravity joint torques, hiding the external wrench from this calculation
                self.assertGreaterEqual(
                    id_solver.CartToJnt(q, jnt_array_zero, jnt_array_zero, f_ext_zero,
                                        gravity_torque), 0)

                # Compute joint control commands: transpose(J) * F + gravity - damping
                for j in range(nj):
                    column = jacobian_end_eff.getColumn(j)
                    command_torque[j] = (dot(column.vel, Vector(*end_eff_force[0:3])) +
                                         dot(column.rot, Vector(*end_eff_force[3:6])) +
                                         gravity_torque[j] - qd[j] * k_d_jnt)

                # Start simulating the external force halfway through the simulation
                if step * time_delta > 0.2:
                    f_ext_base[ns - 1] = end_effector_pose.M * wrench_reference[case]

                # Compute the joint accelerations that simulate the robot's behaviour, given the
                # command torques. The external wrench is included in this calculation.
                self.assertGreaterEqual(
                    constraint_solver.CartToJnt(q, qd, qdd, alpha, beta, f_ext_base,
                                                command_torque, constraint_tau), 0)

                # State integration: from model accelerations to the next joint state
                for j in range(nj):
                    qd[j] = qd[j] + qdd[j] * time_delta  # Euler forward
                    q[j] = q[j] + qd[j] * time_delta  # Symplectic Euler
                    # Saturate the integrated joint position for full circle crossing
                    q[j] = math.fmod(q[j], 2 * math.pi)
                    if q[j] < 0.0:
                        q[j] += 2 * math.pi

                self.assertGreaterEqual(
                    estimator.JntToExtWrench(q, qd, command_torque, f_tool_estimated), 0)

            # Inverse force kinematics: the ground-truth joint torques due to the external force
            ext_torque_reference = JntArray(nj)
            for j in range(nj):
                column = jacobian_end_eff.getColumn(j)
                ext_torque_reference[j] = (dot(column.vel, f_ext_base[ns - 1].force) +
                                           dot(column.rot, f_ext_base[ns - 1].torque))

            ext_torque_estimated = JntArray(nj)
            estimator.getEstimatedJntTorque(ext_torque_estimated)

            for i in range(6):
                self.assertAlmostEqual(f_tool_estimated[i], wrench_reference[case][i],
                                       delta=eps_wrench,
                                       msg="case {}: wrench element {}".format(case, i))
            for i in range(nj):
                self.assertAlmostEqual(ext_torque_estimated[i], ext_torque_reference[i],
                                       delta=eps_torque,
                                       msg="case {}: joint torque {}".format(case, i))


def suite():
    suite = unittest.TestSuite()
    suite.addTest(DynamicsTestFunctions('testJntSpaceInertiaMatrix'))
    suite.addTest(DynamicsTestFunctions('testVereshchagin'))
    suite.addTest(DynamicsTestFunctions('testExternalWrenchEstimator'))
    return suite


if __name__ == '__main__':
    import sys
    suite = suite()
    result = unittest.TextTestRunner(verbosity=3).run(suite)

    if result.wasSuccessful():
        sys.exit(0)
    else:
        sys.exit(1)
