/*
*   description : construct destory function
*   author      : xwj
*   start       : 2024/1/4 18:44
*   finish      :
*
*/

#ifndef _Xconstruct_h_
#define _Xconstruct_h_

#include <new>

// 基本的拷贝构造和析构
template<class T1,class T2>
inline void construct(T1 * p ,const T2& x)
{
    new(p) T1(x);
}

template<class T>
inline void destroy(T * p)
{
    p->~T();
}

// 迭代器
template<class ForwardIterator>
inline void destory(ForwardIterator first,ForwardIterator last);

#endif