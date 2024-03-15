// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

// 完全平方数 是一个整数，其值等于另一个整数的平方；
// 换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//44ms 74.96% 10.48MB 15%
class Solution {
public:
    int numSquares(int n) {
         //dp[j]表示最少数量
        //dp[j] = min(dp[j],dp[j - ?] + 1)
        if(n == 1)
            return 1;
        vector<int> dp(n + 1,INT_MAX);
        dp[0] = 0;
        int x = n / 2;
        for (int i = 1; i <= x; i++)
        {
            int temp = i * i;
            for (int j = temp; j <= n; j++)
            {
                if(dp[j - temp] < INT_MAX)
                dp[j] = min(dp[j],dp[j - temp] + 1);
            }
        }
        return dp[n];
    }
};