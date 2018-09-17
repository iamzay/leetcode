#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(),G.end());
        int res = 0;
        auto cur = head;
        auto inComponent = false;
        while (cur != NULL) {
            if (!inComponent && s.count(cur->val)) {
                inComponent = true;
                ++res;
           } else if (!s.count(cur->val)) {
               inComponent = false;
           }
           cur = cur->next;
        }

        return res;
    }
};
