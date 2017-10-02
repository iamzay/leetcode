#include <vector>
#include <queue>
#include <functional>
using namespace std;
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> q;
    int n=nums.size();
    for(int i=0;i<n;++i){
      if(i<k)
        q.push(nums[i]);
      else {
        int top=q.top();
        if(nums[i]>top){
          q.pop();
          q.push(nums[i]);
        }
      }
    }
    return q.top();
  }
};
