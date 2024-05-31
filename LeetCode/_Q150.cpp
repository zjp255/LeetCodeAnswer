// 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

// 请你计算该表达式。返回一个表示表达式值的整数。

// 注意：

// 有效的算符为 '+'、'-'、'*' 和 '/' 。
// 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
// 两个整数之间的除法总是 向零截断 。
// 表达式中不含除零运算。
// 输入是一个根据逆波兰表示法表示的算术表达式。
// 答案及所有中间计算结果可以用 32 位 整数表示。


#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <stack>
#include <sstream>
using namespace std;
//11ms 22.56% 15.07MB 88%
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        int temp = 0;
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i].length() == 1 && (tokens[i][0] < '0' || tokens[i][0] > '9'))
            {
                temp = st.top();
                st.pop();
                ans = st.top();
                st.pop();
                if(tokens[i] == "-")
                {
                    ans = ans - temp;
                }
                else if(tokens[i] == "+")
                {
                    ans = ans + temp;
                }
                else if(tokens[i] == "*")
                {
                    ans = ans * temp;
                }
                else if(tokens[i] == "/")
                {
                    ans = ans / temp;
                }
                st.push(ans);
            }else{
                stringstream cv;
                cv << tokens[i];
                int num;
                cv >> num;
                st.push(num);
            }
        }
        return st.top();
    }
};