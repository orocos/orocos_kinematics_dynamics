#include "PyKDL.h"
#include <kdl/frames.hpp>
#include <kdl/path.hpp>
#include <kdl/path_line.hpp>
#include <kdl/rotational_interpolation.hpp>
#include <kdl/rotational_interpolation_sa.hpp>
#include <kdl/trajectory_segment.hpp>
#include <kdl/velocityprofile.hpp>
#include <kdl/velocityprofile_trap.hpp>

namespace py = pybind11;
using namespace KDL;

void init_trajectory(py::module &m) {

  // --------------------
  // VelocityProfile
  // --------------------
  py::class_<VelocityProfile, std::shared_ptr<VelocityProfile>>(
      m, "VelocityProfile");

  // --------------------
  // VelocityProfile_Trap
  // --------------------
  py::class_<VelocityProfile_Trap, VelocityProfile,
             std::shared_ptr<VelocityProfile_Trap>>(m, "VelocityProfile_Trap")
      .def(py::init<double, double>(), py::arg("_maxvel") = 0.0,
           py::arg("_maxacc") = 0.0)
      .def("SetProfile", &VelocityProfile_Trap::SetProfile, py::arg("pos1"),
           py::arg("pos2"))
      .def("SetProfileDuration", &VelocityProfile_Trap::SetProfileDuration,
           py::arg("pos1"), py::arg("pos2"), py::arg("newduration"))
      .def("SetProfileVelocity", &VelocityProfile_Trap::SetProfileVelocity,
           py::arg("pos1"), py::arg("pos2"), py::arg("newvelocity"))
      .def("SetMax", &VelocityProfile_Trap::SetMax, py::arg("_maxvel"),
           py::arg("_maxacc"))
      .def("Duration", &VelocityProfile_Trap::Duration)
      .def("Pos", &VelocityProfile_Trap::Pos, py::arg("time"))
      .def("Vel", &VelocityProfile_Trap::Vel, py::arg("time"))
      .def("Acc", &VelocityProfile_Trap::Acc, py::arg("time"));

  // --------------------
  // Path
  // --------------------
  py::class_<Path, std::shared_ptr<Path>>(m, "Path")
      // Bind the enum IdentifierType
      .def_property_readonly_static("ID_LINE",
                                    [](py::object) { return Path::ID_LINE; })
      .def_property_readonly_static("ID_CIRCLE",
                                    [](py::object) { return Path::ID_CIRCLE; })
      .def_property_readonly_static(
          "ID_COMPOSITE", [](py::object) { return Path::ID_COMPOSITE; })
      .def_property_readonly_static(
          "ID_ROUNDED_COMPOSITE",
          [](py::object) { return Path::ID_ROUNDED_COMPOSITE; })
      .def_property_readonly_static("ID_POINT",
                                    [](py::object) { return Path::ID_POINT; })
      .def_property_readonly_static(
          "ID_CYCLIC_CLOSED", [](py::object) { return Path::ID_CYCLIC_CLOSED; })

      .def("LengthToS", &Path::LengthToS, py::arg("length"))
      .def("PathLength", &Path::PathLength)
      .def("Pos", &Path::Pos, py::arg("s"))
      .def("Vel", &Path::Vel, py::arg("s"), py::arg("sd"))
      .def("Acc", &Path::Acc, py::arg("s"), py::arg("sd"), py::arg("sdd"))
      .def("Clone", &Path::Clone)
      .def("getIdentifier", &Path::getIdentifier);

  // --------------------
  // Path_Line
  // --------------------
  py::class_<Path_Line, Path, std::shared_ptr<Path_Line>>(m, "Path_Line")
      // Constructors
      .def(py::init<const Frame &, const Frame &, RotationalInterpolation *,
                    double, bool>(),
           py::arg("F_base_start"), py::arg("F_base_end"), py::arg("orient"),
           py::arg("eqradius"), py::arg("aggregate") = false, py::keep_alive<1, 4>())
      .def(py::init<const Frame &, const Twist &, RotationalInterpolation *,
                    double, bool>(),
           py::arg("F_base_start"), py::arg("twist_in_base"), py::arg("orient"),
           py::arg("eqradius"), py::arg("aggregate") = false, py::keep_alive<1, 4>())

      .def("LengthToS", &Path_Line::LengthToS, py::arg("length"))
      .def("PathLength", &Path_Line::PathLength)
      .def("Pos", &Path_Line::Pos, py::arg("s"))
      .def("Vel", &Path_Line::Vel, py::arg("s"), py::arg("sd"))
      .def("Acc", &Path_Line::Acc, py::arg("s"), py::arg("sd"), py::arg("sdd"))
      .def("Clone", &Path_Line::Clone)
      .def("getIdentifier", &Path_Line::getIdentifier);

  // --------------------
  // RotationalInterpolation
  // --------------------
  py::class_<RotationalInterpolation, std::shared_ptr<RotationalInterpolation>>(
      m, "RotationalInterpolation")
      .def("SetStartEnd", &RotationalInterpolation::SetStartEnd,
           py::arg("start"), py::arg("end"))
      .def("Angle", &RotationalInterpolation::Angle)
      .def("Pos", &RotationalInterpolation::Pos, py::arg("theta"))
      .def("Vel", &RotationalInterpolation::Vel, py::arg("theta"),
           py::arg("thetad"))
      .def("Acc", &RotationalInterpolation::Acc, py::arg("theta"),
           py::arg("thetad"), py::arg("thetadd"))
      .def("Clone", &RotationalInterpolation::Clone);

  py::class_<RotationalInterpolation_SingleAxis, RotationalInterpolation,
             std::shared_ptr<RotationalInterpolation_SingleAxis>>(
      m, "RotationalInterpolation_SingleAxis")
      .def(py::init<>())
      .def("SetStartEnd", &RotationalInterpolation_SingleAxis::SetStartEnd,
           py::arg("start"), py::arg("end"))
      .def("RotateLongWay", &RotationalInterpolation_SingleAxis::RotateLongWay)
      .def("Angle", &RotationalInterpolation_SingleAxis::Angle)
      .def("Pos", &RotationalInterpolation_SingleAxis::Pos, py::arg("theta"))
      .def("Vel", &RotationalInterpolation_SingleAxis::Vel, py::arg("theta"),
           py::arg("thetad"))
      .def("Acc", &RotationalInterpolation_SingleAxis::Acc, py::arg("theta"),
           py::arg("thetad"), py::arg("thetadd"));

  // ---------------------
  // Trajectory
  // ---------------------
  py::class_<Trajectory, std::shared_ptr<Trajectory>>(m, "Trajectory")
      .def("Duration", &Trajectory::Duration)
      .def("Pos", &Trajectory::Pos, py::arg("time"))
      .def("Vel", &Trajectory::Vel, py::arg("time"))
      .def("Acc", &Trajectory::Acc, py::arg("time"))
      .def("Clone", &Trajectory::Clone, py::return_value_policy::reference);
  // ---------------------
  // Trajectory_Segment
  // ---------------------
  py::class_<Trajectory_Segment, Trajectory,
             std::shared_ptr<Trajectory_Segment>>(m, "Trajectory_Segment")
      .def(py::init<Path *, VelocityProfile *, bool>(), py::arg("path"),
           py::arg("velocity_profile"), py::arg("aggregate") = false, py::keep_alive<1, 2>(), py::keep_alive<1, 3>())
      .def(py::init<Path *, VelocityProfile *, double, bool>(), py::arg("path"),
           py::arg("velocity_profile"), py::arg("duration"),
           py::arg("aggregate") = false, py::keep_alive<1, 2>(), py::keep_alive<1, 3>())
      .def("Duration", &Trajectory_Segment::Duration)
      .def("Pos", &Trajectory_Segment::Pos, py::arg("time"))
      .def("Vel", &Trajectory_Segment::Vel, py::arg("time"))
      .def("Acc", &Trajectory_Segment::Acc, py::arg("time"))
      .def("Clone", &Trajectory_Segment::Clone,
           py::return_value_policy::reference) // careful: returns raw pointer
      .def("GetPath", &Trajectory_Segment::GetPath,
           py::return_value_policy::reference)
      .def("GetProfile", &Trajectory_Segment::GetProfile,
           py::return_value_policy::reference);
}
