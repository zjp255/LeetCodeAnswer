// 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

// 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;
//21ms 95% 16MB 23%
class Solution1 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp_secend);
        list<vector<int>> ans;
        for(int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            std::list<vector<int>>::iterator it = ans.begin();
            while (pos--) { // 寻找在插入位置
                it++;
            }
            ans.insert(it, people[i]);
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }

    static bool cmp_secend(vector<int>& x,vector<int>& y)
    {
        if(x[0] == y[0])
        {
            return x[1] < y[1];
        }else{
            return x[0] > y[0];
        }
    }
};


//42ms 56.93% 14.91MB 36.46%
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp_secend);
        vector<vector<int>> ans;
        ans.push_back(people[0]);
        for(int i = 1; i < people.size(); i++)
        {
            int count = 0;
            for(int j = 0; j < ans.size(); j++)
            {
                if(ans[j][0] >= people[i][0])
                {
                    count++;
                }
                 if(count == people[i][1])
                {
                    if(j + 1 < ans.size() && people[i][0] > ans[j + 1][0])
                        continue;
                    ans.insert(ans.begin() + j + 1,people[i]);
                    break;
                }   
            }
        }
        return ans;
    }

    static bool cmp_secend(vector<int>& x,vector<int>& y)
    {
        if(x[1] != y[1])
        {
            return x[1] < y[1];
        }else{
            return x[0] < y[0];
        }
    }
};

int main()
{
    Solution s;
     vector<vector<int>> temp = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    s.reconstructQueue(temp);

}