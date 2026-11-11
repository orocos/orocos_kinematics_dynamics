set(KDL_SOURCES
  articulatedbodyinertia.cpp
  chain.cpp
  chaindynparam.cpp
  chainexternalwrenchestimator.cpp
  chainfdsolver_recursive_newton_euler.cpp
  chainfksolverpos_recursive.cpp
  chainfksolvervel_recursive.cpp
  chainhdsolver_vereshchagin.cpp
  chainidsolver_recursive_newton_euler.cpp
  chainiksolverpos_lma.cpp
  chainiksolverpos_nr.cpp
  chainiksolverpos_nr_jl.cpp
  chainiksolvervel_pinv.cpp
  chainiksolvervel_pinv_givens.cpp
  chainiksolvervel_pinv_nso.cpp
  chainiksolvervel_wdls.cpp
  chainjnttojacdotsolver.cpp
  chainjnttojacsolver.cpp
  frameacc.cpp
  frames.cpp
  frames_io.cpp
  framevel.cpp
  jacobian.cpp
  jntarray.cpp
  jntarrayacc.cpp
  jntarrayvel.cpp
  jntspaceinertiamatrix.cpp
  joint.cpp
  kinfam_io.cpp
  path.cpp
  path_circle.cpp
  path_composite.cpp
  path_cyclic_closed.cpp
  path_line.cpp
  path_point.cpp
  path_roundedcomposite.cpp
  rigidbodyinertia.cpp
  rotational_interpolation.cpp
  rotational_interpolation_sa.cpp
  rotationalinertia.cpp
  segment.cpp
  trajectory.cpp
  trajectory_composite.cpp
  trajectory_segment.cpp
  trajectory_stationary.cpp
  tree.cpp
  treefksolverpos_recursive.cpp
  treeidsolver_recursive_newton_euler.cpp
  treeiksolverpos_nr_jl.cpp
  treeiksolverpos_online.cpp
  treeiksolvervel_wdls.cpp
  treejnttojacsolver.cpp
  utilities/error_stack.cxx
  utilities/ldl_solver_eigen.cpp
  utilities/svd_HH.cpp
  utilities/svd_eigen_HH.cpp
  utilities/svd_eigen_Macie.cpp
  utilities/utility.cxx
  utilities/utility_io.cxx
  velocityprofile.cpp
  velocityprofile_dirac.cpp
  velocityprofile_rect.cpp
  velocityprofile_spline.cpp
  velocityprofile_trap.cpp
  velocityprofile_traphalf.cpp
)

set(KDL_PUBLIC_HEADERS
  articulatedbodyinertia.hpp
  chain.hpp
  chaindynparam.hpp
  chainexternalwrenchestimator.hpp
  chainfdsolver.hpp
  chainfdsolver_recursive_newton_euler.hpp
  chainfksolver.hpp
  chainfksolverpos_recursive.hpp
  chainfksolvervel_recursive.hpp
  chainhdsolver_vereshchagin.hpp
  chainidsolver.hpp
  chainidsolver_recursive_newton_euler.hpp
  chainiksolver.hpp
  chainiksolverpos_lma.hpp
  chainiksolverpos_nr.hpp
  chainiksolverpos_nr_jl.hpp
  chainiksolvervel_pinv.hpp
  chainiksolvervel_pinv_givens.hpp
  chainiksolvervel_pinv_nso.hpp
  chainiksolvervel_wdls.hpp
  chainjnttojacdotsolver.hpp
  chainjnttojacsolver.hpp
  frameacc.hpp
  frameacc_io.hpp
  frames.hpp
  frames_io.hpp
  framevel.hpp
  framevel_io.hpp
  jacobian.hpp
  jntarray.hpp
  jntarrayacc.hpp
  jntarrayvel.hpp
  jntspaceinertiamatrix.hpp
  joint.hpp
  kdl.hpp
  kinfam.hpp
  kinfam_io.hpp
  motion.hpp
  path.hpp
  path_circle.hpp
  path_composite.hpp
  path_cyclic_closed.hpp
  path_line.hpp
  path_point.hpp
  path_roundedcomposite.hpp
  rigidbodyinertia.hpp
  rotational_interpolation.hpp
  rotational_interpolation_sa.hpp
  rotationalinertia.hpp
  segment.hpp
  solveri.hpp
  stiffness.hpp
  trajectory.hpp
  trajectory_composite.hpp
  trajectory_segment.hpp
  trajectory_stationary.hpp
  tree.hpp
  treefksolver.hpp
  treefksolverpos_recursive.hpp
  treeidsolver.hpp
  treeidsolver_recursive_newton_euler.hpp
  treeiksolver.hpp
  treeiksolverpos_nr_jl.hpp
  treeiksolverpos_online.hpp
  treeiksolvervel_wdls.hpp
  treejnttojacsolver.hpp
  velocityprofile.hpp
  velocityprofile_dirac.hpp
  velocityprofile_rect.hpp
  velocityprofile_spline.hpp
  velocityprofile_trap.hpp
  velocityprofile_traphalf.hpp
)

set(KDL_UTILITY_HEADERS
  utilities/error.h
  utilities/error_stack.h
  utilities/hash_combine.h
  utilities/ldl_solver_eigen.hpp
  utilities/rall1d.h
  utilities/rall1d_io.h
  utilities/rall2d.h
  utilities/rall2d_io.h
  utilities/rallNd.h
  utilities/svd_HH.hpp
  utilities/svd_eigen_HH.hpp
  utilities/svd_eigen_Macie.hpp
  utilities/traits.h
  utilities/utility.h
  utilities/utility_io.h
)

#In Windows (Visual Studio) it is necessary to specify the postfix
#of the debug library name and no symbols are exported by kdl, 
#so it is necessary to compile it as a static library
IF(MSVC)
    SET(CMAKE_DEBUG_POSTFIX "d")
    SET(LIB_TYPE STATIC)
ELSE(MSVC)
    SET(LIB_TYPE SHARED)
ENDIF(MSVC)

CONFIGURE_FILE(config.h.in config.h @ONLY)

#### Settings for rpath
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
        FILE(RELATIVE_PATH _rel_path "${CMAKE_INSTALL_PREFIX}/bin" "${CMAKE_INSTALL_PREFIX}/lib")
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
#####end RPATH

ADD_LIBRARY(orocos-kdl ${LIB_TYPE} ${KDL_SOURCES})

# Consumers need C++17 too: the public headers rely on it.
TARGET_COMPILE_FEATURES(orocos-kdl PUBLIC cxx_std_17)

TARGET_INCLUDE_DIRECTORIES(orocos-kdl PUBLIC
  "$<INSTALL_INTERFACE:include>")

SET_TARGET_PROPERTIES( orocos-kdl PROPERTIES
  SOVERSION "${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}"
  VERSION "${KDL_VERSION}"
  COMPILE_FLAGS "${CMAKE_CXX_FLAGS_ADD}"
  PUBLIC_HEADER "${KDL_PUBLIC_HEADERS};${CMAKE_CURRENT_BINARY_DIR}/config.h"
  )

#### Settings for rpath disabled (back-compatibility)
IF(NOT OROCOSKDL_ENABLE_RPATH)
    SET_TARGET_PROPERTIES( orocos-kdl PROPERTIES
      INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}")
ENDIF()
#####end RPATH

# Needed so that the generated config.h can be used
TARGET_INCLUDE_DIRECTORIES(orocos-kdl PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
# Public dependencies, so consumers linking orocos-kdl get their include directories too
TARGET_LINK_LIBRARIES(orocos-kdl PUBLIC Eigen3::Eigen)
IF(KDL_USE_NEW_TREE_INTERFACE)
  TARGET_LINK_LIBRARIES(orocos-kdl PUBLIC Boost::boost)
ENDIF()

INSTALL(TARGETS orocos-kdl
  EXPORT OrocosKDLTargets
  ARCHIVE DESTINATION lib${LIB_SUFFIX}
  LIBRARY DESTINATION lib${LIB_SUFFIX}
  RUNTIME DESTINATION bin
  PUBLIC_HEADER DESTINATION include/kdl
)

INSTALL(FILES ${KDL_UTILITY_HEADERS} DESTINATION include/kdl/utilities)
