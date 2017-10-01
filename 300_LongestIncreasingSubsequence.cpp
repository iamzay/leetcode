class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    if(!n)
      return 0;
    // d[n]表示以nums[n]为结尾的最长子串的长度
    vector<int> d(n,1);
    d[0]=1;
    int _max=1;
    for(int i=1;i<n;++i){
      for(int j=0;j<i;++j){
        if(nums[j]<nums[i])
          d[i]=max(d[i],1+d[j]);
      }
      _max=max(_max,d[i]);
    }
    return _max;
  }
};
