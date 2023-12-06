// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
//4ms70.77% 7.98MB91.79%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string sem = "()";
        vector<string> ans;
        unordered_map<string,bool> hashMAP;
        for(int i = 0; i < n; i++)
        {
            int len = ans.size();
            for(int j = 0; j < len; j++)
            {
                int slen = ans[j].length();
                for(int x = 0; x < slen; x++)
                {
                    string temp = ans[j];
                    temp.insert(x, sem);
                    if(hashMAP[temp] == NULL)
                    {
                        ans.push_back(temp);
                        hashMAP[temp] = true;
                    }
                }
            }
            if(len == 0)
            {
                ans.push_back(sem);
            }
            ans.erase(ans.begin(),ans.begin() + len);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(3);
}