/*
Minimum Window Substring
Description: Given two strings s and t of lengths m and n respectively,
             return the minimum window substring of s,
             such that every character in t (including duplicates) is included in the window. 
             If there is no such substring, return the empty string "".
*/

#include<string>
#include<unordered_map>
#include<iostream>


class Solution {
public:
    std::string minWindow(const std::string& s, const std::string& t) {
        std::unordered_map<char, int> um_t;
        int min_len = INT_MAX, start = 0;
        int varified = 0;

        for(char c:t)   ++um_t[c];

        int l = 0, r = 0;
        while(r < s.length() && l <= r)
        {
            if(varified == t.length())
            {
                if(min_len > r-l+1)
                {
                    min_len = r-l+1;
                    start = l;
                }
                char c = s[l];
                if(um_t.find(c) != um_t.end() && ++um_t[s[l]] > 0) --varified;
                if(varified < t.length()) ++r;
                ++l;
            }
            else
            {
                char c = s[r];
                if(um_t.find(c) != um_t.end() && --um_t[c] >= 0)
                {
                    ++varified;
                }
                if(varified < t.length()) ++r;
            }
        }
        return min_len < INT_MAX?s.substr(start, min_len):"";
    }
};

int main()
{
    Solution sol;
    std::string s{"a"};
    std::string  t{"b"};
    std::string ans = sol.minWindow(s,t);

    std::cout <<"ans: " <<  ans << std::endl;

    return 0;
}