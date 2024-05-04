// 你可以选择使用单链表或者双链表，设计并实现自己的链表。

// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

// 实现 MyLinkedList 类：

// MyLinkedList() 初始化 MyLinkedList 对象。
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点



#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
// 27ms 96.87% 22.87MB 40.89%
class MyLinkedList {
public:

    class Node{
        public:
            int val;
            Node* next;
    };


    MyLinkedList() {
        head = new Node();
        tail = head;
    }
    
    int get(int index) {
        if(index >= length)
            return -1;
        Node* temp = head;
        for (int i = 0; i <= index; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node();
        head->val = val;
        temp->next = head;
        head = temp;
        length++;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node();
        temp->val = val;
        tail->next = temp;
        tail = temp;
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > length)
            return;
        if(index == length)
            addAtTail(val);
        else
        {
            Node* temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            Node* newNode = new Node();
            newNode->val = val;
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index >= length)
            return;
        Node* temp = head;
        for (int i = 0; i < index; i++)
        {
                temp = temp->next;
        }
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        if(index == length - 1)
        {
            tail = temp;
        }
        delete deleteNode;
        length--;
    }
private:
   Node* head;
   Node* tail;
   int length = 0;
};