class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    // 需要找出两个集合p,q
    // 其中sum[p]-sum[q]=S
    // 也即sum[p]+sum[q]+sum[p]-sum[q]=S+sum[nums]
    // 即2sum[p]=S+sum[nums]，问题转换成子集和
    int sum=0,res=0;
    for(auto num:nums)
      sum+=num;
    if((sum+S)&1||sum<S||-sum>S)
      return 0;
    sum=(sum+S)>>1;
    // i==0况
    vector<int> d(sum+1,0);
    d[0]=1;
    for(auto num:nums)
      for(int j=sum;j>=0;--j)
        if(j>=num)
          d[j]+=d[j-num];
    return d[sum];
  }
};
