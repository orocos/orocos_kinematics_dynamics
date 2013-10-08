Orocos Kinematics and Dynamics Library (KDL)
============================================

## Building KDL

KDL and the Python KDL bindings can either be built normally with CMake, or they
can be built in an isolated [catkin](http://www.ros.org/wiki/catkin) workspace.

## Using KDL

The following  can be used to link against KDL in a CMake-based project:

```cmake
# Find the KDL Package
find_package(Orocos-KDL)
include_directories(${Orocos-KDL_INCLUDE_DIRS})
link_directories(${Orocos-KDL_LIBRARY_DIRS})

# add your target ...

# Link against KDL
target_link_libraries(my_target ${Orocos-KDL_LIBRARIES})
```

## Deprecated Packages

Up until ROS Hydromedusa, the KDL packages were named `orocos_kdl` and
`python_orocos_kdl`, which resulted from their early incorporation into the ROS
ecosystem. This naming convention was different from the naming convention used
by other package in the Orocos toolchain, and created inconsistencies in how
users referred to the packages when building code. 

* `kdl` (stack) --> `orocos_kinematics_dynamics`
* `orocos_kdl` --> `kdl`
* `python_orocos_kdl` --> `pykdl`

The old names will still be supported through ROS Hydromedusa through deprecated
wrapper packages.
