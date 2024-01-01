/*
Kth Smallest Number in Multiplication Table
Description: The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).
             Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.
*/

#include<vector>
#include<iostream>
#include<queue>

class Solution
{
public:
/* this method has time limit problem if m and n are big */
    int findKthNumber(int m, int n, int k) {
        std::priority_queue<int> m_h;
        int count = 1;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(count <= k)
                {
                    m_h.push(i*j);
                    ++count;
                }
                else
                {
                    int k = m_h.top();
                    if(k > i*j)
                    {
                        m_h.pop();
                        m_h.push(i*j);
                    }
                }
            }
        }
        return m_h.top();
    }

    /* improvement with binary search */
    int findKthNumber1(int m, int n, int k){
        long l = 1, r = m*n, mid = 0;
        while(l<r)
        {
            mid = l + (r-l)/2;
            if(count(m,n,mid) >= k) r = mid;
            else l = mid + 1;
        }
        return (int)l;
    }
private:
    int count(int m, int n, int x)
    {
        int ans = 0;
        for(int i = 1; i <=m; ++i)
        {
            ans += std::min(x/i, n);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int m = 3, n = 3, k = 5;
    int ans = sol.findKthNumber1(m,n,k);
    std::cout << "ans: " << ans << std::endl;

    return 0;
}