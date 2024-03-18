// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 9MB 52%
class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[j]表示偷到第j号房屋可以获得的最大值
        //dp[j] = max(dp[j - 1], dp[j - 2] + nums[j - 2])
        vector<int> dp(nums.size());
        for (int j = 1; j < nums.size(); j++)
        {
            dp[j] = max(dp[j - 1 < 0?nums.size() + (j - 1):j - 1],dp[j - 2<0?nums.size() + (j - 2): j - 2] + nums[j]);
        }
        vector<int> dp1(nums.size());
        for (int j = 0; j < nums.size() - 1; j++)
        {
            dp1[j] = max(dp1[j - 1 < 0?nums.size() + (j - 1):j - 1],dp1[j - 2<0?nums.size() + (j - 2): j - 2] + nums[j]);
        }
        return max(dp[nums.size() - 1],nums.size() >= 2?dp1[nums.size() - 2]:nums[0]);
    }
};