// 给你一个大小为 m x n 的二进制矩阵 grid 。

// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

// 岛屿的面积是岛上值为 1 的单元格的数目。

// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。


#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>

using namespace std;
//15ms 62% 26MB 53%
class Solution {
public:
    int dir[4][2] ={0,1,1,0,-1,0,0,-1};
    int ans = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> used(grid.size(),vector<bool>(grid[0].size(), false));
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1 && used[i][j] == false)
                {
                    ans = 0;
                    dfs(grid,used,i,j);
                    if(ans > result)
                    {
                        result = ans;
                    }
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& used, int x, int y)
    {
        if(used[x][y] || grid[x][y] == 0)
            return;
        used[x][y] = true;
        ans++;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[0].size())
                continue;
            dfs(grid,used,tx,ty);
        }
        
    }
};