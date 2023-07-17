/*给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *list = new ListNode();
        ListNode *answer = nullptr;
        answer = list;
        ListNode *num1 = l1;
        ListNode *num2 = l2;
        int c = 0;
        while (num1 != nullptr && num2 != nullptr)
        {
            ListNode *temp = new ListNode(num1->val + num2->val + c);
            if (temp->val >= 10)
            {
                c = temp->val / 10;
                temp->val = temp->val % 10;
            }
            else
            {
                c = 0;
            }
            if (num1->next == nullptr && num2->next != nullptr)
            {
                num2->next->val += c;
                temp->next = num2->next;
                carryNum(num2->next);
            }
            else if (num2->next == nullptr && num1->next != nullptr)
            {
                num1->next->val += c;
                temp->next = num1->next;
                carryNum(num1->next);
            }
            else if (num2->next == nullptr && num1->next == nullptr && c > 0)
            {
                temp->next = new ListNode(c);
            }

            num1 = num1->next;
            num2 = num2->next;

            answer->next = temp;
            answer = answer->next;
        }
        return list->next;
    }

    void carryNum(ListNode *l1)
    {
        if (l1 == nullptr)
        {
            return;
        }
        else if (l1->val >= 10)
        {
            if (l1->next == nullptr)
            {
                l1->next = new ListNode(l1->val / 10);
            }
            else
            {
                l1->next->val += l1->val / 10;
            }
            l1->val %= 10;
            if (l1->next->val >= 10)
            {
                carryNum(l1->next);
            }
        }
    }
};
class Solution2
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int c = 0;
        ListNode *list = nullptr;
        ListNode *node = new ListNode();
        while (l1 || l2 || c > 0)
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int num3 = num1 + num2 + c;
            c = num3 / 10;
            num3 %= 10;
            if (list == nullptr)
            {
                node->val = num3;
                list = node;
            }
            else
            {
                node->next = new ListNode(num3);
                node = node->next;
            }
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return list;
    }
};