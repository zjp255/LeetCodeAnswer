// 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。

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
//12ms 58.27% 21.67MB 96.96%
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> ans;
        if(root) que.push(root);
        while (!que.empty())
        {
            double sum = 0;
            int size =  que.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                sum += temp->val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            ans.push_back(sum / size);
        }
        return ans;
    }
};