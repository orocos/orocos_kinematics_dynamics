// Checks that out-of-range index access is caught by assert(). NDEBUG is
// undefined on purpose so the check is active in every build type.
#undef NDEBUG

#include "frames.hpp"

int main()
{
    KDL::Vector v;
    volatile int i = 3;
    return static_cast<int>(v(i));
}
