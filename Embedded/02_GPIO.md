### PORT and GPIO Pin
Port可以理解为GPIO在逻辑上的分组，每个Port由一组GPIO Pin组成，并通过一系列的寄存器来控制操作。
GPIO的Pin就是直观上的芯片GPIO的引脚，每一个Port包含的引脚数往往是固定的，通常为8到16个。

### Port Registers
对于同一款MCU来说，每个Port都有一套自己的Register，用来控制该Port的各种设置；不同的Port所拥有的Register相同，因此控制PortA的逻辑也可以控制其他的Port。

对于不同的MCU，GPIO的功能实现略有差异，因此它们的Register也各不相同；但是需要实现的功能都是类似的，因此寄存器的种类有相似之处，例如，所有的MCU都需要模式寄存器，输入输出寄存器等。

要实现GPIO某一种的功能，不同的MCU需要进行的操作大体也是类似的。因此，了解并熟悉一款MCU GPIO的基本功能和控制方法对于学习其他MCU也是很有帮助的。当遇到新的MCU时，可以按照功能需求去查看如何操作相应的寄存器来实现。

### GPIO Mode
GPIO模式可以简单分为输入，输出, 复用(其他的外设使用该引脚实现相应的功能)和Analog四种。

### Input
1. Input Floating
    GPIO引脚不连接到任何上拉或者下拉电阻。
2. Input Pull-Up
    GPIO引脚连接到上拉电阻，适用于默认高电平输入的场景，比如按钮按下的时候可以接地拉低信号。
3. Input Pull-Down
    GPIO引脚连接到下拉电阻，适用于默认低电平输入的场景，比如按钮按下连接到电源拉高电平。
4. EXIT 
    可以通过配置寄存器来实现哪个引脚开启中断功能，以STM32为例，SYSCFG_EXTICR寄存器可以控制哪个引脚连接到相对应的EXTI line；然后再通过相应的EXTI寄存器，配置相关中断的mask，edge等选项。ISR的实现要参考NVIC的实现，自定义的函数要使用和weak定义的函数同样的签名。

### Output Type
1. Open-Drain
    在开漏模式下，GPIO 引脚只能输出低电平或高阻态（悬空状态）。如果需要输出高电平，通常需要通过外部上拉电阻将信号拉高。

2. Push-Pull
    在推挽模式下，GPIO 引脚可以主动输出高电平或低电平，不需要外部电阻。

### GPIO other Configuration
GPIO speed, pull-p/pull-down, input/output data register, ect. 

### How to Use
对于一款MCU的GPIO，如果我想要使用某个引脚，那么我会按照如下的步骤思考：
1. 如何enable芯片的GPIO功能，有的MCU GPIO默认都是开启的，而STM32需要enable相应的GPIO时钟才能开启。
2. 设置GPIO该引脚的模式，是出入还是输出，是否需要上拉或者下拉电阻。
3. GPIO是否需要接口复用的功能，如何操作寄存器开启相关功能。
3. 按照需求根据input/output data register设置引脚的状态。


