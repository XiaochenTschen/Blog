/*
Minimum Size Subarray Sum
Description: Given an array of positive integers nums and a positive integer target, 
             return the minimal length of a subarray whose sum is greater than or equal to target. 
             If there is no such subarray, return 0 instead.
*/
#include<vector>
#include<iostream>

class Solution
{
public:
    int minSubArrayLen(const int& target, const std::vector<int>& nums)
    {
        int l = 0, r = 0;
        int window_sum = 0;
        int ans = INT_MAX;
        while(r < nums.size())
        {
            window_sum += nums[r];
            while(window_sum >= target)
            {
                ans = std::min(ans, r-l+1);
                window_sum -= nums[l];
                l++;
            }
            ++r;
        }
        return ans==INT_MAX?0:ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> test{1,8,2,4};
    int target = 7;
    int ans = sol.minSubArrayLen(target, test);
    std::cout << "ans: " << ans;

    return 0;
}