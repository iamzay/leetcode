#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int getListLength(ListNode *lst) {
        int res = 0;
        while (lst != NULL) {
            ++res;
            lst = lst->next;
        }

        return res;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = getListLength(root);
        vector<ListNode*> res;
        ListNode *lst = root;
        for (; k > 0; --k) {
            int curLen = (int)(ceil((double)len / k));
            len -= curLen;
            ListNode *curLst = curLen ? lst : NULL;
            ListNode *tmp = curLst;
            while (--curLen > 0) {
                tmp = tmp->next;
            }
            lst = tmp == NULL ? NULL : tmp->next;
            if (tmp != NULL) {
                tmp ->next = NULL;
            }
            res.push_back(curLst);
        }      

        return res;
    }
};