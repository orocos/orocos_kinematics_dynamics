IF(ENABLE_EXAMPLES)
 INCLUDE_DIRECTORIES(${PROJ_SOURCE_DIR}/install_dir/include)

 add_executable(geometry geometry.cpp )
 TARGET_LINK_LIBRARIES(geometry orocos-kdl)

ENDIF(ENABLE_EXAMPLES)  

