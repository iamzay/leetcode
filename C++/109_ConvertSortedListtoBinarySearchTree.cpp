#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* toBST(ListNode* head, ListNode* tail) {
        if(head == tail) {
            return NULL;
        }
        if(head->next == tail) {
            return new TreeNode(head->val);
        }

        auto slow = head, fast = head;
        while(fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto root = new TreeNode(slow->val);
        root->left = toBST(head,slow);
        root->right = toBST(slow->next,tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return toBST(head,NULL);
    }
};