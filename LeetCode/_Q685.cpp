// 在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。

// 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n 中的两个不同顶点间，这条附加的边不属于树中已存在的边。

// 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 vi 的一个父节点。

// 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。


#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 12.29Mb 79%
class Solution {
public:
    vector<int> father;
    int n = 0;
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        father = vector<int>(n + 1);
        vector<int> inDgree(n + 1,0);
        for (int i = 0; i < n; i++)
        {
            inDgree[edges[i][1]]++;
        }
        
        vector<int> vec;

        for (int i = n - 1; i >= 0; i--)
        {
            if(inDgree[edges[i][1]] == 2)
            {
                vec.push_back(i);
            }
        }

        if(vec.size() > 0)
        {
            if(isTree(edges,vec[0]))
            {
                return edges[vec[0]];
            }else{
                return edges[vec[1]];
            }
        }

        return removeEdge(edges);
        
    }

    int find(int u)
    {
        return u == father[u]?u:father[u] = find(father[u]);
    }

    bool isTree(vector<vector<int>>& edges, int deleteEdge)
    {
        for (int i = 0; i <= n; i++)
        {
            father[i] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            if(i == deleteEdge + 1)
                continue;
            int u = find(edges[i - 1][0]);
            int v = find(edges[i - 1][1]);
            if(u == v) return false;
            father[v] = u;
        }
        return true;
    }

    vector<int> removeEdge(vector<vector<int>>& edges)
    {
        for (int i = 0; i <= n; i++)
        {
            father[i] = i;
        }
        
        for (int i = 1; i <= n; i++)
        {
            int u = find(edges[i - 1][0]);
            int v = find(edges[i - 1][1]);
            if(u == v) return edges[i - 1];
            father[v] = u;
        }
        return {};
    }
};