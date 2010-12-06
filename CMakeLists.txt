# Generated from orogen/lib/orogen/templates/typekit/CMakeLists.txt

##
# Header for typegen-generated typekits
#

project("kdl-typekit")
cmake_minimum_required(VERSION 2.6)

include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
rosbuild_init()
set(ROS_BUILD_TYPE Debug)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/install/lib/orocos/types)

SET (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/config")

# In Orogen components, the build target is specified at generation time
set(OROCOS_TARGET "gnulinux")

include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/types)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${OrocosRTT_INCLUDE_DIRS})
add_definitions(${OrocosRTT_CFLAGS_OTHER})
link_directories(${OrocosRTT_LIBRARY_DIRS})

# Generate the base typekit shared library
set(libname kdl-typekit-${OROCOS_TARGET})
rosbuild_add_library(${libname} ${CMAKE_CURRENT_SOURCE_DIR}/Plugin.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Frame.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Frames.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Rotation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Rotations.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Twist.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Twists.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Vector.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Vectors.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Wrench.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__Wrenches.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/__KDL__JntArray.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/type_info/doubleArray.cpp
    ${TYPEKIT_ADDITIONAL_SOURCES}
    ${TOOLKIT_ADDITIONAL_SOURCES}
    )


target_link_libraries(${libname} ${OrocosRTT_LIBRARIES} ${TYPEKIT_ADDITIONAL_LIBRARIES} ${TOOLKIT_ADDITIONAL_LIBRARIES})
target_link_libraries(${libname} LINK_INTERFACE_LIBRARIES ${OrocosRTT_LIBRARIES})

#add_subdirectory(transports/typelib)
    
add_subdirectory(transports/corba)
    
add_subdirectory(transports/mqueue)
