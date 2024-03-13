// 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

// 题目数据保证答案符合 32 位整数范围。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//0ms 100% 7.82MB 30.76%
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //dp[i] 表示容量为i时的组合数
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int j = 0; j <= target; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if(j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};