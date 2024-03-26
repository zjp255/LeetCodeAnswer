// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的
// 子序列
// 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//76ms 70% 12.58MB 52%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]以nums[i]结尾的最大子序列长度
        //if(nums[i] > nums[j])
        //dp[i] = max(dp[i],dp[j] + 1)
        if (nums.size() <= 1) return nums.size();
        int ans = 0;
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(ans < dp[i])
            {
                ans = dp[i];
            }
        }
        return ans;
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[i] > nums[i - 1])
        //     {
        //         dp[i] = dp[i - 1] + 1;
        //     }else{
        //         dp[i] = dp[i - 1];
        //     }
        // }
        // return dp[nums.size() - 1];
    }
};

