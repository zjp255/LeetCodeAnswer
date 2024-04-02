// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

// 进阶：

// 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//0ms 100% 9MB 14%
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //dp[i][j]表示到ij时最大子序列的长度
        //if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1]  + 1;
        //else dp[i][j] = dp[i][j - 1]
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1));

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1]  + 1;
                else 
                    dp[i][j] = dp[i][j - 1];
            }
        }
        if(dp[s.length()][t.size()] == s.size())
            return true;
        else
            return false;
    }
};