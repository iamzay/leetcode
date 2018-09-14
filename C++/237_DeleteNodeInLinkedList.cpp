#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        while (true) {
            node->val = node->next->val;
            if (node->next->next == NULL) {
                node->next = NULL;
                break;
            }
            node = node->next;
        }       
    }
};