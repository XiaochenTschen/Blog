/*
Find First and Last Position of Element in Sorted Array
*/

#include<vector>
#include<iostream>

class Solution
{
public:
    std::vector<int> searchRange(const std::vector<int>& arr, const int& target)
    {
        int l = findStarting(arr, target);
        int r = findEnding(arr, target);
        return {l,r};
    }

private:
    int findStarting(const std::vector<int>& arr, const int& target)
    {
        if(arr.size() == 0) return -1;
        int l = 0, r = arr.size() - 1;
        while(l < r) /* without equal,otherwise endless loop*/
        {
            int mid = l + (r - l)/2;
            if(arr[mid] >= target)  r = mid; /* here not mid-1, because mid is a potentional solution*/
            else l = mid + 1;
        }
        return arr[l] == target?l:-1;
    }
    int findEnding(const std::vector<int>& arr, const int& target)
    {
        if(arr.size() == 0) return -1;
        int l = 0, r = arr.size() - 1;
        while(l < r)
        {
            int mid = l + (r - l + 1)/2;
            if(arr[mid] <= target)  l = mid; /* same reason not mid + 1*/
            else r = mid - 1;
        }
        return arr[r] == target?r:-1;
    }
};

int main()
{
    Solution sol;
    std::vector<int> arr{1,2,3};
    int tar = 2;
    std::vector<int> ans = sol.searchRange(arr, tar);
    std::cout << "ans: ";
    for(int ele:ans)
    {
        std::cout << ele << " ";
    }
    return 0;
}