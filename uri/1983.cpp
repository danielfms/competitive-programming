// The Chosen
// https://www.urionlinejudge.com.br/judge/en/problems/view/1983
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,s;
  float g;
  cin>>n;
  vector< pair<float,int>  > v;
  while(n--){
    cin>>s>>g;
    v.push_back(make_pair(g,s));
  }
  sort(v.begin(),v.end(),greater<pair<float,int> >());
  if(v[0].first >= 8.0)
    cout<<v[0].second<<endl;
  else cout<<"Minimum note not reached"<<endl;

  return 0;
}
