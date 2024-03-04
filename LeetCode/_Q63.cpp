// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

// 网格中的障碍物和空位置分别用 1 和 0 来表示

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 9.6MB 52%
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1)
            return 0;
        obstacleGrid[0][0] = 1;
        for (size_t i = 1; i < col; i++)
        {
            if(obstacleGrid[0][i] == 1)
            {
                obstacleGrid[0][i] = 0;
                continue;
            }
            obstacleGrid[0][i] = obstacleGrid[0][i - 1];
        }
        for (size_t i = 1; i < row; i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                obstacleGrid[i][0] = 0;
                continue;
            }
            obstacleGrid[i][0] = obstacleGrid[i - 1][0];
        }
        for (size_t i = 1; i < row; i++)
        {
            for (size_t j = 1; j < col; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }
        return obstacleGrid[row - 1][col - 1];
    }
};