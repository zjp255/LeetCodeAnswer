// 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

// 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//65ms 81.08% 56.04Mb 6.81%
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* temp = root;
        while (true)
        {
            if(val > temp->val)
            {
                if(temp->right == nullptr)
                {
                    temp->right = new TreeNode(val);
                    break;
                }
                temp = temp->right;
            }
            else {
                if(temp->left == nullptr)
                {
                    temp->left = new TreeNode(val);
                    break;
                }
                temp = temp->left;
            }
        }
        return temp;
    }
};