// 给你一个字符串 s，找到 s 中最长的回文子串。

// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

 

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"
 

// 提示：

// 1 <= s.length <= 1000
// s 仅由数字和英文字母组成
#include<iostream>
using namespace std;

//时间20ms 76.37%  内存17.5MB 61.39%
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int count = 0;
        int type1 = 0, type2 = 0;
        string a = s.substr(0 , 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(type1 == 1 && type2 == 1)
                    break;
                if(type1 == 0)
                {
                    if(s[i - j] != s[i + j])
                    {
                        type1 = 1;
                    }
                    else{
                        if(j * 2 + 1 > count)
                        {
                            count = j * 2 + 1;
                            a.clear();
                            a = s.substr(i - j , j * 2 + 1);
                        } 

                    }
                }
                if(type2 == 0)
                {
                    if(s[i - j] != s[i + j - 1])
                    {
                        type2 = 1;
                    }
                    else{
                        if(j * 2 > count)
                        {
                            count = j * 2;
                            a.clear();
                            a = s.substr(i - j , j * 2);
                        } 

                    }
                }
                
            }
            type1 = 0;
            type2 = 0;
        }
        return a;
    }
};

//o 12ms 92.6%  M 17.19mb 61.36%
class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int count = 0;
        int r;
        int type1 = 0, type2 = 0;
        string a = s.substr(0 , 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(type1 == 1 && type2 == 1)
                    break;
                if(type1 == 0)
                {
                    if(s[i - j] != s[i + j])
                    {
                        type1 = 1;
                    }
                    else{
                         r = j * 2 + 1;
                        if(r > count)
                        {
                            count = r;
                            a.clear();
                            a = s.substr(i - j , r);
                        } 

                    }
                }
                if(type2 == 0)
                {
                    if(s[i - j] != s[i + j - 1])
                    {
                        type2 = 1;
                    }
                    else{
                        r = j * 2;
                        if(r > count)
                        {
                            count = r;
                            a.clear();
                            a = s.substr(i - j , r);
                        } 

                    }
                }
                
            }
            type1 = 0;
            type2 = 0;
        }
        return a;
    }
};
//o 12ms 92.6%  M 6.85mb 88.57%
class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int count = 0;
        int r;
        int type1 = 0, type2 = 0;
        int start  = 0, len = 0;
        string a = s.substr(0 , 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(type1 == 1 && type2 == 1)
                    break;
                if(type1 == 0)
                {
                    if(s[i - j] != s[i + j])
                    {
                        type1 = 1;
                    }
                    else{
                         r = j * 2 + 1;
                        if(r > count)
                        {
                            count = r;
                            a.clear();
                            start = i - j;
                            len = r;
                        } 

                    }
                }
                if(type2 == 0)
                {
                    if(s[i - j] != s[i + j - 1])
                    {
                        type2 = 1;
                    }
                    else{
                        r = j * 2;
                        if(r > count)
                        {
                            count = r;
                            a.clear();
                            start = i - j;
                            len = r;
                        } 

                    }
                }
                
            }
            type1 = 0;
            type2 = 0;
        }
        return s.substr(start,len);
    }
};

//错误方法不行，例如“abb”
class Solution3 {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        return getMaxString(s,turnString(s,len),len);
    }

    string getMaxString(string s, string t, int slen)
    {   
        int star = 0,len = 1;
        int count = 0;
        int tstar = 0,tlen = 0;
        int tcount = 0;
        for(int i = 0; i < slen; i++)
        {
            if(s[i] == t[i])
            {
               if(tcount == 0)
               {
                 tstar = i;
               } 
               tcount++;
               tlen++;
               if(tcount > count)
               {
                count = tcount;
                star = tstar;
                len = tlen;
               }
            }
            else{
                tstar = 0;
                tlen = 0;
                tcount = 0;
            }

        }
        return s.substr(star,len);
    }

    string turnString(string s,int len)
    {
        string t;
        for(int i = len - 1; i >= 0 ; i--)
        {
            t += s[i];
        }
        return t;
    }
};


int main()
{
    Solution s;
    cout<<s.longestPalindrome("aacabdkacaa")<<endl;
    
    return 0;
}