class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n-1;++i){
      if(nums[i]>nums[i+1]){
        int tmp=nums[i];
        nums[i]=nums[i+1];
        bool res1=isNondecreasing(nums);
        nums[i+1]=nums[i]=tmp;
        bool res2=isNondecreasing(nums);
        return res1||res2;
      }
    }
    return true;
  }

private:
  bool isNondecreasing(vector<int>& nums){
    int n=nums.size();
    for(int i=0;i<n-1;++i){
      if(nums[i]>nums[i+1])
        return false;
    }
    return true;
  }
};
