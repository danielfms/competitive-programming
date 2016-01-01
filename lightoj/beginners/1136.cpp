// 1136 - Division by 3
// http://lightoj.com/volume_showproblem.php?problem=1136
 
#include <bits/stdc++.h>
using namespace std;
int  main(){
    long long T,i=1,A,B, ans;
    scanf("%lld",&T);
    while(T--){
        ans = 0;
        scanf("%lld %lld",&A,&B);
        A-=1;
        ans = (2*B)/3 - (2*A)/3;
        printf("Case %lld: %lld\n",i++,ans);
          
    }
    return 0;
}