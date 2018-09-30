#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        dfs(root,0,res);

        return res;
    }

private:
    void dfs(Node *node, int level, vector<vector<int>> &res) {
        if(node == NULL) return;
        if(res.size() <= level) {
            res.push_back(vector<int>());
        }
        res[level].push_back(node->val);

        auto children = node->children;
        for(auto childNode:children) {
            dfs(childNode, level + 1, res);
        }
    }
};