// 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

// 返回获得利润的最大值。

// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//70ms 86% 56.04MB 85%
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(2,vector<int>(2));
        dp[0][1] = - prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i % 2][0] = max(dp[(i - 1)% 2][0] ,dp[(i - 1)% 2][1] + prices[i] - fee);
            dp[i % 2][1] = max(dp[(i - 1)% 2][1] ,dp[(i - 1)% 2][0] - prices[i]); 
        }
        return dp[(prices.size() - 1) % 2][0];
    }
};