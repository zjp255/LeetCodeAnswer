// 给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

//  s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

// 例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 

// "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。

// 返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,bool> hashMap;
        int wordsLen = words.size();
        int sLen = s.length();
        int wLen = words.size();
        int wordLen = words[0].length();
        vector<int> ans;
        for(int i = 0; i < wordsLen; i++)
        {
            hashMap[words[i]] = true;
        }

        for(int i = 0; i < sLen; i++)
        {
            unordered_map<string,bool> temp = hashMap;
            
            for(int j = 0; j < wLen; j++)
            {
                string tempS = s.substr(i + j * wordLen, wordLen);
                if(temp[tempS] == true)
                {
                    temp[tempS] = false;
                    if(j == sLen - 1)
                    {
                        ans.push_back(i);
                    }
                }
                else{
                    break;
                }
            }
            
        }
        return ans;
        
    }
};