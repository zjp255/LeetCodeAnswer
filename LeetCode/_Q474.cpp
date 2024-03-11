// 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//48ms 93% 12MB 60%
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i = 0; i < strs.size(); i++)
        {
            int zeroNum = 0, oneNum = 0;
            for (int j = 0; j < strs[i].size(); j++)
            {
                if(strs[i][j] == '0')
                {
                    zeroNum++;
                }
                else{
                    oneNum++;
                }
            }
            for (int x = m; x >= zeroNum; x--)
            {
                for(int y = n; y >= oneNum;y--)
                {
                    dp[x][y] = max(dp[x][y],dp[x - zeroNum][y - oneNum] + 1);
                }
            }    
        }
        return dp[m][n];
    }
};