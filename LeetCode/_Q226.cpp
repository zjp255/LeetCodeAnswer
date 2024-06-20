// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

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
//0ms 100% 11.18% 38.94%
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        reverseRoot(root);
        return root;
    }

    void reverseRoot(TreeNode* root)
    {
        if(root == NULL)
            return;
        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;
        reverseRoot(root->left);
        reverseRoot(root->right);
    }
};