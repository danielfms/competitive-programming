// 1015 - Brush (I) 
// http://lightoj.com/volume_showproblem.php?problem=1015

#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,c=1,total=0,n,units;
    
    cin>>T;
    while(T--){
        total=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>units;
            if(units>0)
                total+=units;
        }
        cout<<"Case "<<c++<<": "<<total<<endl;
    }
    
    return 0;
}
