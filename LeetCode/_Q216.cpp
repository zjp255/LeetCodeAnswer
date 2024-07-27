// 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

// 只使用数字1到9
// 每个数字 最多使用一次 
// 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> combinationSum3(int k, int n) {
        combination(k, n, 1, 0);
        return ans;
    }
    //0ms 100% 7.93Mb 43.96%
    void combination(int k, int n, int start, int sum)
    {
        if(part.size() == k && sum == n)
        {
            ans.push_back(part);
            return;
        }
        for(int i = start; i <= 9; i++)
        {
            if(9 - i + 1< k - part.size() || sum > n || part.size() > k)
                return;
            part.push_back(i);
            combination(k,n,i+1,sum + i);
            part.pop_back();
        }
    }
};







//0ms 100% 7.6MB 7.8%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> part;
    vector<vector<int>> combinationSum3(int k, int n) {
        combin(n,k,0,1);
        return ans;
    }

    void combin(int n, int k, int sum,int start)
    {
        if(part.size() == k)
        {
            if(sum == n)
            {
                ans.push_back(part);
            }
        }else{
            for(int i = start; i <= 9 - (k - part.size()) + 1; i++)
            {
                if(sum > n)
                {
                    break;
                }
                if(part.size() < k)
                {
                    part.push_back(i);
                    combin(n,k,sum + i,i + 1);
                    part.pop_back();
                }
                else if(part.size() == k)
                {
                    if(sum == n)
                    {
                        ans.push_back(part);
                        break;
                    }
                    break;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    s.combinationSum3(3,7);

    return 0;
}