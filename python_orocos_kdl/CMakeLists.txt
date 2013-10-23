cmake_minimum_required(VERSION 2.4.6)

project(python_orocos_kdl)

find_package(orocos_kdl)
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})

find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SIP REQUIRED)
include(SIPMacros)

include_directories(${SIP_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS})

file(GLOB SIP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.sip")
set(SIP_INCLUDES ${SIP_FILES})
set(SIP_EXTRA_OPTIONS "-o")
set(PYTHON_PACKAGES_DIR_NAME "")
set(PYTHON_PACKAGES_DIR_NAME "dist-packages")
set(PYTHON_SITE_PACKAGES_INSTALL_DIR
${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/${PYTHON_PACKAGES_DIR_NAME}
 CACHE PATH "The directory where python modules will be installed to.")
add_sip_python_module(PyKDL PyKDL/PyKDL.sip ${orocos_kdl_LIBRARIES})

install(FILES package.xml DESTINATION share/python_orocos_kdl)