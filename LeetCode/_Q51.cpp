// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//144ms 5.14% 10.90MB 37.60%
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> part;
    vector<vector<string>> solveNQueens(int n) {
        // 初始化
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = 0; j < n; j++) {
                str += ".";
            }
            part.push_back(str);
        }
        vector<bool> rowUsed = vector(n, false);                     // 行
        vector<bool> colUsed = vector(n, false);                     // 列
        vector<bool> slashUsed = vector((n - 1) * 2 + 1, false);     // 斜线
        vector<bool> antiSlashUsed = vector((n - 1) * 2 + 1, false); // 反
        combination(n, 0, 0, rowUsed, colUsed, slashUsed, antiSlashUsed);
        return ans;
    }

    void combination(int n, int k, int startI, vector<bool>& rowUsed,
                     vector<bool>& colUsed, vector<bool>& slashUsed,
                     vector<bool>& antiSlashUsed) {
        if (k == n) {
            ans.push_back(part);
            return;
        }
        for (int i = startI; i < n; i++) {
            if (rowUsed[i])
                continue;
            for (int j = 0; j < n; j++) {
                if (colUsed[j] || slashUsed[i + j] ||
                    antiSlashUsed[i + (n - j - 1)])
                    continue;
                part[i][j] = 'Q';
                rowUsed[i] = true;
                colUsed[j] = true;
                slashUsed[i + j] = true;
                antiSlashUsed[i + (n - j - 1)] = true;
                combination(n, k + 1, i + 1, rowUsed, colUsed, slashUsed,
                            antiSlashUsed);
                rowUsed[i] = false;
                colUsed[j] = false;
                slashUsed[i + j] = false;
                antiSlashUsed[i + (n - j - 1)] = false;
                part[i][j] = '.';
            }
        }
    }
};




//0ms 100% 10.65MB 21.74%
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> part;
    vector<vector<string>> solveNQueens(int n) {
        init(n);
        vector<bool> usedI(n,false);
        vector<bool> usedJ(n,false);
        vector<bool> usedZhen(2 * n - 1,false);
        vector<bool> usedFan(2 * n - 1,false);
        combine(0,n,usedI,usedJ,usedZhen,usedFan,0);
        return ans;
    }

    void init(int n)
    {
        for(int i = 0; i < n; i++)
        {
            string temp = "";
            for(int j = 0; j < n; j++)
            {
                temp += ".";
            }
            part.push_back(temp);
        }
    }


    void combine(int nCount,int n,vector<bool>& usedI,vector<bool>& usedJ,vector<bool>& usedZhen,vector<bool>& usedFan,int startI)
    {
        if(nCount == n)
        {
            ans.push_back(part);
        }else{
            for(int i = startI; i < n; i++)
            {
                if(usedI[i] == true || ( i > nCount))
                    continue;
                
                for(int j = 0; j < n; j++)
                {
                    if(usedJ[j] == true || usedZhen[i + j] == true || usedFan[i + n - 1 - j] == true)
                        continue;
                    part[i][j] = 'Q';
                    usedI[i] = true;
                    usedJ[j] = true;
                    usedZhen[i + j] = true;
                    usedFan[i + n - 1 - j] = true;
                    combine(nCount + 1,n,usedI,usedJ,usedZhen,usedFan,startI + 1);
                    usedI[i] = false;
                    usedJ[j] = false;
                    usedZhen[i + j] = false;
                    usedFan[i + n - 1 - j] = false;
                    part[i][j] = '.';
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ans =  s.solveNQueens(5);

    return 0;
}