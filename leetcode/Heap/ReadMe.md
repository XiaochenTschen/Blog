Heap可以分为最大堆和最小堆，通常用来解决第K个最大或者最小元素的问题。

C++中的堆数据结构是由queue中的priority_queue实现的，默认情况下用户得到的是一个最大堆，也就是最大的(或者说优先级最大的)元素在最顶端；如果要实现一个最小堆的话，在创建堆的时候需要传入一个比较函数。搞清楚实现最大堆和最小堆时需要用什么样子的比较函数，首先要明白优先序列的排序规则。

优先序列是依靠底层的容器实现的，通常是vector。元素在序列中存在优先级顺序，优先级高的元素会排在序列前面，优先级低的元素会排在容器后面。当对序列进行pop操作的时候，由于底层的数据结构是vector，因此取值是从后向前来的，由此可以实现最大堆和最小堆。

因此，想要让序列中的元素按照我们的需求进行排序，就要选择或者自定义排序函数，C++有相应的库函数可以使用，当库函数无法满足需求的时候，我们就需要自己定义。而这个排序函数就是决定了元素优先级问题。

排序函数实际上是重载了'operator()',它接受两个输入参数，当返回值为true的时候，说明第一个参数的优先级大于第二个参数；返回false的时候，说明第一个参数的优先级小于第二个参数。

根据上面的理论我们可以理解，为什么实现最大堆默认的排序的函数时std::less，less函数在第一个值大于第二个值的时候返回true，但它说明第一个值的优先级大于第二个值，因此第一个值排在第二个值之前，以此类推，在底层的vector元素时升序排列的，pop元素的时候就会从大到小。同样的道理也可以解释为什么最小堆会使用std::greater函数。

对于复杂一点的元素，比如std::pair，我们可以自定义比较函数。比如std::pair<string, int>，我们希望根据int值实现一个最小堆，当int值相等的时候string按照字母序列排序。我们的比较函数可以写成如下形式：
```c++
struct Compare // member is public as default
{
    bool opreator()(conts std::pair<std::string, int>& a, conts std::pair<std::string, int>& b)
    {
        if(a.second == b.second) return a.second < b.second;
        else return a.first > b.first;
    }
};
```
当在有限序列中使用这个比较函数的时候，可以使用如下语句，其中第一个参数代表序列中的元素类型，第二个参数代表底层容器，第三个参数代表排序函数：
```c++
std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> pq;
```

除了定义Compare类，也可以通过lambda表达式来实现同样的效果。
```c++
auto comp = [](conts std::pair<std::string, int>& a, conts std::pair<std::string, int>& b){
    if(a.second == b.second) return a.second < b.second;
        else return a.first > b.first;
}
std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(comp)> pq(comp);
```