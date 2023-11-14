### 模板的特化
模板的特化是C++中的一个重要特性，包括完全特化和偏特化

#### 完全特化
当给模板所有的参数都提供了具体的类型或值，这也意味着给模板实例提供了一个专门的实现，这个时候就会发生完全特化。
比如有一个通用的模板函数如下所示：
```c++
template <typename T>
void foo(T value) {
    // 通用实现
}
```
可以为类型 int 提供一个完全特化的版本：
```c++
template <>
void foo<int>(int value) {
    // 针对 int 类型的特化实现
}
```

#### 偏特化
相对于完全特化，偏特化只允许对模板的部分参数提供具体的类型，同时保留其他参数为通用模板。偏特化通常用于类模板，因为C++不支持函数模板的偏特化。
比如有一个通用的模板类如下所示：
```c++
template <typename T, typename U>
class MyClass {
    // 通用实现
};
```
可以为第一个类型参数 T 特化，同时保留第二个参数 U 为通用类型：
```c++
template <typename U>
class MyClass<int, U> {
    // 针对 T 为 int 的偏特化实现
};
```

#### 示例
```c++
namespace RingBufHelper {
  template<bool fits_in_uint8_t> struct Index {
    using Type = uint16_t;        
    using BiggerType = uint32_t;  
  };
  template<> struct Index<false> {
    using Type = uint8_t;         
    using BiggerType = uint16_t; 
  };
}

template <
  typename ET,
  size_t S,
  typename IT = typename RingBufHelper::Index<(S > 255)>::Type,
  typename BT = typename RingBufHelper::Index<(S > 255)>::BiggerType
>
class RingBuf
{
}
```
在这段代码中，RingBufHelper命名空间中的struct就使用了模板的完全特化，也就是当fits_in_uint8_t为false的时候，使用第二个模板，否则使用第一个模板。
因此在RingBuf模板类里面，IT和BT可以根据模板的大小自动选择合适的类型。在这里使用了两个typename，它们是不同的用法：

1. 第一个 typename：这个 typename 用于声明 IT 是这个模板的一个类型参数。在模板参数列表中，使用 typename 或 class 关键字来声明一个类型参数。在这个上下文中，typename 表示 IT 是一个将被用作类型的模板参数。

2. 第二个 typename：这个 typename 用于指示 RingBufHelper::Index<(S > 255)>::Type 是一个依赖于模板参数的类型名称（dependent type name）。在模板定义中，当类型名称依赖于另一个模板参数时，必须在前面加上 typename 来明确指出这是一个类型名称，而不是一个静态成员或其他东西。这里，Type 是依赖于 Index 模板实例化的结果的类型，所以需要 typename。

在模板编程中，编译器在解析模板代码之前并不知道某个模板实例化会是什么，特别是当涉及到从模板参数派生的类型时。因此，typename 关键字用于明确地告诉编译器：接下来的名称应该被解释为一个类型。
