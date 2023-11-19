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
//使用动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[10][10];
        int sLen = s.length(),pLen = s.length();
        //初始化dp数组
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                dp[i][j] = false;
            }
        }
        char ofstar = ' ';
        int j = 0;
        int count = 0;
        for(int i = 0; i < pLen; i++)
        {
            for( j; j < sLen; j++)
            {
                if(p[i + 1] !=  '*')
                {
                    if(p[i] == s[j] || p[i] == '.')
                    {
                        dp[i][j] = true;
                        break;
                    }else if(p[i] == ofstar)
                    {
                        if(count >= 1)
                        {
                            count--;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    
                }else
                {
                    i++;
                    if(p[i-1] == s[j] || p[i - 1] == '.')
                    {
                        ofstar = p[i - 1];
                        dp[i][j] = true;
                        count++;
                    }
                    else
                    {
                        break;
                    }
                    
                }
            }
        }

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                dp[j][i] = false;
            }
        }

    }
};


int main()
{
    return 0;
}