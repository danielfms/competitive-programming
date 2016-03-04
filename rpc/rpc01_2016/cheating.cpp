#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  double d,x,y,h;
  cin>>t;
  while(t--){
    cin>>d>>x>>y;
    if(x==0 && y==0){
      cout<<0<<endl;
    }else{
      double ans = sqrt(x*x + y*y)/sqrt(d);
      int ansint = ans;
      double error = ans - ansint;
      //cout<<ans<<endl;
      if(sqrt(x*x + y*y)<sqrt(d))cout<<2<<endl;
      else{
        if(error<1e-9)cout<<ansint<<endl;
        else cout<<ansint+1<<endl;
      }
    }
  }
  return 0;
}
