stl必要接口
```
template<class T>
class allocator
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T *const_pointer;
    typedef T & reference;
    typedef const T & const_rederence;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    
    template<class U>
    struct rebind
    {
        typedef allocator<U> other;
    };


    void construct(pointer p ,const T& x);
    void destroy(pointer p);

    pointer allocate(size_type n ,const void * = 0);
    void deallocate(pointer p,size_type n);

    pointer address(reference x)const;
    const_pointer const_address(const_reference x)const;

    size_type max_size()const;
};
```

|接口特点|
|-------|
|完备的接口类型|
|可转化为其他allocator|
|把申请内存和初始化类型分开|


问题:  
1. 线程安全
2. 内存碎片
3. 性能
4. 无法创建
5. 跨平台