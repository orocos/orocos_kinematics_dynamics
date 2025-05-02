# PyKDL

Python bindings for the Orocos Kinematics and Dynamics Library (KDL).

## Description

PyKDL provides Python access to the C++ Orocos KDL library, allowing you to perform kinematic and dynamic calculations for articulated robots and mechanisms. The package provides classes for representing:

- Frames, vectors and rotations
- Kinematic chains and trees
- Forward and inverse kinematics
- Dynamics calculations
- Trajectory generation

## Installation

### From Source

Prerequisites:
- Orocos KDL library
- CMake >= 3.16
- C++ compiler

```bash
# Clone the repository
git clone org-19786058@github.com:VentionCo/orocos_kinematics_dynamics.git
cd python_orocos_kdl

# Install
pip install .
```
