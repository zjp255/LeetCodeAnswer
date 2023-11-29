// 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

// 返回这三个数的和。

// 假定每组输入只存在恰好一个解。
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
//32ms 86.19 10.4MB 14.10%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            int left = i + 1;
            int right = len - 1;
            if(i == 0)
            {
                ans = nums[i] + nums[left] + nums[right];
            }
            while(left < right)
            {
                int temp = nums[i] + nums[left] + nums[right];
                int distance = ans - target;
                int distance1 = temp - target;
                if(distance1 == 0)
                    return temp;
                if((distance1 >= 0 ? distance1: -distance1) <= (distance >= 0 ? distance: -distance))
                {
                    ans = temp;
                }
                if(distance1 > 0)
                {
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};