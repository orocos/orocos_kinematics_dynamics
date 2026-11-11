# Benchmarks are not tests: they are not registered with CTest.
IF(ENABLE_BENCHMARKS)
  ADD_EXECUTABLE(framesbench framesbench.cpp)
  TARGET_LINK_LIBRARIES(framesbench PRIVATE orocos-kdl)
  TARGET_INCLUDE_DIRECTORIES(framesbench PRIVATE ${PROJ_SOURCE_DIR}/src)
ENDIF()
