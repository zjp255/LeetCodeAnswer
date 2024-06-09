
// 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  //0ms 100% 9.68MB 49%
class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root == NULL) return ans;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


  //0ms 100% 9.7MB 35.96%
 class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode *root,vector<int>& ans){
        if(root == NULL)
            return;
        dfs(root->left,ans);
        dfs(root->right,ans);
        ans.push_back(root->val);
    }
};