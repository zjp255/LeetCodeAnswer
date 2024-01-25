// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案。

 
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
 vector<vector<int>> ans;
    vector<int> part;

    vector<vector<int>> combine(int n, int k) {
        for(int i = 0; i < k;i++)
        {
            part.push_back(0);
        }
        combines(1,0,n,k);
        return ans;
    }

    void combines(int start,int tempk,int n, int k)
    {
        for(int i = start; i <= n; i++)
        {
            part[tempk] = i;
            if(tempk == k - 1)
            {
                ans.push_back(part);
            }
            else{
                combines(i + 1,tempk + 1,n,k);
            }
        }
    }
};