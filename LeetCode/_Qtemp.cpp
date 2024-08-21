// 给定一个整数数组和一个目标值，找出数组中两个数, 
// 求和为目标值, 返回找到的两个数的索引, 不存在返回空值; 用C/Python/Java/PHP/Golang任意一种语言实现。


#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto temp = map.find(target - nums[i]);
            if(temp != map.end())
            {
                
                return {temp->second,i};
            }
            map.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};