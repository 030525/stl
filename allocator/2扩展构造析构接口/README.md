我们实现了基本的allocator后，仍有些问题需要扩展

我们的allocator专注于内存的分配释放，很少关心对象的初始化,allocator即使有construct和destory，也只是调用对象的构造和析构而已

这里我们进行扩展

Xconstruct.h对应全局的构造析构函数
Xuninitialzed.h对应全局的未初始化的策略

Xconstruct.h  
---
构造
```
template<class T1,class T2>
inline void construct(T1 * p ,const T2& x);
```

析构  
```
template<class T>
inline void destroy(T * p)

template<class ForwardIterator>
inline void destroy(ForwardIterator first,ForwardIterator last);

inline void destroy(char *,char *);
inline void destroy(wchar_t*,wchar_t*);
```

普通指针析构，迭代器析构，c-string的特化处理

---
Xuninitialzed.h
---

```
// copy [first,last)的内容，从result开始
template <class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last,ForwardIterator result);

// 填充 x 到[first,last)
template <class ForwardIterator, class T>
void uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& x);

// 填充n个x 从first开始
template <class ForwardIterator, class Size, class T>
ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n,const T& x);


```