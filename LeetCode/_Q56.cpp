// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
//请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//21ms 90% 23.75MB 11%
class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;
        for(vector<int> part:intervals)
        {
            if(part[0] > end)
            {
                ans.push_back({start,end});
                start = part[0];
                end = part[1];
            }
            if(part[0] <= end && part[1] >= end)
            {
                end = part[1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
    static bool cmp(vector<int>& x,vector<int>& y)
    {
        return x[0] == y[0]?x[1] < y[1]:x[0] < y[0];
    }
};