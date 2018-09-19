#include <iostream>
#include <deque>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        deque<int> s1,s2;

        while(l1 != NULL) {
            s1.push_back(l1->val);
            l1 = l1->next;
        }  
        while(l2 != NULL) {
            s2.push_back(l2->val);
            l2 = l2->next;
        }

        if(s1.size() < s2.size()) {
            s1.swap(s2);
        }
        int n = s1.size() - s2.size();
        while(n--) {
            s2.push_front(0);
        }

        int sum = 0;
        ListNode *prev = NULL;
        while(!s1.empty()) {
            int a = s1.back();
            s1.pop_back();
            int b = s2.back();
            s2.pop_back();
            sum += a + b;
            ListNode *cur = new ListNode(sum % 10);
            cur->next = prev;
            sum /= 10; 
            prev = cur;
        }
        if(sum) {
            ListNode *head = new ListNode(1);
            head->next = prev;
            return head;
        }
        return prev;
    }
};