/*
Permutation in String
Description: Given two strings s1 and s2,
             return true if s2 contains a permutation of s1,
             or false otherwise.
             In other words, return true if one of s1's permutations is the substring of s2.
*/

#include<string>
#include<unordered_map>
#include<iostream>

class Solution
{
public:
    bool checkInclusion(const std::string& s1, const std::string& s2) {
        if(s1.size() > s2.size())   return false;
        std::unordered_map<char, int> um_s1;
        for(char c:s1) ++um_s1[c];
        int varified = 0;
        int l = 0, r = 0;
        for(; r < s1.size() - 1; ++r)
        {
            char c{s2[r]};
            if(um_s1.find(c) != um_s1.end() && --um_s1[c] >= 0)
            {
                ++varified;
            }
        }
        while(r < s2.size())
        {
            if(um_s1.find(s2[r]) != um_s1.end() && --um_s1[s2[r]] >= 0)
            {
                ++varified;
            }

            if(varified == s1.size())   return true;

            if(um_s1.find(s2[l]) != um_s1.end() &&  ++um_s1[s2[l]] > 0)
            {
                --varified;
            }

            ++l;
            ++r;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    std::string s1{"abc"};
    std::string s2{"bbbca"};
    bool ans = sol.checkInclusion(s1, s2);
    
    std::cout << "ans: " << ans;

    return 0;
}
