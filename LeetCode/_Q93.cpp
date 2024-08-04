// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 10.16MB 33.27%
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        combination(s, 0, 0, "");
        return ans;
    }

    void combination(const string& s, int start, int count, string part) {
        if (start == s.size() && count == 4) {
            ans.push_back(part);
            return;
        }
        else if(start >= s.size() || count > 4)
        {
            return;
        }
        if (part.size() > 0)
            part += ".";
        for (int i = 1; i < 4; i++) {
            string str = s.substr(start, i);
            if (str[0] == '0' && str.size() > 1)
                return;
            int num = stringToInt(str);
            if (num > 255)
                continue;
            combination(s, start + i, count + 1, part + str);
        }
    }

    int stringToInt(string str) {
        int temp = 0;
        for (int i = 0; i < str.size(); i++) {
            temp = temp * 10 + str[i] - '0';
        }
        return temp;
    }
};





//0ms 100% 10.19Mb 10%
class Solution {
public:
    vector<string> ans;
    unordered_map<char,int> hashMap = {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
    vector<string> part;
    vector<string> restoreIpAddresses(string s) {
        combine(s,0);
        return ans;
    }

    void combine(string s,int index)
    {
        if(part.size() == 4 && index == s.length())
        {
            ans.push_back(part[0] + "." + part[1] + "." + part[2] + "." + part[3]);
        }else if(part.size() < 4)
        {
            for(int i = 1; i <=  (s.length() - index >= 3?3:s.length() - index); i++)
            {
                if(i == 3)
                {
                    int temp = hashMap[s[index]] * 100 + hashMap[s[index + 1]] * 10 + hashMap[s[index + 2]];
                    if(temp > 255)
                    {
                        break;
                    }
                }
                part.push_back(s.substr(index,i));
                combine(s,index + i);
                part.pop_back();
                if(i == 1 && s[index] == '0')
                {
                    break;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    s.restoreIpAddresses("25525511135");
}