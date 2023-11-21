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
#include<string.h>
using namespace std;
//使用动态规划 从左往右
//t 4ms 88.28% s6.4mb 89.10%
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(),pLen = p.length();
        bool dp[sLen + 1][pLen + 1];
        //初始化dp数组
        for(int i = 0; i <= sLen; i++)
        {
            for(int j = 0; j <= pLen; j++)
            {
                    dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for(int j = 1; j <= pLen;j++)
        {
            if(p[j - 1] == '*')
              dp[0][j] = dp[0][j-2];
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
        for(int i=0;i<=sLen;i++){
            for(int j=0;j<=pLen;j++){
               cout<< dp[i][j]<<" ";
            }
            cout<<"\n";
            }
        return dp[sLen][pLen];
    }
};
    
class Solution2 {
public:
    bool isMatch(string s, string p) {
        s=" "+s;//防止该案例：""\n"c*"
        p=" "+p;
        int m=s.size(),n=p.size();
        bool dp[m+1][n+1];
        memset(dp,false,(m+1)*(n+1));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(s[i-1]!=p[j-2] && p[j-2]!='.')
                        dp[i][j]=dp[i][j-2];
                    else{
                        dp[i][j]=dp[i][j-1] || dp[i][j-2] || dp[i-1][j];

                    }
                }
            }
        }

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
               cout<< dp[i][j]<<" ";
            }
            cout<<"\n";
            }
        return dp[m][n];
    }
};
int main()
{
    Solution s;
    cout<<s.isMatch("aaa","ab*ac*a")<<endl;
    return 0;
}