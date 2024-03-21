// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

// 返回 你能获得的 最大 利润 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//动规
//3ms 86.85% 15MB 28%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][0]表示第i天持有这支股票最大利润
        //dp[i][1]表示第i天不持有这只股票的最大利润
        //dp[i][0] = max(dp[i - 1][0],dp[i - 1][0] - prices[i])
        //dp[i][1] = max(dp[i - 1][1],dp[i - 1][0] + prices[i])
        vector<vector<int>> dp(2,vector<int>(2));
        dp[0][0] -= prices[0];
        for(int i = 1; i < prices.size();i++)
        {
            dp[1][0] = max(dp[0][0],dp[0][1] - prices[i]);
            dp[1][1] = max(dp[0][1],dp[0][0] + prices[i]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return max(dp[1][0],dp[1][1]);
    }
};



//贪心算法
//0ms 100% 15.10MB 37.67%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i - 1])
            {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};