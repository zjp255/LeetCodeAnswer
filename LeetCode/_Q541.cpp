// 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
//3ms 84% 8.42MB 16.36%
class Solution {
public:
    string reverseStr(string s, int k) {
        bool isReverse = true;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(isReverse == true)
            {
                int left = i, right = i + k - 1;
                right = right > s.size() - 1?s.size() - 1: right; 
                while(left < right)
                {
                    char temp = s[right];
                    s[right] = s[left];
                    s[left] = temp;
                    left++;
                    right--;
                }
                isReverse = false;
                count = 0;
                i = i + k - 1;
            }
            else{
                count++;
                if(count == k)
                    isReverse = true;
            }
        }
        return s;
    }
};