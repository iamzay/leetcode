#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }     

        auto cur = head;
        auto last = head->next->next;

        // swap
        auto second = cur->next;
        second->next = cur;
        cur->next = swapPairs(last);

        return second;
    }
};