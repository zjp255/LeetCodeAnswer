// 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

// 创建一个根节点，其值为 nums 中的最大值。
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。
// 返回 nums 构建的 最大二叉树 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//43ms 99.3% 40.58MB 85.68%
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* buildTree(vector<int>& nums, int l, int r)
    {
        TreeNode* root = new TreeNode();
        //int max = 0;
        int maxIndex = l;
        for (int i = l; i <= r; i++)
        {
            if(nums[i] >= nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        root->val = nums[maxIndex];

        if(l < maxIndex)
            root->left = buildTree(nums, l, maxIndex - 1);
        if(r > maxIndex)    
            root->right = buildTree(nums, maxIndex + 1, r);
        return root;
    }
};
