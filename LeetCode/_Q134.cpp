// 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

// 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//100ms 88.5% 127.41MB 40%
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int need = 0;
        int startNeed = 0;
        int ans = 0;
        for(int i = 0; i < gas.size();i++)
        {
            int temp = gas[i] - cost[i];
            need += temp;
            if(i == 0 || (temp >= 0 && gas[i - 1] - cost[i - 1] < 0))
            {
                if(startNeed < 0)
                {
                    ans = i;
                    startNeed = 0;
                }
            }
            startNeed += temp;
        }
        if(need >= 0)
        {
            return ans;
        }else{
            return -1;
        }
    }
};