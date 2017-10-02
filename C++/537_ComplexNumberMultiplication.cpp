#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
  pair<int,int> parse(string s){
    pair<int,int> p;
    auto index=s.find('+');
    p.first=stoi(s.substr(0,index));
    auto i_index=s.find('i');
    p.second=stoi(s.substr(index+1,i_index));
    return p;
  }
public:
  string complexNumberMultiply(string a, string b) {
    pair<int,int> p1=parse(a),p2=parse(b);
    int x=p1.first*p2.first+(-1)*p1.second*p2.second;
    int y=p1.first*p2.second+p1.second*p2.first;
    return string()+to_string(x)+"+"+to_string(y)+"i";
  }
};

int main(){
  string s;
  Solution sol;
  cout<<sol.complexNumberMultiply("1+1i","1+1i");
}
