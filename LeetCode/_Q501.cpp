// 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

// 如果树中有不止一个众数，可以按 任意顺序 返回。

// 假定 BST 满足如下定义：

// 结点左子树中所含节点的值 小于等于 当前节点的值
// 结点右子树中所含节点的值 大于等于 当前节点的值
// 左子树和右子树都是二叉搜索树

#include<iostream>
#include<vector>
#include <unordered_map>

#include <queue>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//15ms 58.32% 22.02MB 39.89%
class Solution {
public:
    vector<int> answer;
    int base, count, maxCount;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return answer;
    }

    void dfs(TreeNode* root)
    {
        if(root == nullptr)
            return;
        dfs(root->left);
        if(root->val == base)
        {
            count++;
        }else{
            base = root->val;
            count = 1;
        }
        if(count == maxCount)
        {
            answer.push_back(base);
        }
        if(count > maxCount)
        {
            answer = vector<int>{base};
            maxCount = count;
        }
        dfs(root->right);
    }
};