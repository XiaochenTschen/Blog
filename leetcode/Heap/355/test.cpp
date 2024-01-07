#include<map>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<queue>

class Twitter
{
private:
    /* map to manage the follow information: key==follower, value==list of followee*/
    std::unordered_map<int, std::unordered_set<int>> follow_m;
    //std::unordered_map<int, std::vector<int>> user_tweet;
    std::unordered_map<int, std::vector<long long>> user_time;
    std::unordered_map<long long, int> time_tweet; 
    long long time_stmple;
public:
    Twitter()
    {
        time_stmple = 0;
    }

    void postTweet(int userID, int tweetID)
    {
        ++time_stmple;
        user_time[userID].push_back(time_stmple);
        time_tweet[time_stmple] = tweetID;
    }

    std::vector<int> getNewsFeed(int userId)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        std::vector<int> ans;
        int i = 0;
        for(auto t:user_time[userId])
        {
            ++i;
            min_heap.push(t);
            if(i > 10)
            {
               min_heap.pop();
            }
        }
        for(auto followee:follow_m[userId])
        {
            for(auto t:user_time[followee])
            {
                ++i;
                min_heap.push(t);
                if(i > 10)
                {
                min_heap.pop();
                }
            }
        }
        while(!min_heap.empty())
        {
            ans.push_back(time_tweet[min_heap.top()]);
            min_heap.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        follow_m[followerId].insert(followeeId);  
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_m[followerId].erase(followeeId);
    }
};