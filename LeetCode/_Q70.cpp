// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 7MB 20%
class Solution {
public:
    int climbStairs(int n) {
       if(n == 1)
        {
            return 1;
        }
        if(n == 2)
        {
            return 2;
        }
        int a = 1, b = 2, c = 0;
        for(int i = 3; i <= n; i++)
        {
            c = b + a;
            a = b;
            b = c;
        }
        return c;
    }
};

//超时
class Solution {
public:
    int ans = 0;
    int climbStairs(int n) {
        combine(n);
        return ans;
    }

    void combine(int n)
    {
        if(n == 0)
        {
            ans++;
            return;
        }
        if(n < 0)
        {
            return;
        }
        for(int i = 1; i <= 2; i++)
        {
            combine(n - i);
        }
    }
};