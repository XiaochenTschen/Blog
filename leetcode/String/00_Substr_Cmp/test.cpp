/*
Description: give string s and string t, if s contains all characters of t, then return true.
*/

#include<string>
#include<unordered_map>

class Solution
{
    /*
    This method is easy to understand.
    Drawbacks:
        1. anohter hash map um_s
        2. if s is lang and t is at the beginning, it is not efficient to use um_s
    */
    bool substrCmp(std::string& s, std::string& t)
    {
        std::unordered_map<char, int> um_t;
        std::unordered_map<char, int> um_s;
        for(char c:t) ++um_t[c];
        for(char c:s) ++um_s[c];
        for(char c:t)
        {
            if(um_s.find(c) == um_s.end() || um_s[c] != um_t[c])
            {
                return false;
            }
        }
        return true;
    }

    /*
    In this method, a record value, varified, is used to save the comparation information.
    If one character is varified in s, varified will be added 1(If this character is already varified and comes again in s, varified will not be changed)
    Once all characters are varified, true will be returned.
    */
    bool substrCmp1(std::string& s, std::string& t)
    {
        std::unordered_map<char, int> um_t;
        int varified = 0;
        for(char c:t) ++um_t[c];
        for(char c:s)
        {
            if(um_t.find(c) != um_t.end() && --um_t[c] >= 0)
            {
                ++varified;
            }
            if(varified == t.length())
            {
                return true;
            }
        }
        return false;
    }
};