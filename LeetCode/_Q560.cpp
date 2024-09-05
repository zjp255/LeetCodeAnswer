// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


//60ms 82.52% 44.27Mb 57.23%
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> myMap;
        myMap[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(myMap.find(sum - k) != myMap.end()){
                ans += myMap[sum - k];
            } 
            myMap[sum]++;
        }
        return ans;
    }
};

//超时
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for(int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if(sum == k)
                    ans++;
            }
        }
        return ans;
    }
};