#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto newHead = new ListNode(val + 1);
        newHead->next = head;
        auto cur = newHead;
        while(cur->next != NULL) {
            auto next = cur->next;
            if (next->val == val) {
                cur->next = next->next;
            } else {
                cur = cur->next;
            }
        }
        return newHead->next;
    }
};