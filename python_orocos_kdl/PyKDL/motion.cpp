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

#include <kdl/rotational_interpolation.hpp>
#include <kdl/rotational_interpolation_sa.hpp>
#include <kdl/path.hpp>
#include <kdl/path_point.hpp>
#include <kdl/path_line.hpp>
#include <kdl/path_circle.hpp>
#include <kdl/path_composite.hpp>
#include <kdl/path_roundedcomposite.hpp>
#include <kdl/path_cyclic_closed.hpp>
#include <kdl/trajectory.hpp>
#include <kdl/trajectory_stationary.hpp>
#include <kdl/trajectory_segment.hpp>
#include <kdl/trajectory_composite.hpp>
#include <kdl/velocityprofile.hpp>
#include <kdl/velocityprofile_dirac.hpp>
#include <kdl/velocityprofile_rect.hpp>
#include <kdl/velocityprofile_spline.hpp>
#include <kdl/velocityprofile_trap.hpp>
#include <kdl/velocityprofile_traphalf.hpp>

#include "PyKDL.h"

namespace py = pybind11;
using namespace KDL;


void init_motion(pybind11::module &m)
{
    // ------------------------
    // RotationalInterpolation
    // ------------------------ 
    py::class_<RotationalInterpolation> rotational_interpolation(m, "RotationalInterpolation");
    rotational_interpolation.def("Acc", &RotationalInterpolation::Acc, py::arg("theta"), py::arg("thetad"), py::arg("thetaddot"));
    rotational_interpolation.def("Angle", &RotationalInterpolation::Angle);
    rotational_interpolation.def("Pos", &RotationalInterpolation::Pos, py::arg("theta"));
    rotational_interpolation.def("SetStartEnd", &RotationalInterpolation::SetStartEnd, py::arg("start"), py::arg("end"));
    rotational_interpolation.def("Vel", &RotationalInterpolation::Vel, py::arg("theta"), py::arg("thetad"));
    rotational_interpolation.def("__repr__", [](const RotationalInterpolation &ri)
		{
			std::ostringstream oss;
			ri.Write(oss);
			return oss.str();
		});
    rotational_interpolation.def("__copy__", &RotationalInterpolation::Clone);
    rotational_interpolation.def("__deepcopy__", [](const RotationalInterpolation& self, py::dict)
		{
			return self.Clone();
		}, 
		py::arg("memo"));

    // -----------------------------------
    // RotationalInterpolation_SingleAxis
    // -----------------------------------
    py::class_<RotationalInterpolation_SingleAxis, RotationalInterpolation> rotational_interpolation_single_axis(m, "RotationalInterpolation_SingleAxis");
    rotational_interpolation_single_axis.def(py::init<>());

    // --------------------
    // Path
    // --------------------
    py::class_<Path> path(m, "Path");
    py::enum_<Path::IdentifierType> path_type(path, "IdentifierType");
        path_type.value("ID_LINE", Path::IdentifierType::ID_LINE);
        path_type.value("ID_CIRCLE", Path::IdentifierType::ID_CIRCLE);
        path_type.value("ID_COMPOSITE", Path::IdentifierType::ID_COMPOSITE);
        path_type.value("ID_ROUNDED_COMPOSITE", Path::IdentifierType::ID_ROUNDED_COMPOSITE);
        path_type.value("ID_POINT", Path::IdentifierType::ID_POINT);
        path_type.value("ID_CYCLIC_CLOSED", Path::IdentifierType::ID_CYCLIC_CLOSED);
        path_type.export_values();

    path.def("LengthToS", &Path::LengthToS, py::arg("length"));
    path.def("PathLength", &Path::PathLength);
    path.def("Pos", &Path::Pos, py::arg("s"));
    path.def("Vel", &Path::Vel, py::arg("s"), py::arg("sd"));
    path.def("Acc", &Path::Acc, py::arg("s"), py::arg("sd"), py::arg("sdd"));
    path.def("getIdentifier", &Path::getIdentifier);
    path.def("__repr__", [](Path& p)
		{
			std::ostringstream oss;
			p.Write(oss);
			return oss.str();
		});
    path.def("__copy__", &Path::Clone);
    path.def("__deepcopy__", [](const Path& self, py::dict)
		{
			return self.Clone();
		}, 
		py::arg("memo"));

    // --------------------
    // Path_Point
    // --------------------
    py::class_<Path_Point, Path> path_point(m, "Path_Point");
    path_point.def(py::init<const Frame&>(), py::arg("F_base_start"));

    // --------------------
    // Path_Line
    // --------------------
    py::class_<Path_Line, Path> path_line(m, "Path_Line");
    path_line.def(py::init([](const Frame& F_base_start, const Frame& F_base_end, const RotationalInterpolation& orient, double eqradius) -> Path_Line *
		{
			return new Path_Line(F_base_start, F_base_end, orient.Clone(), eqradius, true);
		}), 
		py::arg("F_base_start"), py::arg("F_base_end"), py::arg("orient"), py::arg("eqradius"));

    // --------------------
    // Path_Circle
    // --------------------
    py::class_<Path_Circle, Path> path_circle(m, "Path_Circle");
    path_circle.def(py::init([](const Frame& F_base_start, const Vector& V_base_center, const Vector& V_base_p, const Rotation& R_base_end, double alpha, const RotationalInterpolation& orient, double eqradius) -> Path_Circle *
		{
			return new Path_Circle(F_base_start, V_base_center, V_base_p, R_base_end, alpha, orient.Clone(), eqradius, true);
		}), 
		py::arg("F_base_start"), py::arg("V_base_center"), py::arg("V_base_p"),  py::arg("R_base_end"),py::arg("alpha"), py::arg("orient"), py::arg("eqradius"));

    // --------------------
    // Path_Composite
    // --------------------
    py::class_<Path_Composite, Path> path_composite(m, "Path_Composite");
    path_composite.def(py::init<>());
	path_composite.def("Add", [](Path_Composite& p, Path& geom)
		{
			p.Add(geom.Clone(), true);
		},
		py::arg("geom"));
	path_composite.def("GetNrOfSegments", &Path_Composite::GetNrOfSegments);
	path_composite.def("GetSegment", &Path_Composite::GetSegment, py::return_value_policy::reference, py::arg("i"));
	path_composite.def("GetLengthToEndOfSegment", &Path_Composite::GetLengthToEndOfSegment, py::arg("i"));
	path_composite.def("GetCurrentSegmentLocation", [](Path_Composite& path, double s, int segment_number) 
		{
			double inner_s;
			path.GetCurrentSegmentLocation(s, segment_number, inner_s);
			return inner_s;
		}, 
		py::arg("s"), py::arg("segment_number"));

    // ----------------------
    // Path_RoundedComposite
    // ----------------------
    py::class_<Path_RoundedComposite, Path> path_rounded_composite(m, "Path_RoundedComposite");
    path_rounded_composite.def(py::init([](double radius, double eqradius, const RotationalInterpolation& orient) -> Path_RoundedComposite *
		{
			return new Path_RoundedComposite(radius, eqradius, orient.Clone(), true);
		}), 
		py::arg("radius"), py::arg("eqradius"), py::arg("orient"));
	path_rounded_composite.def("Add", &Path_RoundedComposite::Add, py::arg("F_base_point"));
	path_rounded_composite.def("Finish", &Path_RoundedComposite::Finish);
	path_rounded_composite.def("GetNrOfSegments", &Path_RoundedComposite::GetNrOfSegments);
	path_rounded_composite.def("GetSegment", &Path_RoundedComposite::GetSegment, py::return_value_policy::reference, py::arg("i"));
	path_rounded_composite.def("GetLengthToEndOfSegment", &Path_RoundedComposite::GetLengthToEndOfSegment, py::arg("i"));
	path_rounded_composite.def("GetCurrentSegmentLocation", [](Path_RoundedComposite& path, double s, int segment_number) 
		{
			double inner_s;
			path.GetCurrentSegmentLocation(s, segment_number, inner_s);
			return inner_s;
		}, 
		py::arg("s"), py::arg("segment_number"));

    // ----------------------
    // Path_Cyclic_Closed
    // ----------------------
    py::class_<Path_Cyclic_Closed, Path> path_cyclic_closed(m, "Path_Cyclic_Closed");
    path_cyclic_closed.def(py::init([](const Path& geom, int times) -> Path_Cyclic_Closed *
		{
			return new Path_Cyclic_Closed(geom.Clone(), times, true);
		}), 
		py::arg("geom"), py::arg("times"));

    // --------------------
    // Trajectory
    // --------------------
    py::class_<Trajectory> trajectory(m, "Trajectory");
    trajectory.def("Duration", &Trajectory::Duration);
    trajectory.def("Pos", &Trajectory::Pos, py::arg("time"));
    trajectory.def("Vel", &Trajectory::Vel, py::arg("time"));
    trajectory.def("Acc", &Trajectory::Acc, py::arg("time"));
    trajectory.def("__repr__", [](const Trajectory& p)
		{
			std::ostringstream oss;
			p.Write(oss);
			return oss.str();
		});
    trajectory.def("__copy__", &Trajectory::Clone);
    trajectory.def("__deepcopy__", [](const Trajectory& self, py::dict)
		{
			return self.Clone();
		}, 
		py::arg("memo"));

    // ----------------------
    // Trajectory_Stationary
    // -----------------------
    py::class_<Trajectory_Stationary, Trajectory> trajectory_stationary(m, "Trajectory_Stationary");
	trajectory_stationary.def(py::init<double, const Frame&>(), py::arg("duration"), py::arg("pos"));

    // ----------------------
    // Trajectory_Segment
    // -----------------------
    py::class_<Trajectory_Segment, Trajectory> trajectory_segment(m, "Trajectory_Segment");
	trajectory_segment.def(py::init([](Path& geom, const VelocityProfile& motprof) 
		{
			return new Trajectory_Segment(geom.Clone(), motprof.Clone(), true);
		})
		, py::arg("geom"), py::arg("motprof"));
	trajectory_segment.def(py::init([](Path& geom, const VelocityProfile& motprof, double duration) 
		{
			return new Trajectory_Segment(geom.Clone(), motprof.Clone(), duration, true);
		})
		, py::arg("geom"), py::arg("motprof"), py::arg("duration"));
	trajectory_segment.def("GetPath", &Trajectory_Segment::GetPath, py::return_value_policy::reference);
	trajectory_segment.def("GetProfile", &Trajectory_Segment::GetProfile, py::return_value_policy::reference);
				
    // ----------------------
    // Trajectory_Composite
    // ----------------------
    py::class_<Trajectory_Composite, Trajectory> trajectory_composite(m, "Trajectory_Composite");
	trajectory_composite.def(py::init<>());
	trajectory_composite.def("Add", [](Trajectory_Composite& traj, const Trajectory& elem)
		{
			traj.Add(elem.Clone());
		}, 
		py::arg("elem"));
	trajectory_composite.def("Destroy", &Trajectory_Composite::Destroy);

    // --------------------
    // VelocityProfile
    // --------------------
    py::class_<VelocityProfile> velocity_profile(m, "VelocityProfile");
    velocity_profile.def("Acc", &VelocityProfile::Acc, py::arg("time"));
    velocity_profile.def("Duration", &VelocityProfile::Duration);
    velocity_profile.def("Pos", &VelocityProfile::Pos, py::arg("time"));
    velocity_profile.def("SetProfile", &VelocityProfile::SetProfile,
                         py::arg("pos1"), py::arg("pos2"));
    velocity_profile.def("SetProfileDuration", &VelocityProfile::SetProfileDuration,
                         py::arg("pos1"), py::arg("pos2"), py::arg("newduration"));
    velocity_profile.def("Vel", &VelocityProfile::Vel, py::arg("time"));
    velocity_profile.def("__repr__", [](const VelocityProfile &vp)
		{
			std::ostringstream oss;
			vp.Write(oss);
			return oss.str();
		});
    velocity_profile.def("__copy__", &VelocityProfile::Clone);
    velocity_profile.def("__deepcopy__", [](const VelocityProfile& self, py::dict)
		{
			return self.Clone();
		}, 
		py::arg("memo"));

    // ---------------------
    // VelocityProfile_Dirac
    // ---------------------
    py::class_<VelocityProfile_Dirac, VelocityProfile> velocity_profile_dirac(m, "VelocityProfile_Dirac");
    velocity_profile_dirac.def(py::init<>());

    // ---------------------------
    // VelocityProfile_Rectangular
    // ---------------------------
    py::class_<VelocityProfile_Rectangular, VelocityProfile> velocity_profile_rectangular(m, "VelocityProfile_Rectangular");
    velocity_profile_rectangular.def(py::init<double>(), py::arg("maxvel") = 0);
    velocity_profile_rectangular.def("SetMax", &VelocityProfile_Rectangular::SetMax, py::arg("maxvel"));

    // ---------------------------
    // VelocityProfile_Trap
    // ---------------------------
    py::class_<VelocityProfile_Trap, VelocityProfile> velocity_profile_trap(m, "VelocityProfile_Trap");
    velocity_profile_trap.def(py::init<double, double>(), 
                              py::arg("maxvel") = 0, py::arg("maxacc") = 0);
    velocity_profile_trap.def("SetMax", &VelocityProfile_Trap::SetMax, 
                              py::arg("maxvel"), py::arg("maxacc"));
    velocity_profile_trap.def("SetProfileVelocity", &VelocityProfile_Trap::SetProfileVelocity,
                         py::arg("pos1"), py::arg("pos2"), py::arg("newvelocity"));


    // ---------------------------
    // VelocityProfile_TrapHalf
    // ---------------------------
    py::class_<VelocityProfile_TrapHalf, VelocityProfile> velocity_profile_traphalf(m, "VelocityProfile_TrapHalf");
    velocity_profile_traphalf.def(py::init<double, double, bool>(), 
                                  py::arg("maxvel") = 0, py::arg("maxacc") = 0, py::arg("starting") = true);
    velocity_profile_traphalf.def("SetMax", &VelocityProfile_TrapHalf::SetMax, 
                                  py::arg("maxvel"), py::arg("maxacc"), py::arg("starting"));

    // ---------------------------
    // VelocityProfile_Spline
    // ---------------------------
    py::class_<VelocityProfile_Spline, VelocityProfile> velocity_profile_spline(m, "VelocityProfile_Spline");
    velocity_profile_spline.def(py::init<>());
    velocity_profile_spline.def(py::init<const VelocityProfile_Spline&>());
    velocity_profile_spline.def("SetProfileDuration", (void (VelocityProfile_Spline::*)(double, double, double, double, double)) &VelocityProfile_Spline::SetProfileDuration,
                                py::arg("pos1"), py::arg("vel1"), py::arg("pos2"), py::arg("vel2"), py::arg("duration"));
    velocity_profile_spline.def("SetProfileDuration", (void (VelocityProfile_Spline::*)(double, double, double, double, double, double, double)) &VelocityProfile_Spline::SetProfileDuration,
                                py::arg("pos1"), py::arg("vel1"), py::arg("acc1"), py::arg("pos2"), py::arg("vel2"), py::arg("acc2"), py::arg("duration"));
}
