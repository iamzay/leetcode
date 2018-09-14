#include <iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        int n = 0;
        auto cur = head;
        while(cur != NULL) {
            ++n;
            cur = cur->next;
        }

        int m = n & 1 ? n / 2 + 1 : n / 2;
        int i = 1;
        cur = head;
        ListNode *prev = NULL;
        while(i++ <= m) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp; 
        }

        auto lst1 = n & 1 ? prev->next : prev;
        auto lst2 = cur;
        bool res = true;
        while (lst2 != NULL) {
            if (lst1->val != lst2->val) {
                res = false;
                break;
            } 
            lst1 = lst1->next;
            lst2 = lst2->next;
        }

        return res;
    }
};