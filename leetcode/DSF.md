## Depth-first search
深度优先搜索，简单理解就是，我有一堆需要搜索的节点数据，当我搜索到一个符合标准的节点时，就从这个节点开始继续进行遍历。
从算法描述上来看，我们需要一个先入后出的栈来存储信息实现算法。当然也可以通过和栈等价的递归算法来实现。
有时候也可以对已经搜索过的节点进行标记，以防止在搜索过程中重复搜索某个节点，这种方法就是**状态记录**或**记忆化memoization**.

对于深度优先搜索来说，算法可以分为主函数和辅函数:
1. 主函数：主函数用来遍历所有的搜索位置，判断是否可以开始搜索，如果可以便调用辅函数进行搜索。
2. 辅函数：主要负责深度优先的递归调用

### Leetcode 695. Max Area of Island
给定一个二维的0-1 矩阵，其中0 表示海洋，1 表示陆地。单独的或相邻的陆地可以形成岛屿，每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。

首先利用栈数据结构来实现算法。
```c
vector<int> direction{-1, 0, 1, 0, -1};
int maxAreaOfIsland(vector<vector<int>>& grid){
    int m = grid.size(), n = m? grid[0].size() : 0, local_area, area = 0, x, y;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]){
                local_area = 1;
                grid[i][j] = 0;
                stack<pair<int, int>> island;
                island.push({i, j});
                while(!island.empty()){
                    auto [r c] = island.top();
                    island.pop();
                    for(int k = 0; k < 4; ++k>){
                        x = r + direction[k], y = c + direction[k+1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                            grid[x][y] = 0;
                            ++local_area;
                            island.push({x,y});
                        }
                    }
                }
                area = max(area, local_area);
            }
        }
    }
    return area;
}
```
在这个算法里面，采用的状态记录的方法是，如果我们已经搜索过某个位置了，就把这个位置设置为0，这样在下一次搜索的时候直接跳过该位置。
另外用到的direction容器也是一个小技巧。

利用递归调用的实现算法如下：
```c
vector<int> direction{-1, 0, 1, 0, -1};
int maxAreaOfIsland(vector<vector<int>>& grid){
    if(grid.empty() || grid[0].empty()) return 0;
    int area;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(), j++){
            if(gird[i][j]){
                area = std::max(area, dfs(grid, i, j))
            }
        }
    }
    return area;
}

int dfs(vector<vector<int>>& grid, int r, int c){
    if(grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    int x, y, area = 1;
    for(int i = 0; i < 4; i ++){
        x = r + direction[i], y = c + direction[i+1];
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()){
            area += dfs(grid, x, y);
        }
    }
    return area;
}
```