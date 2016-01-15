// AC
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,cont=0,b;
    bool flag = false;
    cin>>n;
    while(n--){
      cin>>b;
      if(b==1) flag=true;
      cont+=b;
    }
    if(flag)
      cout<<"-1"<<endl;
    else
      cout<<"1"<<endl;
    return 0;
}
