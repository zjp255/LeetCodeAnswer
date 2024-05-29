// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <stack>
using namespace std;
//0ms 100% 8.04MB 11%
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {   
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if(!st.empty()){
                if((s[i] == ')' && st.top() == '(') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{') )
                {
                    st.pop();
                }else{
                    return false;
                }
            }
            else
                return false;
        }
        return st.empty();
    }
};


//0ms100% 6.5MB61.69%
class Solution {
public:
    bool isValid(string s) {
    vector<char> stack;
        int len = s.length();
        unordered_map<char,char> hashMAP = {{'(',')'},{'{','}'},{'[',']'}};
        for(int i = 0; i < len; i++)
        {
            if(hashMAP[s[i]] == NULL)
            {
                if(stack.size() != 0 && hashMAP[stack.back()] == s[i])
                {
                    stack.pop_back();
                }
                else{
                    return false;
                }
            }else{
                stack.push_back(s[i]);
            }
        }
        if(stack.size() > 0)
        {
            return false;
        }
         return true;
    }
};