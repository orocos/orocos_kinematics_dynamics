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


#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include "PyKDL.h"

namespace py = pybind11;
using namespace KDL;

void init_frames(py::module &m)
{
    // --------------------
    // Vector
    // --------------------
    py::class_<Vector>(m, "Vector")
        .def(py::init<>())
        .def(py::init<double, double, double>())
        .def(py::init<const Vector&>())
        .def("x", (void (Vector::*)(double)) &Vector::x, "Set x")
        .def("y", (void (Vector::*)(double)) &Vector::y, "Set y")
        .def("z", (void (Vector::*)(double)) &Vector::z, "Set z")
        .def("x", (double (Vector::*)(void) const) &Vector::x, "Get x")
        .def("y", (double (Vector::*)(void) const) &Vector::y, "Get y")
        .def("z", (double (Vector::*)(void) const) &Vector::z, "Get z")
        .def("__getitem__", [](const Vector &v, int i) {
            if (i < 0 || i > 2) throw py::index_error("Vector index out of range");
            return v(i);
        })
        .def("__setitem__", [](Vector &v, int i, double value) {
            if (i < 0 || i > 2) throw py::index_error("Vector index out of range");
            v(i) = value;
        })
        .def("__repr__", [](const Vector &v) {
            std::ostringstream oss;
            oss<<v;
            return oss.str();
        })
        .def("ReverseSign", &Vector::ReverseSign)
        .def(py::self -= py::self)
        .def(py::self += py::self)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self * double())
        .def(double() * py::self)
        .def(py::self / double())
        .def(py::self * py::self)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def("__neg__", [](const Vector &a) {
            return operator-(a);
        }, py::is_operator())
        .def_static("Zero", &Vector::Zero)
        .def("Norm", &Vector::Norm)
        .def("Normalize", &Vector::Normalize, py::arg("eps")=epsilon)
        .def(py::pickle(
            [](const Vector &v) { // __getstate__
                /* Return a tuple that fully encodes the state of the object */
                return py::make_tuple(v.x(), v.y(), v.z());
            },
            [](py::tuple t) { // __setstate__
                if (t.size() != 3) {
                    std::cout << "size error\n";
                    throw std::runtime_error("Invalid state!");
                }

                /* Create a new C++ instance */
                Vector v(t[0].cast<double>(), t[1].cast<double>(), t[2].cast<double>());
                return v;
            }))
        ;

    m.def("SetToZero", (void (*)(Vector&)) &KDL::SetToZero);
    m.def("dot", (double (*)(const Vector&, const Vector&)) &KDL::dot);
    m.def("Equal", (bool (*)(const Vector&, const Vector&, double)) &KDL::Equal,
          py::arg("a"), py::arg("b"), py::arg("eps")=epsilon);


    // --------------------
    // Rotation
    // --------------------
    py::class_<Rotation>(m, "Rotation")
        .def(py::init<>())
        .def(py::init<double, double, double, double, double, double, double, double, double>())
        .def(py::init<const Vector&, const Vector&, const Vector&>())
        .def(py::init<const Rotation&>())
        .def("__getitem__", [](const Rotation &r, int i, int j) {
            if (i < 0 || i > 2 || j < 0 || j > 2) throw py::index_error("Vector index out of range");
            return r(i, j);
        })
        .def("__repr__", [](const Rotation &r) {
            std::ostringstream oss;
            oss<<r;
            return oss.str();
        })
        .def("SetInverse", &Rotation::SetInverse)
        .def("Inverse", (Rotation (Rotation::*)(void) const) &Rotation::Inverse)
        .def("Inverse", (Vector (Rotation::*)(const Vector&) const) &Rotation::Inverse)
        .def("Inverse", (Wrench (Rotation::*)(const Wrench&) const) &Rotation::Inverse)
        .def("Inverse", (Twist (Rotation::*)(const Twist&) const) &Rotation::Inverse)
        .def_static("Identity", &Rotation::Identity)
        .def_static("RotX", &Rotation::RotX)
        .def_static("RotY", &Rotation::RotY)
        .def_static("RotZ", &Rotation::RotZ)
        .def_static("Rot", &Rotation::Rot)
        .def_static("Rot2", &Rotation::Rot2)
        .def_static("EulerZYZ", &Rotation::EulerZYZ)
        .def_static("RPY", &Rotation::RPY)
        .def_static("EulerZYX", &Rotation::EulerZYX)
        .def_static("Quaternion", &Rotation::Quaternion)
        .def("DoRotX", &Rotation::DoRotX)
        .def("DoRotY", &Rotation::DoRotY)
        .def("DoRotZ", &Rotation::DoRotZ)
        .def("GetRot", &Rotation::GetRot)
        .def("GetRotAngle", [](const Rotation &r, double eps) {
            Vector axis;
            double ret = r.GetRotAngle(axis, eps);
            return py::make_tuple(ret, axis);
        }, py::arg("eps") = epsilon)
        .def("GetEulerZYZ", [](const Rotation &r) {
            double Alfa, Beta, Gamma;
            r.GetEulerZYZ(Alfa, Beta, Gamma);
            return py::make_tuple(Alfa, Beta, Gamma);
        })
        .def("GetRPY", [](const Rotation &r) {
            double roll, pitch, yaw;
            r.GetRPY(roll, pitch, yaw);
            return py::make_tuple(roll, pitch, yaw);
        })
        .def("GetEulerZYX", [](const Rotation &r) {
            double Alfa, Beta, Gamma;
            r.GetEulerZYX(Alfa, Beta, Gamma);
            return py::make_tuple(Alfa, Beta, Gamma);
        })
        .def("GetQuaternion", [](const Rotation &r) {
            double x, y, z, w;
            r.GetQuaternion(x, y, z, w);
            return py::make_tuple(x, y, z, w);
        })
        .def("UnitX", (Vector (Rotation::*)() const) &Rotation::UnitX)
        .def("UnitY", (Vector (Rotation::*)() const) &Rotation::UnitY)
        .def("UnitZ", (Vector (Rotation::*)() const) &Rotation::UnitZ)
        .def("UnitX", (void (Rotation::*)(const Vector&)) &Rotation::UnitX)
        .def("UnitY", (void (Rotation::*)(const Vector&)) &Rotation::UnitY)
        .def("UnitZ", (void (Rotation::*)(const Vector&)) &Rotation::UnitZ)
        .def(py::self * Vector())
        .def(py::self * Twist())
        .def(py::self * Wrench())
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self * py::self)
        .def(py::pickle(
            [](const Rotation &rot) { // __getstate__
                /* Return a tuple that fully encodes the state of the object */
                double roll{0}, pitch{0}, yaw{0};
                rot.GetRPY(roll, pitch, yaw);
                return py::make_tuple(roll, pitch, yaw);
            },
            [](py::tuple t) { // __setstate__
                if (t.size() != 3) { throw std::runtime_error("Invalid state!"); }
                /* Create a new C++ instance */
                return Rotation::RPY(t[0].cast<double>(), t[1].cast<double>(), t[2].cast<double>());
            }))
        ;

    m.def("Equal", (bool (*)(const Rotation&, const Rotation&, double eps)) &KDL::Equal,
          py::arg("a"), py::arg("b"), py::arg("eps")=epsilon);


    // --------------------
    // Frame
    // --------------------
    py::class_<Frame>(m, "Frame")
        .def(py::init<const Rotation&, const Vector&>())
        .def(py::init<const Vector&>())
        .def(py::init<const Rotation&>())
        .def(py::init<const Frame&>())
        .def(py::init<>())
        .def_readwrite("M", &Frame::M)
        .def_readwrite("p", &Frame::p)
        .def("__getitem__", [](const Frame &frm, std::tuple<int, int> idx) {
            int i = std::get<0>(idx);
            int j = std::get<1>(idx);
            if (i < 0 || i > 2 || j < 0 || j > 3) {
                throw py::index_error("Frame index out of range");
            }
            return frm((unsigned int)i, (unsigned int)j);
        })
        .def("__setitem__", [](Frame &frm, std::tuple<int, int> idx, double value) {
            int i = std::get<0>(idx);
            int j = std::get<1>(idx);
            if (i < 0 || i > 2 || j < 0 || j > 3) {
                throw py::index_error("Frame index out of range");
            }
            if (j == 3) {
                frm.p(i) = value;
            } else {
                frm.M(i, j) = value;
            }
        })
        .def("__repr__", [](const Frame &frm) {
            std::ostringstream oss;
            oss << frm;
            return oss.str();
        })
        .def("DH_Craig1989", &Frame::DH_Craig1989)
        .def("DH", &Frame::DH)
        .def("Inverse", (Frame (Frame::*)() const) &Frame::Inverse)
        .def("Inverse", (Vector (Frame::*)(const Vector&) const) &Frame::Inverse)
        .def("Inverse", (Wrench (Frame::*)(const Wrench&) const) &Frame::Inverse)
        .def("Inverse", (Twist (Frame::*)(const Twist&) const) &Frame::Inverse)
        .def_static("Identity", &Frame::Identity)
        .def("Integrate", &Frame::Integrate)
        .def(py::self * Vector())
        .def(py::self * Wrench())
        .def(py::self * Twist())
        .def(py::self * py::self)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::pickle(
            [](const Frame &frm) { // __getstate__
                /* Return a tuple that fully encodes the state of the object */
                return py::make_tuple(frm.M, frm.p);
            },
            [](py::tuple t) { // __setstate__
                if (t.size() != 2) {
                    throw std::runtime_error("Invalid state!");
                }

                /* Create a new C++ instance */
                Frame frm(t[0].cast<Rotation>(), t[1].cast<Vector>());
                return frm;
            }))
        ;

    m.def("Equal", (bool (*)(const Frame&, const Frame&, double eps)) &KDL::Equal,
          py::arg("a"), py::arg("b"), py::arg("eps")=epsilon);


    // --------------------
    // Twist
    // --------------------
    py::class_<Twist>(m, "Twist")
        .def(py::init<>())
        .def(py::init<const Vector&, const Vector&>())
        .def(py::init<const Twist&>())
        .def_readwrite("vel", &Twist::vel)
        .def_readwrite("rot", &Twist::rot)
        .def("__getitem__", [](const Twist &t, int i) {
            if (i < 0 || i > 5) {
                throw py::index_error("Twist index out of range");
            }
            return t(i);
        })
        .def("__setitem__", [](Twist &t, int i, double value) {
            if (i < 0 || i > 5) {
                throw py::index_error("Twist index out of range");
            }
            t(i) = value;
        })
        .def("__repr__", [](const Twist &t) {
            std::ostringstream oss;
            oss << t;
            return oss.str();
        })
        .def_static("Zero", &Twist::Zero)
        .def("ReverseSign", &Twist::ReverseSign)
        .def("RefPoint", &Twist::RefPoint)
        .def(py::self -= py::self)
        .def(py::self += py::self)
        .def(py::self * double())
        .def(double() * py::self)
        .def(py::self / double())
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def("__neg__", [](const Twist &a) {
            return operator-(a);
        }, py::is_operator())
        .def(py::pickle(
            [](const Twist &tt) { // __getstate__
                /* Return a tuple that fully encodes the state of the object */
                return py::make_tuple(tt.vel, tt.rot);
            },
            [](py::tuple t) { // __setstate__
                if (t.size() != 2) {
                    throw std::runtime_error("Invalid state!");
                }

                /* Create a new C++ instance */
                Twist tt(t[0].cast<Vector>(), t[1].cast<Vector>());
                return tt;
            }))
        ;

    m.def("dot", (double (*)(const Twist&, const Wrench&)) &KDL::dot);
    m.def("dot", (double (*)(const Wrench&, const Twist&)) &KDL::dot);
    m.def("SetToZero", (void (*)(Twist&)) &KDL::SetToZero);
    m.def("Equal", (bool (*)(const Twist&, const Twist&, double eps)) &KDL::Equal,
          py::arg("a"), py::arg("b"), py::arg("eps")=epsilon);


    // --------------------
    // Wrench
    // --------------------
    py::class_<Wrench>(m, "Wrench")
        .def(py::init<>())
        .def(py::init<const Vector&, const Vector&>())
        .def(py::init<const Wrench&>())
        .def_readwrite("force", &Wrench::force)
        .def_readwrite("torque", &Wrench::torque)
        .def("__getitem__", [](const Wrench &t, int i) {
            if (i < 0 || i > 5) {
                throw py::index_error("Wrench index out of range");
            }
            return t(i);
        })
        .def("__setitem__", [](Wrench &t, int i, double value) {
            if (i < 0 || i > 5) {
                throw py::index_error("Wrench index out of range");
            }
            t(i) = value;
        })
        .def("__repr__", [](const Wrench &t) {
            std::ostringstream oss;
            oss << t;
            return oss.str();
        })
        .def_static("Zero", &Wrench::Zero)
        .def("ReverseSign", &Wrench::ReverseSign)
        .def("RefPoint", &Wrench::RefPoint)
        .def(py::self -= py::self)
        .def(py::self += py::self)
        .def(py::self * double())
        .def(double() * py::self)
        .def(py::self / double())
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def("__neg__", [](const Wrench &w) {
            return operator-(w);
        }, py::is_operator())
        .def(py::pickle(
            [](const Wrench &wr) { // __getstate__
                /* Return a tuple that fully encodes the state of the object */
                return py::make_tuple(wr.force, wr.torque);
            },
            [](py::tuple t) { // __setstate__
                if (t.size() != 2) {
                    throw std::runtime_error("Invalid state!");
                }

                /* Create a new C++ instance */
                Wrench wr(t[0].cast<Vector>(), t[1].cast<Vector>());
                return wr;
            }))
        ;

    m.def("SetToZero", (void (*)(Wrench&)) &KDL::SetToZero);
    m.def("Equal", (bool (*)(const Wrench&, const Wrench&, double eps)) &KDL::Equal,
          py::arg("a"), py::arg("b"), py::arg("eps")=epsilon);


    // --------------------
    // Global
    // --------------------
    m.def("diff", (Vector (*)(const Vector&, const Vector&, double dt)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt") = 1);
    m.def("diff", (Vector (*)(const Rotation&, const Rotation&, double dt)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt") = 1);
    m.def("diff", (Twist (*)(const Frame&, const Frame&, double dt)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt") = 1);
    m.def("diff", (Twist (*)(const Twist&, const Twist&, double dt)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt") = 1);
    m.def("diff", (Wrench (*)(const Wrench&, const Wrench&, double dt)) &KDL::diff,
          py::arg("a"), py::arg("b"), py::arg("dt") = 1);
    m.def("addDelta", (Vector (*)(const Vector&, const Vector&, double dt)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt") = 1);
    m.def("addDelta", (Rotation (*)(const Rotation&, const Vector&, double dt)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt") = 1);
    m.def("addDelta", (Frame (*)(const Frame&, const Twist&, double dt)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt") = 1);
    m.def("addDelta", (Twist (*)(const Twist&, const Twist&, double dt)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt") = 1);
    m.def("addDelta", (Wrench (*)(const Wrench&, const Wrench&, double dt)) &KDL::addDelta,
          py::arg("a"), py::arg("da"), py::arg("dt") = 1);
}
