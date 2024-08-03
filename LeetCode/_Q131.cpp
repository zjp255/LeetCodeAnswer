// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

// 回文串 是正着读和反着读都一样的字符串。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//回溯 + 动态规划
//96ms 82.95% 77.61MB 50.63%
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> part;
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
        huWen(s);
        combination(s, 0);
        return ans;
    }

    void combination(const string& s, int start) {
        if (start >= s.size()) {
            ans.push_back(part);
            return;
        }
        for (int i = 1; i <= s.size() - start; i++) {
            if (!dp[start][start + i - 1]) {
                continue;
            }
            string str = s.substr(start, i);
            part.push_back(str);
            combination(s, start + i);
            part.pop_back();
        }
    }

    void huWen(const string& s) {
        int size = s.size();
        dp = vector(size, vector<bool>(size, false));
        // dp[i][j]表示从下标i 到 j 之间的字符串是否为回文字符串
        // i==j dp[i][j] = true
        // dp[i][j] = dp[i - 1]dp[j - 1] && s[i] = s[j]
        for (int i = size - 1; i >= 0; i--) {
            for (int j = 0; j < size; j++) {
                if (i > j)
                    continue;
                if (s[i] == s[j] && (i + 1 > j - 1 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
            }
        }
    }
};


//87ms 91.32% 77.61MB 50.31%
class Solution {
public:
     vector<vector<string>> ans;
    vector<string> part;
    vector<vector<string>> partition(string s) {
        combination(s,0);
        return ans;
    }

    void combination(const string& s, int start)
    {
        if(start == s.size())
        {
            ans.push_back(part);
            return;
        }
        for (int i = 1; i < s.size() - start + 1; i++)
        {
            string str = s.substr(start,i);
            if(isHuiWen(str))
            {
                part.push_back(str);
                combination(s, start + i);
                part.pop_back();
            }
        }
    }

    bool isHuiWen(string str)
    {
        int left = 0;
        int right = str.size() - 1;
        while(left < right)
        {
            if(str[left++] != str[right--])
            {
                return false;
            }
        }
        return true;
    }
};



//101ms 87.62% 81.5MB 24%
class Solution {
public:
 vector<vector<string>> ans;
    vector<string> part;
    vector<vector<string>> partition(string s) {
        partitionT(s,0,0);
        return ans;
    }

    void partitionT(string s,int index,int len)
    {
        if(len == s.length())
        {
            ans.push_back(part);
        }else{
            for(int i = 1; i <= s.length() - len; i++)
            {
                string temp = s.substr(index,i);
                if(isHuiWen(temp))
                {
                    part.push_back(temp);
                    partitionT(s,index + i,len + i);
                    part.pop_back();
                }
            }
        }
    }

    bool isHuiWen(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
};