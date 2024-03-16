// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
//8ms 72.86% 9.89MB 84.31%
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[j]前j个字符是否匹配
        //dp[j] = dp[j - wordict[i]];
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;
        for (int j = 0; j <= s.size(); j++)
        {
            for(int i = 0; i < wordDict.size(); i++)
            {
                if(j >= wordDict[i].size() &&  equal(s.substr(j - wordDict[i].size(),wordDict[i].size()),wordDict[i]))
                {
                   dp[j] =(dp[j] == true? dp[j]: dp[j - wordDict[i].size()]);
                }
            }
        }
        return dp[s.size()];
    }

    bool equal(string a,string b)
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
};