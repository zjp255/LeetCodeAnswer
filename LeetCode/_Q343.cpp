// 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

// 返回 你可以获得的最大乘积 。


#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//0ms 100% 7.25MB 26%
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1,0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max(dp[i],max(j * (i - j),dp[i - j] * j));
            }
        }
        return dp[n];
    }
};