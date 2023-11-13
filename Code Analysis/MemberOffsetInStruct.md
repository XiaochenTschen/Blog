当我们分析一个成员在结构体中相较于结构体起始地址偏移量的时候，通常先考虑当前程序使用的对齐方式是怎样的，然后看各个成员变量所需内存的大小，然后计算得出各个成员在结构体中的偏移量。
如果在程序中需要计算相应的偏移量数值的话，下面的宏定义可以满足我们的需求。
```c
define offset(s, m) ((size_t)&((s*)0)->m)
```
在这个宏定义中，s表示结构体类型，m表示成员，首先我们将0地址转换为s类型的指针，然后获取m成员，这个时候再取m成员的地址的话，将相当于偏移量，然后再将地址变量转换为size_t类型，方便后续的数学操作。