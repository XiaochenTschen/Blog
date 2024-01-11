#include<string>
#include<iostream>
#include<vector>

class Solution
{
public:
    int countBinarySubstrings(std::string s) {
        int count1 = 0, ans = 0, count2 = 0;
        int l = 0, r = 0;
        bool changed = false;
        while(r < s.length())
        {
            while(s[r] == s[l] && r < s.length())
            {
                ++r;
                ++count1;
            }
            while(s[r] != s[l] && r < s.length())
            {
                ++r;
                ++count2;
            }
            ans += std::min(count1, count2);
            l = l + count1;
            r = l;
            count1 = count2 = 0;
        }
       
        return ans;
    }
};

int main()
{
    Solution sol;
    std::string s {"00110011"};
    int ans = sol.countBinarySubstrings(s);
    
    std::cout << "ans: " << ans << '\n';

    return 0;
}