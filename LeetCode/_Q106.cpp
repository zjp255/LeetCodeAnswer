// 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，
// 请你构造并返回这颗 二叉树 。

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

//176ms 5.08% 25.99MB 49.57%
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap, postMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
            postMap[postorder[i]] = i;
        }
        

        return build(inorder, inMap, 0, inorder.size() - 1, postorder, postMap, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, unordered_map<int,int>& inMap, int iL, int iR,
                     vector<int>& postorder, unordered_map<int,int>& postMap, int pL, int pR)
    {
        TreeNode* root = new TreeNode();
        root->val = postorder[pR];
        int temp = inMap[root->val];
        int max = 0;
        for (int i = iL; i < temp; i++)
        {
            if(postMap[inorder[i]] > max)
            {
                max = postMap[inorder[i]];
            }
        }

        if(iL <= temp - 1)
            root->left = build(inorder, inMap, iL, temp - 1, postorder, postMap, pL, max);
        if(iR >= temp + 1)
            root->right = build(inorder, inMap, temp + 1, iR, postorder, postMap, max + 1, pR - 1);
        return root;
    }
};


//12ms 78.48% 24.86MB 91.75%
class Solution {
public:
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return build(inorder, 0, inorder.size() - 1, postorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, int iL, int iR,
                     vector<int>& postorder, int pL, int pR)
    {
        TreeNode* root = new TreeNode();
        root->val = postorder[pR];
        int temp = 0;
        int max = 0;
        for (int i = iL; i <= iR; i++)
        {
            if(inorder[i] == root->val)
            {
                temp = i;
                max = pL + i - iL - 1;
            }
        }

        if(iL <= temp - 1)
            root->left = build(inorder, iL, temp - 1, postorder, pL, max);
        if(iR >= temp + 1)
            root->right = build(inorder, temp + 1, iR, postorder, max + 1, pR - 1);
        return root;
    }
};