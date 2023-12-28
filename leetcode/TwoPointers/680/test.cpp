/*
Valid Palindrome
Description: Given a string s, 
             return true if the s can be palindrome after deleting at most one character from it.
*/

#include<string>
#include<iostream>

class Solution
{
public:
    bool validPalindrome(std::string& s) {
        bool changed = false;
        int l = 0, r = s.length() - 1;
        while(l < r)
        {
            if(s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                if(isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1))
                    return true;
                else
                    return false;
            }
        }
        return true;
    }

private:
    bool isPalindrome(std::string&s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] == s[r])
            {
                r--;
                l++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::string test{"aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"};

    bool res = sol.validPalindrome(test);

    std::cout << "res: " << res;

    return 0;
}