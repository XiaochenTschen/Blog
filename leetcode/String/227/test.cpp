/*
Basic Calculator II
Description: Given a string s which represents an expression, evaluate this expression and return its value. 
*/

#include<string>
#include<stack>
#include<iostream>


class Solution
{
public:
    int calculate(std::string s)
    {
        if(s.empty())   return 0;

        std::stack<int> num_stack;

        char sign = '+';
        int tmp = 0;
        int ans = 0;

        for(int i = 0; i < s.length(); ++i)
        {
            if(std::isdigit(s[i]))
            {
                tmp += tmp*10 + s[i] - '0';
            }
            if(!(std::isdigit(s[i])) || i == s.length() - 1)
            {
                if(sign == '+')
                {
                    num_stack.push(tmp);
                }
                else if(sign == '-')
                {
                    num_stack.push(-tmp);
                }
                else{
                    int num = num_stack.top();
                    if(sign == '*') num *= tmp;
                    else    num /= tmp;
                    num_stack.pop();
                    num_stack.push(num);
                }
                sign = s[i];
                tmp = 0;
            }
        }
        while(!num_stack.empty())
        {
            ans += num_stack.top();
            num_stack.pop();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::string s{"3+2*2*4/6-8"};
    int ans = sol.calculate(s);
    int compare = 3+2*2*4/6-8;
    std::cout << "ans: " << ans << '\n';
    std::cout << "compare: " << compare << '\n';

    return 0;
}