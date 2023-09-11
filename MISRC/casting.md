```
the value of an expression of integer type shall not be implicated converted to a different underlying data type if:
 (a) it is not a conversion to a wider integer type of the same signedness, or
 (b) the expression is complex, or
 (c) the expression is not constant and is a function arguement,or 
 (d) the expression is not constant and is a return expression.
```
underlaying data type最常遇到的场景是字面型常量和枚举类型，在C语言中，枚举类型或者字面型常量的underlying data type通常是int。

在MISRC标准中，在函数操作中，implicate cast是不建议的，而underlying data type很容易被忽略，因此在代码中需要根据其他变量的数据类型，对枚举类型或者字面型常量做显式的类型转换，也可以对字面型常量加后缀来指定其类型（如U, L, LL, UL等），比如10U就代表这个字面型常量是unsigned int。

对于位运算，比如移位运算，运算符左边的变量必须是unsigned，右侧的变量并未做强制规定，但必须是有意义的。按位与或操作，操作符两边的变量如果类型不同，则会有隐式转换的问题。

对于文章开始贴出来的规定，下面会进行逐条分析并附上示例代码。

1. 只有当目标类型的位宽比源类型宽，且两者的符号性相同（即都是有符号或无符号）时，才允许隐式转换。
```c
int16_t smallInt = 32767;
int32_t bigInt = smallInt;  // 允许的，因为从短整型转到长整型，并且它们都是有符号的

int32_t intVal = 2147483647;
int16_t smallVal = intVal;  // 不允许，可能导致溢出
```

2. 表达式是复杂的.
```c
int32_t val1 = 10000;
int32_t val2 = 20000;
uint16_t result = val1 * val2;  // 不允许，因为这是一个复杂表达式并且可能导致溢出
```

3. 表达式不是常量并且是函数参数, 这意味着不应该隐式地将函数的非常量参数转换为其他类型。
```c
void function(uint16_t param) {...}

int32_t arg = 32767;
function(arg);  // 不允许，因为arg是一个非常量，并且它的类型与参数不匹配
```

4. 表达式不是常量并且是返回表达式, 当函数返回非常量值时，该值不应隐式转换为不同的类型。
```c
uint16_t function(void) {
    int32_t val = 32767;
    return val;  // 不允许，因为val是一个非常量，并且它的类型与返回类型不匹配
}
```

