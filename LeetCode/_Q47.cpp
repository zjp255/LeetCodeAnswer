// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 11.29MB 45.41%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used1 = vector(nums.size(), false);
        combination(nums, used1);
        return ans;
    }
    void combination(const vector<int>& nums, vector<bool>& used1)
    {
        if(part.size() == nums.size())
        {
            ans.push_back(part);
            return;
        }
        bool used[21] = {false};
        for (int i = 0; i < nums.size(); i++)
        {
            if(used[nums[i] + 10] == true || used1[i] == true)
            {
                continue;
            }
            part.push_back(nums[i]);
            used[nums[i] + 10] = true;
            used1[i] = true;
            combination(nums, used1);
            used1[i] = false;
            part.pop_back();
        }
    }
};


//0ms 100% 11.1MB 26.2%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
            int usedNum[21] = {0};
            for(int i = 0; i < nums.size(); i++)
            {
                if(used[i] == true || usedNum[nums[i] + 10] == 1)
                {
                    continue;
                }
                usedNum[nums[i] + 10] = 1;
                part.push_back(nums[i]);
                used[i] = true;
                combine(nums,used);
                used[i] = false;
                part.pop_back();
            }
        }
    }
};