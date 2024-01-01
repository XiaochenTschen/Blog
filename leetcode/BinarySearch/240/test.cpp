/*
Description: Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
             This matrix has the following properties:
             1. Integers in each row are sorted in ascending from left to right.
             2. Integers in each column are sorted in ascending from top to bottom.
*/

#include<vector>
#include<iostream>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row = matrix.size(), clo = matrix[0].size();
        for(auto& arr:matrix)
        {
            if(arr[0] <= target && arr[clo-1] >= target)
            {
                if(binarySearch(arr, target, clo))  return true;
            }
        }
        return false;
    }
private:
    bool binarySearch(const std::vector<int>& arr, const int& target, const int& len)
    {
        int l = 0, r = len - 1, mid = 0;
        while(l < r)
        {
            mid = l + (r-l)/2;
            if(arr[mid] == target)   return true;
            else if(arr[mid] > target)  r = mid - 1;
            else    l = mid + 1;
        }
        return arr[l] == target;
    }
};