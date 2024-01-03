/*
*   description   :
*   start    date :
*   design   date :
*   realize  date :
*
*/

#ifndef _Xallocator_h_
#define _Xallocator_h_

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace X
{

template<class T>
class allocator
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T *const_pointer;
    typedef T & reference;
    typedef const T & const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    
    template<class U>
    struct rebind
    {
        typedef allocator<U> other;
    };


    void construct(pointer p ,const T& x){}
    void destroy(pointer p){}

    pointer allocate(size_type n ,const void * = 0){}
    void deallocate(pointer p,size_type n){}

    pointer address(reference x)const{}
    const_pointer const_address(const_reference x)const{}

    size_type max_size()const{}
};

}

#endif