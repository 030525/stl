STL allocator标准接口
```
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

    // 构造析构
    template<class T1>
    void construct(pointer p ,const T1& x);
    void destroy(pointer p);

    //分配释放内存
    pointer allocate(size_type n ,const void * = 0);
    void deallocate(pointer p,size_type n);

    //分配后的指针地址
    pointer address(reference x)const;
    const_pointer const_address(const_reference x)const;

    //最大分配T量
    size_type max_size()const;
};

```

