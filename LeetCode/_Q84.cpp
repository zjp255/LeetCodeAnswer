// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
//102ms 76% 77.80MB 71%
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //vector<int> result(heights.size(), -1);
        int ans = 0;
        stack<int> st;
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        st.push(0);
        for (int i = 1; i < heights.size(); i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int temp = 0;
                int mid = st.top();
                st.pop();
                int left = st.top();
                temp = (i - left  -  1) * heights[mid];
                if(temp > ans)
                {
                    ans = temp;
                }
            }
            st.push(i);
        }
        return ans;
    }
};