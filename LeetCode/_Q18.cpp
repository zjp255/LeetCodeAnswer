// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 你可以按 任意顺序 返回答案 。

#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
//96ms 23.15% 13.18mb 63.98%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
         int len = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < len - 3; i++)
        {
             if(i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
            for(int j = i + 1; j < len -2; j++)
            {
                if(j > i + 1 && nums[j - 1] == nums[j])
                {
                    continue;
                }
                int left = j + 1;
                int right = len - 1;
                while(left < right)
                {
                    long temp = (long)nums[j] + nums[i] + nums[left] + nums[right];
                    long distance = temp - target;
                    if(distance == 0)
                    {
                        ans.push_back({nums[j] , nums[i] , nums[left] , nums[right]});
                    }
                    if(distance > 0)
                    {
                        right--;
                        while(right -1 >= 0 && nums[right + 1] == nums[right])
                        {
                            right--;
                        }
                    }
                    else{
                        left++;
                        while(left + 1 < len && nums[left - 1] == nums[left])
                        {
                            left++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
//8ms 95.95%
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
         int len = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < len - 3; i++)
        {
             if(i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                 if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long) nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) {
                continue;
            }
            for(int j = i + 1; j < len -2; j++)
            {
                if(j > i + 1 && nums[j - 1] == nums[j])
                {
                    continue;
                }
                 if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long) nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target) {
                    continue;
                }
                int left = j + 1;
                int right = len - 1;
                while(left < right)
                {
                    long temp = (long)nums[j] + nums[i] + nums[left] + nums[right];
                    long distance = temp - target;
                    if(distance == 0)
                    {
                        ans.push_back({nums[j] , nums[i] , nums[left] , nums[right]});
                    }
                    if(distance > 0)
                    {
                        right--;
                        while(right -1 >= 0 && nums[right + 1] == nums[right])
                        {
                            right--;
                        }
                    }
                    else{
                        left++;
                        while(left + 1 < len && nums[left - 1] == nums[left])
                        {
                            left++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> a = {2,2,2,2,2};
    int temp = 0;
     vector<vector<int>> ans = s.fourSum(a,temp);
    return 0;
}