// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//167ms 68% 27.48MB 76%
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        for(int a:nums1)
        {
            for(int b : nums2)
            {
                map[a + b]++;
            }
        }
        int count = 0;
        for(int c : nums3)
        {
            for(int d : nums4)
            {
                if(map.find(0 - c -d) != map.end())
                    count += map[0 - c - d];
            }
        }
        return count;
    }
};