#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> m;
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<n;++i){
      int numberToFind=target-nums[i];
      if(m.find(numberToFind)!=m.end()){
        ans.push_back(i);
        ans.push_back(m[numberToFind]);
        return ans;
      }
      m[nums[i]]=i;
    }
    return ans;
  }
};
