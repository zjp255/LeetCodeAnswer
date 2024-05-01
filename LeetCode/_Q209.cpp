// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其总和大于等于 target 的长度最小的 连续
// 子数组
//  [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//25ms 68.48% 29.85MB 79.91%
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, tans = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tans++;
            sum += nums[i];
            while(sum - nums[left] >= target)
            {
                sum -= nums[left];
                left++;
                tans--;
            }
            if((tans < ans || ans == 0) && sum >= target)
            {
                ans = tans;
            }
        }
        return ans;
    }
};