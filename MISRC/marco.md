```
marcos shall only expand to :
a braced intialiser
a string literal
a parenthesised expression
a type qualifier
a storage class specifier
or a do-while-zero construct
```
MISRC对宏展开有严格的规定，一下最上面的规定逐条进行分析并附上示例代码。

1. Braced Initialiser
```c
#define INIT_STRUCT {1, 2, 3}
struct S { int a, b, c; };
struct S s = INIT_STRUCT;
```

2. String Literal
```c
#define GREETING "Hello, World!"
printf(GREETING);
```

3. Parenthesised Expression
```c
#define GREETING "Hello, World!"
printf(GREETING);
```

4. Type Qualifier
```c
#define CONST_QUALIFIER const
CONST_QUALIFIER int x = 5;
```

5. Storage Class Specifier
```c
#define STATIC_STORAGE static
STATIC_STORAGE int counter = 0;
```

6. Do-While-Zero Construct: 这是一种常用的技巧，使得宏展开后可以像一个语句那样工作，确保宏在任何地方都能安全地使用，不会引入错误。
```c
#define DO_SOMETHING(x) do { printf("%d", x); } while(0)
if(condition)
    DO_SOMETHING(5);  // 这里没有问题，因为do-while-zero模式使宏像一个完整的语句。
else
    // some other code
```

除了上述的规定，关于宏MISRC还有其他的规定，比如：
```
'()' shall not be used within a macro body except to surround the expansion of a parameter.
```
```c
#define SQUARE(a) a * a // falsh
#define SQUARE(a) ((a) * (a)) // right
```