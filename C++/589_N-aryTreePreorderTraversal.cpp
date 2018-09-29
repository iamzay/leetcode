#include <vector>
#include <stack>
#include <iostream>
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
    vector<int> preorder(Node* root) {
        if(root == NULL) {
            return vector<int>();
        }
        stack<Node*> s;
        vector<int> res;
        s.push(root);
        while(!s.empty()) {
            auto node = s.top();
            s.pop();
            res.push_back(node->val);
            auto children = node->children;
            for(auto it = children.rbegin(); it != children.rend(); ++it) {
                s.push(*it);
            }
        }

        return res;
    }
};