#include <iostream>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int _max=nums[0];
    int current=0,n=nums.size();
    for(int i=0;i<n;++i){
      current+=nums[i];
      _max=max(_max,current);
      current=max(0,current);
    }
    return _max;
  }
};
