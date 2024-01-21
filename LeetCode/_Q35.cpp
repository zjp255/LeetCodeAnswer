// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

// 请必须使用时间复杂度为 O(log n) 的算法。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//0ms 100% 11.84MB 5.95%
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        int mid = 0;
        while(left < right)
        {
            mid = (right + left) / 2;

            if(nums[mid] == target)
            {
                return mid;
            }

            if(target > nums[mid])
            {
                left = mid + 1;
            }
            else if(target < nums[mid]){
                right = mid - 1;
            }
        }

        if(nums[left] >= target)
        {
            return left;
        }
        else{
            return left + 1;
        }
    }
};