// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//92ms 86.94% 75.96MB 68%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[j][0]表示一次持有的最大利润
        //dp[j][1]表示二次持有的最大利润
        //dp[j][2]表示一次卖出持有的最大利润
        //dp[j][3]表示二次卖出持有的最大利润
        //dp[j][0] = max(dp[j - 1][0], - prices[j])
        //dp[j][1] = max(dp[j - 1][1],dp[j - 1][2] - prices[j])
        //dp[j][2] = max(dp[j - 1][2] , dp[j - 1][0] + prices[j])
        //dp[j][3] = max(dp[j - 1][3],dp[j - 1][1] + prices[j])
        vector<vector<int>> dp(2,vector<int>(4));
        dp[0][0] -= prices[0];
        dp[0][1] = INT_MIN / 2;
        dp[0][2] = 0;
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], - prices[i]);
            dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][0] + prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][2] - prices[i]);
            dp[i % 2][3] = max(dp[(i - 1) % 2][3], dp[(i - 1) % 2][1] + prices[i]);
            //cout<< dp[i % 2][0]<< " "<< dp[i % 2][1]<< " "<< dp[i % 2][2]<< " "<< dp[i % 2][3]<<endl;
        }
        int ans = max(dp[(prices.size() - 1) % 2][2],dp[(prices.size() - 1) % 2][3]);    
        return ans < 0? 0: ans;        
    }
};