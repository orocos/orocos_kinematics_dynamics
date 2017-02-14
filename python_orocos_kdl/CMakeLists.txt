cmake_minimum_required(VERSION 3.0.2)
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

project(python_orocos_kdl VERSION 1.5.1)

# find a matching version of orocos_kdl
find_package(orocos_kdl ${PROJECT_VERSION} EXACT REQUIRED)
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})

if(DEFINED ENV{ROS_PYTHON_VERSION})
  SET(PYTHON_VERSION $ENV{ROS_PYTHON_VERSION} CACHE STRING "Python Version")
else()
  SET(PYTHON_VERSION 3 CACHE STRING "Python Version")
endif()

set(PYBIND11_PYTHON_VERSION ${PYTHON_VERSION} CACHE STRING "Python version used by PyBind11")

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

# OROCOSKDL_ENABLE_RPATH
IF(NOT MSVC)
    #add the option to disable RPATH
    OPTION(OROCOSKDL_ENABLE_RPATH "Enable RPATH during installation" TRUE)
    MARK_AS_ADVANCED(OROCOSKDL_ENABLE_RPATH)
ENDIF(NOT MSVC)

IF(OROCOSKDL_ENABLE_RPATH)
    #Configure RPATH
    SET(CMAKE_MACOSX_RPATH TRUE) #enable RPATH on OSX. This also suppress warnings on CMake >= 3.0
    # when building, don't use the install RPATH already
    # (but later on when installing)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
    #build directory by default is built with RPATH
    SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

    #This is relative RPATH for libraries built in the same project
    #I assume that the directory is
    # - install_dir/something for binaries
    # - install_dir/lib for libraries
    LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
    IF("${isSystemDir}" STREQUAL "-1")
        FILE(RELATIVE_PATH _rel_path "${PYTHON_SITE_PACKAGES_INSTALL_DIR}" "${CMAKE_INSTALL_PREFIX}/lib" )
        IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
            SET(CMAKE_INSTALL_RPATH "@loader_path/${_rel_path}")
        ELSE()
            SET(CMAKE_INSTALL_RPATH "\$ORIGIN/${_rel_path}")
        ENDIF()
    ENDIF("${isSystemDir}" STREQUAL "-1")
    # add the automatically determined parts of the RPATH
    # which point to directories outside the build tree to the install RPATH
    SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE) #very important!
ENDIF()

# Build the module
if(WIN32)
  set(PYTHON_MODULE_EXTENSION ".pyd")
else()
  set(PYTHON_MODULE_EXTENSION ".so")
endif()

find_package(pybind11 QUIET)
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
