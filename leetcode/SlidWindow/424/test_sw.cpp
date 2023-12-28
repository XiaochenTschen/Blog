#include<string>
#include<iostream>
#include<unordered_map>

class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {
        std::unordered_map<char, int> u_m;
        int l = 0, r = 0;
        int max_count = 0;
        int ans  = 0;
       for(; r < s.length(); r++)
       {
            ++u_m[s[r]];
            max_count = std::max(max_count, u_m[s[r]]);
            while(r-l+1 - max_count > k)
            {
                --u_m[s[l]];
                l++;
            }

            ans = std::max(ans, r-l+1);
       }

       return ans;

    }
};

int main()
{
    Solution sol;
    std::string test_s{"BABB"};
    int k = 0;

    int res = sol.characterReplacement(test_s, k);

    std::cout << "res: " << res;

    return 0;
}