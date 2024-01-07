/*
Relative Ranks
*/

#include<vector>
#include<map>
#include<queue>

class Solution
{
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::map<int,int, std::greater<int>> m;
        std::vector<std::string> ans(score.size(), "");
        for(int i = 0; i < score.size(); ++i)
        {
            m.insert({score[i], i});
        }
        
        int j = 0;
        for(auto ele:m)
        {
            ++j;
            if(j == 1)
            {
                ans[ele.second] = "Gold Medal";
            }
            else if(j == 2)
            {
                ans[ele.second] = "Silver Medal";
            }
            else if(j == 3)
            {
                ans[ele.second] = "Bronze Medal";
            }
            else
            {
                ans[ele.second] = std::to_string(j);
            }
        }
        return ans;
    }

    std::vector<std::string> findRelativeRanks1(std::vector<int>& score) {
        std::priority_queue<std::pair<int, int>> pq;
        std::vector<std::string> ans(score.size(), "");
        for(int i = 0; i < score.size(); ++i)
        {
            pq.push({score[i], i});
        }
        for(int j = 1; j <= score.size(); ++j)
        {
            int idx = pq.top().second;
            if(j == 1)
            {
                ans[idx] = "Gold Medal";
            }
            else if(j == 2)
            {
                ans[idx] = "Silver Medal";
            }
            else if(j == 3)
            {
                ans[idx] = "Bronze Medal";
            }
            else
            {
                ans[idx] = std::to_string(j);
            }
            pq.pop();
        }
        return ans;
    }
};