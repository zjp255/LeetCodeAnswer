// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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
//4ms 89.34% 14.7MB77.79%
 class Solution {
public:
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