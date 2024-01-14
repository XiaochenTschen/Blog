#include<string>
#include<iostream>

class Solution
{
public:
    std::string shortestPalindrome(std::string s)
    {
        int r = s.length()-1;
        while(!isPalindrome(s.substr(0, r+1)))
        {
            --r;
        }

        std::string tmp;
        for(++r; r < s.length(); ++r)
        {
            tmp = s[r] + tmp;
        }

        return tmp+s;
    }
private:
    bool isPalindrome(const std::string& s)
    {
        int l = 0, r = s.length()-1;
        while(l <=r)
        {
            if(s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::string s{"abcd"};

    std::string ans = sol.shortestPalindrome(s);

    std::cout << "ans: " << ans << '\n';

    return 0;
}