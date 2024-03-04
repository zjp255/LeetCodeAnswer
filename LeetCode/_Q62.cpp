// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

// 问总共有多少条不同的路径？
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//0ms 100% 7.5Mb 14%
class Solution {
public:
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m,vector<int>(n,0));
        //初始化dp数组
        for (size_t i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        for (size_t i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        
        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 1; j < m; j++)
            {
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};