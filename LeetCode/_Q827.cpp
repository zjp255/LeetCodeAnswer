// 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。

// 返回执行此操作后，grid 中最大的岛屿面积是多少？

// 岛屿 由一组上、下、左、右四个方向相连的 1 形成。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <unordered_set>
//570ms 53.98% 120.59MB 77%
using namespace std;
class Solution {
public:
    int dir1[4][2] = {0,1,1,0,0,-1,-1,0};
    //int dir2[8][2] = {0,2,2,0,0,-2,-2,0,1,1,-1,-1,-1,1,1,-1};
    int signal = 1;
    int count = 0;
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int,int> maplandCount;
        int result = 0;
        bool isAllLand = true;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                    isAllLand = false;
                if(grid[i][j] == 1)
                {
                    count = 0;
                    signal++;
                    dfs(grid,i,j);
                    maplandCount[signal] = count;
                }
            }
        }
        if(isAllLand == true)
            return m*n;
        unordered_set<int> visitedGrid;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    count = 1;
                    visitedGrid.clear();
                    for (int k = 0; k < 4; k++)
                    {
                        int tx = i + dir1[k][0];
                        int ty = j + dir1[k][1];
                        if(tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[0].size())
                            continue;
                        if (visitedGrid.count(grid[tx][ty])) continue;
                        count += maplandCount[grid[tx][ty]];
                        visitedGrid.insert(grid[tx][ty]);
                    } 
                    result = max(result,count); 
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        grid[x][y] = signal;
        count++;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dir1[i][0];
            int ty = y + dir1[i][1];
            if(tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[0].size())
                continue;
            if(grid[tx][ty] == 1)
            {
                dfs(grid,tx,ty);
            }
        }  
    }
};