// 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 
// 平衡
//  二叉搜索树。
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
//7ms 87.41% 21.74MB 17.18%
class Solution {
public:
    TreeNode* createRoot(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = createRoot(nums, left, mid - 1);
        temp->right = createRoot(nums, mid + 1, right);
        return temp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createRoot(nums, 0, nums.size() - 1);
    }
};