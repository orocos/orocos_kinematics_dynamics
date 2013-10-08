cmake_minimum_required(VERSION 2.8.3)
project(orocos_kdl)

find_package(catkin REQUIRED)

find_package(Orocos-KDL REQUIRED)

catkin_package(
  DEPENDS kdl
  LIBRARIES ${Orocos-KDL_LIBRARIES}
  INCLUDE_DIRS ${Orocos-KDL_INCLUDE_DIRS}
  CFG_EXTRAS orocos_kdl_extras.cmake
  )
