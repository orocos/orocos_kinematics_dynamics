^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package python_orocos_kdl
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Entries up to and including 1.5.1 were never split per package; see the
repository-wide `CHANGELOG.md
<https://github.com/orocos/orocos_kinematics_dynamics/blob/master/CHANGELOG.md>`_
for that history.

Forthcoming
-----------
* Convert from an optionally-catkin to an optionally-ament package. The package keeps
  ``<build_type>cmake</build_type>`` and still builds with plain cmake/make when neither ament
  nor colcon is installed.
* Install PyKDL into the ROS 2 site-packages directory and register a PYTHONPATH environment
  hook, so ``import PyKDL`` works after sourcing the workspace. Unlike catkin, ament does not
  add site-packages to the PYTHONPATH by itself.
* Add an explicit ``<build_type>cmake</build_type>``; package format 3 otherwise defaults to catkin
* Migrate the API documentation from rosdoc_lite to rosdoc2
* Drop the obsolete python3-future dependency; ``builtins.range`` is part of the standard library
  on Python 3
* Point the package urls at orocos.org and the GitHub repository instead of the ROS 1 wiki
* Bump python_orocos_kdl/pybind11 (`#510 <https://github.com/orocos/orocos_kinematics_dynamics/issues/510>`_, `#512 <https://github.com/orocos/orocos_kinematics_dynamics/issues/512>`_)
* Contributors: Matthijs van der Burgh, dependabot[bot]

1.5.3 (2025-10-17)
------------------
* Bump minimum pybind11 version to 2.13.0 (`#505 <https://github.com/orocos/orocos_kinematics_dynamics/issues/505>`_)
* Bump working version to 1.5.3 (`#501 <https://github.com/orocos/orocos_kinematics_dynamics/issues/501>`_)
* Contributors: Matthijs van der Burgh

1.5.2 (2025-09-07)
------------------
* Add a vector version of JntToCart for fk pos and vel (`#497 <https://github.com/orocos/orocos_kinematics_dynamics/issues/497>`_)
* Reduce the minimum CMake version to 3.16 (`#490 <https://github.com/orocos/orocos_kinematics_dynamics/issues/490>`_, `#489 <https://github.com/orocos/orocos_kinematics_dynamics/issues/489>`_)
* Require an exact python version match (`#481 <https://github.com/orocos/orocos_kinematics_dynamics/issues/481>`_)
* Fix return type and bound name (`#465 <https://github.com/orocos/orocos_kinematics_dynamics/issues/465>`_)
* Allow PYTHON_SITE_PACKAGES_INSTALL_DIR to be set externally (`#461 <https://github.com/orocos/orocos_kinematics_dynamics/issues/461>`_)
* Drop python2 compatibility (`#418 <https://github.com/orocos/orocos_kinematics_dynamics/issues/418>`_); python3 is now the default
* Use FindPython (`#425 <https://github.com/orocos/orocos_kinematics_dynamics/issues/425>`_)
* Skip building pybind11 if it is already available on the system (`#375 <https://github.com/orocos/orocos_kinematics_dynamics/issues/375>`_)
* Use a minimum pybind11 of 2.6
* Add hash support and tests for frames and framevel, matching the C++ values
* Sync the twist and wrench tests with the C++ ones
* Add more argument names
* Add unit tests for Frame initialization from Denavit-Hartenberg parameters, on both the class
  and an instance
* Fix the Python bindings for the static member functions Frame::DH() and Frame::DH_Craig1989()
* Disable the function taking a vector by reference
* Fix a CMake warning on Windows
* Bump python_orocos_kdl/pybind11 several times
* Contributors: DasRoteSkelett, Jacob Perron, Johannes Meyer, Matthijs van der Burgh,
  dependabot[bot]
