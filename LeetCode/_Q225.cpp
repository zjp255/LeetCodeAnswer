// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

// 实现 MyStack 类：

// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。


#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
//0ms 100% 8.13 34.56%
class MyStack {
public:
    queue<int> que;
    int size = 0;
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        que.push(x);
        size++;
    }
    
    int pop() {
        queue<int> temp;
        while(que.size() != 1)
        {
            temp.push(que.front());
            que.pop();
        }

        int ans = que.back();
        que = temp;
        size--;
        return ans;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        if(size == 0)
            return true;
        else
            return false;
    }
};
