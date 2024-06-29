// 给定一个二叉树，判断它是否是 
// 平衡二叉树
  
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


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int ans = balanced(root);
        return ans <= 1? true: false;
    }

    int balanced(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int l = balanced(root->left);
        int r = balanced(root->right);
        return l - r > 0? l - r + 1 : r - l + 1;
    }
};