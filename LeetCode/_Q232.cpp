// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

// 实现 MyQueue 类：

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
// 说明：

// 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
//0ms 100% 8.27Mb 44.28%
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int length = 0;
    MyQueue() {
        length = 0;
    }
    
    void push(int x) {
        st1.push(x);
        length++;
    }
    
    int pop() {
        convert(st1,st2);
        int ans = st2.top();
        st2.pop();
        length--;
        convert(st2,st1);
        return ans;
    }
    
    int peek() {
        convert(st1,st2);
        int ans = st2.top();
        convert(st2,st1);
        return ans;
    }
    
    bool empty() {
        if(length == 0)
            return true;
        else
            return false;
    }

    void convert(stack<int>& st1, stack<int>& st2)
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }
};