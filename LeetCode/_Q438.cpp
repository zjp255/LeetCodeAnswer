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
//3ms 99.17% 9.91Mb 72%
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen)
            return {};
        int eff = 0;
        int left = 0;
        vector<int> used = vector<int>(26, -1);
        vector<int> ans;
        for (char temp : p) {
            if (used[temp - 'a'] == -1)
                used[temp - 'a'] = 0;
            used[temp - 'a']++;
        }
        for (int i = 0; i < sLen; i++) {
            if (used[s[i] - 'a'] > 0) {
                used[s[i] - 'a']--;
                eff++;
            } else if (used[s[i] - 'a'] == 0) {
                while (s[left] != s[i]) {
                    if (used[s[left] - 'a'] != -1) {
                        used[s[left] - 'a']++;
                        eff--;
                    }
                    left++;
                }
                left++;
            }

            if (i - left > pLen - 1) {
                if (used[s[left] - 'a'] != -1) {
                    used[s[left] - 'a']++;
                    eff--;
                }
                left++;
            }

            if (eff == pLen)
                ans.push_back(left);
        }
        return ans;
    }
};


//8ms 77.59% 11.03MB 29.82%
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
                } else {
                    while (s[left] != s[i]) {
                        if (myMap.find(s[left]) != myMap.end()) {
                            myMap[s[left]]++;
                            eff--;
                        }
                        left++;
                    }
                    left++;
                }
            }
            if (i - left > k - 1) {
                if (myMap.find(s[left]) != myMap.end()) {
                    myMap[s[left]]++;
                    eff--;
                }
                left++;
            }
            if (eff == k && i - left == k - 1) {
                ans.push_back(left);
            }
        }
        return ans;
    }
};