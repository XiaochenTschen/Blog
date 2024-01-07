/*
Find K Pairs with Smallest Sums
Description: You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
             Define a pair (u, v) which consists of one element from the first array and one element from the second array.
             Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
*/

#include<vector>
#include<queue>
#include<iostream>

class Solution
{
public:
/* this method has time limit problem */
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::priority_queue<std::pair<int, std::vector<int>>> pq;
        std::vector<std::vector<int>> ans;
        int count = 0;
        for(int i = 0; i < nums1.size(); ++i)
        {
            for(int j = 0; j < nums2.size(); ++j)
            {
                if(count++ < k)
                {
                    pq.push({nums1[i]+nums2[j], {nums1[i], nums2[j]}});
                }
                else
                {
                    int sum = nums1[i]+nums2[j];
                    if(sum < pq.top().first)
                    {
                        pq.pop();
                        pq.push({sum, {nums1[i], nums2[j]}});
                    }
                }
            }
        }
        for(int j = 0; j < k; ++j)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    std::vector<std::vector<int>> kSmallestPairs1(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        auto comp = [](const std::pair<int, std::pair<int,int>>& a, const std::pair<int, std::pair<int,int>>& b) {
            return a.first > b.first; 
        };

        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,  decltype(comp)> pq(comp);
        std::vector<std::vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size(), add_sum = 0;
        for(int i = 0; i < n1; ++i)
        {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        while(!pq.empty() && ans.size() < k)
        {
            int idx1 = pq.top().second.first, idx2 = pq.top().second.second;
            ans.push_back({nums1[idx1], nums2[idx2]});
            pq.pop();

            if(++idx2 < n2) /* if not, the next small sum is nums1[x]+nums2[0], which is already in pq, or replaced with other small values */
            {
                pq.push({nums1[idx1] + nums2[idx2], {idx1, idx2}});
            }
        }

        return ans;
    }
};