
CONFIGURE_FILE(Doxyfile.in doc/Doxyfile IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(docs "doxygen" "Doxyfile")
INSTALL_FILES(doc kdl.tag) # only installs if found.
