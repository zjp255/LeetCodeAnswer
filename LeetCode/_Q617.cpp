// 给你两棵二叉树： root1 和 root2 。

// 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

// 返回合并后的二叉树。

// 注意: 合并过程必须从两个树的根节点开始。

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
//29ms 45.65% 31.38MB 75.48%
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }

    TreeNode* merge(TreeNode* root1, TreeNode* root2)
    {
        if(root1 && root2)
            root1->val += root2->val;
        else if(root1 == NULL && root2)
            return root2;
        else if(root1 && root2 == NULL)
            return root1;
        else
            return NULL;
        root1->left = merge(root1->left,root2->left);
        root1->right = merge(root1->right, root2->right);
        return root1;
    }
};
//27ms 59.58% 31.36MB 82.27%
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2)
            root1->val += root2->val;
        else if(root1 == NULL && root2)
            return root2;
        else if(root1 && root2 == NULL)
            return root1;
        else
            return NULL;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};