// 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//101ms 60% 85MB 17%
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j] 表示以nums1[i - 1]和nums2[j - 1]为结尾的子数组的最大长度
        //if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        int ans = 0;
        vector<vector<int>> dp(nums1.size() + 1,vector<int>(nums2.size()));
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if(nums1[i - 1] == nums2[j - 1])
                  dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > ans)
                    ans =dp[i][j];  
            }
        }
        return ans;
    }
};