/*****************************************************************************
 * \file  
 *      defines debug macros that make it easy to write test-sequences
 *      Defined are :
 *          - function logger() that returns a ofstream to the logger-stream.  
 *          this stream is created the first time the function is called.
 *          - D(x,y) tests whether x is equal to y, Equal(..,..) should be defined
 *          on x and y.
 *          - D_eps(x,y,eps) same as previous but with Equal(..,..,eps) (in eps-interval)
 *          - L(x), converts x to a string and write to the logger, and also executes x
 *          - DRESULT(x) displays x and the evaluation of x
 *          - N(x)  calls subroutine x and logs this call
 *          - DEBUG_RETURNVALUE can be used to check whether errors occurred.
 *  \author 
 *      Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version 
 *      ORO_Geometry V0.2
 *
 *  \par History
 *      - $log$ 
 *
 *  \par Release
 *      $Id: debug_macros.h,v 1.1.1.1.2.1 2003/07/18 14:58:36 psoetens Exp $
 *      $Name:  $ 
 ****************************************************************************/
#ifndef DEBUG_MACROS
#define DEBUG_MACROS

#include <kdl/utility.h>

#include <iostream>
#include <fstream>

namespace KDL {


extern std::ofstream& logger();

extern std::ofstream& errorlogger();

extern int DEBUG_RETURNVALUE;

};

#define D(x,y) \
    {KDL::logger() << "Line: "<<__LINE__ << " File:"<<__FILE__<<" ("<< #x  << ") Equal to (" << #y << ") ? " << std::endl\
          << "    X : " << (x) << std::endl\
          << "    Y : " << (y) << std::endl;\
    if (!Equal(x,y)) \
    {std::cout << "Line: "<<__LINE__ << " File:"<<__FILE__<< " ("<< #x  << ") Equal to (" << #y << ") ? " << std::endl\
          << "    X : " << (x) << std::endl\
          << "    Y : " << (y) << std::endl;\
     KDL::logger() << "ERROR : ==== VALUES SHOULD BE EQUAL ====" << std::endl;\
     KDL::errorlogger() << "Line: "<<__LINE__ << " File:"<<__FILE__<< " ("<< #x  << ") Equal to (" << #y << ") ? " << std::endl\
          << "    X : " << (x) << std::endl\
          << "    Y : " << (y) << std::endl;\
     KDL::errorlogger() << "ERROR : ==== VALUES SHOULD BE EQUAL ====" << std::endl;\
     KDL::DEBUG_RETURNVALUE = -1; \
    }}

#define D_eps(x,y,eps) \
    {KDL::logger() << "Line: "<<__LINE__ << " File:"<<__FILE__<< " ("<< #x  << ") Equal to (" << #y << ") within "<< eps << " range ? " << std::endl\
          << "    X : " << (x) << std::endl\
          << "    Y : " << (y) << std::endl;\
    if (!Equal(x,y,eps)) \
    {std::cout << "Line: "<<__LINE__ << " File:"<<__FILE__<< " ("<< #x  << ") Equal to (" << #y << ") within " << eps << " range ? " << std::endl\
          << "    X : " << (x) << std::endl\
          << "    Y : " << (y) << std::endl;\
     KDL::logger() << "ERROR : ==== VALUES SHOULD BE EQUAL ====" << std::endl;\
     KDL::errorlogger() << "Line: "<<__LINE__ << " File:"<<__FILE__<< " ("<< #x  << ") Equal to (" << #y << ") within " << eps << " range ? " << std::endl\
          << "    X : " << (x) << std::endl\
          << "    Y : " << (y) << std::endl;\
     KDL::errorlogger() << "ERROR : ==== VALUES SHOULD BE EQUAL ====" << std::endl;\
     KDL::DEBUG_RETURNVALUE = -1; \
    }}

#define L(x) KDL::logger() << "Line: "<<__LINE__ << "File:"<<__FILE__<< " " << #x << std::endl;x;
#define DRESULT(x) KDL::logger() << "Line: "<<__LINE__ << " File:"<<__FILE__<< " " << #x << std::endl;logger() << x << std::endl;
#define N(x) KDL::logger() << "--------------------------------------------------------------------" << std::endl\
                      << "Line: "<<__LINE__<< " File:"<<__FILE__<< "  ROUTINE " << #x << std::endl\
                      << "--------------------------------------------------------------------" << std::endl;x;
                      
#endif
