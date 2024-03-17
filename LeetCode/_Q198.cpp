// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 9.10MB 21.43%
class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[j]偷到第i号房屋能获得的最大金额
        //dp[j] = max(dp[j - 1],dp[j - 2] + nums[j])
        vector<int> dp(nums.size() + 2);
        for ( int j = 2; j < nums.size() + 2; j++)
        {
            dp[j] = max(dp[j - 1], dp[j - 2] + nums[j - 2]);
        }
      
        return dp[nums.size() + 1];
    }
};