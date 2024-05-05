// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

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
//3ms 80% 11.35mb 61.28%
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* newHead = head;
        ListNode* temp = head->next;
        ListNode* temp2;
        while (temp)
        {
            temp2 = temp;
            temp = temp->next;
            temp2->next = newHead;
            newHead = temp2;
        }
        head->next = NULL;
        return newHead;
    }
};