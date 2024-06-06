// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

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
//0ms 100% 9.53MB 91.31%
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
            return;
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }
};