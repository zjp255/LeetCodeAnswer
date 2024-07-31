// 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用 一次 。

// 注意：解集不能包含重复的组合。 


#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        combination(candidates,target,0,0);
        return ans;
    }
    void combination(const vector<int>& candidates, const int& target, int sum, int start)
    {
        if(sum == target)
        {
            ans.push_back(part);
            return;
        }
        if(sum > target)
            return;

        for (int i = 0; i < candidates.size(); i++)
        {
            part.push_back(candidates[i]);
            combination(candidates,target,sum + candidates[i], i + 1);
            part.pop_back();
        }
    }
};