// 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

// 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
#include <iostream>
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
//20ms 50% 30MB 25%
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ans = traversalTree(root);
        return max(ans[0],ans[1]);
    }

    vector<int> traversalTree(TreeNode* root)
    {
        if(root == NULL) return {0,0};
        vector<int> left = traversalTree(root->left);
        vector<int> right = traversalTree(root->right);
        //拿
        int v1 = root->val + left[0] + right[0];
        //不拿
        int v2 = max(left[0], left[1]) + max(right[0],right[1]);
        return {v2,v1}; 
    }
};

 //无法AC
class Solution {
public:
    int length = 0;
    int rob(TreeNode* root) {
        vector<int> data(10000);
        traversalTree(root,data,0);
        vector<int> dp(length + 2);
        for (int i = length + 2; i >= 1; i--)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + data[i - 2]);
        }
        return dp[length + 2];
    }

    void traversalTree(TreeNode* root,vector<int>& data,int layer)
    {
        if(root == NULL)
        {
            length = max(length,layer);
            return;
        }
        data[layer] += root->val;
        traversalTree(root->left,data,layer+1);
        traversalTree(root->right,data,layer+1);
    }
};