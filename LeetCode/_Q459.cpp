// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
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