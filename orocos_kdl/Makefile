ifdef ROS_ROOT
INSTALL_PREFIX=${PWD}/install
EXTRA_CMAKE_FLAGS=-DCMAKE_INSTALL_PREFIX=${INSTALL_PREFIX} \
		-DBUILD_MODELS=ON \
		-DCMAKE_PREFIX_PATH="`rospack find eigen`"\
		-DCMAKE_BUILD_TYPE="Release"\
		-DENABLE_TESTS=ON

include $(shell rospack find mk)/cmake.mk

default: all
	cd build; ${MAKE} install


else
$(warning This Makefile only works with ROS rosmake. Without rosmake, create a build directory and run cmake ..)
endif

