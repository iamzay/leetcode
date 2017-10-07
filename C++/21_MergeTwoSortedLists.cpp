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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p1=l1,*p2=l2,*tmp,*head;
    if(!p1||!p2) return p1?p1:p2;
    if(p1->val<p2->val) {
      tmp=head=p1;
      p1=p1->next;
    } else{
      tmp=head=p2;
      p2=p2->next;
    }
    while(p1&&p2){
      if(p1->val<p2->val){
        tmp->next=p1;
        tmp=tmp->next;
        p1=p1->next;
      } else{
        tmp->next=p2;
        tmp=tmp->next;
        p2=p2->next;
      }
    }
    tmp->next=p1?p1:p2;
    return head;
  }
};
