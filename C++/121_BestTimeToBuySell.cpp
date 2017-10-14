class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int maxProfit=0;
    if(!n) return maxProfit;
    int _min=prices[0];
    for(int i=1;i<n;++i){
      maxProfit=max(maxProfit,prices[i]-_min);
      _min=min(_min,prices[i]);
    }
    return maxProfit;
  }
};
