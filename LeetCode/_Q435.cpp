// 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。
//返回 需要移除区间的最小数量，使剩余区间互不重叠 。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;
//290ms 71.98% 91MB 44%
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp_temp);
        int ans = 0;
        int target = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(target > intervals[i][0])
            {
                ans++;
            }else{
                target = intervals[i][1];
            }
        }
        return ans;
    }
    static bool cmp_temp(vector<int>& x,vector<int>& y)
    {
        return x[1] == y [1]?x [0] < y[0]: x[1] < y[1];
    }
};