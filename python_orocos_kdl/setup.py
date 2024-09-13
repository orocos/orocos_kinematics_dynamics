from setuptools import setup, Extension
import pybind11
import subprocess
import pkgconfig

setup(name='PyKDL',
      version='1.4.0',
      description='Python binding for KDL',
      license='LGPL',
      url='https://github.com/orocos/orocos_kinematics_dynamics',
      author='Ruben Smits',
      author_email='ruben@intermodalics.eu',
      requires=['pkgconfig','pybind11'],
      ext_modules=[
          Extension("PyKDL",
            sources=[i+".cpp" for i in ('PyKDL', 'frames', 'framevel', 'kinfam', 'dynamics') ],
            language="c++",
            extra_compile_args=(pkgconfig.libs('eigen3')+' '+pkgconfig.cflags('eigen3')+' -I'+pybind11.get_include()).split()
      )],
      zip_safe=False)

