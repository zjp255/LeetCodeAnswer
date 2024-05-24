// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//KMP
//15ms 72.76% 13.64MB 25.35%
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next = kmp(s);
        
        int len = s.length();

        if(next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
        {
            return true;
        }
        return false;
    }

    vector<int> kmp(string& s)
    {
        vector<int> next(s.length(),0);
        int index = 0;
        for (int i = 1; i < s.length(); i++)
        {
            while(index > 0 && s[i] != s[index])
                index = next[index - 1];
            if(s[i] == s[index])
            {
                next[i] = index + 1;
                index++;
            }
        }
        return next;
    }
};


//13ms 88.53% 12.83MB 50.96%
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s + s;
        temp.erase(temp.begin());
        temp.erase(temp.end());
        if( temp.find(s) != temp.npos)
            return true;
        else
            return false;
    }
};