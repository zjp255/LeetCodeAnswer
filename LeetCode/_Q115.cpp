// 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 109 + 7 取模。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//18ms 65% 30MB 49%
class Solution {
public:
    int numDistinct(string s, string t) {
        //dp[i][j] 以i- 1为结尾和以就j- 1为结尾 的数量
        //if(s[i - 1] == t[i - 1])
        // dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        //else
        // dp[i][j] = dp[i][j - 1];
    
        int sLen = s.size(), tLen = t.size();
        vector<vector<uint64_t>> dp(tLen + 1, vector<uint64_t>(sLen + 1));
        //int ans = 0;
        for (int i = 0; i <= sLen; i++)
            dp[0][i] = 1;
        for (int i = 1; i <= tLen; i++)
        {
            for (int j = 1; j <= sLen; j++)
            {
                if(s[j - 1] == t[i - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else
                    //dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
                    dp[i][j] = dp[i][j - 1];
                //if(dp[i][j] == tLen - 1)
                    //ans++;
            }  
        }
        // for (int i = 0; i <= tLen; i++)
        //  {
        //      for (int j = 0; j <= sLen; j++)
        //      {
        //          cout<<dp[i][j]<<" ";
        //      }
        //      cout<<"\n";  
        //  }
        return dp[tLen][sLen];
         
        // return ans;
    }
};