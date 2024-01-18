//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//0ms 100% 8.38MB 5%
class Solution {
public:
    int longestValidParentheses(string s) {
     vector<int> stack;
        int len = s.length();
        int ans = 0;
        stack.push_back(-1);
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                stack.push_back(i);
            }
            else{
                if( stack.size() > 1)
                {
                    stack.pop_back();
                    if(i - stack.back() > ans)
                    {
                        ans = i - stack.back();
                    }
                }
                else{
                    stack.clear();
                    stack.push_back(i);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.longestValidParentheses(")()())");
}