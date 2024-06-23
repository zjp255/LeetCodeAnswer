// 给你一个二叉树的根节点 root ， 检查它是否轴对称。
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
 //对此bbb
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        else
            return false;
        int lastLayerCount = 1;
        while (!que.empty())
        {
            int size = que.size();
            
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left) 
                {
                    que.push(temp->left);
                    lastLayerCount++;
                }
                if(temp->right)
                {
                    que.push(temp->right);
                    lastLayerCount++;
                }
                if(lastLayerCount != 1 && lastLayerCount * 2 != size)
                    return false;
            }
        }
        return true;
    }
};