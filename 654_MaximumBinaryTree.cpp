#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int findMaxIndex(vector<int>& nums,int begin,int end){
    if(end<begin)
      return -1;
    int index=begin;
    for(auto i=begin+1;i<=end;++i)
      if(nums[i]>nums[index])
        index=i;
    return index;
  }
  TreeNode* ConstructMaximumBinaryTree(vector<int>& nums,int begin,int end){
    if(end<begin)
      return NULL;
    int index=findMaxIndex(nums,begin,end);
    TreeNode *node=new TreeNode(nums[index]);
    node->left=ConstructMaximumBinaryTree(nums,begin,index-1);
    node->right=ConstructMaximumBinaryTree(nums,index+1,end);
    return node;
  }
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    auto size=nums.size();
    if(!size)
      return NULL;
    return ConstructMaximumBinaryTree(nums,0,size-1);
  }
};
int main(){
  auto s="hello world";
  cout<<s<<endl;
}
