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
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;
        using difference_type = ptrdiff_t;

        template <class U> struct rebind
        {
            typedef allocator<U> other;
        };

        // member functions
        allocator() noexcept;
        allocator(const allocator &other) noexcept;
        template <class U> allocator(const allocator<U> &other) noexcept;
        ~allocator();
        pointer       address(reference x) const noexcept;
        const_pointer address(const_reference x) const noexcept;
        pointer       allocate(size_type n, const void *hint = 0);
        void          deallocate(T *p, std::size_t n);
        size_type     max_size() const noexcept;
        void          construct(pointer p, const_reference val);
        void          destroy(pointer p);
    };

    template <class T1, class T2>
    bool operator==(const allocator<T1> &lhs, const allocator<T2> &rhs) noexcept;
    template <class T1, class T2>
    bool operator!=(const allocator<T1> &lhs, const allocator<T2> &rhs) noexcept;
} // namespace ystd
