// 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

// 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// 10ms 89.7% 15.41MB 5%
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> ans;
        if(root) que.push(root);
        while (!que.empty())
        {
            int size =  que.size();
            vector<int> el;
            for (int i = 0; i < size; i++)
            {       
                Node* temp = que.front();
                que.pop();
                el.push_back(temp->val);
                vector<Node*> childrens = temp->children;
                for(Node* n : childrens)
                {
                    if(n != NULL)
                        que.push(n);
                }
            }
            ans.push_back(el);
        }
        return ans;
    }
};