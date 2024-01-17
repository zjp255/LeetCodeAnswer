// 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

// 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
// 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
// 那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
// 如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

// 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
// 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
// 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
// 给你一个整数数组 nums ，找出 nums 的下一个排列。

// 必须 原地 修改，只允许使用额外常数空间。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 14.3Mb 5%
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        for(int i = len - 1; i >= 0; i--)
        {
            if(i == 0)
            {
                fanZhuan(nums,0);
                return;
            }
            else{
                if(nums[i - 1] < nums[i])
                {
                    int j = len - 1;
                    while(nums[j] <= nums[i - 1])
                    {
                        j--;
                    }
                    swap(nums,i - 1,j);
                    fanZhuan(nums,i);
                    return;
                }
            }
        }
    }

    void fanZhuan(vector<int>& nums,int start)
    {
        int len = nums.size() + start;
        for(int j = start; j < len / 2; j++)
        {
            swap(nums,j,len - j - 1);
        }
    }

    void swap(vector<int>& nums,int left,int right)
    {
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
    }
};