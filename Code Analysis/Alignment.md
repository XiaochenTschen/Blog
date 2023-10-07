```c
if (( xWantedSize & portBYTE_ALIGNMENT_MASK) != 0)
{
    xWantedSize += (portBYTE_ALIGNMENT - (xWantedSize & portBYTE_ALIGNMENT_MASK));
}
```

在数学上，$mod(a,2^n) \leftrightarrow a\&(2^n-1) $. $a\&(2^n-1) $实际上保留a的后n位，也就相当于对$2^n$取余。
知道了这一点后就可以分析上面的代码：
```c
portBYTE_ALIGNMENT_MASK = portBYTE_ALIGNMENT - 1
```
因此代码首先判断xWantedSize是不是portBYTE_ALIGNMENT的整数倍，如果不是的话，对xWantedSize进行调整使其成为portBYTE_ALIGNMENT的整数倍。
