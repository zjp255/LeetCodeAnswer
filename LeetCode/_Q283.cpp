// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//12ms 86.97% 21.38Mb 37.69%
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                swap(nums,i,left++);
            }
        }
    }
    void swap(vector<int>& nums, int l, int r)
    {
         int temp = nums[l];
         nums[l] = nums[r];
         nums[r] = temp;
    }
};