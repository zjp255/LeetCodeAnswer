// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。


#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//41ms 10.61% 19.38mb 23%
//广搜法
class Solution {
public:
     int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> used(m,vector<bool>(n,false));
        queue<pair<int,int>> que;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(!used[i][j] && grid[i][j] == '1')
                {
                    //cout<<i<<" "<<j<<" ";
                    ans += 1;
                    que.push({i,j});
                    dfs(grid,used,que);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& used, queue<pair<int,int>>& que)
    {
        while (!que.empty())
        {
            int x = que.front().first,y = que.front().second;
            que.pop();
            if(used[x][y] || grid[x][y] == '0')
                continue;
            used[x][y] = true;
            for(int i = 0; i < 4; i++)
            {
                int tx = x + dir[i][0];
                int ty = y + dir[i][1];
                if( tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[0].size())
                    continue;
                if(!used[tx][ty])
                {
                    que.push({tx,ty});
                }
            }
        }
        
    }
};



//37ms 19.68% 15.74Mb 45%
//深搜法
class Solution {
public:
     int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> used(m,vector<bool>(n,false));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(!used[i][j] && grid[i][j] == '1')
                {
                    //cout<<i<<" "<<j<<" ";
                    ans += 1;
                    dfs(grid,used,i,j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& used,int x, int y)
    {
        if(used[x][y] || grid[x][y] == '0')
            return;
        used[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if( tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[0].size())
                continue;
            dfs(grid,used,tx,ty);
        }
    }
};