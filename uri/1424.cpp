// Easy Problem from Rujia Liu?
// https://www.urionlinejudge.com.br/judge/en/problems/view/1424
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n,nn,q,t,k,va;
  while(cin>>n>>q){
    nn = n;
    unordered_map<int, vector<int> > m;
    for(int i=1;i<=n;i++){
      cin>>t;
      m[t].push_back(i);
    }
    for(int i=0;i<q;i++){
      cin>>k>>va;
      if(m.count(va)==0)
        cout<<"0"<<endl;
      else{
        if(k>m[va].size())
          cout<<"0"<<endl;
        else
          cout<<m[va][k-1]<<endl;
      }
    }
  }
  return 0;
}
