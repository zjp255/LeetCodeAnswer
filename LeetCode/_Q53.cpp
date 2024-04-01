// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 子数组 是数组中的一个连续部分。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//动态规划
//70 ms 90% 70MB 22%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i],nums[i]);
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};


//82ms 77% 68.57MB 40%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if(count > ans)
            {
                ans = count;
            }
            if(count < 0)
            {
                count = 0;
            }
        }
        return ans;
    }
};

//超时
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = 0;
            for(int j = i + 1; j < nums.size(); j++)
            {
                temp += nums[j];
                if(temp > ans)
                {
                    ans = temp;
                }
            }
        }
        return ans;
    }
};