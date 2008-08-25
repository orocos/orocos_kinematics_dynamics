#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>

int main()
{
    KDL::Vector v1;
    KDL::Vector v2(1.0,2.0,3.0);
    
    std::cout<<"v1: "<<v1<<std::endl;
    std::cout<<"v2: "<<v2<<std::endl;
}    
