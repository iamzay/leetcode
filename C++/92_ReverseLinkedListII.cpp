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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(m==n) return head;
    ListNode preHead(0);
    preHead.next=head;
    ListNode *pre=&preHead,*cur;
    n=n-m;
    while(--m){
      pre=pre->next;
    }
    cur=pre->next;
    while(n--){
      ListNode *p=cur->next;
      cur->next=p->next;
      p->next=pre->next;
      pre->next=p;
    }
    return preHead.next;
  }
};
