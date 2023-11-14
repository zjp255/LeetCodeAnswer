// 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

// P   A   H   N
// A P L S I I G
// Y   I   R
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

// 请你实现这个将字符串进行指定行数变换的函数：
//T 28ms 26.91%  s8.53mb 70.29%
#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        string a = "";
        int *rowIndex = new int[len];
        int type = 0;
        int underIndex = 1;
        for(int i = 0; i < len; i++)
        {
            if(type == 0 && underIndex == numRows)
            {
                type = 1;
            }else if (type == 1 && underIndex == 1)
            {
                type = 0;
            }
            rowIndex[i] = underIndex;
            if(type == 0)
            {
                underIndex++;
            }else if(type == 1)
            {
                underIndex--;
            }
            if(underIndex < 1)
            {
                underIndex = 1;
            }else if(underIndex > numRows)
            {
                underIndex = numRows;
            }
        }

        for(int j = 1; j <= numRows; j++)
        {
            for(int i = 0; i < len; i++)
            {
                if(rowIndex[i] == j)
                {
                    a += s[i];
                }
            }
        }
        return a;
    }
};
//T 91.44% s 10.9mb 24.78%
class Solution1 {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        string a = "";
        int *rowIndex = new int[len];
        string *answer = new string[numRows];
        int type = 0;
        int underIndex = 1;
        for(int i = 0; i < len; i++)
        {
            if(type == 0 && underIndex == numRows)
            {
                type = 1;
            }else if (type == 1 && underIndex == 1)
            {
                type = 0;
            }
            answer[underIndex - 1] += s[i];
            if(type == 0)
            {
                underIndex++;
            }else if(type == 1)
            {
                underIndex--;
            }
            if(underIndex < 1)
            {
                underIndex = 1;
            }else if(underIndex > numRows)
            {
                underIndex = numRows;
            }
        }

        for(int j = 0; j < numRows; j++)
        {
           a += answer[j];
        }
        return a;
    }
};

//t 12ms 69.82% s 11.1 24.95%
class Solution2 {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        else{
            int len = s.length();
            string a;
            int *rowIndex = new int[len];
            string *answer = new string[numRows];
            bool type = true;
            int underIndex = 1;
            for(int i = 0; i < len; i++)
            {
                if(type == true && underIndex == numRows)
                {
                    type = false;
                }else if (type == false && underIndex == 1)
                {
                    type = true;
                }
                answer[underIndex - 1] += s[i];
                if(type == true)
                {
                    underIndex++;
                }else if(type == false)
                {
                    underIndex--;
                }
            }

            for(int j = 0; j < numRows; j++)
            {
            a += answer[j];
            }
            return a;
        }
    }
};
// t 4ms 98.94%  s 7.85mb 85.24%
class Solution3 {
public:
    string convert(string s, int numRows) {
          int len = s.length();
        if(numRows == 1 || numRows >= len)
        {
            return s;
        }
        string a;
        int n = numRows * 2 - 2;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j + i < len; j += n)
            {
                a += s[j + i];
                if(i > 0 &&  j + n - i < len && i < numRows -1)
                {
                    a += s[j + n - i];
                }
            }
        }

        return a;
    }
};

int main()
{
    Solution p;
   cout<< p.convert("AB",1)<<endl;
}