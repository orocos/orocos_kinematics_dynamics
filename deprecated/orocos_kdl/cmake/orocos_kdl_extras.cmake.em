# Get CMake variables from real orocos package
find_package(Orocos-KDL REQUIRED)

set(orocos_kdl_FOUND ${Orocos-KDL_FOUND})
set(orocos_kdl_INCLUDE_DIRS ${Orocos-KDL_INCLUDE_DIRS})
set(orocos_kdl_LIBRARIES ${Orocos-KDL_LIBRARIES})
set(orocos_kdl_CFLAGS ${Orocos-KDL_CFLAGS})
set(orocos_kdl_LD_FLAGS ${Orocos-KDL_LD_FLAGS})
set(orocos_kdl_LIBRARY_DIRS ${Orocos-KDL_LIBRARY_DIRS})
set(orocos_kdl_DEFINES ${Orocos-KDL_DEFINES})

