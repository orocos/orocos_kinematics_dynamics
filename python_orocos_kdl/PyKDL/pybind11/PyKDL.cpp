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


#include <kdl/config.h>
#include "PyKDL.h"

namespace py = pybind11;


PYBIND11_MODULE(PyKDL, m)
{
    m.doc() = "Orocos KDL Python wrapper"; // optional module docstring
    m.attr("__version__") = KDL_VERSION_STRING;
    init_frames(m);
    init_kinfam(m);
    init_framevel(m);
    init_dynamics(m);
}
