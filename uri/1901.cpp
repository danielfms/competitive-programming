// Butterflies
// https://www.urionlinejudge.com.br/judge/en/problems/view/1901
#include <bits/stdc++.h>
using namespace std;
int forest[201][201];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n,ans=0,x,y,k;
  set<int> b;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      cin>>forest[i][j];
  }
  for(int i=0;i<2*n;i++){
    cin>>x>>y;
    k = forest[x][y];
    if(b.count(k)==0)
      b.insert(k);
  }
  cout<<b.size()<<"\n";
  return 0;
}
