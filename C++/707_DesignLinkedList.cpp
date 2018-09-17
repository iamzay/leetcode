#include <iostream>
using namespace std;
class MyLinkedList {

    struct MyNode {
        MyNode *next;
        int val;
        MyNode (int v, MyNode *n=NULL): val(v), next(n) {}
    };

    MyNode *head;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new MyNode(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        MyNode *cur = head;
        for (int i = 0; i <= index && cur != NULL; ++i) {
            cur = cur->next;
        }
        return cur == head || cur == NULL ? -1 : cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyNode *node = new MyNode(val,head->next);
        head->next = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyNode *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new MyNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        MyNode *cur = head;
        for (int i = 0; i < index && cur != NULL; ++i) {
            cur = cur->next;
        }
        if (cur != NULL) {
            MyNode *tmp = cur->next;
            cur->next = new MyNode(val);
            cur->next->next = tmp;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        MyNode *cur = head;
        for (int i = 0;i < index && cur != NULL; ++i) {
            cur = cur->next;        
        }
        if (cur != NULL && cur->next != NULL) {
            MyNode *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        } 
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */