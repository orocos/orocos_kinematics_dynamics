# add everything necessary for a directory to use Corba (ACE/TAO)

SET(ORO_ACETAO_LIBRARIES TAO TAO_PortableServer TAO_CosNaming ACE CACHE INTERNAL "")
IF( NOT TAO_15 )
  SET(ORO_ACETAO_LIBRARIES ${ORO_ACETAO_LIBRARIES} TAO_IDL_BE CACHE INTERNAL "")
ENDIF( NOT TAO_15 )

IF(APPLE)
  # Mac OS X needs this define (or _POSIX_C_SOURCE) to pick up some type
  # definitions that ACE/TAO needs. Personally, I think this is a bug in
  # ACE/TAO, but ....
  ADD_DEFINITIONS(-D_DARWIN_C_SOURCE)
  # and needs additional libraries 
  SET(ORO_ACETAO_LIBRARIES ${ORO_ACETAO_LIBRARIES} TAO_AnyTypeCode CACHE INTERNAL "")
ENDIF(APPLE)

#MESSAGE("ORO_ACETAO_LIBRARIES = ${ORO_ACETAO_LIBRARIES}")

# any possible non-standard install location for ACE/TAO will need
# to specify where everything is.
INCLUDE_DIRECTORIES(${ACE_DIR})

# this is ../lib as this file assumes that the ACE_DIR/TAO_DIR is of the
# form /path/to/ace/include ... ie the dir containing the include files.
# See top of config/FindCorbaDeps.cmake: the check against /usr/include
LINK_DIRECTORIES(${TAO_DIR}/../lib)

# depending on their needs, caller should either do 
#
# LINK_LIBRARIES(${ORO_ACETAO_LIBRARIES})
#
# or
#
# TARGET_LINK_LIBRARIES(prog-or-lib ... ${ORO_ACETAO_LIBRARIES})
#
