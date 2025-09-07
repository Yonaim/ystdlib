/**
 * @file ystddef.h
 * @brief type definition according to current platform
 */

#include "platform.h"

/**
 * @brief size_t, ptrdiff_t
 */
namespace ystd
{
#if defined(YSTD_PLATFORM_WINDOWS)
    using size_t = unsigned long long;
    using ptrdiff_t = long long;
#elif defined(YSTD_PLATFORM_UNIX64) || defined(YSTD_PLATFORM_ARM64)
    using size_t = unsigned long;
    using ptrdiff_t = long;
#elif defined(YSTD_PLATFORM_32BIT)
    using size_t = unsigned int;
    using ptrdiff_t = int;
#else
#error "Unknown platform"
#endif
} // namespace ystd
