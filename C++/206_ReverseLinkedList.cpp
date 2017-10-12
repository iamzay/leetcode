/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *prev=NULL,*cur=head;
    if(!cur) return NULL;
    while(cur->next){
      ListNode *tmp=cur->next;
      cur->next=prev;
      prev=cur;
      cur=tmp;
    }
    cur->next=prev;
    return cur;
  }
};
