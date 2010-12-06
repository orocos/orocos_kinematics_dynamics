EXTRA_CMAKE_FLAGS=-DCMAKE_PREFIX_PATH=`rospack find rtt`/install/lib/cmake/orocos-rtt

include $(shell rospack find mk)/cmake.mk

wipe: clean
	svn-clean -f
