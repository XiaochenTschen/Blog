MISRA C对指针的使用有许多规定，这是因为指针是C语言中容易导致错误和不确定行为的一个部分。下面是MISRA C (以2012版为例)关于指针的部分规定：

1. 不要使用void指针
原因: void指针隐藏了类型信息，从void指针赋值或者解引用都可能导致类型错误。
```c
void *ptr;
int x = 10;
ptr = &x;  // 这违反了MISRA的规则
```

2. 不要进行指针运算
原因: 指针运算可能导致指针超出其预期的边界，从而引发未定义行为。
```c
int arr[10];
int *ptr = arr;
ptr += 11;  // 这违反了MISRA的规则
```

3. 不要在函数间传递或返回指向堆栈的指针
原因: 如果函数返回堆栈上的指针，当函数返回时，该指针可能已经无效。
```c
int *returnStackPointer(void) {
    int x = 10;
    return &x;  // 这违反了MISRA的规则
}
```

4. 指针和数组之间的转换应该被限制
原因: 在某些上下文中，指针和数组是可以互相转换的，但这可能导致混淆和误解。
```c
void func(int *p) {
    int x = p[2];  // 这看起来像是使用数组，但实际上是使用指针
}
```

5. 不要使用函数指针
原因: 函数指针会使程序的控制流变得不明确，并可能被用作恶意攻击的工具。
```c
void someFunction(void) {
    //...
}
void (*func_ptr)(void) = someFunction;  // 这违反了MISRA的规则
```

6. 不要进行指针类型转换
原因: 指针类型转换可能会导致对内存的错误访问或解释。
```c
double x = 0.0;
int* ip = (int*)&x;  // 这违反了MISRA的规则
```

在C和C++中，数组本身并不直接存储它的大小信息。但是，在你定义数组的同一个作用域内，你可以使用sizeof操作符来获取数组的总字节数，然后通过它来计算数组的元素个数.
```c
int arr[10];
size_t size = sizeof(arr) / sizeof(arr[0]);
printf("Number of elements in the array: %zu", size);
```
这里一定要注意**同一个作用域**的问题，这种方法只在数组在当前作用域内定义时有效。如果你将数组作为一个函数参数传递，那么在那个函数中它会被解释为一个指针，你将无法使用这种方法来得知其大小。

---

在上面的介绍中提到了函数指针，这里可以详细说一下：
1. 定义函数指针的时候，需要将指针变量和*符号放到括号里，例如
```c
int (*func)(int, int);
```
试想一下，如果不用小括号，我们写成```int *func(int, int);```,这代表我们声明了一个返回值为int指针的函数，函数名为func。

2. 给函数指针赋值，比如我们有个函数
```c
int add(int a, int b){
    return a+b;
};
func = add;
int sum = func(3,4);
```
**注意：**在C语言中，函数名称（如add）本身就是该函数的地址的引用，因此不需要使用&来获取函数的指针。以下两种赋值方法都是合法的，并且效果相同：
```c
func = add;
func = &add;
```
然而，由于函数名称自动解引用为其地址，第一种形式在实际代码中更为常见。在某些编程环境中，使用第二种形式（带有&）可能会被视为更明确的表示，但它并不是必需的。

定义函数指针的别名，在C/C++中可以使用typedef, C++11之后可以使用using，下面是一个使用实例：
```c
int myFunction(int x, double y) {
    return x + (int)y;
}

typedef int(*FuncPtrType)(int, double);
//using FuncPtrType = int (*)(int, double) 
int main() {
    FuncPtrType ptr = myFunction;
    int result = ptr(3, 4.5);
    return 0;
}

```

