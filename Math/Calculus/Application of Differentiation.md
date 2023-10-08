### Linear Approximation

$$f(x) \approx f(x_0) + f'(x_0)(x-x_0) $$
公式的几何意义：对于一条曲线$y=f(x) $, 在点$ x_0$ 处近似等于在该点的切线$ y=f(x_0)+f'(x_0)(x-x_0) $。

### Quadratic Approximation

$$f(x) \approx f(x_0) + f'(x_0)(x-x_0) + \frac{f''(x)}{2}(x-x_0)^2 $$

二阶近似只有在线性近似精度不够的情况下才会使用。
二阶近似的几何意义：见下

### Curve Sketching

Goal: Draw graph of \(f\) using \(f', f''\) positive/negative
1. $f'>0 \Rightarrow f$ is increasing and vice versa
2. $f''>0 \Rightarrow f'$ is increasing, $f$ is concave up(凸) and vice versa

if $f'(x_0)=0 $ we call $x_0$ a critical point. $y_0 = f(x_0)$ is a critical value. 
if $f''(x_0)=0 $ we call $x_0$ a inflection point(拐点).

画函数图像的基本步骤和需要注意的事项如下：
1. 找到函数不连续的点，这些点会将横轴划分为不同的区域。
2. 分析函数在不连续的点两侧的值是多少，以及分析函数在端点位置的值是多少(end points, 通常为正负无穷远)。
3. 利用一阶微分寻找驻点，并计算驻点处的数值。
4. 可选：利用二阶微分判断凹凸性。

### Max/Min Problems


### Commen Foumular with Quadratic Approximation
$sinx \approx x $
$cosx \approx 1 - \frac{1}{2}x^2 $
$e^x \approx 1 + x + \frac{1}{2}x^2 $
$ln(1+x) \approx x - \frac{1}{2}x^2 $
$(1+x)^r \approx 1 + rx + \frac{r(r-1)}{2} $

### Example

#### Linear Approximation of $e^{-3x}(1+x)^{-\frac{1}{2}} $
首先可以利用上面的公式分别计算公式两项的线性近似：
$e^{-3x} \approx 1-3x $
$(1+x)^{-\frac{1}{2}} \approx 1 - \frac{1}{2}x $
然后我们将两项相乘，忽略所有的高阶项，可以得到：
$e^{-3x}(1+x)^{-\frac{1}{2}} \approx 1 - \frac{7}{2}x $

#### Quadratic Approximation of $e^{-3x}(1+x)^{-\frac{1}{2}} $
同样的道理，分别计算两项的二次近似：
$e^{-3x} \approx 1-3x+\frac{1}{2}(3x)^2 $
$(1+x)^{-\frac{1}{2}} \approx 1 - \frac{1}{2}x + \frac{3}{8}x^2 $
同样两项相乘，忽略高于二次的项，得到最终结果。

### Related Rates
通俗来说，就是两个变量之间满足一定的约束条件，利用这个约束条件来计算相应的微分。
**举例：** 比如说一个测速装置，举例马路30m，在40m远处驶来一辆汽车，测速装置测得速度为80m/s，那实际速度是多少.
在这个问题中，可以设汽车沿马路距离测速仪为x，距离测速仪的直线距离为D，那么两者满足如下方程：
\(x^2+30^2=D^2\)
这个公式就包含了两个变量之间的隐含关系，同时对时间t取微分：
\(\frac{dx}{dt}(2x) = 2D\frac{dD}{dt} \Rightarrow \frac{dx}{dt} =\frac{dD}{dt}\frac{D}{x} \)
通过这种方式问题得以解决。