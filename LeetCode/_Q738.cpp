// 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

// 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//2ms 32.65% 7.22MB 17.67%
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
          vector<int> ans;
        int t = 0;
        int x = 0;
        while(n > 0)
        {
            ans.push_back(n %  10);
            n /= 10;
        }
        for(int i = 0; i < ans.size();i++)
        {
            if(i < ans.size() - 1)
            {
                if(ans[i] < 0)
                {
                    ans[i] = 9;
                    ans[i + 1] -= 1;
                }
                while(ans[i] < ans[i + 1])
                {
                    ans[i]--;
                    if(ans[i] < 0)
                    {
                        ans[i] = 9;
                        ans[i + 1] -= 1;
                    }
                }
            }
        }
        for(int i = ans.size() - 1; i >= 0;i--)
        {
            if(i < ans.size() - 1)
            {
                while(ans[i] < ans[i + 1])
                {
                    ans[i]++;
                }
            }
            t = t * 10 + ans[i];
        }
        return t;
    }
};