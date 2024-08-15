// 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

//37ms 88% 50MB 41.30%
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;//最远距离
        int size = nums.size();
        for (int i = 0; i <= far; i++)
        {
            far = max(i + nums[i], far);
            if(far >= size - 1)
                return true;
        }
        return false;
    }
};







//35ms 97.03% 49.7MB 19.62%
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for(int i = 0; i < nums.size() && far < nums.size(); i++)
        {
             if((i > 0 && nums[i] != 0 && nums[i - 1] == 0) || i == nums.size() - 1)
            {
                if(far < i)
                {
                    return false;
                }
            }
            if(i + nums[i] > far)
                far = i + nums[i];
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nusm = {3,2,1,0,4};
    s.canJump(nusm);
    return 0;
}