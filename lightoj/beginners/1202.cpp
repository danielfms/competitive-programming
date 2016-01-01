// 1202 - Bishops 
// http://www.lightoj.com/volume_showproblem.php?problem=1202

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,ax,ay,bx,by,i=1;
    cin>>T;
    while(T--){
        cin>>ax>>ay>>bx>>by;
        
        if(abs(ax-bx) == abs(ay-by))
            printf("Case %d: 1\n", i++);
        else if(abs(abs(ax-bx) - abs(ay-by))%2==1)
            printf("Case %d: impossible\n", i++);
        else
            printf("Case %d: 2\n", i++);
    }
    return 0;
}