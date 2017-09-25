#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    bool add=1;
    for(int i=digits.size()-1;i>=0&&add;--i){
      if(digits[i]==9){
        digits[i]=0;
        add=1;
      } else {
        ++digits[i];
        add=0;
      }
    }
    vector<int> res;
    if(add)
      res.push_back(1);
    res.insert(res.end(),digits.begin(),digits.end());
    return res;
  }
};

int main(){
  Solution s;
  vector<int> vec{1,0};
  s.plusOne(vec);
}
