// 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

// 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

// 0 <= j <= nums[i] 
// i + j < n
// 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//7ms 93.55% 18.5MB 27.93%
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxStep = 0;
        int farIndex = 0;
        int step = 0;
        for(int i = 0; i < nums.size();i++)
        {
            if(maxStep >= nums.size() -1)
            {              
                break;
            }
            if(nums[i] + i > farIndex)
            {
                farIndex = nums[i] + i;
            }
            if(maxStep == i)
            {
               maxStep = farIndex;
               step++;
            }
        }
        return step;
    }
};