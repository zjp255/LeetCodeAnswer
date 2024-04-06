// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

// 回文字符串 是正着读和倒过来读一样的字符串。

// 子字符串 是字符串中的由连续字符组成的一个序列。

// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//45ms 14% 9.96MB 31.56%
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int ans = 0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
       for (int i = len - 1; i >= 0; i--)
       {
            for (int j = i; j < len; j++)
            {
                if(s[i] == s[j])
                {
                    if(j - i > 1)
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                        if(dp[i][j])
                            ans++;
                    }
                    else
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                }
                //if(dp[i][j] == true)
                    //ans++;
            }   
       }
       return ans;
    }
};