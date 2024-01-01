#include<vector>
#include<iostream>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row = matrix.size(), clo = row?matrix[0].size():0;
        int i = 0, j = clo - 1;
        while(i < row && j >= 0)
        {
            if(matrix[i][j] > target)
                --j;
            else if(matrix[i][j] < target)
                ++i;
            else
                return true;
        }
        return false;
    }
};