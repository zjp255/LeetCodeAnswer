// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 8.46MB 32%
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> record(26,0);
        for (int i = 0; i < s.length(); i++)
        {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if(record[i] != 0)
                return false;
        }
        return true;
    }
};



//4ms 82% 5% 9.66%
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;
        for (int i = 0; i < s.length(); i++)
        {
            sMap[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            tMap[t[i]]++;
        }
        for(pair<char,int> temp : sMap)
        {
            if(tMap[temp.first] == temp.second)
            {
                tMap.erase(temp.first);
            }else{
                return false;
            }
        }
        if( tMap.empty())
        {
            return true;
        }
        return false;
    }
};