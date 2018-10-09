#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

TreeNode* constructTree(vector<string> &strs) {
    if(strs.empty()) return NULL;
    queue<TreeNode*> q;
    auto root = new TreeNode(stoi(strs[0]));
    q.push(root);
    int i = 1;
    int n = strs.size();
    while(!q.empty() && i < n) {
        auto node = q.front();
        q.pop();
        node->left = !strs[i++].size() ? NULL : new TreeNode(stoi(strs[i]));
        node->right = i >=n || !strs[i++].size() ? NULL : new TreeNode(stoi(strs[i]));
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }
    return root;
}