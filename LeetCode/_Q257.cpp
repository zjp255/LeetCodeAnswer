// 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

// 叶子节点 是指没有子节点的节点。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
//3ms 66% 16.37MB 11.98%
class Solution {
public:
     vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        findPath(root, "");
        return ans;
    }

    void findPath(TreeNode* root, string path)
    {
        if(!root)
            return;
        path += std::to_string(root->val) + "->";
        if(!root->left && !root->right)
        {
            if(path.length() >= 2)
                path.erase(path.length() - 2);
            ans.push_back(path);
        }
        else
        {
            findPath(root->left, path);
            findPath(root->right, path);
        }
    }
};