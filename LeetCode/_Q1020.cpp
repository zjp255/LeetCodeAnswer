// 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。

// 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。

// 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//改进后
//48ms 89.80% 30.05 86%
class Solution {
public:
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    int numEnclaves(vector<vector<int>>& grid) {
        int xlen = grid.size(), ylen = grid[0].size();
        int result = 0;

        for(int i = 0; i < ylen; i++)
        {
            if(grid[0][i] == 1)dfs(grid,0,i);
            if(grid[xlen - 1][i] == 1)dfs(grid,xlen - 1,i);
        }
        
        for(int i = 0; i < xlen; i++)
        {
            if(grid[i][0] == 1)dfs(grid,i,0);
            if(grid[i][ylen - 1] == 1)dfs(grid,i,ylen - 1);
        }
        for (int i = 1; i < xlen - 1; i++)
        {
            for (int j = 1; j < ylen - 1; j++)
            {
                if(grid[i][j] == 1)
                {
                   result++;
                }
            } 
        }
        return result;
    }

    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[0].size())
                continue;
            if(grid[tx][ty] == 0)
                continue;
            dfs(grid,tx,ty);
        }    
    }
};


//1050ms 5% 43.52Mb 38.09%
class Solution {
public:
     int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    bool istrue = false;
    int ans = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        int xlen = grid.size(), ylen = grid[0].size();
        vector<vector<bool>> used(xlen,vector<bool>(ylen,false));
        int result = 0;
        for (int i = 0; i < xlen; i++)
        {
            for (int j = 0; j < ylen; j++)
            {
                if(grid[i][j] == 1 && used[i][j] == false)
                {
                    istrue = false;
                    dfs(grid,used,i,j);
                    if (!istrue)
                    {
                        result += ans;
                    }
                    ans = 0;
                }
            } 
        }
        return result;
    }

    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& used, int x, int y)
    {
        if(grid[x][y] == 0 || used[x][y] == true)
            return;
        if(istrue == false && (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1))
            istrue = true;
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

