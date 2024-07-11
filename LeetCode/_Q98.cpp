// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

// 有效 二叉搜索树定义如下：

// 节点的左
// 子树
// 只包含 小于 当前节点的数。
// 节点的右子树只包含 大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。

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
//4ms 90.87% 19.72MB 75.09%
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode* root, long left, long right)
    {
        if(root == NULL)
            return true;
        if(root->left != NULL && (root->left->val >= root->val || root->left->val <= left))
        {
            return false;
        }
        if(root->right != NULL && (root->right->val <= root->val || root->right->val >= right))
        {
            return false;
        }

        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }
};