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
  
        auto slow = head,fast = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // odd case
        if (fast != NULL) {
            slow = slow->next;
        }
        
        ListNode *lst2 = reverse(slow);
        ListNode *lst1 = head;
        bool isPalindrome = true;
        while (lst2 != NULL) {
            if (lst1->val != lst2->val) {
                isPalindrome = false;
                break;
            }
            lst1 = lst1->next;
            lst2 = lst2->next;
        }
        return isPalindrome;
    }

private:
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *cur = head;
        while(cur != NULL) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
}; 