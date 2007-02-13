#include <iostream>
#include <fstream>

namespace KDL {


std::ofstream& logger() {
  static std::ofstream log("Verify.log");//,std::ios::app);
  return log;
}

std::ofstream& errorlogger() {
  static std::ofstream errorlog("Error.log");//,std::ios::app);
  return errorlog;
}

int DEBUG_RETURNVALUE = 0;


};

