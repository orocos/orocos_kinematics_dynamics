# Benchmarks are not tests: they are not registered with CTest.
IF(ENABLE_BENCHMARKS)
  ADD_EXECUTABLE(framesbench framesbench.cpp)
  TARGET_LINK_LIBRARIES(framesbench PRIVATE orocos-kdl)
ENDIF()
