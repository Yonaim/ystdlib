/**
 * @file platform.h
 * @brief Detect platform(os & architecture) and set flag
 * 
 */

#pragma once

#if defined(_WIN64)
    #define YSTD_PLATFORM_WINDOWS 1
#elif defined(__x86_64__) || defined(__ppc64__)
    #define YSTD_PLATFORM_UNIX64 1
#elif defined(__aarch64__) || defined(__arm64__)
    #define YSTD_PLATFORM_ARM64 1
#else
    #define YSTD_PLATFORM_32BIT 1
#endif
