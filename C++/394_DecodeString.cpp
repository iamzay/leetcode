class Solution {
public:
  string decodeString(string s) {
    string searchStr="0123456789";
    if(s.find_first_of(searchStr)==-1)
      return s;
    string res;
    int begin=0,n=s.size();
    while(begin<n){
      int num=s.find_first_of(searchStr,begin);
      if(num==-1){
        res+=s.substr(begin,-1);
        break;
      }
      int leftBracket=s.find_first_of("[",begin);
      int times=stoi(s.substr(num,leftBracket-num));
      int rightBracket=findRightBracket(s,leftBracket);
      res+=s.substr(begin,num-begin);
      string decode=decodeString(s.substr(leftBracket+1,rightBracket-leftBracket-1));
      for(int i=0;i<times;++i)
        res+=decode;
      begin=rightBracket+1;
    }
    return res;
  }

private:
  int findRightBracket(string s,int begin){
    int n=s.size();
    int cnt=0;
    for(int i=begin;i<n;++i){
      if(s[i]=='[')
        ++cnt;
      if(s[i]==']'){
        --cnt;
        if(!cnt)
          return i;
      }
    }
  }
};
