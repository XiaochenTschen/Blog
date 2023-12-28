/*
Subarray Product Less Than K
Description: Given an array of integers nums and an integer k,
             return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
*/

#include<vector>
#include<iostream>

class Solution
{
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        int l = 0, r = 0, ans = 0, len = nums.size();
        int local_product = 1;
        while(r < len)
        {
            local_product *= nums[r];
            while(local_product >= k)
            {
                local_product /= nums[l];
                ++l;
            }
            ans += r-l+1;
            ++r;           
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{1,2,3};
    int k = 0;
    int ans = sol.numSubarrayProductLessThanK(nums, k);

    std::cout << "ans: " << ans;

    return 0;
}
