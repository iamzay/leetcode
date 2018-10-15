#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
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
    unordered_map<TreeNode*, int> depthMap;

    int depth(TreeNode* node) {
        if(node == NULL) return 0;
        if(depthMap.count(node))
            return depthMap[node];
        depthMap[node] = max(depth(node->left), depth(node->right)) + 1;
        return depthMap[node];
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL) return NULL;
        auto leftDepth = depth(root->left);
        auto rightDepth = depth(root->right);
        if(leftDepth == rightDepth)
            return root;
        else if(leftDepth > rightDepth)
            return subtreeWithAllDeepest(root->left);
        else
            return subtreeWithAllDeepest(root->right);
    }
};