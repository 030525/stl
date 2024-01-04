/*
*   description : implement functions of uninit object
*   author      : xwj
*   start       : 2024/1/4 18:30
*   finish      :
*
*/

#ifndef _Xuninitialzed_h_
#define _Xuninitialzed_h_

// commit or rollback
// 要么构造出所有必要的内容，要么不构造
// 有异常时，必须析构所有已经构造好的内容


// 都是用迭代器进行初始化填充

// copy [first,last)的内容，从result开始
template <class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last,ForwardIterator result);

// 填充 x 到[first,last)
template <class ForwardIterator, class T>
void uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& x);

// 填充n个x 从first开始
template <class ForwardIterator, class Size, class T>
ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n,const T& x);

#endif