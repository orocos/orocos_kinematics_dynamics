#ifndef KDLCHAINFKSOLVERPOS_SUCCESIVE_HPP
#define KDLCHAINFKSOLVERPOS_SUCCESIVE_HPP

#include <chainfksolver.hpp>

namespace KDL {

/**
	@author Ruben Smits <first dot last at mech dot kuleuven dot be>
*/
class ChainFkSolverPos_succesive : public ChainFkSolverPos
{
public:
    ChainFkSolverPos_succesive(Chain* chain);
    ~ChainFkSolverPos_succesive();
private:
    Chain* chain;



};

}

#endif
