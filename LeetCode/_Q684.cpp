// 树可以看成是一个连通且 无环 的 无向 图。

// 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

// 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。

 #include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//3ms 88.33% 11.34MB 66.73%
class Solution {
public:
   int n = 0;
    vector<int> father;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        father = vector<int>(n + 1,0);
        vector<int> result;
        for (int i = 0; i <= n; i++)
        {
            father[i] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            int u = find(edges[i - 1][0]);
            int v = find(edges[i - 1][1]);
            if(u == v)
                result = edges[i - 1];
            else if(u != v)
                father[u] = v;
        }
        return result;
    }
    int find(int u)
    {
        return father[u] == u?u: father[u] = find(father[u]);
    }
};