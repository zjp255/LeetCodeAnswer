// n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

// 你需要按照以下要求，给这些孩子分发糖果：

// 每个孩子至少分配到 1 个糖果。
// 相邻两个孩子评分更高的孩子会获得更多的糖果。
// 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//11ms 93% 19.64MB 20% 
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(),1);
        int ans = 0;
        if(ratings.size() > 1 && ratings[0] > ratings[1])
        {
            candy[0]++;
        }
        for(int i = 0; i < ratings.size();i++)
        {
            if(i > 0 && ratings[i - 1] < ratings[i])
            {
                    candy[i] = candy[i - 1] + 1;
            }
        }
        for(int i = ratings.size() - 1; i >= 0;i--)
        {
            if(i < ratings.size() - 1 && ratings[i] > ratings[i + 1])
            {
                if(candy[i] <= candy[i + 1])
                {
                    candy[i] = candy[i + 1] + 1;
                }
            }
            ans += candy[i];
        }

        return ans;
    }
};