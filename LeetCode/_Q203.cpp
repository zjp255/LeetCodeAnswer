// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

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
 //11ms 89.78% 18.13MB 84.89%
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* beforeHead = new ListNode();
        beforeHead->next = head;
        ListNode* temp = beforeHead;
        while(temp->next != NULL)
        {
            if(temp->next->val == val)
            {
                temp->next = temp->next->next;  
            }
            else
                temp = temp->next;
        }
        return beforeHead->next;
    }
};