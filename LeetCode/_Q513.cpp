// 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

// 假设二叉树中至少有一个节点。

#include <iostream>
#include <vector>
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

//7ms 96.49% 22.83MB 20%
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(!root) return -1;
        int ans = 0;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            ans = que.front()->val;

            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        return ans;
    }
};