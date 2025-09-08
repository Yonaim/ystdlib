/**
 * @file iterator.h
 * @brief
 */

#pragma once

#include "platform.h"
#include "ystddef.h"

namespace ystdlib
{

    template <class Category, class T, class Distance = ystd::ptrdiff_t, class Pointer = T *,
              class Reference = T &>
    struct iterator
    {
        using iterator_category = Category;
        using value_type = T;
        using difference_type = Distance;
        using pointer = Pointer;
        using reference = Reference;

        // ...
    };

    template <class Iterator> struct iterator_traits
    {
        using difference_type = typename Iterator::difference_type;
        using value_type = typename Iterator::value_type;
        using pointer = typename Iterator::pointer;
        using reference = typename Iterator::reference;
        using iterator_category = typename Iterator::iterator_category;
        using iterator_concept = typename Iterator::iterator_concept;
    };

    // template specialization for pointer type
    template <class T> struct iterator_traits<T *>
    {
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using iterator_category = std::random_access_iterator_tag;
        using iterator_concept = std::contiguous_iterator_tag;
    };
} // namespace ystdlib
