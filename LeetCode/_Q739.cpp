// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，
// 请在该位置用 0 来代替。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
//110ms 91% 103MB 15%
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        vector<int> ans(temperatures.size(),0);
        stack.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            while( !stack.empty() && temperatures[i] > temperatures[stack.top()])
            {
                int index = stack.top();
                ans[index] = i - index;
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};