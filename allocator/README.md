sgi allocators

https://www.boost.org/sgi/stl/Allocators.html

实现allocator类型：alloc

实现功能
```
0. 内存分配，释放
1. 初始化：拷贝，迭代器
3. 缓冲区
```

allocator原则  
> 将内存分配和构造两个步骤明显分开，因为有时候我们并不关心初始值，而一味的构造只会降低性能

