// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回""
#include<iostream>
#include<vector>
using namespace std;
//O(mn + n)
//0ms 100% 9.32mb 52.53%
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int lenMin = strs[0].length();
        int strsLen = strs.size();
        for(int i = 0; i < strsLen; i++)
        {
            if(strs[i].length() < lenMin)
            {
                lenMin = strs[i].length();
            }
        }

        for(int i = 0; i < lenMin; i++)
        {
            char temp = strs[0][i];
            for(int j = 1; j < strsLen;j++)
            {
                if(strs[j][i] != temp)
                {
                    return ans;
                }
            }
            ans += temp;
        }
        return ans;
    }
};