/*
*   description :
*   start       :
*   finish      :
*
*/

#ifndef _Xiterators_h_
#define _Xiterators_h_

#include "Xiterator_base.h"
#include "Xiterator_tag.h"

template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct input_iterator 
    : public iterator<input_iterator_tag, T, Distance, Pointer, Reference> 
{};


template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct output_iterator
    : public iterator<output_iterator_tag, T, Distance, Pointer, Reference> 
{};


template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct forward_iterator 
    : public iterator<forward_iterator_tag, T, Distance, Pointer, Reference> 
{};


template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct bidirectional_iterator 
    : public iterator<bidirectional_iterator_tag, T, Distance, Pointer, Reference> 
{};

template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct random_access_iterator 
    : public iterator<random_access_iterator_tag, T, Distance, Pointer, Reference> 
{};

#endif