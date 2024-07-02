// 给定二叉树的根节点 root ，返回所有左叶子之和。

#include <vector>
#include <unordered_map>
#include <map>
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
 

//3ms 65.03% 14.32MB 94.84%
class Solution {
public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        midF(root);
        return ans;
    }

    void midF(TreeNode* root)
    {
        if(!root)
            return;
        TreeNode* left = root->left;
        if(left && !left->left && !left->right)
            ans += left->val;
        else
            midF(root->left);
        midF(root->right);
    }
};