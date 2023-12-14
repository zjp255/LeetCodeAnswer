// 给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。

// 整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。

// 返回被除数 dividend 除以除数 divisor 得到的 商 。

// 注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是 [−231,  231 − 1] 。
// 本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 -231 ，则返回 -231 。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//超时
class Solution {
public:
    int divide(int dividend, int divisor) {
       long n = 0;
        int ans = 1;
        long Ldividend = dividend;
        long Ldivisor = divisor;
        if(dividend < 0 || divisor < 0)
        {
            if(dividend < 0)
            {
                ans = -ans;
            }
            if(divisor < 0)
            {
                ans = -ans;
            }
            Ldividend = Ldividend < 0? -Ldividend:Ldividend;
            Ldivisor = Ldivisor < 0? -Ldivisor:Ldivisor;
        }
        while(Ldividend >= Ldivisor)
        {
            Ldividend -= Ldivisor;
            n++;
        }
        if(ans == 1)
        {
            return n > INT32_MAX?INT32_MAX:n;
        }
        else{
            return -n < INT32_MIN?INT32_MIN:-n;
        }
    
    }
};

//使用long
class Solution1 {
public:
     int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        long long ldividend = dividend;
        long ldivisor = divisor;
        if(ldividend == INT_MIN)
        {
            ldividend = INT_MAX;
            ldividend++;
        }else{
        ldividend = ldividend<0?-ldividend:ldividend;
        }
        ldivisor = ldivisor<0?-ldivisor:ldivisor;
        int sign = (dividend>>31) == (divisor>>31)?1:-1;
        int index1 = findClose(ldividend,ldivisor);
        int n = 0;
        while(ldividend >= ldivisor)
        {
            if(ldividend >= ldivisor<<index1)
            {
                ldividend -= ldivisor<<index1;
                n += 1<<index1;
            }
            index1--;        
        }
        if(sign == -1)
        {
            return -n;
        }
        return n;
    }
    int findClose(long target,long ans)
    {
        int left = 0,right = 32, mid = 16;
        while(left < right)
        {
            if(ans<<mid > target)
            {
                right = mid - 1;
                mid = (mid + left) / 2;
            }
            else{
                left = mid + 1;
                mid = (mid + right) / 2;
            }
        }
        return mid;
    }
};

//0ms 100% 6.5mb 5.6%
class Solution2 {
public:
     int divide(int dividend, int divisor) {
         int sign = (dividend>>31) == (divisor>>31)?1:-1;
        dividend = dividend > 0? -dividend:dividend;
        divisor = divisor > 0? -divisor:divisor;
        vector<vector<int>> map;
        int ans = 0;
        for(int i = 0; i <= 32; i++)
        {
            int temp = divisor<<i;
            if(temp >= INT_MIN>>1)
            {
                if(temp >= dividend)
                {
                    map.push_back({temp,1<<i});
                }else{
                    break;
                }
            }
            else{
                break;
            }
        }

        while(dividend <= divisor)
        {
            if(map.empty())
            {
                if(dividend <= divisor)
                {
                    return sign;
                }
                return 0;
            }
            vector<int> temp = map.back();
            if(temp.empty())
                return 0;
            if(temp[0] >= dividend)
            {
                dividend -= temp[0];
                if(temp[1] <= INT_MIN>>1 && ans <= INT_MIN>>1)
                { 
                    ans = INT_MIN;
                    break;
                }
                 else
                {
                    ans -= temp[1];
                }
            }
            if(temp[0] <dividend)
            {
                map.pop_back();
            }
        }
        if(sign == 1)
        {
            if(ans == INT_MIN)
                return INT_MAX;
            return -ans;
        }else{
           return ans;
        }
     }
      
};



int main()
{
    Solution2 s;
    cout<<s.divide(2147483647,-1);
}
 