// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//80ms 90.35% 97MB 18%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[j] 表示第j天的最大利润
        //dp[j] = max(dp[j - 1],nums[j] - min);
        vector<int> dp(prices.size() + 1);
        int min = prices[0];
        for (int i = 1; i <= prices.size(); i++)
        {
            if(prices[i - 1] < min)
            {
                min = prices[i - 1];
            }
            dp[i] = max(dp[i - 1], prices[i - 1] - min); 
        }
        return dp[prices.size()];
    }
};