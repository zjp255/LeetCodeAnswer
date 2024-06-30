// 给定一个二叉树，判断它是否是 
// 平衡二叉树
  
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

//4ms 90% 21.11MB 76.99%
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int ans = balanced(root);
        return ans == -1? false: true;
    }

    int balanced(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int l = balanced(root->left);
        if(l == - 1)
            return -1; 
        int r = balanced(root->right);
        if(r == - 1)
            return -1; 
        int result = r - l > 0? r-l : l-r;
        if(result > 1)
            return -1;
        else
            result = max(r,l) + 1;
        return result;
    }
};