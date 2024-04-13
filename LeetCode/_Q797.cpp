// 给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

//  graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

 #include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//3ms 98.83% 14.24MB 21.97%
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> used;
        dfs(0,used,graph);
        return ans;
    }

    void dfs(int graphIndex, vector<int>& used, vector<vector<int>>& graph)
    {
        used.push_back(graphIndex);
        for (int i = 0; i < graph[graphIndex].size(); i++)
        {
            dfs(graph[graphIndex][i],used,graph);
            used.pop_back();
        }
        if(graphIndex == graph.size() - 1)
        {
            ans.push_back(used);
            return;
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution sl;
    vector<vector<int>> graph ={{1,2},{3},{3},{}};
    sl.allPathsSourceTarget(graph);
    return 0;
}
