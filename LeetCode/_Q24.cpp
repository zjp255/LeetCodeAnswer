
//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
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
//0ms100% 7.77MB24.10%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       ListNode* thead = new ListNode();
        thead->next = head;
        ListNode* front = thead;
        ListNode* first = head;
        ListNode* second = first?first->next:NULL;
        while(second)
        {
            first->next = second->next;
            second->next = first;
            front->next = second;
            front = front->next->next;
            first = first->next; 
            if(first && first->next)
            {
                second = first->next;
            }
            else{
                second = NULL;
            }
        }
        return thead->next;
    }
};