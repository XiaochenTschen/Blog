二分查找最基础的应用，是在一个已排序的数据结构中，查看某个元素是否存在。根据这个最基础的思想，在实际应用中会有很多不同的变种。

#### 找到某一个target
在一个排序好的数据序列中查找某一个target，如果存在的话，可以返回该元素的位置下标，不存在的话返回-1.
```c++
int findEle(std::vector<int>& arr, int tar)
{
    int l = 0, r = arr.size() - 1; /* left and right boundary are closed */
    int mid = 0;
    while(l <= r) /* euqal position should be also checked */
    {
        mid = l + (r - l)/2;
        if(arr[mid] == tar) return mid;
        else if(arr[mid] < tar) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```

#### 找到某一个target的左边界
给定一个排序好的数据序列和一个target，在序列中找到target第一次出现的位置，当target不存在的时候找到target在序列中的左边界(即第一个大于等于tar的元素).
```c++
int findLeftBoundary(std::vector<int>& arr, int tar)
{
    int l = 0, r = arr.size() - 1;
    int mid = 0;
    while(l <= r)
    {
        mid = l + (r-l)/2;
        if(arr[mid] >= tar) r = mid - 1;
        else l = mid + 1;
    }
    return l < arr.size()?l:-1; /* if tar bigger than all elements, l == arr.size() which is not allowed */
}
```
#### 找到某一个target的右边界
给定一个排序好的数据序列和一个target，在序列中找到target最后一次出现的位置
```c++
int findRightBoundary(std::vector<int>& arr, int tar)
{
    int l = 0, r = arr.size() - 1;
    int mid = 0;
    while(l <= r)
    {
        mid = l + (r-l+1)/2; /* this means l moves to r */
        if(arr[mid] > tar) r = mid - 1;
        else l = mid + 1;
    }
    return r >= 0?r:-1;
}
```
#### 找到某一个最合适的区间
给定一个排序好的数据序列和一个target,在序列中找到连续k个元素的子序列，使得子序列的元素到target的距离最短。
```c++
std::vector<int> findCloestElements(std::vector<int>& arr, int k, int target)
{
    /* initialize the start point of the window */
    int l = 0, r = arr.size() - k;
    while(l < r)
    {
        int mid = l + (r - l)/2;
        /* 
        this is the same logic as sliding window
        arr[mid] is the starting point of sliding window, arr[mid+k] is the point on the right of the window
        so if target is closer to the right one, move the sliding window to the right
        otherweise the starting point is one of the potentional solution, thus r = mid
         */
        if(target - arr[mid] > arr[mid + k] - target)   l = mid + 1;/* this is the same logic as sliding window */
        else r = mid;
    }
    return std::vector<int>(arr.begin() + l, arr.begin() + l + k);
}
```

#### 需要注意的问题
在一些算法中，会面临左边界或者右边界需要等于mid，或者是mid-1还是mid+1。这些操作的区别在于，mid是不是潜在的解，如果是的话，就不能进行加减操作，而是直接将其赋值给新的左边界或者右边界；反之就要加减1后赋值给新的边界。