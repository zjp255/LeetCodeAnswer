// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//0ms 100% 8.38MB 39.54%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> subsets(vector<int>& nums) {
        combination(nums, 0);
        ans.push_back({});
        return ans;
    }

    void combination(const vector<int>& nums, int start)
    {
        ans.push_back(part);
        for (int i = start; i < nums.size(); i++)
        {
            part.push_back(nums[i]);
            combination(nums, start + 1);
            part.pop_back();
        }
        
    }
};


//0ms 100% 8.26Mb 16.8%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int i = 0; i <= nums.size(); i++)
        {
            combine(nums,0,i);
        }
        return ans;
    }

    void combine(vector<int>& nums,int start,int targetLen)
    {
        if(part.size() == targetLen)
        {
            ans.push_back(part);
        }else{
            for(int i = start; i < nums.size(); i++)
            {
                part.push_back(nums[i]);
                combine(nums,i + 1,targetLen);
                part.pop_back();
            }
        }
    }

};