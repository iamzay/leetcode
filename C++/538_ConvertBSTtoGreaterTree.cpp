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
  TreeNode* convertBST(TreeNode* root) {
    ConvertBST(root,0);
    return root;
  }
private:
  int ConvertBST(TreeNode *r,int parentSum){
    if(!r) return 0;
    int tmp=r->val;
    int rightSum=ConvertBST(r->right,parentSum);
    r->val+=parentSum+rightSum;
    int leftSum=ConvertBST(r->left,r->val);
    return tmp+rightSum+leftSum;
  }
};
