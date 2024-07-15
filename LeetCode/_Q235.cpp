// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
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
//28ms 33.54% 21.51Mb 5.08%
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q, INT32_MIN, INT32_MAX);
        return ans;
    }

    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, int l, int r)
    {
        if(root == nullptr || ans != nullptr)
            return;

        dfs(root->left, p, q, l, root->val);
        dfs(root->right, p, q, root->val, r);
        if((p->val >= root->val || q->val >= root->val) && (p->val <= root->val || q->val <= root->val)
            && (p->val < r && p->val > l) && (q->val < r && q->val > l))
            {
                ans = root;
                return;
            }
    }
};