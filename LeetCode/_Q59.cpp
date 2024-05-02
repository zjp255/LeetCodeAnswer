// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。




#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 7.50Mb 91.11%
class Solution {
public:
   vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        generateMatrixSmall(n,1,0,ans);
        if(n % 2 == 1)
            ans[n / 2][n / 2] = n * n;
        return ans;
    }

    void generateMatrixSmall(int n, int start, int loopCount, vector<vector<int>>& ans)
    {
        if(loopCount == n / 2)
            return;   
        for(int i = loopCount; i < n - loopCount; i++)
        {
            ans[loopCount][i] = start;
            start++;
        }
        start--;
        for(int i = loopCount; i < n - loopCount; i++)
        {
            ans[i][n - loopCount - 1] = start;
            start++;
        }
        start--;
        for(int i = n - loopCount - 1; i >= loopCount; i--)
        {
            ans[n - loopCount - 1][i] = start;
            start++;
        }
        start--;
        for(int i = n - loopCount - 1; i > loopCount; i--)
        {
            ans[i][loopCount] = start;
            start++;
        }
        generateMatrixSmall(n,start,++loopCount,ans);
    }
};