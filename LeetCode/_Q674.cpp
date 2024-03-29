// 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

// 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//4ms 90% 13MB 13%
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
         //dp[i]表示到i时的最长子序列
        //dp[i] = dp[i - 1] + 1;
        if(nums.size() == 1)
            return 1;
        int ans = 0;
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            else{
                dp[i] = 1;
            }
            if(dp[i] > ans)
            {
                ans = dp[i];
            }
        }
        return ans;
    }
};