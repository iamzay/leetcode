class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> window(26,0),pv(26,0),res;
    int n=p.size(),m=s.size();
    if(n>m) return res;
    for(int i=0;i<n;++i){
      ++pv[p[i]-'a'];
      ++window[s[i]-'a'];
    }
    if(pv==window) res.push_back(0);
    for(int i=n;i<m;++i){
      ++window[s[i]-'a'];
      --window[s[i-n]-'a'];
      if(pv==window) res.push_back(i-n+1);
    }
    return res;
  }
};
