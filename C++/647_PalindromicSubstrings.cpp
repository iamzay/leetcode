class Solution {
public:
  int countSubstrings(string s) {
    int n=s.size();
    for(int i=0;i<n;++i){
      extendPalindromic(s,i,i);
      extendPalindromic(s,i,i+1);
    }
    return res;
  }

private:
  void extendPalindromic(string &s,int left,int right){
    int n=s.size();
    for(;left>=0&&right<n&&s[left]==s[right];--left,++right)
      ++res;
  }
  int res;
};
