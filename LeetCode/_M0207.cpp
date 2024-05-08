// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

// 图示两个链表在节点 c1 开始相交：



// 题目数据 保证 整个链式结构中不存在环。

// 注意，函数返回结果后，链表必须 保持其原始结构 。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
//哈希集合法
//40ms 41% 20MB 5%
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        ListNode* temp = headA;
        while (temp != NULL)
        {
            set.insert(temp);
            temp->next;
        }
        temp = headB;
        while(temp != NULL)
        {
            if(set.count(temp))
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};



//普通方法
//27ms 98% 16.53Mb 99.95
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLen = 0, bLen = 0;
        ListNode* curA = headA, *curB = headB;
        while(curA != NULL)
        {
            aLen++;
            curA = curA->next;
        }

        while (curB != NULL)
        {
            bLen++;
            curB = curB->next;
        }
        
        curA = headA;
        curB = headB;

        while(aLen != bLen)
        {
            if(aLen > bLen)
            {
                curA = curA->next;
                aLen--;
            }else{
                curB = curB->next;
                bLen--;
            }
        }

        while (curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }
        
        return curA;
    }
};