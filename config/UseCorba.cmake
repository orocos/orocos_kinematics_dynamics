# add everything necessary for a directory to use Corba (whichever 
# implementation we are using)

ADD_DEFINITIONS(${CORBA_CFLAGS} -DKIWI)
INCLUDE_DIRECTORIES(${CORBA_INCLUDE_DIRS})
LINK_DIRECTORIES(${CORBA_LINK_DIRECTORIES})
# \todo ${CORBA_LDFLAGS}


# depending on their needs, caller should either do 
#
# LINK_LIBRARIES(${CORBA_LIBRARIES})
#
# or
#
# TARGET_LINK_LIBRARIES(prog-or-lib ... ${CORBA_LIBRARIES})
#
