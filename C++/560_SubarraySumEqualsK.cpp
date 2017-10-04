class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int cnt=0,n=nums.size();
    unordered_map<int,int> preSum;
    preSum[0]=1;
    int currentSum=0;
    for(int i=0;i<n;++i){
      currentSum+=nums[i];
      int sum=currentSum-k;
      if(preSum.find(sum)!=preSum.end())
        cnt+=preSum[sum];
      ++preSum[currentSum];
    }
    return cnt;
  }
};
