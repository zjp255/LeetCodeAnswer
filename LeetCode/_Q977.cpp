// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//双指针法
//7ms 99.90% 27.80Mb 50%
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int leftNum = nums[left] * nums[left];
            int rightNum = nums[right] * nums[right];
            if(leftNum <= rightNum)
            {
                ans[i] = rightNum;
                right--;
            }else{
                ans[i] = leftNum;
                left++;
            }
        }
        return ans;
    }
};

//30ms 18.02% 28.81mb 20.20%
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};