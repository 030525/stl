/*
*   description : 萃取迭代器，目的是在编译时根据不同的类型，选择不同的特化，从而提升效率，避免运行时判断类型降低效率
*   start       :
*   finish      :
*
*/

#ifndef _Xiterator_traits_h_
#define _Xiterator_traits_h_

#include "Xiterators.h"

template<class Iter>
struct iterator_traits
{
    typedef typename Iter::iterator_category iterator_category;
    typedef typename Iter::value_type value_type;
    typedef typename Iter::difference_type difference_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;
};

// 对普通指针的特化，使得普通指针可以使用迭代器功能
template <class _Tp>
struct iterator_traits<_Tp*> 
{
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp                         value_type;
  typedef ptrdiff_t                   difference_type;
  typedef _Tp*                        pointer;
  typedef _Tp&                        reference;
};

template <class _Tp>
struct iterator_traits<const _Tp*> 
{
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp                         value_type;
  typedef ptrdiff_t                   difference_type;
  typedef const _Tp*                  pointer;
  typedef const _Tp&                  reference;
};

// 萃取对应的类型
template <class _Iter>
inline typename iterator_traits<_Iter>::iterator_category __iterator_category(const _Iter&)
{
  typedef typename iterator_traits<_Iter>::iterator_category _Category;
  return _Category();
}

template <class _Iter>
inline typename iterator_traits<_Iter>::difference_type* __distance_type(const _Iter&)
{
  return static_cast<typename iterator_traits<_Iter>::difference_type*>(0);
}

template <class _Iter>
inline typename iterator_traits<_Iter>::value_type* __value_type(const _Iter&)
{
  return static_cast<typename iterator_traits<_Iter>::value_type*>(0);
}

template <class _Iter>
inline typename iterator_traits<_Iter>::iterator_category iterator_category(const _Iter& __i) 
{
     return __iterator_category(__i); 
}

template <class _Iter>
inline typename iterator_traits<_Iter>::difference_type* distance_type(const _Iter& __i) 
{
     return __distance_type(__i); 
}

template <class _Iter>
inline typename iterator_traits<_Iter>::value_type* value_type(const _Iter& __i) 
{ 
    return __value_type(__i); 
}

// 输入iter，获取tag
template <class _Tp, class _Distance> 
inline input_iterator_tag iterator_category(const input_iterator<_Tp, _Distance>&)
{ 
    return input_iterator_tag(); 
}

template <class _Tp, class _Distance> 
inline output_iterator_tag iterator_category(const output_iterator<_Tp, _Distance>&)
{ 
    return output_iterator_tag();
}

template <class _Tp, class _Distance> 
inline forward_iterator_tag iterator_category(const forward_iterator<_Tp, _Distance>&)
{ 
    return forward_iterator_tag(); 
}

template <class _Tp, class _Distance> 
inline bidirectional_iterator_tag iterator_category(const bidirectional_iterator<_Tp, _Distance>&)
{ 
    return bidirectional_iterator_tag(); 
}

template <class _Tp, class _Distance> 
inline random_access_iterator_tag iterator_category(const random_access_iterator<_Tp, _Distance>&)
{ 
    return random_access_iterator_tag(); 
}



#endif