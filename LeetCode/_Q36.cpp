// 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

// 16ms 81% 28.9MB 5%
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> orgMap = {{'1',0},{'2',0},{'3',0},{'4',0},{'5',0},{'6',0},{'7',0},{'8',0},{'9',0}};
        unordered_map<char,int> rowMap;
        unordered_map<char,int> colMap[9];
        unordered_map<char,int> blockMap[9];
        int rowLen = 9;
        int colLen = 9;
        
        for(int i = 0; i < rowLen; i++)
        {
            colMap[i] = orgMap;
            blockMap[i] = orgMap; 
        }

        for(int i = 0; i < rowLen; i++)
        {
            rowMap = orgMap;
            for(int j = 0; j < colLen; j++)
            {
                if(board[i][j] != '.')
                {
                    if(rowMap[board[i][j]] == 0)
                    {
                        rowMap[board[i][j]]++;
                    }else{
                        return false;
                    }

                    if(colMap[j][board[i][j]] == 0)
                    {
                        colMap[j][board[i][j]]++;
                    }else{
                        return false;
                    }

                    if(blockMap[(i / 3) * 3 + j / 3 ][board[i][j]] == 0)
                    {
                        blockMap[(i / 3) * 3 + j / 3 ][board[i][j]]++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};