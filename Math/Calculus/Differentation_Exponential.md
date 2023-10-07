### Problem
这一部分着重介绍指数函数的微分形式是如何推导出来的，以及在推导过程中如何引进自然对数\(e\).

根据微分的定义来计算指数函数的微分形式。
$$(a^x)'=\lim_{x \to 0}\frac{a^{x+\Delta x}-a^x}{\Delta x}=\lim_{x \to 0}\frac{a^x(a^{\Delta x}-1)}{\Delta x} = a^x\lim_{x \to 0}\frac{(a^{\Delta x}-1)}{\Delta x}$$
令\(M(a) = \lim_{x \to 0}\frac{(a^{\Delta x}-1)}{\Delta x}\):
$$ (a^x)' = M(a)a^x$$
问题到这一步，难点在于如何计算\(M(a)\).

### Natural Number
为了解决这个问题，我们引入自然对数的概念，假设有这么一个数\(e\), 以它为底的对数方程表示为\(lnx\), 该数满足\(M(e) = 1\). 在这个假设的前提下我们还可以知道$ (e^x)' = e^x$.

为什么这个\(e\)是存在的，我们令$f(x) = 2^x $, 根据上面计算指数函数的公式可知，$f(x) $在0点处的切线斜率为$M(2) $. 这时我们可以对横坐标进行缩放，令$f(kx) = 2^{kx} = (2^k)^x = b^x, b = 2^k $. 继续对$b^x $ 求微分的话可得：
$$\frac{d}{dx}b^x = \frac{d}{dx}f(kx) = kf'(kx) \stackrel{\text{x=0}}{=} kf'(0) = k*M(2) $$
根据上面推导的公式和我们做出的假设，如果\(b = e\), 那么只需要满足\( k*M(2) = 1\)即可。扩展开来，对于任何底数\(a\), \(e = \frac{1}{M(a)} \).

计算\(lnx\)的微分我们可以使用反函数的方法。令 $w=lnx \Rightarrow e^w=x$，两边分别对\(x\)进行微分，则有：
$$\frac{d}{dx}e^w=1 \Rightarrow \frac{d}{dw}e^w*\frac{dw}{dx}=1$$
$$\frac{dw}{dx}*e^w=1 \Rightarrow \frac{dw}{dx} = \frac{1}{e^w}=\frac{1}{x} $$

### How To Use
有了自然对数的概念，我们来看看如何计算指数函数的微分形式：

令$a^x=(e^{lna})^x=e^{xlna} $, 则有：
$$\frac{d}{dx}a^x = \frac{d}{dx}e^{xlna} = e^xlna*lna = lna*a^x $$

也可以使用对数微分法 logarithmic differentation
计算函数\(u\)的微分，我们可以计算函数\(lnu\)的微分，\(\frac{d}{dx}lnu = \frac{dlnu}{du} * \frac{du}{dx} = \frac{1}{u}*\frac{du}{dx}\). 即\((lnu)' = \frac{u'}{u} \).
当我们令$u = a^x $,则有$u' = u*(lnu)' = u*(xlna)' = lna*a^x $
同样的方法，如果我们令$u = x^x$, 则有$(lnu)' = (xlnx)' = lnx + x*\frac{1}{x} = lnx+1 $
可得$u' = u*(lnu)' = (1+lnx)x^x $

自然底数$e$还可以表示为如下等式：
$$ e = \lim_{x \to \infty}(1 + \frac{1}{n})^n $$
如何证明这个等式，首先我们对取极限的公式取对数：
$$ln((1 + \frac{1}{n})^n) = nln(1 + \frac{1}{n}) = \frac{1}{\Delta x}ln(1 + \Delta x) = \frac{1}{\Delta x}(ln(1 + \Delta x) - ln1), ln1 = 0 $$
当\(n\)趋向于无穷大的时候，相当于\(\Delta x\)趋向于0，那么上述公式就相当于计算\(lnx\)在\(x=1\)处的导数，即为1.
$$\lim_{n \to \infty}ln((1 + \frac{1}{n})^n) = 1 \Rightarrow e = \lim_{x \to \infty}(1 + \frac{1}{n})^n $$
