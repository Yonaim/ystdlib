/**
 * @file allocator.h
 * @brief stateless, default allocator
 */

#pragma once

namespace ystd
{
    template <class T> struct allocator
    {
        T        value_type;
        T       *pointer;
        const T *const_pointer;
        T       &reference;
        const T &reference;
        size_t   size_type;
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
