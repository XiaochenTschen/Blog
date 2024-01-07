#include<queue>
#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>


class Solution
{
public:
    std::string reorganizeString(std::string& s) {
        int len = s.length();
        std::string ans(len, ' ');
        std::unordered_map<char, int> um;
        for(char c:s)
            ++um[c];
        
        auto comp = [](std::pair<char, int>&a, std::pair<char, int>&b){
            return a.second < b.second;
        };

        std::priority_queue<std::pair<char,int>,std::vector<std::pair<char,int>>, decltype(comp)> pq(comp);

        for(auto ele:um)
            pq.push(ele);

        int loop_2 = 0, idx = 0;
        while(!pq.empty())
        {
            auto ele = pq.top();
            while(ele.second > 0)
            {
                int new_idx = 2*idx+loop_2;
                if(new_idx < len)
                {
                    ans[new_idx] = ele.first;
                    if(loop_2 == 1 && ans[new_idx] == ans[new_idx-1])   return "";
                    --ele.second;
                    ++idx;
                }
                else
                {
                    loop_2 = 1;
                    idx = 0;
                }
            }
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::string s{"aabbc"};
    std::string ans = sol.reorganizeString(s);

    std::cout << "ans: " << ans << '\n';

    return 0;
}