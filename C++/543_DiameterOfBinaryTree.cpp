/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int diameterOfBinaryTree(TreeNode* root) {
    _max=0;
    depth(root);
    return _max;
  }

private:
  int depth(TreeNode *r){
    if(!r) return -1;
    int l_depth=depth(r->left);
    int r_depth=depth(r->right);
    int length=l_depth+r_depth+2;
    _max=max(_max,length);
    return 1+max(l_depth,r_depth);
  }

  int _max;
};
