/*
Find All Anagrams in a String

Description: Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
             You may return the answer in any order.

             An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

class Solution
{
public:
    std::vector<int> findAnagrams(std::string& s, std::string& p) 
    {
        std::vector<int> ans;
        if(s.length() < p.length()) return ans;
        for(int l = 0; l <= s.length() - p.length(); l++)
        {
            if(isAnagrams(s.substr(l, p.length()), p))
            {
                ans.push_back(l);
            }
        }
        return ans;
    }

    bool isAnagrams(const std::string& sub_s, const std::string& p)
    {
        std::unordered_map<char, int> u_m;
        for(int i = 0; i < sub_s.length(); i++)
        {
            u_m[sub_s[i]]++;
        }
        for(int i = 0; i < p.length(); i++)
        {
            if(--u_m[p[i]] < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::string s = "baa", p = "aaaaaa";
    std::vector<int> ans = sol.findAnagrams(s, p);

    std::cout << "ans: ";
    for(auto ele:ans)
    {
        std::cout << ele;
    }

    return 0;
}