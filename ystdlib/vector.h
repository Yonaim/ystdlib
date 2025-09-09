/**
 * @file vector.h
 * @brief declaration of vector
 * (Do not implement pmr::vector)
 */

#pragma once

#include "allocator.h"
#include "platform.h"
#include "ystddef.h"

namespace ystd
{
    template <class T, class Allocator = ystd::allocator<T>> class vector
    {
        using value_type = T;
        using allocator_type = Allocator;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using reference = value_type &;
        using const_reference = const value_type &;
        using pointer = Allocator::pointer;
        using const_pointer = Allocator::const_pointer;
        // iterators...

      public:
        vector();
        explicit vector(const Allocator &alloc = Allocator());
        explicit vector(size_type count, const Allocator &alloc = Allocator());
        explicit vector(size_type count, const T &value = T(),
                        const Allocator &alloc = Allocator());

        ~vector();
        void operator=();
        void assign();
        void get_allocator();

        // Element access
        void at();
        void operator[]();
        void front();
        void back();
        void data();

        // Iterators
        void begin();
        void end();
        void rbegin();
        void rend();

        // Capacity
        void empty();
        void size();
        void max_size();
        void reserve();
        void capacity();
        void shrink_to_fit();

        // Modifiers
        void clear();
        void insert();
        void emplace();
        void erase();
        void push_back();
        void emplace_back();
        void pop_back();
        void resize();
        void swap();
    };

    template <class T> void operator==(const vector<T> &lfs, const vector<T> &rfs);
    void                    operator!=(const vector<T> &lfs, const vector<T> &rfs);
    void                    operator<(const vector<T> &lfs, const vector<T> &rfs);
    void                    operator<=(const vector<T> &lfs, const vector<T> &rfs);
    void                    operator>(const vector<T> &lfs, const vector<T> &rfs);
    void                    operator>=(const vector<T> &lfs, const vector<T> &rfs);

} // namespace ystd