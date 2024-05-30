// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

// 在 S 上反复执行重复项删除操作，直到无法继续删除。

// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack> 
using namespace std;
//14ms 88% 11.52MB 97%
class Solution {
public:
    string removeDuplicates(string s) {
         string result;
        for (int i = 0; i < s.length(); i++)
        {
            if(result.empty() == false && s[i] == result.back())
            {
                result.pop_back();
                continue;
            }
            result.push_back(s[i]);
        }
        return result;
    }
};


//107ms 8.3% 11.61MB 96%
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if(st.size() == 0)
            {
                st.push(s[i]);
                continue;
            }
            if(s[i] == st.top())
            {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        s = "";
        while(!st.empty())
        {
            s.insert(0,1,st.top());
        }
        return s;
    }
};