// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//7ms 94.79% 9.87MB 63.64%
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         int record[26] = {0};
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过record数据记录 magazine里各个字符出现次数
            record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j]-'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
//19ms 21.90% 10.98MB 29.10%
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length())
        {
            return false;
        }
        unordered_map<char,int> map;
        for(char e : magazine)
        {
            map[e]++;
        }
        for(char e : ransomNote)
        {
            if(map.find(e) != map.end() && map[e] != 0)
            {
                map[e]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};