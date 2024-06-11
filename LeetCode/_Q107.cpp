
// 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）


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
//0ms 100% 13.71mb 14.08%
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> e;
            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
                e.push_back(temp->val);
            }
            ans.insert(ans.begin(),e);
        }
        return ans;
    }
};