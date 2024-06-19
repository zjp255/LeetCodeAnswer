// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 说明：叶子节点是指没有子节点的节点。
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

//188ms 97.7% 141.52MB 34.97%
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int ans = INT32_MAX;
        int depth = 0;
        if(root) que.push(root);
        else return 0;
        while (!que.empty())
        {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left == NULL && temp->right == NULL && depth < ans)
                {
                    ans = depth;
                }
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            if(ans != INT32_MAX)
                return ans;
        }
        return ans;
    }
};