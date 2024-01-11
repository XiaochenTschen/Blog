#include<string>
#include<vector>
#include<iostream>
#include<queue>

struct Compare
{
    bool operator()(const std::string& a, const std::string& b)
    {
        return a+b < b+a;
    }
};

class Solution
{
public:
    std::string largestNumber(std::vector<int>& nums)
    {
        if(nums.empty())    return "";
        std::priority_queue<std::string, std::vector<std::string>, Compare> pq;
        for(int num:nums)
        {
            pq.push(std::to_string(num));
        }
        std::string ans;
        while(!pq.empty() && pq.top() == "0")
        {
            pq.pop();
        }
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans.empty()?"0":ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{3,30,34,5,9};
    std::string ans = sol.largestNumber(nums);

    std::cout << "ans: " << ans << '\n';
    std::cout << "43243 < 432: " << ("43243" < "432") << '\n';
    std::cout << "43203 < 432: " << ("43203" < "432") << '\n';
    std::cout << "44 < 432: " << ("44" < "432") << '\n';

    return 0;
}