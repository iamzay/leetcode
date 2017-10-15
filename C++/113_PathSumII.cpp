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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<int> tmp;
    PathSum(root,sum,tmp);
    return res;
  }

private:
  void PathSum(TreeNode* r,int sum,vector<int>& tmp){
    if(!r) return;
    tmp.push_back(r->val);
    if(r->val==sum&&!r->left&&!r->right){
      res.push_back(tmp);
      tmp.pop_back();
      return;
    }
    PathSum(r->left,sum-r->val,tmp);
    PathSum(r->right,sum-r->val,tmp);
    tmp.pop_back();
  }
  vector<vector<int>> res;
};
