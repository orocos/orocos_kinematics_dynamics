ifdef ROS_ROOT
INSTALL_PREFIX=${PWD}/install_dir
EXTRA_CMAKE_FLAGS=-DCMAKE_INSTALL_PREFIX=${INSTALL_PREFIX} \
		-DBUILD_MODELS=ON \
		-DCMAKE_OSX_ARCHITECTURES="i386;x86_64" \
		-DCMAKE_BUILD_TYPE="Release"\
		-DENABLE_TESTS=ON

default: all
	cd build; ${MAKE} install

include $(shell rospack find mk)/cmake.mk

else
$(warning This Makefile only works with ROS rosmake. Without rosmake, create a build directory and run cmake ..)
endif
