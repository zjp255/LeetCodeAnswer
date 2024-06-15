// 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
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

//7ms 82% 20.14MB 82%
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> ans;
        if(root) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            int max = INT32_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                if(temp->val > max)
                    max = temp->val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
};
 