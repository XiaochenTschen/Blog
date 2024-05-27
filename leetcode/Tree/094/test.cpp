#include<optional>
#include<queue>
#include<vector>
#include<iostream>

struct  TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

TreeNode* createTree(const std::vector<std::optional<int>>& arr)
{
    
}
