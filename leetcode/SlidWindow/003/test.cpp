/*
Longest Substring Without Repeating Characters
Description: 
    Given a string s, find the length of the longest substring without repeating characters.
*/

#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>

class Solution
{
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_set<char> u_s;
        size_t ans = 0;
        if(s.length() == 0) return ans;
        size_t l = 0, r =0;
        while( r < s.size())
        {
            if(u_s.find(s[r]) == u_s.end())
            {
                u_s.insert(s[r]);
                ans = std::max(ans, r-l+1);
                ++r; 
            }
            else
            {
                u_s.erase(s[l]);
                ++l;
            }
        }
        return static_cast<int>(ans);
    }
};

int main()
{
    Solution sol;
    std::string test{"abcabcbb"};
    int ans = sol.lengthOfLongestSubstring(test);
    std::cout << "ans: " << ans << std::endl;
    return 0;
}