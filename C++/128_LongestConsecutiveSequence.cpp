class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> m;
    int _max=0;
    for(auto n:nums){
      if(m.find(n)!=m.end())
        continue;
      int left=m.find(n-1)==m.end()?0:m[n-1];
      int right=m.find(n+1)==m.end()?0:m[n+1];
      int len=right+left+1;
      m[n]=len;
      m[n-left]=m[n+right]=len;
      _max=max(_max,len);
    }
    return _max;
  }
};
