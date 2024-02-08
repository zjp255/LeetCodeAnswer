// 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

// 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

// 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
// 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(),false);
        combine(tickets,0,used);
        return ans;
    }

    void combine(vector<vector<string>>& tickets,int usedCount,vector<bool>& used)
    {
        if(usedCount < tickets.size())
        {
            for(int i = 0; i < tickets.size(); i++)
            {
                if(ans.size() > 0)
                {
                    if(tickets[i][0] != ans.back() || used[i] == true)
                    {
                        continue;
                    }
                    ans.push_back(tickets[i][1]);
                    used[i] = true;
                    combine(tickets,usedCount + 1,used);
                    used[i] = false;
                    ans.pop_back();
                }else{
                    ans.push_back(tickets[i][0]);
                    ans.push_back(tickets[i][1]);
                    used[i] = true;
                    combine(tickets,usedCount + 1,used);
                    used[i] = false;
                    ans.pop_back();
                    ans.pop_back();
                }
            }
        }
    }
};