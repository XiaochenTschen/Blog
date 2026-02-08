### Memory Map
以32位的MCU来说，它能支持的最大内存空间是4GB，以Arm Cortex-M为例，该内核支持的内存空间可以划分为如下几部分：
1. 0x0000 0000 - 0x2000 0000, 0.5GB Code Section
2. 0x2000 0000 - 0x4000 0000, 0.5GB SRAM Section
3. 0x4000 0000 - 0x6000 0000, 0.5GB Peripheral Section
4. 0x6000 0000 - 0xA000 0000, 1.0GB External Device Section
5. 0xA000 0000 - 0xE000 0000, 1.0GB External RAM Section
6. 0xE000 0000 - 0xFFFF FFFF, 0.5GB System Section

### Memory Types
虽然Cortex-M4内核最大支持4GB存储空间，但实际情况下MCU真正可用的存储远小于这个数量。
对于MCU来说，常用到的存储介质可以分为如下三类：Flash, RAM and EEPROM

### Code Section
MCU的Code Section通常使用internal flash memory，相对于理论上的0.5GB(起始地址0x0000 0000)，通常只有1MB左右的大小(起始地址0x0800 0000)，高性能的MCU空间会更大。

Code Section的内容在map文件中可以在.text段中查看。.text段的布局是由链接脚本决定的，但通常可以划分为如下几部分：
1. **Bootloader Section** (optonal)
2. **Interrupt Vector Table**
3. **Text Section**: (所有源文件编译生成的机器指令)
4. **RO Data Section**: .rodata, 变量的值在runtime不能被修改，数据不需要加载到RAM，程序会直接读取Flash中的内容
5. **RW Data Section**: Flash中存储.data初始值的内容，程序启动的时候这部分的值会加载到RAM的.data段

Cortex-M内核的内存映射机制，可以将其实地址为0x0800 0000的Initial MSP和Interrupt Vector Table映射到起始位置0x0000 0000的位置，以满足System Boot时访问中断向量表和初始堆栈指针。

### RAM

在MCU中，RAM通常是SRAM，使用中可以被划分为如下的区域：

##### Initialized data
**.data**: 该区域存储那些已经被初始化过的全局变量

##### Zero-initialized data
**.bss**: 该区域存储那些没有被初始化过(默认初始值为0)的全局变量

##### Stack
位于SRAM地址的最顶端，向下生长

##### Heap
位于SRAM空闲地址的最低端，向上生长

### Compiling
All source code will be compiled into machine code, the so-called object files.
Which kind of object files are got depends on which kind of compiler used. In most case object files are with ELF format.

Each object file can be divided into different sections
.text: programm code
.bss:  stored in RAM, globle variable not initialized
.data: stored in RAM, global variable
.const: stored in flash, const global variable

All object files can be linked together via linker script. During this process, the memory layout should be deceided, including RAM and flash, where to put different section contents.

When reset the MCU, a piece of startup code will be executed. This code will initialize the RAM (runs before main), initialize the data and stack.

global variables with initialization (.data + .const) saved in RAM + FLASH
local variables with initialization (.stack + .const) saved in RAM + FLASH
stctic variable (.data + .const) saved in RAM + FLASH
program code (.text) saved in FLASH
