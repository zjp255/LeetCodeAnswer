// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> myMap;
        int k = 0;
        int eff = 0;
        int left = 0;
        vector<int> ans;
        for (char a : p)
        {
            myMap[a] = 1;
        }
        
        for (int i = 0; i < s.size(); i++){
            if(k == 3){
                 if(eff == 3)
                    ans.push_back(i - 3);
                if(myMap.find(s[i]) == myMap.end()){
                    eff--;
                }else{
                    if(myMap[s[i]] == 1){
                        eff++;
                        myMap[s[i]]--;
                    }
                }
                if(myMap.find(s[i - 3]) != myMap.end()){
                    eff--;
                    myMap[s[i - 3]] = 1;
                }
            }
            else{
                k++;
                if(myMap.find(s[i]) == myMap.end()){
                    eff--;
                }else{
                    eff++;
                }
            }
        }
        return ans;
    }
};