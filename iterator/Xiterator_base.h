/*
*   description :
*   start       :
*   finish      :
*
*/

#ifndef _Xiterator_base_h_
#define _Xiterator_base_h_

#include <cstddef>

template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator 
{
    typedef Category iterator_category;
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
};


#endif