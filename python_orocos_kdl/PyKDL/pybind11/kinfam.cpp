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


#include <kdl/joint.hpp>
#include <kdl/rotationalinertia.hpp>
#include <kdl/rigidbodyinertia.hpp>
#include <kdl/chain.hpp>
#include <kdl/tree.hpp>
#include <kdl/jntarrayvel.hpp>
#include <kdl/chainiksolver.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainfksolvervel_recursive.hpp>
#include <kdl/chainiksolverpos_nr.hpp>
#include <kdl/chainiksolverpos_nr_jl.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainiksolvervel_wdls.hpp>
#include <kdl/chainiksolverpos_lma.hpp>
#include <kdl/chainiksolvervel_pinv_nso.hpp>
#include <kdl/chainiksolvervel_pinv_givens.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/chainidsolver_recursive_newton_euler.hpp>
#include <kdl/kinfam_io.hpp>
#include "PyKDL.h"

namespace py = pybind11;
using namespace KDL;

void init_kinfam(pybind11::module &m)
{
    // --------------------
    // Joint
    // --------------------
    py::class_<Joint> joint(m, "Joint");
    py::enum_<Joint::JointType>(joint, "JointType")
        .value("RotAxis", Joint::JointType::RotAxis)
        .value("RotX", Joint::JointType::RotX)
        .value("RotY", Joint::JointType::RotY)
        .value("RotZ", Joint::JointType::RotZ)
        .value("TransAxis", Joint::JointType::TransAxis)
        .value("TransX", Joint::JointType::TransX)
        .value("TransY", Joint::JointType::TransY)
        .value("TransZ", Joint::JointType::TransZ)
        .value("None", Joint::JointType::None)
        .export_values()
        ;

    joint.def(py::init<>());
    joint.def(py::init<std::string, Joint::JointType, double, double, double, double, double>(),
              py::arg("name"), py::arg("type")=Joint::JointType::None, py::arg("scale")=1, py::arg("offset")=0,
              py::arg("inertia")=0, py::arg("damping")=0, py::arg("stiffness")=0);
    joint.def(py::init<Joint::JointType, double, double, double, double, double>(),
              py::arg("type")=Joint::JointType::None, py::arg("scale")=1, py::arg("offset")=0,
              py::arg("inertia")=0, py::arg("damping")=0, py::arg("stiffness")=0);
    joint.def(py::init<std::string, Vector, Vector, Joint::JointType, double, double, double, double, double>(),
              py::arg("name"), py::arg("origin"), py::arg("axis"), py::arg("type"), py::arg("scale")=1, py::arg("offset")=0,
              py::arg("inertia")=0, py::arg("damping")=0, py::arg("stiffness")=0);
    joint.def(py::init<Vector, Vector, Joint::JointType, double, double, double, double, double>(),
              py::arg("origin"), py::arg("axis"), py::arg("type"), py::arg("scale")=1, py::arg("offset")=0,
              py::arg("inertia")=0, py::arg("damping")=0, py::arg("stiffness")=0);
    joint.def(py::init<const Joint&>());
    joint.def("pose", &Joint::pose);
    joint.def("twist", &Joint::twist);
    joint.def("JointAxis", &Joint::JointAxis);
    joint.def("JointOrigin", &Joint::JointOrigin);
    joint.def("getName", &Joint::getName);
    joint.def("getType", &Joint::getType);
    joint.def("getTypeName", &Joint::getTypeName);
    joint.def("__repr__", [](const Joint &j) {
        std::ostringstream oss;
        oss << j;
        return oss.str();
    });


    // --------------------
    // RotationalInertia
    // --------------------
    py::class_<RotationalInertia>(m, "RotationalInertia")
        .def(py::init<double, double, double, double, double, double>(),
             py::arg("Ixx")=0, py::arg("Iyy")=0, py::arg("Izz")=0,
             py::arg("Ixy")=0, py::arg("Ixz")=0, py::arg("Iyz")=0)
        .def_static("Zero", &RotationalInertia::Zero)
        .def("__getitem__", [](const RotationalInertia &inertia, int i) {
            if (i < 0 || i > 8) {
                throw py::index_error("RotationalInertia index out of range");
            }
            return inertia.data[i];
        })
        .def("__setitem__", [](RotationalInertia &inertia, int i, double value) {
            if (i < 0 || i > 8) {
                throw py::index_error("RotationalInertia index out of range");
            }
            inertia.data[i] = value;
        })
        .def(double() * py::self)
        .def(py::self + py::self)
        .def(py::self * Vector())
        ;

    // --------------------
    // RigidBodyInertia
    // --------------------
    py::class_<RigidBodyInertia>(m, "RigidBodyInertia")
        .def(py::init<double, const Vector&, const RotationalInertia&>(),
                py::arg("m")=0, py::arg_v("oc", Vector::Zero(), "Vector.Zero"), py::arg_v("Ic", RotationalInertia::Zero(), "RigidBodyInertia.Zero"))
        .def_static("Zero", &RigidBodyInertia::Zero)
        .def("RefPoint", &RigidBodyInertia::RefPoint)
        .def("getMass", &RigidBodyInertia::getMass)
        .def("getCOG", &RigidBodyInertia::getCOG)
        .def("getRotationalInertia", &RigidBodyInertia::getRotationalInertia)
        .def(double() * py::self)
        .def(py::self + py::self)
        .def(py::self * Twist())
        .def(Frame() * py::self)
        .def(Rotation() * py::self)
        ;

    // --------------------
    // Segment
    // --------------------
    py::class_<Segment>(m, "Segment")
        .def(py::init<const std::string&, const Joint&, const Frame&, const RigidBodyInertia&>(),
             py::arg("name"), py::arg_v("joint", Joint(), "Joint"), py::arg_v("f_tip", Frame::Identity(), "Frame.Identity"), py::arg_v("I", RigidBodyInertia::Zero(), "RigidBodyInertia.Zero"))
        .def(py::init<const Joint&, const Frame&, const RigidBodyInertia&>(),
             py::arg_v("joint", Joint(), "Joint"), py::arg_v("f_tip", Frame::Identity(), "Frame.Identity"), py::arg_v("I", RigidBodyInertia::Zero(), "RigidBodyInertia.Zero"))
        .def(py::init<const Segment&>())
        .def("getFrameToTip", &Segment::getFrameToTip)
        .def("pose", &Segment::pose)
        .def("twist", &Segment::twist)
        .def("getName", &Segment::getName)
        .def("getJoint", &Segment::getJoint)
        .def("getInertia", &Segment::getInertia)
        .def("setInertia", &Segment::setInertia)
        ;

    // --------------------
    // Chain
    // --------------------
    py::class_<Chain>(m, "Chain")
            .def(py::init<>())
        .def(py::init<const Chain&>())
        .def("addSegment", &Chain::addSegment)
        .def("addChain", &Chain::addChain)
        .def("getNrOfJoints", &Chain::getNrOfJoints)
        .def("getNrOfSegments", &Chain::getNrOfSegments)
        .def("getSegment", (Segment& (Chain::*)(unsigned int)) &Chain::getSegment)
        .def("getSegment", (const Segment& (Chain::*)(unsigned int) const) &Chain::getSegment)
        ;

    // --------------------
    // Tree
    // --------------------
    py::class_<Tree>(m, "Tree")
        .def(py::init<const std::string&>(), py::arg("root_name")="root")
        .def("addSegment", &Tree::addSegment)
        .def("addChain", &Tree::addChain)
        .def("addTree", &Tree::addTree)
        .def("getNrOfJoints", &Tree::getNrOfJoints)
        .def("getNrOfSegments", &Tree::getNrOfSegments)
        .def("getSegment", &Tree::getSegment)
        .def("getRootSegment", &Tree::getRootSegment)
        .def("getChain", [](const Tree &tree, const std::string& chain_root, const std::string& chain_tip) {
            Chain* chain = new Chain();
            tree.getChain(chain_root, chain_tip, *chain);
            return chain;
        })
        ;

    // --------------------
    // JntArray
    // --------------------
    py::class_<JntArray>(m, "JntArray")
        .def(py::init<unsigned int>())
        .def(py::init<const JntArray&>())
        .def("rows", &JntArray::rows)
        .def("columns", &JntArray::columns)
        .def("resize", &JntArray::resize)
        .def("__getitem__", [](const JntArray &ja, int i) {
            if (i < 0 || i > ja.rows()) {
                throw py::index_error("JntArray index out of range");
            }
            return ja(i);
        })
        .def("__setitem__", [](JntArray &ja, int i, double value) {
            if (i < 0 || i > ja.rows()) {
                throw py::index_error("JntArray index out of range");
            }
            ja(i) = value;
        })
        .def("__repr__", [](const JntArray &ja) {
            std::ostringstream oss;
            oss << ja;
            return oss.str();
        })
        .def(py::self == py::self)
        ;

    m.def("Add", (void (*)(const JntArray&, const JntArray&, JntArray&)) &KDL::Add);
    m.def("Subtract", (void (*)(const JntArray&, const JntArray&, JntArray&)) &KDL::Subtract);
    m.def("Multiply", (void (*)(const JntArray&, const double&, JntArray&)) &KDL::Multiply);
    m.def("Divide", (void (*)(const JntArray&, const double&, JntArray&)) &KDL::Divide);
    m.def("MultiplyJacobian", (void (*)(const Jacobian&, const JntArray&, Twist&)) &KDL::MultiplyJacobian);
    m.def("SetToZero", (void (*)(JntArray&)) &KDL::SetToZero);
    m.def("Equal", (bool (*)(const JntArray&, const JntArray&, double)) &KDL::Equal,
          py::arg("src1"), py::arg("src2"), py::arg("eps")=epsilon);


    // --------------------
    // JntArrayVel
    // --------------------
    py::class_<JntArrayVel>(m, "JntArrayVel")
        .def_readwrite("q", &JntArrayVel::q)
        .def_readwrite("qdot", &JntArrayVel::qdot)
        .def(py::init<unsigned int>())
        .def(py::init<const JntArray&, const JntArray&>())
        .def(py::init<const JntArray&>())
        .def("resize", &JntArrayVel::resize)
        .def("value", &JntArrayVel::value)
        .def("deriv", &JntArrayVel::deriv)
        ;

    m.def("Add", (void (*)(const JntArrayVel&, const JntArrayVel&, JntArrayVel&)) &KDL::Add);
    m.def("Add", (void (*)(const JntArrayVel&, const JntArray&, JntArrayVel&)) &KDL::Add);
    m.def("Subtract", (void (*)(const JntArrayVel&, const JntArrayVel&, JntArrayVel&)) &KDL::Subtract);
    m.def("Subtract", (void (*)(const JntArrayVel&, const JntArray&, JntArrayVel&)) &KDL::Subtract);
    m.def("Multiply", (void (*)(const JntArrayVel&, const double&, JntArrayVel&)) &KDL::Multiply);
    m.def("Multiply", (void (*)(const JntArrayVel&, const doubleVel&, JntArrayVel&)) &KDL::Multiply);
    m.def("Divide", (void (*)(const JntArrayVel&, const double&, JntArrayVel&)) &KDL::Divide);
    m.def("Divide", (void (*)(const JntArrayVel&, const doubleVel&, JntArrayVel&)) &KDL::Divide);
    m.def("SetToZero", (void (*)(JntArrayVel&)) &KDL::SetToZero);
    m.def("Equal", (bool (*)(const JntArrayVel&, const JntArrayVel&, double)) &KDL::Equal,
          py::arg("src1"), py::arg("src2"), py::arg("eps")=epsilon);


    // --------------------
    // Jacobian
    // --------------------
    py::class_<Jacobian>(m, "Jacobian")
        .def(py::init<unsigned int>())
        .def(py::init<const Jacobian&>())
        .def("rows", &Jacobian::rows)
        .def("columns", &Jacobian::columns)
        .def("resize", &Jacobian::resize)
        .def("getColumn", &Jacobian::getColumn)
        .def("setColumn", &Jacobian::setColumn)
        .def("changeRefPoint", &Jacobian::changeRefPoint)
        .def("changeBase", &Jacobian::changeBase)
        .def("changeRefFrame", &Jacobian::changeRefFrame)
        .def("__getitem__", [](const Jacobian &jac, std::tuple<int, int> idx) {
            int i = std::get<0>(idx);
            int j = std::get<1>(idx);
            if (i < 0 || i > 5 || j < 0 || j > jac.columns()) {
                throw py::index_error("Jacobian index out of range");
            }
            return jac((unsigned int)i, (unsigned int)j);
        })
        .def("__setitem__", [](Jacobian &jac, std::tuple<int, int> idx, double value) {
            int i = std::get<0>(idx);
            int j = std::get<1>(idx);
            if (i < 0 || i > 5 || j < 0 || j > jac.columns()) {
                throw py::index_error("Jacobian index out of range");
            }
            jac((unsigned int)i, (unsigned int)j) = value;
        })
        .def("__repr__", [](const Jacobian &jac) {
            std::ostringstream oss;
            oss << jac;
            return oss.str();
        })
        ;

    m.def("SetToZero", (void (*)(Jacobian&)) &KDL::SetToZero);
    m.def("changeRefPoint", (void (*)(const Jacobian&, const Vector&, Jacobian&)) &KDL::changeRefPoint);
    m.def("changeBase", (void (*)(const Jacobian&, const Rotation&, Jacobian&)) &KDL::changeBase);
    m.def("SetToZero", (void (*)(const Jacobian&, const Frame&, Jacobian&)) &KDL::changeRefFrame);


    // --------------------
    // SolverI
    // --------------------
    py::class_<SolverI>(m, "SolverI")
        .def("getError", &SolverI::getError)
        .def("strError", &SolverI::strError)
        .def("updateInternalDataStructures", &SolverI::updateInternalDataStructures)
        ;

    // --------------------
    // ChainFkSolverPos
    // --------------------
    py::class_<ChainFkSolverPos, SolverI>(m, "ChainFkSolverPos")
        .def("JntToCart", (int (ChainFkSolverPos::*)(const JntArray&, Frame&, int)) &ChainFkSolverPos::JntToCart,
             py::arg("q_in"), py::arg("p_out"), py::arg("segmentNr")=-1)
        ;

    // --------------------
    // ChainFkSolverVel
    // --------------------
    py::class_<ChainFkSolverVel, SolverI>(m, "ChainFkSolverVel")
        .def("JntToCart", (int (ChainFkSolverVel::*)(const JntArrayVel&, FrameVel&, int)) &ChainFkSolverVel::JntToCart,
             py::arg("q_in"), py::arg("p_out"), py::arg("segmentNr")=-1)
        ;

    // ------------------------------
    // ChainFkSolverPos_recursive
    // ------------------------------
    py::class_<ChainFkSolverPos_recursive, ChainFkSolverPos>(m, "ChainFkSolverPos_recursive")
        .def(py::init<const Chain&>())
        ;


    // ------------------------------
    // ChainFkSolverVel_recursive
    // ------------------------------
    py::class_<ChainFkSolverVel_recursive, ChainFkSolverVel>(m, "ChainFkSolverVel_recursive")
        .def(py::init<const Chain&>())
        ;

    // --------------------
    // ChainIkSolverPos
    // --------------------
    py::class_<ChainIkSolverPos, SolverI>(m, "ChainIkSolverPos")
        .def("CartToJnt", (int (ChainIkSolverPos::*)(const JntArray&, const Frame&, JntArray&)) &ChainIkSolverPos::CartToJnt,
             py::arg("q_init"), py::arg("p_in"), py::arg("q_out"))
        ;

    // --------------------
    // ChainIkSolverVel
    // --------------------
    py::class_<ChainIkSolverVel, SolverI>(m, "ChainIkSolverVel")
        .def("CartToJnt", (int (ChainIkSolverVel::*)(const JntArray&, const Twist&, JntArray&)) &ChainIkSolverVel::CartToJnt,
             py::arg("q_in"), py::arg("v_in"), py::arg("qdot_out"))
        .def("CartToJnt", (int (ChainIkSolverVel::*)(const JntArray&, const FrameVel&, JntArrayVel&)) &ChainIkSolverVel::CartToJnt,
             py::arg("q_init"), py::arg("v_in"), py::arg("q_out"))
        ;


    // --------------------
    // ChainIkSolverPos_NR
    // --------------------
    py::class_<ChainIkSolverPos_NR, ChainIkSolverPos>(m, "ChainIkSolverPos_NR")
        .def(py::init<const Chain&, ChainFkSolverPos&, ChainIkSolverVel&, unsigned int, double>(),
             py::arg("chain"), py::arg("fksolver"), py::arg("iksolver"),
             py::arg("maxiter")=100, py::arg("eps")=epsilon)
        ;

    // ---------------------------
    // ChainIkSolverPos_NR_JL
    // ---------------------------
    py::class_<ChainIkSolverPos_NR_JL, ChainIkSolverPos>(m, "ChainIkSolverPos_NR_JL")
        .def(py::init<const Chain&, const JntArray&,
                     const JntArray&, ChainFkSolverPos&, ChainIkSolverVel&, unsigned int, double>(),
             py::arg("chain"), py::arg("q_min"), py::arg("q_max"), py::arg("fksolver"), py::arg("iksolver"),
             py::arg("maxiter")=100, py::arg("eps")=epsilon)
        ;

    // -------------------------
    // ChainIkSolverVel_pinv
    // -------------------------
    py::class_<ChainIkSolverVel_pinv, ChainIkSolverVel>(m, "ChainIkSolverVel_pinv")
        .def(py::init<const Chain&, double, int>(),
                py::arg("chain"), py::arg("eps")=0.00001, py::arg("maxiter")=150)
        ;

    // -------------------------
    // ChainIkSolverVel_wdls
    // -------------------------
    py::class_<ChainIkSolverVel_wdls, ChainIkSolverVel>(m, "ChainIkSolverVel_wdls")
        .def(py::init<const Chain&, double, int>(),
             py::arg("chain"), py::arg("eps")=0.00001, py::arg("maxiter")=150)
        .def("setWeightTS", &ChainIkSolverVel_wdls::setWeightTS)
        .def("setWeightJS", &ChainIkSolverVel_wdls::setWeightJS)
        .def("setLambda", &ChainIkSolverVel_wdls::setLambda)
        .def("setEps", &ChainIkSolverVel_wdls::setEps)
        .def("setMaxIter", &ChainIkSolverVel_wdls::setMaxIter)
        .def("getNrZeroSigmas", &ChainIkSolverVel_wdls::getNrZeroSigmas)
        .def("getSigmaMin", &ChainIkSolverVel_wdls::getSigmaMin)
        .def("getSigma", &ChainIkSolverVel_wdls::getSigma)
        .def("getEps", &ChainIkSolverVel_wdls::getEps)
        .def("getLambda", &ChainIkSolverVel_wdls::getLambda)
        .def("getLambdaScaled", &ChainIkSolverVel_wdls::getLambdaScaled)
        .def("getSVDResult", &ChainIkSolverVel_wdls::getSVDResult)
        ;

    // -------------------------
    // ChainIkSolverPos_LMA
    // -------------------------
    py::class_<ChainIkSolverPos_LMA, ChainIkSolverPos>(m, "ChainIkSolverPos_LMA")
        .def(py::init<const Chain&, double, int, double>(),
             py::arg("chain"), py::arg("eps")=0.00001, py::arg("maxiter")=500, py::arg("eps_joints")=0.000000000000001)
        ;

    // -------------------------
    // ChainIkSolverVel_pinv_nso
    // -------------------------
    py::class_<ChainIkSolverVel_pinv_nso, ChainIkSolverVel>(m, "ChainIkSolverVel_pinv_nso")
        .def(py::init<const Chain&, double, int, double>(),
             py::arg("chain"), py::arg("eps")=0.00001, py::arg("maxiter")=150, py::arg("alpha")=0.25)
        .def("setWeights", &ChainIkSolverVel_pinv_nso::setWeights)
        .def("setOptPos", &ChainIkSolverVel_pinv_nso::setOptPos)
        .def("setAlpha", &ChainIkSolverVel_pinv_nso::setAlpha)
        .def("getWeights", &ChainIkSolverVel_pinv_nso::getWeights)
        .def("getOptPos", &ChainIkSolverVel_pinv_nso::getOptPos)
        .def("getAlpha", &ChainIkSolverVel_pinv_nso::getAlpha)
        ;

    // ------------------------------
    // ChainIkSolverVel_pinv_givens
    // ------------------------------
    py::class_<ChainIkSolverVel_pinv_givens, ChainIkSolverVel>(m, "ChainIkSolverVel_pinv_givens")
        .def(py::init<const Chain&>())
        ;

    // ------------------------------
    // ChainJntToJacSolver
    // ------------------------------
    py::class_<ChainJntToJacSolver, SolverI>(m, "ChainJntToJacSolver")
        .def(py::init<const Chain&>())
        .def("JntToJac", &ChainJntToJacSolver::JntToJac,
             py::arg("q_in"), py::arg("jac"), py::arg("segmentNR")=-1)
        .def("setLockedJoints", &ChainJntToJacSolver::setLockedJoints)
        ;

    // ------------------------------
    // ChainIdSolver
    // ------------------------------
    py::class_<ChainIdSolver, SolverI>(m, "ChainIdSolver")
        .def("CartToJnt", &ChainIdSolver::CartToJnt)
        ;

    // ------------------------------
    // ChainIdSolver_RNE
    // ------------------------------
    py::class_<ChainIdSolver_RNE, ChainIdSolver>(m, "ChainIdSolver_RNE")
        .def(py::init<const Chain&, Vector>())
        ;
}
