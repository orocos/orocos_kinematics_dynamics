# Install instructions

These install instructions are focused on Debian/Ubuntu systems.

## Shared instructions

1. Follow the shared instructions of the C++ library from [orocos_kdl/INSTALL.md](../orocos_kdl/INSTALL.md#shared-instructions)
2. Install the `future` and `psutil` module: `sudo apt-get install python3-psutil python3-future`
3. (Optional) Install `Sphinx` to generate API-documentation: `sudo apt-get install python3-sphinx`

## Compilation

### With catkin

1. Clone the repository inside the workspace
2. Initialize the [PyBind11](https://github.com/pybind/pybind11) submodule: `git submodule update --init`
3. Build with your catkin tool of preference. This will also build the C++ library
4. Source the workspace
5. (Optional) To generate the API-documentation use either [rosdoc_lite](http://wiki.ros.org/rosdoc_lite) or
[catkin_tools_document](https://github.com/mikepurvis/catkin_tools_document)

### Without catkin

1. Clone the repository where you want
2. Initialize the [PyBind11](https://github.com/pybind/pybind11) submodule: `git submodule update --init`
3. Follow the mandatory instruction to compile the C++ library from [orocos_kdl/INSTALL.md](../orocos_kdl/INSTALL.md#without-catkin)
4. Create a new build folder (it is always better not to build in the source folder): `mkdir build`
5. Go to the build folder `cd build`
6. Execute cmake: `cmake ..`
   - (Optional) Adapt `CMAKE_INSTALL_PREFIX` to the desired installation directory
   - (Optional) To change the build type, add: `-DCMAKE_BUILD_TYPE=<DESIRED_BUILD_TYPE>`
7. Compile: `make`
8. Install the python bindings: `sudo make install`
9. Make sure `LD_LIBRARY_PATH` is set correctly: `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib`. Add this also
to your `.bashrc`.
10. Execute `ldconfig`: `sudo ldconfig`
11. (Optional) Execute tests: `python3 ../tests/PyKDLtest.py`
12. (Optional) To create the API-documentation: `sphinx-build ../doc docs`. The API-documentation will be generated at
`<builddir>/docs`.

To uninstall the python bindings: `sudo make uninstall`
