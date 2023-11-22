// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 返回容器可以储存的最大水量。

//第一个循环只需要遍历前一半，第二个循环i遍历之后的
//时间太长不通过
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int maxSize = 0;
        for(int i = 0; i < len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                int ans = (height.at(i) > height.at(j) ? height.at(j):height.at(i)) * (j - i);
                maxSize = ans > maxSize? ans: maxSize;
            }
        }
        return maxSize;
    }
};

//双指针
//60ms 97.51% s58.10mb 11.45%
class Solution2 {
public:
    int maxArea(vector<int>& height) {
       int len = height.size();
       int maxSize = 0;
        int left = 0;
        int right = len - 1;
        int ans = 0;
       while(left != right)
       {

            if(height.at(left) >= height.at(right))
            {
                ans = height.at(right) * (right - left);
                maxSize = ans > maxSize? ans:maxSize;
                right--;
            }else
            {
                ans = height.at(left) * (right - left);
                maxSize = ans > maxSize? ans:maxSize;
                left++;
            }
       }
        return maxSize;
    }
};