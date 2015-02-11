//Copyright  (C)  2005  Torsten Marek <shlomme at gmx.net>
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


%MappedType std::string
{
%TypeHeaderCode
#include <string>
%End

%ConvertFromTypeCode
    // convert an std::string to a Python (unicode) string
    PyObject* newstring;
    newstring = PyUnicode_DecodeUTF8(sipCpp->c_str(), sipCpp->length(), NULL);
    if(newstring == NULL) {
        PyErr_Clear();
        newstring = PyUnicode_FromString(sipCpp->c_str());
    }
    return newstring;
%End

%ConvertToTypeCode
     // Allow a Python string (or a unicode string) whenever a string is
     // expected.
    // If argument is a Unicode string, just decode it to UTF-8
    // If argument is a Python string, assume it's UTF-8
     if (sipIsErr == NULL)
#if PY_MAJOR_VERSION < 3
        return (PyString_Check(sipPy) || PyUnicode_Check(sipPy));
#else
        return PyUnicode_Check(sipPy);
#endif
     if (sipPy == Py_None) {
        *sipCppPtr = new std::string;
         return 1;
     }
     if (PyUnicode_Check(sipPy)) {
        PyObject* s = PyUnicode_AsEncodedString(sipPy, "UTF-8", "");
        *sipCppPtr = new std::string(PyUnicode_AS_DATA(s));
        Py_DECREF(s);
        return 1;
     }
#if PY_MAJOR_VERSION < 3
     if (PyString_Check(sipPy)) {
        *sipCppPtr = new std::string(PyString_AS_STRING(sipPy));
        return 1;
     }
#endif

     return 0;
%End
};

