// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//3ms 93.9% 15.61MB 5.07%
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = (left + right) / 2;

            if(nums[mid] == target)
            {
                right = mid;
                left = mid;
                while((right + 1 == len?false:nums[right + 1] == target) || (left - 1 < 0? false: nums[left - 1] == target))
                {
                    if(right + 1 < len && nums[right + 1] == target)
                    {
                        right++;
                    }
                    if(left - 1 >= 0  && nums[left - 1] == target)
                    {
                        left--;
                    }
                }
                return {left,right};
            }

            if(nums[mid] > target)
            {
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return {-1,-1};
    }
};

int main()
{
    Solution s;
    vector<int> v = {1};
    s.searchRange(v,1);
}