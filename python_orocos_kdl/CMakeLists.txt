cmake_minimum_required(VERSION 2.4.6)
if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif()

project(python_orocos_kdl)

find_package(orocos_kdl REQUIRED)
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})

if(DEFINED ENV{ROS_PYTHON_VERSION})
  SET(PYTHON_VERSION $ENV{ROS_PYTHON_VERSION} CACHE STRING "Python Version")
else()
  SET(PYTHON_VERSION 2 CACHE STRING "Python Version")
endif()

find_package(PythonInterp ${PYTHON_VERSION} REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} REQUIRED)
# get_python_lib in python3 produces path which isn't in sys.path: https://bugs.launchpad.net/ubuntu/+source/python3-stdlib-extensions/+bug/1832215
# execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "from distutils.sysconfig import get_python_lib; print(get_python_lib(plat_specific=True, prefix=''))" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
set(PYTHON_SITE_PACKAGES_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/dist-packages")  # This might be overridden below if built with catkin.
set(LIBRARY_NAME "PyKDL")

# catkin-specific configuration (optional)
find_package(catkin QUIET)
if(catkin_FOUND)
  catkin_package(
    SKIP_CMAKE_CONFIG_GENERATION
    SKIP_PKG_CONFIG_GENERATION
  )
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CATKIN_DEVEL_PREFIX}/${PYTHON_INSTALL_DIR})
  set(PYTHON_SITE_PACKAGES_INSTALL_DIR "${PYTHON_INSTALL_DIR}")
endif()

message(DEPRECATION "PyKDL has been moved to PyBind11. PyKDL based on SIP might become depracted in the (near) future. To keep using the SIP based version set 'BUILD_PYKDL_PYBIND11' to OFF.")

option(BUILD_PYKDL_PYBIND11 "Use PyBind11 instead of SIP" ON)
if (BUILD_PYKDL_PYBIND11)
  SET(PYTHON_MODULE_EXTENSION ".so")
  add_subdirectory(pybind11)
  pybind11_add_module(${LIBRARY_NAME}
    PyKDL/pybind11/PyKDL.h
    PyKDL/pybind11/PyKDL.cpp
    PyKDL/pybind11/frames.cpp
    PyKDL/pybind11/kinfam.cpp
    PyKDL/pybind11/framevel.cpp
    PyKDL/pybind11/dynamics.cpp)
  target_link_libraries(${LIBRARY_NAME} PRIVATE ${orocos_kdl_LIBRARIES})
  install(TARGETS ${LIBRARY_NAME} DESTINATION "${PYTHON_SITE_PACKAGES_INSTALL_DIR}")
else (BUILD_PYKDL_PYBIND11)
  list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
  find_package(SIP REQUIRED)
  include(SIPMacros)

  include_directories(${SIP_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS})

  file(GLOB SIP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_NAME}/sip/*.sip")
  set(SIP_INCLUDES ${SIP_FILES})
  if (${PYTHON_VERSION_MAJOR} GREATER_EQUAL "3")
    set(SIP_EXTRA_OPTIONS "-o;-x;PYTHON2") # '-x' disables the feature
  else()
    set(SIP_EXTRA_OPTIONS "-o")
  endif()
  add_sip_python_module(${LIBRARY_NAME} ${LIBRARY_NAME}/sip/${LIBRARY_NAME}.sip ${orocos_kdl_LIBRARIES})
endif(BUILD_PYKDL_PYBIND11)
