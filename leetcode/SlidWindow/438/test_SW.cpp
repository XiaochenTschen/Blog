#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

class Solution
{
public:
    std::vector<int> findAnagrams(std::string& s, std::string& p) 
    {
        std::unordered_map<char, int> s_count;
        std::unordered_map<char, int> p_count;

        std::vector<int> ans;
        if(s.length() < p.length())  return ans;

        for(char c:p)   ++p_count[c];
        for(int i = 0; i < p.length(); i++) ++s_count[s[i]];
        if(s_count == p_count)  ans.push_back(0);

        for(int i = p.length(); i < s.length(); i++)
        {
            ++s_count[s[i]];
            --s_count[s[i-p.length()]];
            if(s_count[s[i-p.length()]] == 0) s_count.erase(s[i-p.length()]);
            if(s_count == p_count)  ans.push_back(i-p.length()+1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::string s = "abaabaabba", p = "ab";
    std::vector<int> ans = sol.findAnagrams(s, p);

    std::cout << "ans: ";
    for(auto ele:ans)
    {
        std::cout << ele;
    }

    return 0;
}