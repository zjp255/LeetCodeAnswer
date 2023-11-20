// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
// 1 <= s.length <= 20
// 1 <= p.length <= 20
// s 只包含从 a-z 的小写字母。
// p 只包含从 a-z 的小写字母，以及字符 . 和 *。
// 保证每次出现字符 * 时，前面都匹配到有效的字符
#include<iostream>
using namespace std;
//使用动态规划 从左往右
class Solution {
public:
    bool isMatch(string s, string p) {
           bool dp[11][11];
        int sLen = s.length(),pLen = s.length();
        //初始化dp数组
        for(int i = 0; i < 11; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                if(i == 0)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
        

        for(int i = 0; i < sLen; i++)
        {
            for(int j = 0; j < pLen; j++)
           {
                if(p[j] == s[i] || p[j] == '.')
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if(p[j] == '*')
                {
                    if(p[j - 1] != s[i] && p[j - 1] != '.')
                    {
                        dp[i + 1][j + 1] = dp[i + 1][j + 1 - 2];
                    }else
                    {
                         dp[i + 1][j + 1]= dp[i + 1][j + 1-1] || dp[i + 1][j + 1-2] || dp[i + 1-1][j + 1];
                    }
                }

           }
        }



        return dp[sLen][pLen];
    }
};


int main()
{
    Solution s;
    cout<<s.isMatch("aab","c*a*b")<<endl;
    return 0;
}