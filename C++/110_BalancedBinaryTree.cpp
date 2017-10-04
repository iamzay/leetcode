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
  bool isBalanced(TreeNode* root) {
    if(!root)
      return true;
    auto ans=_isBalanced(root);
    return ans.first;
  }

private:
  pair<bool,int> _isBalanced(TreeNode *root){
    if(!root)
      return {true,0};
    pair<bool,int> pLeft=_isBalanced(root->left),pRight=_isBalanced(root->right);
    if(!pLeft.first||!pRight.first)
      return {false,-1};
    if(abs(pLeft.second-pRight.second)>1)
      return {false,-1};
    return {true,max(pLeft.second,pRight.second)+1};
  }
};
