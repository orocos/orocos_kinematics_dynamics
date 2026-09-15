# Kinematics and Dynamics Library

[![CI](https://github.com/orocos/orocos_kinematics_dynamics/workflows/CI/badge.svg)](https://github.com/orocos/orocos_kinematics_dynamics/actions)

Orocos project to supply RealTime usable kinematics and dynamics code,
it contains code for rigid body kinematics calculations and
representations for kinematic structures and their inverse and forward
kinematic solvers.

The C++ library is located in the `orocos_kdl` folder. The installation instructions can be found in
[INSTALL.md](orocos_kdl/INSTALL.md).

The python bindings, are located in the `python_orocos_kdl` folder. The installation instructions can be found in
[INSTALL.md](python_orocos_kdl/INSTALL.md).

Always use the same version of the C++ library and the python bindings. As a mismatch between these two can cause many issues.

Also when using ROS 2, it is preferred to use the colcon installation method over the `cmake/make` method.

## ROS support

The `master` branch targets ROS 2 and builds with `colcon`/`ament`. The `release-1.5` branch is
the last one supporting ROS 1 and `catkin`; there will be no ROS Noetic release.

Both packages declare `<build_type>cmake</build_type>`, so they also build with plain `cmake` and
`make` without ROS, ament or colcon installed.
