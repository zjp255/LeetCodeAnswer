// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 子数组 是数组中的一个连续部分。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
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