/*
Kth Smallest Element in a Sorted Matrix
*/

#include<vector>
#include<iostream>

class Solution
{
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int row = matrix.size(), clo = row?matrix[0].size():0;
        int lo = matrix[0][0], hi = matrix[row-1][clo-1];
        int ans = -1;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if(countElementLessOrEqual(matrix, mid) >= k)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }

private:
    int countElementLessOrEqual(std::vector<std::vector<int>>& matrix, int x)
    {
        int row = matrix.size(), clo = row?matrix[0].size():0;
        int count = 0;
        int i = 0, j = clo - 1;
        for(; i < row; ++i)
        {
            while(j >= 0 && matrix[i][j] > x)
            {
                --j;
            }
            count += (j+1);
        }
        return count;
    }
};