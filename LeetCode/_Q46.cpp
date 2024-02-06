//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 9.79MB 9.63%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        combine(nums,used);
        return ans;
    }

    void combine(vector<int>& nums,vector<bool>& used)
    {
        if(part.size() == nums.size())
        {
            ans.push_back(part);
        }else{
            for(int i = 0; i < nums.size(); i++)
            {
                if(used[i] == true)
                {
                    continue;
                }
                part.push_back(nums[i]);
                used[i] = true;
                combine(nums,used);
                used[i] = false;
                part.pop_back();
            }
        }
    }
};