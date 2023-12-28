/*
Sliding Window Maximum
Description: You are given an array of integers nums,
             there is a sliding window of size k which is moving from the very left of the array to the very right.
              You can only see the k numbers in the window.
              Each time the sliding window moves right by one position.
              Return the maximum element of each window
*/

#include<vector>
#include<iostream>
#include<map>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> ans;
        std::map<int, int> m;
        if(k > nums.size()) return ans;
        for(int i = 0; i < k; ++i)
        {
            ++m[(nums[i])];
        }
        ans.push_back((*m.rbegin()).first);
        for(int i = k; i < nums.size(); i++)
        {
            if(--m[nums[i-k]] == 0)
                m.erase(nums[i-k]);
            ++m[nums[i]];
            ans.push_back((*m.rbegin()).first);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{-7,-8,7,5,7,1,6,0};
    int k = 4;
    std::vector<int> ans = sol.maxSlidingWindow(nums, k);
    std::cout << "ans: ";
    for(int ele:ans)
    {
        std::cout << ele << ",";
    }
     return 0;
}