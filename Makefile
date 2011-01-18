ifdef ROS_ROOT
include Makefile.ros
else
$(warning This Makefile only works with ROS rosmake. Without rosmake, create a build directory and run cmake ..)
endif
