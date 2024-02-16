// 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。

// 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。

// 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
// 子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。

// 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
//超时
class Solution {
public:
    int ans = 0;
    vector<int> part;
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return 1;
        }
        part.push_back(nums[0]);
        bool state = false;
        int i = 1;
        while(i < nums.size())
        {
            if(nums[i] - nums[0] > 0)
            {
                state = true;
                part.push_back(nums[i]);
                break;
            }else if(nums[i] - nums[0] < 0){
                state = false;
                part.push_back(nums[i]);
                break;
            }else{
                i++;
            }
        }
        if(part.size() < 2)
        {
            return 1;
        }
        combine(nums,i,2,state);
        return ans;
    }

    void combine(vector<int>& nums,int stratI,int count,bool state)
    {
        if(count > ans)
        {
            ans = count;
        }
        for(int i = stratI; i < nums.size(); i++)
        {
            if(state == true)
            {
                if((nums[i] - part.back()) < 0 )
                {
                    part.push_back(nums[i]);
                    state = false;
                    combine(nums,i + 1,count + 1,state);
                    state = true;
                    part.pop_back();
                }else{
                    continue;
                }
            }else{
                if((nums[i] - part.back()) > 0 )
                {
                    part.push_back(nums[i]);
                    state = true;
                    combine(nums,i + 1,count + 1,state);
                    state = false;
                    part.pop_back();
                }else{
                    continue;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    s.wiggleMaxLength(nums);

}