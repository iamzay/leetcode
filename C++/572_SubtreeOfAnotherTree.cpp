/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    int th=getHeight(t,-1),sh=getHeight(s,th);
    for(auto node:candidates){
      if(isEqual(node,t)) return true;
    }
    return false;
  }

private:
  int getHeight(TreeNode *r,int d){
    if(!r) return 0;
    int depth=1+max(getHeight(r->left,d),getHeight(r->right,d));
    if(depth==d) candidates.push_back(r);
    return depth;
  }

  bool isEqual(TreeNode *t1,TreeNode *t2){
    if(!t1&&!t2) return true;
    if(!t1||!t2) return false;
    if(t1->val!=t2->val) return false;
    return isEqual(t1->left,t2->left)&&isEqual(t1->right,t2->right);
  }

  vector<TreeNode *> candidates;
};

class Solution1 {
public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    int sh=getHeight(s),th=getHeight(t);
    int diff=sh-th;
    if(diff<0) return false;
    if(!t) return true;
    queue<TreeNode *> q;
    q.push(s);
    for(;diff;--diff){
      int n=q.size();
      while(n--){
        TreeNode *cur=q.front();
        q.pop();
        if(cur->left)
          q.push(cur->left);
        if(cur->right)
          q.push(cur->right);
      }
    }
    while(!q.empty()){
      TreeNode *cur=q.front();
      q.pop();
      if(isEqual(cur,t)) return true;
    }
    return false;
  }

private:
  int getHeight(TreeNode *r){
    if(!r) return 0;
    return 1+max(getHeight(r->left),getHeight(r->right));
  }

  bool isEqual(TreeNode *t1,TreeNode *t2){
    if(!t1&&!t2) return true;
    if(!t1||!t2) return false;
    if(t1->val!=t2->val) return false;
    return isEqual(t1->left,t2->left)&&isEqual(t1->right,t2->right);
  }
};
