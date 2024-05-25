// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//双指针
//0ms 100% 10.21MB 66.5%
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
};


//0ms 100% 10.20Mb 72.57%
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
};


//双指针
//0ms 100% 8.9MB46.2%
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int front = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(nums[i] != val)
            {
                nums[front] = nums[i];
                front++;
            }
        }
        return front;
    }
};