## What Is A DERIVATIVE

### geometric interpretation
从几何的角度来理解，导数就是在某条曲线，比如\(y = f(x)\)在点\(P(x_0, y_0)\)处的切线。理解切线这个概念可以引入曲线上另一个点\(Q(x_1,y_1)\)，连接两个点我们可以得到一条割线，但是当Q点无线接近P点时，割线就会变成P点的切线。


### physical interpretation

## How To Differentiate any Function
对于形如\(f(x) = x^n\)这样的函数，其导数可以表示为\(f'(x) = nx^{n-1}\).

### Derivative Formular
#### Specific
针对特定的函数形式
1. sin 和 cos
知识回顾：\(sin(a+b)=sina *cosb + cosa*sinb, cos(a+b)=cosa*cosb-sina*sinb\)
导数形式
\((sinx)'=cosx, (cosx)'=-sinx\)

#### General
导数乘法法则 product rule
$$ (uv)' = u'v + uv'$$
$$ (u/v)' = (u'v-uv')/v^2$$

导数加法法则 
$$ (u+v)' = u' + v' $$

合成法则 composition rule/ chain rule
$$\frac{dy}{dt} = \frac{dy}{dx} * \frac{dx}{dt}$$
具体到应用其实就是使用换元法，比如
$$ ((sint)^{10})' = 10(sint)^{9}*cost$$
#### Higher Derivative
