#include<string>
#include<iostream>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::string ans;
        int count = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            std::string word;
            if(s[i] == ' ') continue;
            while(i < s.length() && s[i] != ' ')
            {
                word += s[i];
                ++i;
            }
            if(ans.empty())   ans += word;
            else ans = word + " " + ans;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::string s{"the sky is blue"};
    std::string ans = sol.reverseWords(s);

    std::cout << ans <<'\n';

    return 0;
}