//Copyright  (C)  2007  Ruben Smits <ruben dot smits at intermodalics dot eu>
//
//Version: 1.0
//Author: Ruben Smits Ruben Smits <ruben dot smits at intermodalics dot eu>
//Author: Zihan Chen <zihan dot chen dot jhu at gmail dot com>
//Author: Matthijs van der Burgh <MatthijsBurgh at outlook dot com>
//Maintainer: Ruben Smits Ruben Smits <ruben dot smits at intermodalics dot eu>
//Maintainer: Matthijs van der Burgh <MatthijsBurgh at outlook dot com>
//URL: http://www.orocos.org/kdl
//
//This library is free software; you can redistribute it and/or
//modify it under the terms of the GNU Lesser General Public
//License as published by the Free Software Foundation; either
//version 2.1 of the License, or (at your option) any later version.
//
//This library is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//Lesser General Public License for more details.
//
//You should have received a copy of the GNU Lesser General Public
//License along with this library; if not, write to the Free Software
//Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA


#include <iostream>
#include <iomanip>
#include <kdl/chaindynparam.hpp>
#include <kdl/jntspaceinertiamatrix.hpp>
#include <kdl/kinfam_io.hpp>
#include "PyKDL.h"

namespace py = pybind11;
using namespace KDL;


void init_dynamics(pybind11::module &m)
{
    // --------------------
    // JntSpaceInertiaMatrix
    // --------------------
    py::class_<JntSpaceInertiaMatrix> jnt_space_inertia_matrix(m, "JntSpaceInertiaMatrix");
    jnt_space_inertia_matrix.def(py::init<>());
    jnt_space_inertia_matrix.def(py::init<int>());
    jnt_space_inertia_matrix.def(py::init<const JntSpaceInertiaMatrix&>());
    jnt_space_inertia_matrix.def("resize", &JntSpaceInertiaMatrix::resize, py::arg("new_size"));
    jnt_space_inertia_matrix.def("rows", &JntSpaceInertiaMatrix::rows);
    jnt_space_inertia_matrix.def("columns", &JntSpaceInertiaMatrix::columns);
    jnt_space_inertia_matrix.def("__getitem__", [](const JntSpaceInertiaMatrix &jm, std::tuple<int, int> idx)
    {
        int i = std::get<0>(idx);
        int j = std::get<1>(idx);
        if (i < 0 || (unsigned int)i >= jm.rows() || j < 0 || (unsigned int)j >= jm.columns())
            throw py::index_error("Inertia index out of range");

        return jm((unsigned int)i, (unsigned int)j);
    });
    jnt_space_inertia_matrix.def("__setitem__", [](JntSpaceInertiaMatrix &jm, std::tuple<int, int> idx, double value)
    {
        int i = std::get<0>(idx);
        int j = std::get<1>(idx);
        if (i < 0 || (unsigned int)i >= jm.rows() || j < 0 || (unsigned int)j >= jm.columns())
            throw py::index_error("Inertia index out of range");

        jm((unsigned int)i, (unsigned int)j) = value;
    });
    jnt_space_inertia_matrix.def("__repr__", [](const JntSpaceInertiaMatrix &jm)
    {
        std::ostringstream oss;
        oss << jm;
        return oss.str();
    });
    jnt_space_inertia_matrix.def(py::self == py::self);

    m.def("Add", (void (*)(const JntSpaceInertiaMatrix&, const JntSpaceInertiaMatrix&, JntSpaceInertiaMatrix&)) &KDL::Add, py::arg("src1"), py::arg("src2"), py::arg("dest"));
    m.def("Subtract", (void (*)(const JntSpaceInertiaMatrix&, const JntSpaceInertiaMatrix&,JntSpaceInertiaMatrix&)) &KDL::Subtract, py::arg("src1"), py::arg("src2"), py::arg("dest"));
    m.def("Multiply", (void (*)(const JntSpaceInertiaMatrix&, const double&, JntSpaceInertiaMatrix&)) &KDL::Multiply, py::arg("src"), py::arg("factor"), py::arg("dest"));
    m.def("Divide", (void (*)(const JntSpaceInertiaMatrix&, const double&, JntSpaceInertiaMatrix&)) &KDL::Divide, py::arg("src"), py::arg("factor"), py::arg("dest"));
    m.def("Multiply", (void (*)(const JntSpaceInertiaMatrix&, const JntArray&, JntArray&)) &KDL::Multiply, py::arg("src"), py::arg("vec"), py::arg("dest"));
    m.def("SetToZero", (void (*)(JntSpaceInertiaMatrix&)) &KDL::SetToZero, py::arg("matrix"));
    m.def("Equal", (bool (*)(const JntSpaceInertiaMatrix&, const JntSpaceInertiaMatrix&, double)) &KDL::Equal,
          py::arg("src1"), py::arg("src2"), py::arg("eps")=epsilon);


    // --------------------
    // ChainDynParam
    // --------------------
    py::class_<ChainDynParam> chain_dyn_param(m, "ChainDynParam");
    chain_dyn_param.def(py::init<const Chain&, Vector>());
    chain_dyn_param.def("JntToCoriolis", &ChainDynParam::JntToCoriolis, py::arg("q"), py::arg("q_dot"), py::arg("coriolis"));
    chain_dyn_param.def("JntToMass", &ChainDynParam::JntToMass, py::arg("q"), py::arg("H"));
    chain_dyn_param.def("JntToGravity", &ChainDynParam::JntToGravity, py::arg("q"), py::arg("gravity"));
}
