//Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//
//Version: 1.0
//Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//Author: Zihan Chen <zihan dot chen dot jhu at gmail dot com>
//Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
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

#include <kdl/framevel.hpp>
#include <kdl/framevel_io.hpp>
#include "PyKDL.h"

namespace py = pybind11;
using namespace KDL;


void init_framevel(pybind11::module &m)
{
    // --------------------
    // doubleVel
    // --------------------
    py::class_<Rall1d<double> >(m, "doubleVel")
        .def_readwrite("t", &doubleVel::t)
        .def_readwrite("grad", &doubleVel::grad)
        .def(py::init<>())
        ;
    m.def("diff", (doubleVel (*)(const doubleVel&, const doubleVel&, double)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt")=1.0);
    m.def("addDelta", (doubleVel (*)(const doubleVel&, const doubleVel&, double)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt")=1.0);
    m.def("Equal", (bool (*)(const doubleVel&, const doubleVel&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);

    py::class_<VectorVel>(m, "VectorVel")
        .def_readwrite("p", &VectorVel::p)
        .def_readwrite("v", &VectorVel::v)
        .def(py::init<>())
        .def(py::init<const Vector&, const Vector&>())
        .def(py::init<const Vector&>())
        .def(py::init<const VectorVel&>())
        .def("value", &VectorVel::value)
        .def("deriv", &VectorVel::deriv)
        .def_static("Zero", &VectorVel::Zero)
        .def("ReverseSign", &VectorVel::ReverseSign)
        .def("Norm", &VectorVel::Norm)
        .def(py::self += py::self)
        .def(py::self -= py::self)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(Vector() + py::self)
        .def(Vector() - py::self)
        .def(py::self + Vector())
        .def(py::self - Vector())

        .def(py::self * py::self)
        .def(py::self * Vector())
        .def(Vector() * py::self)
        .def(double() * py::self)
        .def(py::self * double())
        .def(doubleVel() * py::self)
        .def(py::self * doubleVel())
        .def(Rotation() * py::self)

        .def(py::self / double())
        .def(py::self / doubleVel())
        .def("__neg__", [](const VectorVel &a) {
            return operator-(a);
        }, py::is_operator())
        ;

    m.def("Equal", (bool (*)(const VectorVel&, const VectorVel&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);
    m.def("Equal", (bool (*)(const Vector&, const VectorVel&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);
    m.def("Equal", (bool (*)(const VectorVel&, const Vector&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);

    m.def("dot", (doubleVel (*)(const VectorVel&, const VectorVel&)) &KDL::dot);
    m.def("dot", (doubleVel (*)(const VectorVel&, const Vector&)) &KDL::dot);
    m.def("dot", (doubleVel (*)(const Vector&, const VectorVel&)) &KDL::dot);


    // --------------------
    // RotationVel
    // --------------------
    py::class_<RotationVel>(m, "RotationVel")
        .def_readwrite("R", &RotationVel::R)
        .def_readwrite("w", &RotationVel::w)
        .def(py::init<>())
        .def(py::init<const Rotation&>())
        .def(py::init<const Rotation&, const Vector&>())
        .def(py::init<const RotationVel&>())
        .def("value", &RotationVel::value)
        .def("deriv", &RotationVel::deriv)
        .def("UnitX", &RotationVel::UnitX)
        .def("UnitY", &RotationVel::UnitY)
        .def("UnitZ", &RotationVel::UnitZ)
        .def_static("Identity", &RotationVel::Identity)
        .def("Inverse", (RotationVel (RotationVel::*)(void) const) &RotationVel::Inverse)
        .def("Inverse", (VectorVel (RotationVel::*)(const VectorVel&) const) &RotationVel::Inverse)
        .def("Inverse", (VectorVel (RotationVel::*)(const Vector&) const) &RotationVel::Inverse)
        .def("DoRotX", &RotationVel::DoRotX)
        .def("DoRotY", &RotationVel::DoRotY)
        .def("DoRotZ", &RotationVel::DoRotZ)
        .def_static("RotX", &RotationVel::RotX)
        .def_static("RotY", &RotationVel::RotY)
        .def_static("RotZ", &RotationVel::RotZ)
        .def_static("Rot", &RotationVel::Rot)
        .def_static("Rot2", &RotationVel::Rot2)

        .def("Inverse", (TwistVel (RotationVel::*)(const TwistVel&) const) &RotationVel::Inverse)
        .def("Inverse", (TwistVel (RotationVel::*)(const Twist&) const) &RotationVel::Inverse)

        .def(py::self * VectorVel())
        .def(py::self * Vector())
        .def(py::self * TwistVel())
        .def(py::self * Twist())
        .def(py::self * py::self)
        .def(Rotation() * py::self)
        .def(py::self * Rotation())
        ;

    m.def("Equal", (bool (*)(const RotationVel&, const RotationVel&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);
    m.def("Equal", (bool (*)(const Rotation&, const RotationVel&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);
    m.def("Equal", (bool (*)(const RotationVel&, const Rotation&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);


    // --------------------
    // FrameVel
    // --------------------
    py::class_<FrameVel>(m, "FrameVel")
        .def_readwrite("M", &FrameVel::M)
        .def_readwrite("p", &FrameVel::p)
        .def(py::init<>())
        .def(py::init<const Frame&>())
        .def(py::init<const Frame&, const Twist&>())
        .def(py::init<const RotationVel&, const VectorVel&>())
        .def(py::init<const FrameVel&>())
        .def("value", &FrameVel::value)
        .def("deriv", &FrameVel::deriv)
        .def_static("Identity", &FrameVel::Identity)
        .def("Inverse", (FrameVel (FrameVel::*)() const) &FrameVel::Inverse)
        .def("Inverse", (VectorVel (FrameVel::*)(const VectorVel&) const) &FrameVel::Inverse)
        .def("Inverse", (VectorVel (FrameVel::*)(const Vector&) const) &FrameVel::Inverse)
        .def(py::self * VectorVel())
        .def(py::self * Vector())
        .def("GetFrame", &FrameVel::GetFrame)
        .def("GetTwist", &FrameVel::GetTwist)
        .def("Inverse", (TwistVel (FrameVel::*)(const TwistVel&) const) &FrameVel::Inverse)
        .def("Inverse", (TwistVel (FrameVel::*)(const Twist&) const) &FrameVel::Inverse)
        .def(py::self * TwistVel())
        .def(py::self * Twist())
        .def(py::self * py::self)
        .def(Frame() * py::self)
        .def(py::self * Frame())
        ;

    m.def("Equal", (bool (*)(const FrameVel&, const FrameVel&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);
    m.def("Equal", (bool (*)(const Frame&, const FrameVel&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);
    m.def("Equal", (bool (*)(const FrameVel&, const Frame&, double)) &KDL::Equal,
          py::arg("r1"), py::arg("r2"), py::arg("eps")=epsilon);


    // --------------------
    // TwistVel
    // --------------------
    py::class_<TwistVel>(m, "TwistVel")
        .def_readwrite("vel", &TwistVel::vel)
        .def_readwrite("rot", &TwistVel::rot)
        .def(py::init<>())
        .def(py::init<const VectorVel&, const VectorVel&>())
        .def(py::init<const Twist&, const Twist&>())
        .def(py::init<const Twist&>())
        .def("value", &TwistVel::value)
        .def("deriv", &TwistVel::deriv)
        .def_static("Zero", &TwistVel::Zero)
        .def("ReverseSign", &TwistVel::ReverseSign)
        .def("RefPoint", &TwistVel::RefPoint)
        .def("GetTwist", &TwistVel::GetTwist)
        .def("GetTwistDot", &TwistVel::GetTwistDot)

        .def(py::self -= py::self)
        .def(py::self += py::self)
        .def(py::self * double())
        .def(double() * py::self)
        .def(py::self / double())

        .def(py::self * doubleVel())
        .def(doubleVel() * py::self)
        .def(py::self / doubleVel())

        .def(py::self + py::self)
        .def(py::self - py::self)
        .def("__neg__", [](const TwistVel &a) {
            return operator-(a);
        }, py::is_operator())
        ;

    m.def("SetToZero", (void (*)(TwistVel&)) &KDL::SetToZero);
    m.def("Equal", (bool (*)(const TwistVel&, const TwistVel&, double)) &KDL::Equal,
          py::arg("a"), py::arg("b"), py::arg("eps")=epsilon);
    m.def("Equal", (bool (*)(const Twist&, const TwistVel&, double)) &KDL::Equal,
          py::arg("a"), py::arg("b"), py::arg("eps")=epsilon);
    m.def("Equal", (bool (*)(const TwistVel&, const Twist&, double)) &KDL::Equal,
          py::arg("a"), py::arg("b"), py::arg("eps")=epsilon);


    // --------------------
    // Global
    // --------------------
    m.def("diff", (VectorVel (*)(const VectorVel&, const VectorVel&, double)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt")=1.0);
    m.def("diff", (VectorVel (*)(const RotationVel&, const RotationVel&, double)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt")=1.0);
    m.def("diff", (TwistVel (*)(const FrameVel&, const FrameVel&, double)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt")=1.0);

    m.def("addDelta", (VectorVel (*)(const VectorVel&, const VectorVel&, double)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt")=1.0);
    m.def("addDelta", (RotationVel (*)(const RotationVel&, const VectorVel&, double)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt")=1.0);
    m.def("addDelta", (FrameVel (*)(const FrameVel&, const TwistVel&, double)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt")=1.0);
}
