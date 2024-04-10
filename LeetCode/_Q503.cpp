// 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），
// 返回 nums 中每个元素的 下一个更大元素 。

// 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，
// 这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
//16ms 96% 25.93mb 68%
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        st.push(0);
        for(int i = 1; i < nums.size() * 2; i++)
        {
            int temp = i % nums.size();
            while ( !st.empty() && nums[temp] > nums[st.top()])
            {
                ans[st.top()] = nums[temp];
                st.pop();
            }
            st.push(temp);
        }
        return ans;
    }
};