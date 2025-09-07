/**
 * @file allocator.h
 * @brief stateless, default allocator
 */

#pragma once

#include "platform.h"
#include "ystddef.h"

namespace ystd
{
    template <class T> struct allocator
    {
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using reference = T&;
        using const reference = const T&;
        using size_type = size_t;
        using difference_type = ptrdiff_t;

        template <class U> struct rebind
        {
            typedef allocator<U> other;
        };

        allocator() {}
        ~allocator() {}
        void allocate();
        void deallocate();
        void max_size();
        void construct();
        void destroy();
    };

    bool operator==(int dummy1, allocator<int> dummy2);
    bool operator!=(int dummy1, allocator<int> dummy2);
} // namespace ystd
