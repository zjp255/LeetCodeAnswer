// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while(left < right)
        {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);
            if(height[left] < height[right])
            {
                ans += maxLeft - height[left];
                left++;
            }else{
                ans += maxRight - height[right];
                right--;
            }
        }
        return ans;
    }
};




//单调递减的栈
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            while(!st.empty() && height[st.top()] < height[i]){
                int j = st.top();
                st.pop();
                if(!st.empty())
                {
                    int x = st.top();
                    if(height[x] == height[j])
                        continue;
                    ans += (min(height[i], height[x]) - height[j]) * (i - j);
                }
            }
        }
        return ans;
    }
};







//7ms 90% 22.63mb 37.4%
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            while(!st.empty() && height[st.top()] < height[i]){
                int j = st.top();
                st.pop();
                if(!st.empty())
                {
                    int x = st.top();
                    if(height[x] == height[j])
                        continue;
                    ans += (min(height[i], height[x]) - height[j]) * (i - x  - 1);
                }
            }
            st.push(i);
        }
        return ans;
    }
};