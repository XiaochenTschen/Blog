C语言里面的struct和enum，平时大多都是读代码，自己动手写的时候比较少，因此一些基本用法感觉都很模糊，读代码的时候感觉清晰明了，但是需要自己动手写的时候就感觉哪里都有疑问。所以这里就以代码为示例，写一下enum和struct的使用以及相关的一些问题。

#### enum
```c
enum Cloor
{
    RED, // here use ,
    GREEN,
    BLUE
};

enum Color myColor;
myColor = GREEN;
```
上面这段示例代码说明了enum如何定义，如何声明并初始化变量。需要注意的是，定义enum的时候成员之间要用逗号，声明一个enum变量的时候enum关键字和定义的类型名称都要写上。为了避免这种麻烦，在实际项目中enum常常与typedef一起使用，使用方法见如下代码。

```c
typedef enum
{
    RED, 
    GREEN,
    BLUE
} Color;

Color myColor;
myColor = GREEN;
```

#### Struct
```c
struct Point {
    int x; // here use ；
    int y;
};
struct Point p1;
p1.x = 10;
p1.y = 20;
```
Struct使用起来和enum非常像，但是要注意，在struct里面成员之间要用分号隔开。struct也是经常和typedef一起使用。
```c
typedef struct {
    int x; // here use ；
    int y;
} Point;
Point p1;
p1.x = 10;
p1.y = 20;
```