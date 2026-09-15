^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package orocos_kdl
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Entries up to and including 1.5.1 were never split per package; see the
repository-wide `CHANGELOG.md
<https://github.com/orocos/orocos_kinematics_dynamics/blob/master/CHANGELOG.md>`_
for that history.

Forthcoming
-----------
* Convert from an optionally-catkin to an optionally-ament package. The package keeps
  ``<build_type>cmake</build_type>`` and still builds with plain cmake/make when neither ament
  nor colcon is installed.
* Migrate the API documentation from rosdoc_lite to rosdoc2
* Point the package urls at orocos.org and the GitHub repository instead of the ROS 1 wiki
* Remove the obsolete rosbuild manifest.xml
* Modernise the Debian packaging in debian/
* (ChainExternalWrenchEstimator) initialize previous mass matrix on the first estimation step
  and in setInitialMomentum
* (Solver test) fix random-input flakiness and accept degraded IK convergence in
  FkPosAndIkPosLocal
* Contributors: Matthijs van der Burgh

1.5.3 (2025-10-17)
------------------
* Hotfix: incorrect package version (`#502 <https://github.com/orocos/orocos_kinematics_dynamics/issues/502>`_)
* Bump working version to 1.5.3 (`#501 <https://github.com/orocos/orocos_kinematics_dynamics/issues/501>`_)
* Contributors: Matthijs van der Burgh

1.5.2 (2025-09-07)
------------------
* Bump minimum CMake version to 3.12.0 (`#488 <https://github.com/orocos/orocos_kinematics_dynamics/issues/488>`_)
* Add support for boost::timer 1.83+ (`#463 <https://github.com/orocos/orocos_kinematics_dynamics/issues/463>`_)
* Rename variables with reserved names (`#456 <https://github.com/orocos/orocos_kinematics_dynamics/issues/456>`_)
* Fix KDL::PI in chainiksolverpos_lma_demo.cpp (`#452 <https://github.com/orocos/orocos_kinematics_dynamics/issues/452>`_)
* Fix whitespace splitting in CMake (`#440 <https://github.com/orocos/orocos_kinematics_dynamics/issues/440>`_)
* Add rosdoc config (`#437 <https://github.com/orocos/orocos_kinematics_dynamics/issues/437>`_)
* Add accessors (`#419 <https://github.com/orocos/orocos_kinematics_dynamics/issues/419>`_)
* Export a modern CMake interface target
* Add KDL::hash_combine and hash functions plus tests for frames, frameacc and framevel
* (Joint) make thread safe
* Add unit tests for Frame initialization from Denavit-Hartenberg parameters, on both the class
  and an instance
* (KDL) return the correct not_implemented_error
* Use a reverse iterator instead of decrementing an index
* Do not pass the generated header to add_library
* Remove members from the initializer list
* Use strncpy_s instead of strncpy on Windows
* Fix implicit conversion warnings
* Remove the CMake warning related to the minimum version
* Follow-up of "Get rid of using std namespace"
* Fix typos
* Contributors: Dirk Thomas, Jacob Perron, Johannes Meyer, Masa0u0,
  Matthijs van der Burgh, efferre79, kmartin36, luzpaz, thyssentishman, xtkoba
