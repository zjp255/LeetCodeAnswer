// nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

// 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

// 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，
// 并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

// 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
//单调栈
//4ms 69.48% 11.88MB 29.49%
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans(nums1.size(),-1);
        if(nums1.size() == 0)
        {
            return ans;
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]] = i;
        }
        stack<int> st;
        st.push(nums2[0]);
        for (int i = 1; i < nums2.size(); i++)
        {
            while( !st.empty() && nums2[i] > st.top())
            {
                int temp = st.top();
                st.pop();
                if(mp.count(temp) != 0)
                {
                    ans[mp[temp]] = nums2[i];
                }
            }
            st.push(nums2[i]);
        }
        return ans;
    }

     
};

int main(int argc, char const *argv[])
    {
        vector<int> num1 = {2,4};
        vector<int> num2 = {1,2,3,4};
        (new Solution())->nextGreaterElement(num1,num2);
        return 0;
    }

//暴力解决
//10ms 13% 10.51MB 83%
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        bool start = false;
        for (int i = 0; i < nums1.size(); i++)
        {
            start = false;
            for (int j = 0; j < nums2.size(); j++)
            {
                if(nums2[j] == nums1[i])
                {
                    start = true;
                    continue;
                }
                if(start && nums2[j] > nums1[i])
                {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }

   
    
};