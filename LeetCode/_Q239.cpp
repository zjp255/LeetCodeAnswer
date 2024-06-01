// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        queue<int> que;
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(que.size() < k)
            {
                que.push(nums[i])
            }
            else{
                ans.push_back(max);
                
               
            }
            if(nums[i] > max)
                max = nums[i];
        }
        return ans;
    }
};