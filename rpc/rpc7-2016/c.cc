#include <bits/stdc++.h>

using namespace std;

void smaller(string &s, unsigned long long l){
  for(unsigned long long i=l-1; i>=0; i--){
    if(s[i]!='0'){
      s[i] -= 1;
      return;
    }
    else{
      continue;
    }
  }
}

int main(){
  string s;
  unsigned long long len;
  while(cin>>s && s!="END"){
    len = s.size();
    if(count(s,len) == 1)
      cout<<"0"<<endl;
    else{
      smaller(s,len);
      cout<<s<<endl;
    }
  }
  return 0;
}
