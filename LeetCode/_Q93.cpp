// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    vector<string> ans;
    unordered_map<char,int> hashMap = {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
    string part;
    string part2;
    vector<string> restoreIpAddresses(string s) {
        combine(s,0,0);
        return ans;
    }

    void combine(string s,int size,int index)
    {
        if(index == s.length())
        {
            ans.push_back(temp);
        }else{
            for(int i = 1; i <= s.length() - index >= 3?3:s.length() - index; i++)
            {
                int tempInt = 0;
                while(temp.length() < size + i)
                {
                    temp += s[index];
                    tempInt = tempInt * 10 + hashMap[s[index]]; 
                    index++;
                    cout<<index<<endl;
                }
                if(index != s.length())
                {
                    temp += '.';
                }
                if(count > 3)
                {
                    break;
                }
                if(tempInt > 255 || ( i > 1 && hashMap[s[index - i]] == '0'))
                {
                    break;
                }
                combine(s,size + i + 1,index);
                while(temp.length() > size)
                {
                    temp.pop_back();
                    index--;
                    cout<<index<<endl;
                }
                index++;
            }
        }
    }
};

int main()
{
    Solution s;
    s.restoreIpAddresses("25525511135");
}