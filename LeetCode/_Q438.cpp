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
        int k = p.size();
        int eff = 0;
        int left = 0;
        vector<int> ans;
        for (char a : p) {
            myMap[a]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (myMap.find(s[i]) != myMap.end()) {
                if (myMap[s[i]] > 0) {
                    eff++;
                    myMap[s[i]]--;
                }else{
                    while(s[left] != s[i]){
                        if(myMap.find(s[left]) != myMap.end()){
                             myMap[s[left]]++;
                             eff--;
                        }
                        left++;
                    }
                    if(myMap.find(s[left]) != myMap.end()){
                        myMap[s[left]]++;
                        eff--;
                    }
                    left++;
                }
            }
            else{
                if(i - left > k - 1 && myMap.find(s[left]) != myMap.end())
                {
                    myMap[s[left]]++;
                    eff--;
                    left++;
                }
            }
            if (eff == k && i - left == k - 1)
            {
                ans.push_back(left);
            }
        }
        return ans;
    }
};