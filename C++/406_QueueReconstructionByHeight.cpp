#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    vector<pair<int,int>> res;
    using pp=pair<int,int>;
    if(!people.size()) return res;
    sort(people.begin(),people.end(),[](pp p1,pp p2){
        return p1.first>p2.first||p1.first==p2.first&&p1.second<p2.second;
      });
    res.push_back(people[0]);
    int n=people.size();
    for(int i=1;i<n;++i){
      auto beg=res.begin();
      res.insert(beg+people[i].second,people[i]);
    }
    return res;
  }
};

int main(){
  vector<pair<int,int>> data{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  for(auto p:data){
    cout<<p.first<<" "<<p.second<<endl;
  }
  cout<<"-------"<<endl;
  auto ans=Solution().reconstructQueue(data);
  for(auto p:ans){
    cout<<p.first<<" "<<p.second<<endl;
  }
}
