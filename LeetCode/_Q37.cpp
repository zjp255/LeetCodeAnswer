// 编写一个程序，通过填充空格来解决数独问题。

// 数独的解法需 遵循如下规则：

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
// 数独部分空格内已填入了数字，空白格用 '.' 表示。


#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//7ms 72.09% 9.10MB 12.38%
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<vector<bool>> rows = vector(n, vector(n, false));
        vector<vector<bool>> cols = vector(n, vector(n, false));
        vector<vector<bool>> squares = vector(n, vector(n, false));
        // 初始化
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    rows[i][num - 1] = true;
                    cols[j][num - 1] = true;
                    squares[(i / 3) * 3 + (j / 3)][num - 1] = true;
                }
            }
        }
        combination(board, 0, 0, rows, cols, squares);
    }
    bool combination(vector<vector<char>>& board, int row, int col,
                     vector<vector<bool>>& rows, vector<vector<bool>>& cols,
                     vector<vector<bool>>& squares) {
        if (row == 9) {
            return true;
        }
        if (board[row][col] != '.') {
            return combination(board, row + ((col + 1) / 9), (col + 1) % 9,
                               rows, cols, squares);
        }
        int index = (row / 3) * 3 + (col / 3);
        for (int i = 0; i < 9; i++) {
            if (rows[row][i] || cols[col][i] || squares[index][i])
                continue;
            rows[row][i] = true;
            cols[col][i] = true;
            squares[index][i] = true;
            board[row][col] = '0' + i + 1;
            if (combination(board, row + ((col + 1) / 9), (col + 1) % 9, rows,
                            cols, squares))
                return true;
            rows[row][i] = false;
            cols[col][i] = false;
            squares[index][i] = false;
            board[row][col] = '.';
        }
        return false;
    }
};


//6ms 77.95% 8.7MB 11.07%
class Solution {
public:
   void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> used(27,vector<bool>(9,false));
        initUsed(board,used);
        combine(board,used,0);
    }

    void initUsed(vector<vector<char>>& board,vector<vector<bool>>& used)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    used[i][board[i][j] - 49] = true;
                    used[j + 9][board[i][j] - 49] = true;
                    used[(i / 3)*3 + j / 3 + 18][board[i][j] - 49] = true;
                }
            }
        }
    }

    bool combine(vector<vector<char>>& board,vector<vector<bool>>& used,int count)
    {
        if(count == 81)
        {
            return true;
        }
        if(board[count/9][count%9] == '.')
        {
            int i = count/9;
            int j = count%9;
            for(int x = 1; x <= 9; x++)
            {
                if(used[i][x - 1] == true ||
                used[j + 9][x - 1] == true ||
                    used[(i / 3)*3 + j / 3 + 18][x - 1] == true)
                    {
                        continue;
                    }
                    board[i][j] = x + 48;
                    used[i][x - 1] = true;
                    used[j + 9][x - 1] = true;
                    used[(i / 3)*3 + j / 3 + 18][x - 1] = true;
                    if(combine(board,used, count + 1)) return true;
                    board[i][j] = '.';
                    used[i][x - 1] = false;
                    used[j + 9][x - 1] = false;
                    used[(i / 3)*3 + j / 3 + 18][x - 1] = false;
            }
            return false;            
        }else{
            if(combine(board,used, count + 1)) return true;
        }
        return false; 
    }
};

//8ms 75.37% 8.84MB 10%
class Solution2 {
public:
        void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> used(27,vector<bool>(9,false));
        initUsed(board,used);
        combine(board,used);
    }

    void initUsed(vector<vector<char>>& board,vector<vector<bool>>& used)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    used[i][board[i][j] - 49] = true;
                    used[j + 9][board[i][j] - 49] = true;
                    used[(i / 3)*3 + j / 3 + 18][board[i][j] - 49] = true;
                }
            }
        }
    }

    bool combine(vector<vector<char>>& board,vector<vector<bool>>& used)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    continue;
                }
                for(int x = 1; x <= 9; x++)
                {
                    if(used[i][x - 1] == true ||
                        used[j + 9][x - 1] == true ||
                        used[(i / 3)*3 + j / 3 + 18][x - 1] == true)
                    {
                        continue;
                    }
                    board[i][j] = x + 48;
                    used[i][x - 1] = true;
                    used[j + 9][x - 1] = true;
                    used[(i / 3)*3 + j / 3 + 18][x - 1] = true;
                    if(combine(board,used)) return true;
                    board[i][j] = '.';
                    used[i][x - 1] = false;
                    used[j + 9][x - 1] = false;
                    used[(i / 3)*3 + j / 3 + 18][x - 1] = false;
                }
                return false;
            }
        } 
        return true;
    } 
};

int main()
{
    Solution s;
    vector<vector<char>> temp = {{'5','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(temp);
}