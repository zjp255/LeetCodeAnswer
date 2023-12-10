// 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

// 考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

// 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
// 返回 k 。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//468ms5.1% 18.2MB75.52%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] == nums[j])
                {
                    nums.erase(nums.begin() + j);
                    j--;
                }
            }
        }
        return nums.size();
    }
};
//8ms85.57%19.20MB5%
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool> hashmap;
        vector<int> ans;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(hashmap[nums[i]] == NULL)
            {
                hashmap[nums[i]] = true;
                ans.push_back(nums[i]);
            }
        }
        len = ans.size();
        for(int i = 0; i < len; i++)
        {
            nums[i] = ans[i];
        }
        return len;
    }
};
//双指针
//4ms98.02% 18.41MB23.60%
class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n  <= 1)
            return n;
        int first = 0,next = 1;
        while(next < n)
        {
            if(nums[first] != nums[next])
            {
                first++;
                nums[first] = nums[next];
            }
            next++;
        }
        return ++first;

    }
};