// 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

// 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

// 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//62ms 97.95% 99mb 26.09%
class Solution {
public:
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    int result = 0;
    int islandPerimeter(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
         for (int i = 0; i < m; i++)
         {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i ,j);
                    return result;
                }
            }
            
         }
         return result;
    }

    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        grid[x][y] = 2;
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[0].size())
            {
                count++;
                continue;
            }
            if(grid[tx][ty] == 0)
                count++;
            if(grid[tx][ty] == 1)
                dfs(grid,tx,ty);
        }
        result += count;
    }
};