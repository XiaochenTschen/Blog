/*
Top K Frequent Words
*/

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<iostream>

class Compare
{
public:
    bool operator()(const std::pair<std::string,int>& a, std::pair<std::string,int>& b)
    {
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};


class Solution
{
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k){
        std::map<std::string, int> m;
        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string,int>>, Compare> pq;
        std::vector<std::string> ans;
        for(auto ele:words)
        {
            ++m[ele];
        }
        int i = 0;
        for(auto ele:m)
        {
            if(i < k)
            {
                pq.push(ele);
            }
            else
            {
                auto temp = pq.top();
                if(temp.second < ele.second || (temp.second == ele.second && temp.first < ele.first))
                {
                    pq.pop();
                    pq.push(ele);
                }
            }
           ++i;
        }
         while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
    std::vector<std::string> topKFrequent1(std::vector<std::string>& words, int k) {
        std::map<std::string, int> m;
        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> pq;
        std::vector<std::string> ans;

        // 统计每个单词的频率
        for (auto& word : words) {
            ++m[word];
        }

        // 将统计结果放入优先队列
        for (auto& ele : m) {
            pq.push(ele);
            if (pq.size() > k) pq.pop();
        }

        // 从优先队列中提取前 k 个元素
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        // 如果题目要求特定顺序，可能需要对 ans 进行排序
        //std::reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<std::string> word{"i","love","leetcode","i","love","coding"};
    int k = 2;
    std::vector<std::string> ans = sol.topKFrequent1(word,k);

    return 0;
}

