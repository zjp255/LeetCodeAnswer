// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

// 请你计算并返回达到楼梯顶部的最低花费。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//3ms 84% 16MB 6%
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1,0);
        for (size_t i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 2] + cost[i - 2],dp[i - 1] + cost[i - 1]);
        }
        return dp.back();
    }
};