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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto tmp=head;
    for(int i=1;i<n&&tmp;++i)
      tmp=tmp->next;
    if(!tmp) return head;
    tmp=tmp->next;

    if(!tmp) return head->next;
    auto first=head,prev=head;
    while(tmp){
      tmp=tmp->next;
      prev=head;
      head=head->next;
    }
    prev->next=prev->next->next;
    return first;
  }
};
