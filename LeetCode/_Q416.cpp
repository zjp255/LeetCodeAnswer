// 给你一个 只包含正整数 的 非空 数组 nums 。
// 请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum = 0;
       for (int i = 0; i < nums.size(); i++)
       {
            sum += nums[i];
       }
       if(sum % 2 == 1) return false;
       vector<int> dp(sum / 2);
       int target = sum / 2;
       for (int i = 0; i < nums.size(); i++)
       {
            
       }
       
     return true;
    }
};