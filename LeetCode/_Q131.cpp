// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

// 回文串 是正着读和反着读都一样的字符串。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
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