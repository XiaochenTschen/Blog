积分，相当于微分的逆运算，但是要在最终的结果后面加上一个常数，因为常数的微分等于0.正是由于常数的存在，这样的积分又叫做不定积分indefinite integral.
### 不定积分的计算方法

#### 记住一些常见的积分公式
$\int sin(x)dx  = -cos(x) + C $
$\int x^adx = \frac{1}{a+1}x^{a+1} + C $
$\int \frac{dx}{x} = ln|x| + C $
$\int sec^2(x)dx = tan(x) + C $
$\int \frac{dx}{\sqrt{1-x^2}} = sin^{-1}(x) + C $
$\int \frac{dx}{1+x^2} = tan^{-1}(x) + C $

#### 换元法

1. $\int x^3(x^4+2)^5dx $
$u = x^4+2 \Rightarrow du=4x^3dx $
带入原式可得：$\int u^5\frac{1}{4}du = \frac{1}{24}u^6+C $ 

2. $\int \frac{dx}{xlnx} $
$u=lnx \Rightarrow du=\frac{dx}{x} $
带入原式可得： $\int \frac{du}{u} = ln|u| + C \Rightarrow ln|lnx| + C $

#### 猜测法

根据经验事先预估积分结果，然后对预估的结果进行微分，和积分项进行比较然后做相应的调整。
1. $\int \frac{xdx}{\sqrt{1+x^2}} $
假设 $u=\sqrt{1+x^2} \Rightarrow \frac{du}{dx} = \frac{2x}{2\sqrt{1+x^2}} $
2. $\int xe^{-x^2} $
假设 $u=e^{-x^2} \Rightarrow \frac{du}{dx} = -2xe^{-x^2} $，再调整系数即可

#### Separation Variables 分离变量法
$\frac{dy}{dx} = f(x)g(y) $
$\frac{dy}{g(y)} = f(x)dx  \Rightarrow H(y) = \int \frac{dy}{g(y)}, F(x) = \int f(x)dx \Rightarrow H(y) = F(x) + C $

___

### 定积分 Definite Integrals
相对于不定积分来说，定积分确定了积分区间。

#### Theory 1

if $F'(x) = f(x) $, then $\int_a^b f(x)dx = F(b) - F(a) = F(x)\bigg|_a^b $
该定理可以延伸出很多与之相关的小定理：
1. $\int_a^b (f(x)+g(x))dx = \int_a^b f(x)dx + \int_a^b g(x)dx $
2. $\int_a^b cf(x)dx = c\int_a^b f(x)dx $
3. $\int_a^b f(x)dx + \int_b^c f(x)dx = \int_a^c f(x)dx $
4. $\int_a^a f(x)dx = 0 $
5. $\int_a^b f(x)dx = -\int_b^a f(x)dx $
6. if $f(x) < g(x) $, then $\int_a^b f(x)dx < \int_a^b g(x)dx $
7. $\int_{u_1}^{u_2} g(u)du = \int_{x_1}^{x_2} g(u(x))u'(x)dx $, where $u = u(x), du = u'(x)dx $
e.g. $\int_1^2 (x^3+2)^5x^2dx $, with $u = x^3+2, du = 3x^2dx $, then it is equal to $\int_3^{10} \frac{1}{3}u^5du $ 

#### Theory 2

if function $f$ is continous, and $G(x) = \int_a^x f(t)dt $, then $G'(x) = f(x) $
With this theory, we can prove, e.g. $\int_a^b f(x)dx = F(b) - F(a) $.
Define $G(x) = \int_a^x f(t)dt $, then $G'(x) = f(x) \Rightarrow F'(x) = G'(x) \Rightarrow F(x) = G(x) + C $
Hence $F(b)-F(a) = (G(b)+C)-(G(a)+C) = G(b)-G(a) = \int_a^b f(x)dx - \int_a^a f(x)dx = \int_a^b f(x)dx $

#### Numerical Integration

对一个函数做积分，可以把变量切分成很多小的部分，然后利用每一个小部分对应的面积求和，最终得到积分结果。在计算每个小部分的时候，有不同的方法可以进行计算。

1. **Riemann Sum** 
将每个小部分看作小矩形，计算每个小矩形的面积。而且容易理解，分割后小矩形左右边是不同的，所以又有两种计算方式。
$(y_0+y_1+y_2+...+y_{n-1})\Delta x $ (left hand)
$(+y_1+y_2+y_3...+y_n)\Delta x $ (right hand)

2. **Trapezoidel rule**
切分后的图形不再看作小矩形，而是看作小梯形，因此面积计算变成
$\Delta x(\frac{y_0+y_1}{2} + \frac{y_1+y_2}{2} + \frac{y_2+y_3}{2} + ... + \frac{y_{n-1}+y_n}{2}) = \Delta x (\frac{y_0}{2} + y_1 + y_2 +y_3 + ... + y_{n-1} + \frac{y_n}{2}) $
观察上面的式子，它的结果其实是上面Riemann Sum两种取值方式的平均值。

3. **Simpson's Rule**
该定理会把相邻的三个点用抛物线连接起来，然后取高度平均值作为高，然后乘以底作为面积。
在这种情况下，base: $2\Delta x$, average: $\frac{y_0+4y_1+y_2}{6} $
最终的计算结果：$\frac{\Delta x}{3}(y_0+4y_1+2y_2+4y_3+2y_4 + ... 2y_{n-2} + 4y_{n-1}+y_n) $
由该方法计算得到的结果和实际值插值的绝对值有如下的规律:
$|Simpson's - ExactAns| \approx (\Delta x)^4 $
再次，对于平均值的计算可以由如下推导得出：
假设抛物线方程为$y = Ax^2 + Bx + C $, 两个端点值为 $(x_1, y_1),(x_3, y_3) $,则该区间的平均高度计算如下：
$\int_{x_1}^{x_3}(Ax^2 +Bx + C) = \frac{A}{3}x^3 + \frac{B}{2}x^2 +Cx \bigg|_{x_1}^{x_3} = \frac{A}{3}(x_3^3 - x_1^3) + \frac{B}{2}(x_3^2-x_1^2) + C(x_3 - x_1) $
$= \frac{A}{3}((x_3-x_1)(x_3^2+x_3x_1+x_1^2)) + \frac{B}{2}(x_3-x_1)(x_3+x_1) + C(x_3-x_1) $
$= \frac{x_3-x_1}{6}(2A(x_3^2+x_3x_1+x_1^2) + 3B(x_3+x_1) + 6C) $
$= \frac{x_3-x_1}{6}(Ax_3^2 + Ax_1^2 + A(x_3^2 + 2x_3x_1 + x_1^2) + Bx_3 + Bx_1 + 2B(x_3+x_1) + 6C) $ with $x_3 + x_1 = 2x_2 $
$= \frac{x_3-x_1}{6}((Ax_3^2 + Bx_3 + C) + (Ax_1^2 + Bx_1 + C) + (A(x_3+x_1)^2 + 2B(x_3+x_1) + 4C)) $
$= \frac{x_3-x_1}{6}((Ax_3^2 + Bx_3 + C) + (Ax_1^2 + Bx_1 + C) + (A(2x_2)^2 + 2B(2x_2) + 4C)) $
$= \frac{x_3-x_1}{6}(y_3 + y_1 + 4y_2) $