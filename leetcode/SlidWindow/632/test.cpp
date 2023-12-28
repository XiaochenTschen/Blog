/*
Find K Closest Elements
Description: Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
             The result should also be sorted in ascending order.
             An integer a is closer to x than an integer b if:
                |a - x| < |b - x|, or
                |a - x| == |b - x| and a < b
*/


#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        unsigned int distance = 0;
        std::unordered_map<unsigned int, size_t> u_m;
        for(size_t i = 0; i < k; i++)
        {
            distance += abs(x - arr[i]);
        }
        u_m[distance] = 0;
        unsigned int min_distance = distance;
        for(size_t l = 1, r = k; r < arr.size(); l++, r++)
        {
            distance = distance - abs(arr[l-1] - x) + abs(arr[r] - x);
            min_distance = std::min(distance, min_distance);
            if(u_m.find(distance) == u_m.end())
                u_m[distance] = l;
        }

        return std::vector<int>(arr.begin()+u_m[min_distance], arr.begin()+u_m[min_distance]+k);
    }
};

int main()
{
    Solution sol;
    std::vector<int> arr{1,2,3,4,5};
    int k = 4, x = 3;
    std::vector<int> ans = sol.findClosestElements(arr, k, x);

    std::cout << "ans: ";
    for(int ele:ans)
    {
        std::cout << ele << ",";
    }
    return 0;
}