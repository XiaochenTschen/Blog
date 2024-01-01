#include<iostream>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size() - k;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
}

};

int main()
{
    Solution sol;
    std::vector<int> arr{0,0,0,1,3,5,6,7,8,8};
    int k = 2, x = 2;
    std::vector<int> ans = sol.findClosestElements(arr, k, x);
    std::cout << "ans: ";
    for(int ele:ans)
    {
        std::cout << ele << ", ";
    }

    return 0;
}
