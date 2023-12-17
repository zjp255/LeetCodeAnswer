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


//超时
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> words) {
        unordered_map<string,int> hashMap;
        unordered_map<string,unordered_map<int,int>> nextMap;
        int wordsLen = words.size();
        int sLen = s.length();
        int wLen = words.size();
        int wordLen = words[0].length();
        vector<int> ans;
        for(int i = 0; i < wordsLen; i++)
        {
            hashMap[words[i]] += 1;
        }

        for(int i = 0 ; i < wLen; i++)
        {
            int index1 = 1;
            int index2 = 0;
            int index3 = 0;
            while(index2 < wLen)
            {
                if(index2 == i)
                {
                    index2++;
                    continue;
                }
                if(words[i][index1] == words[index2][index3])
                {
                    index1++;
                    index3++;
                    if(index1 == wordLen)
                    {
                        nextMap[words[i]][index1 - index3] = index2;
                        index1 = 1;
                        index3 = 0;
                    }
                }
                else{
                    index1 += 1;
                    index3 = 0;
                    if(index1 == wordLen)
                    {
                        index1 = 1;
                    }
                }
            }   

        }


        for(int i = 0; i < sLen; i++)
        {
            unordered_map<string,int> temp = hashMap;   
            for(int j = 0; j < wLen; j++)
            {
                string tempS = s.substr(i + j * wordLen, wordLen);
                if(temp[tempS] > 0)
                {
                    temp[tempS] -= 1;
                    if(j == wLen - 1)
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



//滑动窗口法
//68ms 67.41% 38MB 24.60%
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> wordCount;
        int sLen = s.length();
        int wLen = words.size();
        int wordLen = words[0].length();
        int windowSize = wLen * wordLen;
        vector<int> ans;
        for(int i = 0; i < wLen; i++)
        {
            wordCount[words[i]] -= 1;
        }

        for(int i = 0; i < wordLen; i++)
        {
            unordered_map<string,int> tempWordCount = wordCount;
            for(int j = 0; j < wLen; j++)
            {
                string temp = s.substr(i + j * wordLen,wordLen);
                if(++tempWordCount[temp] == 0)
                {
                    tempWordCount.erase(temp);
                }
            }
            for(int j = i; j <= sLen - windowSize; j += wordLen)
            {
                if(tempWordCount.empty())
                {
                    ans.push_back(j);
                }
                string temp = s.substr(j,wordLen);
                if(--tempWordCount[temp] == 0)
                {
                    tempWordCount.erase(temp);
                }
                temp = s.substr(j + windowSize,wordLen);
                if(++tempWordCount[temp] == 0)
                {
                    tempWordCount.erase(temp);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> temp = {"foo","bar"};
    s.findSubstring("barfoothefoobarman", temp);
}