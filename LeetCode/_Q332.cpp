// 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

// 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

// 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
// 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//11ms 94.66% 17.6MB 43.71%
class Solution {
public:
    unordered_map<string ,map<string, int>> myMap;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++)
        {
            myMap[tickets[i][0]][tickets[i][1]] += 1;
        }
        ans.push_back("JFK");
        combination(tickets);
        return ans;
    }

    bool combination(const vector<vector<string>>& tickets)
    {
        if(ans.size() == tickets.size() + 1)
        {
            return true;
        }
        map<string, int>& destination = myMap[ans.back()];
        for(pair<const string, int>& temp : destination)
        {
            if(temp.second >= 1)
            {
                temp.second -= 1;
                ans.push_back(temp.first);
                if(combination(tickets)) return true;
                ans.pop_back();
                temp.second += 1;
            }
        }
        return false;
    }
};


//82ms 5.14% 37.19MB 5.02%
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> part;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used = vector(tickets.size(), false);
        part.push_back("JFK");
        sort(tickets.begin(), tickets.end(), cmp);
        combination(tickets, used, 0);
        return ans[0];
    }
    static bool cmp(vector<string> a, vector<string> b) {
        if (a[1].compare(b[1]) == 0) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    void combination(const vector<vector<string>>& tickets, vector<bool>& used,
                     int start) {
        if (part.size() == tickets.size() + 1) {
            ans.push_back(part);
            return;
        }
        unordered_map<string, bool> map;
        for (int i = start; i < tickets.size(); i++) {
            if (ans.size() >= 1) {
                return;
            }
            if (used[i] || map.count(tickets[i][1]) != 0 || tickets[i][0].compare(part.back()) != 0)
                continue;
            part.push_back(tickets[i][1]);
            used[i] = true;
            map[tickets[i][1]] = true;
            combination(tickets, used, 0);
            used[i] = false;
            part.pop_back();
        }
    }
};






//无法通过测试
class Solution {
public:
   vector<vector<string>> ans;
    vector<string> part;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(),false);
        combine(tickets,0,used);
        int ansIndex = 0;
        bool isBroke = false;
        if(tickets.size() > 2)
        {
            for(int i = 0; i < ans[0].size() * 3; i++)
            {
                for(int j = 0; j < ans.size();j++)
                {                
                    if(ans[j][i / 3][i % 3] <= ans[ansIndex][i / 3][i % 3] )
                    {
                        ansIndex = j;
                        isBroke = true;
                    }
                }
                if(isBroke == true)
                {
                    break;
                }
            }
        }
        
        return ans[ansIndex];
    }

    void combine(vector<vector<string>>& tickets,int usedCount,vector<bool>& used)
    {
        if(usedCount < tickets.size())
        {
            for(int i = 0; i < tickets.size(); i++)
            {
                if(part.size() > 0)
                {
                    if(tickets[i][0] != part.back() || used[i] == true)
                    {
                        continue;
                    }
                    part.push_back(tickets[i][1]);
                    used[i] = true;              
                    combine(tickets,usedCount + 1,used);
                    used[i] = false;
                    part.pop_back();
                }else{
                    part.push_back(tickets[i][0]);
                    part.push_back(tickets[i][1]);
                    used[i] = true;
                    combine(tickets,usedCount + 1,used);
                    used[i] = false;
                    part.pop_back();
                    part.pop_back();
                }
            }
        }
        else{
            ans.push_back(part);
        }
    }
};
//18ms 17.1MB17.77%
class Solution1 {
public:
    vector<string> ans;
    unordered_map<string,map<string,int>> map;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0; i < tickets.size(); i++)
        {
            map[tickets[i][0]][tickets[i][1]]++;
        }
        ans.push_back("JFK");
        combine(tickets.size());
        return ans;
    }

    bool combine(int ticketsSize)
    {
        if(ans.size() == ticketsSize + 1)
        {
            return true;
        }else{
            for(pair<const string,int>& element : map[ans.back()])
            {
                if(element.second > 0)
                {
                    ans.push_back(element.first);
                    element.second--;
                    if(combine(ticketsSize)) return true;
                    element.second++;
                    ans.pop_back();
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> tickets;
    tickets = {{"JFK","ATL"},{"ORD","PHL"},{"JFK","ORD"},{"PHX","LAX"},{"LAX","JFK"},{"PHL","ATL"},{"ATL","PHX"}};
    vector<string> result = s.findItinerary(tickets);
    return 0;
}