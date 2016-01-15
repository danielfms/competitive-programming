//AC
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string w;
    cin>>w;
    int l= w.size();
    for(int i=0,j=l-1;i<=j;i++,j--)
      if(w[i] != w[j]){
        cout<<"NO"<<endl;
        return 0;
      }else{
        if((((w[i]>=66 && w[i]<=71)||(w[i]>=74 && w[i]<=76)) || (w[i]=='N' || (w[i]>=80 && w[i]<=83))) || (w[i]=='Z')){
            cout<<"NO"<<endl;
            return 0;
          }
      }

    cout<<"YES"<<endl;
    return 0;
}
