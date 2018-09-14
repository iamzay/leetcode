#include <iostream>
#include <cmath>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        auto cur = head;
        while(cur != NULL) {
            ++n;
            cur = cur -> next;
        }
        
        int mid = n / 2 + 1;
        while (--mid) {
            head = head -> next;
        }

        return head;
    }
};