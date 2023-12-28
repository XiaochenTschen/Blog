/*
Maximum Length of Repeated Subarray
Description: Given two integer arrays nums1 and nums2,
             return the maximum length of a subarray that appears in both arrays.
*/

#include<vector>
#include<iostream>

class Solution
{
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int ans = 0;
        int l = 0;
        while(l < nums1.size())
        {
            for(int i = 0; i < nums2.size(); ++i)
            {
                if(nums1[l] == nums2[i])
                {
                    int local_ans = findSubArray(nums1, l, i, nums2);
                    ans = std::max(ans,local_ans);
                }
            }
            ++l;
        }
        return ans;
    }

    int findSubArray(std::vector<int>& nums1, int l1, int l2, std::vector<int>& nums2)
    {
        int ans = 0;
        while(l1 < nums1.size() && l2 < nums2.size())
        {
            if(nums1[l1] == nums2[l2])  
            {
                 ++ans;
                 ++l1;
                 ++l2;
            }  
            else 
                return ans;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums1{0,0,0,0,0};
    std::vector<int> nums2{0,0,0,0,0};
    int ans = sol.findLength(nums1, nums2);
    std::cout << "ans: " << ans;
    return 0;
}