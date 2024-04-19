// 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

// 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

// 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

// 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;
//23ms 94% 20.75MB 52%
class Solution {
public:
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    vector<vector<int>> result;
    int count = 1;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> used(heights.size(),vector<int>(heights[0].size(), 0));
        for (int i = 0; i < heights.size(); i++)
        {
            if(used[i][0] != 1) 
            {
                count = 1;
                dfs(heights,used,i,0);
            }
            if(used[i][heights[0].size() - 1] != 2)
            {
                count = 2;
                dfs(heights,used,i,heights[0].size() - 1);
            }
        }
         for (int i = 0; i < heights[0].size(); i++)
        {
            if(used[0][i] != 1) 
            {
                count = 1;
                dfs(heights,used,0,i);
            }
            if(used[heights.size() - 1][i] != 2)
            {
                count = 2;
                dfs(heights,used,heights.size() - 1,i);
            }
        }
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
               if(used[i][j] == 3)
                result.push_back({i,j});
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& heights,vector<vector<int>>& used, int x, int y)
    {
        if(used[x][y] == count || used[x][y] == 3)
            return;
        used[x][y] += count;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= heights.size() || ty < 0 || ty >= heights[0].size())
                continue;
            if(heights[tx][ty] >= heights[x][y])
                dfs(heights,used,tx,ty);
        }
    }
};



//超时
class Solution {
public:
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    vector<vector<int>> result;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        bool po = false,ao = false;
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
                po = false;
                ao = false;
                dfs(heights,i,j,po,ao,-1,-1);
                if(po && ao)
                    result.push_back({i,j});
            }
            
        }
        return result;
    }

    void dfs(vector<vector<int>>& heights, int x, int y , bool& po, bool& ao, int lx, int ly)
    {
        if(x == 0 || y == 0)
            po = true;
        if(x == heights.size() - 1 || y == heights[0].size() - 1 )
            ao = true;
        if(po && ao)
            return;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= heights.size() || ty < 0 || ty >= heights[0].size()|| (lx == tx && ly == ty))
                continue;
            if(heights[tx][ty] <= heights[x][y])
                dfs(heights,tx,ty,po,ao,x,y);
        }
    }
};