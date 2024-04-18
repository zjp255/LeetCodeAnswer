// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//7ms 91.62% 13.09Mb 92.16%
class Solution {
public:
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    void solve(vector<vector<char>>& board) {

        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][board[0].size() - 1] == 'O') dfs(board, i, board[0].size() - 1);
        }

        // 从上边和下边 向中间遍历
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[board.size() - 1][j] == 'O') dfs(board, board.size() - 1, j);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y)
    {
        board[x][y] = 'A';
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= board.size()  || ty < 0 || ty >= board[0].size())
                continue;
            if(board[tx][ty] == 'O')
                dfs(board,tx,ty);
        }
    }
};