// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
//0ms 100% 13MB 73.9%
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode();
        temp->next = head;
        head = temp;
        ListNode* left = head,* right = head;
        int gap = 0;
        while (right != NULL)
        {
            right = right->next;
            if(gap <= n)
                gap++;
            else{
                left = left->next;
            }
        }
        left->next = left->next->next;
        return head->next;
    }
};



 
//0ms 100% 10.75MB 12.25%
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = 1;
        ListNode* p = head;
        ListNode* front = head;
        ListNode* tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
            if(n <= 1)
            {
                 front = p;
                p = p->next;
            }
            n--;
        }
        if(front == p)
        {
            head = head->next;         
        }else
        {
            front->next = p->next;
        }
        return head;
    }
};
//0ms100% 10.82MB 31.39%
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
            if(n <= 0)
            {
                p = p->next;
            }
            n--;
        }
        if(p->next == NULL || n > 0)
        {
            head = head->next;
        }else{
          p->next = p->next->next;
        }
        return head;
    }
};