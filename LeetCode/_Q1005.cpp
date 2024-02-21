// 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

// 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
// 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

// 以这种方式修改数组后，返回数组 可能的最大和 。

 
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
// 2ms 87.79% 11.27MB 20.09%
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
         int min = nums[0] < 0? -nums[0]:nums[0];
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
            if(nums[i] < min)
            {
                min = nums[i];
            }
            ans += nums[i];
        }
        if(k % 2 == 1)
        {
            ans = ans - 2 * min;
        }
        return ans;
    }
};