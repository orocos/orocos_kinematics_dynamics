FILE( GLOB KDL_SRCS [^.]*.c*)
FILE( GLOB KDL_HPPS [^.]*.h* )
FILE( GLOB KDL_INLS [^.]*.inl )

FILE( GLOB KINFAM_SRCS kinfam/[^.]*.c*)
FILE( GLOB KINFAM_HPPS kinfam/[^.]*.h* )
FILE( GLOB KINFAM_INLS kinfam/[^.]*.inl )

FILE( GLOB MOTION_SRCS motion/[^.]*.c*)
FILE( GLOB MOTION_HPPS motion/[^.]*.h* )
FILE( GLOB MOTION_INLS motion/[^.]*.inl )

INCLUDE_DIRECTORIES(${KDL_SOURCE_DIR})
ADD_LIBRARY(kdl STATIC ${KDL_SRCS} ${KINFAM_SRCS} ${MOTION_SRCS}) 
INSTALL_TARGETS( /lib kdl)

# CMake 2.2:
INSTALL_FILES( /include/kdl FILES ${KDL_HPPS} ${KDL_INLS})
INSTALL_FILES( /include/kdl/kinfam FILES ${KINFAM_HPPS} ${KINFAM_INLS})
INSTALL_FILES( /include/kdl/motion FILES ${MOTION_HPPS} ${MOTION_INLS})

CONFIGURE_FILE( kdl.pc.in kdl/kdl.pc @ONLY)
INSTALL_FILES( /lib/pkgconfig FILES kdl.pc)

# Orocos convention:
CONFIGURE_FILE( kdl.pc.in kdl/orocos-kdl.pc @ONLY)
INSTALL_FILES( /lib/pkgconfig FILES orocos-kdl.pc)

IF( OROCOS_PLUGIN )
  ADD_SUBDIRECTORY( kdltk )
ENDIF( OROCOS_PLUGIN )

