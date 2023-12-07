// 给你一个链表数组，每个链表都已经按升序排列。

// 请你将所有链表合并到一个升序链表中，返回合并后的链表。
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
//188ms 11.50% 12.9MB92%
 class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0)
        {
            return NULL;
        }
        if(len == 1)
        {
            return lists[0];
        }
        for(int i = 1; i < len; i++)
        {
           lists[i] = mergeTwoLists(lists[i - 1],lists[i]);
        }
        return lists[len - 1];

    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode* p1 = list1;
        ListNode* p2 = list2;
        if(list1 == NULL || list2 == NULL)
        {
            if(list1 != NULL && list2 == NULL)
                return list1;
            else if(list2 != NULL && list1 == NULL)
                return list2;
            else
                return NULL;
        }
        while(p1 != NULL)
        {
            if(p1->val <= p2->val)
            {
                ListNode* temp = p1;
                p1 = p1->next;
                int tpnum = temp->val;
                temp->val = p2->val;
                p2->val = tpnum;
                temp->next = p2->next;
                p2->next = temp;
            }
            else{
                if(p2->next == NULL)
                {
                    p2->next = p1;
                    break;
                }
                else
                    p2 = p2->next;
            }
        }
        return list2;
    
    }
};


//优先队列法
class Solution1 {
public:
    struct Node{
        int var;
        ListNode* node;
        bool operator <(const Node& temp) const
        {
            return var > temp.var;
        }
    };
    priority_queue<Node> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node: lists)
        {
            if(node)
                q.push({node->val,node});
        }
        ListNode* node = new ListNode();
        ListNode* tail = node;
        while(!q.empty())
        {
            auto ft = q.top();
            q.pop();
            tail->next = ft.node;
            tail = tail->next;
            if(ft.node->next)
                q.push({ft.node->next->val,ft.node->next});
        }
        return node->next;
    }
};