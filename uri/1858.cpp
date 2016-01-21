// Theon's Answer
// https://www.urionlinejudge.com.br/judge/en/problems/view/1858
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,i=1,p,mi=numeric_limits<int>::max(),ans;
  cin>>n;
  while(n--){
    cin>>p;
    if(p<mi){
      ans = i;
      mi = p;
    }
    i+=1;
  }
  cout<<ans<<endl;
  return 0;
}
