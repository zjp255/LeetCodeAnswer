// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。


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
//11ms 77.61% 24.82MB 93.65%
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, preorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int pL, int pR,vector<int>& inorder, int iL, int iR)
    {
        TreeNode* root = new TreeNode();
        root->val = preorder[pL];
        int rootIndex = iL;
        int size = 0;
        while (inorder[rootIndex] != root->val && rootIndex <= iR)
        {
            rootIndex++;
        }
        
        size = rootIndex - iL;

        if( pL + 1 <= pL + size)
            root->left = build(preorder, pL + 1, pL + size, inorder, iL, rootIndex - 1);
        if(pL + size + 1 <=  pR)
            root->right = build(preorder, pL + size + 1, pR, inorder, rootIndex + 1, iR);
        
        return root;
    }
};