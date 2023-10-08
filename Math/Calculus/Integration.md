积分，相当于微分的逆运算，但是要在最终的结果后面加上一个常数，因为常数的微分等于0.正是由于常数的存在，这样的积分又叫做不定积分indefinite integral.
### 不定积分的计算方法

#### 记住一些常见的积分公式

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