FILE( GLOB KDL_SRCS [^.]*.cpp [^.]*.cxx)
FILE( GLOB KDL_HPPS [^.]*.hpp [^.]*.h [^.]*.inl)

FILE( GLOB KINFAM_SRCS kinfam/[^.]*.cpp)
FILE( GLOB KINFAM_HPPS kinfam/[^.]*.h kinfam/[^.]*.hpp kinfam/[^.]*.inl)

FILE( GLOB MOTION_SRCS motion/[^.]*.cpp motion/[^.]*.cxx)
FILE( GLOB MOTION_HPPS motion/[^.]*.hpp motion/[^.]*.h motion/[^.]*.inl) 

INCLUDE_DIRECTORIES(${KDL_SOURCE_DIR})
ADD_LIBRARY(kdl SHARED ${KDL_SRCS} ${KINFAM_SRCS} ${MOTION_SRCS}) 
SET_TARGET_PROPERTIES( kdl PROPERTIES
    DEFINE_SYMBOL KDL_DLL_EXPORT
    SOVERSION ${VERSION}
)

INSTALL_TARGETS( /lib kdl)

# CMake 2.2:
INSTALL_FILES( /include/kdl FILES ${KDL_HPPS})
INSTALL_FILES( /include/kdl/kinfam FILES ${KINFAM_HPPS})
INSTALL_FILES( /include/kdl/motion FILES ${MOTION_HPPS})

CONFIGURE_FILE( kdl.pc.in kdl/kdl.pc @ONLY)
INSTALL_FILES( /lib/pkgconfig FILES kdl.pc)

# Orocos convention:
CONFIGURE_FILE( kdl.pc.in kdl/orocos-kdl.pc @ONLY)
INSTALL_FILES( /lib/pkgconfig FILES orocos-kdl.pc)

ADD_SUBDIRECTORY( kdltk )

