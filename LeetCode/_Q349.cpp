// 给定两个数组 nums1 和 nums2 ，返回 它们的 
// 交集
//  。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;
//0ms 100% 13.93Mb 75%
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            set1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if(set1.count(nums2[i]) != 0)
            {
                ans.push_back(nums2[i]);
                set1.erase(nums2[i]);
            }
        }
        return ans;
    }
};