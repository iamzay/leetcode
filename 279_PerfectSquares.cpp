#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  // d[n]表示当和为n时最少的个数
  int numSquares(int n) {
    vector<int> d(n+1,n+1);
    d[0]=0;
    for(int i=1;i<=n;++i)
      for(int j=1;j*j<=i;++j){
        d[i]=min(d[i],d[i-j*j]+1);
      }
    return d[n];
  }
};

class Solution1 {
public:
  int numSquares(int n){
    vector<int> squareNumbers;
    for(int i=1;i*i<=n;++i)
      squareNumbers.push_back(i*i);
    if(squareNumbers.back()==n)
      return 1;
    vector<bool> visited(n,false);
    int step=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      ++step;
      int m=q.size();
      for(int k=0;k<m;++k){
        int cur=q.front();
        q.pop();
        for(auto num:squareNumbers){
          int next=cur+num;
          if(next==n)
            return step;
          else if(next<n&&!visited[next]){
            visited[next]=true;
            q.push(next);
          } else if(next>n){
            break;
          }
        }
      }
    }
    return 0;
  }
};
