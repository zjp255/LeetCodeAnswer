// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//3ms 83.86% 12.52MB 44.76%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combination(candidates, target, 0);
        return ans;
    }
    void combination(const vector<int>& candidates,const int& target, int sum)
    {
        if(sum == target)
        {
            ans.push_back(part);
            return;
        }
        if(sum > target)
            return;
        for(int i = 0; i < candidates.size(); i++)
        {
            part.push_back(candidates[i]);
            combination(candidates, target, sum + candidates[i]);
            part.pop_back();
        }
    }
};


//3ms 88.24% 12.2MB 35.49%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        myCombin(candidates,target,0,0);
        return ans;
    }

    void myCombin(vector<int>& candidates,int target,int sum ,int start)
    {
        
        if(sum == target)
        {   
            ans.push_back(part);
        }else{
            for(int i = start; i < candidates.size(); i++)
            {
                if(sum + candidates[i] <= target)
                {
                    part.push_back(candidates[i]);
                    myCombin(candidates,target,sum + candidates[i],i);
                    part.pop_back();
                }
            }
        }
        
    }
};