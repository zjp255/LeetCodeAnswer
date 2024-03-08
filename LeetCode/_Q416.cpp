// 给你一个 只包含正整数 的 非空 数组 nums 。
// 请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;
//56ms 79% 12.77MB 56%
class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum = 0;
       for (int i = 0; i < nums.size(); i++)
       {
            sum += nums[i];
       }
       if(sum % 2 == 1) return false;
       vector<int> dp((sum / 2) + 1);//dp[i]表示当前容量下的sum最大值
       int target = sum / 2;
       //取 dp[i] = dp[i]] + nums[j];
       //不取 dp[i] = dp[i];
       for (int i = 0; i < nums.size(); i++)
       {
          for(int j = target; j >= nums[i]; j--)
          {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
          }
       }
       if(dp[target] == target)
        return true;  
     return false;
    }
};