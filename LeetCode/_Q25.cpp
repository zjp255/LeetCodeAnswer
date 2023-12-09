// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


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
//8ms96.83% 11.8MB10.2%
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(k < 2)
        {
            return head;
        }
       vector<ListNode*> nodes;
       ListNode* thead = new ListNode();
       thead->next = head;
       ListNode* first = thead;
       ListNode* tail = head;
       while(tail)
       {
            int i = 0;
            for(; i < k; i++)
            {
                nodes.push_back(tail);
                tail = tail->next;
                if(!tail)
                {
                    i++;
                    break;
                }
            }
            if(i == k)
            {
               
                while(nodes.size())
                {
                    first->next = nodes.back();
                    first = first->next;
                    nodes.pop_back();
                }
                first->next = tail;
            }
       }
       return thead->next;
    }
};