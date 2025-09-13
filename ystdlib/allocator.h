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

        // constructors
        /*
        - allocate: 메모리 확보
        - deallocate: 확보했던 메모리 해제
        - construct: 확보된 메모리에 실제 객체 생성
        - destroy: 소멸자 호출 (메모리는 그대로임)
        */
        allocator() noexcept = default;
        allocator(const allocator &other) noexcept = default;
        template <class U> allocator(const allocator<U> &other) noexcept {};
        ~allocator() noexcept = default;

        pointer address(reference x) const noexcept { return &x; }

        const_pointer address(const_reference x) const noexcept { return &x; }

        pointer allocate(size_type n, const void *hint = 0) noexcept
        {
            return static_cast<T *>(::operator new(sizeof(T) * n);)
        }

        void deallocate(T *p, std::size_t n) noexcept {}

        size_type max_size() const noexcept {}

        void construct(pointer p, const_reference val) noexcept {}

        void destroy(pointer p) noexcept {}
    };

    template <class T1, class T2>
    bool operator==(const allocator<T1> &lhs, const allocator<T2> &rhs) noexcept;
    template <class T1, class T2>
    bool operator!=(const allocator<T1> &lhs, const allocator<T2> &rhs) noexcept;
} // namespace ystd
