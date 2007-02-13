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
#ifndef KDL_TEST_MACROS
#define KDL_TEST_MACROS

#include <kdl/utility.h>

#include <iostream>
#include <iomanip>
#include <fstream>

namespace KDL {                     



class DisplContext { 
        static int level;

        std::string file;
        int line;
        std::string func;
    public:
        static std::ostream& out;
        static bool display;
        DisplContext(std::string _file,int _line,std::string _func):
            file(_file),line(_line),func(_func)
        {
            if (display) {
                Tab();out << "Entering " << func << "[" << file << ":" << line <<"]" << std::endl;
            }
            level++;
        }
        ~DisplContext() {
            level--;
            if (display) {
                Tab();out << "Leaving  " << func << "[" << file << ":" << line <<"]" << std::endl;
            }
        }
        static void Tab() {
            out << std::setw(level*4) << " ";
        }
        /*template <typename A,typename B>
        void Difference(const A& a, const B& b) {
            if (!display) return;
    		Tab();std::cout << "difference " << KDL::diff(a,b,1) << std::endl;
	    	Tab();std::cout << "A:" << a << std::endl;
		    Tab();std::cout << "B:" << b << std::endl;
        }*/
       template <typename A>
       void Argument(const A& a) {
            if (!display) return;
            Tab();out << "Argument " << a.value() << std::endl;
        }
       template <typename A,typename B>
       void Argument(const A& a,const B& b) {
            if (!display) return;
            Tab();out << "Argument 1" << a.value() << std::endl;
            Tab();out << "Argument 2" << b.value() << std::endl;
       }
};

};

#define KDL_DIFF(a,b) \
    if (lrl_disp_context.display) {\
            lrl_disp_context.Tab();lrl_disp_context.out << "At line : " << __LINE__ << " : ("<< #a << ") equal to (" << #b << ") ?" << std::endl;\
	    	lrl_disp_context.Tab();lrl_disp_context.out << "  A : " << a << std::endl;\
		    lrl_disp_context.Tab();lrl_disp_context.out << "  B : " << b << std::endl;\
    }\
    assert(Equal(a,b));

#define KDL_CTX \
    KDL::DisplContext lrl_disp_context(__FILE__,__LINE__,__PRETTY_FUNCTION__);

#define KDL_ARG1(a) \
    lrl_disp_context.Argument(a);

#define KDL_ARG2(a,b) \
    lrl_disp_context.Argument(a,b);

#define KDL_DISP(a) \
   if (lrl_disp_context.display) {\
            lrl_disp_context.Tab();lrl_disp_context.out << "At line : " << __LINE__ << " : "<< #a << " = " << a << std::endl;\
   }
#define KDL_MSG(a) \
   if (lrl_disp_context.display) {\
            lrl_disp_context.Tab();lrl_disp_context.out << "At line : " << __LINE__ << " : "<< a << std::endl;\
   }


#endif
