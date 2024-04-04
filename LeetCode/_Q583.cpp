// 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

// 每步 可以删除任意一个字符串中的一个字符。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//16ms 46% 15MB 10%
class Solution {
public:
    int minDistance(string word1, string word2) {
         //dp[i][j]表示到i-1和j - 1时的最大共同子序列
        //if(word1[i - 1] == word2[j - 1])
        //  dp[i][j] = dp[i - 1][j - 1] + 1
        //else
        //  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                 dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }   
        }
        return len1 + len2 - 2 * dp[len1][len2];
    }
};