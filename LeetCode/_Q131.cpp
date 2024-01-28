// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

// 回文串 是正着读和反着读都一样的字符串。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
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