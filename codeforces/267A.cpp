//AC
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b,mi,ma,ans;
    cin>>n;
    while(n--){
      ans = 0;
      cin>>a>>b;
      ma = max(a,b);
      mi = min(a,b);
      if(ma % mi == 0){
        ans = ma/mi;
      }else{
        do{
          a = ma/mi;
          b = ma%mi;
          ans+= a;
          ma = max(b,mi);
          mi = min(b,mi);
        }while(b!=0);
      }
      cout<<ans<<endl;
    }
    return 0;
}
