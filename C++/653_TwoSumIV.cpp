#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return _findTarget(root, k , s);
    }

private:
    bool _findTarget(TreeNode* node, int k , unordered_set<int>& s) {
        if(node == NULL) return false;
        int target = k - node->val;
        if(s.count(target)) return true;
        s.insert(node->val);
        return _findTarget(node->left, k , s) || _findTarget(node->right, k , s);
    }
};