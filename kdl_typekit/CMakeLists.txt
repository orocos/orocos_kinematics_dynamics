cmake_minimum_required(VERSION 2.6.3)

project(kdl_typekit)

#
# Do setup in case of ros package, If ROS_ROOT is set, it is
# recommended to use RTT/OCL through the ros packages.
#
set (ROS_ROOT $ENV{ROS_ROOT} )
if (ROS_ROOT)
  include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
  rosbuild_init()
  rosbuild_find_ros_package( rtt )
  rosbuild_find_ros_package( ocl )
  set( RTT_HINTS HINTS ${rtt_PACKAGE_PATH}/install )
  set( OCL_HINTS HINTS ${ocl_PACKAGE_PATH}/install )
endif()

# Set the CMAKE_PREFIX_PATH in case you're not using Orocos through ROS
# for helping these find commands find RTT.
find_package(Orocos-RTT REQUIRED ${RTT_HINTS})

# Defines the orocos_* cmake macros. See that file for additional
# documentation.
include(${OROCOS-RTT_USE_FILE_PATH}/UseOROCOS-RTT.cmake)

# Define the way rotation properties get written to XML
# Set one of the two options below to write them as EULER ZYX or RPY
# Set none of them to write them as matrices
#add_definitions(-DROTATION_PROPERTIES_EULER)
add_definitions(-DROTATION_PROPERTIES_RPY)

orocos_typekit(${PROJECT_NAME} src/kdlTypekit.cpp src/kdlTypekitConstructors.cpp
src/kdlTypekitOperators.cpp src/kdlTypekitChain.cpp src/kdlTypekitFrame.cpp
src/kdlTypekitJacobian.cpp src/kdlTypekitJntArray.cpp src/kdlTypekitJoint.cpp
src/kdlTypekitRotation.cpp src/kdlTypekitSegment.cpp src/kdlTypekitTwist.cpp
src/kdlTypekitVector.cpp src/kdlTypekitWrench.cpp src/motionproperties.cpp src/kinfamproperties.cpp )

add_subdirectory(test)
