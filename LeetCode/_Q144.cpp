// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

 #include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
//0ms 100% 9.63MB 72.24%
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root == NULL) return ans;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* temp = st.top();
            ans.push_back(temp->val);
            st.pop();
            if(temp->right != NULL)
                st.push(temp->right);
            if(temp->left != NULL)
                st.push(temp->left);
        }
        return ans;
    }
};



  //0ms 100% 9.7MB 35.96%
 class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode *root,vector<int>& ans){
        if(root == NULL)
            return;
        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
};