// 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 例如，121 是回文，而 123 不是。
#include<iostream>
using namespace std;
//t 4ms 94.94%   s 6.13mb 51.43%
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        int nums[10];
        int len = getNums(x,&nums[0]);
        for(int i = 0; i < len ; i++)
        {
            if(nums[i] == nums[len - 1 -i])
            {
                continue;
            }else
            {
                return false;
            }
        }
        return true;
    }

    int getNums(int x,int* nums)
    {
        int index = 0;
        do{
            nums[index] = x % 10;
            x /= 10;
            index++;
        }while (x);
       return index;       
    }
};

//没有必要都比较一遍，只需要比较一半就行
//T 0ms 100% s6.16mb 44.12%
class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        int nums[10];
        int len = getNums(x,&nums[0]);
        int halfLne = len / 2;
        for(int i = 0; i < halfLne; i++)
        {
            if(nums[i] == nums[len - 1 -i])
            {
                continue;
            }else
            {
                return false;
            }
        }
        return true;
    }

    int getNums(int x,int* nums)
    {
        int index = 0;
        do{
            nums[index] = x % 10;
            x /= 10;
            index++;
        }while (x);
       return index;       
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0 || ( x % 10 == 0 && x != 0))
        {
            return false;
        }
       int halfX = 0;
       while (x > halfX)
       {
            halfX = halfX * 10 + x % 10;
            x /= 10;
       }
       return x == halfX || x == halfX / 10;
    }
};