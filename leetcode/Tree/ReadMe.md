### 树的前中后序遍历
前中后是相对于root节点来说的

#### 前序遍历
根节点->左子树->右子树
```c++
void preorder(TreeNode* root) {
    if(!root) return;
    /*do some thing with node*/
    std::cout << root->val << '\n';
    preorder(root->left);
    preorder(root->right);
}
```

#### 中序遍历
左节点->根节点->右子树
```c++
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    /*do some thing with node*/
    std::cout << root->val << '\n';
    inorder(root->right);
}
```

#### 前序遍历
左子树->右子树->根节点
```c++
void postorder(TreeNode* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    /*do some thing with node*/
    std::cout << root->val << '\n';
}
```

### 树的层序遍历
树的层序遍历是一种广度优先的算法，可以借助queue来实现。
```c++
void levelTraverse(TreeNode* root) {
    if(!root) return;
    std::queue<TreeNode*> q_node;
    q_node.push(root);
    while(!q_node.empty()) {
        int q_len = q_node.size();
        for(int i = 0; i < q_len; ++i) {
            TreeNode* tmp = q_node.front();
            q_node.pop();
            std::cout << tmp->val << '\n';
            if(tmp->left) q_node.push(tmp->left);
            if(tmp->right) q_node.push(tmp->right);
        } 
    }
}
```
____

### 常见题型

根据树的特性，利用递归解决树相关的问题是最常用的选择。

**根节点到叶子节点最长路径**
```c++
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}
```

**寻找两个节点的最低公共祖先**
寻找公共祖先，题解分为两种情况：两个节点分别位于某节点的左右子树；两个节点互为父子关系(并不一定直接连接)

1. 如果树中的节点有指向父节点的指针，那么这个问题就可以转化成两条链表的交点问题
2. 如果树是二叉查找树，可以利用二叉查找树的特性来解决问题
```c++ 
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val > p->val && root->val > q->val) {
        lca(root->left, p, q);
    else if(root->val < p->val && root->val < q->val)
        lca(root->left, p, q);
    else
        return root;
    }
}
```
3. 如果树是普通的二叉树，可以使用从根节点开始递归的方法解决，也可以利用哈希表来存储子节点和父节点的对应关系来辅助解决
```c++ 
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q)
        return root;
    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);
    if(left && right) /*one in left tree and other in right tree*/
        return root;
    return left ? left : right; /*both on same side*/
}

TreeNode* lca_hash(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return nullptr;
    std::unordered_map<TreeNode*, TreeNode*> parent;
    std::unordered_set<TreeNode*> p_node;
    std::queue<TreeNode*> q_hash;
    q_hash.push(root);
    while(!q_hash.empty()) {
        TreeNode* par = q_hash.front();
        q_hash.pop();
        if(par->left) {
            parent[par->left] = par;
            q_hash.push(par->left);
        }
        if(par->right) {
            parent[par->right] = par;
            q_hash.push(par->right);
        }
        if(parent.find(p) != parent.end() && parent.find(q) != parent.end())
            break;
    }
    TreeNode* cur = p;
    p_node.insert(p);
    while(cur != root) {
        p_node.insert(parent[cur]);
        cur = parent[cur];
    }
    cur = q;
    while(!p_node.count(cur)) {
        cur = parent[cur];
    }
    return cur;
}
```

**根据两种遍历的结果恢复树的结构**
Leetcode 105, 106, 889