// 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

// 一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

// 给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//267ms 94.28% 90.99MB 48%
class Solution {
public:
     int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp_X);
        int ans = 0;
        vector<int> target = points[0];
        for(int i = 0; i < points.size(); i++)
        {
            if(points[i][0] >= target[0] && points[i][0] <= target[1])
            {
                target[0] = target[0] < points[i][0]? points[i][0]:target[0];
                target[1] = target[1] > points[i][1]? points[i][1]:target[1];
                continue;
            }else{
                ans++;
                target = points[i];
            }
        }
        return ++ans;
    }
    static bool cmp_X(vector<int>& x,vector<int>& y)
    {
        if(x[0] == y[0])
        {
            return x[1] < y[1];
        }else{
            return x[0] < y[0];
        }
    }
};