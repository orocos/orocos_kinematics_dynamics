cmake_minimum_required(VERSION 3.16)
if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif()
# Avoid warning from pybind11 on Windows
if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()
if(POLICY CMP0057)
  cmake_policy(SET CMP0057 NEW)  # support IN_LISTS which is required for PyBind11 2.6 and newer
endif()
# CMake policy CMP0094 controls how Python versions are found;
# the OLD policy was to find the newest one, while the new policy
# is to stop after finding the first one.  We want to find the first
# one, so be sure to set that policy here.
if(POLICY CMP0094)
  cmake_policy(SET CMP0094 NEW)
endif()
# The default for Python3_FIND_UNVERSIONED_NAMES is LAST, which
# means find_package(Python3) will prefer to find /usr/bin/python3.11
# over /usr/bin/python3.  We actually prefer to find the system version,
# so set this to FIRST.
set(Python3_FIND_UNVERSIONED_NAMES FIRST)

project(python_orocos_kdl VERSION 1.5.2)

# Determine if we are being built via scikit-build-core
if(SKBUILD)
  message(STATUS "Building with scikit-build-core")
  set(PYTHON_PACKAGE_BUILD TRUE)
endif()

# find a matching version of orocos_kdl
find_package(orocos_kdl ${PROJECT_VERSION} EXACT REQUIRED)
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})

set(PYBIND11_PYTHON_VERSION 3 CACHE STRING "Python version used by PyBind11")

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
set(LIBRARY_NAME "PyKDL")

# catkin-specific configuration (optional, only if not building as Python package)
if(NOT PYTHON_PACKAGE_BUILD)
    find_package(catkin QUIET)
    if(catkin_FOUND)
        catkin_package(
            SKIP_CMAKE_CONFIG_GENERATION
            SKIP_PKG_CONFIG_GENERATION
        )
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CATKIN_DEVEL_PREFIX}/${PYTHON_INSTALL_DIR})
        set(PYTHON_SITE_PACKAGES_INSTALL_DIR "${PYTHON_INSTALL_DIR}")
    else()
        set(PYTHON_SITE_PACKAGES_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/dist-packages" CACHE STRING "Install location of the python package")
    endif()
endif()

# Build the module
find_package(pybind11 2.6 QUIET)
if(NOT ${pybind11_FOUND})
  message(STATUS "pybind11 not found, building from source")
  add_subdirectory(pybind11)
else()
  message(STATUS "pybind11 found, building against installed version")
endif()

pybind11_add_module(${LIBRARY_NAME}
  PyKDL/PyKDL.h
  PyKDL/PyKDL.cpp
  PyKDL/frames.cpp
  PyKDL/kinfam.cpp
  PyKDL/framevel.cpp
  PyKDL/dynamics.cpp
  PyKDL/trajectory.cpp)
target_link_libraries(${LIBRARY_NAME} PRIVATE ${orocos_kdl_LIBRARIES})

# Install target - different behaviour for Python package vs. system install
if(PYTHON_PACKAGE_BUILD)
    install(TARGETS ${LIBRARY_NAME} DESTINATION .)
else()
    install(TARGETS ${LIBRARY_NAME} DESTINATION "${PYTHON_SITE_PACKAGES_INSTALL_DIR}")
endif()
