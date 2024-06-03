// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <deque>
#include <queue>
using namespace std;
//10ms 72.73% 16.67MB
class Solution {
public:
    class mycomparison{
        public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for (int i = 0; i < nums.size(); i++){
                mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { 
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
        
    }
};