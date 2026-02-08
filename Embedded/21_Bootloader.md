bootloader可能在不同的技术语境下有不同的意思。
bootloader可能有不同的层级：
    initial bootloader，储存在不能被修改rom区域中，通常在MCU上电的时候运行，对整个系统进行初始化操作，并跳转到程序执行的起始点。
    其他用户自定义的bootloader，initial bootloader之后首先执行这段程序，其功能可以是对主程序做一些初始化操作，执行一些安全检查或者从外部存储器加载程序之类的操作。

### Bootloader Design Example with STM32F401
对于一个程序来说，大致可以分为如下两部分:
1. Interrupt Vector Table
2. Code and Data

Interrupt Vector Table中的每个条目都是一个指针
Interrupt Vector Table的第一个条目是一个地址，该地址是RAM中程序开始执行的地址。
Interrupt Vector Table的第二个条目是reset vector，规定了程序进入reset状态的时候需要做哪些处理，也是程序最开始执行的位置。