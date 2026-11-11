// Compatibility stub: KDL 2.0 renamed <kdl/config.h> to <kdl/config.hpp>.
// This stub is kept for the 2.x series and will be removed in KDL 3.0.
#ifndef KDL_COMPAT_CONFIG_H
#define KDL_COMPAT_CONFIG_H

#ifdef _MSC_VER
#pragma message("warning: kdl/config.h is deprecated, include kdl/config.hpp")
#else
#warning "kdl/config.h is deprecated, include kdl/config.hpp"
#endif

#include <kdl/config.hpp>

#endif // KDL_COMPAT_CONFIG_H
