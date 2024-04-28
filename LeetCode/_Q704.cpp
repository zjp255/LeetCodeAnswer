// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//20ms 89.59% 29.18Mb 81.72%
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return - 1;
    }
};

//22ms 84% 29.26MB 43.7%
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums,0,nums.size() - 1, target);
    }

    int search(vector<int>& nums, int left, int right, int target)
    {
        
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        if(left == right || right >= nums.size() || left < 0)
            return -1;
        if(target > nums[mid])
            return search(nums, mid + 1, right, target);
        else
            return search(nums, left, mid - 1,target);
    }
};