// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
//117ms 83.97% 73MB 29.42%
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mySet.insert(nums[i]);
        }

        for(int num : mySet)
        {
            if(!mySet.count(num - 1))
            {
                int tempCount = 1;
                while (mySet.count(++num))
                {
                    tempCount++;
                }
                if(tempCount > ans)
                    ans = tempCount;
            }
        }
        return ans;
    }
};