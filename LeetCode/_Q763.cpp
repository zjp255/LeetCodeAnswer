// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

// 返回一个表示每个字符串片段的长度的列表

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 7.85MB 18.82%
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            last[s[i] - 'a'] = i; 
        }
        vector<int> ans;
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++)
        {
            end = max(end,last[s[i] - 'a']);
            if(i == end)
            {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};


//3ms 65.14% 9.17MB 5.11%
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> map;
        unordered_map<char,bool> temp;
        for(char a:s)
        {
            if(map[a] == NULL)
            {
                map[a] = 1;
            }else{
                map[a]++;
            }
            temp[a] == false;;
        }
        vector<int> ans;
        int count = 0;
        int last = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(temp[s[i]] == false)
            {
                count += map[s[i]] - 1;
                temp[s[i]] = true;
            }else{
                count--;
            }
            if(count == 0)
            {
                ans.push_back(i + 1 - last);
                last = i + 1;
            }
        }
        return ans;
    }
};