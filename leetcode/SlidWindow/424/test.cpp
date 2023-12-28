/*
    longest Repeating Charactor Replacement
    Description:
        You are given a string s and an integer k. 
        You can choose any character of the string and change it to any other uppercase English character. 
        You can perform this operation at most k times.
    Goal:
        Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/
#include<string>
#include<iostream>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int ans = 0, local_ans = 0, change = 0;
        for(int i = 0; i < s.length(); i++)
        {
            local_ans = 1;
            change = 0;
            int j = i + 1;
            for(; j < s.length(); j++)
            {
                if(s[j] == s[i])    local_ans += 1;
                else if(change < k)
                {
                    ++change;
                    ++local_ans;
                }
                else
                {
                    break;
                }
            }
            if(j == s.length() && change < k)
                local_ans = std::min(local_ans+k-change, static_cast<int>(s.length()));
            ans = std::max(ans, local_ans); 
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::string test_s{"KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF"};
    int k = 4;

    int res = sol.characterReplacement(test_s, k);

    std::cout << "res: " << res;

    return 0;
}