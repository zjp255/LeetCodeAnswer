// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//24ms 90% 21.86MB 83.96%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        combination(nums, 0);
        return ans;
    }

    void combination(const vector<int>& nums, int start)
    {
        if(part.size() >= 2)
        {
            ans.push_back(part);
        }
        bool used[201] = {false};
        for (int i = start; i < nums.size(); i++)
        {
            if((part.size() > 0 && nums[i] < part.back()) || (used[nums[i] + 100] = true))
                continue;
            part.push_back(nums[i]);
            used[nums[i] + 100] = true;
            combination(nums, i + 1);
            part.pop_back();
        }
    }
};


//17ms 99.25% 21.85Mb 77.05%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        combine(nums,0);
        return ans;
    }

    void combine(vector<int>& nums,int start)
    {
        if(part.size() >= 2)
        {
            ans.push_back(part);
        }
        int used[201] = {0};
        for(int i = start; i < nums.size();i++)
        {    
            if(( part.size() > 0 && nums[i] < part.back()) || used[nums[i] + 100] == 1)
            {
                continue;
            }
            used[nums[i] + 100] = 1;
            part.push_back(nums[i]);
            combine(nums,i + 1);
            part.pop_back();
        }
    }
};