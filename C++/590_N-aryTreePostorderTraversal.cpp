#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL) {
            return vector<int>();
        }

        vector<int> doge;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            auto node = s.top();
            s.pop();
            doge.push_back(node->val);

            auto children = node->children;
            for(auto it = children.begin(); it != children.end(); ++it) {
                s.push(*it);
            }
        }

        vector<int> res(doge.rbegin(),doge.rend());
        return res;
    }    
};  