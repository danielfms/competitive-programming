// Stakes
// https://www.urionlinejudge.com.br/judge/en/problems/view/1630
#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,gcd,ans;
  while(cin>>a>>b){
    gcd = __gcd(a,b);
    ans = 2*(a/gcd + b/gcd);
    cout<<ans<<endl;
  }
  return 0;
}
