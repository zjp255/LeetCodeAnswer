// 给你一个二叉树的根节点 root ， 检查它是否轴对称。
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
 //3ms 75% 16.94MB 68.27%
class Solution {
public:
      bool check(TreeNode* left ,TreeNode* right)
    {
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        return left->val == right->val && check(left->left,right->right) && check(left->right, right->left); 
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};