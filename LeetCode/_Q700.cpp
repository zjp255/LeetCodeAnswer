// 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

// 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
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
//31ms 71.04% 32.33MB 81.62%
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root->val == val)
            return root;
        else if(root->val > val){
            if(!root->left)
                return NULL;
            return searchBST(root->left, val);
        }
        else{
            if(!root->right)
                return NULL;
            return searchBST(root->right, val);
        }
    }
};