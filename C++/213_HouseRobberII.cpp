class Solution {
public:
  int rob(vector<int>& nums) {
    int n=nums.size();
    if(!n) return 0;
    if(n==1) return  nums[0];
    // 分两种情况，取第一个和不取第一个
    // 若取第一个，则结果为d[n-1]，因为第n个不能取
    // 若不取第一个，则结果为d[n]
    vector<int> d(n+1,0);
    d[0]=0;
    d[1]=nums[0];
    for(int i=2;i<n;++i)
      d[i]=max(d[i-1],nums[i-1]+d[i-2]);
    int res1=d[n-1];
    d[1]=0;
    for(int i=2;i<=n;++i)
      d[i]=max(d[i-1],nums[i-1]+d[i-2]);
    int res2=d[n];
    return max(res1,res2);
  }
};
