// Simulator
// https://www.urionlinejudge.com.br/judge/en/problems/view/1945
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string line,A,B,C,op,last;
  int b,c,tmp=0;
  bool fb,fc;
  map<string, int> m;
  while(getline(cin, line)){
    fb = false;
    fc = false;
    //cout<<line<<endl;
    stringstream ss(line);
    ss>>A;
    last = A;
    ss>>op;
    ss>>B;
    tmp = 0;
    if(B[0]>='0' && B[0]<='9'){
      b = atoi(B.c_str());
      fb = true;
    }
    if(!ss.eof()){
      ss>>op;
      ss>>C;
      if(C[0]>='0' && C[0]<='9'){
        c = atoi(C.c_str());
        fc = true;
      }
      if(fb)
        tmp = b;
      else
        tmp = m[B];

      if(fc)
        tmp+= c;
      else
        tmp+= m[C];

      m[A] = tmp;
    }else{
      if(fb)
        m[A] = b;
      else
        m[A] = m[B];
    }
  }
  cout<<m[last]<<endl;
  return 0;
}
