cmake_minimum_required(VERSION 3.20)
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

project(python_orocos_kdl VERSION 1.5.4)

# find a matching version of orocos_kdl
find_package(orocos_kdl ${PROJECT_VERSION} EXACT REQUIRED)
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})

# Note: this find_package must stay ahead of the pybind11 subdirectory/package below.
# pybind11 only runs its own find_package(Python ...) when neither Python_FOUND nor
# Python3_FOUND is set, so this call is the single place where the minimum Python
# version for PyKDL is enforced.
find_package(Python3 3.10 COMPONENTS Interpreter Development REQUIRED)
# get_python_lib in python3 produces path which isn't in sys.path: https://bugs.launchpad.net/ubuntu/+source/python3-stdlib-extensions/+bug/1832215
# execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "from distutils.sysconfig import get_python_lib; print(get_python_lib(plat_specific=True, prefix=''))" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
set(PYTHON_SITE_PACKAGES_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/dist-packages" CACHE STRING "Install location of the python package")  # This might be overridden below if built with ament.
set(LIBRARY_NAME "PyKDL")

# ament-specific configuration (optional)
# ament_package() has to be called after all targets and install() rules, so it
# lives at the end of this file together with the environment hook.
if(DEFINED ENV{ROS_VERSION} AND "$ENV{ROS_VERSION}" STREQUAL "2")
  find_package(ament_cmake QUIET)
  if(ament_cmake_FOUND)
    find_package(ament_cmake_python REQUIRED)
    # ament_cmake_python knows the install prefix-relative site-packages
    # directory ROS 2 uses, but only exposes it through a private macro. Fall
    # back to the ROS 2 layout if that macro ever disappears.
    if(COMMAND _ament_cmake_python_get_python_install_dir)
      _ament_cmake_python_get_python_install_dir()
    endif()
    if(NOT PYTHON_INSTALL_DIR)
      set(PYTHON_INSTALL_DIR
        "lib/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/site-packages")
    endif()
    set(PYTHON_SITE_PACKAGES_INSTALL_DIR "${PYTHON_INSTALL_DIR}")
  endif()
endif()

# Build the module
find_package(pybind11 3.0 QUIET)
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
  PyKDL/dynamics.cpp)
target_link_libraries(${LIBRARY_NAME} PRIVATE ${orocos_kdl_LIBRARIES})
install(TARGETS ${LIBRARY_NAME} DESTINATION "${PYTHON_SITE_PACKAGES_INSTALL_DIR}")

# ament-specific configuration (optional)
# Unlike catkin, ament does not put site-packages on the PYTHONPATH by itself,
# so register an environment hook that does. The .dsv descriptor lets colcon
# generate the equivalent for every shell it supports.
if(ament_cmake_FOUND)
  set(AMENT_CMAKE_ENVIRONMENT_HOOKS_DESC_pythonpath
    "prepend-non-duplicate;PYTHONPATH;${PYTHON_INSTALL_DIR}")
  ament_environment_hooks("cmake/environment_hook/pythonpath.sh.in")
  ament_package()
endif()
