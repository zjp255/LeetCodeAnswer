// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = s.length();
        char *arr = new char[length + 1];
        strcpy(arr, s.c_str());
        unordered_set<char> mySet;
        int count = 0;
        for (int i = 0; i <= length; i++)
        {
            if (arr[i] == '\0' || mySet.find(arr[i]) != mySet.end())
            {
                count < mySet.size() ? count = mySet.size() : true;
                i -= mySet.size();
                mySet.clear();
            }
            else
            {
                mySet.insert(arr[i]);
            }
        }
        return count;
    }
};

class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = s.length();
        char *arr = new char[length + 1];
        strcpy(arr, s.c_str());
        unordered_map<char, int> mymap;
        int count = 0;
        for (int i = 0; i <= length; i++)
        {
            auto it = mymap.find(arr[i]);
            if (arr[i] == '\0' || it != mymap.end())
            {
                count < mymap.size() ? count = mymap.size() : true;
                if (arr[i] != '\0')
                {
                    i = it->second;
                }
                mymap.clear();
            }
            else
            {
                mymap[arr[i]] = i;
            }
        }
        return count;
    }
};

class Solution3
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = s.length();
        char *arr = new char[length + 1];
        strcpy(arr, s.c_str());
        unordered_map<char, int> mymap;
        int count = 0;
        int tempCount = 0;
        int index = 0;
        for (int i = 0; i < length; i++)
        {
            auto it = mymap.find(arr[i]);
            if (it != mymap.end())
            {
                if (tempCount > count)
                {
                    count = tempCount;
                }
                if (it->second > index)
                    index = it->second;
                tempCount = -1 + (i - index);
            }
            tempCount++;
            mymap[arr[i]] = i;
        }
        if (tempCount > count)
        {
            count = tempCount;
        }
        return count;
    }
};