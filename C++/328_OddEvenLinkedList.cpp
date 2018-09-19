#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }      

        auto oddLst = head;
        auto evenLst = head->next;
        auto evenLstHead = head->next;
        auto cur = head->next->next;

        while(cur != NULL) {
            auto tmp = cur->next;

            // 插入奇数队列 
            oddLst->next = cur;
            oddLst = cur;

            // 插入偶数队列
            if(tmp != NULL) {
                cur = tmp;
                tmp = cur->next; 
                evenLst->next = cur;
                evenLst = cur;
            }
            cur = tmp;
        }

        // 合并奇数队列和偶数队列
        oddLst->next = evenLstHead;
        evenLst->next = NULL;

        return head; 
    }
};