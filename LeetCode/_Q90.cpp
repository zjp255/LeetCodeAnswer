// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//0ms 100% 9.2MB 35%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<bool> used;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector(nums.size(), false);
        combination(nums, 0);
        return ans;
    }

    void combination(const vector<int>& nums, int start)
    {
        ans.push_back(part);
        for (int i = start; i < nums.size(); i++)
        {
            if(i > 0 && used[i - 1] == false && nums[i - 1] == nums[i])
                continue;
            part.push_back(nums[i]);
            used[i] = true;
            combination(nums, i + 1);
            used[i] = false;
            part.pop_back();
        }
        
    }
};







//0ms 100% 8.77Mb 22.51%
class Solution {
public:
   vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i <= nums.size(); i++)
        {
            combine(nums,0,i,ans.size());
        }
        return ans;
    }

    void combine(vector<int>& nums,int start,int targetLen,int startIndex)
    {
        if(part.size() == targetLen)
        {
            for(int i = startIndex; i < ans.size(); i++)
            {
                if(part == ans[i])
                {
                    return;
                }
            }
            ans.push_back(part);
        }else{
            for(int i = start; i < nums.size(); i++)
            {
                part.push_back(nums[i]);
                combine(nums,i + 1,targetLen,startIndex);
                part.pop_back();
            }
        }
    }

};
//0ms 100% 9.02MB 17.55%
class Solution1 {
public:
  vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(), false);
        combine(nums,0,used);
        return ans;
    }

    void combine(vector<int>& nums,int start,vector<bool>& used)
    { 
         ans.push_back(part);
        for(int i = start; i < nums.size(); i++)
        {
            if( i > 0 && nums[i] == nums[i - 1]  && used[i - 1] == false)
            {
                continue;
            }
            part.push_back(nums[i]);
           used[i] = true;
            combine(nums,i + 1,used);
            used[i] = false;
            part.pop_back();    
        }
        
    }
};