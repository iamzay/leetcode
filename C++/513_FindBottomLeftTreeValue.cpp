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

class Solution {
private:
    int maxLevel = 0;
    int res;

    void _dfs(TreeNode* node, int level) {
        if(node == NULL) return;
        if(level > maxLevel) { 
            res = node->val;
            maxLevel = level;
        }
        _dfs(node->left, level + 1);
        _dfs(node->right, level + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        _dfs(root, 1);
        return res;
    }
};