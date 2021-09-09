#include <iostream>
#include <kdl/error_stack.h>
#include <kdl/error.h>
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <kdl/kinfam/joint.hpp>
#include <kdl/kinfam/serialchain.hpp>
#include <kdl/kinfam/kinematicfamily_io.hpp>
#include <kdl/kinfam/crs450.hpp>
#include <kdl/kinfam/jnt2cartpos.hpp>
#include <memory>

using namespace KDL;

void test_io(KinematicFamily* kf) {
	// write a kf to the file tst.dat
        std::ofstream os("tst.dat");
        os << kf << std::endl;
        std::cout << kf  << std::endl;
	os.close();

	// read a serial chain from the file tst.dat
        std::ifstream is ("tst.dat");
	KinematicFamily* kf2;
	try {
	  kf2 = readKinematicFamily(is);
          std::cout << kf2 << std::endl;
	} catch (Error& err) {
          IOTraceOutput(std::cerr);
          std::cout << "ERROR : " << err.Description() << std::endl;
	  exit(-1);
	}

	std::vector<double> q(6);
	for (int i=0;i<q.size();++i) q[i] = i*0.2;
	Frame F1,F2;
	Jnt2CartPos* jnt2cartpos  = kf->createJnt2CartPos();
	Jnt2CartPos* jnt2cartpos2 = kf2->createJnt2CartPos();

	jnt2cartpos->evaluate(q);jnt2cartpos->getFrame(F1);
	jnt2cartpos2->evaluate(q);jnt2cartpos2->getFrame(F2);
        std::cout << F1 << std::endl;
        std::cout << F2 << std::endl;
	if (!Equal(F1,F2)) {
                std::cerr << "Results are not equal" << std::endl;
		exit(-1);
	}
	delete jnt2cartpos;
	delete jnt2cartpos2;
	delete kf2;
	delete kf;
}

int main(int argc,char* argv[]) {
    test_io(new CRS450());
    test_io(new CRS450Feath());
}


