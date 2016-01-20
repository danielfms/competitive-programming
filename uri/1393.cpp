// Hexagonal Tiles
// https://www.urionlinejudge.com.br/judge/en/problems/view/1393
#include <bits/stdc++.h>
using namespace std;

int dp[41];

int fibonacci(int n){
  if(n==0)
    return 1;
  if(n<0)
    return 0;
  if(dp[n]!=-1)
    return dp[n];

  return dp[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(){
  int n;
  memset(dp,-1,sizeof(dp));
  while(cin>>n && n!=0){
    cout<<fibonacci(n)<<endl;
  }
  return 0;
}
