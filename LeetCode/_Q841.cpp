// 有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。

// 当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。

// 给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。如果能进入 所有 房间返回 true，否则返回 false。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;
//0ms 100% 13.30Mb 67.12%
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visit(rooms.size(),false);
        queue<int> que;
        int count = 0;
        que.push(0);
        while(!que.empty())
        {
            int index = que.front();que.pop();
            if(visit[index] == false)
            {
                count++;
                visit[index] = true;
                for (int i = 0; i < rooms[index].size(); i++)
                {
                    que.push(rooms[index][i]);
                }
            }
        }
        if(count == visit.size())
            return true;
        else
            return false;
    }        
    
};
