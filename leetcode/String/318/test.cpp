#include<string>
#include<vector>
#include<iostream>

class Solution
{
public:
    int maxProduct(std::vector<std::string>& words)
    {
        int ans = 0;
        int len = words.size();
        for(int i = 0; i < len; ++i)
        {
            int len1 = words[i].length();
            for(int j = i+1; j < len; ++j)
            {
                if(!hasCommenLetter(words[i], words[j]))
                {
                    int len2 = words[j].length();
                    ans = std::max(ans, len1*len2);
                }
            }
        }
        return ans;

    }
private:
    bool hasCommenLetter(std::string& a, std::string& b)
    {
        unsigned int a_i = 0, b_i = 0;
        for(char c:a)
        {
            a_i |= 1u << (c-'a');
        }
        for(char c:b)
        {
            b_i |= 1u << (c-'a');
        }
        return (a_i&b_i) > 0;
    }

};

int main()
{
    Solution sol;
    std::vector<std::string> words{"abcw","baz","foo","bar","xtfn","abcdef"};
    int ans = sol.maxProduct(words);

    std::cout << "ans: " << ans << '\n';

    return 0;
}