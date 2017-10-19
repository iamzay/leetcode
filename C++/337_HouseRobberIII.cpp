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
  int rob(TreeNode* root) {
    if(!root) return 0;
    // 若选当前节点，则max为root->val+rob(root的孙子节点)
    // 若不选当前节点，max为rob(root的孩子节点)
    m.insert({NULL,0});
    queue<TreeNode*> q;
    vector<vector<TreeNode*>> levels;
    q.push(root);
    while(!q.empty()){
      int n=q.size();
      vector<TreeNode*> curLevel;
      while(n--){
        auto tmp=q.front();
        q.pop();
        curLevel.push_back(tmp);
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
      }
      levels.push_back(curLevel);
    }
    // 从最后一层开始
    int n=levels.size();
    for(int i=n-1;i>=0;--i){
      auto &curLevel=levels[i];
      for(auto curNode:curLevel){
        int max1=m[curNode->left]+m[curNode->right];
        int max2=curNode->val+childSum(curNode->left)+childSum(curNode->right);
        m[curNode]=max(max1,max2);
      }
    }
    return m[root];
  }
private:
  int childSum(TreeNode *r){
    if(!r) return 0;
    return m[r->left]+m[r->right];
  }

  unordered_map<TreeNode*,int> m;
};
