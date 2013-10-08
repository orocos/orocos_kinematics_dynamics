cmake_minimum_required(VERSION 2.8.3)
project(orocos_kdl)

find_package(catkin REQUIRED)

catkin_package(
  DEPENDS kdl
  CFG_EXTRAS orocos_kdl_extras.cmake
  )
