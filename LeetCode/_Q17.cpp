// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
//0ms 100% 8.55Mb 9.87% 
class Solution {
public:
vector<string> ans;
    vector<string> ans;
    unordered_map<char,string> hashTable = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"qprs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return ans;
        combinations(digits, 0, "");
        return ans;
    }
    void combinations(const string& digits, int index, const string& temp)
    {
        if(index == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string charS = hashTable[digits[index]];
        for (int i = 0; i < charS.size(); i++)
        {
            combinations(digits,index + 1, temp + charS[i]);
        }   
    }
};



//0ms 100% 8.39Mb 16.18%
class Solution {
public:
    vector<string> ans;
    unordered_map<char,string> hashTable = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"qprs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        combination(digits, 0);
        return ans;
    }

    void combination(string digits, int index)
    {
        if(index >= digits.size())
            return;
        string temp = hashTable[digits[index]];
        if(ans.size() == 0)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                string s;
                s.push_back(temp[i]);
                ans.push_back(s);
            }
        }
        else
        {
            vector<string> tempAns;
            for (int i = 0; i < temp.size(); i++)
            {
                for(int j = 0; j < ans.size(); j++)
                {
                    tempAns.push_back(ans[j] + temp[i]);
                }
            }
            ans = tempAns;
        }
        combination(digits, index + 1);
    }
};


//0ms 100% 6.74mb59.91%
//暴力循环
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        unordered_map<char,string> hashTable = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"qprs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ans;
        for(int i = 0; i < len; i++)
        {
            string temp = hashTable[digits[i]];
            if(ans.size() == 0)
            {
                for(int j = 0;j < temp.size(); j++)
                {
                    string a;
                    a.push_back(temp[j]);
                    ans.push_back(a);
                }
            }
            else{
                int tempLen = ans.size();
                for(int j = 0;j < temp.size(); j++)
                {
                    for(int x = 0; x < tempLen; x++)
                    {
                        ans.push_back(ans[x] + temp[j]);
                    }
                }
                ans.erase(ans.begin(),ans.begin() + tempLen);
            }
        }
        return ans;
    }
};


//使用递归的解法
//0ms 100% 6.81mb42.09%
class Solution1 {
public:
    unordered_map<char,string> hashTable = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"qprs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
      int len = digits.size();
      if(len == 0)
      {
          return {};
      }
      return DEF(digits,0);
    }

    vector<string> DEF(string digits, int index)
    {
        vector<string> temp;
        if(index < digits.size() -1)
            temp = DEF(digits, index + 1);
        if(temp.size() == 0)
        {
            string a = hashTable[digits[index]];
            for(int i = 0; i < a.size(); i++)
            {
                string b;
                b.push_back(a[i]);
                temp.push_back(b);
            }
        }else{
            string a = hashTable[digits[index]];
            int len = temp.size();
            for(int i = 0; i < a.size(); i++)
            {     
                for(int j = 0; j < len; j++)
                   {
                    string b;
                    b.append(temp[j]);
                    b.insert(b.begin(), a[i]);
                    temp.push_back(b);
                   }
            }
            temp.erase(temp.begin(), temp.begin() + len);
        }
        return temp;
    }
};
int main()
{
    Solution1 s;
    vector<string> ans = s.letterCombinations("23");
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}