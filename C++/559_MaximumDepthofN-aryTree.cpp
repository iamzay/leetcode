#include <vector>
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
    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }
        int res = 0;
        for(auto node:root->children) {
            res = max(res, 1 + maxDepth(node));
        }

        return res;
    }
};