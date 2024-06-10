// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

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

//0ms 100% 14.55MB 68.43%
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        if(root)
        {
            que.push(root);
            que.push(NULL);
        }
        vector<int> e;
        while(!que.empty())
        {
            TreeNode* temp = que.front();
            que.pop();
            if(temp != NULL)
            {
                e.push_back(temp->val);                                  
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }else{
                if(!que.empty())
                    que.push(NULL);
                ans.push_back(e);
                e.clear();
            }
        } 
        return ans;
    }
};