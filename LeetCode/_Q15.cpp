// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

// 你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,vector<vector<int>>> hashTable;
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j < len; j++)
            {
                int key = nums[i] + nums[j];
                
            }
        }
        
    }
};