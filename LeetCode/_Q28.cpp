// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回  -1 。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//kmp
//0ms 100% 7.49mb 22.02%
class Solution {
public:
   int strStr(string haystack, string needle) {
        vector<int> next = getNextNums(needle);
        int j = 0;
        for (int i = 0; i < haystack.length();i++)
        {
            while(j > 0 && haystack[i] != needle[j]) { // 不匹配
                j = next[j - 1]; // j 寻找之前匹配的位置
            }
            if(haystack[i] == needle[j])
            {
                j++;
                if(j == needle.length())
                {
                    return i - j + 1;
                }
            }
            
        }
        return -1;
    }

    vector<int> getNextNums(string& a)
    {
        vector<int> next(a.length(), 0);
        int left = 0;
        int right = 0;
        for (int i = 1; i < a.length(); i++)
        {
            left = 0;
            right = left + 1;
            while(right <= i)
            {
                if(a[left] == a[right])
                {
                    left++;
                    right++;
                }else{
                    right = right - left + 1;
                    left = 0;
                }
            }
            next[i] += left;
        }
        return next;
    }
};



//0ms 100% 6.50% 46.10%
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
        if(len < 1)
        {
            return -1;
        }
        int* next = new int[len]();
        getNextNums(needle,next);
        int hayLen = haystack.length();
        int i = 0;
        int j = 0;
        while (i < hayLen && j < len)
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }else{
                if(j >= 1)
                    j = next[j - 1];
                else
                    i++;
            }
        }
        if(j < len)
        {
            return -1;
        }
        else{
            return i - j;
        }
    }

    void getNextNums(string needle,int*& next)
    {
        int i = 0, j = 1;
        int len = needle.length();
        next[0] = 0;
        while( j < len)
        {
            cout<< next[j- 1];
            if(needle[i] == needle[j])
            {
                next[j] = ++i;
                j++;   
            }
            else{
               if(i > 0)
               {
                   i = next[i - 1];
               }else{
                   next[j] = 0;
                   j++;
               }
            }
        }
        cout<< next[j- 1];
    }
};

int main()
{
    Solution s;
    cout<<s.strStr("mississippi","issip");
}