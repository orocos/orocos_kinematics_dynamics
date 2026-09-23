# Copyright  (C)  2025  Bartek Lukawski <bwmn.peter at gmail dot com>

# Version: 1.0
# Author: Bartek Lukawski <bwmn.peter at gmail dot com>
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


from PyKDL import Chain, Frame, Joint, RigidBodyInertia, RotationalInertia, Segment, Vector


def create_kuka_lwr():
    """
    KUKA LWR 4 chain with dynamics parameters, mirroring the kukaLWR chain of the C++ solvertest.

    Both the Vereshchagin solver and the tests built on top of it require a chain with an equal
    number of joints and segments. Joint effective inertia values in this model are closely aligned
    with the joint inertia of the real robot. These parameters are published in: Jubien, A.,
    Gautier, M. and Janot, A., "Dynamic identification of the Kuka LWR robot using motor torques and
    joint torque sensors data.", IFAC Proceedings Volumes, 2014., 47(3), pp.8391-8396.
    """
    scale = 1.0
    offset = 0.0
    damping = 0.0
    stiffness = 0.0

    # (inertia, DH-Craig1989 parameters, mass, center of gravity, rotational inertia)
    segments = [
        (3.19, (0.0, 1.5707963, 0.0, 0.0), 2,
         Vector.Zero(), RotationalInertia(0.0, 0.0, 0.0115343, 0.0, 0.0, 0.0)),
        (3.05, (0.0, -1.5707963, 0.4, 0.0), 2,
         Vector(0.0, -0.3120511, -0.0038871),
         RotationalInertia(-0.5471572, -0.0000302, -0.5423253, 0.0, 0.0, 0.0018828)),
        (1.98, (0.0, -1.5707963, 0.0, 0.0), 2,
         Vector(0.0, -0.0015515, 0.0),
         RotationalInertia(0.0063507, 0.0, 0.0107804, 0.0, 0.0, -0.0005147)),
        (2.05, (0.0, 1.5707963, 0.39, 0.0), 2,
         Vector(0.0, 0.5216809, 0.0),
         RotationalInertia(-1.0436952, 0.0, -1.0392780, 0.0, 0.0, 0.0005324)),
        (0.787, (0.0, 1.5707963, 0.0, 0.0), 2,
         Vector(0.0, 0.0119891, 0.0),
         RotationalInertia(0.0036654, 0.0, 0.0060429, 0.0, 0.0, 0.0004226)),
        (0.391, (0.0, -1.5707963, 0.0, 0.0), 2,
         Vector(0.0, 0.0080787, 0.0),
         RotationalInertia(0.0010431, 0.0, 0.0036376, 0.0, 0.0, 0.0000101)),
    ]

    chain = Chain()
    for inertia, dh, mass, cog, rot_inertia in segments:
        frame = Frame.DH_Craig1989(*dh)
        chain.addSegment(Segment(Joint(Joint.RotZ, scale, offset, inertia, damping, stiffness),
                                 frame,
                                 frame.Inverse() * RigidBodyInertia(mass, cog, rot_inertia)))

    # The last segment carries no DH transform, so its rigid body inertia is not transformed either.
    chain.addSegment(Segment(Joint(Joint.RotZ, scale, offset, 0.394, damping, stiffness),
                             Frame.Identity(),
                             RigidBodyInertia(2, Vector.Zero(),
                                              RotationalInertia(0.000001, 0.0, 0.0001203, 0.0, 0.0, 0.0))))
    return chain
