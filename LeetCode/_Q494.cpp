// 给你一个非负整数数组 nums 和一个整数 target 。

// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//4ms 74% 13.89 MB 14%
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         //target = x - sum + x
        //x = (target + sum)/2
        //dp[i][j] 1 ~ i 任意加减 得到j的方式,j指的是添加的大小
        //dp[i][j] = dp[i - 1][j - nums[i]]
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int jSize = target + sum;
        if(abs(target) > sum || jSize % 2 == 1)
        {
            return 0;
        }
        jSize /= 2;
        vector<vector<int>> dp(nums.size() + 1,vector<int>(jSize + 1));
        for(int i = 0 ; i <= nums.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 0; j <= jSize; j++)
            {
                if(j - nums[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size()][jSize];
    }
};