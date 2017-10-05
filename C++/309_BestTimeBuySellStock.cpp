#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(!n)
      return 0;
    // buy[i]: 第i天前以buy结尾的子串最大利润
    vector<int> buy(n,0);
    vector<int> sell(n,0);
    vector<int> rest(n,0);
    buy[0]=-prices[0];
    sell[0]=INT_MIN;
    rest[0]=0;
    for(int i=1;i<n;++i){
      buy[i]=max(buy[i-1],rest[i-1]-prices[i]);
      sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
      rest[i]=max(rest[i-1],sell[i-1]);
    }
    return max(sell[n-1],rest[n-1]);
  }
};
