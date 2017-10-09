class Solution {
public:
  int rob(vector<int>& nums) {
    int n=nums.size();
    if(!n) return 0;
    // d[n]表示nums[0~n]的最大值
    vector<int> d(n,0);
    d[0]=nums[0];
    if(n>1)
      d[1]=max(nums[1],nums[0]);
    for(int i=2;i<n;++i)
      d[i]=max(d[i-1],nums[i]+d[i-2]);
    return d[n-1];
  }
};

class Solution {
public:
  int rob(vector<int>& nums){
    int n=nums.size();
    if(!n) return 0;
    if(n==1) return nums[0];
    int prev=nums[0],cur=0;
    if(n>1)
      cur=max(nums[1],nums[0]);
    for(int i=2;i<n;++i){
      int tmp=cur;
      cur=max(nums[i]+prev,cur);
      prev=tmp;
    }
    return max(cur,prev);
  }
};
