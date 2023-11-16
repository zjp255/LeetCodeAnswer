// 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

// 函数 myAtoi(string s) 的算法如下：

// 读入字符串并丢弃无用的前导空格
// 检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
// 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
// 将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
// 如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
// 返回整数作为最终结果。
// 注意：

// 本题中的空白字符只包括空格字符 ' ' 。
// 除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
#include<iostream>
using namespace std;
//t 4ms 67.84% s 6.36mb 32.82%
class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        long ans = 0;
        bool fuhao = false;
        int haveFuhao = 0;
        int haveNum = 0;
        for(int i = 0; i < len; i++)
        {
            if((s[i] <= 57 && s[i] >= 48) || s[i] == 45 || s[i] == 43 || s[i] == 32)
            {
                if(s[i] == 32 && (haveNum >0 || haveFuhao > 0))
                 return fuhao == true? -ans:ans;
                if (s[i] == 45 || s[i] == 43)
                {
                    haveFuhao++;
                   
                    if(haveFuhao > 1 || haveNum > 0)
                    {
                        if(haveNum > 0)
                            return fuhao == true? -ans:ans;
                        else    
                            return 0;
                    }
                    if(s[i] == 45 )
                        fuhao = true;
                } 
                else if(s[i] <= 57 && s[i] >= 48)
                {
                    haveNum++;
                     ans = ans * 10 + s[i] - 48;
                    if(ans > INT_MAX  && fuhao == false )
                    {
                        return INT_MAX;
                    }
                    else if(ans - 1 > INT_MAX && fuhao == true) 
                    {
                        return INT_MIN;
                    }                    
                }
            }
            else{
                break;
            }
        }   
        if(fuhao == true)
            ans = -ans;
        return ans;
    }
};



int main()
{
    
   
    return 0;
}