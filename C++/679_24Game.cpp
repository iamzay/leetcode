#include <iostream>
using namespace std;

class Solution {
private:
  bool JudgePoint24(vector<double>& nums){
    if(nums.size()==1) return abs(nums[0]-24)<0.000000001;
    for(int i=0;i<nums.size();++i)
      for(int j=i+1;j<nums.size();++j){
        vector<double> tmp;
        for(int k=0;k<nums.size();++k)
          if(k!=i&&k!=j)
            tmp.push_back(nums[k]);
        for(int k=0;k<6;++k){
          double value;
          switch(k){
          case 0:
            value=nums[i]+nums[j];
            break;
          case 1:
            value=nums[i]-nums[j];
            break;
          case 2:
            value=nums[j]-nums[i];
            break;
          case 3:
            value=nums[i]*nums[j];
            break;
          case 4:
            if(nums[j]<0.000000001) continue;
            value=nums[i]/nums[j];
            break;
          case 5:
            if(nums[i]<0.000000001) continue;
            value=nums[j]/nums[i];
            break;
          default:
            break;
          }
          tmp.push_back(value);
          if(JudgePoint24(tmp)) return true;
          tmp.pop_back();
        }
      }
    return false;
  }
public:
  bool judgePoint24(vector<int>& nums){
    vector<double> ds;
    for(auto n:nums) ds.push_back(n);
    return JudgePoint24(ds);
  }
};
