不同于SysTick，Timer属于MCU的外设部分。一款MCU通常有多个Timer,不同的Timer功能上略有区别，具体使用哪一个Timer需要根据需求决定。

对我来说，如果我拿到一款新的MCU并需要使用它的某一个Timer，我可能会根据如下的问题来寻找实现方法：

1. 该Timer的时钟来源是什么，如何进行配置
2. 对于Timer来说，一些通用的设置选项如何实现，比如counter-up还是counter-down，auto-reload counter如何设置
3. 如果需要该Timer触发中断的话，如何进行设置
4. 是否需要该Timer的PWM功能

