/** @file   utility.cpp
 *  @author Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *  @version 
 *      ORO_Geometry V0.2
 *   
 *  @par history
 *   - changed layout of the comments to accommodate doxygen
 */
 
#include "utility.h"

namespace KDL {

int STREAMBUFFERSIZE = 10000;
int MAXLENFILENAME = 255;

namespace detail {

bool equalScaled(const double* a, const double* b, int n, double eps)
{
    double scale = 1.0;
    for (int i = 0; i < n; ++i) {
        if (std::isfinite(a[i]) && std::fabs(a[i]) > scale)
            scale = std::fabs(a[i]);
        if (std::isfinite(b[i]) && std::fabs(b[i]) > scale)
            scale = std::fabs(b[i]);
    }
    const double tolerance = eps * scale;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;
        const double diff = a[i] - b[i];
        if (!std::isfinite(diff) || !(std::fabs(diff) <= tolerance))
            return false;
    }
    return true;
}

} // namespace detail
}
