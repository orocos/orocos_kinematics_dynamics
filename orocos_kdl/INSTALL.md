# Install instructions

These install instructions are focused on Debian/Ubuntu systems.

## Shared instructions

1. (Optional) Update apt cache: `sudo apt-get update`
2. Install EIGEN and cppunit: `sudo apt-get install libeigen3-dev libcppunit-dev`
3. (Optional) Install `Doxygen` and `Graphviz` to generate API-documentation: `sudo apt-get install doxygen graphviz`

## Compilation

### With colcon

1. Clone the repository inside the `src` folder of the workspace
2. Build the workspace: `colcon build`
3. Source the workspace: `source install/setup.bash`
4. (Optional) To generate the API-documentation, install
[rosdoc2](https://github.com/ros-infrastructure/rosdoc2) and run
`rosdoc2 build --package-path src/orocos_kinematics_dynamics/orocos_kdl`. The result is written
to `docs_output/orocos_kdl`.

### Without colcon

1. Clone the repository where you want
2. Go to the `orocos_kdl` folder": `cd orocos_kdl`
3. Create a new build folder (it is always better not to build in the source folder): `mkdir build`
4. Go to the build folder `cd build`
5. Execute cmake: `cmake ..`
   - (Optional) Adapt `CMAKE_INSTALL_PREFIX` to the desired installation directory
   - (Optional) To build the tests, add: `-DENABLE_TESTS:BOOL=ON`
   - (Optional) To change the build type, add: `-DCMAKE_BUILD_TYPE=<DESIRED_BUILD_TYPE>`
6. Compile: `make`
7. Install the library: `sudo make install`
8. (Optional) To execute the tests: `make check`
9. (Optional) To create the API-documentation: `make docs`. The API-documentation will be generated at
`<builddir>/doc/api/html`.

To uninstall the library: `sudo make uninstall`
