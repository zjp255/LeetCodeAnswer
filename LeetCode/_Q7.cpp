// 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

// 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

// 假设环境不允许存储 64 位整数（有符号或无符号）。

//时间 0ms 100%  6.62mb击败5.02% 没有必要用空间为100的数组，int类型变量最大值为2147483647因此只需要10空间的数组
#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x < 10 && x > -10)
            return x;
       
        try
        {
            if(x == INT_MIN)
            throw 0;
            int nums[100];
            int numIn10 = 1;
            bool isNeg = false;
            int index = 0;
            double ans = 0;
            if(x < 0)
            {
                x = -x;
                isNeg = true; 
            }
            do
            {
                numIn10 = x % 10;
                x /= 10;
                nums[index] = numIn10;
                index++;
            }
            while (x != 0);
            
            numIn10 = 0;
            for(index -= 1; index >= 0; index--)
            {
                ans += nums[index] * pow(10,numIn10);
                if(ans > INT_MAX)
                {
                    throw 0;
                }
                numIn10++;
            }
            if(isNeg ==false)
            {
                return (int)ans;
            }else{
                return (int)-ans;
            }
        }
        catch(int e)
        {
           return e;
        }    
    }

   
};

//时间 0ms 100% 空间6.57mb 5.02% 改进方向没必要把负数转成正数
class Solution2 {
public:
    int reverse(int x) {
        if(x < 10 && x > -10)
            return x;
       
        try
        {
            if(x == INT_MIN)
            throw 0;
            int nums[10];
            int numIn10 = 1;
            bool isNeg = false;
            int index = 0;
            double ans = 0;
            if(x < 0)
            {
                x = -x;
                isNeg = true; 
            }
            do
            {
                numIn10 = x % 10;
                x /= 10;
                nums[index] = numIn10;
                index++;
            }
            while (x != 0);
            
            numIn10 = 0;
            for(index -= 1; index >= 0; index--)
            {
                ans += nums[index] * pow(10,numIn10);
                if(ans > INT_MAX)
                {
                    throw 0;
                }
                numIn10++;
            }
            if(isNeg ==false)
            {
                return (int)ans;
            }else{
                return (int)-ans;
            }
        }
        catch(int e)
        {
           return e;
        }    
    }
};

//时间 0ms 100% 空间6.52mb 5.02%
class Solution3 {
public:
    int reverse(int x) {
        if(x < 10 && x > -10)
            return x;      
        try
        {
            if(x == INT_MIN)
                throw 0;
            int nums[10];
            int index = 0;
            double ans = 0;
            int numIn10 = 0;
            do
            {
                nums[index] = x % 10;
                x /= 10;               
                index++;
            }
            while (x != 0);
            for(index -= 1; index >= 0; index--)
            {
                ans += nums[index] * pow(10,numIn10);
                if(ans > INT_MAX || ans < INT_MIN)
                {
                    throw 0;
                }
                numIn10++;
            }
           return (int)ans;
        }
        catch(int e)
        {
           return e;
        }    
    }
};
//T 0ms 100% s 6.09mb 28.13%,减少了数组的使用 简化了代码，内存使用还是降不下去
class Solution4 {
public:
    int reverse(int x) {
        if(x < 10 && x > -10)
            return x;      
        double ans = 0;
        do
        {
            ans =  (ans + x % 10)*10 ;
            x /= 10;               
        }
        while (x != 0);
        ans /= 10;
        if(ans > INT_MAX || ans < INT_MIN)
        {
            return 0;
        }
        return (int)ans;
    }
};
//6mb
class Solution5 {
public:
    int reverse(int x) {
        if(x < 10 && x > -10)
            return x;      
        double ans = 0;
        do
        {
            ans = ans * 10 + x % 10;
            x /= 10;               
        }
        while (x != 0);
        return (ans > INT_MAX || ans < INT_MIN)? 0 : (int)ans;
    }
};

class Solution5 {
public:
    int reverse(int x) { 
        double ans = 0;
        do
        {
            ans = ans * 10 + x % 10;
            x /= 10;               
        }
        while (x != 0);
        return (ans > INT_MAX || ans < INT_MIN)? 0 : (int)ans;
    }
};

class Solution6 {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
                return 0;
            }
            rev = rev * 10 +  x % 10;
            x /= 10;
        }
        return rev;
    }
};

int main()
{
    Solution s;
    cout<<s.reverse(-2147483648)<<endl;
}