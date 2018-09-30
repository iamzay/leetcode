#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;
        _binaryTreePaths(root, root, "", res);
        
        return res;
    }

private:
    void _binaryTreePaths(TreeNode* root,TreeNode* node, string path, vector<string>& res) {
        auto currentPath = path + "->" + to_string(node->val);
        if(node->left != NULL) _binaryTreePaths(root, node->left, currentPath, res);
        if(node->right != NULL) _binaryTreePaths(root, node->right, currentPath, res); 
        if(node->left == NULL && node->right == NULL) res.push_back(currentPath.substr(2, currentPath.size()));
    }
};