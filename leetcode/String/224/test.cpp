#include<string>
#include<stack>
#include<iostream>
#include<stdlib.h>

class Solution
{
public:
    int calculate(std::string s)
    {
        int isPositiv = 1;
        int num = 0;
        int ans = 0;
        std::stack<int> op({1});

        for(char c:s)
        {
            if(std::isdigit(c))
            {
                num = num*10 + (c-'0');
            }
            else
            {
                ans += num*isPositiv*op.top();
                num = 0;
                if(c == '+') isPositiv = 1;
                if(c== '-') isPositiv = -1;
                if(c == '(')
                {
                    op.push(op.top()*isPositiv);
                    isPositiv = 1;
                }
                if(c == ')')    op.pop();
            }
        }
        ans += num*isPositiv*op.top();
        return ans;
    }

    int calculate1(std::string s)
    {
        char sign = '+';
        if(s[0] == '-')  s = '0' + s;
        int len = s.length();
        std::stack<int> stk;
        for(int i = 0; i < s.length(); ++i)
        {
            int num = 0;
            while( i < len && std::isdigit(s[i]))
            {
                num = 10*num + (s[i]-'0');
                ++i;
            } 

            if(sign == '+')
            {
                stk.push(num);
            }
            if(sign == '-' )
            {
                stk.push(-num);
            }

            if(i < len && s[i] == ' ') continue;
            if(i < len && s[i] == '+') sign = '+';
            if(i < len && s[i] == '-') sign = '-';
            if(i < len && s[i] == '(')
            {
                int bracket = 1;
                int j = i;
                while(bracket != 0)
                {
                    ++j;
                    if(s[j] == '(') ++bracket;
                    if(s[j] == ')') --bracket;
                }
                if(sign == '+')
                    stk.push(this->calculate(s.substr(i+1, j-i-1)));
                else
                    stk.push(-(this->calculate(s.substr(i+1, j-i-1))));
                i = j;
            }
        }

        int ans = 0;
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    std::string s{"1-(     -2)"};
    int ans = sol.calculate(s);

    std::cout << "ans: " << ans << '\n';

    return 0;
}