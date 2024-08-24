// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//15ms 99.15% 21.99Mb 96.53%
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> myMap;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(myMap.find(temp) != myMap.end())
            {
                ans[myMap[temp]].push_back(strs[i]);
            }
            else{
                myMap[temp] = ans.size();
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};