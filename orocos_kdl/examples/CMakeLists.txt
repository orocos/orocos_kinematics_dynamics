IF(ENABLE_EXAMPLES)
INCLUDE_DIRECTORIES(${PROJ_SOURCE_DIR}/src ${PROJ_SOURCE_DIR}/models)

 add_executable(geometry geometry.cpp )
 TARGET_LINK_LIBRARIES(geometry orocos-kdl)
 add_executable(trajectory_example trajectory_example.cpp )
 TARGET_LINK_LIBRARIES(trajectory_example orocos-kdl)
 add_executable(chainiksolverpos_lma_demo chainiksolverpos_lma_demo.cpp )
 TARGET_LINK_LIBRARIES(chainiksolverpos_lma_demo orocos-kdl orocos-kdl-models)
 add_executable(expressiontree_example expressiontree_example.cpp )
 TARGET_LINK_LIBRARIES(expressiontree_example orocos-kdl)

ENDIF(ENABLE_EXAMPLES)  

