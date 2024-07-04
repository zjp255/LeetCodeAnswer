// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

// 叶子节点 是指没有子节点的节点。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//5ms 90.35% 19.4MB 22.76%
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(!root)
            return false;
        targetSum -= root->val;
        if(targetSum == 0 && !root->left && !root->right)
            return true;
        bool left = hasPathSum(root->left, targetSum);
        bool right = hasPathSum(root->right, targetSum);
        if(left || right)
            return true;
        else
            return false;
    }

    
};