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
execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "from distutils.sysconfig import get_python_lib; print(get_python_lib(plat_specific=True, prefix=''))" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
set(PYTHON_SITE_PACKAGES_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/${PYTHON_SITE_PACKAGES})
set(LIBRARY_NAME "PyKDL")

option(BUILD_PYKDL_PYBIND11 "Use PyBind11 instead of SIP" OFF)
if (BUILD_PYKDL_PYBIND11)
  add_subdirectory(pybind11)
  pybind11_add_module(${LIBRARY_NAME}
    PyKDL/PyKDL.h
    PyKDL/PyKDL.cpp
    PyKDL/frames.cpp
    PyKDL/kinfam.cpp
    PyKDL/framevel.cpp
    PyKDL/dynamics.cpp)
  target_link_libraries(${LIBRARY_NAME} PRIVATE ${orocos_kdl_LIBRARIES})
  install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}.so" DESTINATION "${PYTHON_SITE_PACKAGES_INSTALL_DIR}")
else (BUILD_PYKDL_PYBIND11)
  list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
  find_package(SIP REQUIRED)
  include(SIPMacros)

  include_directories(${SIP_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS})

  file(GLOB SIP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.sip")
  set(SIP_INCLUDES ${SIP_FILES})
  set(SIP_EXTRA_OPTIONS "-o")
  add_sip_python_module(${LIBRARY_NAME} ${LIBRARY_NAME}/${LIBRARY_NAME}.sip ${orocos_kdl_LIBRARIES})
endif(BUILD_PYKDL_PYBIND11)

install(FILES package.xml DESTINATION share/python_orocos_kdl)

find_package(catkin QUIET)
if(catkin_FOUND)
  catkin_add_env_hooks(python_orocos_kdl_site_packages SHELLS bash tcsh zsh DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/env-hooks)
endif()
