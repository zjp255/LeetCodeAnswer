// 给定一个二叉树：

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。

// 初始状态下，所有 next 指针都被设置为 NULL 。



#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;



class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//4ms 95% 16.95MB 36.73%
class Solution {
public:
    Node* connect(Node* root) {
       queue<Node*> que;
        if(root) que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                Node* temp = que.front();
                que.pop();
                if(i == size - 1)
                {
                    temp->next = NULL;
                }
                else
                {
                    temp->next = que.front();
                }
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        return root; 
    }
};