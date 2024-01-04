/*
*   description   : implement allocator interface
*   author        : xwj
*   start         : 2024/1/4 17:31
*   end           : 2024/1/4 18:23
*/

#ifndef _Xallocator_h_
#define _Xallocator_h_

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>


template<class T>
class allocator
{
public:
    // 为什么如此设置类型，以后会讲到
    typedef T value_type;
    typedef T* pointer;
    typedef const T *const_pointer;
    typedef T & reference;
    typedef const T & const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    
    // 随时转化类型，从allocator<int> 变为allocator<char>
    template<class U>
    struct rebind
    {
        typedef allocator<U> other;
    };

    // 为什么这里需要用T1来构造，而不是T，可能是想实现int a = 3.5类似的自动类型转化的构造，所以使用两个类型来进行构造
    template<class T1>
    void construct(pointer p ,const T1& x)
    {
        new(p) T(x);
    }

    void destroy(pointer p)
    {
        p->~T();
    }

    pointer allocate(size_type n ,const void * = 0)
    {
        // ::opeartor new不是普通的new，是只有内存分配的new，并不涉及调用构造函数
        // 如果out of memory 会抛出异常
        pointer p = (T*)(::operator new((size_t)(n * sizeof(T))));

        return p;
    }

    void deallocate(pointer p,size_type n)
    {
        ::operator delete(p, n * sizeof(T));
    }

    pointer address(reference x)const
    {
        return (pointer)&x;
    }

    const_pointer const_address(const_reference x)const
    {
        return (const_pointer)&x;
    }

    // 数值上可以分配多少个T，并不是heap上真能分配这么多
    size_type max_size()const
    {
        //这里的UINT_MAX指的是跨平台都统一的类型,
        return (UINT_MAX / sizeof(T));
    }
};


#endif