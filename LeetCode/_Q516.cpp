// 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

// 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//37ms 86% 72.54MB 8.78%
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //dp[i][j]表示在区间i- j最长回文子序列长度
        //if(s[i] == s[j])
        // dp[i][j] = dp[i + 1][ j - 1] + 1;
        //else
        //  dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        int len = s.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1));
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i + 1; j <= len; j++)
            {
                if(s[i] == s[j - 1])
                {
                    if(i != j - 1)
                        dp[i][j] = dp[i + 1][ j - 1] + 2;
                    else
                        dp[i][j] = dp[i + 1][ j - 1] + 1;
                }
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }   
        }
        // for (int i = 0; i <= len; i++)
        // {
        //     for (int j = 0; j <= len ; j++)
        //     {
        //        cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";   
        // }

        return dp[0][len];
    }
};